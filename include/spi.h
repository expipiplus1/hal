#pragma once

#include <gpio.h>

namespace hal
{

namespace spi
{

using namespace device;
using namespace gpio;

enum spi_mode_t
    { mode_0    // CPOL=0, CPHA=0
    , mode_1    // CPOL=0, CPHA=1
    , mode_2    // CPOL=1, CPHA=0
    , mode_3    // CPOL=1, CPHA=1
    };

enum spi_bit_order_t { msb_first, lsb_first };

enum spi_clock_divider_t
    { fpclk_2
    , fpclk_4
    , fpclk_8
    , fpclk_16
    , fpclk_32
    , fpclk_64
    , fpclk_128
    , fpclk_256
    };

template<int NO> struct spi_traits {};

template<> struct spi_traits<1>
{
    typedef spi1_t T;
    static inline T& SPI() { return SPI1; }
    static const gpio::internal::alternate_function_t sck = gpio::internal::SPI1_SCK;
    static const gpio::internal::alternate_function_t mosi = gpio::internal::SPI1_MOSI;
    static const gpio::internal::alternate_function_t miso = gpio::internal::SPI1_MISO;
    static const gpio::internal::alternate_function_t nss = gpio::internal::SPI1_NSS;
};

template<> struct spi_traits<2>
{
    typedef spi2_t T;
    static inline T& SPI() { return SPI2; }
    static const gpio::internal::alternate_function_t sck = gpio::internal::SPI2_SCK;
    static const gpio::internal::alternate_function_t mosi = gpio::internal::SPI2_MOSI;
    static const gpio::internal::alternate_function_t miso = gpio::internal::SPI2_MISO;
    static const gpio::internal::alternate_function_t nss = gpio::internal::SPI2_NSS;
};

#if defined(HAVE_PERIPHERAL_SPI3)
template<> struct spi_traits<3>
{
    typedef spi3_t T;
    static inline T& SPI() { return SPI3; }
    static const gpio::internal::alternate_function_t sck = gpio::internal::SPI3_SCK;
    static const gpio::internal::alternate_function_t mosi = gpio::internal::SPI3_MOSI;
    static const gpio::internal::alternate_function_t miso = gpio::internal::SPI3_MISO;
    static const gpio::internal::alternate_function_t nss = gpio::internal::SPI3_NSS;
};
#endif

template<spi_mode_t> struct spi_mode_traits {};

template<> struct spi_mode_traits<mode_0>
{
    template<typename _>
    static constexpr uint32_t mode() { return 0; }
};

template<> struct spi_mode_traits<mode_1>
{
    template<typename _>
    static constexpr uint32_t mode() { return _::CR1_CPHA; }
};

template<> struct spi_mode_traits<mode_2>
{
    template<typename _>
    static constexpr uint32_t mode() { return _::CR1_CPOL; }
};

template<> struct spi_mode_traits<mode_3>
{
    template<typename _>
    static constexpr uint32_t mode() { return _::CR1_CPHA | _::CR1_CPOL; }
};

template<int NO, gpio_pin_t SCK, gpio_pin_t MOSI> struct spi_t
{
private:
    typedef typename spi_traits<NO>::T _;

public:
    template
        < spi_mode_t            mode    = mode_0
        , spi_bit_order_t       order   = msb_first
        , spi_clock_divider_t   divider = fpclk_256
        , output_speed_t        speed   = low_speed
        >
    static inline void setup()
    {
        using namespace gpio::internal;

        alternate_t<SCK, spi_traits<NO>::sck>::template setup<speed>();
        alternate_t<MOSI, spi_traits<NO>::mosi>::template setup<speed>();

        peripheral_traits<_>::enable();                         // enable spi clock
        SPI().CR1 = _::CR1_RESET_VALUE                          // reset control register 1
                  | _::CR1_MSTR                                 // master mode
                  | _::template CR1_BR<divider>                 // clock divider
                  | spi_mode_traits<mode>::template mode<_>()   // SPI-mode
                  | (order == lsb_first ?  _::CR1_LSBFIRST : 0) // lsb first
                  ;
        SPI().CR2 = _::CR2_RESET_VALUE;         // reset control register 2
        SPI().CR2 |= _::CR2_SSOE;               // ss output enable
        SPI().CR1 |= _::CR1_SPE;                // enable spi
    }

    __attribute__((always_inline))
    static inline void write8(uint8_t x)
    {
        while (!(SPI().SR & _::SR_TXE));        // wait until tx buffer is empty
        *reinterpret_cast<volatile uint8_t*>(&SPI().DR) = x;
    }

    __attribute__((always_inline))
    static inline void write16(uint16_t x)
    {
        while (!(SPI().SR & _::SR_TXE));        // wait until tx buffer is empty
        SPI().DR = x;
    }

    __attribute__((always_inline))
    static inline bool busy()
    {
        return SPI().SR & _::SR_BSY;
    }

    __attribute__((always_inline))
    static inline void wait_idle()
    {
        while ((SPI().SR & (_::SR_BSY | _::SR_TXE)) != _::SR_TXE);
    }

    enum interrupt_t
        { err_interrupt = _::CR2_ERRIE
        , rx_interrupt = _::CR2_RXNEIE
        , tx_interrupt = _::CR2_TXEIE
        };

    static inline void interrupt_enable(uint32_t flags)
    {
        static const uint32_t mask = err_interrupt | rx_interrupt | tx_interrupt;

        SPI().CR2 &= ~mask;
        SPI().CR2 |= flags & mask;
    }

private:
    static inline typename spi_traits<NO>::T& SPI() { return spi_traits<NO>::SPI(); }
};

}

}

