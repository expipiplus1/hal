#pragma once

#include <stdint.h>

////
//
//    STM32F411
//
//       schema-version : 1.1
//       vendor         : 
//       series         : 
//       device-version : 1.1
//       address-unit   : 8 bits
//       device-width   : 32
//       device-size    : 32
//
////

namespace stm32f411
{

template<int N> class reserved_t { private: uint32_t m_pad[N]; };

template<uint8_t POS, uint32_t MASK>
struct bit_field_t
{
    template <uint32_t X>
    static constexpr uint32_t value()
    {
        static_assert((X & ~MASK) == 0, "field value too large");
        return X << POS;
    }
};

////
//
//    ADC common registers
//
////

struct adc_common_t
{
    volatile uint32_t    CSR;                  // [Read-only] ADC Common status register
    volatile uint32_t    CCR;                  // [Read-write] ADC common control register

    static constexpr uint32_t CSR_OVR3 = 0x200000;      // Overrun flag of ADC3
    static constexpr uint32_t CSR_STRT3 = 0x100000;     // Regular channel Start flag of ADC 3
    static constexpr uint32_t CSR_JSTRT3 = 0x80000;     // Injected channel Start flag of ADC 3
    static constexpr uint32_t CSR_JEOC3 = 0x40000;      // Injected channel end of conversion of ADC 3
    static constexpr uint32_t CSR_EOC3 = 0x20000;       // End of conversion of ADC 3
    static constexpr uint32_t CSR_AWD3 = 0x10000;       // Analog watchdog flag of ADC 3
    static constexpr uint32_t CSR_OVR2 = 0x2000;        // Overrun flag of ADC 2
    static constexpr uint32_t CSR_STRT2 = 0x1000;       // Regular channel Start flag of ADC 2
    static constexpr uint32_t CSR_JSTRT2 = 0x800;       // Injected channel Start flag of ADC 2
    static constexpr uint32_t CSR_JEOC2 = 0x400;        // Injected channel end of conversion of ADC 2
    static constexpr uint32_t CSR_EOC2 = 0x200;         // End of conversion of ADC 2
    static constexpr uint32_t CSR_AWD2 = 0x100;         // Analog watchdog flag of ADC 2
    static constexpr uint32_t CSR_OVR1 = 0x20;          // Overrun flag of ADC 1
    static constexpr uint32_t CSR_STRT1 = 0x10;         // Regular channel Start flag of ADC 1
    static constexpr uint32_t CSR_JSTRT1 = 0x8;         // Injected channel Start flag of ADC 1
    static constexpr uint32_t CSR_JEOC1 = 0x4;          // Injected channel end of conversion of ADC 1
    static constexpr uint32_t CSR_EOC1 = 0x2;           // End of conversion of ADC 1
    static constexpr uint32_t CSR_AWD1 = 0x1;           // Analog watchdog flag of ADC 1
    static const uint32_t CSR_RESET_VALUE = 0x0;

    static constexpr uint32_t CCR_TSVREFE = 0x800000;   // Temperature sensor and VREFINT enable
    static constexpr uint32_t CCR_VBATE = 0x400000;     // VBAT enable
    template<uint32_t X>
    static constexpr uint32_t CCR_ADCPRE =              // ADC prescaler (2 bits)
        bit_field_t<16, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CCR_DMA =                 // Direct memory access mode for multi ADC mode (2 bits)
        bit_field_t<14, 0x3>::value<X>();
    static constexpr uint32_t CCR_DDS = 0x2000;         // DMA disable selection for multi-ADC mode
    template<uint32_t X>
    static constexpr uint32_t CCR_DELAY =               // Delay between 2 sampling phases (4 bits)
        bit_field_t<8, 0xf>::value<X>();
    static const uint32_t CCR_RESET_VALUE = 0x0;

    static constexpr uint8_t FPU = 81; // FPU interrupt
};

static adc_common_t& ADC_COMMON = *reinterpret_cast<adc_common_t*>(0x40012300);

#define HAVE_PERIPHERAL_ADC_COMMON


////
//
//    Analog-to-digital converter
//
////

struct adc1_t
{
    volatile uint32_t    SR;                   // [Read-write] status register
    volatile uint32_t    CR1;                  // [Read-write] control register 1
    volatile uint32_t    CR2;                  // [Read-write] control register 2
    volatile uint32_t    SMPR1;                // [Read-write] sample time register 1
    volatile uint32_t    SMPR2;                // [Read-write] sample time register 2
    volatile uint32_t    JOFR1;                // [Read-write] injected channel data offset register x
    volatile uint32_t    JOFR2;                // [Read-write] injected channel data offset register x
    volatile uint32_t    JOFR3;                // [Read-write] injected channel data offset register x
    volatile uint32_t    JOFR4;                // [Read-write] injected channel data offset register x
    volatile uint32_t    HTR;                  // [Read-write] watchdog higher threshold register
    volatile uint32_t    LTR;                  // [Read-write] watchdog lower threshold register
    volatile uint32_t    SQR1;                 // [Read-write] regular sequence register 1
    volatile uint32_t    SQR2;                 // [Read-write] regular sequence register 2
    volatile uint32_t    SQR3;                 // [Read-write] regular sequence register 3
    volatile uint32_t    JSQR;                 // [Read-write] injected sequence register
    volatile uint32_t    JDR1;                 // [Read-only] injected data register x
    volatile uint32_t    JDR2;                 // [Read-only] injected data register x
    volatile uint32_t    JDR3;                 // [Read-only] injected data register x
    volatile uint32_t    JDR4;                 // [Read-only] injected data register x
    volatile uint32_t    DR;                   // [Read-only] regular data register

    static constexpr uint32_t SR_OVR = 0x20;           // Overrun
    static constexpr uint32_t SR_STRT = 0x10;          // Regular channel start flag
    static constexpr uint32_t SR_JSTRT = 0x8;          // Injected channel start flag
    static constexpr uint32_t SR_JEOC = 0x4;           // Injected channel end of conversion
    static constexpr uint32_t SR_EOC = 0x2;            // Regular channel end of conversion
    static constexpr uint32_t SR_AWD = 0x1;            // Analog watchdog flag
    static const uint32_t SR_RESET_VALUE = 0x0;

    static constexpr uint32_t CR1_OVRIE = 0x4000000;    // Overrun interrupt enable
    template<uint32_t X>
    static constexpr uint32_t CR1_RES =                 // Resolution (2 bits)
        bit_field_t<24, 0x3>::value<X>();
    static constexpr uint32_t CR1_AWDEN = 0x800000;     // Analog watchdog enable on regular channels
    static constexpr uint32_t CR1_JAWDEN = 0x400000;    // Analog watchdog enable on injected channels
    template<uint32_t X>
    static constexpr uint32_t CR1_DISCNUM =             // Discontinuous mode channel count (3 bits)
        bit_field_t<13, 0x7>::value<X>();
    static constexpr uint32_t CR1_JDISCEN = 0x1000;     // Discontinuous mode on injected channels
    static constexpr uint32_t CR1_DISCEN = 0x800;       // Discontinuous mode on regular channels
    static constexpr uint32_t CR1_JAUTO = 0x400;        // Automatic injected group conversion
    static constexpr uint32_t CR1_AWDSGL = 0x200;       // Enable the watchdog on a single channel in scan mode
    static constexpr uint32_t CR1_SCAN = 0x100;         // Scan mode
    static constexpr uint32_t CR1_JEOCIE = 0x80;        // Interrupt enable for injected channels
    static constexpr uint32_t CR1_AWDIE = 0x40;         // Analog watchdog interrupt enable
    static constexpr uint32_t CR1_EOCIE = 0x20;         // Interrupt enable for EOC
    template<uint32_t X>
    static constexpr uint32_t CR1_AWDCH =               // Analog watchdog channel select bits (5 bits)
        bit_field_t<0, 0x1f>::value<X>();
    static const uint32_t CR1_RESET_VALUE = 0x0;

    static constexpr uint32_t CR2_SWSTART = 0x40000000; // Start conversion of regular channels
    template<uint32_t X>
    static constexpr uint32_t CR2_EXTEN =               // External trigger enable for regular channels (2 bits)
        bit_field_t<28, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CR2_EXTSEL =              // External event select for regular group (4 bits)
        bit_field_t<24, 0xf>::value<X>();
    static constexpr uint32_t CR2_JSWSTART = 0x400000;  // Start conversion of injected channels
    template<uint32_t X>
    static constexpr uint32_t CR2_JEXTEN =              // External trigger enable for injected channels (2 bits)
        bit_field_t<20, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CR2_JEXTSEL =             // External event select for injected group (4 bits)
        bit_field_t<16, 0xf>::value<X>();
    static constexpr uint32_t CR2_ALIGN = 0x800;        // Data alignment
    static constexpr uint32_t CR2_EOCS = 0x400;         // End of conversion selection
    static constexpr uint32_t CR2_DDS = 0x200;          // DMA disable selection (for single ADC mode)
    static constexpr uint32_t CR2_DMA = 0x100;          // Direct memory access mode (for single ADC mode)
    static constexpr uint32_t CR2_CONT = 0x2;           // Continuous conversion
    static constexpr uint32_t CR2_ADON = 0x1;           // A/D Converter ON / OFF
    static const uint32_t CR2_RESET_VALUE = 0x0;


    static const uint32_t SMPR1_RESET_VALUE = 0x0;


    static const uint32_t SMPR2_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t JOFR1_JOFFSET1 =            // Data offset for injected channel x (12 bits)
        bit_field_t<0, 0xfff>::value<X>();
    static const uint32_t JOFR1_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t JOFR2_JOFFSET2 =            // Data offset for injected channel x (12 bits)
        bit_field_t<0, 0xfff>::value<X>();
    static const uint32_t JOFR2_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t JOFR3_JOFFSET3 =            // Data offset for injected channel x (12 bits)
        bit_field_t<0, 0xfff>::value<X>();
    static const uint32_t JOFR3_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t JOFR4_JOFFSET4 =            // Data offset for injected channel x (12 bits)
        bit_field_t<0, 0xfff>::value<X>();
    static const uint32_t JOFR4_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t HTR_HT =                  // Analog watchdog higher threshold (12 bits)
        bit_field_t<0, 0xfff>::value<X>();
    static const uint32_t HTR_RESET_VALUE = 0xfff;

    template<uint32_t X>
    static constexpr uint32_t LTR_LT =                  // Analog watchdog lower threshold (12 bits)
        bit_field_t<0, 0xfff>::value<X>();
    static const uint32_t LTR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t SQR1_L =                   // Regular channel sequence length (4 bits)
        bit_field_t<20, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t SQR1_SQ16 =                // 16th conversion in regular sequence (5 bits)
        bit_field_t<15, 0x1f>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t SQR1_SQ15 =                // 15th conversion in regular sequence (5 bits)
        bit_field_t<10, 0x1f>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t SQR1_SQ14 =                // 14th conversion in regular sequence (5 bits)
        bit_field_t<5, 0x1f>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t SQR1_SQ13 =                // 13th conversion in regular sequence (5 bits)
        bit_field_t<0, 0x1f>::value<X>();
    static const uint32_t SQR1_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t SQR2_SQ12 =                // 12th conversion in regular sequence (5 bits)
        bit_field_t<25, 0x1f>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t SQR2_SQ11 =                // 11th conversion in regular sequence (5 bits)
        bit_field_t<20, 0x1f>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t SQR2_SQ10 =                // 10th conversion in regular sequence (5 bits)
        bit_field_t<15, 0x1f>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t SQR2_SQ9 =                 // 9th conversion in regular sequence (5 bits)
        bit_field_t<10, 0x1f>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t SQR2_SQ8 =                 // 8th conversion in regular sequence (5 bits)
        bit_field_t<5, 0x1f>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t SQR2_SQ7 =                 // 7th conversion in regular sequence (5 bits)
        bit_field_t<0, 0x1f>::value<X>();
    static const uint32_t SQR2_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t SQR3_SQ6 =                 // 6th conversion in regular sequence (5 bits)
        bit_field_t<25, 0x1f>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t SQR3_SQ5 =                 // 5th conversion in regular sequence (5 bits)
        bit_field_t<20, 0x1f>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t SQR3_SQ4 =                 // 4th conversion in regular sequence (5 bits)
        bit_field_t<15, 0x1f>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t SQR3_SQ3 =                 // 3rd conversion in regular sequence (5 bits)
        bit_field_t<10, 0x1f>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t SQR3_SQ2 =                 // 2nd conversion in regular sequence (5 bits)
        bit_field_t<5, 0x1f>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t SQR3_SQ1 =                 // 1st conversion in regular sequence (5 bits)
        bit_field_t<0, 0x1f>::value<X>();
    static const uint32_t SQR3_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t JSQR_JL =                  // Injected sequence length (2 bits)
        bit_field_t<20, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t JSQR_JSQ4 =                // 4th conversion in injected sequence (5 bits)
        bit_field_t<15, 0x1f>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t JSQR_JSQ3 =                // 3rd conversion in injected sequence (5 bits)
        bit_field_t<10, 0x1f>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t JSQR_JSQ2 =                // 2nd conversion in injected sequence (5 bits)
        bit_field_t<5, 0x1f>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t JSQR_JSQ1 =                // 1st conversion in injected sequence (5 bits)
        bit_field_t<0, 0x1f>::value<X>();
    static const uint32_t JSQR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t JDR1_JDATA =               // Injected data (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t JDR1_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t JDR2_JDATA =               // Injected data (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t JDR2_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t JDR3_JDATA =               // Injected data (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t JDR3_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t JDR4_JDATA =               // Injected data (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t JDR4_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t DR_DATA =                // Regular data (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t DR_RESET_VALUE = 0x0;

    static constexpr uint8_t ADC = 18; // ADC1 global interrupt
};

static adc1_t& ADC1 = *reinterpret_cast<adc1_t*>(0x40012000);

#define HAVE_PERIPHERAL_ADC1


////
//
//    Cryptographic processor
//
////

struct crc_t
{
    volatile uint32_t    DR;                   // [Read-write] Data register
    volatile uint32_t    IDR;                  // [Read-write] Independent Data register
    volatile uint32_t    CR;                   // [Write-only] Control register


    static const uint32_t DR_RESET_VALUE = 0xffffffff;

    template<uint32_t X>
    static constexpr uint32_t IDR_IDR =                 // Independent Data register (8 bits)
        bit_field_t<0, 0xff>::value<X>();
    static const uint32_t IDR_RESET_VALUE = 0x0;

    static constexpr uint32_t CR_CR = 0x1;             // Control regidter
    static const uint32_t CR_RESET_VALUE = 0x0;
};

static crc_t& CRC = *reinterpret_cast<crc_t*>(0x40023000);

#define HAVE_PERIPHERAL_CRC


////
//
//    Debug support
//
////

struct dbg_t
{
    volatile uint32_t    DBGMCU_IDCODE;        // [Read-only] IDCODE
    volatile uint32_t    DBGMCU_CR;            // [Read-write] Control Register
    volatile uint32_t    DBGMCU_APB1_FZ;       // [Read-write] Debug MCU APB1 Freeze registe
    volatile uint32_t    DBGMCU_APB2_FZ;       // [Read-write] Debug MCU APB2 Freeze registe

    template<uint32_t X>
    static constexpr uint32_t DBGMCU_IDCODE_DEV_ID =              // DEV_ID (12 bits)
        bit_field_t<0, 0xfff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t DBGMCU_IDCODE_REV_ID =              // REV_ID (16 bits)
        bit_field_t<16, 0xffff>::value<X>();
    static const uint32_t DBGMCU_IDCODE_RESET_VALUE = 0x10006411;

    static constexpr uint32_t DBGMCU_CR_DBG_SLEEP = 0x1;      // DBG_SLEEP
    static constexpr uint32_t DBGMCU_CR_DBG_STOP = 0x2;       // DBG_STOP
    static constexpr uint32_t DBGMCU_CR_DBG_STANDBY = 0x4;    // DBG_STANDBY
    static constexpr uint32_t DBGMCU_CR_TRACE_IOEN = 0x20;    // TRACE_IOEN
    template<uint32_t X>
    static constexpr uint32_t DBGMCU_CR_TRACE_MODE =          // TRACE_MODE (2 bits)
        bit_field_t<6, 0x3>::value<X>();
    static const uint32_t DBGMCU_CR_RESET_VALUE = 0x0;

    static constexpr uint32_t DBGMCU_APB1_FZ_DBG_TIM2_STOP = 0x1;  // DBG_TIM2_STOP
    static constexpr uint32_t DBGMCU_APB1_FZ_DBG_TIM3_STOP = 0x2;  // DBG_TIM3 _STOP
    static constexpr uint32_t DBGMCU_APB1_FZ_DBG_TIM4_STOP = 0x4;  // DBG_TIM4_STOP
    static constexpr uint32_t DBGMCU_APB1_FZ_DBG_TIM5_STOP = 0x8;  // DBG_TIM5_STOP
    static constexpr uint32_t DBGMCU_APB1_FZ_DBG_RTC_Stop = 0x400; // RTC stopped when Core is halted
    static constexpr uint32_t DBGMCU_APB1_FZ_DBG_WWDG_STOP = 0x800;// DBG_WWDG_STOP
    static constexpr uint32_t DBGMCU_APB1_FZ_DBG_IWDEG_STOP = 0x1000;// DBG_IWDEG_STOP
    static constexpr uint32_t DBGMCU_APB1_FZ_DBG_I2C1_SMBUS_TIMEOUT = 0x200000;// DBG_J2C1_SMBUS_TIMEOUT
    static constexpr uint32_t DBGMCU_APB1_FZ_DBG_I2C2_SMBUS_TIMEOUT = 0x400000;// DBG_J2C2_SMBUS_TIMEOUT
    static constexpr uint32_t DBGMCU_APB1_FZ_DBG_I2C3SMBUS_TIMEOUT = 0x800000;// DBG_J2C3SMBUS_TIMEOUT
    static const uint32_t DBGMCU_APB1_FZ_RESET_VALUE = 0x0;

    static constexpr uint32_t DBGMCU_APB2_FZ_DBG_TIM1_STOP = 0x1;  // TIM1 counter stopped when core is halted
    static constexpr uint32_t DBGMCU_APB2_FZ_DBG_TIM9_STOP = 0x10000;// TIM9 counter stopped when core is halted
    static constexpr uint32_t DBGMCU_APB2_FZ_DBG_TIM10_STOP = 0x20000;// TIM10 counter stopped when core is halted
    static constexpr uint32_t DBGMCU_APB2_FZ_DBG_TIM11_STOP = 0x40000;// TIM11 counter stopped when core is halted
    static const uint32_t DBGMCU_APB2_FZ_RESET_VALUE = 0x0;
};

static dbg_t& DBG = *reinterpret_cast<dbg_t*>(0xe0042000);

#define HAVE_PERIPHERAL_DBG


////
//
//    External interrupt/event controller
//
////

struct exti_t
{
    volatile uint32_t    IMR;                  // [Read-write] Interrupt mask register (EXTI_IMR)
    volatile uint32_t    EMR;                  // [Read-write] Event mask register (EXTI_EMR)
    volatile uint32_t    RTSR;                 // [Read-write] Rising Trigger selection register (EXTI_RTSR)
    volatile uint32_t    FTSR;                 // [Read-write] Falling Trigger selection register (EXTI_FTSR)
    volatile uint32_t    SWIER;                // [Read-write] Software interrupt event register (EXTI_SWIER)
    volatile uint32_t    PR;                   // [Read-write] Pending register (EXTI_PR)

    static constexpr uint32_t IMR_MR0 = 0x1;            // Interrupt Mask on line 0
    static constexpr uint32_t IMR_MR1 = 0x2;            // Interrupt Mask on line 1
    static constexpr uint32_t IMR_MR2 = 0x4;            // Interrupt Mask on line 2
    static constexpr uint32_t IMR_MR3 = 0x8;            // Interrupt Mask on line 3
    static constexpr uint32_t IMR_MR4 = 0x10;           // Interrupt Mask on line 4
    static constexpr uint32_t IMR_MR5 = 0x20;           // Interrupt Mask on line 5
    static constexpr uint32_t IMR_MR6 = 0x40;           // Interrupt Mask on line 6
    static constexpr uint32_t IMR_MR7 = 0x80;           // Interrupt Mask on line 7
    static constexpr uint32_t IMR_MR8 = 0x100;          // Interrupt Mask on line 8
    static constexpr uint32_t IMR_MR9 = 0x200;          // Interrupt Mask on line 9
    static constexpr uint32_t IMR_MR10 = 0x400;         // Interrupt Mask on line 10
    static constexpr uint32_t IMR_MR11 = 0x800;         // Interrupt Mask on line 11
    static constexpr uint32_t IMR_MR12 = 0x1000;        // Interrupt Mask on line 12
    static constexpr uint32_t IMR_MR13 = 0x2000;        // Interrupt Mask on line 13
    static constexpr uint32_t IMR_MR14 = 0x4000;        // Interrupt Mask on line 14
    static constexpr uint32_t IMR_MR15 = 0x8000;        // Interrupt Mask on line 15
    static constexpr uint32_t IMR_MR16 = 0x10000;       // Interrupt Mask on line 16
    static constexpr uint32_t IMR_MR17 = 0x20000;       // Interrupt Mask on line 17
    static constexpr uint32_t IMR_MR18 = 0x40000;       // Interrupt Mask on line 18
    static constexpr uint32_t IMR_MR19 = 0x80000;       // Interrupt Mask on line 19
    static constexpr uint32_t IMR_MR20 = 0x100000;      // Interrupt Mask on line 20
    static constexpr uint32_t IMR_MR21 = 0x200000;      // Interrupt Mask on line 21
    static constexpr uint32_t IMR_MR22 = 0x400000;      // Interrupt Mask on line 22
    static const uint32_t IMR_RESET_VALUE = 0x0;

    static constexpr uint32_t EMR_MR0 = 0x1;            // Event Mask on line 0
    static constexpr uint32_t EMR_MR1 = 0x2;            // Event Mask on line 1
    static constexpr uint32_t EMR_MR2 = 0x4;            // Event Mask on line 2
    static constexpr uint32_t EMR_MR3 = 0x8;            // Event Mask on line 3
    static constexpr uint32_t EMR_MR4 = 0x10;           // Event Mask on line 4
    static constexpr uint32_t EMR_MR5 = 0x20;           // Event Mask on line 5
    static constexpr uint32_t EMR_MR6 = 0x40;           // Event Mask on line 6
    static constexpr uint32_t EMR_MR7 = 0x80;           // Event Mask on line 7
    static constexpr uint32_t EMR_MR8 = 0x100;          // Event Mask on line 8
    static constexpr uint32_t EMR_MR9 = 0x200;          // Event Mask on line 9
    static constexpr uint32_t EMR_MR10 = 0x400;         // Event Mask on line 10
    static constexpr uint32_t EMR_MR11 = 0x800;         // Event Mask on line 11
    static constexpr uint32_t EMR_MR12 = 0x1000;        // Event Mask on line 12
    static constexpr uint32_t EMR_MR13 = 0x2000;        // Event Mask on line 13
    static constexpr uint32_t EMR_MR14 = 0x4000;        // Event Mask on line 14
    static constexpr uint32_t EMR_MR15 = 0x8000;        // Event Mask on line 15
    static constexpr uint32_t EMR_MR16 = 0x10000;       // Event Mask on line 16
    static constexpr uint32_t EMR_MR17 = 0x20000;       // Event Mask on line 17
    static constexpr uint32_t EMR_MR18 = 0x40000;       // Event Mask on line 18
    static constexpr uint32_t EMR_MR19 = 0x80000;       // Event Mask on line 19
    static constexpr uint32_t EMR_MR20 = 0x100000;      // Event Mask on line 20
    static constexpr uint32_t EMR_MR21 = 0x200000;      // Event Mask on line 21
    static constexpr uint32_t EMR_MR22 = 0x400000;      // Event Mask on line 22
    static const uint32_t EMR_RESET_VALUE = 0x0;

    static constexpr uint32_t RTSR_TR0 = 0x1;            // Rising trigger event configuration of line 0
    static constexpr uint32_t RTSR_TR1 = 0x2;            // Rising trigger event configuration of line 1
    static constexpr uint32_t RTSR_TR2 = 0x4;            // Rising trigger event configuration of line 2
    static constexpr uint32_t RTSR_TR3 = 0x8;            // Rising trigger event configuration of line 3
    static constexpr uint32_t RTSR_TR4 = 0x10;           // Rising trigger event configuration of line 4
    static constexpr uint32_t RTSR_TR5 = 0x20;           // Rising trigger event configuration of line 5
    static constexpr uint32_t RTSR_TR6 = 0x40;           // Rising trigger event configuration of line 6
    static constexpr uint32_t RTSR_TR7 = 0x80;           // Rising trigger event configuration of line 7
    static constexpr uint32_t RTSR_TR8 = 0x100;          // Rising trigger event configuration of line 8
    static constexpr uint32_t RTSR_TR9 = 0x200;          // Rising trigger event configuration of line 9
    static constexpr uint32_t RTSR_TR10 = 0x400;         // Rising trigger event configuration of line 10
    static constexpr uint32_t RTSR_TR11 = 0x800;         // Rising trigger event configuration of line 11
    static constexpr uint32_t RTSR_TR12 = 0x1000;        // Rising trigger event configuration of line 12
    static constexpr uint32_t RTSR_TR13 = 0x2000;        // Rising trigger event configuration of line 13
    static constexpr uint32_t RTSR_TR14 = 0x4000;        // Rising trigger event configuration of line 14
    static constexpr uint32_t RTSR_TR15 = 0x8000;        // Rising trigger event configuration of line 15
    static constexpr uint32_t RTSR_TR16 = 0x10000;       // Rising trigger event configuration of line 16
    static constexpr uint32_t RTSR_TR17 = 0x20000;       // Rising trigger event configuration of line 17
    static constexpr uint32_t RTSR_TR18 = 0x40000;       // Rising trigger event configuration of line 18
    static constexpr uint32_t RTSR_TR19 = 0x80000;       // Rising trigger event configuration of line 19
    static constexpr uint32_t RTSR_TR20 = 0x100000;      // Rising trigger event configuration of line 20
    static constexpr uint32_t RTSR_TR21 = 0x200000;      // Rising trigger event configuration of line 21
    static constexpr uint32_t RTSR_TR22 = 0x400000;      // Rising trigger event configuration of line 22
    static const uint32_t RTSR_RESET_VALUE = 0x0;

    static constexpr uint32_t FTSR_TR0 = 0x1;            // Falling trigger event configuration of line 0
    static constexpr uint32_t FTSR_TR1 = 0x2;            // Falling trigger event configuration of line 1
    static constexpr uint32_t FTSR_TR2 = 0x4;            // Falling trigger event configuration of line 2
    static constexpr uint32_t FTSR_TR3 = 0x8;            // Falling trigger event configuration of line 3
    static constexpr uint32_t FTSR_TR4 = 0x10;           // Falling trigger event configuration of line 4
    static constexpr uint32_t FTSR_TR5 = 0x20;           // Falling trigger event configuration of line 5
    static constexpr uint32_t FTSR_TR6 = 0x40;           // Falling trigger event configuration of line 6
    static constexpr uint32_t FTSR_TR7 = 0x80;           // Falling trigger event configuration of line 7
    static constexpr uint32_t FTSR_TR8 = 0x100;          // Falling trigger event configuration of line 8
    static constexpr uint32_t FTSR_TR9 = 0x200;          // Falling trigger event configuration of line 9
    static constexpr uint32_t FTSR_TR10 = 0x400;         // Falling trigger event configuration of line 10
    static constexpr uint32_t FTSR_TR11 = 0x800;         // Falling trigger event configuration of line 11
    static constexpr uint32_t FTSR_TR12 = 0x1000;        // Falling trigger event configuration of line 12
    static constexpr uint32_t FTSR_TR13 = 0x2000;        // Falling trigger event configuration of line 13
    static constexpr uint32_t FTSR_TR14 = 0x4000;        // Falling trigger event configuration of line 14
    static constexpr uint32_t FTSR_TR15 = 0x8000;        // Falling trigger event configuration of line 15
    static constexpr uint32_t FTSR_TR16 = 0x10000;       // Falling trigger event configuration of line 16
    static constexpr uint32_t FTSR_TR17 = 0x20000;       // Falling trigger event configuration of line 17
    static constexpr uint32_t FTSR_TR18 = 0x40000;       // Falling trigger event configuration of line 18
    static constexpr uint32_t FTSR_TR19 = 0x80000;       // Falling trigger event configuration of line 19
    static constexpr uint32_t FTSR_TR20 = 0x100000;      // Falling trigger event configuration of line 20
    static constexpr uint32_t FTSR_TR21 = 0x200000;      // Falling trigger event configuration of line 21
    static constexpr uint32_t FTSR_TR22 = 0x400000;      // Falling trigger event configuration of line 22
    static const uint32_t FTSR_RESET_VALUE = 0x0;

    static constexpr uint32_t SWIER_SWIER0 = 0x1;         // Software Interrupt on line 0
    static constexpr uint32_t SWIER_SWIER1 = 0x2;         // Software Interrupt on line 1
    static constexpr uint32_t SWIER_SWIER2 = 0x4;         // Software Interrupt on line 2
    static constexpr uint32_t SWIER_SWIER3 = 0x8;         // Software Interrupt on line 3
    static constexpr uint32_t SWIER_SWIER4 = 0x10;        // Software Interrupt on line 4
    static constexpr uint32_t SWIER_SWIER5 = 0x20;        // Software Interrupt on line 5
    static constexpr uint32_t SWIER_SWIER6 = 0x40;        // Software Interrupt on line 6
    static constexpr uint32_t SWIER_SWIER7 = 0x80;        // Software Interrupt on line 7
    static constexpr uint32_t SWIER_SWIER8 = 0x100;       // Software Interrupt on line 8
    static constexpr uint32_t SWIER_SWIER9 = 0x200;       // Software Interrupt on line 9
    static constexpr uint32_t SWIER_SWIER10 = 0x400;      // Software Interrupt on line 10
    static constexpr uint32_t SWIER_SWIER11 = 0x800;      // Software Interrupt on line 11
    static constexpr uint32_t SWIER_SWIER12 = 0x1000;     // Software Interrupt on line 12
    static constexpr uint32_t SWIER_SWIER13 = 0x2000;     // Software Interrupt on line 13
    static constexpr uint32_t SWIER_SWIER14 = 0x4000;     // Software Interrupt on line 14
    static constexpr uint32_t SWIER_SWIER15 = 0x8000;     // Software Interrupt on line 15
    static constexpr uint32_t SWIER_SWIER16 = 0x10000;    // Software Interrupt on line 16
    static constexpr uint32_t SWIER_SWIER17 = 0x20000;    // Software Interrupt on line 17
    static constexpr uint32_t SWIER_SWIER18 = 0x40000;    // Software Interrupt on line 18
    static constexpr uint32_t SWIER_SWIER19 = 0x80000;    // Software Interrupt on line 19
    static constexpr uint32_t SWIER_SWIER20 = 0x100000;   // Software Interrupt on line 20
    static constexpr uint32_t SWIER_SWIER21 = 0x200000;   // Software Interrupt on line 21
    static constexpr uint32_t SWIER_SWIER22 = 0x400000;   // Software Interrupt on line 22
    static const uint32_t SWIER_RESET_VALUE = 0x0;

    static constexpr uint32_t PR_PR0 = 0x1;            // Pending bit 0
    static constexpr uint32_t PR_PR1 = 0x2;            // Pending bit 1
    static constexpr uint32_t PR_PR2 = 0x4;            // Pending bit 2
    static constexpr uint32_t PR_PR3 = 0x8;            // Pending bit 3
    static constexpr uint32_t PR_PR4 = 0x10;           // Pending bit 4
    static constexpr uint32_t PR_PR5 = 0x20;           // Pending bit 5
    static constexpr uint32_t PR_PR6 = 0x40;           // Pending bit 6
    static constexpr uint32_t PR_PR7 = 0x80;           // Pending bit 7
    static constexpr uint32_t PR_PR8 = 0x100;          // Pending bit 8
    static constexpr uint32_t PR_PR9 = 0x200;          // Pending bit 9
    static constexpr uint32_t PR_PR10 = 0x400;         // Pending bit 10
    static constexpr uint32_t PR_PR11 = 0x800;         // Pending bit 11
    static constexpr uint32_t PR_PR12 = 0x1000;        // Pending bit 12
    static constexpr uint32_t PR_PR13 = 0x2000;        // Pending bit 13
    static constexpr uint32_t PR_PR14 = 0x4000;        // Pending bit 14
    static constexpr uint32_t PR_PR15 = 0x8000;        // Pending bit 15
    static constexpr uint32_t PR_PR16 = 0x10000;       // Pending bit 16
    static constexpr uint32_t PR_PR17 = 0x20000;       // Pending bit 17
    static constexpr uint32_t PR_PR18 = 0x40000;       // Pending bit 18
    static constexpr uint32_t PR_PR19 = 0x80000;       // Pending bit 19
    static constexpr uint32_t PR_PR20 = 0x100000;      // Pending bit 20
    static constexpr uint32_t PR_PR21 = 0x200000;      // Pending bit 21
    static constexpr uint32_t PR_PR22 = 0x400000;      // Pending bit 22
    static const uint32_t PR_RESET_VALUE = 0x0;

    static constexpr uint8_t EXTI0 = 6; // EXTI Line0 interrupt
    static constexpr uint8_t EXTI1 = 7; // EXTI Line1 interrupt
    static constexpr uint8_t EXTI15_10 = 40; // EXTI Line[15:10] interrupts
    static constexpr uint8_t EXTI2 = 8; // EXTI Line2 interrupt
    static constexpr uint8_t EXTI3 = 9; // EXTI Line3 interrupt
    static constexpr uint8_t EXTI4 = 10; // EXTI Line4 interrupt
    static constexpr uint8_t EXTI9_5 = 23; // EXTI Line[9:5] interrupts
    static constexpr uint8_t TAMP_STAMP = 2; // Tamper and TimeStamp interrupts through the EXTI line
};

static exti_t& EXTI = *reinterpret_cast<exti_t*>(0x40013c00);

#define HAVE_PERIPHERAL_EXTI


////
//
//    FLASH
//
////

struct flash_t
{
    volatile uint32_t    ACR;                  // Flash access control register
    volatile uint32_t    KEYR;                 // [Write-only] Flash key register
    volatile uint32_t    OPTKEYR;              // [Write-only] Flash option key register
    volatile uint32_t    SR;                   // Status register
    volatile uint32_t    CR;                   // [Read-write] Control register
    volatile uint32_t    OPTCR;                // [Read-write] Flash option control register

    template<uint32_t X>
    static constexpr uint32_t ACR_LATENCY =             // Latency (3 bits), Read-write
        bit_field_t<0, 0x7>::value<X>();
    static constexpr uint32_t ACR_PRFTEN = 0x100;       // Prefetch enable, Read-write
    static constexpr uint32_t ACR_ICEN = 0x200;         // Instruction cache enable, Read-write
    static constexpr uint32_t ACR_DCEN = 0x400;         // Data cache enable, Read-write
    static constexpr uint32_t ACR_ICRST = 0x800;        // Instruction cache reset, Write-only
    static constexpr uint32_t ACR_DCRST = 0x1000;       // Data cache reset, Read-write
    static const uint32_t ACR_RESET_VALUE = 0x0;


    static const uint32_t KEYR_RESET_VALUE = 0x0;


    static const uint32_t OPTKEYR_RESET_VALUE = 0x0;

    static constexpr uint32_t SR_EOP = 0x1;            // End of operation, Read-write
    static constexpr uint32_t SR_OPERR = 0x2;          // Operation error, Read-write
    static constexpr uint32_t SR_WRPERR = 0x10;        // Write protection error, Read-write
    static constexpr uint32_t SR_PGAERR = 0x20;        // Programming alignment error, Read-write
    static constexpr uint32_t SR_PGPERR = 0x40;        // Programming parallelism error, Read-write
    static constexpr uint32_t SR_PGSERR = 0x80;        // Programming sequence error, Read-write
    static constexpr uint32_t SR_BSY = 0x10000;        // Busy, Read-only
    static const uint32_t SR_RESET_VALUE = 0x0;

    static constexpr uint32_t CR_PG = 0x1;             // Programming
    static constexpr uint32_t CR_SER = 0x2;            // Sector Erase
    static constexpr uint32_t CR_MER = 0x4;            // Mass Erase
    template<uint32_t X>
    static constexpr uint32_t CR_SNB =                 // Sector number (4 bits)
        bit_field_t<3, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CR_PSIZE =               // Program size (2 bits)
        bit_field_t<8, 0x3>::value<X>();
    static constexpr uint32_t CR_STRT = 0x10000;       // Start
    static constexpr uint32_t CR_EOPIE = 0x1000000;    // End of operation interrupt enable
    static constexpr uint32_t CR_ERRIE = 0x2000000;    // Error interrupt enable
    static constexpr uint32_t CR_LOCK = 0x80000000;    // Lock
    static const uint32_t CR_RESET_VALUE = 0x80000000;

    static constexpr uint32_t OPTCR_OPTLOCK = 0x1;        // Option lock
    static constexpr uint32_t OPTCR_OPTSTRT = 0x2;        // Option start
    template<uint32_t X>
    static constexpr uint32_t OPTCR_BOR_LEV =             // BOR reset Level (2 bits)
        bit_field_t<2, 0x3>::value<X>();
    static constexpr uint32_t OPTCR_WDG_SW = 0x20;        // WDG_SW User option bytes
    static constexpr uint32_t OPTCR_nRST_STOP = 0x40;     // nRST_STOP User option bytes
    static constexpr uint32_t OPTCR_nRST_STDBY = 0x80;    // nRST_STDBY User option bytes
    template<uint32_t X>
    static constexpr uint32_t OPTCR_RDP =                 // Read protect (8 bits)
        bit_field_t<8, 0xff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OPTCR_nWRP =                // Not write protect (12 bits)
        bit_field_t<16, 0xfff>::value<X>();
    static const uint32_t OPTCR_RESET_VALUE = 0x14;

    static constexpr uint8_t FLASH = 4; // FLASH global interrupt
};

static flash_t& FLASH = *reinterpret_cast<flash_t*>(0x40023c00);

#define HAVE_PERIPHERAL_FLASH


////
//
//    Independent watchdog
//
////

struct iwdg_t
{
    volatile uint32_t    KR;                   // [Write-only] Key register
    volatile uint32_t    PR;                   // [Read-write] Prescaler register
    volatile uint32_t    RLR;                  // [Read-write] Reload register
    volatile uint32_t    SR;                   // [Read-only] Status register

    template<uint32_t X>
    static constexpr uint32_t KR_KEY =                 // Key value (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t KR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t PR_PR =                  // Prescaler divider (3 bits)
        bit_field_t<0, 0x7>::value<X>();
    static const uint32_t PR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t RLR_RL =                  // Watchdog counter reload value (12 bits)
        bit_field_t<0, 0xfff>::value<X>();
    static const uint32_t RLR_RESET_VALUE = 0xfff;

    static constexpr uint32_t SR_RVU = 0x2;            // Watchdog counter reload value update
    static constexpr uint32_t SR_PVU = 0x1;            // Watchdog prescaler value update
    static const uint32_t SR_RESET_VALUE = 0x0;
};

static iwdg_t& IWDG = *reinterpret_cast<iwdg_t*>(0x40003000);

#define HAVE_PERIPHERAL_IWDG


////
//
//    USB on the go full speed
//
////

struct otg_fs_device_t
{
    volatile uint32_t    FS_DCFG;              // [Read-write] OTG_FS device configuration register (OTG_FS_DCFG)
    volatile uint32_t    FS_DCTL;              // OTG_FS device control register (OTG_FS_DCTL)
    volatile uint32_t    FS_DSTS;              // [Read-only] OTG_FS device status register (OTG_FS_DSTS)
    reserved_t<1>        _0;
    volatile uint32_t    FS_DIEPMSK;           // [Read-write] OTG_FS device IN endpoint common interrupt mask register (OTG_FS_DIEPMSK)
    volatile uint32_t    FS_DOEPMSK;           // [Read-write] OTG_FS device OUT endpoint common interrupt mask register (OTG_FS_DOEPMSK)
    volatile uint32_t    FS_DAINT;             // [Read-only] OTG_FS device all endpoints interrupt register (OTG_FS_DAINT)
    volatile uint32_t    FS_DAINTMSK;          // [Read-write] OTG_FS all endpoints interrupt mask register (OTG_FS_DAINTMSK)
    reserved_t<2>        _1;
    volatile uint32_t    DVBUSDIS;             // [Read-write] OTG_FS device VBUS discharge time register
    volatile uint32_t    DVBUSPULSE;           // [Read-write] OTG_FS device VBUS pulsing time register
    reserved_t<1>        _2;
    volatile uint32_t    DIEPEMPMSK;           // [Read-write] OTG_FS device IN endpoint FIFO empty interrupt mask register
    reserved_t<50>       _3;
    volatile uint32_t    FS_DIEPCTL0;          // OTG_FS device control IN endpoint 0 control register (OTG_FS_DIEPCTL0)
    reserved_t<1>        _4;
    volatile uint32_t    DIEPINT0;             // device endpoint-x interrupt register
    reserved_t<1>        _5;
    volatile uint32_t    DIEPTSIZ0;            // [Read-write] device endpoint-0 transfer size register
    reserved_t<1>        _6;
    volatile uint32_t    DTXFSTS0;             // [Read-only] OTG_FS device IN endpoint transmit FIFO status register
    reserved_t<1>        _7;
    volatile uint32_t    DIEPCTL1;             // OTG device endpoint-1 control register
    reserved_t<1>        _8;
    volatile uint32_t    DIEPINT1;             // device endpoint-1 interrupt register
    reserved_t<1>        _9;
    volatile uint32_t    DIEPTSIZ1;            // [Read-write] device endpoint-1 transfer size register
    reserved_t<1>        _10;
    volatile uint32_t    DTXFSTS1;             // [Read-only] OTG_FS device IN endpoint transmit FIFO status register
    reserved_t<1>        _11;
    volatile uint32_t    DIEPCTL2;             // OTG device endpoint-2 control register
    reserved_t<1>        _12;
    volatile uint32_t    DIEPINT2;             // device endpoint-2 interrupt register
    reserved_t<1>        _13;
    volatile uint32_t    DIEPTSIZ2;            // [Read-write] device endpoint-2 transfer size register
    reserved_t<1>        _14;
    volatile uint32_t    DTXFSTS2;             // [Read-only] OTG_FS device IN endpoint transmit FIFO status register
    reserved_t<1>        _15;
    volatile uint32_t    DIEPCTL3;             // OTG device endpoint-3 control register
    reserved_t<1>        _16;
    volatile uint32_t    DIEPINT3;             // device endpoint-3 interrupt register
    reserved_t<1>        _17;
    volatile uint32_t    DIEPTSIZ3;            // [Read-write] device endpoint-3 transfer size register
    reserved_t<1>        _18;
    volatile uint32_t    DTXFSTS3;             // [Read-only] OTG_FS device IN endpoint transmit FIFO status register
    reserved_t<97>       _19;
    volatile uint32_t    DOEPCTL0;             // device endpoint-0 control register
    reserved_t<1>        _20;
    volatile uint32_t    DOEPINT0;             // [Read-write] device endpoint-0 interrupt register
    reserved_t<1>        _21;
    volatile uint32_t    DOEPTSIZ0;            // [Read-write] device OUT endpoint-0 transfer size register
    reserved_t<3>        _22;
    volatile uint32_t    DOEPCTL1;             // device endpoint-1 control register
    reserved_t<1>        _23;
    volatile uint32_t    DOEPINT1;             // [Read-write] device endpoint-1 interrupt register
    reserved_t<1>        _24;
    volatile uint32_t    DOEPTSIZ1;            // [Read-write] device OUT endpoint-1 transfer size register
    reserved_t<3>        _25;
    volatile uint32_t    DOEPCTL2;             // device endpoint-2 control register
    reserved_t<1>        _26;
    volatile uint32_t    DOEPINT2;             // [Read-write] device endpoint-2 interrupt register
    reserved_t<1>        _27;
    volatile uint32_t    DOEPTSIZ2;            // [Read-write] device OUT endpoint-2 transfer size register
    reserved_t<3>        _28;
    volatile uint32_t    DOEPCTL3;             // device endpoint-3 control register
    reserved_t<1>        _29;
    volatile uint32_t    DOEPINT3;             // [Read-write] device endpoint-3 interrupt register
    reserved_t<1>        _30;
    volatile uint32_t    DOEPTSIZ3;            // [Read-write] device OUT endpoint-3 transfer size register

    template<uint32_t X>
    static constexpr uint32_t FS_DCFG_DSPD =                // Device speed (2 bits)
        bit_field_t<0, 0x3>::value<X>();
    static constexpr uint32_t FS_DCFG_NZLSOHSK = 0x4;       // Non-zero-length status OUT handshake
    template<uint32_t X>
    static constexpr uint32_t FS_DCFG_DAD =                 // Device address (7 bits)
        bit_field_t<4, 0x7f>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t FS_DCFG_PFIVL =               // Periodic frame interval (2 bits)
        bit_field_t<11, 0x3>::value<X>();
    static const uint32_t FS_DCFG_RESET_VALUE = 0x2200000;

    static constexpr uint32_t FS_DCTL_RWUSIG = 0x1;         // Remote wakeup signaling, Read-write
    static constexpr uint32_t FS_DCTL_SDIS = 0x2;           // Soft disconnect, Read-write
    static constexpr uint32_t FS_DCTL_GINSTS = 0x4;         // Global IN NAK status, Read-only
    static constexpr uint32_t FS_DCTL_GONSTS = 0x8;         // Global OUT NAK status, Read-only
    template<uint32_t X>
    static constexpr uint32_t FS_DCTL_TCTL =                // Test control (3 bits), Read-write
        bit_field_t<4, 0x7>::value<X>();
    static constexpr uint32_t FS_DCTL_SGINAK = 0x80;        // Set global IN NAK, Read-write
    static constexpr uint32_t FS_DCTL_CGINAK = 0x100;       // Clear global IN NAK, Read-write
    static constexpr uint32_t FS_DCTL_SGONAK = 0x200;       // Set global OUT NAK, Read-write
    static constexpr uint32_t FS_DCTL_CGONAK = 0x400;       // Clear global OUT NAK, Read-write
    static constexpr uint32_t FS_DCTL_POPRGDNE = 0x800;     // Power-on programming done, Read-write
    static const uint32_t FS_DCTL_RESET_VALUE = 0x0;

    static constexpr uint32_t FS_DSTS_SUSPSTS = 0x1;        // Suspend status
    template<uint32_t X>
    static constexpr uint32_t FS_DSTS_ENUMSPD =             // Enumerated speed (2 bits)
        bit_field_t<1, 0x3>::value<X>();
    static constexpr uint32_t FS_DSTS_EERR = 0x8;           // Erratic error
    template<uint32_t X>
    static constexpr uint32_t FS_DSTS_FNSOF =               // Frame number of the received SOF (14 bits)
        bit_field_t<8, 0x3fff>::value<X>();
    static const uint32_t FS_DSTS_RESET_VALUE = 0x10;

    static constexpr uint32_t FS_DIEPMSK_XFRCM = 0x1;          // Transfer completed interrupt mask
    static constexpr uint32_t FS_DIEPMSK_EPDM = 0x2;           // Endpoint disabled interrupt mask
    static constexpr uint32_t FS_DIEPMSK_TOM = 0x8;            // Timeout condition mask (Non-isochronous endpoints)
    static constexpr uint32_t FS_DIEPMSK_ITTXFEMSK = 0x10;     // IN token received when TxFIFO empty mask
    static constexpr uint32_t FS_DIEPMSK_INEPNMM = 0x20;       // IN token received with EP mismatch mask
    static constexpr uint32_t FS_DIEPMSK_INEPNEM = 0x40;       // IN endpoint NAK effective mask
    static const uint32_t FS_DIEPMSK_RESET_VALUE = 0x0;

    static constexpr uint32_t FS_DOEPMSK_XFRCM = 0x1;          // Transfer completed interrupt mask
    static constexpr uint32_t FS_DOEPMSK_EPDM = 0x2;           // Endpoint disabled interrupt mask
    static constexpr uint32_t FS_DOEPMSK_STUPM = 0x8;          // SETUP phase done mask
    static constexpr uint32_t FS_DOEPMSK_OTEPDM = 0x10;        // OUT token received when endpoint disabled mask
    static const uint32_t FS_DOEPMSK_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t FS_DAINT_IEPINT =              // IN endpoint interrupt bits (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t FS_DAINT_OEPINT =              // OUT endpoint interrupt bits (16 bits)
        bit_field_t<16, 0xffff>::value<X>();
    static const uint32_t FS_DAINT_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t FS_DAINTMSK_IEPM =                // IN EP interrupt mask bits (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t FS_DAINTMSK_OEPINT =              // OUT endpoint interrupt bits (16 bits)
        bit_field_t<16, 0xffff>::value<X>();
    static const uint32_t FS_DAINTMSK_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t DVBUSDIS_VBUSDT =              // Device VBUS discharge time (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t DVBUSDIS_RESET_VALUE = 0x17d7;

    template<uint32_t X>
    static constexpr uint32_t DVBUSPULSE_DVBUSP =              // Device VBUS pulsing time (12 bits)
        bit_field_t<0, 0xfff>::value<X>();
    static const uint32_t DVBUSPULSE_RESET_VALUE = 0x5b8;

    template<uint32_t X>
    static constexpr uint32_t DIEPEMPMSK_INEPTXFEM =           // IN EP Tx FIFO empty interrupt mask bits (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t DIEPEMPMSK_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t FS_DIEPCTL0_MPSIZ =               // Maximum packet size (2 bits), Read-write
        bit_field_t<0, 0x3>::value<X>();
    static constexpr uint32_t FS_DIEPCTL0_USBAEP = 0x8000;      // USB active endpoint, Read-only
    static constexpr uint32_t FS_DIEPCTL0_NAKSTS = 0x20000;     // NAK status, Read-only
    template<uint32_t X>
    static constexpr uint32_t FS_DIEPCTL0_EPTYP =               // Endpoint type (2 bits), Read-only
        bit_field_t<18, 0x3>::value<X>();
    static constexpr uint32_t FS_DIEPCTL0_STALL = 0x200000;     // STALL handshake, Read-write
    template<uint32_t X>
    static constexpr uint32_t FS_DIEPCTL0_TXFNUM =              // TxFIFO number (4 bits), Read-write
        bit_field_t<22, 0xf>::value<X>();
    static constexpr uint32_t FS_DIEPCTL0_CNAK = 0x4000000;     // Clear NAK, Write-only
    static constexpr uint32_t FS_DIEPCTL0_SNAK = 0x8000000;     // Set NAK, Write-only
    static constexpr uint32_t FS_DIEPCTL0_EPDIS = 0x40000000;   // Endpoint disable, Read-only
    static constexpr uint32_t FS_DIEPCTL0_EPENA = 0x80000000;   // Endpoint enable, Read-only
    static const uint32_t FS_DIEPCTL0_RESET_VALUE = 0x0;

    static constexpr uint32_t DIEPINT0_TXFE = 0x80;          // TXFE, Read-only
    static constexpr uint32_t DIEPINT0_INEPNE = 0x40;        // INEPNE, Read-write
    static constexpr uint32_t DIEPINT0_ITTXFE = 0x10;        // ITTXFE, Read-write
    static constexpr uint32_t DIEPINT0_TOC = 0x8;            // TOC, Read-write
    static constexpr uint32_t DIEPINT0_EPDISD = 0x2;         // EPDISD, Read-write
    static constexpr uint32_t DIEPINT0_XFRC = 0x1;           // XFRC, Read-write
    static const uint32_t DIEPINT0_RESET_VALUE = 0x80;

    template<uint32_t X>
    static constexpr uint32_t DIEPTSIZ0_PKTCNT =              // Packet count (2 bits)
        bit_field_t<19, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t DIEPTSIZ0_XFRSIZ =              // Transfer size (7 bits)
        bit_field_t<0, 0x7f>::value<X>();
    static const uint32_t DIEPTSIZ0_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t DTXFSTS0_INEPTFSAV =           // IN endpoint TxFIFO space available (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t DTXFSTS0_RESET_VALUE = 0x0;

    static constexpr uint32_t DIEPCTL1_EPENA = 0x80000000;   // EPENA, Read-write
    static constexpr uint32_t DIEPCTL1_EPDIS = 0x40000000;   // EPDIS, Read-write
    static constexpr uint32_t DIEPCTL1_SODDFRM_SD1PID = 0x20000000;// SODDFRM/SD1PID, Write-only
    static constexpr uint32_t DIEPCTL1_SD0PID_SEVNFRM = 0x10000000;// SD0PID/SEVNFRM, Write-only
    static constexpr uint32_t DIEPCTL1_SNAK = 0x8000000;     // SNAK, Write-only
    static constexpr uint32_t DIEPCTL1_CNAK = 0x4000000;     // CNAK, Write-only
    template<uint32_t X>
    static constexpr uint32_t DIEPCTL1_TXFNUM =              // TXFNUM (4 bits), Read-write
        bit_field_t<22, 0xf>::value<X>();
    static constexpr uint32_t DIEPCTL1_Stall = 0x200000;     // Stall, Read-write
    template<uint32_t X>
    static constexpr uint32_t DIEPCTL1_EPTYP =               // EPTYP (2 bits), Read-write
        bit_field_t<18, 0x3>::value<X>();
    static constexpr uint32_t DIEPCTL1_NAKSTS = 0x20000;     // NAKSTS, Read-only
    static constexpr uint32_t DIEPCTL1_EONUM_DPID = 0x10000; // EONUM/DPID, Read-only
    static constexpr uint32_t DIEPCTL1_USBAEP = 0x8000;      // USBAEP, Read-write
    template<uint32_t X>
    static constexpr uint32_t DIEPCTL1_MPSIZ =               // MPSIZ (11 bits), Read-write
        bit_field_t<0, 0x7ff>::value<X>();
    static const uint32_t DIEPCTL1_RESET_VALUE = 0x0;

    static constexpr uint32_t DIEPINT1_TXFE = 0x80;          // TXFE, Read-only
    static constexpr uint32_t DIEPINT1_INEPNE = 0x40;        // INEPNE, Read-write
    static constexpr uint32_t DIEPINT1_ITTXFE = 0x10;        // ITTXFE, Read-write
    static constexpr uint32_t DIEPINT1_TOC = 0x8;            // TOC, Read-write
    static constexpr uint32_t DIEPINT1_EPDISD = 0x2;         // EPDISD, Read-write
    static constexpr uint32_t DIEPINT1_XFRC = 0x1;           // XFRC, Read-write
    static const uint32_t DIEPINT1_RESET_VALUE = 0x80;

    template<uint32_t X>
    static constexpr uint32_t DIEPTSIZ1_MCNT =                // Multi count (2 bits)
        bit_field_t<29, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t DIEPTSIZ1_PKTCNT =              // Packet count (10 bits)
        bit_field_t<19, 0x3ff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t DIEPTSIZ1_XFRSIZ =              // Transfer size (19 bits)
        bit_field_t<0, 0x7ffff>::value<X>();
    static const uint32_t DIEPTSIZ1_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t DTXFSTS1_INEPTFSAV =           // IN endpoint TxFIFO space available (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t DTXFSTS1_RESET_VALUE = 0x0;

    static constexpr uint32_t DIEPCTL2_EPENA = 0x80000000;   // EPENA, Read-write
    static constexpr uint32_t DIEPCTL2_EPDIS = 0x40000000;   // EPDIS, Read-write
    static constexpr uint32_t DIEPCTL2_SODDFRM = 0x20000000; // SODDFRM, Write-only
    static constexpr uint32_t DIEPCTL2_SD0PID_SEVNFRM = 0x10000000;// SD0PID/SEVNFRM, Write-only
    static constexpr uint32_t DIEPCTL2_SNAK = 0x8000000;     // SNAK, Write-only
    static constexpr uint32_t DIEPCTL2_CNAK = 0x4000000;     // CNAK, Write-only
    template<uint32_t X>
    static constexpr uint32_t DIEPCTL2_TXFNUM =              // TXFNUM (4 bits), Read-write
        bit_field_t<22, 0xf>::value<X>();
    static constexpr uint32_t DIEPCTL2_Stall = 0x200000;     // Stall, Read-write
    template<uint32_t X>
    static constexpr uint32_t DIEPCTL2_EPTYP =               // EPTYP (2 bits), Read-write
        bit_field_t<18, 0x3>::value<X>();
    static constexpr uint32_t DIEPCTL2_NAKSTS = 0x20000;     // NAKSTS, Read-only
    static constexpr uint32_t DIEPCTL2_EONUM_DPID = 0x10000; // EONUM/DPID, Read-only
    static constexpr uint32_t DIEPCTL2_USBAEP = 0x8000;      // USBAEP, Read-write
    template<uint32_t X>
    static constexpr uint32_t DIEPCTL2_MPSIZ =               // MPSIZ (11 bits), Read-write
        bit_field_t<0, 0x7ff>::value<X>();
    static const uint32_t DIEPCTL2_RESET_VALUE = 0x0;

    static constexpr uint32_t DIEPINT2_TXFE = 0x80;          // TXFE, Read-only
    static constexpr uint32_t DIEPINT2_INEPNE = 0x40;        // INEPNE, Read-write
    static constexpr uint32_t DIEPINT2_ITTXFE = 0x10;        // ITTXFE, Read-write
    static constexpr uint32_t DIEPINT2_TOC = 0x8;            // TOC, Read-write
    static constexpr uint32_t DIEPINT2_EPDISD = 0x2;         // EPDISD, Read-write
    static constexpr uint32_t DIEPINT2_XFRC = 0x1;           // XFRC, Read-write
    static const uint32_t DIEPINT2_RESET_VALUE = 0x80;

    template<uint32_t X>
    static constexpr uint32_t DIEPTSIZ2_MCNT =                // Multi count (2 bits)
        bit_field_t<29, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t DIEPTSIZ2_PKTCNT =              // Packet count (10 bits)
        bit_field_t<19, 0x3ff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t DIEPTSIZ2_XFRSIZ =              // Transfer size (19 bits)
        bit_field_t<0, 0x7ffff>::value<X>();
    static const uint32_t DIEPTSIZ2_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t DTXFSTS2_INEPTFSAV =           // IN endpoint TxFIFO space available (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t DTXFSTS2_RESET_VALUE = 0x0;

    static constexpr uint32_t DIEPCTL3_EPENA = 0x80000000;   // EPENA, Read-write
    static constexpr uint32_t DIEPCTL3_EPDIS = 0x40000000;   // EPDIS, Read-write
    static constexpr uint32_t DIEPCTL3_SODDFRM = 0x20000000; // SODDFRM, Write-only
    static constexpr uint32_t DIEPCTL3_SD0PID_SEVNFRM = 0x10000000;// SD0PID/SEVNFRM, Write-only
    static constexpr uint32_t DIEPCTL3_SNAK = 0x8000000;     // SNAK, Write-only
    static constexpr uint32_t DIEPCTL3_CNAK = 0x4000000;     // CNAK, Write-only
    template<uint32_t X>
    static constexpr uint32_t DIEPCTL3_TXFNUM =              // TXFNUM (4 bits), Read-write
        bit_field_t<22, 0xf>::value<X>();
    static constexpr uint32_t DIEPCTL3_Stall = 0x200000;     // Stall, Read-write
    template<uint32_t X>
    static constexpr uint32_t DIEPCTL3_EPTYP =               // EPTYP (2 bits), Read-write
        bit_field_t<18, 0x3>::value<X>();
    static constexpr uint32_t DIEPCTL3_NAKSTS = 0x20000;     // NAKSTS, Read-only
    static constexpr uint32_t DIEPCTL3_EONUM_DPID = 0x10000; // EONUM/DPID, Read-only
    static constexpr uint32_t DIEPCTL3_USBAEP = 0x8000;      // USBAEP, Read-write
    template<uint32_t X>
    static constexpr uint32_t DIEPCTL3_MPSIZ =               // MPSIZ (11 bits), Read-write
        bit_field_t<0, 0x7ff>::value<X>();
    static const uint32_t DIEPCTL3_RESET_VALUE = 0x0;

    static constexpr uint32_t DIEPINT3_TXFE = 0x80;          // TXFE, Read-only
    static constexpr uint32_t DIEPINT3_INEPNE = 0x40;        // INEPNE, Read-write
    static constexpr uint32_t DIEPINT3_ITTXFE = 0x10;        // ITTXFE, Read-write
    static constexpr uint32_t DIEPINT3_TOC = 0x8;            // TOC, Read-write
    static constexpr uint32_t DIEPINT3_EPDISD = 0x2;         // EPDISD, Read-write
    static constexpr uint32_t DIEPINT3_XFRC = 0x1;           // XFRC, Read-write
    static const uint32_t DIEPINT3_RESET_VALUE = 0x80;

    template<uint32_t X>
    static constexpr uint32_t DIEPTSIZ3_MCNT =                // Multi count (2 bits)
        bit_field_t<29, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t DIEPTSIZ3_PKTCNT =              // Packet count (10 bits)
        bit_field_t<19, 0x3ff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t DIEPTSIZ3_XFRSIZ =              // Transfer size (19 bits)
        bit_field_t<0, 0x7ffff>::value<X>();
    static const uint32_t DIEPTSIZ3_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t DTXFSTS3_INEPTFSAV =           // IN endpoint TxFIFO space available (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t DTXFSTS3_RESET_VALUE = 0x0;

    static constexpr uint32_t DOEPCTL0_EPENA = 0x80000000;   // EPENA, Write-only
    static constexpr uint32_t DOEPCTL0_EPDIS = 0x40000000;   // EPDIS, Read-only
    static constexpr uint32_t DOEPCTL0_SNAK = 0x8000000;     // SNAK, Write-only
    static constexpr uint32_t DOEPCTL0_CNAK = 0x4000000;     // CNAK, Write-only
    static constexpr uint32_t DOEPCTL0_Stall = 0x200000;     // Stall, Read-write
    static constexpr uint32_t DOEPCTL0_SNPM = 0x100000;      // SNPM, Read-write
    template<uint32_t X>
    static constexpr uint32_t DOEPCTL0_EPTYP =               // EPTYP (2 bits), Read-only
        bit_field_t<18, 0x3>::value<X>();
    static constexpr uint32_t DOEPCTL0_NAKSTS = 0x20000;     // NAKSTS, Read-only
    static constexpr uint32_t DOEPCTL0_USBAEP = 0x8000;      // USBAEP, Read-only
    template<uint32_t X>
    static constexpr uint32_t DOEPCTL0_MPSIZ =               // MPSIZ (2 bits), Read-only
        bit_field_t<0, 0x3>::value<X>();
    static const uint32_t DOEPCTL0_RESET_VALUE = 0x8000;

    static constexpr uint32_t DOEPINT0_B2BSTUP = 0x40;       // B2BSTUP
    static constexpr uint32_t DOEPINT0_OTEPDIS = 0x10;       // OTEPDIS
    static constexpr uint32_t DOEPINT0_STUP = 0x8;           // STUP
    static constexpr uint32_t DOEPINT0_EPDISD = 0x2;         // EPDISD
    static constexpr uint32_t DOEPINT0_XFRC = 0x1;           // XFRC
    static const uint32_t DOEPINT0_RESET_VALUE = 0x80;

    template<uint32_t X>
    static constexpr uint32_t DOEPTSIZ0_STUPCNT =             // SETUP packet count (2 bits)
        bit_field_t<29, 0x3>::value<X>();
    static constexpr uint32_t DOEPTSIZ0_PKTCNT = 0x80000;     // Packet count
    template<uint32_t X>
    static constexpr uint32_t DOEPTSIZ0_XFRSIZ =              // Transfer size (7 bits)
        bit_field_t<0, 0x7f>::value<X>();
    static const uint32_t DOEPTSIZ0_RESET_VALUE = 0x0;

    static constexpr uint32_t DOEPCTL1_EPENA = 0x80000000;   // EPENA, Read-write
    static constexpr uint32_t DOEPCTL1_EPDIS = 0x40000000;   // EPDIS, Read-write
    static constexpr uint32_t DOEPCTL1_SODDFRM = 0x20000000; // SODDFRM, Write-only
    static constexpr uint32_t DOEPCTL1_SD0PID_SEVNFRM = 0x10000000;// SD0PID/SEVNFRM, Write-only
    static constexpr uint32_t DOEPCTL1_SNAK = 0x8000000;     // SNAK, Write-only
    static constexpr uint32_t DOEPCTL1_CNAK = 0x4000000;     // CNAK, Write-only
    static constexpr uint32_t DOEPCTL1_Stall = 0x200000;     // Stall, Read-write
    static constexpr uint32_t DOEPCTL1_SNPM = 0x100000;      // SNPM, Read-write
    template<uint32_t X>
    static constexpr uint32_t DOEPCTL1_EPTYP =               // EPTYP (2 bits), Read-write
        bit_field_t<18, 0x3>::value<X>();
    static constexpr uint32_t DOEPCTL1_NAKSTS = 0x20000;     // NAKSTS, Read-only
    static constexpr uint32_t DOEPCTL1_EONUM_DPID = 0x10000; // EONUM/DPID, Read-only
    static constexpr uint32_t DOEPCTL1_USBAEP = 0x8000;      // USBAEP, Read-write
    template<uint32_t X>
    static constexpr uint32_t DOEPCTL1_MPSIZ =               // MPSIZ (11 bits), Read-write
        bit_field_t<0, 0x7ff>::value<X>();
    static const uint32_t DOEPCTL1_RESET_VALUE = 0x0;

    static constexpr uint32_t DOEPINT1_B2BSTUP = 0x40;       // B2BSTUP
    static constexpr uint32_t DOEPINT1_OTEPDIS = 0x10;       // OTEPDIS
    static constexpr uint32_t DOEPINT1_STUP = 0x8;           // STUP
    static constexpr uint32_t DOEPINT1_EPDISD = 0x2;         // EPDISD
    static constexpr uint32_t DOEPINT1_XFRC = 0x1;           // XFRC
    static const uint32_t DOEPINT1_RESET_VALUE = 0x80;

    template<uint32_t X>
    static constexpr uint32_t DOEPTSIZ1_RXDPID_STUPCNT =      // Received data PID/SETUP packet count (2 bits)
        bit_field_t<29, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t DOEPTSIZ1_PKTCNT =              // Packet count (10 bits)
        bit_field_t<19, 0x3ff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t DOEPTSIZ1_XFRSIZ =              // Transfer size (19 bits)
        bit_field_t<0, 0x7ffff>::value<X>();
    static const uint32_t DOEPTSIZ1_RESET_VALUE = 0x0;

    static constexpr uint32_t DOEPCTL2_EPENA = 0x80000000;   // EPENA, Read-write
    static constexpr uint32_t DOEPCTL2_EPDIS = 0x40000000;   // EPDIS, Read-write
    static constexpr uint32_t DOEPCTL2_SODDFRM = 0x20000000; // SODDFRM, Write-only
    static constexpr uint32_t DOEPCTL2_SD0PID_SEVNFRM = 0x10000000;// SD0PID/SEVNFRM, Write-only
    static constexpr uint32_t DOEPCTL2_SNAK = 0x8000000;     // SNAK, Write-only
    static constexpr uint32_t DOEPCTL2_CNAK = 0x4000000;     // CNAK, Write-only
    static constexpr uint32_t DOEPCTL2_Stall = 0x200000;     // Stall, Read-write
    static constexpr uint32_t DOEPCTL2_SNPM = 0x100000;      // SNPM, Read-write
    template<uint32_t X>
    static constexpr uint32_t DOEPCTL2_EPTYP =               // EPTYP (2 bits), Read-write
        bit_field_t<18, 0x3>::value<X>();
    static constexpr uint32_t DOEPCTL2_NAKSTS = 0x20000;     // NAKSTS, Read-only
    static constexpr uint32_t DOEPCTL2_EONUM_DPID = 0x10000; // EONUM/DPID, Read-only
    static constexpr uint32_t DOEPCTL2_USBAEP = 0x8000;      // USBAEP, Read-write
    template<uint32_t X>
    static constexpr uint32_t DOEPCTL2_MPSIZ =               // MPSIZ (11 bits), Read-write
        bit_field_t<0, 0x7ff>::value<X>();
    static const uint32_t DOEPCTL2_RESET_VALUE = 0x0;

    static constexpr uint32_t DOEPINT2_B2BSTUP = 0x40;       // B2BSTUP
    static constexpr uint32_t DOEPINT2_OTEPDIS = 0x10;       // OTEPDIS
    static constexpr uint32_t DOEPINT2_STUP = 0x8;           // STUP
    static constexpr uint32_t DOEPINT2_EPDISD = 0x2;         // EPDISD
    static constexpr uint32_t DOEPINT2_XFRC = 0x1;           // XFRC
    static const uint32_t DOEPINT2_RESET_VALUE = 0x80;

    template<uint32_t X>
    static constexpr uint32_t DOEPTSIZ2_RXDPID_STUPCNT =      // Received data PID/SETUP packet count (2 bits)
        bit_field_t<29, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t DOEPTSIZ2_PKTCNT =              // Packet count (10 bits)
        bit_field_t<19, 0x3ff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t DOEPTSIZ2_XFRSIZ =              // Transfer size (19 bits)
        bit_field_t<0, 0x7ffff>::value<X>();
    static const uint32_t DOEPTSIZ2_RESET_VALUE = 0x0;

    static constexpr uint32_t DOEPCTL3_EPENA = 0x80000000;   // EPENA, Read-write
    static constexpr uint32_t DOEPCTL3_EPDIS = 0x40000000;   // EPDIS, Read-write
    static constexpr uint32_t DOEPCTL3_SODDFRM = 0x20000000; // SODDFRM, Write-only
    static constexpr uint32_t DOEPCTL3_SD0PID_SEVNFRM = 0x10000000;// SD0PID/SEVNFRM, Write-only
    static constexpr uint32_t DOEPCTL3_SNAK = 0x8000000;     // SNAK, Write-only
    static constexpr uint32_t DOEPCTL3_CNAK = 0x4000000;     // CNAK, Write-only
    static constexpr uint32_t DOEPCTL3_Stall = 0x200000;     // Stall, Read-write
    static constexpr uint32_t DOEPCTL3_SNPM = 0x100000;      // SNPM, Read-write
    template<uint32_t X>
    static constexpr uint32_t DOEPCTL3_EPTYP =               // EPTYP (2 bits), Read-write
        bit_field_t<18, 0x3>::value<X>();
    static constexpr uint32_t DOEPCTL3_NAKSTS = 0x20000;     // NAKSTS, Read-only
    static constexpr uint32_t DOEPCTL3_EONUM_DPID = 0x10000; // EONUM/DPID, Read-only
    static constexpr uint32_t DOEPCTL3_USBAEP = 0x8000;      // USBAEP, Read-write
    template<uint32_t X>
    static constexpr uint32_t DOEPCTL3_MPSIZ =               // MPSIZ (11 bits), Read-write
        bit_field_t<0, 0x7ff>::value<X>();
    static const uint32_t DOEPCTL3_RESET_VALUE = 0x0;

    static constexpr uint32_t DOEPINT3_B2BSTUP = 0x40;       // B2BSTUP
    static constexpr uint32_t DOEPINT3_OTEPDIS = 0x10;       // OTEPDIS
    static constexpr uint32_t DOEPINT3_STUP = 0x8;           // STUP
    static constexpr uint32_t DOEPINT3_EPDISD = 0x2;         // EPDISD
    static constexpr uint32_t DOEPINT3_XFRC = 0x1;           // XFRC
    static const uint32_t DOEPINT3_RESET_VALUE = 0x80;

    template<uint32_t X>
    static constexpr uint32_t DOEPTSIZ3_RXDPID_STUPCNT =      // Received data PID/SETUP packet count (2 bits)
        bit_field_t<29, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t DOEPTSIZ3_PKTCNT =              // Packet count (10 bits)
        bit_field_t<19, 0x3ff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t DOEPTSIZ3_XFRSIZ =              // Transfer size (19 bits)
        bit_field_t<0, 0x7ffff>::value<X>();
    static const uint32_t DOEPTSIZ3_RESET_VALUE = 0x0;
};

static otg_fs_device_t& OTG_FS_DEVICE = *reinterpret_cast<otg_fs_device_t*>(0x50000800);

#define HAVE_PERIPHERAL_OTG_FS_DEVICE


////
//
//    USB on the go full speed
//
////

struct otg_fs_global_t
{
    volatile uint32_t    FS_GOTGCTL;           // OTG_FS control and status register (OTG_FS_GOTGCTL)
    volatile uint32_t    FS_GOTGINT;           // [Read-write] OTG_FS interrupt register (OTG_FS_GOTGINT)
    volatile uint32_t    FS_GAHBCFG;           // [Read-write] OTG_FS AHB configuration register (OTG_FS_GAHBCFG)
    volatile uint32_t    FS_GUSBCFG;           // OTG_FS USB configuration register (OTG_FS_GUSBCFG)
    volatile uint32_t    FS_GRSTCTL;           // OTG_FS reset register (OTG_FS_GRSTCTL)
    volatile uint32_t    FS_GINTSTS;           // OTG_FS core interrupt register (OTG_FS_GINTSTS)
    volatile uint32_t    FS_GINTMSK;           // OTG_FS interrupt mask register (OTG_FS_GINTMSK)
    volatile uint32_t    FS_GRXSTSR_Device;    // [Read-only] OTG_FS Receive status debug read(Device mode)
    reserved_t<1>        _0;
    volatile uint32_t    FS_GRXFSIZ;           // [Read-write] OTG_FS Receive FIFO size register (OTG_FS_GRXFSIZ)
    volatile uint32_t    FS_GNPTXFSIZ_Device;  // [Read-write] OTG_FS non-periodic transmit FIFO size register (Device mode)
    volatile uint32_t    FS_GNPTXSTS;          // [Read-only] OTG_FS non-periodic transmit FIFO/queue status register (OTG_FS_GNPTXSTS)
    reserved_t<2>        _1;
    volatile uint32_t    FS_GCCFG;             // [Read-write] OTG_FS general core configuration register (OTG_FS_GCCFG)
    volatile uint32_t    FS_CID;               // [Read-write] core ID register
    reserved_t<48>       _2;
    volatile uint32_t    FS_HPTXFSIZ;          // [Read-write] OTG_FS Host periodic transmit FIFO size register (OTG_FS_HPTXFSIZ)
    volatile uint32_t    FS_DIEPTXF1;          // [Read-write] OTG_FS device IN endpoint transmit FIFO size register (OTG_FS_DIEPTXF2)
    volatile uint32_t    FS_DIEPTXF2;          // [Read-write] OTG_FS device IN endpoint transmit FIFO size register (OTG_FS_DIEPTXF3)
    volatile uint32_t    FS_DIEPTXF3;          // [Read-write] OTG_FS device IN endpoint transmit FIFO size register (OTG_FS_DIEPTXF4)

    static constexpr uint32_t FS_GOTGCTL_SRQSCS = 0x1;         // Session request success, Read-only
    static constexpr uint32_t FS_GOTGCTL_SRQ = 0x2;            // Session request, Read-write
    static constexpr uint32_t FS_GOTGCTL_HNGSCS = 0x100;       // Host negotiation success, Read-only
    static constexpr uint32_t FS_GOTGCTL_HNPRQ = 0x200;        // HNP request, Read-write
    static constexpr uint32_t FS_GOTGCTL_HSHNPEN = 0x400;      // Host set HNP enable, Read-write
    static constexpr uint32_t FS_GOTGCTL_DHNPEN = 0x800;       // Device HNP enabled, Read-write
    static constexpr uint32_t FS_GOTGCTL_CIDSTS = 0x10000;     // Connector ID status, Read-only
    static constexpr uint32_t FS_GOTGCTL_DBCT = 0x20000;       // Long/short debounce time, Read-only
    static constexpr uint32_t FS_GOTGCTL_ASVLD = 0x40000;      // A-session valid, Read-only
    static constexpr uint32_t FS_GOTGCTL_BSVLD = 0x80000;      // B-session valid, Read-only
    static const uint32_t FS_GOTGCTL_RESET_VALUE = 0x800;

    static constexpr uint32_t FS_GOTGINT_SEDET = 0x4;          // Session end detected
    static constexpr uint32_t FS_GOTGINT_SRSSCHG = 0x100;      // Session request success status change
    static constexpr uint32_t FS_GOTGINT_HNSSCHG = 0x200;      // Host negotiation success status change
    static constexpr uint32_t FS_GOTGINT_HNGDET = 0x20000;     // Host negotiation detected
    static constexpr uint32_t FS_GOTGINT_ADTOCHG = 0x40000;    // A-device timeout change
    static constexpr uint32_t FS_GOTGINT_DBCDNE = 0x80000;     // Debounce done
    static const uint32_t FS_GOTGINT_RESET_VALUE = 0x0;

    static constexpr uint32_t FS_GAHBCFG_GINT = 0x1;           // Global interrupt mask
    static constexpr uint32_t FS_GAHBCFG_TXFELVL = 0x80;       // TxFIFO empty level
    static constexpr uint32_t FS_GAHBCFG_PTXFELVL = 0x100;     // Periodic TxFIFO empty level
    static const uint32_t FS_GAHBCFG_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t FS_GUSBCFG_TOCAL =               // FS timeout calibration (3 bits), Read-write
        bit_field_t<0, 0x7>::value<X>();
    static constexpr uint32_t FS_GUSBCFG_PHYSEL = 0x40;        // Full Speed serial transceiver select, Write-only
    static constexpr uint32_t FS_GUSBCFG_SRPCAP = 0x100;       // SRP-capable, Read-write
    static constexpr uint32_t FS_GUSBCFG_HNPCAP = 0x200;       // HNP-capable, Read-write
    template<uint32_t X>
    static constexpr uint32_t FS_GUSBCFG_TRDT =                // USB turnaround time (4 bits), Read-write
        bit_field_t<10, 0xf>::value<X>();
    static constexpr uint32_t FS_GUSBCFG_FHMOD = 0x20000000;   // Force host mode, Read-write
    static constexpr uint32_t FS_GUSBCFG_FDMOD = 0x40000000;   // Force device mode, Read-write
    static constexpr uint32_t FS_GUSBCFG_CTXPKT = 0x80000000;  // Corrupt Tx packet, Read-write
    static const uint32_t FS_GUSBCFG_RESET_VALUE = 0xa00;

    static constexpr uint32_t FS_GRSTCTL_CSRST = 0x1;          // Core soft reset, Read-write
    static constexpr uint32_t FS_GRSTCTL_HSRST = 0x2;          // HCLK soft reset, Read-write
    static constexpr uint32_t FS_GRSTCTL_FCRST = 0x4;          // Host frame counter reset, Read-write
    static constexpr uint32_t FS_GRSTCTL_RXFFLSH = 0x10;       // RxFIFO flush, Read-write
    static constexpr uint32_t FS_GRSTCTL_TXFFLSH = 0x20;       // TxFIFO flush, Read-write
    template<uint32_t X>
    static constexpr uint32_t FS_GRSTCTL_TXFNUM =              // TxFIFO number (5 bits), Read-write
        bit_field_t<6, 0x1f>::value<X>();
    static constexpr uint32_t FS_GRSTCTL_AHBIDL = 0x80000000;  // AHB master idle, Read-only
    static const uint32_t FS_GRSTCTL_RESET_VALUE = 0x20000000;

    static constexpr uint32_t FS_GINTSTS_CMOD = 0x1;           // Current mode of operation, Read-only
    static constexpr uint32_t FS_GINTSTS_MMIS = 0x2;           // Mode mismatch interrupt, Read-write
    static constexpr uint32_t FS_GINTSTS_OTGINT = 0x4;         // OTG interrupt, Read-only
    static constexpr uint32_t FS_GINTSTS_SOF = 0x8;            // Start of frame, Read-write
    static constexpr uint32_t FS_GINTSTS_RXFLVL = 0x10;        // RxFIFO non-empty, Read-only
    static constexpr uint32_t FS_GINTSTS_NPTXFE = 0x20;        // Non-periodic TxFIFO empty, Read-only
    static constexpr uint32_t FS_GINTSTS_GINAKEFF = 0x40;      // Global IN non-periodic NAK effective, Read-only
    static constexpr uint32_t FS_GINTSTS_GOUTNAKEFF = 0x80;    // Global OUT NAK effective, Read-only
    static constexpr uint32_t FS_GINTSTS_ESUSP = 0x400;        // Early suspend, Read-write
    static constexpr uint32_t FS_GINTSTS_USBSUSP = 0x800;      // USB suspend, Read-write
    static constexpr uint32_t FS_GINTSTS_USBRST = 0x1000;      // USB reset, Read-write
    static constexpr uint32_t FS_GINTSTS_ENUMDNE = 0x2000;     // Enumeration done, Read-write
    static constexpr uint32_t FS_GINTSTS_ISOODRP = 0x4000;     // Isochronous OUT packet dropped interrupt, Read-write
    static constexpr uint32_t FS_GINTSTS_EOPF = 0x8000;        // End of periodic frame interrupt, Read-write
    static constexpr uint32_t FS_GINTSTS_IEPINT = 0x40000;     // IN endpoint interrupt, Read-only
    static constexpr uint32_t FS_GINTSTS_OEPINT = 0x80000;     // OUT endpoint interrupt, Read-only
    static constexpr uint32_t FS_GINTSTS_IISOIXFR = 0x100000;  // Incomplete isochronous IN transfer, Read-write
    static constexpr uint32_t FS_GINTSTS_IPXFR_INCOMPISOOUT = 0x200000;// Incomplete periodic transfer(Host mode)/Incomplete isochronous OUT transfer(Device mode), Read-write
    static constexpr uint32_t FS_GINTSTS_HPRTINT = 0x1000000;  // Host port interrupt, Read-only
    static constexpr uint32_t FS_GINTSTS_HCINT = 0x2000000;    // Host channels interrupt, Read-only
    static constexpr uint32_t FS_GINTSTS_PTXFE = 0x4000000;    // Periodic TxFIFO empty, Read-only
    static constexpr uint32_t FS_GINTSTS_CIDSCHG = 0x10000000; // Connector ID status change, Read-write
    static constexpr uint32_t FS_GINTSTS_DISCINT = 0x20000000; // Disconnect detected interrupt, Read-write
    static constexpr uint32_t FS_GINTSTS_SRQINT = 0x40000000;  // Session request/new session detected interrupt, Read-write
    static constexpr uint32_t FS_GINTSTS_WKUPINT = 0x80000000; // Resume/remote wakeup detected interrupt, Read-write
    static const uint32_t FS_GINTSTS_RESET_VALUE = 0x4000020;

    static constexpr uint32_t FS_GINTMSK_MMISM = 0x2;          // Mode mismatch interrupt mask, Read-write
    static constexpr uint32_t FS_GINTMSK_OTGINT = 0x4;         // OTG interrupt mask, Read-write
    static constexpr uint32_t FS_GINTMSK_SOFM = 0x8;           // Start of frame mask, Read-write
    static constexpr uint32_t FS_GINTMSK_RXFLVLM = 0x10;       // Receive FIFO non-empty mask, Read-write
    static constexpr uint32_t FS_GINTMSK_NPTXFEM = 0x20;       // Non-periodic TxFIFO empty mask, Read-write
    static constexpr uint32_t FS_GINTMSK_GINAKEFFM = 0x40;     // Global non-periodic IN NAK effective mask, Read-write
    static constexpr uint32_t FS_GINTMSK_GONAKEFFM = 0x80;     // Global OUT NAK effective mask, Read-write
    static constexpr uint32_t FS_GINTMSK_ESUSPM = 0x400;       // Early suspend mask, Read-write
    static constexpr uint32_t FS_GINTMSK_USBSUSPM = 0x800;     // USB suspend mask, Read-write
    static constexpr uint32_t FS_GINTMSK_USBRST = 0x1000;      // USB reset mask, Read-write
    static constexpr uint32_t FS_GINTMSK_ENUMDNEM = 0x2000;    // Enumeration done mask, Read-write
    static constexpr uint32_t FS_GINTMSK_ISOODRPM = 0x4000;    // Isochronous OUT packet dropped interrupt mask, Read-write
    static constexpr uint32_t FS_GINTMSK_EOPFM = 0x8000;       // End of periodic frame interrupt mask, Read-write
    static constexpr uint32_t FS_GINTMSK_EPMISM = 0x20000;     // Endpoint mismatch interrupt mask, Read-write
    static constexpr uint32_t FS_GINTMSK_IEPINT = 0x40000;     // IN endpoints interrupt mask, Read-write
    static constexpr uint32_t FS_GINTMSK_OEPINT = 0x80000;     // OUT endpoints interrupt mask, Read-write
    static constexpr uint32_t FS_GINTMSK_IISOIXFRM = 0x100000; // Incomplete isochronous IN transfer mask, Read-write
    static constexpr uint32_t FS_GINTMSK_IPXFRM_IISOOXFRM = 0x200000;// Incomplete periodic transfer mask(Host mode)/Incomplete isochronous OUT transfer mask(Device mode), Read-write
    static constexpr uint32_t FS_GINTMSK_PRTIM = 0x1000000;    // Host port interrupt mask, Read-only
    static constexpr uint32_t FS_GINTMSK_HCIM = 0x2000000;     // Host channels interrupt mask, Read-write
    static constexpr uint32_t FS_GINTMSK_PTXFEM = 0x4000000;   // Periodic TxFIFO empty mask, Read-write
    static constexpr uint32_t FS_GINTMSK_CIDSCHGM = 0x10000000;// Connector ID status change mask, Read-write
    static constexpr uint32_t FS_GINTMSK_DISCINT = 0x20000000; // Disconnect detected interrupt mask, Read-write
    static constexpr uint32_t FS_GINTMSK_SRQIM = 0x40000000;   // Session request/new session detected interrupt mask, Read-write
    static constexpr uint32_t FS_GINTMSK_WUIM = 0x80000000;    // Resume/remote wakeup detected interrupt mask, Read-write
    static const uint32_t FS_GINTMSK_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t FS_GRXSTSR_Device_BCNT =                // Byte count (11 bits)
        bit_field_t<4, 0x7ff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t FS_GRXSTSR_Device_DPID =                // Data PID (2 bits)
        bit_field_t<15, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t FS_GRXSTSR_Device_EPNUM =               // Endpoint number (4 bits)
        bit_field_t<0, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t FS_GRXSTSR_Device_FRMNUM =              // Frame number (4 bits)
        bit_field_t<21, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t FS_GRXSTSR_Device_PKTSTS =              // Packet status (4 bits)
        bit_field_t<17, 0xf>::value<X>();
    static const uint32_t FS_GRXSTSR_Device_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t FS_GRXFSIZ_RXFD =                // RxFIFO depth (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t FS_GRXFSIZ_RESET_VALUE = 0x200;

    template<uint32_t X>
    static constexpr uint32_t FS_GNPTXFSIZ_Device_NPTXFD =              // Non-periodic TxFIFO depth (16 bits)
        bit_field_t<16, 0xffff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t FS_GNPTXFSIZ_Device_NPTXFSA =             // Non-periodic transmit RAM start address (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t FS_GNPTXFSIZ_Device_TX0FD =               // Endpoint 0 TxFIFO depth (16 bits)
        bit_field_t<16, 0xffff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t FS_GNPTXFSIZ_Device_TX0FSA =              // Endpoint 0 transmit RAM start address (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t FS_GNPTXFSIZ_Device_RESET_VALUE = 0x200;

    template<uint32_t X>
    static constexpr uint32_t FS_GNPTXSTS_NPTXFSAV =            // Non-periodic TxFIFO space available (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t FS_GNPTXSTS_NPTQXSAV =            // Non-periodic transmit request queue space available (8 bits)
        bit_field_t<16, 0xff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t FS_GNPTXSTS_NPTXQTOP =            // Top of the non-periodic transmit request queue (7 bits)
        bit_field_t<24, 0x7f>::value<X>();
    static const uint32_t FS_GNPTXSTS_RESET_VALUE = 0x80200;

    static constexpr uint32_t FS_GCCFG_PWRDWN = 0x10000;     // Power down
    static constexpr uint32_t FS_GCCFG_VBUSASEN = 0x40000;   // Enable the VBUS sensing device
    static constexpr uint32_t FS_GCCFG_VBUSBSEN = 0x80000;   // Enable the VBUS sensing device
    static constexpr uint32_t FS_GCCFG_SOFOUTEN = 0x100000;  // SOF output enable
    static const uint32_t FS_GCCFG_RESET_VALUE = 0x0;


    static const uint32_t FS_CID_RESET_VALUE = 0x1000;

    template<uint32_t X>
    static constexpr uint32_t FS_HPTXFSIZ_PTXSA =               // Host periodic TxFIFO start address (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t FS_HPTXFSIZ_PTXFSIZ =             // Host periodic TxFIFO depth (16 bits)
        bit_field_t<16, 0xffff>::value<X>();
    static const uint32_t FS_HPTXFSIZ_RESET_VALUE = 0x2000600;

    template<uint32_t X>
    static constexpr uint32_t FS_DIEPTXF1_INEPTXSA =            // IN endpoint FIFO2 transmit RAM start address (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t FS_DIEPTXF1_INEPTXFD =            // IN endpoint TxFIFO depth (16 bits)
        bit_field_t<16, 0xffff>::value<X>();
    static const uint32_t FS_DIEPTXF1_RESET_VALUE = 0x2000400;

    template<uint32_t X>
    static constexpr uint32_t FS_DIEPTXF2_INEPTXSA =            // IN endpoint FIFO3 transmit RAM start address (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t FS_DIEPTXF2_INEPTXFD =            // IN endpoint TxFIFO depth (16 bits)
        bit_field_t<16, 0xffff>::value<X>();
    static const uint32_t FS_DIEPTXF2_RESET_VALUE = 0x2000400;

    template<uint32_t X>
    static constexpr uint32_t FS_DIEPTXF3_INEPTXSA =            // IN endpoint FIFO4 transmit RAM start address (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t FS_DIEPTXF3_INEPTXFD =            // IN endpoint TxFIFO depth (16 bits)
        bit_field_t<16, 0xffff>::value<X>();
    static const uint32_t FS_DIEPTXF3_RESET_VALUE = 0x2000400;
};

static otg_fs_global_t& OTG_FS_GLOBAL = *reinterpret_cast<otg_fs_global_t*>(0x50000000);

#define HAVE_PERIPHERAL_OTG_FS_GLOBAL


////
//
//    USB on the go full speed
//
////

struct otg_fs_host_t
{
    volatile uint32_t    FS_HCFG;              // OTG_FS host configuration register (OTG_FS_HCFG)
    volatile uint32_t    HFIR;                 // [Read-write] OTG_FS Host frame interval register
    volatile uint32_t    FS_HFNUM;             // [Read-only] OTG_FS host frame number/frame time remaining register (OTG_FS_HFNUM)
    reserved_t<1>        _0;
    volatile uint32_t    FS_HPTXSTS;           // OTG_FS_Host periodic transmit FIFO/queue status register (OTG_FS_HPTXSTS)
    volatile uint32_t    HAINT;                // [Read-only] OTG_FS Host all channels interrupt register
    volatile uint32_t    HAINTMSK;             // [Read-write] OTG_FS host all channels interrupt mask register
    reserved_t<9>        _1;
    volatile uint32_t    FS_HPRT;              // OTG_FS host port control and status register (OTG_FS_HPRT)
    reserved_t<47>       _2;
    volatile uint32_t    FS_HCCHAR0;           // [Read-write] OTG_FS host channel-0 characteristics register (OTG_FS_HCCHAR0)
    reserved_t<1>        _3;
    volatile uint32_t    FS_HCINT0;            // [Read-write] OTG_FS host channel-0 interrupt register (OTG_FS_HCINT0)
    volatile uint32_t    FS_HCINTMSK0;         // [Read-write] OTG_FS host channel-0 mask register (OTG_FS_HCINTMSK0)
    volatile uint32_t    FS_HCTSIZ0;           // [Read-write] OTG_FS host channel-0 transfer size register
    reserved_t<3>        _4;
    volatile uint32_t    FS_HCCHAR1;           // [Read-write] OTG_FS host channel-1 characteristics register (OTG_FS_HCCHAR1)
    reserved_t<1>        _5;
    volatile uint32_t    FS_HCINT1;            // [Read-write] OTG_FS host channel-1 interrupt register (OTG_FS_HCINT1)
    volatile uint32_t    FS_HCINTMSK1;         // [Read-write] OTG_FS host channel-1 mask register (OTG_FS_HCINTMSK1)
    volatile uint32_t    FS_HCTSIZ1;           // [Read-write] OTG_FS host channel-1 transfer size register
    reserved_t<3>        _6;
    volatile uint32_t    FS_HCCHAR2;           // [Read-write] OTG_FS host channel-2 characteristics register (OTG_FS_HCCHAR2)
    reserved_t<1>        _7;
    volatile uint32_t    FS_HCINT2;            // [Read-write] OTG_FS host channel-2 interrupt register (OTG_FS_HCINT2)
    volatile uint32_t    FS_HCINTMSK2;         // [Read-write] OTG_FS host channel-2 mask register (OTG_FS_HCINTMSK2)
    volatile uint32_t    FS_HCTSIZ2;           // [Read-write] OTG_FS host channel-2 transfer size register
    reserved_t<3>        _8;
    volatile uint32_t    FS_HCCHAR3;           // [Read-write] OTG_FS host channel-3 characteristics register (OTG_FS_HCCHAR3)
    reserved_t<1>        _9;
    volatile uint32_t    FS_HCINT3;            // [Read-write] OTG_FS host channel-3 interrupt register (OTG_FS_HCINT3)
    volatile uint32_t    FS_HCINTMSK3;         // [Read-write] OTG_FS host channel-3 mask register (OTG_FS_HCINTMSK3)
    volatile uint32_t    FS_HCTSIZ3;           // [Read-write] OTG_FS host channel-3 transfer size register
    reserved_t<3>        _10;
    volatile uint32_t    FS_HCCHAR4;           // [Read-write] OTG_FS host channel-4 characteristics register (OTG_FS_HCCHAR4)
    reserved_t<1>        _11;
    volatile uint32_t    FS_HCINT4;            // [Read-write] OTG_FS host channel-4 interrupt register (OTG_FS_HCINT4)
    volatile uint32_t    FS_HCINTMSK4;         // [Read-write] OTG_FS host channel-4 mask register (OTG_FS_HCINTMSK4)
    volatile uint32_t    FS_HCTSIZ4;           // [Read-write] OTG_FS host channel-x transfer size register
    reserved_t<3>        _12;
    volatile uint32_t    FS_HCCHAR5;           // [Read-write] OTG_FS host channel-5 characteristics register (OTG_FS_HCCHAR5)
    reserved_t<1>        _13;
    volatile uint32_t    FS_HCINT5;            // [Read-write] OTG_FS host channel-5 interrupt register (OTG_FS_HCINT5)
    volatile uint32_t    FS_HCINTMSK5;         // [Read-write] OTG_FS host channel-5 mask register (OTG_FS_HCINTMSK5)
    volatile uint32_t    FS_HCTSIZ5;           // [Read-write] OTG_FS host channel-5 transfer size register
    reserved_t<3>        _14;
    volatile uint32_t    FS_HCCHAR6;           // [Read-write] OTG_FS host channel-6 characteristics register (OTG_FS_HCCHAR6)
    reserved_t<1>        _15;
    volatile uint32_t    FS_HCINT6;            // [Read-write] OTG_FS host channel-6 interrupt register (OTG_FS_HCINT6)
    volatile uint32_t    FS_HCINTMSK6;         // [Read-write] OTG_FS host channel-6 mask register (OTG_FS_HCINTMSK6)
    volatile uint32_t    FS_HCTSIZ6;           // [Read-write] OTG_FS host channel-6 transfer size register
    reserved_t<3>        _16;
    volatile uint32_t    FS_HCCHAR7;           // [Read-write] OTG_FS host channel-7 characteristics register (OTG_FS_HCCHAR7)
    reserved_t<1>        _17;
    volatile uint32_t    FS_HCINT7;            // [Read-write] OTG_FS host channel-7 interrupt register (OTG_FS_HCINT7)
    volatile uint32_t    FS_HCINTMSK7;         // [Read-write] OTG_FS host channel-7 mask register (OTG_FS_HCINTMSK7)
    volatile uint32_t    FS_HCTSIZ7;           // [Read-write] OTG_FS host channel-7 transfer size register

    template<uint32_t X>
    static constexpr uint32_t FS_HCFG_FSLSPCS =             // FS/LS PHY clock select (2 bits), Read-write
        bit_field_t<0, 0x3>::value<X>();
    static constexpr uint32_t FS_HCFG_FSLSS = 0x4;          // FS- and LS-only support, Read-only
    static const uint32_t FS_HCFG_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t HFIR_FRIVL =               // Frame interval (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t HFIR_RESET_VALUE = 0xea60;

    template<uint32_t X>
    static constexpr uint32_t FS_HFNUM_FRNUM =               // Frame number (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t FS_HFNUM_FTREM =               // Frame time remaining (16 bits)
        bit_field_t<16, 0xffff>::value<X>();
    static const uint32_t FS_HFNUM_RESET_VALUE = 0x3fff;

    template<uint32_t X>
    static constexpr uint32_t FS_HPTXSTS_PTXFSAVL =            // Periodic transmit data FIFO space available (16 bits), Read-write
        bit_field_t<0, 0xffff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t FS_HPTXSTS_PTXQSAV =             // Periodic transmit request queue space available (8 bits), Read-only
        bit_field_t<16, 0xff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t FS_HPTXSTS_PTXQTOP =             // Top of the periodic transmit request queue (8 bits), Read-only
        bit_field_t<24, 0xff>::value<X>();
    static const uint32_t FS_HPTXSTS_RESET_VALUE = 0x80100;

    template<uint32_t X>
    static constexpr uint32_t HAINT_HAINT =               // Channel interrupts (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t HAINT_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t HAINTMSK_HAINTM =              // Channel interrupt mask (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t HAINTMSK_RESET_VALUE = 0x0;

    static constexpr uint32_t FS_HPRT_PCSTS = 0x1;          // Port connect status, Read-only
    static constexpr uint32_t FS_HPRT_PCDET = 0x2;          // Port connect detected, Read-write
    static constexpr uint32_t FS_HPRT_PENA = 0x4;           // Port enable, Read-write
    static constexpr uint32_t FS_HPRT_PENCHNG = 0x8;        // Port enable/disable change, Read-write
    static constexpr uint32_t FS_HPRT_POCA = 0x10;          // Port overcurrent active, Read-only
    static constexpr uint32_t FS_HPRT_POCCHNG = 0x20;       // Port overcurrent change, Read-write
    static constexpr uint32_t FS_HPRT_PRES = 0x40;          // Port resume, Read-write
    static constexpr uint32_t FS_HPRT_PSUSP = 0x80;         // Port suspend, Read-write
    static constexpr uint32_t FS_HPRT_PRST = 0x100;         // Port reset, Read-write
    template<uint32_t X>
    static constexpr uint32_t FS_HPRT_PLSTS =               // Port line status (2 bits), Read-only
        bit_field_t<10, 0x3>::value<X>();
    static constexpr uint32_t FS_HPRT_PPWR = 0x1000;        // Port power, Read-write
    template<uint32_t X>
    static constexpr uint32_t FS_HPRT_PTCTL =               // Port test control (4 bits), Read-write
        bit_field_t<13, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t FS_HPRT_PSPD =                // Port speed (2 bits), Read-only
        bit_field_t<17, 0x3>::value<X>();
    static const uint32_t FS_HPRT_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t FS_HCCHAR0_MPSIZ =               // Maximum packet size (11 bits)
        bit_field_t<0, 0x7ff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t FS_HCCHAR0_EPNUM =               // Endpoint number (4 bits)
        bit_field_t<11, 0xf>::value<X>();
    static constexpr uint32_t FS_HCCHAR0_EPDIR = 0x8000;       // Endpoint direction
    static constexpr uint32_t FS_HCCHAR0_LSDEV = 0x20000;      // Low-speed device
    template<uint32_t X>
    static constexpr uint32_t FS_HCCHAR0_EPTYP =               // Endpoint type (2 bits)
        bit_field_t<18, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t FS_HCCHAR0_MCNT =                // Multicount (2 bits)
        bit_field_t<20, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t FS_HCCHAR0_DAD =                 // Device address (7 bits)
        bit_field_t<22, 0x7f>::value<X>();
    static constexpr uint32_t FS_HCCHAR0_ODDFRM = 0x20000000;  // Odd frame
    static constexpr uint32_t FS_HCCHAR0_CHDIS = 0x40000000;   // Channel disable
    static constexpr uint32_t FS_HCCHAR0_CHENA = 0x80000000;   // Channel enable
    static const uint32_t FS_HCCHAR0_RESET_VALUE = 0x0;

    static constexpr uint32_t FS_HCINT0_XFRC = 0x1;           // Transfer completed
    static constexpr uint32_t FS_HCINT0_CHH = 0x2;            // Channel halted
    static constexpr uint32_t FS_HCINT0_STALL = 0x8;          // STALL response received interrupt
    static constexpr uint32_t FS_HCINT0_NAK = 0x10;           // NAK response received interrupt
    static constexpr uint32_t FS_HCINT0_ACK = 0x20;           // ACK response received/transmitted interrupt
    static constexpr uint32_t FS_HCINT0_TXERR = 0x80;         // Transaction error
    static constexpr uint32_t FS_HCINT0_BBERR = 0x100;        // Babble error
    static constexpr uint32_t FS_HCINT0_FRMOR = 0x200;        // Frame overrun
    static constexpr uint32_t FS_HCINT0_DTERR = 0x400;        // Data toggle error
    static const uint32_t FS_HCINT0_RESET_VALUE = 0x0;

    static constexpr uint32_t FS_HCINTMSK0_XFRCM = 0x1;          // Transfer completed mask
    static constexpr uint32_t FS_HCINTMSK0_CHHM = 0x2;           // Channel halted mask
    static constexpr uint32_t FS_HCINTMSK0_STALLM = 0x8;         // STALL response received interrupt mask
    static constexpr uint32_t FS_HCINTMSK0_NAKM = 0x10;          // NAK response received interrupt mask
    static constexpr uint32_t FS_HCINTMSK0_ACKM = 0x20;          // ACK response received/transmitted interrupt mask
    static constexpr uint32_t FS_HCINTMSK0_NYET = 0x40;          // response received interrupt mask
    static constexpr uint32_t FS_HCINTMSK0_TXERRM = 0x80;        // Transaction error mask
    static constexpr uint32_t FS_HCINTMSK0_BBERRM = 0x100;       // Babble error mask
    static constexpr uint32_t FS_HCINTMSK0_FRMORM = 0x200;       // Frame overrun mask
    static constexpr uint32_t FS_HCINTMSK0_DTERRM = 0x400;       // Data toggle error mask
    static const uint32_t FS_HCINTMSK0_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t FS_HCTSIZ0_XFRSIZ =              // Transfer size (19 bits)
        bit_field_t<0, 0x7ffff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t FS_HCTSIZ0_PKTCNT =              // Packet count (10 bits)
        bit_field_t<19, 0x3ff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t FS_HCTSIZ0_DPID =                // Data PID (2 bits)
        bit_field_t<29, 0x3>::value<X>();
    static const uint32_t FS_HCTSIZ0_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t FS_HCCHAR1_MPSIZ =               // Maximum packet size (11 bits)
        bit_field_t<0, 0x7ff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t FS_HCCHAR1_EPNUM =               // Endpoint number (4 bits)
        bit_field_t<11, 0xf>::value<X>();
    static constexpr uint32_t FS_HCCHAR1_EPDIR = 0x8000;       // Endpoint direction
    static constexpr uint32_t FS_HCCHAR1_LSDEV = 0x20000;      // Low-speed device
    template<uint32_t X>
    static constexpr uint32_t FS_HCCHAR1_EPTYP =               // Endpoint type (2 bits)
        bit_field_t<18, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t FS_HCCHAR1_MCNT =                // Multicount (2 bits)
        bit_field_t<20, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t FS_HCCHAR1_DAD =                 // Device address (7 bits)
        bit_field_t<22, 0x7f>::value<X>();
    static constexpr uint32_t FS_HCCHAR1_ODDFRM = 0x20000000;  // Odd frame
    static constexpr uint32_t FS_HCCHAR1_CHDIS = 0x40000000;   // Channel disable
    static constexpr uint32_t FS_HCCHAR1_CHENA = 0x80000000;   // Channel enable
    static const uint32_t FS_HCCHAR1_RESET_VALUE = 0x0;

    static constexpr uint32_t FS_HCINT1_XFRC = 0x1;           // Transfer completed
    static constexpr uint32_t FS_HCINT1_CHH = 0x2;            // Channel halted
    static constexpr uint32_t FS_HCINT1_STALL = 0x8;          // STALL response received interrupt
    static constexpr uint32_t FS_HCINT1_NAK = 0x10;           // NAK response received interrupt
    static constexpr uint32_t FS_HCINT1_ACK = 0x20;           // ACK response received/transmitted interrupt
    static constexpr uint32_t FS_HCINT1_TXERR = 0x80;         // Transaction error
    static constexpr uint32_t FS_HCINT1_BBERR = 0x100;        // Babble error
    static constexpr uint32_t FS_HCINT1_FRMOR = 0x200;        // Frame overrun
    static constexpr uint32_t FS_HCINT1_DTERR = 0x400;        // Data toggle error
    static const uint32_t FS_HCINT1_RESET_VALUE = 0x0;

    static constexpr uint32_t FS_HCINTMSK1_XFRCM = 0x1;          // Transfer completed mask
    static constexpr uint32_t FS_HCINTMSK1_CHHM = 0x2;           // Channel halted mask
    static constexpr uint32_t FS_HCINTMSK1_STALLM = 0x8;         // STALL response received interrupt mask
    static constexpr uint32_t FS_HCINTMSK1_NAKM = 0x10;          // NAK response received interrupt mask
    static constexpr uint32_t FS_HCINTMSK1_ACKM = 0x20;          // ACK response received/transmitted interrupt mask
    static constexpr uint32_t FS_HCINTMSK1_NYET = 0x40;          // response received interrupt mask
    static constexpr uint32_t FS_HCINTMSK1_TXERRM = 0x80;        // Transaction error mask
    static constexpr uint32_t FS_HCINTMSK1_BBERRM = 0x100;       // Babble error mask
    static constexpr uint32_t FS_HCINTMSK1_FRMORM = 0x200;       // Frame overrun mask
    static constexpr uint32_t FS_HCINTMSK1_DTERRM = 0x400;       // Data toggle error mask
    static const uint32_t FS_HCINTMSK1_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t FS_HCTSIZ1_XFRSIZ =              // Transfer size (19 bits)
        bit_field_t<0, 0x7ffff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t FS_HCTSIZ1_PKTCNT =              // Packet count (10 bits)
        bit_field_t<19, 0x3ff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t FS_HCTSIZ1_DPID =                // Data PID (2 bits)
        bit_field_t<29, 0x3>::value<X>();
    static const uint32_t FS_HCTSIZ1_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t FS_HCCHAR2_MPSIZ =               // Maximum packet size (11 bits)
        bit_field_t<0, 0x7ff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t FS_HCCHAR2_EPNUM =               // Endpoint number (4 bits)
        bit_field_t<11, 0xf>::value<X>();
    static constexpr uint32_t FS_HCCHAR2_EPDIR = 0x8000;       // Endpoint direction
    static constexpr uint32_t FS_HCCHAR2_LSDEV = 0x20000;      // Low-speed device
    template<uint32_t X>
    static constexpr uint32_t FS_HCCHAR2_EPTYP =               // Endpoint type (2 bits)
        bit_field_t<18, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t FS_HCCHAR2_MCNT =                // Multicount (2 bits)
        bit_field_t<20, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t FS_HCCHAR2_DAD =                 // Device address (7 bits)
        bit_field_t<22, 0x7f>::value<X>();
    static constexpr uint32_t FS_HCCHAR2_ODDFRM = 0x20000000;  // Odd frame
    static constexpr uint32_t FS_HCCHAR2_CHDIS = 0x40000000;   // Channel disable
    static constexpr uint32_t FS_HCCHAR2_CHENA = 0x80000000;   // Channel enable
    static const uint32_t FS_HCCHAR2_RESET_VALUE = 0x0;

    static constexpr uint32_t FS_HCINT2_XFRC = 0x1;           // Transfer completed
    static constexpr uint32_t FS_HCINT2_CHH = 0x2;            // Channel halted
    static constexpr uint32_t FS_HCINT2_STALL = 0x8;          // STALL response received interrupt
    static constexpr uint32_t FS_HCINT2_NAK = 0x10;           // NAK response received interrupt
    static constexpr uint32_t FS_HCINT2_ACK = 0x20;           // ACK response received/transmitted interrupt
    static constexpr uint32_t FS_HCINT2_TXERR = 0x80;         // Transaction error
    static constexpr uint32_t FS_HCINT2_BBERR = 0x100;        // Babble error
    static constexpr uint32_t FS_HCINT2_FRMOR = 0x200;        // Frame overrun
    static constexpr uint32_t FS_HCINT2_DTERR = 0x400;        // Data toggle error
    static const uint32_t FS_HCINT2_RESET_VALUE = 0x0;

    static constexpr uint32_t FS_HCINTMSK2_XFRCM = 0x1;          // Transfer completed mask
    static constexpr uint32_t FS_HCINTMSK2_CHHM = 0x2;           // Channel halted mask
    static constexpr uint32_t FS_HCINTMSK2_STALLM = 0x8;         // STALL response received interrupt mask
    static constexpr uint32_t FS_HCINTMSK2_NAKM = 0x10;          // NAK response received interrupt mask
    static constexpr uint32_t FS_HCINTMSK2_ACKM = 0x20;          // ACK response received/transmitted interrupt mask
    static constexpr uint32_t FS_HCINTMSK2_NYET = 0x40;          // response received interrupt mask
    static constexpr uint32_t FS_HCINTMSK2_TXERRM = 0x80;        // Transaction error mask
    static constexpr uint32_t FS_HCINTMSK2_BBERRM = 0x100;       // Babble error mask
    static constexpr uint32_t FS_HCINTMSK2_FRMORM = 0x200;       // Frame overrun mask
    static constexpr uint32_t FS_HCINTMSK2_DTERRM = 0x400;       // Data toggle error mask
    static const uint32_t FS_HCINTMSK2_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t FS_HCTSIZ2_XFRSIZ =              // Transfer size (19 bits)
        bit_field_t<0, 0x7ffff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t FS_HCTSIZ2_PKTCNT =              // Packet count (10 bits)
        bit_field_t<19, 0x3ff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t FS_HCTSIZ2_DPID =                // Data PID (2 bits)
        bit_field_t<29, 0x3>::value<X>();
    static const uint32_t FS_HCTSIZ2_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t FS_HCCHAR3_MPSIZ =               // Maximum packet size (11 bits)
        bit_field_t<0, 0x7ff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t FS_HCCHAR3_EPNUM =               // Endpoint number (4 bits)
        bit_field_t<11, 0xf>::value<X>();
    static constexpr uint32_t FS_HCCHAR3_EPDIR = 0x8000;       // Endpoint direction
    static constexpr uint32_t FS_HCCHAR3_LSDEV = 0x20000;      // Low-speed device
    template<uint32_t X>
    static constexpr uint32_t FS_HCCHAR3_EPTYP =               // Endpoint type (2 bits)
        bit_field_t<18, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t FS_HCCHAR3_MCNT =                // Multicount (2 bits)
        bit_field_t<20, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t FS_HCCHAR3_DAD =                 // Device address (7 bits)
        bit_field_t<22, 0x7f>::value<X>();
    static constexpr uint32_t FS_HCCHAR3_ODDFRM = 0x20000000;  // Odd frame
    static constexpr uint32_t FS_HCCHAR3_CHDIS = 0x40000000;   // Channel disable
    static constexpr uint32_t FS_HCCHAR3_CHENA = 0x80000000;   // Channel enable
    static const uint32_t FS_HCCHAR3_RESET_VALUE = 0x0;

    static constexpr uint32_t FS_HCINT3_XFRC = 0x1;           // Transfer completed
    static constexpr uint32_t FS_HCINT3_CHH = 0x2;            // Channel halted
    static constexpr uint32_t FS_HCINT3_STALL = 0x8;          // STALL response received interrupt
    static constexpr uint32_t FS_HCINT3_NAK = 0x10;           // NAK response received interrupt
    static constexpr uint32_t FS_HCINT3_ACK = 0x20;           // ACK response received/transmitted interrupt
    static constexpr uint32_t FS_HCINT3_TXERR = 0x80;         // Transaction error
    static constexpr uint32_t FS_HCINT3_BBERR = 0x100;        // Babble error
    static constexpr uint32_t FS_HCINT3_FRMOR = 0x200;        // Frame overrun
    static constexpr uint32_t FS_HCINT3_DTERR = 0x400;        // Data toggle error
    static const uint32_t FS_HCINT3_RESET_VALUE = 0x0;

    static constexpr uint32_t FS_HCINTMSK3_XFRCM = 0x1;          // Transfer completed mask
    static constexpr uint32_t FS_HCINTMSK3_CHHM = 0x2;           // Channel halted mask
    static constexpr uint32_t FS_HCINTMSK3_STALLM = 0x8;         // STALL response received interrupt mask
    static constexpr uint32_t FS_HCINTMSK3_NAKM = 0x10;          // NAK response received interrupt mask
    static constexpr uint32_t FS_HCINTMSK3_ACKM = 0x20;          // ACK response received/transmitted interrupt mask
    static constexpr uint32_t FS_HCINTMSK3_NYET = 0x40;          // response received interrupt mask
    static constexpr uint32_t FS_HCINTMSK3_TXERRM = 0x80;        // Transaction error mask
    static constexpr uint32_t FS_HCINTMSK3_BBERRM = 0x100;       // Babble error mask
    static constexpr uint32_t FS_HCINTMSK3_FRMORM = 0x200;       // Frame overrun mask
    static constexpr uint32_t FS_HCINTMSK3_DTERRM = 0x400;       // Data toggle error mask
    static const uint32_t FS_HCINTMSK3_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t FS_HCTSIZ3_XFRSIZ =              // Transfer size (19 bits)
        bit_field_t<0, 0x7ffff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t FS_HCTSIZ3_PKTCNT =              // Packet count (10 bits)
        bit_field_t<19, 0x3ff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t FS_HCTSIZ3_DPID =                // Data PID (2 bits)
        bit_field_t<29, 0x3>::value<X>();
    static const uint32_t FS_HCTSIZ3_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t FS_HCCHAR4_MPSIZ =               // Maximum packet size (11 bits)
        bit_field_t<0, 0x7ff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t FS_HCCHAR4_EPNUM =               // Endpoint number (4 bits)
        bit_field_t<11, 0xf>::value<X>();
    static constexpr uint32_t FS_HCCHAR4_EPDIR = 0x8000;       // Endpoint direction
    static constexpr uint32_t FS_HCCHAR4_LSDEV = 0x20000;      // Low-speed device
    template<uint32_t X>
    static constexpr uint32_t FS_HCCHAR4_EPTYP =               // Endpoint type (2 bits)
        bit_field_t<18, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t FS_HCCHAR4_MCNT =                // Multicount (2 bits)
        bit_field_t<20, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t FS_HCCHAR4_DAD =                 // Device address (7 bits)
        bit_field_t<22, 0x7f>::value<X>();
    static constexpr uint32_t FS_HCCHAR4_ODDFRM = 0x20000000;  // Odd frame
    static constexpr uint32_t FS_HCCHAR4_CHDIS = 0x40000000;   // Channel disable
    static constexpr uint32_t FS_HCCHAR4_CHENA = 0x80000000;   // Channel enable
    static const uint32_t FS_HCCHAR4_RESET_VALUE = 0x0;

    static constexpr uint32_t FS_HCINT4_XFRC = 0x1;           // Transfer completed
    static constexpr uint32_t FS_HCINT4_CHH = 0x2;            // Channel halted
    static constexpr uint32_t FS_HCINT4_STALL = 0x8;          // STALL response received interrupt
    static constexpr uint32_t FS_HCINT4_NAK = 0x10;           // NAK response received interrupt
    static constexpr uint32_t FS_HCINT4_ACK = 0x20;           // ACK response received/transmitted interrupt
    static constexpr uint32_t FS_HCINT4_TXERR = 0x80;         // Transaction error
    static constexpr uint32_t FS_HCINT4_BBERR = 0x100;        // Babble error
    static constexpr uint32_t FS_HCINT4_FRMOR = 0x200;        // Frame overrun
    static constexpr uint32_t FS_HCINT4_DTERR = 0x400;        // Data toggle error
    static const uint32_t FS_HCINT4_RESET_VALUE = 0x0;

    static constexpr uint32_t FS_HCINTMSK4_XFRCM = 0x1;          // Transfer completed mask
    static constexpr uint32_t FS_HCINTMSK4_CHHM = 0x2;           // Channel halted mask
    static constexpr uint32_t FS_HCINTMSK4_STALLM = 0x8;         // STALL response received interrupt mask
    static constexpr uint32_t FS_HCINTMSK4_NAKM = 0x10;          // NAK response received interrupt mask
    static constexpr uint32_t FS_HCINTMSK4_ACKM = 0x20;          // ACK response received/transmitted interrupt mask
    static constexpr uint32_t FS_HCINTMSK4_NYET = 0x40;          // response received interrupt mask
    static constexpr uint32_t FS_HCINTMSK4_TXERRM = 0x80;        // Transaction error mask
    static constexpr uint32_t FS_HCINTMSK4_BBERRM = 0x100;       // Babble error mask
    static constexpr uint32_t FS_HCINTMSK4_FRMORM = 0x200;       // Frame overrun mask
    static constexpr uint32_t FS_HCINTMSK4_DTERRM = 0x400;       // Data toggle error mask
    static const uint32_t FS_HCINTMSK4_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t FS_HCTSIZ4_XFRSIZ =              // Transfer size (19 bits)
        bit_field_t<0, 0x7ffff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t FS_HCTSIZ4_PKTCNT =              // Packet count (10 bits)
        bit_field_t<19, 0x3ff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t FS_HCTSIZ4_DPID =                // Data PID (2 bits)
        bit_field_t<29, 0x3>::value<X>();
    static const uint32_t FS_HCTSIZ4_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t FS_HCCHAR5_MPSIZ =               // Maximum packet size (11 bits)
        bit_field_t<0, 0x7ff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t FS_HCCHAR5_EPNUM =               // Endpoint number (4 bits)
        bit_field_t<11, 0xf>::value<X>();
    static constexpr uint32_t FS_HCCHAR5_EPDIR = 0x8000;       // Endpoint direction
    static constexpr uint32_t FS_HCCHAR5_LSDEV = 0x20000;      // Low-speed device
    template<uint32_t X>
    static constexpr uint32_t FS_HCCHAR5_EPTYP =               // Endpoint type (2 bits)
        bit_field_t<18, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t FS_HCCHAR5_MCNT =                // Multicount (2 bits)
        bit_field_t<20, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t FS_HCCHAR5_DAD =                 // Device address (7 bits)
        bit_field_t<22, 0x7f>::value<X>();
    static constexpr uint32_t FS_HCCHAR5_ODDFRM = 0x20000000;  // Odd frame
    static constexpr uint32_t FS_HCCHAR5_CHDIS = 0x40000000;   // Channel disable
    static constexpr uint32_t FS_HCCHAR5_CHENA = 0x80000000;   // Channel enable
    static const uint32_t FS_HCCHAR5_RESET_VALUE = 0x0;

    static constexpr uint32_t FS_HCINT5_XFRC = 0x1;           // Transfer completed
    static constexpr uint32_t FS_HCINT5_CHH = 0x2;            // Channel halted
    static constexpr uint32_t FS_HCINT5_STALL = 0x8;          // STALL response received interrupt
    static constexpr uint32_t FS_HCINT5_NAK = 0x10;           // NAK response received interrupt
    static constexpr uint32_t FS_HCINT5_ACK = 0x20;           // ACK response received/transmitted interrupt
    static constexpr uint32_t FS_HCINT5_TXERR = 0x80;         // Transaction error
    static constexpr uint32_t FS_HCINT5_BBERR = 0x100;        // Babble error
    static constexpr uint32_t FS_HCINT5_FRMOR = 0x200;        // Frame overrun
    static constexpr uint32_t FS_HCINT5_DTERR = 0x400;        // Data toggle error
    static const uint32_t FS_HCINT5_RESET_VALUE = 0x0;

    static constexpr uint32_t FS_HCINTMSK5_XFRCM = 0x1;          // Transfer completed mask
    static constexpr uint32_t FS_HCINTMSK5_CHHM = 0x2;           // Channel halted mask
    static constexpr uint32_t FS_HCINTMSK5_STALLM = 0x8;         // STALL response received interrupt mask
    static constexpr uint32_t FS_HCINTMSK5_NAKM = 0x10;          // NAK response received interrupt mask
    static constexpr uint32_t FS_HCINTMSK5_ACKM = 0x20;          // ACK response received/transmitted interrupt mask
    static constexpr uint32_t FS_HCINTMSK5_NYET = 0x40;          // response received interrupt mask
    static constexpr uint32_t FS_HCINTMSK5_TXERRM = 0x80;        // Transaction error mask
    static constexpr uint32_t FS_HCINTMSK5_BBERRM = 0x100;       // Babble error mask
    static constexpr uint32_t FS_HCINTMSK5_FRMORM = 0x200;       // Frame overrun mask
    static constexpr uint32_t FS_HCINTMSK5_DTERRM = 0x400;       // Data toggle error mask
    static const uint32_t FS_HCINTMSK5_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t FS_HCTSIZ5_XFRSIZ =              // Transfer size (19 bits)
        bit_field_t<0, 0x7ffff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t FS_HCTSIZ5_PKTCNT =              // Packet count (10 bits)
        bit_field_t<19, 0x3ff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t FS_HCTSIZ5_DPID =                // Data PID (2 bits)
        bit_field_t<29, 0x3>::value<X>();
    static const uint32_t FS_HCTSIZ5_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t FS_HCCHAR6_MPSIZ =               // Maximum packet size (11 bits)
        bit_field_t<0, 0x7ff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t FS_HCCHAR6_EPNUM =               // Endpoint number (4 bits)
        bit_field_t<11, 0xf>::value<X>();
    static constexpr uint32_t FS_HCCHAR6_EPDIR = 0x8000;       // Endpoint direction
    static constexpr uint32_t FS_HCCHAR6_LSDEV = 0x20000;      // Low-speed device
    template<uint32_t X>
    static constexpr uint32_t FS_HCCHAR6_EPTYP =               // Endpoint type (2 bits)
        bit_field_t<18, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t FS_HCCHAR6_MCNT =                // Multicount (2 bits)
        bit_field_t<20, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t FS_HCCHAR6_DAD =                 // Device address (7 bits)
        bit_field_t<22, 0x7f>::value<X>();
    static constexpr uint32_t FS_HCCHAR6_ODDFRM = 0x20000000;  // Odd frame
    static constexpr uint32_t FS_HCCHAR6_CHDIS = 0x40000000;   // Channel disable
    static constexpr uint32_t FS_HCCHAR6_CHENA = 0x80000000;   // Channel enable
    static const uint32_t FS_HCCHAR6_RESET_VALUE = 0x0;

    static constexpr uint32_t FS_HCINT6_XFRC = 0x1;           // Transfer completed
    static constexpr uint32_t FS_HCINT6_CHH = 0x2;            // Channel halted
    static constexpr uint32_t FS_HCINT6_STALL = 0x8;          // STALL response received interrupt
    static constexpr uint32_t FS_HCINT6_NAK = 0x10;           // NAK response received interrupt
    static constexpr uint32_t FS_HCINT6_ACK = 0x20;           // ACK response received/transmitted interrupt
    static constexpr uint32_t FS_HCINT6_TXERR = 0x80;         // Transaction error
    static constexpr uint32_t FS_HCINT6_BBERR = 0x100;        // Babble error
    static constexpr uint32_t FS_HCINT6_FRMOR = 0x200;        // Frame overrun
    static constexpr uint32_t FS_HCINT6_DTERR = 0x400;        // Data toggle error
    static const uint32_t FS_HCINT6_RESET_VALUE = 0x0;

    static constexpr uint32_t FS_HCINTMSK6_XFRCM = 0x1;          // Transfer completed mask
    static constexpr uint32_t FS_HCINTMSK6_CHHM = 0x2;           // Channel halted mask
    static constexpr uint32_t FS_HCINTMSK6_STALLM = 0x8;         // STALL response received interrupt mask
    static constexpr uint32_t FS_HCINTMSK6_NAKM = 0x10;          // NAK response received interrupt mask
    static constexpr uint32_t FS_HCINTMSK6_ACKM = 0x20;          // ACK response received/transmitted interrupt mask
    static constexpr uint32_t FS_HCINTMSK6_NYET = 0x40;          // response received interrupt mask
    static constexpr uint32_t FS_HCINTMSK6_TXERRM = 0x80;        // Transaction error mask
    static constexpr uint32_t FS_HCINTMSK6_BBERRM = 0x100;       // Babble error mask
    static constexpr uint32_t FS_HCINTMSK6_FRMORM = 0x200;       // Frame overrun mask
    static constexpr uint32_t FS_HCINTMSK6_DTERRM = 0x400;       // Data toggle error mask
    static const uint32_t FS_HCINTMSK6_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t FS_HCTSIZ6_XFRSIZ =              // Transfer size (19 bits)
        bit_field_t<0, 0x7ffff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t FS_HCTSIZ6_PKTCNT =              // Packet count (10 bits)
        bit_field_t<19, 0x3ff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t FS_HCTSIZ6_DPID =                // Data PID (2 bits)
        bit_field_t<29, 0x3>::value<X>();
    static const uint32_t FS_HCTSIZ6_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t FS_HCCHAR7_MPSIZ =               // Maximum packet size (11 bits)
        bit_field_t<0, 0x7ff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t FS_HCCHAR7_EPNUM =               // Endpoint number (4 bits)
        bit_field_t<11, 0xf>::value<X>();
    static constexpr uint32_t FS_HCCHAR7_EPDIR = 0x8000;       // Endpoint direction
    static constexpr uint32_t FS_HCCHAR7_LSDEV = 0x20000;      // Low-speed device
    template<uint32_t X>
    static constexpr uint32_t FS_HCCHAR7_EPTYP =               // Endpoint type (2 bits)
        bit_field_t<18, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t FS_HCCHAR7_MCNT =                // Multicount (2 bits)
        bit_field_t<20, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t FS_HCCHAR7_DAD =                 // Device address (7 bits)
        bit_field_t<22, 0x7f>::value<X>();
    static constexpr uint32_t FS_HCCHAR7_ODDFRM = 0x20000000;  // Odd frame
    static constexpr uint32_t FS_HCCHAR7_CHDIS = 0x40000000;   // Channel disable
    static constexpr uint32_t FS_HCCHAR7_CHENA = 0x80000000;   // Channel enable
    static const uint32_t FS_HCCHAR7_RESET_VALUE = 0x0;

    static constexpr uint32_t FS_HCINT7_XFRC = 0x1;           // Transfer completed
    static constexpr uint32_t FS_HCINT7_CHH = 0x2;            // Channel halted
    static constexpr uint32_t FS_HCINT7_STALL = 0x8;          // STALL response received interrupt
    static constexpr uint32_t FS_HCINT7_NAK = 0x10;           // NAK response received interrupt
    static constexpr uint32_t FS_HCINT7_ACK = 0x20;           // ACK response received/transmitted interrupt
    static constexpr uint32_t FS_HCINT7_TXERR = 0x80;         // Transaction error
    static constexpr uint32_t FS_HCINT7_BBERR = 0x100;        // Babble error
    static constexpr uint32_t FS_HCINT7_FRMOR = 0x200;        // Frame overrun
    static constexpr uint32_t FS_HCINT7_DTERR = 0x400;        // Data toggle error
    static const uint32_t FS_HCINT7_RESET_VALUE = 0x0;

    static constexpr uint32_t FS_HCINTMSK7_XFRCM = 0x1;          // Transfer completed mask
    static constexpr uint32_t FS_HCINTMSK7_CHHM = 0x2;           // Channel halted mask
    static constexpr uint32_t FS_HCINTMSK7_STALLM = 0x8;         // STALL response received interrupt mask
    static constexpr uint32_t FS_HCINTMSK7_NAKM = 0x10;          // NAK response received interrupt mask
    static constexpr uint32_t FS_HCINTMSK7_ACKM = 0x20;          // ACK response received/transmitted interrupt mask
    static constexpr uint32_t FS_HCINTMSK7_NYET = 0x40;          // response received interrupt mask
    static constexpr uint32_t FS_HCINTMSK7_TXERRM = 0x80;        // Transaction error mask
    static constexpr uint32_t FS_HCINTMSK7_BBERRM = 0x100;       // Babble error mask
    static constexpr uint32_t FS_HCINTMSK7_FRMORM = 0x200;       // Frame overrun mask
    static constexpr uint32_t FS_HCINTMSK7_DTERRM = 0x400;       // Data toggle error mask
    static const uint32_t FS_HCINTMSK7_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t FS_HCTSIZ7_XFRSIZ =              // Transfer size (19 bits)
        bit_field_t<0, 0x7ffff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t FS_HCTSIZ7_PKTCNT =              // Packet count (10 bits)
        bit_field_t<19, 0x3ff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t FS_HCTSIZ7_DPID =                // Data PID (2 bits)
        bit_field_t<29, 0x3>::value<X>();
    static const uint32_t FS_HCTSIZ7_RESET_VALUE = 0x0;
};

static otg_fs_host_t& OTG_FS_HOST = *reinterpret_cast<otg_fs_host_t*>(0x50000400);

#define HAVE_PERIPHERAL_OTG_FS_HOST


////
//
//    USB on the go full speed
//
////

struct otg_fs_pwrclk_t
{
    volatile uint32_t    FS_PCGCCTL;           // [Read-write] OTG_FS power and clock gating control register

    static constexpr uint32_t FS_PCGCCTL_STPPCLK = 0x1;        // Stop PHY clock
    static constexpr uint32_t FS_PCGCCTL_GATEHCLK = 0x2;       // Gate HCLK
    static constexpr uint32_t FS_PCGCCTL_PHYSUSP = 0x10;       // PHY Suspended
    static const uint32_t FS_PCGCCTL_RESET_VALUE = 0x0;
};

static otg_fs_pwrclk_t& OTG_FS_PWRCLK = *reinterpret_cast<otg_fs_pwrclk_t*>(0x50000e00);

#define HAVE_PERIPHERAL_OTG_FS_PWRCLK


////
//
//    Power control
//
////

struct pwr_t
{
    volatile uint32_t    CR;                   // [Read-write] power control register
    volatile uint32_t    CSR;                  // power control/status register

    template<uint32_t X>
    static constexpr uint32_t CR_VOS =                 // Regulator voltage scaling output selection (2 bits)
        bit_field_t<14, 0x3>::value<X>();
    static constexpr uint32_t CR_ADCDC1 = 0x2000;      // ADCDC1
    static constexpr uint32_t CR_FPDS = 0x200;         // Flash power down in Stop mode
    static constexpr uint32_t CR_DBP = 0x100;          // Disable backup domain write protection
    template<uint32_t X>
    static constexpr uint32_t CR_PLS =                 // PVD level selection (3 bits)
        bit_field_t<5, 0x7>::value<X>();
    static constexpr uint32_t CR_PVDE = 0x10;          // Power voltage detector enable
    static constexpr uint32_t CR_CSBF = 0x8;           // Clear standby flag
    static constexpr uint32_t CR_CWUF = 0x4;           // Clear wakeup flag
    static constexpr uint32_t CR_PDDS = 0x2;           // Power down deepsleep
    static constexpr uint32_t CR_LPDS = 0x1;           // Low-power deep sleep
    static const uint32_t CR_RESET_VALUE = 0x0;

    static constexpr uint32_t CSR_WUF = 0x1;            // Wakeup flag, Read-only
    static constexpr uint32_t CSR_SBF = 0x2;            // Standby flag, Read-only
    static constexpr uint32_t CSR_PVDO = 0x4;           // PVD output, Read-only
    static constexpr uint32_t CSR_BRR = 0x8;            // Backup regulator ready, Read-only
    static constexpr uint32_t CSR_EWUP = 0x100;         // Enable WKUP pin, Read-write
    static constexpr uint32_t CSR_BRE = 0x200;          // Backup regulator enable, Read-write
    static constexpr uint32_t CSR_VOSRDY = 0x4000;      // Regulator voltage scaling output selection ready bit, Read-write
    static const uint32_t CSR_RESET_VALUE = 0x0;
};

static pwr_t& PWR = *reinterpret_cast<pwr_t*>(0x40007000);

#define HAVE_PERIPHERAL_PWR


////
//
//    Reset and clock control
//
////

struct rcc_t
{
    volatile uint32_t    CR;                   // clock control register
    volatile uint32_t    PLLCFGR;              // [Read-write] PLL configuration register
    volatile uint32_t    CFGR;                 // clock configuration register
    volatile uint32_t    CIR;                  // clock interrupt register
    volatile uint32_t    AHB1RSTR;             // [Read-write] AHB1 peripheral reset register
    volatile uint32_t    AHB2RSTR;             // [Read-write] AHB2 peripheral reset register
    reserved_t<2>        _0;
    volatile uint32_t    APB1RSTR;             // [Read-write] APB1 peripheral reset register
    volatile uint32_t    APB2RSTR;             // [Read-write] APB2 peripheral reset register
    reserved_t<2>        _1;
    volatile uint32_t    AHB1ENR;              // [Read-write] AHB1 peripheral clock register
    volatile uint32_t    AHB2ENR;              // [Read-write] AHB2 peripheral clock enable register
    reserved_t<2>        _2;
    volatile uint32_t    APB1ENR;              // [Read-write] APB1 peripheral clock enable register
    volatile uint32_t    APB2ENR;              // [Read-write] APB2 peripheral clock enable register
    reserved_t<2>        _3;
    volatile uint32_t    AHB1LPENR;            // [Read-write] AHB1 peripheral clock enable in low power mode register
    volatile uint32_t    AHB2LPENR;            // [Read-write] AHB2 peripheral clock enable in low power mode register
    reserved_t<2>        _4;
    volatile uint32_t    APB1LPENR;            // [Read-write] APB1 peripheral clock enable in low power mode register
    volatile uint32_t    APB2LPENR;            // [Read-write] APB2 peripheral clock enabled in low power mode register
    reserved_t<2>        _5;
    volatile uint32_t    BDCR;                 // Backup domain control register
    volatile uint32_t    CSR;                  // clock control &amp; status register
    reserved_t<2>        _6;
    volatile uint32_t    SSCGR;                // [Read-write] spread spectrum clock generation register
    volatile uint32_t    PLLI2SCFGR;           // [Read-write] PLLI2S configuration register

    static constexpr uint32_t CR_PLLI2SRDY = 0x8000000;// PLLI2S clock ready flag, Read-only
    static constexpr uint32_t CR_PLLI2SON = 0x4000000; // PLLI2S enable, Read-write
    static constexpr uint32_t CR_PLLRDY = 0x2000000;   // Main PLL (PLL) clock ready flag, Read-only
    static constexpr uint32_t CR_PLLON = 0x1000000;    // Main PLL (PLL) enable, Read-write
    static constexpr uint32_t CR_CSSON = 0x80000;      // Clock security system enable, Read-write
    static constexpr uint32_t CR_HSEBYP = 0x40000;     // HSE clock bypass, Read-write
    static constexpr uint32_t CR_HSERDY = 0x20000;     // HSE clock ready flag, Read-only
    static constexpr uint32_t CR_HSEON = 0x10000;      // HSE clock enable, Read-write
    template<uint32_t X>
    static constexpr uint32_t CR_HSICAL =              // Internal high-speed clock calibration (8 bits), Read-only
        bit_field_t<8, 0xff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CR_HSITRIM =             // Internal high-speed clock trimming (5 bits), Read-write
        bit_field_t<3, 0x1f>::value<X>();
    static constexpr uint32_t CR_HSIRDY = 0x2;         // Internal high-speed clock ready flag, Read-only
    static constexpr uint32_t CR_HSION = 0x1;          // Internal high-speed clock enable, Read-write
    static const uint32_t CR_RESET_VALUE = 0x83;

    static constexpr uint32_t PLLCFGR_PLLQ3 = 0x8000000;    // Main PLL (PLL) division factor for USB OTG FS, SDIO and random number generator clocks
    static constexpr uint32_t PLLCFGR_PLLQ2 = 0x4000000;    // Main PLL (PLL) division factor for USB OTG FS, SDIO and random number generator clocks
    static constexpr uint32_t PLLCFGR_PLLQ1 = 0x2000000;    // Main PLL (PLL) division factor for USB OTG FS, SDIO and random number generator clocks
    static constexpr uint32_t PLLCFGR_PLLQ0 = 0x1000000;    // Main PLL (PLL) division factor for USB OTG FS, SDIO and random number generator clocks
    static constexpr uint32_t PLLCFGR_PLLSRC = 0x400000;    // Main PLL(PLL) and audio PLL (PLLI2S) entry clock source
    static constexpr uint32_t PLLCFGR_PLLP1 = 0x20000;      // Main PLL (PLL) division factor for main system clock
    static constexpr uint32_t PLLCFGR_PLLP0 = 0x10000;      // Main PLL (PLL) division factor for main system clock
    static constexpr uint32_t PLLCFGR_PLLN8 = 0x4000;       // Main PLL (PLL) multiplication factor for VCO
    static constexpr uint32_t PLLCFGR_PLLN7 = 0x2000;       // Main PLL (PLL) multiplication factor for VCO
    static constexpr uint32_t PLLCFGR_PLLN6 = 0x1000;       // Main PLL (PLL) multiplication factor for VCO
    static constexpr uint32_t PLLCFGR_PLLN5 = 0x800;        // Main PLL (PLL) multiplication factor for VCO
    static constexpr uint32_t PLLCFGR_PLLN4 = 0x400;        // Main PLL (PLL) multiplication factor for VCO
    static constexpr uint32_t PLLCFGR_PLLN3 = 0x200;        // Main PLL (PLL) multiplication factor for VCO
    static constexpr uint32_t PLLCFGR_PLLN2 = 0x100;        // Main PLL (PLL) multiplication factor for VCO
    static constexpr uint32_t PLLCFGR_PLLN1 = 0x80;         // Main PLL (PLL) multiplication factor for VCO
    static constexpr uint32_t PLLCFGR_PLLN0 = 0x40;         // Main PLL (PLL) multiplication factor for VCO
    static constexpr uint32_t PLLCFGR_PLLM5 = 0x20;         // Division factor for the main PLL (PLL) and audio PLL (PLLI2S) input clock
    static constexpr uint32_t PLLCFGR_PLLM4 = 0x10;         // Division factor for the main PLL (PLL) and audio PLL (PLLI2S) input clock
    static constexpr uint32_t PLLCFGR_PLLM3 = 0x8;          // Division factor for the main PLL (PLL) and audio PLL (PLLI2S) input clock
    static constexpr uint32_t PLLCFGR_PLLM2 = 0x4;          // Division factor for the main PLL (PLL) and audio PLL (PLLI2S) input clock
    static constexpr uint32_t PLLCFGR_PLLM1 = 0x2;          // Division factor for the main PLL (PLL) and audio PLL (PLLI2S) input clock
    static constexpr uint32_t PLLCFGR_PLLM0 = 0x1;          // Division factor for the main PLL (PLL) and audio PLL (PLLI2S) input clock
    static const uint32_t PLLCFGR_RESET_VALUE = 0x24003010;

    template<uint32_t X>
    static constexpr uint32_t CFGR_MCO2 =                // Microcontroller clock output 2 (2 bits), Read-write
        bit_field_t<30, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CFGR_MCO2PRE =             // MCO2 prescaler (3 bits), Read-write
        bit_field_t<27, 0x7>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CFGR_MCO1PRE =             // MCO1 prescaler (3 bits), Read-write
        bit_field_t<24, 0x7>::value<X>();
    static constexpr uint32_t CFGR_I2SSRC = 0x800000;    // I2S clock selection, Read-write
    template<uint32_t X>
    static constexpr uint32_t CFGR_MCO1 =                // Microcontroller clock output 1 (2 bits), Read-write
        bit_field_t<21, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CFGR_RTCPRE =              // HSE division factor for RTC clock (5 bits), Read-write
        bit_field_t<16, 0x1f>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CFGR_PPRE2 =               // APB high-speed prescaler (APB2) (3 bits), Read-write
        bit_field_t<13, 0x7>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CFGR_PPRE1 =               // APB Low speed prescaler (APB1) (3 bits), Read-write
        bit_field_t<10, 0x7>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CFGR_HPRE =                // AHB prescaler (4 bits), Read-write
        bit_field_t<4, 0xf>::value<X>();
    static constexpr uint32_t CFGR_SWS1 = 0x8;           // System clock switch status, Read-only
    static constexpr uint32_t CFGR_SWS0 = 0x4;           // System clock switch status, Read-only
    static constexpr uint32_t CFGR_SW1 = 0x2;            // System clock switch, Read-write
    static constexpr uint32_t CFGR_SW0 = 0x1;            // System clock switch, Read-write
    static const uint32_t CFGR_RESET_VALUE = 0x0;

    static constexpr uint32_t CIR_CSSC = 0x800000;      // Clock security system interrupt clear, Write-only
    static constexpr uint32_t CIR_PLLI2SRDYC = 0x200000;// PLLI2S ready interrupt clear, Write-only
    static constexpr uint32_t CIR_PLLRDYC = 0x100000;   // Main PLL(PLL) ready interrupt clear, Write-only
    static constexpr uint32_t CIR_HSERDYC = 0x80000;    // HSE ready interrupt clear, Write-only
    static constexpr uint32_t CIR_HSIRDYC = 0x40000;    // HSI ready interrupt clear, Write-only
    static constexpr uint32_t CIR_LSERDYC = 0x20000;    // LSE ready interrupt clear, Write-only
    static constexpr uint32_t CIR_LSIRDYC = 0x10000;    // LSI ready interrupt clear, Write-only
    static constexpr uint32_t CIR_PLLI2SRDYIE = 0x2000; // PLLI2S ready interrupt enable, Read-write
    static constexpr uint32_t CIR_PLLRDYIE = 0x1000;    // Main PLL (PLL) ready interrupt enable, Read-write
    static constexpr uint32_t CIR_HSERDYIE = 0x800;     // HSE ready interrupt enable, Read-write
    static constexpr uint32_t CIR_HSIRDYIE = 0x400;     // HSI ready interrupt enable, Read-write
    static constexpr uint32_t CIR_LSERDYIE = 0x200;     // LSE ready interrupt enable, Read-write
    static constexpr uint32_t CIR_LSIRDYIE = 0x100;     // LSI ready interrupt enable, Read-write
    static constexpr uint32_t CIR_CSSF = 0x80;          // Clock security system interrupt flag, Read-only
    static constexpr uint32_t CIR_PLLI2SRDYF = 0x20;    // PLLI2S ready interrupt flag, Read-only
    static constexpr uint32_t CIR_PLLRDYF = 0x10;       // Main PLL (PLL) ready interrupt flag, Read-only
    static constexpr uint32_t CIR_HSERDYF = 0x8;        // HSE ready interrupt flag, Read-only
    static constexpr uint32_t CIR_HSIRDYF = 0x4;        // HSI ready interrupt flag, Read-only
    static constexpr uint32_t CIR_LSERDYF = 0x2;        // LSE ready interrupt flag, Read-only
    static constexpr uint32_t CIR_LSIRDYF = 0x1;        // LSI ready interrupt flag, Read-only
    static const uint32_t CIR_RESET_VALUE = 0x0;

    static constexpr uint32_t AHB1RSTR_DMA2RST = 0x400000;   // DMA2 reset
    static constexpr uint32_t AHB1RSTR_DMA1RST = 0x200000;   // DMA2 reset
    static constexpr uint32_t AHB1RSTR_CRCRST = 0x1000;      // CRC reset
    static constexpr uint32_t AHB1RSTR_GPIOHRST = 0x80;      // IO port H reset
    static constexpr uint32_t AHB1RSTR_GPIOERST = 0x10;      // IO port E reset
    static constexpr uint32_t AHB1RSTR_GPIODRST = 0x8;       // IO port D reset
    static constexpr uint32_t AHB1RSTR_GPIOCRST = 0x4;       // IO port C reset
    static constexpr uint32_t AHB1RSTR_GPIOBRST = 0x2;       // IO port B reset
    static constexpr uint32_t AHB1RSTR_GPIOARST = 0x1;       // IO port A reset
    static const uint32_t AHB1RSTR_RESET_VALUE = 0x0;

    static constexpr uint32_t AHB2RSTR_OTGFSRST = 0x80;      // USB OTG FS module reset
    static const uint32_t AHB2RSTR_RESET_VALUE = 0x0;

    static constexpr uint32_t APB1RSTR_PWRRST = 0x10000000;  // Power interface reset
    static constexpr uint32_t APB1RSTR_I2C3RST = 0x800000;   // I2C3 reset
    static constexpr uint32_t APB1RSTR_I2C2RST = 0x400000;   // I2C 2 reset
    static constexpr uint32_t APB1RSTR_I2C1RST = 0x200000;   // I2C 1 reset
    static constexpr uint32_t APB1RSTR_UART2RST = 0x20000;   // USART 2 reset
    static constexpr uint32_t APB1RSTR_SPI3RST = 0x8000;     // SPI 3 reset
    static constexpr uint32_t APB1RSTR_SPI2RST = 0x4000;     // SPI 2 reset
    static constexpr uint32_t APB1RSTR_WWDGRST = 0x800;      // Window watchdog reset
    static constexpr uint32_t APB1RSTR_TIM5RST = 0x8;        // TIM5 reset
    static constexpr uint32_t APB1RSTR_TIM4RST = 0x4;        // TIM4 reset
    static constexpr uint32_t APB1RSTR_TIM3RST = 0x2;        // TIM3 reset
    static constexpr uint32_t APB1RSTR_TIM2RST = 0x1;        // TIM2 reset
    static const uint32_t APB1RSTR_RESET_VALUE = 0x0;

    static constexpr uint32_t APB2RSTR_TIM11RST = 0x40000;   // TIM11 reset
    static constexpr uint32_t APB2RSTR_TIM10RST = 0x20000;   // TIM10 reset
    static constexpr uint32_t APB2RSTR_TIM9RST = 0x10000;    // TIM9 reset
    static constexpr uint32_t APB2RSTR_SYSCFGRST = 0x4000;   // System configuration controller reset
    static constexpr uint32_t APB2RSTR_SPI1RST = 0x1000;     // SPI 1 reset
    static constexpr uint32_t APB2RSTR_SDIORST = 0x800;      // SDIO reset
    static constexpr uint32_t APB2RSTR_ADCRST = 0x100;       // ADC interface reset (common to all ADCs)
    static constexpr uint32_t APB2RSTR_USART6RST = 0x20;     // USART6 reset
    static constexpr uint32_t APB2RSTR_USART1RST = 0x10;     // USART1 reset
    static constexpr uint32_t APB2RSTR_TIM1RST = 0x1;        // TIM1 reset
    static const uint32_t APB2RSTR_RESET_VALUE = 0x0;

    static constexpr uint32_t AHB1ENR_DMA2EN = 0x400000;    // DMA2 clock enable
    static constexpr uint32_t AHB1ENR_DMA1EN = 0x200000;    // DMA1 clock enable
    static constexpr uint32_t AHB1ENR_CRCEN = 0x1000;       // CRC clock enable
    static constexpr uint32_t AHB1ENR_GPIOHEN = 0x80;       // IO port H clock enable
    static constexpr uint32_t AHB1ENR_GPIOEEN = 0x10;       // IO port E clock enable
    static constexpr uint32_t AHB1ENR_GPIODEN = 0x8;        // IO port D clock enable
    static constexpr uint32_t AHB1ENR_GPIOCEN = 0x4;        // IO port C clock enable
    static constexpr uint32_t AHB1ENR_GPIOBEN = 0x2;        // IO port B clock enable
    static constexpr uint32_t AHB1ENR_GPIOAEN = 0x1;        // IO port A clock enable
    static const uint32_t AHB1ENR_RESET_VALUE = 0x100000;

    static constexpr uint32_t AHB2ENR_OTGFSEN = 0x80;       // USB OTG FS clock enable
    static const uint32_t AHB2ENR_RESET_VALUE = 0x0;

    static constexpr uint32_t APB1ENR_PWREN = 0x10000000;   // Power interface clock enable
    static constexpr uint32_t APB1ENR_I2C3EN = 0x800000;    // I2C3 clock enable
    static constexpr uint32_t APB1ENR_I2C2EN = 0x400000;    // I2C2 clock enable
    static constexpr uint32_t APB1ENR_I2C1EN = 0x200000;    // I2C1 clock enable
    static constexpr uint32_t APB1ENR_USART2EN = 0x20000;   // USART 2 clock enable
    static constexpr uint32_t APB1ENR_SPI3EN = 0x8000;      // SPI3 clock enable
    static constexpr uint32_t APB1ENR_SPI2EN = 0x4000;      // SPI2 clock enable
    static constexpr uint32_t APB1ENR_WWDGEN = 0x800;       // Window watchdog clock enable
    static constexpr uint32_t APB1ENR_TIM5EN = 0x8;         // TIM5 clock enable
    static constexpr uint32_t APB1ENR_TIM4EN = 0x4;         // TIM4 clock enable
    static constexpr uint32_t APB1ENR_TIM3EN = 0x2;         // TIM3 clock enable
    static constexpr uint32_t APB1ENR_TIM2EN = 0x1;         // TIM2 clock enable
    static const uint32_t APB1ENR_RESET_VALUE = 0x0;

    static constexpr uint32_t APB2ENR_TIM1EN = 0x1;         // TIM1 clock enable
    static constexpr uint32_t APB2ENR_USART1EN = 0x10;      // USART1 clock enable
    static constexpr uint32_t APB2ENR_USART6EN = 0x20;      // USART6 clock enable
    static constexpr uint32_t APB2ENR_ADC1EN = 0x100;       // ADC1 clock enable
    static constexpr uint32_t APB2ENR_SDIOEN = 0x800;       // SDIO clock enable
    static constexpr uint32_t APB2ENR_SPI1EN = 0x1000;      // SPI1 clock enable
    static constexpr uint32_t APB2ENR_SPI4EN = 0x2000;      // SPI4 clock enable
    static constexpr uint32_t APB2ENR_SYSCFGEN = 0x4000;    // System configuration controller clock enable
    static constexpr uint32_t APB2ENR_TIM9EN = 0x10000;     // TIM9 clock enable
    static constexpr uint32_t APB2ENR_TIM10EN = 0x20000;    // TIM10 clock enable
    static constexpr uint32_t APB2ENR_TIM11EN = 0x40000;    // TIM11 clock enable
    static const uint32_t APB2ENR_RESET_VALUE = 0x0;

    static constexpr uint32_t AHB1LPENR_DMA2LPEN = 0x400000;  // DMA2 clock enable during Sleep mode
    static constexpr uint32_t AHB1LPENR_DMA1LPEN = 0x200000;  // DMA1 clock enable during Sleep mode
    static constexpr uint32_t AHB1LPENR_SRAM1LPEN = 0x10000;  // SRAM 1interface clock enable during Sleep mode
    static constexpr uint32_t AHB1LPENR_FLITFLPEN = 0x8000;   // Flash interface clock enable during Sleep mode
    static constexpr uint32_t AHB1LPENR_CRCLPEN = 0x1000;     // CRC clock enable during Sleep mode
    static constexpr uint32_t AHB1LPENR_GPIOHLPEN = 0x80;     // IO port H clock enable during Sleep mode
    static constexpr uint32_t AHB1LPENR_GPIOELPEN = 0x10;     // IO port E clock enable during Sleep mode
    static constexpr uint32_t AHB1LPENR_GPIODLPEN = 0x8;      // IO port D clock enable during Sleep mode
    static constexpr uint32_t AHB1LPENR_GPIOCLPEN = 0x4;      // IO port C clock enable during Sleep mode
    static constexpr uint32_t AHB1LPENR_GPIOBLPEN = 0x2;      // IO port B clock enable during Sleep mode
    static constexpr uint32_t AHB1LPENR_GPIOALPEN = 0x1;      // IO port A clock enable during sleep mode
    static const uint32_t AHB1LPENR_RESET_VALUE = 0x7e6791ff;

    static constexpr uint32_t AHB2LPENR_OTGFSLPEN = 0x80;     // USB OTG FS clock enable during Sleep mode
    static const uint32_t AHB2LPENR_RESET_VALUE = 0xf1;

    static constexpr uint32_t APB1LPENR_PWRLPEN = 0x10000000; // Power interface clock enable during Sleep mode
    static constexpr uint32_t APB1LPENR_I2C3LPEN = 0x800000;  // I2C3 clock enable during Sleep mode
    static constexpr uint32_t APB1LPENR_I2C2LPEN = 0x400000;  // I2C2 clock enable during Sleep mode
    static constexpr uint32_t APB1LPENR_I2C1LPEN = 0x200000;  // I2C1 clock enable during Sleep mode
    static constexpr uint32_t APB1LPENR_USART2LPEN = 0x20000; // USART2 clock enable during Sleep mode
    static constexpr uint32_t APB1LPENR_SPI3LPEN = 0x8000;    // SPI3 clock enable during Sleep mode
    static constexpr uint32_t APB1LPENR_SPI2LPEN = 0x4000;    // SPI2 clock enable during Sleep mode
    static constexpr uint32_t APB1LPENR_WWDGLPEN = 0x800;     // Window watchdog clock enable during Sleep mode
    static constexpr uint32_t APB1LPENR_TIM5LPEN = 0x8;       // TIM5 clock enable during Sleep mode
    static constexpr uint32_t APB1LPENR_TIM4LPEN = 0x4;       // TIM4 clock enable during Sleep mode
    static constexpr uint32_t APB1LPENR_TIM3LPEN = 0x2;       // TIM3 clock enable during Sleep mode
    static constexpr uint32_t APB1LPENR_TIM2LPEN = 0x1;       // TIM2 clock enable during Sleep mode
    static const uint32_t APB1LPENR_RESET_VALUE = 0x36fec9ff;

    static constexpr uint32_t APB2LPENR_TIM1LPEN = 0x1;       // TIM1 clock enable during Sleep mode
    static constexpr uint32_t APB2LPENR_USART1LPEN = 0x10;    // USART1 clock enable during Sleep mode
    static constexpr uint32_t APB2LPENR_USART6LPEN = 0x20;    // USART6 clock enable during Sleep mode
    static constexpr uint32_t APB2LPENR_ADC1LPEN = 0x100;     // ADC1 clock enable during Sleep mode
    static constexpr uint32_t APB2LPENR_SDIOLPEN = 0x800;     // SDIO clock enable during Sleep mode
    static constexpr uint32_t APB2LPENR_SPI1LPEN = 0x1000;    // SPI 1 clock enable during Sleep mode
    static constexpr uint32_t APB2LPENR_SPI4LPEN = 0x2000;    // SPI4 clock enable during Sleep mode
    static constexpr uint32_t APB2LPENR_SYSCFGLPEN = 0x4000;  // System configuration controller clock enable during Sleep mode
    static constexpr uint32_t APB2LPENR_TIM9LPEN = 0x10000;   // TIM9 clock enable during sleep mode
    static constexpr uint32_t APB2LPENR_TIM10LPEN = 0x20000;  // TIM10 clock enable during Sleep mode
    static constexpr uint32_t APB2LPENR_TIM11LPEN = 0x40000;  // TIM11 clock enable during Sleep mode
    static const uint32_t APB2LPENR_RESET_VALUE = 0x75f33;

    static constexpr uint32_t BDCR_BDRST = 0x10000;      // Backup domain software reset, Read-write
    static constexpr uint32_t BDCR_RTCEN = 0x8000;       // RTC clock enable, Read-write
    static constexpr uint32_t BDCR_RTCSEL1 = 0x200;      // RTC clock source selection, Read-write
    static constexpr uint32_t BDCR_RTCSEL0 = 0x100;      // RTC clock source selection, Read-write
    static constexpr uint32_t BDCR_LSEBYP = 0x4;         // External low-speed oscillator bypass, Read-write
    static constexpr uint32_t BDCR_LSERDY = 0x2;         // External low-speed oscillator ready, Read-only
    static constexpr uint32_t BDCR_LSEON = 0x1;          // External low-speed oscillator enable, Read-write
    static const uint32_t BDCR_RESET_VALUE = 0x0;

    static constexpr uint32_t CSR_LPWRRSTF = 0x80000000;// Low-power reset flag, Read-write
    static constexpr uint32_t CSR_WWDGRSTF = 0x40000000;// Window watchdog reset flag, Read-write
    static constexpr uint32_t CSR_WDGRSTF = 0x20000000; // Independent watchdog reset flag, Read-write
    static constexpr uint32_t CSR_SFTRSTF = 0x10000000; // Software reset flag, Read-write
    static constexpr uint32_t CSR_PORRSTF = 0x8000000;  // POR/PDR reset flag, Read-write
    static constexpr uint32_t CSR_PADRSTF = 0x4000000;  // PIN reset flag, Read-write
    static constexpr uint32_t CSR_BORRSTF = 0x2000000;  // BOR reset flag, Read-write
    static constexpr uint32_t CSR_RMVF = 0x1000000;     // Remove reset flag, Read-write
    static constexpr uint32_t CSR_LSIRDY = 0x2;         // Internal low-speed oscillator ready, Read-only
    static constexpr uint32_t CSR_LSION = 0x1;          // Internal low-speed oscillator enable, Read-write
    static const uint32_t CSR_RESET_VALUE = 0xe000000;

    static constexpr uint32_t SSCGR_SSCGEN = 0x80000000;  // Spread spectrum modulation enable
    static constexpr uint32_t SSCGR_SPREADSEL = 0x40000000;// Spread Select
    template<uint32_t X>
    static constexpr uint32_t SSCGR_INCSTEP =             // Incrementation step (15 bits)
        bit_field_t<13, 0x7fff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t SSCGR_MODPER =              // Modulation period (13 bits)
        bit_field_t<0, 0x1fff>::value<X>();
    static const uint32_t SSCGR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t PLLI2SCFGR_PLLI2SRx =            // PLLI2S division factor for I2S clocks (3 bits)
        bit_field_t<28, 0x7>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PLLI2SCFGR_PLLI2SNx =            // PLLI2S multiplication factor for VCO (9 bits)
        bit_field_t<6, 0x1ff>::value<X>();
    static const uint32_t PLLI2SCFGR_RESET_VALUE = 0x20003000;

    static constexpr uint8_t I2C1_ER = 32; // I2C1 error interrupt
    static constexpr uint8_t I2C1_EV = 31; // I2C1 event interrupt
};

static rcc_t& RCC = *reinterpret_cast<rcc_t*>(0x40023800);

#define HAVE_PERIPHERAL_RCC


////
//
//    Real-time clock
//
////

struct rtc_t
{
    volatile uint32_t    TR;                   // [Read-write] time register
    volatile uint32_t    DR;                   // [Read-write] date register
    volatile uint32_t    CR;                   // [Read-write] control register
    volatile uint32_t    ISR;                  // initialization and status register
    volatile uint32_t    PRER;                 // [Read-write] prescaler register
    volatile uint32_t    WUTR;                 // [Read-write] wakeup timer register
    volatile uint32_t    CALIBR;               // [Read-write] calibration register
    volatile uint32_t    ALRMAR;               // [Read-write] alarm A register
    volatile uint32_t    ALRMBR;               // [Read-write] alarm B register
    volatile uint32_t    WPR;                  // [Write-only] write protection register
    volatile uint32_t    SSR;                  // [Read-only] sub second register
    volatile uint32_t    SHIFTR;               // [Write-only] shift control register
    volatile uint32_t    TSTR;                 // [Read-only] time stamp time register
    volatile uint32_t    TSDR;                 // [Read-only] time stamp date register
    volatile uint32_t    TSSSR;                // [Read-only] timestamp sub second register
    volatile uint32_t    CALR;                 // [Read-write] calibration register
    volatile uint32_t    TAFCR;                // [Read-write] tamper and alternate function configuration register
    volatile uint32_t    ALRMASSR;             // [Read-write] alarm A sub second register
    volatile uint32_t    ALRMBSSR;             // [Read-write] alarm B sub second register
    reserved_t<1>        _0;
    volatile uint32_t    BKP0R;                // [Read-write] backup register
    volatile uint32_t    BKP1R;                // [Read-write] backup register
    volatile uint32_t    BKP2R;                // [Read-write] backup register
    volatile uint32_t    BKP3R;                // [Read-write] backup register
    volatile uint32_t    BKP4R;                // [Read-write] backup register
    volatile uint32_t    BKP5R;                // [Read-write] backup register
    volatile uint32_t    BKP6R;                // [Read-write] backup register
    volatile uint32_t    BKP7R;                // [Read-write] backup register
    volatile uint32_t    BKP8R;                // [Read-write] backup register
    volatile uint32_t    BKP9R;                // [Read-write] backup register
    volatile uint32_t    BKP10R;               // [Read-write] backup register
    volatile uint32_t    BKP11R;               // [Read-write] backup register
    volatile uint32_t    BKP12R;               // [Read-write] backup register
    volatile uint32_t    BKP13R;               // [Read-write] backup register
    volatile uint32_t    BKP14R;               // [Read-write] backup register
    volatile uint32_t    BKP15R;               // [Read-write] backup register
    volatile uint32_t    BKP16R;               // [Read-write] backup register
    volatile uint32_t    BKP17R;               // [Read-write] backup register
    volatile uint32_t    BKP18R;               // [Read-write] backup register
    volatile uint32_t    BKP19R;               // [Read-write] backup register

    static constexpr uint32_t TR_PM = 0x400000;        // AM/PM notation
    template<uint32_t X>
    static constexpr uint32_t TR_HT =                  // Hour tens in BCD format (2 bits)
        bit_field_t<20, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t TR_HU =                  // Hour units in BCD format (4 bits)
        bit_field_t<16, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t TR_MNT =                 // Minute tens in BCD format (3 bits)
        bit_field_t<12, 0x7>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t TR_MNU =                 // Minute units in BCD format (4 bits)
        bit_field_t<8, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t TR_ST =                  // Second tens in BCD format (3 bits)
        bit_field_t<4, 0x7>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t TR_SU =                  // Second units in BCD format (4 bits)
        bit_field_t<0, 0xf>::value<X>();
    static const uint32_t TR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t DR_YT =                  // Year tens in BCD format (4 bits)
        bit_field_t<20, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t DR_YU =                  // Year units in BCD format (4 bits)
        bit_field_t<16, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t DR_WDU =                 // Week day units (3 bits)
        bit_field_t<13, 0x7>::value<X>();
    static constexpr uint32_t DR_MT = 0x1000;          // Month tens in BCD format
    template<uint32_t X>
    static constexpr uint32_t DR_MU =                  // Month units in BCD format (4 bits)
        bit_field_t<8, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t DR_DT =                  // Date tens in BCD format (2 bits)
        bit_field_t<4, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t DR_DU =                  // Date units in BCD format (4 bits)
        bit_field_t<0, 0xf>::value<X>();
    static const uint32_t DR_RESET_VALUE = 0x2101;

    static constexpr uint32_t CR_COE = 0x800000;       // Calibration output enable
    template<uint32_t X>
    static constexpr uint32_t CR_OSEL =                // Output selection (2 bits)
        bit_field_t<21, 0x3>::value<X>();
    static constexpr uint32_t CR_POL = 0x100000;       // Output polarity
    static constexpr uint32_t CR_COSEL = 0x80000;      // Calibration Output selection
    static constexpr uint32_t CR_BKP = 0x40000;        // Backup
    static constexpr uint32_t CR_SUB1H = 0x20000;      // Subtract 1 hour (winter time change)
    static constexpr uint32_t CR_ADD1H = 0x10000;      // Add 1 hour (summer time change)
    static constexpr uint32_t CR_TSIE = 0x8000;        // Time-stamp interrupt enable
    static constexpr uint32_t CR_WUTIE = 0x4000;       // Wakeup timer interrupt enable
    static constexpr uint32_t CR_ALRBIE = 0x2000;      // Alarm B interrupt enable
    static constexpr uint32_t CR_ALRAIE = 0x1000;      // Alarm A interrupt enable
    static constexpr uint32_t CR_TSE = 0x800;          // Time stamp enable
    static constexpr uint32_t CR_WUTE = 0x400;         // Wakeup timer enable
    static constexpr uint32_t CR_ALRBE = 0x200;        // Alarm B enable
    static constexpr uint32_t CR_ALRAE = 0x100;        // Alarm A enable
    static constexpr uint32_t CR_DCE = 0x80;           // Coarse digital calibration enable
    static constexpr uint32_t CR_FMT = 0x40;           // Hour format
    static constexpr uint32_t CR_BYPSHAD = 0x20;       // Bypass the shadow registers
    static constexpr uint32_t CR_REFCKON = 0x10;       // Reference clock detection enable (50 or 60 Hz)
    static constexpr uint32_t CR_TSEDGE = 0x8;         // Time-stamp event active edge
    template<uint32_t X>
    static constexpr uint32_t CR_WCKSEL =              // Wakeup clock selection (3 bits)
        bit_field_t<0, 0x7>::value<X>();
    static const uint32_t CR_RESET_VALUE = 0x0;

    static constexpr uint32_t ISR_ALRAWF = 0x1;         // Alarm A write flag, Read-only
    static constexpr uint32_t ISR_ALRBWF = 0x2;         // Alarm B write flag, Read-only
    static constexpr uint32_t ISR_WUTWF = 0x4;          // Wakeup timer write flag, Read-only
    static constexpr uint32_t ISR_SHPF = 0x8;           // Shift operation pending, Read-write
    static constexpr uint32_t ISR_INITS = 0x10;         // Initialization status flag, Read-only
    static constexpr uint32_t ISR_RSF = 0x20;           // Registers synchronization flag, Read-write
    static constexpr uint32_t ISR_INITF = 0x40;         // Initialization flag, Read-only
    static constexpr uint32_t ISR_INIT = 0x80;          // Initialization mode, Read-write
    static constexpr uint32_t ISR_ALRAF = 0x100;        // Alarm A flag, Read-write
    static constexpr uint32_t ISR_ALRBF = 0x200;        // Alarm B flag, Read-write
    static constexpr uint32_t ISR_WUTF = 0x400;         // Wakeup timer flag, Read-write
    static constexpr uint32_t ISR_TSF = 0x800;          // Time-stamp flag, Read-write
    static constexpr uint32_t ISR_TSOVF = 0x1000;       // Time-stamp overflow flag, Read-write
    static constexpr uint32_t ISR_TAMP1F = 0x2000;      // Tamper detection flag, Read-write
    static constexpr uint32_t ISR_TAMP2F = 0x4000;      // TAMPER2 detection flag, Read-write
    static constexpr uint32_t ISR_RECALPF = 0x10000;    // Recalibration pending Flag, Read-only
    static const uint32_t ISR_RESET_VALUE = 0x7;

    template<uint32_t X>
    static constexpr uint32_t PRER_PREDIV_A =            // Asynchronous prescaler factor (7 bits)
        bit_field_t<16, 0x7f>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PRER_PREDIV_S =            // Synchronous prescaler factor (15 bits)
        bit_field_t<0, 0x7fff>::value<X>();
    static const uint32_t PRER_RESET_VALUE = 0x7f00ff;

    template<uint32_t X>
    static constexpr uint32_t WUTR_WUT =                 // Wakeup auto-reload value bits (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t WUTR_RESET_VALUE = 0xffff;

    static constexpr uint32_t CALIBR_DCS = 0x80;           // Digital calibration sign
    template<uint32_t X>
    static constexpr uint32_t CALIBR_DC =                  // Digital calibration (5 bits)
        bit_field_t<0, 0x1f>::value<X>();
    static const uint32_t CALIBR_RESET_VALUE = 0x0;

    static constexpr uint32_t ALRMAR_MSK4 = 0x80000000;    // Alarm A date mask
    static constexpr uint32_t ALRMAR_WDSEL = 0x40000000;   // Week day selection
    template<uint32_t X>
    static constexpr uint32_t ALRMAR_DT =                  // Date tens in BCD format (2 bits)
        bit_field_t<28, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t ALRMAR_DU =                  // Date units or day in BCD format (4 bits)
        bit_field_t<24, 0xf>::value<X>();
    static constexpr uint32_t ALRMAR_MSK3 = 0x800000;      // Alarm A hours mask
    static constexpr uint32_t ALRMAR_PM = 0x400000;        // AM/PM notation
    template<uint32_t X>
    static constexpr uint32_t ALRMAR_HT =                  // Hour tens in BCD format (2 bits)
        bit_field_t<20, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t ALRMAR_HU =                  // Hour units in BCD format (4 bits)
        bit_field_t<16, 0xf>::value<X>();
    static constexpr uint32_t ALRMAR_MSK2 = 0x8000;        // Alarm A minutes mask
    template<uint32_t X>
    static constexpr uint32_t ALRMAR_MNT =                 // Minute tens in BCD format (3 bits)
        bit_field_t<12, 0x7>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t ALRMAR_MNU =                 // Minute units in BCD format (4 bits)
        bit_field_t<8, 0xf>::value<X>();
    static constexpr uint32_t ALRMAR_MSK1 = 0x80;          // Alarm A seconds mask
    template<uint32_t X>
    static constexpr uint32_t ALRMAR_ST =                  // Second tens in BCD format (3 bits)
        bit_field_t<4, 0x7>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t ALRMAR_SU =                  // Second units in BCD format (4 bits)
        bit_field_t<0, 0xf>::value<X>();
    static const uint32_t ALRMAR_RESET_VALUE = 0x0;

    static constexpr uint32_t ALRMBR_MSK4 = 0x80000000;    // Alarm B date mask
    static constexpr uint32_t ALRMBR_WDSEL = 0x40000000;   // Week day selection
    template<uint32_t X>
    static constexpr uint32_t ALRMBR_DT =                  // Date tens in BCD format (2 bits)
        bit_field_t<28, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t ALRMBR_DU =                  // Date units or day in BCD format (4 bits)
        bit_field_t<24, 0xf>::value<X>();
    static constexpr uint32_t ALRMBR_MSK3 = 0x800000;      // Alarm B hours mask
    static constexpr uint32_t ALRMBR_PM = 0x400000;        // AM/PM notation
    template<uint32_t X>
    static constexpr uint32_t ALRMBR_HT =                  // Hour tens in BCD format (2 bits)
        bit_field_t<20, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t ALRMBR_HU =                  // Hour units in BCD format (4 bits)
        bit_field_t<16, 0xf>::value<X>();
    static constexpr uint32_t ALRMBR_MSK2 = 0x8000;        // Alarm B minutes mask
    template<uint32_t X>
    static constexpr uint32_t ALRMBR_MNT =                 // Minute tens in BCD format (3 bits)
        bit_field_t<12, 0x7>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t ALRMBR_MNU =                 // Minute units in BCD format (4 bits)
        bit_field_t<8, 0xf>::value<X>();
    static constexpr uint32_t ALRMBR_MSK1 = 0x80;          // Alarm B seconds mask
    template<uint32_t X>
    static constexpr uint32_t ALRMBR_ST =                  // Second tens in BCD format (3 bits)
        bit_field_t<4, 0x7>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t ALRMBR_SU =                  // Second units in BCD format (4 bits)
        bit_field_t<0, 0xf>::value<X>();
    static const uint32_t ALRMBR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t WPR_KEY =                 // Write protection key (8 bits)
        bit_field_t<0, 0xff>::value<X>();
    static const uint32_t WPR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t SSR_SS =                  // Sub second value (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t SSR_RESET_VALUE = 0x0;

    static constexpr uint32_t SHIFTR_ADD1S = 0x80000000;   // Add one second
    template<uint32_t X>
    static constexpr uint32_t SHIFTR_SUBFS =               // Subtract a fraction of a second (15 bits)
        bit_field_t<0, 0x7fff>::value<X>();
    static const uint32_t SHIFTR_RESET_VALUE = 0x0;

    static constexpr uint32_t TSTR_PM = 0x400000;        // AM/PM notation
    template<uint32_t X>
    static constexpr uint32_t TSTR_HT =                  // Hour tens in BCD format (2 bits)
        bit_field_t<20, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t TSTR_HU =                  // Hour units in BCD format (4 bits)
        bit_field_t<16, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t TSTR_MNT =                 // Minute tens in BCD format (3 bits)
        bit_field_t<12, 0x7>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t TSTR_MNU =                 // Minute units in BCD format (4 bits)
        bit_field_t<8, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t TSTR_ST =                  // Second tens in BCD format (3 bits)
        bit_field_t<4, 0x7>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t TSTR_SU =                  // Second units in BCD format (4 bits)
        bit_field_t<0, 0xf>::value<X>();
    static const uint32_t TSTR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t TSDR_WDU =                 // Week day units (3 bits)
        bit_field_t<13, 0x7>::value<X>();
    static constexpr uint32_t TSDR_MT = 0x1000;          // Month tens in BCD format
    template<uint32_t X>
    static constexpr uint32_t TSDR_MU =                  // Month units in BCD format (4 bits)
        bit_field_t<8, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t TSDR_DT =                  // Date tens in BCD format (2 bits)
        bit_field_t<4, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t TSDR_DU =                  // Date units in BCD format (4 bits)
        bit_field_t<0, 0xf>::value<X>();
    static const uint32_t TSDR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t TSSSR_SS =                  // Sub second value (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t TSSSR_RESET_VALUE = 0x0;

    static constexpr uint32_t CALR_CALP = 0x8000;        // Increase frequency of RTC by 488.5 ppm
    static constexpr uint32_t CALR_CALW8 = 0x4000;       // Use an 8-second calibration cycle period
    static constexpr uint32_t CALR_CALW16 = 0x2000;      // Use a 16-second calibration cycle period
    template<uint32_t X>
    static constexpr uint32_t CALR_CALM =                // Calibration minus (9 bits)
        bit_field_t<0, 0x1ff>::value<X>();
    static const uint32_t CALR_RESET_VALUE = 0x0;

    static constexpr uint32_t TAFCR_ALARMOUTTYPE = 0x40000;// AFO_ALARM output type
    static constexpr uint32_t TAFCR_TSINSEL = 0x20000;    // TIMESTAMP mapping
    static constexpr uint32_t TAFCR_TAMP1INSEL = 0x10000; // TAMPER1 mapping
    static constexpr uint32_t TAFCR_TAMPPUDIS = 0x8000;   // TAMPER pull-up disable
    template<uint32_t X>
    static constexpr uint32_t TAFCR_TAMPPRCH =            // Tamper precharge duration (2 bits)
        bit_field_t<13, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t TAFCR_TAMPFLT =             // Tamper filter count (2 bits)
        bit_field_t<11, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t TAFCR_TAMPFREQ =            // Tamper sampling frequency (3 bits)
        bit_field_t<8, 0x7>::value<X>();
    static constexpr uint32_t TAFCR_TAMPTS = 0x80;        // Activate timestamp on tamper detection event
    static constexpr uint32_t TAFCR_TAMP2TRG = 0x10;      // Active level for tamper 2
    static constexpr uint32_t TAFCR_TAMP2E = 0x8;         // Tamper 2 detection enable
    static constexpr uint32_t TAFCR_TAMPIE = 0x4;         // Tamper interrupt enable
    static constexpr uint32_t TAFCR_TAMP1TRG = 0x2;       // Active level for tamper 1
    static constexpr uint32_t TAFCR_TAMP1E = 0x1;         // Tamper 1 detection enable
    static const uint32_t TAFCR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t ALRMASSR_MASKSS =              // Mask the most-significant bits starting at this bit (4 bits)
        bit_field_t<24, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t ALRMASSR_SS =                  // Sub seconds value (15 bits)
        bit_field_t<0, 0x7fff>::value<X>();
    static const uint32_t ALRMASSR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t ALRMBSSR_MASKSS =              // Mask the most-significant bits starting at this bit (4 bits)
        bit_field_t<24, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t ALRMBSSR_SS =                  // Sub seconds value (15 bits)
        bit_field_t<0, 0x7fff>::value<X>();
    static const uint32_t ALRMBSSR_RESET_VALUE = 0x0;


    static const uint32_t BKP0R_RESET_VALUE = 0x0;


    static const uint32_t BKP1R_RESET_VALUE = 0x0;


    static const uint32_t BKP2R_RESET_VALUE = 0x0;


    static const uint32_t BKP3R_RESET_VALUE = 0x0;


    static const uint32_t BKP4R_RESET_VALUE = 0x0;


    static const uint32_t BKP5R_RESET_VALUE = 0x0;


    static const uint32_t BKP6R_RESET_VALUE = 0x0;


    static const uint32_t BKP7R_RESET_VALUE = 0x0;


    static const uint32_t BKP8R_RESET_VALUE = 0x0;


    static const uint32_t BKP9R_RESET_VALUE = 0x0;


    static const uint32_t BKP10R_RESET_VALUE = 0x0;


    static const uint32_t BKP11R_RESET_VALUE = 0x0;


    static const uint32_t BKP12R_RESET_VALUE = 0x0;


    static const uint32_t BKP13R_RESET_VALUE = 0x0;


    static const uint32_t BKP14R_RESET_VALUE = 0x0;


    static const uint32_t BKP15R_RESET_VALUE = 0x0;


    static const uint32_t BKP16R_RESET_VALUE = 0x0;


    static const uint32_t BKP17R_RESET_VALUE = 0x0;


    static const uint32_t BKP18R_RESET_VALUE = 0x0;


    static const uint32_t BKP19R_RESET_VALUE = 0x0;

    static constexpr uint8_t I2C2_ER = 34; // I2C2 error interrupt
    static constexpr uint8_t I2C2_EV = 33; // I2C2 event interrupt
};

static rtc_t& RTC = *reinterpret_cast<rtc_t*>(0x40002800);

#define HAVE_PERIPHERAL_RTC


////
//
//    Secure digital input/output interface
//
////

struct sdio_t
{
    volatile uint32_t    POWER;                // [Read-write] power control register
    volatile uint32_t    CLKCR;                // [Read-write] SDI clock control register
    volatile uint32_t    ARG;                  // [Read-write] argument register
    volatile uint32_t    CMD;                  // [Read-write] command register
    volatile uint32_t    RESPCMD;              // [Read-only] command response register
    volatile uint32_t    RESP1;                // [Read-only] response 1..4 register
    volatile uint32_t    RESP2;                // [Read-only] response 1..4 register
    volatile uint32_t    RESP3;                // [Read-only] response 1..4 register
    volatile uint32_t    RESP4;                // [Read-only] response 1..4 register
    volatile uint32_t    DTIMER;               // [Read-write] data timer register
    volatile uint32_t    DLEN;                 // [Read-write] data length register
    volatile uint32_t    DCTRL;                // [Read-write] data control register
    volatile uint32_t    DCOUNT;               // [Read-only] data counter register
    volatile uint32_t    STA;                  // [Read-only] status register
    volatile uint32_t    ICR;                  // [Read-write] interrupt clear register
    volatile uint32_t    MASK;                 // [Read-write] mask register
    reserved_t<2>        _0;
    volatile uint32_t    FIFOCNT;              // [Read-only] FIFO counter register
    reserved_t<13>       _1;
    volatile uint32_t    FIFO;                 // [Read-write] data FIFO register

    template<uint32_t X>
    static constexpr uint32_t POWER_PWRCTRL =             // PWRCTRL (2 bits)
        bit_field_t<0, 0x3>::value<X>();
    static const uint32_t POWER_RESET_VALUE = 0x0;

    static constexpr uint32_t CLKCR_HWFC_EN = 0x4000;     // HW Flow Control enable
    static constexpr uint32_t CLKCR_NEGEDGE = 0x2000;     // SDIO_CK dephasing selection bit
    template<uint32_t X>
    static constexpr uint32_t CLKCR_WIDBUS =              // Wide bus mode enable bit (2 bits)
        bit_field_t<11, 0x3>::value<X>();
    static constexpr uint32_t CLKCR_BYPASS = 0x400;       // Clock divider bypass enable bit
    static constexpr uint32_t CLKCR_PWRSAV = 0x200;       // Power saving configuration bit
    static constexpr uint32_t CLKCR_CLKEN = 0x100;        // Clock enable bit
    template<uint32_t X>
    static constexpr uint32_t CLKCR_CLKDIV =              // Clock divide factor (8 bits)
        bit_field_t<0, 0xff>::value<X>();
    static const uint32_t CLKCR_RESET_VALUE = 0x0;


    static const uint32_t ARG_RESET_VALUE = 0x0;

    static constexpr uint32_t CMD_CE_ATACMD = 0x4000;   // CE-ATA command
    static constexpr uint32_t CMD_nIEN = 0x2000;        // not Interrupt Enable
    static constexpr uint32_t CMD_ENCMDcompl = 0x1000;  // Enable CMD completion
    static constexpr uint32_t CMD_SDIOSuspend = 0x800;  // SD I/O suspend command
    static constexpr uint32_t CMD_CPSMEN = 0x400;       // Command path state machine (CPSM) Enable bit
    static constexpr uint32_t CMD_WAITPEND = 0x200;     // CPSM Waits for ends of data transfer (CmdPend internal signal).
    static constexpr uint32_t CMD_WAITINT = 0x100;      // CPSM waits for interrupt request
    template<uint32_t X>
    static constexpr uint32_t CMD_WAITRESP =            // Wait for response bits (2 bits)
        bit_field_t<6, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CMD_CMDINDEX =            // Command index (6 bits)
        bit_field_t<0, 0x3f>::value<X>();
    static const uint32_t CMD_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t RESPCMD_RESPCMD =             // Response command index (6 bits)
        bit_field_t<0, 0x3f>::value<X>();
    static const uint32_t RESPCMD_RESET_VALUE = 0x0;


    static const uint32_t RESP1_RESET_VALUE = 0x0;


    static const uint32_t RESP2_RESET_VALUE = 0x0;


    static const uint32_t RESP3_RESET_VALUE = 0x0;


    static const uint32_t RESP4_RESET_VALUE = 0x0;


    static const uint32_t DTIMER_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t DLEN_DATALENGTH =          // Data length value (25 bits)
        bit_field_t<0, 0x1ffffff>::value<X>();
    static const uint32_t DLEN_RESET_VALUE = 0x0;

    static constexpr uint32_t DCTRL_SDIOEN = 0x800;       // SD I/O enable functions
    static constexpr uint32_t DCTRL_RWMOD = 0x400;        // Read wait mode
    static constexpr uint32_t DCTRL_RWSTOP = 0x200;       // Read wait stop
    static constexpr uint32_t DCTRL_RWSTART = 0x100;      // Read wait start
    template<uint32_t X>
    static constexpr uint32_t DCTRL_DBLOCKSIZE =          // Data block size (4 bits)
        bit_field_t<4, 0xf>::value<X>();
    static constexpr uint32_t DCTRL_DMAEN = 0x8;          // DMA enable bit
    static constexpr uint32_t DCTRL_DTMODE = 0x4;         // Data transfer mode selection 1: Stream or SDIO multibyte data transfer.
    static constexpr uint32_t DCTRL_DTDIR = 0x2;          // Data transfer direction selection
    static constexpr uint32_t DCTRL_DTEN = 0x1;           // DTEN
    static const uint32_t DCTRL_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t DCOUNT_DATACOUNT =           // Data count value (25 bits)
        bit_field_t<0, 0x1ffffff>::value<X>();
    static const uint32_t DCOUNT_RESET_VALUE = 0x0;

    static constexpr uint32_t STA_CEATAEND = 0x800000;  // CE-ATA command completion signal received for CMD61
    static constexpr uint32_t STA_SDIOIT = 0x400000;    // SDIO interrupt received
    static constexpr uint32_t STA_RXDAVL = 0x200000;    // Data available in receive FIFO
    static constexpr uint32_t STA_TXDAVL = 0x100000;    // Data available in transmit FIFO
    static constexpr uint32_t STA_RXFIFOE = 0x80000;    // Receive FIFO empty
    static constexpr uint32_t STA_TXFIFOE = 0x40000;    // Transmit FIFO empty
    static constexpr uint32_t STA_RXFIFOF = 0x20000;    // Receive FIFO full
    static constexpr uint32_t STA_TXFIFOF = 0x10000;    // Transmit FIFO full
    static constexpr uint32_t STA_RXFIFOHF = 0x8000;    // Receive FIFO half full: there are at least 8 words in the FIFO
    static constexpr uint32_t STA_TXFIFOHE = 0x4000;    // Transmit FIFO half empty: at least 8 words can be written into the FIFO
    static constexpr uint32_t STA_RXACT = 0x2000;       // Data receive in progress
    static constexpr uint32_t STA_TXACT = 0x1000;       // Data transmit in progress
    static constexpr uint32_t STA_CMDACT = 0x800;       // Command transfer in progress
    static constexpr uint32_t STA_DBCKEND = 0x400;      // Data block sent/received (CRC check passed)
    static constexpr uint32_t STA_STBITERR = 0x200;     // Start bit not detected on all data signals in wide bus mode
    static constexpr uint32_t STA_DATAEND = 0x100;      // Data end (data counter, SDIDCOUNT, is zero)
    static constexpr uint32_t STA_CMDSENT = 0x80;       // Command sent (no response required)
    static constexpr uint32_t STA_CMDREND = 0x40;       // Command response received (CRC check passed)
    static constexpr uint32_t STA_RXOVERR = 0x20;       // Received FIFO overrun error
    static constexpr uint32_t STA_TXUNDERR = 0x10;      // Transmit FIFO underrun error
    static constexpr uint32_t STA_DTIMEOUT = 0x8;       // Data timeout
    static constexpr uint32_t STA_CTIMEOUT = 0x4;       // Command response timeout
    static constexpr uint32_t STA_DCRCFAIL = 0x2;       // Data block sent/received (CRC check failed)
    static constexpr uint32_t STA_CCRCFAIL = 0x1;       // Command response received (CRC check failed)
    static const uint32_t STA_RESET_VALUE = 0x0;

    static constexpr uint32_t ICR_CEATAENDC = 0x800000; // CEATAEND flag clear bit
    static constexpr uint32_t ICR_SDIOITC = 0x400000;   // SDIOIT flag clear bit
    static constexpr uint32_t ICR_DBCKENDC = 0x400;     // DBCKEND flag clear bit
    static constexpr uint32_t ICR_STBITERRC = 0x200;    // STBITERR flag clear bit
    static constexpr uint32_t ICR_DATAENDC = 0x100;     // DATAEND flag clear bit
    static constexpr uint32_t ICR_CMDSENTC = 0x80;      // CMDSENT flag clear bit
    static constexpr uint32_t ICR_CMDRENDC = 0x40;      // CMDREND flag clear bit
    static constexpr uint32_t ICR_RXOVERRC = 0x20;      // RXOVERR flag clear bit
    static constexpr uint32_t ICR_TXUNDERRC = 0x10;     // TXUNDERR flag clear bit
    static constexpr uint32_t ICR_DTIMEOUTC = 0x8;      // DTIMEOUT flag clear bit
    static constexpr uint32_t ICR_CTIMEOUTC = 0x4;      // CTIMEOUT flag clear bit
    static constexpr uint32_t ICR_DCRCFAILC = 0x2;      // DCRCFAIL flag clear bit
    static constexpr uint32_t ICR_CCRCFAILC = 0x1;      // CCRCFAIL flag clear bit
    static const uint32_t ICR_RESET_VALUE = 0x0;

    static constexpr uint32_t MASK_CEATAENDIE = 0x800000;// CE-ATA command completion signal received interrupt enable
    static constexpr uint32_t MASK_SDIOITIE = 0x400000;  // SDIO mode interrupt received interrupt enable
    static constexpr uint32_t MASK_RXDAVLIE = 0x200000;  // Data available in Rx FIFO interrupt enable
    static constexpr uint32_t MASK_TXDAVLIE = 0x100000;  // Data available in Tx FIFO interrupt enable
    static constexpr uint32_t MASK_RXFIFOEIE = 0x80000;  // Rx FIFO empty interrupt enable
    static constexpr uint32_t MASK_TXFIFOEIE = 0x40000;  // Tx FIFO empty interrupt enable
    static constexpr uint32_t MASK_RXFIFOFIE = 0x20000;  // Rx FIFO full interrupt enable
    static constexpr uint32_t MASK_TXFIFOFIE = 0x10000;  // Tx FIFO full interrupt enable
    static constexpr uint32_t MASK_RXFIFOHFIE = 0x8000;  // Rx FIFO half full interrupt enable
    static constexpr uint32_t MASK_TXFIFOHEIE = 0x4000;  // Tx FIFO half empty interrupt enable
    static constexpr uint32_t MASK_RXACTIE = 0x2000;     // Data receive acting interrupt enable
    static constexpr uint32_t MASK_TXACTIE = 0x1000;     // Data transmit acting interrupt enable
    static constexpr uint32_t MASK_CMDACTIE = 0x800;     // Command acting interrupt enable
    static constexpr uint32_t MASK_DBCKENDIE = 0x400;    // Data block end interrupt enable
    static constexpr uint32_t MASK_STBITERRIE = 0x200;   // Start bit error interrupt enable
    static constexpr uint32_t MASK_DATAENDIE = 0x100;    // Data end interrupt enable
    static constexpr uint32_t MASK_CMDSENTIE = 0x80;     // Command sent interrupt enable
    static constexpr uint32_t MASK_CMDRENDIE = 0x40;     // Command response received interrupt enable
    static constexpr uint32_t MASK_RXOVERRIE = 0x20;     // Rx FIFO overrun error interrupt enable
    static constexpr uint32_t MASK_TXUNDERRIE = 0x10;    // Tx FIFO underrun error interrupt enable
    static constexpr uint32_t MASK_DTIMEOUTIE = 0x8;     // Data timeout interrupt enable
    static constexpr uint32_t MASK_CTIMEOUTIE = 0x4;     // Command timeout interrupt enable
    static constexpr uint32_t MASK_DCRCFAILIE = 0x2;     // Data CRC fail interrupt enable
    static constexpr uint32_t MASK_CCRCFAILIE = 0x1;     // Command CRC fail interrupt enable
    static const uint32_t MASK_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t FIFOCNT_FIFOCOUNT =           // Remaining number of words to be written to or read from the FIFO. (24 bits)
        bit_field_t<0, 0xffffff>::value<X>();
    static const uint32_t FIFOCNT_RESET_VALUE = 0x0;


    static const uint32_t FIFO_RESET_VALUE = 0x0;

    static constexpr uint8_t I2C3_ER = 73; // I2C3 error interrupt
    static constexpr uint8_t I2C3_EV = 72; // I2C3 event interrupt
};

static sdio_t& SDIO = *reinterpret_cast<sdio_t*>(0x40012c00);

#define HAVE_PERIPHERAL_SDIO


////
//
//    System configuration controller
//
////

struct syscfg_t
{
    volatile uint32_t    MEMRM;                // [Read-write] memory remap register
    volatile uint32_t    PMC;                  // [Read-write] peripheral mode configuration register
    volatile uint32_t    EXTICR1;              // [Read-write] external interrupt configuration register 1
    volatile uint32_t    EXTICR2;              // [Read-write] external interrupt configuration register 2
    volatile uint32_t    EXTICR3;              // [Read-write] external interrupt configuration register 3
    volatile uint32_t    EXTICR4;              // [Read-write] external interrupt configuration register 4
    reserved_t<2>        _0;
    volatile uint32_t    CMPCR;                // [Read-only] Compensation cell control register

    template<uint32_t X>
    static constexpr uint32_t MEMRM_MEM_MODE =            // MEM_MODE (2 bits)
        bit_field_t<0, 0x3>::value<X>();
    static const uint32_t MEMRM_RESET_VALUE = 0x0;

    static constexpr uint32_t PMC_ADC1DC2 = 0x10000;    // ADC1DC2
    static const uint32_t PMC_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t EXTICR1_EXTI3 =               // EXTI x configuration (x = 0 to 3) (4 bits)
        bit_field_t<12, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t EXTICR1_EXTI2 =               // EXTI x configuration (x = 0 to 3) (4 bits)
        bit_field_t<8, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t EXTICR1_EXTI1 =               // EXTI x configuration (x = 0 to 3) (4 bits)
        bit_field_t<4, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t EXTICR1_EXTI0 =               // EXTI x configuration (x = 0 to 3) (4 bits)
        bit_field_t<0, 0xf>::value<X>();
    static const uint32_t EXTICR1_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t EXTICR2_EXTI7 =               // EXTI x configuration (x = 4 to 7) (4 bits)
        bit_field_t<12, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t EXTICR2_EXTI6 =               // EXTI x configuration (x = 4 to 7) (4 bits)
        bit_field_t<8, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t EXTICR2_EXTI5 =               // EXTI x configuration (x = 4 to 7) (4 bits)
        bit_field_t<4, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t EXTICR2_EXTI4 =               // EXTI x configuration (x = 4 to 7) (4 bits)
        bit_field_t<0, 0xf>::value<X>();
    static const uint32_t EXTICR2_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t EXTICR3_EXTI11 =              // EXTI x configuration (x = 8 to 11) (4 bits)
        bit_field_t<12, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t EXTICR3_EXTI10 =              // EXTI10 (4 bits)
        bit_field_t<8, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t EXTICR3_EXTI9 =               // EXTI x configuration (x = 8 to 11) (4 bits)
        bit_field_t<4, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t EXTICR3_EXTI8 =               // EXTI x configuration (x = 8 to 11) (4 bits)
        bit_field_t<0, 0xf>::value<X>();
    static const uint32_t EXTICR3_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t EXTICR4_EXTI15 =              // EXTI x configuration (x = 12 to 15) (4 bits)
        bit_field_t<12, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t EXTICR4_EXTI14 =              // EXTI x configuration (x = 12 to 15) (4 bits)
        bit_field_t<8, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t EXTICR4_EXTI13 =              // EXTI x configuration (x = 12 to 15) (4 bits)
        bit_field_t<4, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t EXTICR4_EXTI12 =              // EXTI x configuration (x = 12 to 15) (4 bits)
        bit_field_t<0, 0xf>::value<X>();
    static const uint32_t EXTICR4_RESET_VALUE = 0x0;

    static constexpr uint32_t CMPCR_READY = 0x100;        // READY
    static constexpr uint32_t CMPCR_CMP_PD = 0x1;         // Compensation cell power-down
    static const uint32_t CMPCR_RESET_VALUE = 0x0;
};

static syscfg_t& SYSCFG = *reinterpret_cast<syscfg_t*>(0x40013800);

#define HAVE_PERIPHERAL_SYSCFG


////
//
//    Advanced-timers
//
////

struct tim1_t
{
    volatile uint32_t    CR1;                  // [Read-write] control register 1
    volatile uint32_t    CR2;                  // [Read-write] control register 2
    volatile uint32_t    SMCR;                 // [Read-write] slave mode control register
    volatile uint32_t    DIER;                 // [Read-write] DMA/Interrupt enable register
    volatile uint32_t    SR;                   // [Read-write] status register
    volatile uint32_t    EGR;                  // [Write-only] event generation register
    volatile uint32_t    CCMR1;                // [Read-write] capture/compare mode register 1 (output mode)
    volatile uint32_t    CCMR2;                // [Read-write] capture/compare mode register 2 (output mode)
    volatile uint32_t    CCER;                 // [Read-write] capture/compare enable register
    volatile uint32_t    CNT;                  // [Read-write] counter
    volatile uint32_t    PSC;                  // [Read-write] prescaler
    volatile uint32_t    ARR;                  // [Read-write] auto-reload register
    volatile uint32_t    RCR;                  // [Read-write] repetition counter register
    volatile uint32_t    CCR1;                 // [Read-write] capture/compare register 1
    volatile uint32_t    CCR2;                 // [Read-write] capture/compare register 2
    volatile uint32_t    CCR3;                 // [Read-write] capture/compare register 3
    volatile uint32_t    CCR4;                 // [Read-write] capture/compare register 4
    volatile uint32_t    BDTR;                 // [Read-write] break and dead-time register
    volatile uint32_t    DCR;                  // [Read-write] DMA control register
    volatile uint32_t    DMAR;                 // [Read-write] DMA address for full transfer

    template<uint32_t X>
    static constexpr uint32_t CR1_CKD =                 // Clock division (2 bits)
        bit_field_t<8, 0x3>::value<X>();
    static constexpr uint32_t CR1_ARPE = 0x80;          // Auto-reload preload enable
    template<uint32_t X>
    static constexpr uint32_t CR1_CMS =                 // Center-aligned mode selection (2 bits)
        bit_field_t<5, 0x3>::value<X>();
    static constexpr uint32_t CR1_DIR = 0x10;           // Direction
    static constexpr uint32_t CR1_OPM = 0x8;            // One-pulse mode
    static constexpr uint32_t CR1_URS = 0x4;            // Update request source
    static constexpr uint32_t CR1_UDIS = 0x2;           // Update disable
    static constexpr uint32_t CR1_CEN = 0x1;            // Counter enable
    static const uint32_t CR1_RESET_VALUE = 0x0;

    static constexpr uint32_t CR2_OIS4 = 0x4000;        // Output Idle state 4
    static constexpr uint32_t CR2_OIS3N = 0x2000;       // Output Idle state 3
    static constexpr uint32_t CR2_OIS3 = 0x1000;        // Output Idle state 3
    static constexpr uint32_t CR2_OIS2N = 0x800;        // Output Idle state 2
    static constexpr uint32_t CR2_OIS2 = 0x400;         // Output Idle state 2
    static constexpr uint32_t CR2_OIS1N = 0x200;        // Output Idle state 1
    static constexpr uint32_t CR2_OIS1 = 0x100;         // Output Idle state 1
    static constexpr uint32_t CR2_TI1S = 0x80;          // TI1 selection
    template<uint32_t X>
    static constexpr uint32_t CR2_MMS =                 // Master mode selection (3 bits)
        bit_field_t<4, 0x7>::value<X>();
    static constexpr uint32_t CR2_CCDS = 0x8;           // Capture/compare DMA selection
    static constexpr uint32_t CR2_CCUS = 0x4;           // Capture/compare control update selection
    static constexpr uint32_t CR2_CCPC = 0x1;           // Capture/compare preloaded control
    static const uint32_t CR2_RESET_VALUE = 0x0;

    static constexpr uint32_t SMCR_ETP = 0x8000;         // External trigger polarity
    static constexpr uint32_t SMCR_ECE = 0x4000;         // External clock enable
    template<uint32_t X>
    static constexpr uint32_t SMCR_ETPS =                // External trigger prescaler (2 bits)
        bit_field_t<12, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t SMCR_ETF =                 // External trigger filter (4 bits)
        bit_field_t<8, 0xf>::value<X>();
    static constexpr uint32_t SMCR_MSM = 0x80;           // Master/Slave mode
    template<uint32_t X>
    static constexpr uint32_t SMCR_TS =                  // Trigger selection (3 bits)
        bit_field_t<4, 0x7>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t SMCR_SMS =                 // Slave mode selection (3 bits)
        bit_field_t<0, 0x7>::value<X>();
    static const uint32_t SMCR_RESET_VALUE = 0x0;

    static constexpr uint32_t DIER_TDE = 0x4000;         // Trigger DMA request enable
    static constexpr uint32_t DIER_COMDE = 0x2000;       // COM DMA request enable
    static constexpr uint32_t DIER_CC4DE = 0x1000;       // Capture/Compare 4 DMA request enable
    static constexpr uint32_t DIER_CC3DE = 0x800;        // Capture/Compare 3 DMA request enable
    static constexpr uint32_t DIER_CC2DE = 0x400;        // Capture/Compare 2 DMA request enable
    static constexpr uint32_t DIER_CC1DE = 0x200;        // Capture/Compare 1 DMA request enable
    static constexpr uint32_t DIER_UDE = 0x100;          // Update DMA request enable
    static constexpr uint32_t DIER_BIE = 0x80;           // Break interrupt enable
    static constexpr uint32_t DIER_TIE = 0x40;           // Trigger interrupt enable
    static constexpr uint32_t DIER_COMIE = 0x20;         // COM interrupt enable
    static constexpr uint32_t DIER_CC4IE = 0x10;         // Capture/Compare 4 interrupt enable
    static constexpr uint32_t DIER_CC3IE = 0x8;          // Capture/Compare 3 interrupt enable
    static constexpr uint32_t DIER_CC2IE = 0x4;          // Capture/Compare 2 interrupt enable
    static constexpr uint32_t DIER_CC1IE = 0x2;          // Capture/Compare 1 interrupt enable
    static constexpr uint32_t DIER_UIE = 0x1;            // Update interrupt enable
    static const uint32_t DIER_RESET_VALUE = 0x0;

    static constexpr uint32_t SR_CC4OF = 0x1000;       // Capture/Compare 4 overcapture flag
    static constexpr uint32_t SR_CC3OF = 0x800;        // Capture/Compare 3 overcapture flag
    static constexpr uint32_t SR_CC2OF = 0x400;        // Capture/compare 2 overcapture flag
    static constexpr uint32_t SR_CC1OF = 0x200;        // Capture/Compare 1 overcapture flag
    static constexpr uint32_t SR_BIF = 0x80;           // Break interrupt flag
    static constexpr uint32_t SR_TIF = 0x40;           // Trigger interrupt flag
    static constexpr uint32_t SR_COMIF = 0x20;         // COM interrupt flag
    static constexpr uint32_t SR_CC4IF = 0x10;         // Capture/Compare 4 interrupt flag
    static constexpr uint32_t SR_CC3IF = 0x8;          // Capture/Compare 3 interrupt flag
    static constexpr uint32_t SR_CC2IF = 0x4;          // Capture/Compare 2 interrupt flag
    static constexpr uint32_t SR_CC1IF = 0x2;          // Capture/compare 1 interrupt flag
    static constexpr uint32_t SR_UIF = 0x1;            // Update interrupt flag
    static const uint32_t SR_RESET_VALUE = 0x0;

    static constexpr uint32_t EGR_BG = 0x80;            // Break generation
    static constexpr uint32_t EGR_TG = 0x40;            // Trigger generation
    static constexpr uint32_t EGR_COMG = 0x20;          // Capture/Compare control update generation
    static constexpr uint32_t EGR_CC4G = 0x10;          // Capture/compare 4 generation
    static constexpr uint32_t EGR_CC3G = 0x8;           // Capture/compare 3 generation
    static constexpr uint32_t EGR_CC2G = 0x4;           // Capture/compare 2 generation
    static constexpr uint32_t EGR_CC1G = 0x2;           // Capture/compare 1 generation
    static constexpr uint32_t EGR_UG = 0x1;             // Update generation
    static const uint32_t EGR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t CCMR1_CC1S =                // Capture/Compare 1 selection (2 bits)
        bit_field_t<0, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CCMR1_CC2S =                // Capture/Compare 2 selection (2 bits)
        bit_field_t<8, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CCMR1_IC1F =                // Input capture 1 filter (4 bits)
        bit_field_t<4, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CCMR1_IC2F =                // Input capture 2 filter (4 bits)
        bit_field_t<12, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CCMR1_IC2PCS =              // Input capture 2 prescaler (2 bits)
        bit_field_t<10, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CCMR1_ICPCS =               // Input capture 1 prescaler (2 bits)
        bit_field_t<2, 0x3>::value<X>();
    static constexpr uint32_t CCMR1_OC1CE = 0x80;         // Output Compare 1 clear enable
    static constexpr uint32_t CCMR1_OC1FE = 0x4;          // Output Compare 1 fast enable
    template<uint32_t X>
    static constexpr uint32_t CCMR1_OC1M =                // Output Compare 1 mode (3 bits)
        bit_field_t<4, 0x7>::value<X>();
    static constexpr uint32_t CCMR1_OC1PE = 0x8;          // Output Compare 1 preload enable
    static constexpr uint32_t CCMR1_OC2CE = 0x8000;       // Output Compare 2 clear enable
    static constexpr uint32_t CCMR1_OC2FE = 0x400;        // Output Compare 2 fast enable
    template<uint32_t X>
    static constexpr uint32_t CCMR1_OC2M =                // Output Compare 2 mode (3 bits)
        bit_field_t<12, 0x7>::value<X>();
    static constexpr uint32_t CCMR1_OC2PE = 0x800;        // Output Compare 2 preload enable
    static const uint32_t CCMR1_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t CCMR2_CC3S =                // Capture/Compare 3 selection (2 bits)
        bit_field_t<0, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CCMR2_CC4S =                // Capture/Compare 4 selection (2 bits)
        bit_field_t<8, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CCMR2_IC3F =                // Input capture 3 filter (4 bits)
        bit_field_t<4, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CCMR2_IC3PSC =              // Input capture 3 prescaler (2 bits)
        bit_field_t<2, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CCMR2_IC4F =                // Input capture 4 filter (4 bits)
        bit_field_t<12, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CCMR2_IC4PSC =              // Input capture 4 prescaler (2 bits)
        bit_field_t<10, 0x3>::value<X>();
    static constexpr uint32_t CCMR2_OC3CE = 0x80;         // Output compare 3 clear enable
    static constexpr uint32_t CCMR2_OC3FE = 0x4;          // Output compare 3 fast enable
    template<uint32_t X>
    static constexpr uint32_t CCMR2_OC3M =                // Output compare 3 mode (3 bits)
        bit_field_t<4, 0x7>::value<X>();
    static constexpr uint32_t CCMR2_OC3PE = 0x8;          // Output compare 3 preload enable
    static constexpr uint32_t CCMR2_OC4CE = 0x8000;       // Output compare 4 clear enable
    static constexpr uint32_t CCMR2_OC4FE = 0x400;        // Output compare 4 fast enable
    template<uint32_t X>
    static constexpr uint32_t CCMR2_OC4M =                // Output compare 4 mode (3 bits)
        bit_field_t<12, 0x7>::value<X>();
    static constexpr uint32_t CCMR2_OC4PE = 0x800;        // Output compare 4 preload enable
    static const uint32_t CCMR2_RESET_VALUE = 0x0;

    static constexpr uint32_t CCER_CC4P = 0x2000;        // Capture/Compare 3 output Polarity
    static constexpr uint32_t CCER_CC4E = 0x1000;        // Capture/Compare 4 output enable
    static constexpr uint32_t CCER_CC3NP = 0x800;        // Capture/Compare 3 output Polarity
    static constexpr uint32_t CCER_CC3NE = 0x400;        // Capture/Compare 3 complementary output enable
    static constexpr uint32_t CCER_CC3P = 0x200;         // Capture/Compare 3 output Polarity
    static constexpr uint32_t CCER_CC3E = 0x100;         // Capture/Compare 3 output enable
    static constexpr uint32_t CCER_CC2NP = 0x80;         // Capture/Compare 2 output Polarity
    static constexpr uint32_t CCER_CC2NE = 0x40;         // Capture/Compare 2 complementary output enable
    static constexpr uint32_t CCER_CC2P = 0x20;          // Capture/Compare 2 output Polarity
    static constexpr uint32_t CCER_CC2E = 0x10;          // Capture/Compare 2 output enable
    static constexpr uint32_t CCER_CC1NP = 0x8;          // Capture/Compare 1 output Polarity
    static constexpr uint32_t CCER_CC1NE = 0x4;          // Capture/Compare 1 complementary output enable
    static constexpr uint32_t CCER_CC1P = 0x2;           // Capture/Compare 1 output Polarity
    static constexpr uint32_t CCER_CC1E = 0x1;           // Capture/Compare 1 output enable
    static const uint32_t CCER_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t CNT_CNT =                 // counter value (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t CNT_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t PSC_PSC =                 // Prescaler value (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t PSC_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t ARR_ARR =                 // Auto-reload value (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t ARR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t RCR_REP =                 // Repetition counter value (8 bits)
        bit_field_t<0, 0xff>::value<X>();
    static const uint32_t RCR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t CCR1_CCR1 =                // Capture/Compare 1 value (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t CCR1_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t CCR2_CCR2 =                // Capture/Compare 2 value (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t CCR2_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t CCR3_CCR3 =                // Capture/Compare value (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t CCR3_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t CCR4_CCR4 =                // Capture/Compare value (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t CCR4_RESET_VALUE = 0x0;

    static constexpr uint32_t BDTR_MOE = 0x8000;         // Main output enable
    static constexpr uint32_t BDTR_AOE = 0x4000;         // Automatic output enable
    static constexpr uint32_t BDTR_BKP = 0x2000;         // Break polarity
    static constexpr uint32_t BDTR_BKE = 0x1000;         // Break enable
    static constexpr uint32_t BDTR_OSSR = 0x800;         // Off-state selection for Run mode
    static constexpr uint32_t BDTR_OSSI = 0x400;         // Off-state selection for Idle mode
    template<uint32_t X>
    static constexpr uint32_t BDTR_LOCK =                // Lock configuration (2 bits)
        bit_field_t<8, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t BDTR_DTG =                 // Dead-time generator setup (8 bits)
        bit_field_t<0, 0xff>::value<X>();
    static const uint32_t BDTR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t DCR_DBL =                 // DMA burst length (5 bits)
        bit_field_t<8, 0x1f>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t DCR_DBA =                 // DMA base address (5 bits)
        bit_field_t<0, 0x1f>::value<X>();
    static const uint32_t DCR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t DMAR_DMAB =                // DMA register for burst accesses (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t DMAR_RESET_VALUE = 0x0;
};

static tim1_t& TIM1 = *reinterpret_cast<tim1_t*>(0x40010000);

#define HAVE_PERIPHERAL_TIM1


////
//
//    Advanced-timers
//
////

struct tim8_t
{
    volatile uint32_t    CR1;                  // [Read-write] control register 1
    volatile uint32_t    CR2;                  // [Read-write] control register 2
    volatile uint32_t    SMCR;                 // [Read-write] slave mode control register
    volatile uint32_t    DIER;                 // [Read-write] DMA/Interrupt enable register
    volatile uint32_t    SR;                   // [Read-write] status register
    volatile uint32_t    EGR;                  // [Write-only] event generation register
    volatile uint32_t    CCMR1;                // [Read-write] capture/compare mode register 1 (output mode)
    volatile uint32_t    CCMR2;                // [Read-write] capture/compare mode register 2 (output mode)
    volatile uint32_t    CCER;                 // [Read-write] capture/compare enable register
    volatile uint32_t    CNT;                  // [Read-write] counter
    volatile uint32_t    PSC;                  // [Read-write] prescaler
    volatile uint32_t    ARR;                  // [Read-write] auto-reload register
    volatile uint32_t    RCR;                  // [Read-write] repetition counter register
    volatile uint32_t    CCR1;                 // [Read-write] capture/compare register 1
    volatile uint32_t    CCR2;                 // [Read-write] capture/compare register 2
    volatile uint32_t    CCR3;                 // [Read-write] capture/compare register 3
    volatile uint32_t    CCR4;                 // [Read-write] capture/compare register 4
    volatile uint32_t    BDTR;                 // [Read-write] break and dead-time register
    volatile uint32_t    DCR;                  // [Read-write] DMA control register
    volatile uint32_t    DMAR;                 // [Read-write] DMA address for full transfer

    template<uint32_t X>
    static constexpr uint32_t CR1_CKD =                 // Clock division (2 bits)
        bit_field_t<8, 0x3>::value<X>();
    static constexpr uint32_t CR1_ARPE = 0x80;          // Auto-reload preload enable
    template<uint32_t X>
    static constexpr uint32_t CR1_CMS =                 // Center-aligned mode selection (2 bits)
        bit_field_t<5, 0x3>::value<X>();
    static constexpr uint32_t CR1_DIR = 0x10;           // Direction
    static constexpr uint32_t CR1_OPM = 0x8;            // One-pulse mode
    static constexpr uint32_t CR1_URS = 0x4;            // Update request source
    static constexpr uint32_t CR1_UDIS = 0x2;           // Update disable
    static constexpr uint32_t CR1_CEN = 0x1;            // Counter enable
    static const uint32_t CR1_RESET_VALUE = 0x0;

    static constexpr uint32_t CR2_OIS4 = 0x4000;        // Output Idle state 4
    static constexpr uint32_t CR2_OIS3N = 0x2000;       // Output Idle state 3
    static constexpr uint32_t CR2_OIS3 = 0x1000;        // Output Idle state 3
    static constexpr uint32_t CR2_OIS2N = 0x800;        // Output Idle state 2
    static constexpr uint32_t CR2_OIS2 = 0x400;         // Output Idle state 2
    static constexpr uint32_t CR2_OIS1N = 0x200;        // Output Idle state 1
    static constexpr uint32_t CR2_OIS1 = 0x100;         // Output Idle state 1
    static constexpr uint32_t CR2_TI1S = 0x80;          // TI1 selection
    template<uint32_t X>
    static constexpr uint32_t CR2_MMS =                 // Master mode selection (3 bits)
        bit_field_t<4, 0x7>::value<X>();
    static constexpr uint32_t CR2_CCDS = 0x8;           // Capture/compare DMA selection
    static constexpr uint32_t CR2_CCUS = 0x4;           // Capture/compare control update selection
    static constexpr uint32_t CR2_CCPC = 0x1;           // Capture/compare preloaded control
    static const uint32_t CR2_RESET_VALUE = 0x0;

    static constexpr uint32_t SMCR_ETP = 0x8000;         // External trigger polarity
    static constexpr uint32_t SMCR_ECE = 0x4000;         // External clock enable
    template<uint32_t X>
    static constexpr uint32_t SMCR_ETPS =                // External trigger prescaler (2 bits)
        bit_field_t<12, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t SMCR_ETF =                 // External trigger filter (4 bits)
        bit_field_t<8, 0xf>::value<X>();
    static constexpr uint32_t SMCR_MSM = 0x80;           // Master/Slave mode
    template<uint32_t X>
    static constexpr uint32_t SMCR_TS =                  // Trigger selection (3 bits)
        bit_field_t<4, 0x7>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t SMCR_SMS =                 // Slave mode selection (3 bits)
        bit_field_t<0, 0x7>::value<X>();
    static const uint32_t SMCR_RESET_VALUE = 0x0;

    static constexpr uint32_t DIER_TDE = 0x4000;         // Trigger DMA request enable
    static constexpr uint32_t DIER_COMDE = 0x2000;       // COM DMA request enable
    static constexpr uint32_t DIER_CC4DE = 0x1000;       // Capture/Compare 4 DMA request enable
    static constexpr uint32_t DIER_CC3DE = 0x800;        // Capture/Compare 3 DMA request enable
    static constexpr uint32_t DIER_CC2DE = 0x400;        // Capture/Compare 2 DMA request enable
    static constexpr uint32_t DIER_CC1DE = 0x200;        // Capture/Compare 1 DMA request enable
    static constexpr uint32_t DIER_UDE = 0x100;          // Update DMA request enable
    static constexpr uint32_t DIER_BIE = 0x80;           // Break interrupt enable
    static constexpr uint32_t DIER_TIE = 0x40;           // Trigger interrupt enable
    static constexpr uint32_t DIER_COMIE = 0x20;         // COM interrupt enable
    static constexpr uint32_t DIER_CC4IE = 0x10;         // Capture/Compare 4 interrupt enable
    static constexpr uint32_t DIER_CC3IE = 0x8;          // Capture/Compare 3 interrupt enable
    static constexpr uint32_t DIER_CC2IE = 0x4;          // Capture/Compare 2 interrupt enable
    static constexpr uint32_t DIER_CC1IE = 0x2;          // Capture/Compare 1 interrupt enable
    static constexpr uint32_t DIER_UIE = 0x1;            // Update interrupt enable
    static const uint32_t DIER_RESET_VALUE = 0x0;

    static constexpr uint32_t SR_CC4OF = 0x1000;       // Capture/Compare 4 overcapture flag
    static constexpr uint32_t SR_CC3OF = 0x800;        // Capture/Compare 3 overcapture flag
    static constexpr uint32_t SR_CC2OF = 0x400;        // Capture/compare 2 overcapture flag
    static constexpr uint32_t SR_CC1OF = 0x200;        // Capture/Compare 1 overcapture flag
    static constexpr uint32_t SR_BIF = 0x80;           // Break interrupt flag
    static constexpr uint32_t SR_TIF = 0x40;           // Trigger interrupt flag
    static constexpr uint32_t SR_COMIF = 0x20;         // COM interrupt flag
    static constexpr uint32_t SR_CC4IF = 0x10;         // Capture/Compare 4 interrupt flag
    static constexpr uint32_t SR_CC3IF = 0x8;          // Capture/Compare 3 interrupt flag
    static constexpr uint32_t SR_CC2IF = 0x4;          // Capture/Compare 2 interrupt flag
    static constexpr uint32_t SR_CC1IF = 0x2;          // Capture/compare 1 interrupt flag
    static constexpr uint32_t SR_UIF = 0x1;            // Update interrupt flag
    static const uint32_t SR_RESET_VALUE = 0x0;

    static constexpr uint32_t EGR_BG = 0x80;            // Break generation
    static constexpr uint32_t EGR_TG = 0x40;            // Trigger generation
    static constexpr uint32_t EGR_COMG = 0x20;          // Capture/Compare control update generation
    static constexpr uint32_t EGR_CC4G = 0x10;          // Capture/compare 4 generation
    static constexpr uint32_t EGR_CC3G = 0x8;           // Capture/compare 3 generation
    static constexpr uint32_t EGR_CC2G = 0x4;           // Capture/compare 2 generation
    static constexpr uint32_t EGR_CC1G = 0x2;           // Capture/compare 1 generation
    static constexpr uint32_t EGR_UG = 0x1;             // Update generation
    static const uint32_t EGR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t CCMR1_CC1S =                // Capture/Compare 1 selection (2 bits)
        bit_field_t<0, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CCMR1_CC2S =                // Capture/Compare 2 selection (2 bits)
        bit_field_t<8, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CCMR1_IC1F =                // Input capture 1 filter (4 bits)
        bit_field_t<4, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CCMR1_IC2F =                // Input capture 2 filter (4 bits)
        bit_field_t<12, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CCMR1_IC2PCS =              // Input capture 2 prescaler (2 bits)
        bit_field_t<10, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CCMR1_ICPCS =               // Input capture 1 prescaler (2 bits)
        bit_field_t<2, 0x3>::value<X>();
    static constexpr uint32_t CCMR1_OC1CE = 0x80;         // Output Compare 1 clear enable
    static constexpr uint32_t CCMR1_OC1FE = 0x4;          // Output Compare 1 fast enable
    template<uint32_t X>
    static constexpr uint32_t CCMR1_OC1M =                // Output Compare 1 mode (3 bits)
        bit_field_t<4, 0x7>::value<X>();
    static constexpr uint32_t CCMR1_OC1PE = 0x8;          // Output Compare 1 preload enable
    static constexpr uint32_t CCMR1_OC2CE = 0x8000;       // Output Compare 2 clear enable
    static constexpr uint32_t CCMR1_OC2FE = 0x400;        // Output Compare 2 fast enable
    template<uint32_t X>
    static constexpr uint32_t CCMR1_OC2M =                // Output Compare 2 mode (3 bits)
        bit_field_t<12, 0x7>::value<X>();
    static constexpr uint32_t CCMR1_OC2PE = 0x800;        // Output Compare 2 preload enable
    static const uint32_t CCMR1_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t CCMR2_CC3S =                // Capture/Compare 3 selection (2 bits)
        bit_field_t<0, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CCMR2_CC4S =                // Capture/Compare 4 selection (2 bits)
        bit_field_t<8, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CCMR2_IC3F =                // Input capture 3 filter (4 bits)
        bit_field_t<4, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CCMR2_IC3PSC =              // Input capture 3 prescaler (2 bits)
        bit_field_t<2, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CCMR2_IC4F =                // Input capture 4 filter (4 bits)
        bit_field_t<12, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CCMR2_IC4PSC =              // Input capture 4 prescaler (2 bits)
        bit_field_t<10, 0x3>::value<X>();
    static constexpr uint32_t CCMR2_OC3CE = 0x80;         // Output compare 3 clear enable
    static constexpr uint32_t CCMR2_OC3FE = 0x4;          // Output compare 3 fast enable
    template<uint32_t X>
    static constexpr uint32_t CCMR2_OC3M =                // Output compare 3 mode (3 bits)
        bit_field_t<4, 0x7>::value<X>();
    static constexpr uint32_t CCMR2_OC3PE = 0x8;          // Output compare 3 preload enable
    static constexpr uint32_t CCMR2_OC4CE = 0x8000;       // Output compare 4 clear enable
    static constexpr uint32_t CCMR2_OC4FE = 0x400;        // Output compare 4 fast enable
    template<uint32_t X>
    static constexpr uint32_t CCMR2_OC4M =                // Output compare 4 mode (3 bits)
        bit_field_t<12, 0x7>::value<X>();
    static constexpr uint32_t CCMR2_OC4PE = 0x800;        // Output compare 4 preload enable
    static const uint32_t CCMR2_RESET_VALUE = 0x0;

    static constexpr uint32_t CCER_CC4P = 0x2000;        // Capture/Compare 3 output Polarity
    static constexpr uint32_t CCER_CC4E = 0x1000;        // Capture/Compare 4 output enable
    static constexpr uint32_t CCER_CC3NP = 0x800;        // Capture/Compare 3 output Polarity
    static constexpr uint32_t CCER_CC3NE = 0x400;        // Capture/Compare 3 complementary output enable
    static constexpr uint32_t CCER_CC3P = 0x200;         // Capture/Compare 3 output Polarity
    static constexpr uint32_t CCER_CC3E = 0x100;         // Capture/Compare 3 output enable
    static constexpr uint32_t CCER_CC2NP = 0x80;         // Capture/Compare 2 output Polarity
    static constexpr uint32_t CCER_CC2NE = 0x40;         // Capture/Compare 2 complementary output enable
    static constexpr uint32_t CCER_CC2P = 0x20;          // Capture/Compare 2 output Polarity
    static constexpr uint32_t CCER_CC2E = 0x10;          // Capture/Compare 2 output enable
    static constexpr uint32_t CCER_CC1NP = 0x8;          // Capture/Compare 1 output Polarity
    static constexpr uint32_t CCER_CC1NE = 0x4;          // Capture/Compare 1 complementary output enable
    static constexpr uint32_t CCER_CC1P = 0x2;           // Capture/Compare 1 output Polarity
    static constexpr uint32_t CCER_CC1E = 0x1;           // Capture/Compare 1 output enable
    static const uint32_t CCER_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t CNT_CNT =                 // counter value (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t CNT_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t PSC_PSC =                 // Prescaler value (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t PSC_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t ARR_ARR =                 // Auto-reload value (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t ARR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t RCR_REP =                 // Repetition counter value (8 bits)
        bit_field_t<0, 0xff>::value<X>();
    static const uint32_t RCR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t CCR1_CCR1 =                // Capture/Compare 1 value (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t CCR1_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t CCR2_CCR2 =                // Capture/Compare 2 value (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t CCR2_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t CCR3_CCR3 =                // Capture/Compare value (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t CCR3_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t CCR4_CCR4 =                // Capture/Compare value (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t CCR4_RESET_VALUE = 0x0;

    static constexpr uint32_t BDTR_MOE = 0x8000;         // Main output enable
    static constexpr uint32_t BDTR_AOE = 0x4000;         // Automatic output enable
    static constexpr uint32_t BDTR_BKP = 0x2000;         // Break polarity
    static constexpr uint32_t BDTR_BKE = 0x1000;         // Break enable
    static constexpr uint32_t BDTR_OSSR = 0x800;         // Off-state selection for Run mode
    static constexpr uint32_t BDTR_OSSI = 0x400;         // Off-state selection for Idle mode
    template<uint32_t X>
    static constexpr uint32_t BDTR_LOCK =                // Lock configuration (2 bits)
        bit_field_t<8, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t BDTR_DTG =                 // Dead-time generator setup (8 bits)
        bit_field_t<0, 0xff>::value<X>();
    static const uint32_t BDTR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t DCR_DBL =                 // DMA burst length (5 bits)
        bit_field_t<8, 0x1f>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t DCR_DBA =                 // DMA base address (5 bits)
        bit_field_t<0, 0x1f>::value<X>();
    static const uint32_t DCR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t DMAR_DMAB =                // DMA register for burst accesses (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t DMAR_RESET_VALUE = 0x0;
};

static tim8_t& TIM8 = *reinterpret_cast<tim8_t*>(0x40010400);

#define HAVE_PERIPHERAL_TIM8


////
//
//    General-purpose-timers
//
////

struct tim10_t
{
    volatile uint32_t    CR1;                  // [Read-write] control register 1
    reserved_t<2>        _0;
    volatile uint32_t    DIER;                 // [Read-write] DMA/Interrupt enable register
    volatile uint32_t    SR;                   // [Read-write] status register
    volatile uint32_t    EGR;                  // [Write-only] event generation register
    volatile uint32_t    CCMR1;                // [Read-write] capture/compare mode register 1 (output mode)
    reserved_t<1>        _1;
    volatile uint32_t    CCER;                 // [Read-write] capture/compare enable register
    volatile uint32_t    CNT;                  // [Read-write] counter
    volatile uint32_t    PSC;                  // [Read-write] prescaler
    volatile uint32_t    ARR;                  // [Read-write] auto-reload register
    reserved_t<1>        _2;
    volatile uint32_t    CCR1;                 // [Read-write] capture/compare register 1

    template<uint32_t X>
    static constexpr uint32_t CR1_CKD =                 // Clock division (2 bits)
        bit_field_t<8, 0x3>::value<X>();
    static constexpr uint32_t CR1_ARPE = 0x80;          // Auto-reload preload enable
    static constexpr uint32_t CR1_URS = 0x4;            // Update request source
    static constexpr uint32_t CR1_UDIS = 0x2;           // Update disable
    static constexpr uint32_t CR1_CEN = 0x1;            // Counter enable
    static const uint32_t CR1_RESET_VALUE = 0x0;

    static constexpr uint32_t DIER_CC1IE = 0x2;          // Capture/Compare 1 interrupt enable
    static constexpr uint32_t DIER_UIE = 0x1;            // Update interrupt enable
    static const uint32_t DIER_RESET_VALUE = 0x0;

    static constexpr uint32_t SR_CC1OF = 0x200;        // Capture/Compare 1 overcapture flag
    static constexpr uint32_t SR_CC1IF = 0x2;          // Capture/compare 1 interrupt flag
    static constexpr uint32_t SR_UIF = 0x1;            // Update interrupt flag
    static const uint32_t SR_RESET_VALUE = 0x0;

    static constexpr uint32_t EGR_CC1G = 0x2;           // Capture/compare 1 generation
    static constexpr uint32_t EGR_UG = 0x1;             // Update generation
    static const uint32_t EGR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t CCMR1_CC1S =                // Capture/Compare 1 selection (2 bits)
        bit_field_t<0, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CCMR1_IC1F =                // Input capture 1 filter (4 bits)
        bit_field_t<4, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CCMR1_ICPCS =               // Input capture 1 prescaler (2 bits)
        bit_field_t<2, 0x3>::value<X>();
    static constexpr uint32_t CCMR1_OC1FE = 0x4;          // Output Compare 1 fast enable
    template<uint32_t X>
    static constexpr uint32_t CCMR1_OC1M =                // Output Compare 1 mode (3 bits)
        bit_field_t<4, 0x7>::value<X>();
    static constexpr uint32_t CCMR1_OC1PE = 0x8;          // Output Compare 1 preload enable
    static const uint32_t CCMR1_RESET_VALUE = 0x0;

    static constexpr uint32_t CCER_CC1NP = 0x8;          // Capture/Compare 1 output Polarity
    static constexpr uint32_t CCER_CC1P = 0x2;           // Capture/Compare 1 output Polarity
    static constexpr uint32_t CCER_CC1E = 0x1;           // Capture/Compare 1 output enable
    static const uint32_t CCER_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t CNT_CNT =                 // counter value (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t CNT_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t PSC_PSC =                 // Prescaler value (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t PSC_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t ARR_ARR =                 // Auto-reload value (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t ARR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t CCR1_CCR1 =                // Capture/Compare 1 value (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t CCR1_RESET_VALUE = 0x0;

    static constexpr uint8_t SPI1 = 35; // SPI1 global interrupt
};

static tim10_t& TIM10 = *reinterpret_cast<tim10_t*>(0x40014400);

#define HAVE_PERIPHERAL_TIM10


////
//
//    General-purpose-timers
//
////

struct tim11_t
{
    volatile uint32_t    CR1;                  // [Read-write] control register 1
    reserved_t<2>        _0;
    volatile uint32_t    DIER;                 // [Read-write] DMA/Interrupt enable register
    volatile uint32_t    SR;                   // [Read-write] status register
    volatile uint32_t    EGR;                  // [Write-only] event generation register
    volatile uint32_t    CCMR1;                // [Read-write] capture/compare mode register 1 (output mode)
    reserved_t<1>        _1;
    volatile uint32_t    CCER;                 // [Read-write] capture/compare enable register
    volatile uint32_t    CNT;                  // [Read-write] counter
    volatile uint32_t    PSC;                  // [Read-write] prescaler
    volatile uint32_t    ARR;                  // [Read-write] auto-reload register
    reserved_t<1>        _2;
    volatile uint32_t    CCR1;                 // [Read-write] capture/compare register 1
    reserved_t<6>        _3;
    volatile uint32_t    OR;                   // [Read-write] option register

    template<uint32_t X>
    static constexpr uint32_t CR1_CKD =                 // Clock division (2 bits)
        bit_field_t<8, 0x3>::value<X>();
    static constexpr uint32_t CR1_ARPE = 0x80;          // Auto-reload preload enable
    static constexpr uint32_t CR1_URS = 0x4;            // Update request source
    static constexpr uint32_t CR1_UDIS = 0x2;           // Update disable
    static constexpr uint32_t CR1_CEN = 0x1;            // Counter enable
    static const uint32_t CR1_RESET_VALUE = 0x0;

    static constexpr uint32_t DIER_CC1IE = 0x2;          // Capture/Compare 1 interrupt enable
    static constexpr uint32_t DIER_UIE = 0x1;            // Update interrupt enable
    static const uint32_t DIER_RESET_VALUE = 0x0;

    static constexpr uint32_t SR_CC1OF = 0x200;        // Capture/Compare 1 overcapture flag
    static constexpr uint32_t SR_CC1IF = 0x2;          // Capture/compare 1 interrupt flag
    static constexpr uint32_t SR_UIF = 0x1;            // Update interrupt flag
    static const uint32_t SR_RESET_VALUE = 0x0;

    static constexpr uint32_t EGR_CC1G = 0x2;           // Capture/compare 1 generation
    static constexpr uint32_t EGR_UG = 0x1;             // Update generation
    static const uint32_t EGR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t CCMR1_CC1S =                // Capture/Compare 1 selection (2 bits)
        bit_field_t<0, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CCMR1_IC1F =                // Input capture 1 filter (4 bits)
        bit_field_t<4, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CCMR1_ICPCS =               // Input capture 1 prescaler (2 bits)
        bit_field_t<2, 0x3>::value<X>();
    static constexpr uint32_t CCMR1_OC1FE = 0x4;          // Output Compare 1 fast enable
    template<uint32_t X>
    static constexpr uint32_t CCMR1_OC1M =                // Output Compare 1 mode (3 bits)
        bit_field_t<4, 0x7>::value<X>();
    static constexpr uint32_t CCMR1_OC1PE = 0x8;          // Output Compare 1 preload enable
    static const uint32_t CCMR1_RESET_VALUE = 0x0;

    static constexpr uint32_t CCER_CC1NP = 0x8;          // Capture/Compare 1 output Polarity
    static constexpr uint32_t CCER_CC1P = 0x2;           // Capture/Compare 1 output Polarity
    static constexpr uint32_t CCER_CC1E = 0x1;           // Capture/Compare 1 output enable
    static const uint32_t CCER_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t CNT_CNT =                 // counter value (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t CNT_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t PSC_PSC =                 // Prescaler value (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t PSC_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t ARR_ARR =                 // Auto-reload value (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t ARR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t CCR1_CCR1 =                // Capture/Compare 1 value (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t CCR1_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t OR_RMP =                 // Input 1 remapping capability (2 bits)
        bit_field_t<0, 0x3>::value<X>();
    static const uint32_t OR_RESET_VALUE = 0x0;

    static constexpr uint8_t SPI2 = 36; // SPI2 global interrupt
};

static tim11_t& TIM11 = *reinterpret_cast<tim11_t*>(0x40014800);

#define HAVE_PERIPHERAL_TIM11


////
//
//    General purpose timers
//
////

struct tim2_t
{
    volatile uint32_t    CR1;                  // [Read-write] control register 1
    volatile uint32_t    CR2;                  // [Read-write] control register 2
    volatile uint32_t    SMCR;                 // [Read-write] slave mode control register
    volatile uint32_t    DIER;                 // [Read-write] DMA/Interrupt enable register
    volatile uint32_t    SR;                   // [Read-write] status register
    volatile uint32_t    EGR;                  // [Write-only] event generation register
    volatile uint32_t    CCMR1;                // [Read-write] capture/compare mode register 1 (output mode)
    volatile uint32_t    CCMR2;                // [Read-write] capture/compare mode register 2 (output mode)
    volatile uint32_t    CCER;                 // [Read-write] capture/compare enable register
    volatile uint32_t    CNT;                  // [Read-write] counter
    volatile uint32_t    PSC;                  // [Read-write] prescaler
    volatile uint32_t    ARR;                  // [Read-write] auto-reload register
    reserved_t<1>        _0;
    volatile uint32_t    CCR1;                 // [Read-write] capture/compare register 1
    volatile uint32_t    CCR2;                 // [Read-write] capture/compare register 2
    volatile uint32_t    CCR3;                 // [Read-write] capture/compare register 3
    volatile uint32_t    CCR4;                 // [Read-write] capture/compare register 4
    reserved_t<1>        _1;
    volatile uint32_t    DCR;                  // [Read-write] DMA control register
    volatile uint32_t    DMAR;                 // [Read-write] DMA address for full transfer
    volatile uint32_t    OR;                   // [Read-write] TIM5 option register

    template<uint32_t X>
    static constexpr uint32_t CR1_CKD =                 // Clock division (2 bits)
        bit_field_t<8, 0x3>::value<X>();
    static constexpr uint32_t CR1_ARPE = 0x80;          // Auto-reload preload enable
    template<uint32_t X>
    static constexpr uint32_t CR1_CMS =                 // Center-aligned mode selection (2 bits)
        bit_field_t<5, 0x3>::value<X>();
    static constexpr uint32_t CR1_DIR = 0x10;           // Direction
    static constexpr uint32_t CR1_OPM = 0x8;            // One-pulse mode
    static constexpr uint32_t CR1_URS = 0x4;            // Update request source
    static constexpr uint32_t CR1_UDIS = 0x2;           // Update disable
    static constexpr uint32_t CR1_CEN = 0x1;            // Counter enable
    static const uint32_t CR1_RESET_VALUE = 0x0;

    static constexpr uint32_t CR2_TI1S = 0x80;          // TI1 selection
    template<uint32_t X>
    static constexpr uint32_t CR2_MMS =                 // Master mode selection (3 bits)
        bit_field_t<4, 0x7>::value<X>();
    static constexpr uint32_t CR2_CCDS = 0x8;           // Capture/compare DMA selection
    static const uint32_t CR2_RESET_VALUE = 0x0;

    static constexpr uint32_t SMCR_ETP = 0x8000;         // External trigger polarity
    static constexpr uint32_t SMCR_ECE = 0x4000;         // External clock enable
    template<uint32_t X>
    static constexpr uint32_t SMCR_ETPS =                // External trigger prescaler (2 bits)
        bit_field_t<12, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t SMCR_ETF =                 // External trigger filter (4 bits)
        bit_field_t<8, 0xf>::value<X>();
    static constexpr uint32_t SMCR_MSM = 0x80;           // Master/Slave mode
    template<uint32_t X>
    static constexpr uint32_t SMCR_TS =                  // Trigger selection (3 bits)
        bit_field_t<4, 0x7>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t SMCR_SMS =                 // Slave mode selection (3 bits)
        bit_field_t<0, 0x7>::value<X>();
    static const uint32_t SMCR_RESET_VALUE = 0x0;

    static constexpr uint32_t DIER_TDE = 0x4000;         // Trigger DMA request enable
    static constexpr uint32_t DIER_CC4DE = 0x1000;       // Capture/Compare 4 DMA request enable
    static constexpr uint32_t DIER_CC3DE = 0x800;        // Capture/Compare 3 DMA request enable
    static constexpr uint32_t DIER_CC2DE = 0x400;        // Capture/Compare 2 DMA request enable
    static constexpr uint32_t DIER_CC1DE = 0x200;        // Capture/Compare 1 DMA request enable
    static constexpr uint32_t DIER_UDE = 0x100;          // Update DMA request enable
    static constexpr uint32_t DIER_TIE = 0x40;           // Trigger interrupt enable
    static constexpr uint32_t DIER_CC4IE = 0x10;         // Capture/Compare 4 interrupt enable
    static constexpr uint32_t DIER_CC3IE = 0x8;          // Capture/Compare 3 interrupt enable
    static constexpr uint32_t DIER_CC2IE = 0x4;          // Capture/Compare 2 interrupt enable
    static constexpr uint32_t DIER_CC1IE = 0x2;          // Capture/Compare 1 interrupt enable
    static constexpr uint32_t DIER_UIE = 0x1;            // Update interrupt enable
    static const uint32_t DIER_RESET_VALUE = 0x0;

    static constexpr uint32_t SR_CC4OF = 0x1000;       // Capture/Compare 4 overcapture flag
    static constexpr uint32_t SR_CC3OF = 0x800;        // Capture/Compare 3 overcapture flag
    static constexpr uint32_t SR_CC2OF = 0x400;        // Capture/compare 2 overcapture flag
    static constexpr uint32_t SR_CC1OF = 0x200;        // Capture/Compare 1 overcapture flag
    static constexpr uint32_t SR_TIF = 0x40;           // Trigger interrupt flag
    static constexpr uint32_t SR_CC4IF = 0x10;         // Capture/Compare 4 interrupt flag
    static constexpr uint32_t SR_CC3IF = 0x8;          // Capture/Compare 3 interrupt flag
    static constexpr uint32_t SR_CC2IF = 0x4;          // Capture/Compare 2 interrupt flag
    static constexpr uint32_t SR_CC1IF = 0x2;          // Capture/compare 1 interrupt flag
    static constexpr uint32_t SR_UIF = 0x1;            // Update interrupt flag
    static const uint32_t SR_RESET_VALUE = 0x0;

    static constexpr uint32_t EGR_TG = 0x40;            // Trigger generation
    static constexpr uint32_t EGR_CC4G = 0x10;          // Capture/compare 4 generation
    static constexpr uint32_t EGR_CC3G = 0x8;           // Capture/compare 3 generation
    static constexpr uint32_t EGR_CC2G = 0x4;           // Capture/compare 2 generation
    static constexpr uint32_t EGR_CC1G = 0x2;           // Capture/compare 1 generation
    static constexpr uint32_t EGR_UG = 0x1;             // Update generation
    static const uint32_t EGR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t CCMR1_CC1S =                // CC1S (2 bits)
        bit_field_t<0, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CCMR1_CC2S =                // CC2S (2 bits)
        bit_field_t<8, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CCMR1_IC1F =                // Input capture 1 filter (4 bits)
        bit_field_t<4, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CCMR1_IC2F =                // Input capture 2 filter (4 bits)
        bit_field_t<12, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CCMR1_IC2PCS =              // Input capture 2 prescaler (2 bits)
        bit_field_t<10, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CCMR1_ICPCS =               // Input capture 1 prescaler (2 bits)
        bit_field_t<2, 0x3>::value<X>();
    static constexpr uint32_t CCMR1_OC1CE = 0x80;         // OC1CE
    static constexpr uint32_t CCMR1_OC1FE = 0x4;          // OC1FE
    template<uint32_t X>
    static constexpr uint32_t CCMR1_OC1M =                // OC1M (3 bits)
        bit_field_t<4, 0x7>::value<X>();
    static constexpr uint32_t CCMR1_OC1PE = 0x8;          // OC1PE
    static constexpr uint32_t CCMR1_OC2CE = 0x8000;       // OC2CE
    static constexpr uint32_t CCMR1_OC2FE = 0x400;        // OC2FE
    template<uint32_t X>
    static constexpr uint32_t CCMR1_OC2M =                // OC2M (3 bits)
        bit_field_t<12, 0x7>::value<X>();
    static constexpr uint32_t CCMR1_OC2PE = 0x800;        // OC2PE
    static const uint32_t CCMR1_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t CCMR2_CC3S =                // CC3S (2 bits)
        bit_field_t<0, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CCMR2_CC4S =                // CC4S (2 bits)
        bit_field_t<8, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CCMR2_IC3F =                // Input capture 3 filter (4 bits)
        bit_field_t<4, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CCMR2_IC3PSC =              // Input capture 3 prescaler (2 bits)
        bit_field_t<2, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CCMR2_IC4F =                // Input capture 4 filter (4 bits)
        bit_field_t<12, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CCMR2_IC4PSC =              // Input capture 4 prescaler (2 bits)
        bit_field_t<10, 0x3>::value<X>();
    static constexpr uint32_t CCMR2_O24CE = 0x8000;       // O24CE
    static constexpr uint32_t CCMR2_OC3CE = 0x80;         // OC3CE
    static constexpr uint32_t CCMR2_OC3FE = 0x4;          // OC3FE
    template<uint32_t X>
    static constexpr uint32_t CCMR2_OC3M =                // OC3M (3 bits)
        bit_field_t<4, 0x7>::value<X>();
    static constexpr uint32_t CCMR2_OC3PE = 0x8;          // OC3PE
    static constexpr uint32_t CCMR2_OC4FE = 0x400;        // OC4FE
    template<uint32_t X>
    static constexpr uint32_t CCMR2_OC4M =                // OC4M (3 bits)
        bit_field_t<12, 0x7>::value<X>();
    static constexpr uint32_t CCMR2_OC4PE = 0x800;        // OC4PE
    static const uint32_t CCMR2_RESET_VALUE = 0x0;

    static constexpr uint32_t CCER_CC4NP = 0x8000;       // Capture/Compare 4 output Polarity
    static constexpr uint32_t CCER_CC4P = 0x2000;        // Capture/Compare 3 output Polarity
    static constexpr uint32_t CCER_CC4E = 0x1000;        // Capture/Compare 4 output enable
    static constexpr uint32_t CCER_CC3NP = 0x800;        // Capture/Compare 3 output Polarity
    static constexpr uint32_t CCER_CC3P = 0x200;         // Capture/Compare 3 output Polarity
    static constexpr uint32_t CCER_CC3E = 0x100;         // Capture/Compare 3 output enable
    static constexpr uint32_t CCER_CC2NP = 0x80;         // Capture/Compare 2 output Polarity
    static constexpr uint32_t CCER_CC2P = 0x20;          // Capture/Compare 2 output Polarity
    static constexpr uint32_t CCER_CC2E = 0x10;          // Capture/Compare 2 output enable
    static constexpr uint32_t CCER_CC1NP = 0x8;          // Capture/Compare 1 output Polarity
    static constexpr uint32_t CCER_CC1P = 0x2;           // Capture/Compare 1 output Polarity
    static constexpr uint32_t CCER_CC1E = 0x1;           // Capture/Compare 1 output enable
    static const uint32_t CCER_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t CNT_CNT_H =               // High counter value (16 bits)
        bit_field_t<16, 0xffff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CNT_CNT_L =               // Low counter value (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t CNT_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t PSC_PSC =                 // Prescaler value (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t PSC_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t ARR_ARR_H =               // High Auto-reload value (16 bits)
        bit_field_t<16, 0xffff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t ARR_ARR_L =               // Low Auto-reload value (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t ARR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t CCR1_CCR1_H =              // High Capture/Compare 1 value (16 bits)
        bit_field_t<16, 0xffff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CCR1_CCR1_L =              // Low Capture/Compare 1 value (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t CCR1_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t CCR2_CCR2_H =              // High Capture/Compare 2 value (16 bits)
        bit_field_t<16, 0xffff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CCR2_CCR2_L =              // Low Capture/Compare 2 value (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t CCR2_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t CCR3_CCR3_H =              // High Capture/Compare value (16 bits)
        bit_field_t<16, 0xffff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CCR3_CCR3_L =              // Low Capture/Compare value (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t CCR3_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t CCR4_CCR4_H =              // High Capture/Compare value (16 bits)
        bit_field_t<16, 0xffff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CCR4_CCR4_L =              // Low Capture/Compare value (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t CCR4_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t DCR_DBL =                 // DMA burst length (5 bits)
        bit_field_t<8, 0x1f>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t DCR_DBA =                 // DMA base address (5 bits)
        bit_field_t<0, 0x1f>::value<X>();
    static const uint32_t DCR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t DMAR_DMAB =                // DMA register for burst accesses (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t DMAR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t OR_ITR1_RMP =            // Timer Input 4 remap (2 bits)
        bit_field_t<10, 0x3>::value<X>();
    static const uint32_t OR_RESET_VALUE = 0x0;

    static constexpr uint8_t SPI3 = 51; // SPI3 global interrupt
};

static tim2_t& TIM2 = *reinterpret_cast<tim2_t*>(0x40000000);

#define HAVE_PERIPHERAL_TIM2


////
//
//    General purpose timers
//
////

struct tim3_t
{
    volatile uint32_t    CR1;                  // [Read-write] control register 1
    volatile uint32_t    CR2;                  // [Read-write] control register 2
    volatile uint32_t    SMCR;                 // [Read-write] slave mode control register
    volatile uint32_t    DIER;                 // [Read-write] DMA/Interrupt enable register
    volatile uint32_t    SR;                   // [Read-write] status register
    volatile uint32_t    EGR;                  // [Write-only] event generation register
    volatile uint32_t    CCMR1;                // [Read-write] capture/compare mode register 1 (output mode)
    volatile uint32_t    CCMR2;                // [Read-write] capture/compare mode register 2 (output mode)
    volatile uint32_t    CCER;                 // [Read-write] capture/compare enable register
    volatile uint32_t    CNT;                  // [Read-write] counter
    volatile uint32_t    PSC;                  // [Read-write] prescaler
    volatile uint32_t    ARR;                  // [Read-write] auto-reload register
    reserved_t<1>        _0;
    volatile uint32_t    CCR1;                 // [Read-write] capture/compare register 1
    volatile uint32_t    CCR2;                 // [Read-write] capture/compare register 2
    volatile uint32_t    CCR3;                 // [Read-write] capture/compare register 3
    volatile uint32_t    CCR4;                 // [Read-write] capture/compare register 4
    reserved_t<1>        _1;
    volatile uint32_t    DCR;                  // [Read-write] DMA control register
    volatile uint32_t    DMAR;                 // [Read-write] DMA address for full transfer

    template<uint32_t X>
    static constexpr uint32_t CR1_CKD =                 // Clock division (2 bits)
        bit_field_t<8, 0x3>::value<X>();
    static constexpr uint32_t CR1_ARPE = 0x80;          // Auto-reload preload enable
    template<uint32_t X>
    static constexpr uint32_t CR1_CMS =                 // Center-aligned mode selection (2 bits)
        bit_field_t<5, 0x3>::value<X>();
    static constexpr uint32_t CR1_DIR = 0x10;           // Direction
    static constexpr uint32_t CR1_OPM = 0x8;            // One-pulse mode
    static constexpr uint32_t CR1_URS = 0x4;            // Update request source
    static constexpr uint32_t CR1_UDIS = 0x2;           // Update disable
    static constexpr uint32_t CR1_CEN = 0x1;            // Counter enable
    static const uint32_t CR1_RESET_VALUE = 0x0;

    static constexpr uint32_t CR2_TI1S = 0x80;          // TI1 selection
    template<uint32_t X>
    static constexpr uint32_t CR2_MMS =                 // Master mode selection (3 bits)
        bit_field_t<4, 0x7>::value<X>();
    static constexpr uint32_t CR2_CCDS = 0x8;           // Capture/compare DMA selection
    static const uint32_t CR2_RESET_VALUE = 0x0;

    static constexpr uint32_t SMCR_ETP = 0x8000;         // External trigger polarity
    static constexpr uint32_t SMCR_ECE = 0x4000;         // External clock enable
    template<uint32_t X>
    static constexpr uint32_t SMCR_ETPS =                // External trigger prescaler (2 bits)
        bit_field_t<12, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t SMCR_ETF =                 // External trigger filter (4 bits)
        bit_field_t<8, 0xf>::value<X>();
    static constexpr uint32_t SMCR_MSM = 0x80;           // Master/Slave mode
    template<uint32_t X>
    static constexpr uint32_t SMCR_TS =                  // Trigger selection (3 bits)
        bit_field_t<4, 0x7>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t SMCR_SMS =                 // Slave mode selection (3 bits)
        bit_field_t<0, 0x7>::value<X>();
    static const uint32_t SMCR_RESET_VALUE = 0x0;

    static constexpr uint32_t DIER_TDE = 0x4000;         // Trigger DMA request enable
    static constexpr uint32_t DIER_CC4DE = 0x1000;       // Capture/Compare 4 DMA request enable
    static constexpr uint32_t DIER_CC3DE = 0x800;        // Capture/Compare 3 DMA request enable
    static constexpr uint32_t DIER_CC2DE = 0x400;        // Capture/Compare 2 DMA request enable
    static constexpr uint32_t DIER_CC1DE = 0x200;        // Capture/Compare 1 DMA request enable
    static constexpr uint32_t DIER_UDE = 0x100;          // Update DMA request enable
    static constexpr uint32_t DIER_TIE = 0x40;           // Trigger interrupt enable
    static constexpr uint32_t DIER_CC4IE = 0x10;         // Capture/Compare 4 interrupt enable
    static constexpr uint32_t DIER_CC3IE = 0x8;          // Capture/Compare 3 interrupt enable
    static constexpr uint32_t DIER_CC2IE = 0x4;          // Capture/Compare 2 interrupt enable
    static constexpr uint32_t DIER_CC1IE = 0x2;          // Capture/Compare 1 interrupt enable
    static constexpr uint32_t DIER_UIE = 0x1;            // Update interrupt enable
    static const uint32_t DIER_RESET_VALUE = 0x0;

    static constexpr uint32_t SR_CC4OF = 0x1000;       // Capture/Compare 4 overcapture flag
    static constexpr uint32_t SR_CC3OF = 0x800;        // Capture/Compare 3 overcapture flag
    static constexpr uint32_t SR_CC2OF = 0x400;        // Capture/compare 2 overcapture flag
    static constexpr uint32_t SR_CC1OF = 0x200;        // Capture/Compare 1 overcapture flag
    static constexpr uint32_t SR_TIF = 0x40;           // Trigger interrupt flag
    static constexpr uint32_t SR_CC4IF = 0x10;         // Capture/Compare 4 interrupt flag
    static constexpr uint32_t SR_CC3IF = 0x8;          // Capture/Compare 3 interrupt flag
    static constexpr uint32_t SR_CC2IF = 0x4;          // Capture/Compare 2 interrupt flag
    static constexpr uint32_t SR_CC1IF = 0x2;          // Capture/compare 1 interrupt flag
    static constexpr uint32_t SR_UIF = 0x1;            // Update interrupt flag
    static const uint32_t SR_RESET_VALUE = 0x0;

    static constexpr uint32_t EGR_TG = 0x40;            // Trigger generation
    static constexpr uint32_t EGR_CC4G = 0x10;          // Capture/compare 4 generation
    static constexpr uint32_t EGR_CC3G = 0x8;           // Capture/compare 3 generation
    static constexpr uint32_t EGR_CC2G = 0x4;           // Capture/compare 2 generation
    static constexpr uint32_t EGR_CC1G = 0x2;           // Capture/compare 1 generation
    static constexpr uint32_t EGR_UG = 0x1;             // Update generation
    static const uint32_t EGR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t CCMR1_CC1S =                // CC1S (2 bits)
        bit_field_t<0, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CCMR1_CC2S =                // CC2S (2 bits)
        bit_field_t<8, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CCMR1_IC1F =                // Input capture 1 filter (4 bits)
        bit_field_t<4, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CCMR1_IC2F =                // Input capture 2 filter (4 bits)
        bit_field_t<12, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CCMR1_IC2PCS =              // Input capture 2 prescaler (2 bits)
        bit_field_t<10, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CCMR1_ICPCS =               // Input capture 1 prescaler (2 bits)
        bit_field_t<2, 0x3>::value<X>();
    static constexpr uint32_t CCMR1_OC1CE = 0x80;         // OC1CE
    static constexpr uint32_t CCMR1_OC1FE = 0x4;          // OC1FE
    template<uint32_t X>
    static constexpr uint32_t CCMR1_OC1M =                // OC1M (3 bits)
        bit_field_t<4, 0x7>::value<X>();
    static constexpr uint32_t CCMR1_OC1PE = 0x8;          // OC1PE
    static constexpr uint32_t CCMR1_OC2CE = 0x8000;       // OC2CE
    static constexpr uint32_t CCMR1_OC2FE = 0x400;        // OC2FE
    template<uint32_t X>
    static constexpr uint32_t CCMR1_OC2M =                // OC2M (3 bits)
        bit_field_t<12, 0x7>::value<X>();
    static constexpr uint32_t CCMR1_OC2PE = 0x800;        // OC2PE
    static const uint32_t CCMR1_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t CCMR2_CC3S =                // CC3S (2 bits)
        bit_field_t<0, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CCMR2_CC4S =                // CC4S (2 bits)
        bit_field_t<8, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CCMR2_IC3F =                // Input capture 3 filter (4 bits)
        bit_field_t<4, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CCMR2_IC3PSC =              // Input capture 3 prescaler (2 bits)
        bit_field_t<2, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CCMR2_IC4F =                // Input capture 4 filter (4 bits)
        bit_field_t<12, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CCMR2_IC4PSC =              // Input capture 4 prescaler (2 bits)
        bit_field_t<10, 0x3>::value<X>();
    static constexpr uint32_t CCMR2_O24CE = 0x8000;       // O24CE
    static constexpr uint32_t CCMR2_OC3CE = 0x80;         // OC3CE
    static constexpr uint32_t CCMR2_OC3FE = 0x4;          // OC3FE
    template<uint32_t X>
    static constexpr uint32_t CCMR2_OC3M =                // OC3M (3 bits)
        bit_field_t<4, 0x7>::value<X>();
    static constexpr uint32_t CCMR2_OC3PE = 0x8;          // OC3PE
    static constexpr uint32_t CCMR2_OC4FE = 0x400;        // OC4FE
    template<uint32_t X>
    static constexpr uint32_t CCMR2_OC4M =                // OC4M (3 bits)
        bit_field_t<12, 0x7>::value<X>();
    static constexpr uint32_t CCMR2_OC4PE = 0x800;        // OC4PE
    static const uint32_t CCMR2_RESET_VALUE = 0x0;

    static constexpr uint32_t CCER_CC4NP = 0x8000;       // Capture/Compare 4 output Polarity
    static constexpr uint32_t CCER_CC4P = 0x2000;        // Capture/Compare 3 output Polarity
    static constexpr uint32_t CCER_CC4E = 0x1000;        // Capture/Compare 4 output enable
    static constexpr uint32_t CCER_CC3NP = 0x800;        // Capture/Compare 3 output Polarity
    static constexpr uint32_t CCER_CC3P = 0x200;         // Capture/Compare 3 output Polarity
    static constexpr uint32_t CCER_CC3E = 0x100;         // Capture/Compare 3 output enable
    static constexpr uint32_t CCER_CC2NP = 0x80;         // Capture/Compare 2 output Polarity
    static constexpr uint32_t CCER_CC2P = 0x20;          // Capture/Compare 2 output Polarity
    static constexpr uint32_t CCER_CC2E = 0x10;          // Capture/Compare 2 output enable
    static constexpr uint32_t CCER_CC1NP = 0x8;          // Capture/Compare 1 output Polarity
    static constexpr uint32_t CCER_CC1P = 0x2;           // Capture/Compare 1 output Polarity
    static constexpr uint32_t CCER_CC1E = 0x1;           // Capture/Compare 1 output enable
    static const uint32_t CCER_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t CNT_CNT_H =               // High counter value (16 bits)
        bit_field_t<16, 0xffff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CNT_CNT_L =               // Low counter value (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t CNT_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t PSC_PSC =                 // Prescaler value (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t PSC_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t ARR_ARR_H =               // High Auto-reload value (16 bits)
        bit_field_t<16, 0xffff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t ARR_ARR_L =               // Low Auto-reload value (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t ARR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t CCR1_CCR1_H =              // High Capture/Compare 1 value (16 bits)
        bit_field_t<16, 0xffff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CCR1_CCR1_L =              // Low Capture/Compare 1 value (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t CCR1_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t CCR2_CCR2_H =              // High Capture/Compare 2 value (16 bits)
        bit_field_t<16, 0xffff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CCR2_CCR2_L =              // Low Capture/Compare 2 value (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t CCR2_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t CCR3_CCR3_H =              // High Capture/Compare value (16 bits)
        bit_field_t<16, 0xffff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CCR3_CCR3_L =              // Low Capture/Compare value (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t CCR3_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t CCR4_CCR4_H =              // High Capture/Compare value (16 bits)
        bit_field_t<16, 0xffff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CCR4_CCR4_L =              // Low Capture/Compare value (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t CCR4_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t DCR_DBL =                 // DMA burst length (5 bits)
        bit_field_t<8, 0x1f>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t DCR_DBA =                 // DMA base address (5 bits)
        bit_field_t<0, 0x1f>::value<X>();
    static const uint32_t DCR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t DMAR_DMAB =                // DMA register for burst accesses (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t DMAR_RESET_VALUE = 0x0;

    static constexpr uint8_t SPI4 = 84; // SPI4 global interrupt
};

static tim3_t& TIM3 = *reinterpret_cast<tim3_t*>(0x40000400);

#define HAVE_PERIPHERAL_TIM3


////
//
//    General purpose timers
//
////

struct tim4_t
{
    volatile uint32_t    CR1;                  // [Read-write] control register 1
    volatile uint32_t    CR2;                  // [Read-write] control register 2
    volatile uint32_t    SMCR;                 // [Read-write] slave mode control register
    volatile uint32_t    DIER;                 // [Read-write] DMA/Interrupt enable register
    volatile uint32_t    SR;                   // [Read-write] status register
    volatile uint32_t    EGR;                  // [Write-only] event generation register
    volatile uint32_t    CCMR1;                // [Read-write] capture/compare mode register 1 (output mode)
    volatile uint32_t    CCMR2;                // [Read-write] capture/compare mode register 2 (output mode)
    volatile uint32_t    CCER;                 // [Read-write] capture/compare enable register
    volatile uint32_t    CNT;                  // [Read-write] counter
    volatile uint32_t    PSC;                  // [Read-write] prescaler
    volatile uint32_t    ARR;                  // [Read-write] auto-reload register
    reserved_t<1>        _0;
    volatile uint32_t    CCR1;                 // [Read-write] capture/compare register 1
    volatile uint32_t    CCR2;                 // [Read-write] capture/compare register 2
    volatile uint32_t    CCR3;                 // [Read-write] capture/compare register 3
    volatile uint32_t    CCR4;                 // [Read-write] capture/compare register 4
    reserved_t<1>        _1;
    volatile uint32_t    DCR;                  // [Read-write] DMA control register
    volatile uint32_t    DMAR;                 // [Read-write] DMA address for full transfer

    template<uint32_t X>
    static constexpr uint32_t CR1_CKD =                 // Clock division (2 bits)
        bit_field_t<8, 0x3>::value<X>();
    static constexpr uint32_t CR1_ARPE = 0x80;          // Auto-reload preload enable
    template<uint32_t X>
    static constexpr uint32_t CR1_CMS =                 // Center-aligned mode selection (2 bits)
        bit_field_t<5, 0x3>::value<X>();
    static constexpr uint32_t CR1_DIR = 0x10;           // Direction
    static constexpr uint32_t CR1_OPM = 0x8;            // One-pulse mode
    static constexpr uint32_t CR1_URS = 0x4;            // Update request source
    static constexpr uint32_t CR1_UDIS = 0x2;           // Update disable
    static constexpr uint32_t CR1_CEN = 0x1;            // Counter enable
    static const uint32_t CR1_RESET_VALUE = 0x0;

    static constexpr uint32_t CR2_TI1S = 0x80;          // TI1 selection
    template<uint32_t X>
    static constexpr uint32_t CR2_MMS =                 // Master mode selection (3 bits)
        bit_field_t<4, 0x7>::value<X>();
    static constexpr uint32_t CR2_CCDS = 0x8;           // Capture/compare DMA selection
    static const uint32_t CR2_RESET_VALUE = 0x0;

    static constexpr uint32_t SMCR_ETP = 0x8000;         // External trigger polarity
    static constexpr uint32_t SMCR_ECE = 0x4000;         // External clock enable
    template<uint32_t X>
    static constexpr uint32_t SMCR_ETPS =                // External trigger prescaler (2 bits)
        bit_field_t<12, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t SMCR_ETF =                 // External trigger filter (4 bits)
        bit_field_t<8, 0xf>::value<X>();
    static constexpr uint32_t SMCR_MSM = 0x80;           // Master/Slave mode
    template<uint32_t X>
    static constexpr uint32_t SMCR_TS =                  // Trigger selection (3 bits)
        bit_field_t<4, 0x7>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t SMCR_SMS =                 // Slave mode selection (3 bits)
        bit_field_t<0, 0x7>::value<X>();
    static const uint32_t SMCR_RESET_VALUE = 0x0;

    static constexpr uint32_t DIER_TDE = 0x4000;         // Trigger DMA request enable
    static constexpr uint32_t DIER_CC4DE = 0x1000;       // Capture/Compare 4 DMA request enable
    static constexpr uint32_t DIER_CC3DE = 0x800;        // Capture/Compare 3 DMA request enable
    static constexpr uint32_t DIER_CC2DE = 0x400;        // Capture/Compare 2 DMA request enable
    static constexpr uint32_t DIER_CC1DE = 0x200;        // Capture/Compare 1 DMA request enable
    static constexpr uint32_t DIER_UDE = 0x100;          // Update DMA request enable
    static constexpr uint32_t DIER_TIE = 0x40;           // Trigger interrupt enable
    static constexpr uint32_t DIER_CC4IE = 0x10;         // Capture/Compare 4 interrupt enable
    static constexpr uint32_t DIER_CC3IE = 0x8;          // Capture/Compare 3 interrupt enable
    static constexpr uint32_t DIER_CC2IE = 0x4;          // Capture/Compare 2 interrupt enable
    static constexpr uint32_t DIER_CC1IE = 0x2;          // Capture/Compare 1 interrupt enable
    static constexpr uint32_t DIER_UIE = 0x1;            // Update interrupt enable
    static const uint32_t DIER_RESET_VALUE = 0x0;

    static constexpr uint32_t SR_CC4OF = 0x1000;       // Capture/Compare 4 overcapture flag
    static constexpr uint32_t SR_CC3OF = 0x800;        // Capture/Compare 3 overcapture flag
    static constexpr uint32_t SR_CC2OF = 0x400;        // Capture/compare 2 overcapture flag
    static constexpr uint32_t SR_CC1OF = 0x200;        // Capture/Compare 1 overcapture flag
    static constexpr uint32_t SR_TIF = 0x40;           // Trigger interrupt flag
    static constexpr uint32_t SR_CC4IF = 0x10;         // Capture/Compare 4 interrupt flag
    static constexpr uint32_t SR_CC3IF = 0x8;          // Capture/Compare 3 interrupt flag
    static constexpr uint32_t SR_CC2IF = 0x4;          // Capture/Compare 2 interrupt flag
    static constexpr uint32_t SR_CC1IF = 0x2;          // Capture/compare 1 interrupt flag
    static constexpr uint32_t SR_UIF = 0x1;            // Update interrupt flag
    static const uint32_t SR_RESET_VALUE = 0x0;

    static constexpr uint32_t EGR_TG = 0x40;            // Trigger generation
    static constexpr uint32_t EGR_CC4G = 0x10;          // Capture/compare 4 generation
    static constexpr uint32_t EGR_CC3G = 0x8;           // Capture/compare 3 generation
    static constexpr uint32_t EGR_CC2G = 0x4;           // Capture/compare 2 generation
    static constexpr uint32_t EGR_CC1G = 0x2;           // Capture/compare 1 generation
    static constexpr uint32_t EGR_UG = 0x1;             // Update generation
    static const uint32_t EGR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t CCMR1_CC1S =                // CC1S (2 bits)
        bit_field_t<0, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CCMR1_CC2S =                // CC2S (2 bits)
        bit_field_t<8, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CCMR1_IC1F =                // Input capture 1 filter (4 bits)
        bit_field_t<4, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CCMR1_IC2F =                // Input capture 2 filter (4 bits)
        bit_field_t<12, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CCMR1_IC2PCS =              // Input capture 2 prescaler (2 bits)
        bit_field_t<10, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CCMR1_ICPCS =               // Input capture 1 prescaler (2 bits)
        bit_field_t<2, 0x3>::value<X>();
    static constexpr uint32_t CCMR1_OC1CE = 0x80;         // OC1CE
    static constexpr uint32_t CCMR1_OC1FE = 0x4;          // OC1FE
    template<uint32_t X>
    static constexpr uint32_t CCMR1_OC1M =                // OC1M (3 bits)
        bit_field_t<4, 0x7>::value<X>();
    static constexpr uint32_t CCMR1_OC1PE = 0x8;          // OC1PE
    static constexpr uint32_t CCMR1_OC2CE = 0x8000;       // OC2CE
    static constexpr uint32_t CCMR1_OC2FE = 0x400;        // OC2FE
    template<uint32_t X>
    static constexpr uint32_t CCMR1_OC2M =                // OC2M (3 bits)
        bit_field_t<12, 0x7>::value<X>();
    static constexpr uint32_t CCMR1_OC2PE = 0x800;        // OC2PE
    static const uint32_t CCMR1_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t CCMR2_CC3S =                // CC3S (2 bits)
        bit_field_t<0, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CCMR2_CC4S =                // CC4S (2 bits)
        bit_field_t<8, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CCMR2_IC3F =                // Input capture 3 filter (4 bits)
        bit_field_t<4, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CCMR2_IC3PSC =              // Input capture 3 prescaler (2 bits)
        bit_field_t<2, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CCMR2_IC4F =                // Input capture 4 filter (4 bits)
        bit_field_t<12, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CCMR2_IC4PSC =              // Input capture 4 prescaler (2 bits)
        bit_field_t<10, 0x3>::value<X>();
    static constexpr uint32_t CCMR2_O24CE = 0x8000;       // O24CE
    static constexpr uint32_t CCMR2_OC3CE = 0x80;         // OC3CE
    static constexpr uint32_t CCMR2_OC3FE = 0x4;          // OC3FE
    template<uint32_t X>
    static constexpr uint32_t CCMR2_OC3M =                // OC3M (3 bits)
        bit_field_t<4, 0x7>::value<X>();
    static constexpr uint32_t CCMR2_OC3PE = 0x8;          // OC3PE
    static constexpr uint32_t CCMR2_OC4FE = 0x400;        // OC4FE
    template<uint32_t X>
    static constexpr uint32_t CCMR2_OC4M =                // OC4M (3 bits)
        bit_field_t<12, 0x7>::value<X>();
    static constexpr uint32_t CCMR2_OC4PE = 0x800;        // OC4PE
    static const uint32_t CCMR2_RESET_VALUE = 0x0;

    static constexpr uint32_t CCER_CC4NP = 0x8000;       // Capture/Compare 4 output Polarity
    static constexpr uint32_t CCER_CC4P = 0x2000;        // Capture/Compare 3 output Polarity
    static constexpr uint32_t CCER_CC4E = 0x1000;        // Capture/Compare 4 output enable
    static constexpr uint32_t CCER_CC3NP = 0x800;        // Capture/Compare 3 output Polarity
    static constexpr uint32_t CCER_CC3P = 0x200;         // Capture/Compare 3 output Polarity
    static constexpr uint32_t CCER_CC3E = 0x100;         // Capture/Compare 3 output enable
    static constexpr uint32_t CCER_CC2NP = 0x80;         // Capture/Compare 2 output Polarity
    static constexpr uint32_t CCER_CC2P = 0x20;          // Capture/Compare 2 output Polarity
    static constexpr uint32_t CCER_CC2E = 0x10;          // Capture/Compare 2 output enable
    static constexpr uint32_t CCER_CC1NP = 0x8;          // Capture/Compare 1 output Polarity
    static constexpr uint32_t CCER_CC1P = 0x2;           // Capture/Compare 1 output Polarity
    static constexpr uint32_t CCER_CC1E = 0x1;           // Capture/Compare 1 output enable
    static const uint32_t CCER_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t CNT_CNT_H =               // High counter value (16 bits)
        bit_field_t<16, 0xffff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CNT_CNT_L =               // Low counter value (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t CNT_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t PSC_PSC =                 // Prescaler value (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t PSC_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t ARR_ARR_H =               // High Auto-reload value (16 bits)
        bit_field_t<16, 0xffff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t ARR_ARR_L =               // Low Auto-reload value (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t ARR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t CCR1_CCR1_H =              // High Capture/Compare 1 value (16 bits)
        bit_field_t<16, 0xffff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CCR1_CCR1_L =              // Low Capture/Compare 1 value (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t CCR1_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t CCR2_CCR2_H =              // High Capture/Compare 2 value (16 bits)
        bit_field_t<16, 0xffff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CCR2_CCR2_L =              // Low Capture/Compare 2 value (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t CCR2_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t CCR3_CCR3_H =              // High Capture/Compare value (16 bits)
        bit_field_t<16, 0xffff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CCR3_CCR3_L =              // Low Capture/Compare value (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t CCR3_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t CCR4_CCR4_H =              // High Capture/Compare value (16 bits)
        bit_field_t<16, 0xffff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CCR4_CCR4_L =              // Low Capture/Compare value (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t CCR4_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t DCR_DBL =                 // DMA burst length (5 bits)
        bit_field_t<8, 0x1f>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t DCR_DBA =                 // DMA base address (5 bits)
        bit_field_t<0, 0x1f>::value<X>();
    static const uint32_t DCR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t DMAR_DMAB =                // DMA register for burst accesses (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t DMAR_RESET_VALUE = 0x0;
};

static tim4_t& TIM4 = *reinterpret_cast<tim4_t*>(0x40000800);

#define HAVE_PERIPHERAL_TIM4


////
//
//    General-purpose-timers
//
////

struct tim5_t
{
    volatile uint32_t    CR1;                  // [Read-write] control register 1
    volatile uint32_t    CR2;                  // [Read-write] control register 2
    volatile uint32_t    SMCR;                 // [Read-write] slave mode control register
    volatile uint32_t    DIER;                 // [Read-write] DMA/Interrupt enable register
    volatile uint32_t    SR;                   // [Read-write] status register
    volatile uint32_t    EGR;                  // [Write-only] event generation register
    volatile uint32_t    CCMR1;                // [Read-write] capture/compare mode register 1 (output mode)
    volatile uint32_t    CCMR2;                // [Read-write] capture/compare mode register 2 (output mode)
    volatile uint32_t    CCER;                 // [Read-write] capture/compare enable register
    volatile uint32_t    CNT;                  // [Read-write] counter
    volatile uint32_t    PSC;                  // [Read-write] prescaler
    volatile uint32_t    ARR;                  // [Read-write] auto-reload register
    reserved_t<1>        _0;
    volatile uint32_t    CCR1;                 // [Read-write] capture/compare register 1
    volatile uint32_t    CCR2;                 // [Read-write] capture/compare register 2
    volatile uint32_t    CCR3;                 // [Read-write] capture/compare register 3
    volatile uint32_t    CCR4;                 // [Read-write] capture/compare register 4
    reserved_t<1>        _1;
    volatile uint32_t    DCR;                  // [Read-write] DMA control register
    volatile uint32_t    DMAR;                 // [Read-write] DMA address for full transfer
    volatile uint32_t    OR;                   // [Read-write] TIM5 option register

    template<uint32_t X>
    static constexpr uint32_t CR1_CKD =                 // Clock division (2 bits)
        bit_field_t<8, 0x3>::value<X>();
    static constexpr uint32_t CR1_ARPE = 0x80;          // Auto-reload preload enable
    template<uint32_t X>
    static constexpr uint32_t CR1_CMS =                 // Center-aligned mode selection (2 bits)
        bit_field_t<5, 0x3>::value<X>();
    static constexpr uint32_t CR1_DIR = 0x10;           // Direction
    static constexpr uint32_t CR1_OPM = 0x8;            // One-pulse mode
    static constexpr uint32_t CR1_URS = 0x4;            // Update request source
    static constexpr uint32_t CR1_UDIS = 0x2;           // Update disable
    static constexpr uint32_t CR1_CEN = 0x1;            // Counter enable
    static const uint32_t CR1_RESET_VALUE = 0x0;

    static constexpr uint32_t CR2_TI1S = 0x80;          // TI1 selection
    template<uint32_t X>
    static constexpr uint32_t CR2_MMS =                 // Master mode selection (3 bits)
        bit_field_t<4, 0x7>::value<X>();
    static constexpr uint32_t CR2_CCDS = 0x8;           // Capture/compare DMA selection
    static const uint32_t CR2_RESET_VALUE = 0x0;

    static constexpr uint32_t SMCR_ETP = 0x8000;         // External trigger polarity
    static constexpr uint32_t SMCR_ECE = 0x4000;         // External clock enable
    template<uint32_t X>
    static constexpr uint32_t SMCR_ETPS =                // External trigger prescaler (2 bits)
        bit_field_t<12, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t SMCR_ETF =                 // External trigger filter (4 bits)
        bit_field_t<8, 0xf>::value<X>();
    static constexpr uint32_t SMCR_MSM = 0x80;           // Master/Slave mode
    template<uint32_t X>
    static constexpr uint32_t SMCR_TS =                  // Trigger selection (3 bits)
        bit_field_t<4, 0x7>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t SMCR_SMS =                 // Slave mode selection (3 bits)
        bit_field_t<0, 0x7>::value<X>();
    static const uint32_t SMCR_RESET_VALUE = 0x0;

    static constexpr uint32_t DIER_TDE = 0x4000;         // Trigger DMA request enable
    static constexpr uint32_t DIER_CC4DE = 0x1000;       // Capture/Compare 4 DMA request enable
    static constexpr uint32_t DIER_CC3DE = 0x800;        // Capture/Compare 3 DMA request enable
    static constexpr uint32_t DIER_CC2DE = 0x400;        // Capture/Compare 2 DMA request enable
    static constexpr uint32_t DIER_CC1DE = 0x200;        // Capture/Compare 1 DMA request enable
    static constexpr uint32_t DIER_UDE = 0x100;          // Update DMA request enable
    static constexpr uint32_t DIER_TIE = 0x40;           // Trigger interrupt enable
    static constexpr uint32_t DIER_CC4IE = 0x10;         // Capture/Compare 4 interrupt enable
    static constexpr uint32_t DIER_CC3IE = 0x8;          // Capture/Compare 3 interrupt enable
    static constexpr uint32_t DIER_CC2IE = 0x4;          // Capture/Compare 2 interrupt enable
    static constexpr uint32_t DIER_CC1IE = 0x2;          // Capture/Compare 1 interrupt enable
    static constexpr uint32_t DIER_UIE = 0x1;            // Update interrupt enable
    static const uint32_t DIER_RESET_VALUE = 0x0;

    static constexpr uint32_t SR_CC4OF = 0x1000;       // Capture/Compare 4 overcapture flag
    static constexpr uint32_t SR_CC3OF = 0x800;        // Capture/Compare 3 overcapture flag
    static constexpr uint32_t SR_CC2OF = 0x400;        // Capture/compare 2 overcapture flag
    static constexpr uint32_t SR_CC1OF = 0x200;        // Capture/Compare 1 overcapture flag
    static constexpr uint32_t SR_TIF = 0x40;           // Trigger interrupt flag
    static constexpr uint32_t SR_CC4IF = 0x10;         // Capture/Compare 4 interrupt flag
    static constexpr uint32_t SR_CC3IF = 0x8;          // Capture/Compare 3 interrupt flag
    static constexpr uint32_t SR_CC2IF = 0x4;          // Capture/Compare 2 interrupt flag
    static constexpr uint32_t SR_CC1IF = 0x2;          // Capture/compare 1 interrupt flag
    static constexpr uint32_t SR_UIF = 0x1;            // Update interrupt flag
    static const uint32_t SR_RESET_VALUE = 0x0;

    static constexpr uint32_t EGR_TG = 0x40;            // Trigger generation
    static constexpr uint32_t EGR_CC4G = 0x10;          // Capture/compare 4 generation
    static constexpr uint32_t EGR_CC3G = 0x8;           // Capture/compare 3 generation
    static constexpr uint32_t EGR_CC2G = 0x4;           // Capture/compare 2 generation
    static constexpr uint32_t EGR_CC1G = 0x2;           // Capture/compare 1 generation
    static constexpr uint32_t EGR_UG = 0x1;             // Update generation
    static const uint32_t EGR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t CCMR1_CC1S =                // CC1S (2 bits)
        bit_field_t<0, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CCMR1_CC2S =                // CC2S (2 bits)
        bit_field_t<8, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CCMR1_IC1F =                // Input capture 1 filter (4 bits)
        bit_field_t<4, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CCMR1_IC2F =                // Input capture 2 filter (4 bits)
        bit_field_t<12, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CCMR1_IC2PCS =              // Input capture 2 prescaler (2 bits)
        bit_field_t<10, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CCMR1_ICPCS =               // Input capture 1 prescaler (2 bits)
        bit_field_t<2, 0x3>::value<X>();
    static constexpr uint32_t CCMR1_OC1CE = 0x80;         // OC1CE
    static constexpr uint32_t CCMR1_OC1FE = 0x4;          // OC1FE
    template<uint32_t X>
    static constexpr uint32_t CCMR1_OC1M =                // OC1M (3 bits)
        bit_field_t<4, 0x7>::value<X>();
    static constexpr uint32_t CCMR1_OC1PE = 0x8;          // OC1PE
    static constexpr uint32_t CCMR1_OC2CE = 0x8000;       // OC2CE
    static constexpr uint32_t CCMR1_OC2FE = 0x400;        // OC2FE
    template<uint32_t X>
    static constexpr uint32_t CCMR1_OC2M =                // OC2M (3 bits)
        bit_field_t<12, 0x7>::value<X>();
    static constexpr uint32_t CCMR1_OC2PE = 0x800;        // OC2PE
    static const uint32_t CCMR1_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t CCMR2_CC3S =                // CC3S (2 bits)
        bit_field_t<0, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CCMR2_CC4S =                // CC4S (2 bits)
        bit_field_t<8, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CCMR2_IC3F =                // Input capture 3 filter (4 bits)
        bit_field_t<4, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CCMR2_IC3PSC =              // Input capture 3 prescaler (2 bits)
        bit_field_t<2, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CCMR2_IC4F =                // Input capture 4 filter (4 bits)
        bit_field_t<12, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CCMR2_IC4PSC =              // Input capture 4 prescaler (2 bits)
        bit_field_t<10, 0x3>::value<X>();
    static constexpr uint32_t CCMR2_O24CE = 0x8000;       // O24CE
    static constexpr uint32_t CCMR2_OC3CE = 0x80;         // OC3CE
    static constexpr uint32_t CCMR2_OC3FE = 0x4;          // OC3FE
    template<uint32_t X>
    static constexpr uint32_t CCMR2_OC3M =                // OC3M (3 bits)
        bit_field_t<4, 0x7>::value<X>();
    static constexpr uint32_t CCMR2_OC3PE = 0x8;          // OC3PE
    static constexpr uint32_t CCMR2_OC4FE = 0x400;        // OC4FE
    template<uint32_t X>
    static constexpr uint32_t CCMR2_OC4M =                // OC4M (3 bits)
        bit_field_t<12, 0x7>::value<X>();
    static constexpr uint32_t CCMR2_OC4PE = 0x800;        // OC4PE
    static const uint32_t CCMR2_RESET_VALUE = 0x0;

    static constexpr uint32_t CCER_CC4NP = 0x8000;       // Capture/Compare 4 output Polarity
    static constexpr uint32_t CCER_CC4P = 0x2000;        // Capture/Compare 3 output Polarity
    static constexpr uint32_t CCER_CC4E = 0x1000;        // Capture/Compare 4 output enable
    static constexpr uint32_t CCER_CC3NP = 0x800;        // Capture/Compare 3 output Polarity
    static constexpr uint32_t CCER_CC3P = 0x200;         // Capture/Compare 3 output Polarity
    static constexpr uint32_t CCER_CC3E = 0x100;         // Capture/Compare 3 output enable
    static constexpr uint32_t CCER_CC2NP = 0x80;         // Capture/Compare 2 output Polarity
    static constexpr uint32_t CCER_CC2P = 0x20;          // Capture/Compare 2 output Polarity
    static constexpr uint32_t CCER_CC2E = 0x10;          // Capture/Compare 2 output enable
    static constexpr uint32_t CCER_CC1NP = 0x8;          // Capture/Compare 1 output Polarity
    static constexpr uint32_t CCER_CC1P = 0x2;           // Capture/Compare 1 output Polarity
    static constexpr uint32_t CCER_CC1E = 0x1;           // Capture/Compare 1 output enable
    static const uint32_t CCER_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t CNT_CNT_H =               // High counter value (16 bits)
        bit_field_t<16, 0xffff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CNT_CNT_L =               // Low counter value (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t CNT_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t PSC_PSC =                 // Prescaler value (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t PSC_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t ARR_ARR_H =               // High Auto-reload value (16 bits)
        bit_field_t<16, 0xffff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t ARR_ARR_L =               // Low Auto-reload value (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t ARR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t CCR1_CCR1_H =              // High Capture/Compare 1 value (16 bits)
        bit_field_t<16, 0xffff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CCR1_CCR1_L =              // Low Capture/Compare 1 value (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t CCR1_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t CCR2_CCR2_H =              // High Capture/Compare 2 value (16 bits)
        bit_field_t<16, 0xffff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CCR2_CCR2_L =              // Low Capture/Compare 2 value (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t CCR2_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t CCR3_CCR3_H =              // High Capture/Compare value (16 bits)
        bit_field_t<16, 0xffff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CCR3_CCR3_L =              // Low Capture/Compare value (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t CCR3_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t CCR4_CCR4_H =              // High Capture/Compare value (16 bits)
        bit_field_t<16, 0xffff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CCR4_CCR4_L =              // Low Capture/Compare value (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t CCR4_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t DCR_DBL =                 // DMA burst length (5 bits)
        bit_field_t<8, 0x1f>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t DCR_DBA =                 // DMA base address (5 bits)
        bit_field_t<0, 0x1f>::value<X>();
    static const uint32_t DCR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t DMAR_DMAB =                // DMA register for burst accesses (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t DMAR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t OR_IT4_RMP =             // Timer Input 4 remap (2 bits)
        bit_field_t<6, 0x3>::value<X>();
    static const uint32_t OR_RESET_VALUE = 0x0;
};

static tim5_t& TIM5 = *reinterpret_cast<tim5_t*>(0x40000c00);

#define HAVE_PERIPHERAL_TIM5


////
//
//    General purpose timers
//
////

struct tim9_t
{
    volatile uint32_t    CR1;                  // [Read-write] control register 1
    volatile uint32_t    CR2;                  // [Read-write] control register 2
    volatile uint32_t    SMCR;                 // [Read-write] slave mode control register
    volatile uint32_t    DIER;                 // [Read-write] DMA/Interrupt enable register
    volatile uint32_t    SR;                   // [Read-write] status register
    volatile uint32_t    EGR;                  // [Write-only] event generation register
    volatile uint32_t    CCMR1;                // [Read-write] capture/compare mode register 1 (output mode)
    reserved_t<1>        _0;
    volatile uint32_t    CCER;                 // [Read-write] capture/compare enable register
    volatile uint32_t    CNT;                  // [Read-write] counter
    volatile uint32_t    PSC;                  // [Read-write] prescaler
    volatile uint32_t    ARR;                  // [Read-write] auto-reload register
    reserved_t<1>        _1;
    volatile uint32_t    CCR1;                 // [Read-write] capture/compare register 1
    volatile uint32_t    CCR2;                 // [Read-write] capture/compare register 2

    template<uint32_t X>
    static constexpr uint32_t CR1_CKD =                 // Clock division (2 bits)
        bit_field_t<8, 0x3>::value<X>();
    static constexpr uint32_t CR1_ARPE = 0x80;          // Auto-reload preload enable
    static constexpr uint32_t CR1_OPM = 0x8;            // One-pulse mode
    static constexpr uint32_t CR1_URS = 0x4;            // Update request source
    static constexpr uint32_t CR1_UDIS = 0x2;           // Update disable
    static constexpr uint32_t CR1_CEN = 0x1;            // Counter enable
    static const uint32_t CR1_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t CR2_MMS =                 // Master mode selection (3 bits)
        bit_field_t<4, 0x7>::value<X>();
    static const uint32_t CR2_RESET_VALUE = 0x0;

    static constexpr uint32_t SMCR_MSM = 0x80;           // Master/Slave mode
    template<uint32_t X>
    static constexpr uint32_t SMCR_TS =                  // Trigger selection (3 bits)
        bit_field_t<4, 0x7>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t SMCR_SMS =                 // Slave mode selection (3 bits)
        bit_field_t<0, 0x7>::value<X>();
    static const uint32_t SMCR_RESET_VALUE = 0x0;

    static constexpr uint32_t DIER_TIE = 0x40;           // Trigger interrupt enable
    static constexpr uint32_t DIER_CC2IE = 0x4;          // Capture/Compare 2 interrupt enable
    static constexpr uint32_t DIER_CC1IE = 0x2;          // Capture/Compare 1 interrupt enable
    static constexpr uint32_t DIER_UIE = 0x1;            // Update interrupt enable
    static const uint32_t DIER_RESET_VALUE = 0x0;

    static constexpr uint32_t SR_CC2OF = 0x400;        // Capture/compare 2 overcapture flag
    static constexpr uint32_t SR_CC1OF = 0x200;        // Capture/Compare 1 overcapture flag
    static constexpr uint32_t SR_TIF = 0x40;           // Trigger interrupt flag
    static constexpr uint32_t SR_CC2IF = 0x4;          // Capture/Compare 2 interrupt flag
    static constexpr uint32_t SR_CC1IF = 0x2;          // Capture/compare 1 interrupt flag
    static constexpr uint32_t SR_UIF = 0x1;            // Update interrupt flag
    static const uint32_t SR_RESET_VALUE = 0x0;

    static constexpr uint32_t EGR_TG = 0x40;            // Trigger generation
    static constexpr uint32_t EGR_CC2G = 0x4;           // Capture/compare 2 generation
    static constexpr uint32_t EGR_CC1G = 0x2;           // Capture/compare 1 generation
    static constexpr uint32_t EGR_UG = 0x1;             // Update generation
    static const uint32_t EGR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t CCMR1_CC1S =                // Capture/Compare 1 selection (2 bits)
        bit_field_t<0, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CCMR1_CC2S =                // Capture/Compare 2 selection (2 bits)
        bit_field_t<8, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CCMR1_IC1F =                // Input capture 1 filter (3 bits)
        bit_field_t<4, 0x7>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CCMR1_IC2F =                // Input capture 2 filter (3 bits)
        bit_field_t<12, 0x7>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CCMR1_IC2PCS =              // Input capture 2 prescaler (2 bits)
        bit_field_t<10, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CCMR1_ICPCS =               // Input capture 1 prescaler (2 bits)
        bit_field_t<2, 0x3>::value<X>();
    static constexpr uint32_t CCMR1_OC1FE = 0x4;          // Output Compare 1 fast enable
    template<uint32_t X>
    static constexpr uint32_t CCMR1_OC1M =                // Output Compare 1 mode (3 bits)
        bit_field_t<4, 0x7>::value<X>();
    static constexpr uint32_t CCMR1_OC1PE = 0x8;          // Output Compare 1 preload enable
    static constexpr uint32_t CCMR1_OC2FE = 0x400;        // Output Compare 2 fast enable
    template<uint32_t X>
    static constexpr uint32_t CCMR1_OC2M =                // Output Compare 2 mode (3 bits)
        bit_field_t<12, 0x7>::value<X>();
    static constexpr uint32_t CCMR1_OC2PE = 0x800;        // Output Compare 2 preload enable
    static const uint32_t CCMR1_RESET_VALUE = 0x0;

    static constexpr uint32_t CCER_CC2NP = 0x80;         // Capture/Compare 2 output Polarity
    static constexpr uint32_t CCER_CC2P = 0x20;          // Capture/Compare 2 output Polarity
    static constexpr uint32_t CCER_CC2E = 0x10;          // Capture/Compare 2 output enable
    static constexpr uint32_t CCER_CC1NP = 0x8;          // Capture/Compare 1 output Polarity
    static constexpr uint32_t CCER_CC1P = 0x2;           // Capture/Compare 1 output Polarity
    static constexpr uint32_t CCER_CC1E = 0x1;           // Capture/Compare 1 output enable
    static const uint32_t CCER_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t CNT_CNT =                 // counter value (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t CNT_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t PSC_PSC =                 // Prescaler value (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t PSC_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t ARR_ARR =                 // Auto-reload value (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t ARR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t CCR1_CCR1 =                // Capture/Compare 1 value (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t CCR1_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t CCR2_CCR2 =                // Capture/Compare 2 value (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t CCR2_RESET_VALUE = 0x0;
};

static tim9_t& TIM9 = *reinterpret_cast<tim9_t*>(0x40014000);

#define HAVE_PERIPHERAL_TIM9


////
//
//    Universal synchronous asynchronous receiver transmitter
//
////

struct usart1_t
{
    volatile uint32_t    SR;                   // Status register
    volatile uint32_t    DR;                   // [Read-write] Data register
    volatile uint32_t    BRR;                  // [Read-write] Baud rate register
    volatile uint32_t    CR1;                  // [Read-write] Control register 1
    volatile uint32_t    CR2;                  // [Read-write] Control register 2
    volatile uint32_t    CR3;                  // [Read-write] Control register 3
    volatile uint32_t    GTPR;                 // [Read-write] Guard time and prescaler register

    static constexpr uint32_t SR_CTS = 0x200;          // CTS flag, Read-write
    static constexpr uint32_t SR_LBD = 0x100;          // LIN break detection flag, Read-write
    static constexpr uint32_t SR_TXE = 0x80;           // Transmit data register empty, Read-only
    static constexpr uint32_t SR_TC = 0x40;            // Transmission complete, Read-write
    static constexpr uint32_t SR_RXNE = 0x20;          // Read data register not empty, Read-write
    static constexpr uint32_t SR_IDLE = 0x10;          // IDLE line detected, Read-only
    static constexpr uint32_t SR_ORE = 0x8;            // Overrun error, Read-only
    static constexpr uint32_t SR_NF = 0x4;             // Noise detected flag, Read-only
    static constexpr uint32_t SR_FE = 0x2;             // Framing error, Read-only
    static constexpr uint32_t SR_PE = 0x1;             // Parity error, Read-only
    static const uint32_t SR_RESET_VALUE = 0xc00000;

    template<uint32_t X>
    static constexpr uint32_t DR_DR =                  // Data value (9 bits)
        bit_field_t<0, 0x1ff>::value<X>();
    static const uint32_t DR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t BRR_DIV_Mantissa =        // mantissa of USARTDIV (12 bits)
        bit_field_t<4, 0xfff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t BRR_DIV_Fraction =        // fraction of USARTDIV (4 bits)
        bit_field_t<0, 0xf>::value<X>();
    static const uint32_t BRR_RESET_VALUE = 0x0;

    static constexpr uint32_t CR1_OVER8 = 0x8000;       // Oversampling mode
    static constexpr uint32_t CR1_UE = 0x2000;          // USART enable
    static constexpr uint32_t CR1_M = 0x1000;           // Word length
    static constexpr uint32_t CR1_WAKE = 0x800;         // Wakeup method
    static constexpr uint32_t CR1_PCE = 0x400;          // Parity control enable
    static constexpr uint32_t CR1_PS = 0x200;           // Parity selection
    static constexpr uint32_t CR1_PEIE = 0x100;         // PE interrupt enable
    static constexpr uint32_t CR1_TXEIE = 0x80;         // TXE interrupt enable
    static constexpr uint32_t CR1_TCIE = 0x40;          // Transmission complete interrupt enable
    static constexpr uint32_t CR1_RXNEIE = 0x20;        // RXNE interrupt enable
    static constexpr uint32_t CR1_IDLEIE = 0x10;        // IDLE interrupt enable
    static constexpr uint32_t CR1_TE = 0x8;             // Transmitter enable
    static constexpr uint32_t CR1_RE = 0x4;             // Receiver enable
    static constexpr uint32_t CR1_RWU = 0x2;            // Receiver wakeup
    static constexpr uint32_t CR1_SBK = 0x1;            // Send break
    static const uint32_t CR1_RESET_VALUE = 0x0;

    static constexpr uint32_t CR2_LINEN = 0x4000;       // LIN mode enable
    template<uint32_t X>
    static constexpr uint32_t CR2_STOP =                // STOP bits (2 bits)
        bit_field_t<12, 0x3>::value<X>();
    static constexpr uint32_t CR2_CLKEN = 0x800;        // Clock enable
    static constexpr uint32_t CR2_CPOL = 0x400;         // Clock polarity
    static constexpr uint32_t CR2_CPHA = 0x200;         // Clock phase
    static constexpr uint32_t CR2_LBCL = 0x100;         // Last bit clock pulse
    static constexpr uint32_t CR2_LBDIE = 0x40;         // LIN break detection interrupt enable
    static constexpr uint32_t CR2_LBDL = 0x20;          // lin break detection length
    template<uint32_t X>
    static constexpr uint32_t CR2_ADD =                 // Address of the USART node (4 bits)
        bit_field_t<0, 0xf>::value<X>();
    static const uint32_t CR2_RESET_VALUE = 0x0;

    static constexpr uint32_t CR3_ONEBIT = 0x800;       // One sample bit method enable
    static constexpr uint32_t CR3_CTSIE = 0x400;        // CTS interrupt enable
    static constexpr uint32_t CR3_CTSE = 0x200;         // CTS enable
    static constexpr uint32_t CR3_RTSE = 0x100;         // RTS enable
    static constexpr uint32_t CR3_DMAT = 0x80;          // DMA enable transmitter
    static constexpr uint32_t CR3_DMAR = 0x40;          // DMA enable receiver
    static constexpr uint32_t CR3_SCEN = 0x20;          // Smartcard mode enable
    static constexpr uint32_t CR3_NACK = 0x10;          // Smartcard NACK enable
    static constexpr uint32_t CR3_HDSEL = 0x8;          // Half-duplex selection
    static constexpr uint32_t CR3_IRLP = 0x4;           // IrDA low-power
    static constexpr uint32_t CR3_IREN = 0x2;           // IrDA mode enable
    static constexpr uint32_t CR3_EIE = 0x1;            // Error interrupt enable
    static const uint32_t CR3_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t GTPR_GT =                  // Guard time value (8 bits)
        bit_field_t<8, 0xff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t GTPR_PSC =                 // Prescaler value (8 bits)
        bit_field_t<0, 0xff>::value<X>();
    static const uint32_t GTPR_RESET_VALUE = 0x0;

    static constexpr uint8_t OTG_FS = 67; // USB On The Go FS global interrupt
    static constexpr uint8_t OTG_FS_WKUP = 42; // USB On-The-Go FS Wakeup through EXTI line interrupt
    static constexpr uint8_t USART1 = 37; // USART1 event interrupt
};

static usart1_t& USART1 = *reinterpret_cast<usart1_t*>(0x40011000);

#define HAVE_PERIPHERAL_USART1


////
//
//    Universal synchronous asynchronous receiver transmitter
//
////

struct usart2_t
{
    volatile uint32_t    SR;                   // Status register
    volatile uint32_t    DR;                   // [Read-write] Data register
    volatile uint32_t    BRR;                  // [Read-write] Baud rate register
    volatile uint32_t    CR1;                  // [Read-write] Control register 1
    volatile uint32_t    CR2;                  // [Read-write] Control register 2
    volatile uint32_t    CR3;                  // [Read-write] Control register 3
    volatile uint32_t    GTPR;                 // [Read-write] Guard time and prescaler register

    static constexpr uint32_t SR_CTS = 0x200;          // CTS flag, Read-write
    static constexpr uint32_t SR_LBD = 0x100;          // LIN break detection flag, Read-write
    static constexpr uint32_t SR_TXE = 0x80;           // Transmit data register empty, Read-only
    static constexpr uint32_t SR_TC = 0x40;            // Transmission complete, Read-write
    static constexpr uint32_t SR_RXNE = 0x20;          // Read data register not empty, Read-write
    static constexpr uint32_t SR_IDLE = 0x10;          // IDLE line detected, Read-only
    static constexpr uint32_t SR_ORE = 0x8;            // Overrun error, Read-only
    static constexpr uint32_t SR_NF = 0x4;             // Noise detected flag, Read-only
    static constexpr uint32_t SR_FE = 0x2;             // Framing error, Read-only
    static constexpr uint32_t SR_PE = 0x1;             // Parity error, Read-only
    static const uint32_t SR_RESET_VALUE = 0xc00000;

    template<uint32_t X>
    static constexpr uint32_t DR_DR =                  // Data value (9 bits)
        bit_field_t<0, 0x1ff>::value<X>();
    static const uint32_t DR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t BRR_DIV_Mantissa =        // mantissa of USARTDIV (12 bits)
        bit_field_t<4, 0xfff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t BRR_DIV_Fraction =        // fraction of USARTDIV (4 bits)
        bit_field_t<0, 0xf>::value<X>();
    static const uint32_t BRR_RESET_VALUE = 0x0;

    static constexpr uint32_t CR1_OVER8 = 0x8000;       // Oversampling mode
    static constexpr uint32_t CR1_UE = 0x2000;          // USART enable
    static constexpr uint32_t CR1_M = 0x1000;           // Word length
    static constexpr uint32_t CR1_WAKE = 0x800;         // Wakeup method
    static constexpr uint32_t CR1_PCE = 0x400;          // Parity control enable
    static constexpr uint32_t CR1_PS = 0x200;           // Parity selection
    static constexpr uint32_t CR1_PEIE = 0x100;         // PE interrupt enable
    static constexpr uint32_t CR1_TXEIE = 0x80;         // TXE interrupt enable
    static constexpr uint32_t CR1_TCIE = 0x40;          // Transmission complete interrupt enable
    static constexpr uint32_t CR1_RXNEIE = 0x20;        // RXNE interrupt enable
    static constexpr uint32_t CR1_IDLEIE = 0x10;        // IDLE interrupt enable
    static constexpr uint32_t CR1_TE = 0x8;             // Transmitter enable
    static constexpr uint32_t CR1_RE = 0x4;             // Receiver enable
    static constexpr uint32_t CR1_RWU = 0x2;            // Receiver wakeup
    static constexpr uint32_t CR1_SBK = 0x1;            // Send break
    static const uint32_t CR1_RESET_VALUE = 0x0;

    static constexpr uint32_t CR2_LINEN = 0x4000;       // LIN mode enable
    template<uint32_t X>
    static constexpr uint32_t CR2_STOP =                // STOP bits (2 bits)
        bit_field_t<12, 0x3>::value<X>();
    static constexpr uint32_t CR2_CLKEN = 0x800;        // Clock enable
    static constexpr uint32_t CR2_CPOL = 0x400;         // Clock polarity
    static constexpr uint32_t CR2_CPHA = 0x200;         // Clock phase
    static constexpr uint32_t CR2_LBCL = 0x100;         // Last bit clock pulse
    static constexpr uint32_t CR2_LBDIE = 0x40;         // LIN break detection interrupt enable
    static constexpr uint32_t CR2_LBDL = 0x20;          // lin break detection length
    template<uint32_t X>
    static constexpr uint32_t CR2_ADD =                 // Address of the USART node (4 bits)
        bit_field_t<0, 0xf>::value<X>();
    static const uint32_t CR2_RESET_VALUE = 0x0;

    static constexpr uint32_t CR3_ONEBIT = 0x800;       // One sample bit method enable
    static constexpr uint32_t CR3_CTSIE = 0x400;        // CTS interrupt enable
    static constexpr uint32_t CR3_CTSE = 0x200;         // CTS enable
    static constexpr uint32_t CR3_RTSE = 0x100;         // RTS enable
    static constexpr uint32_t CR3_DMAT = 0x80;          // DMA enable transmitter
    static constexpr uint32_t CR3_DMAR = 0x40;          // DMA enable receiver
    static constexpr uint32_t CR3_SCEN = 0x20;          // Smartcard mode enable
    static constexpr uint32_t CR3_NACK = 0x10;          // Smartcard NACK enable
    static constexpr uint32_t CR3_HDSEL = 0x8;          // Half-duplex selection
    static constexpr uint32_t CR3_IRLP = 0x4;           // IrDA low-power
    static constexpr uint32_t CR3_IREN = 0x2;           // IrDA mode enable
    static constexpr uint32_t CR3_EIE = 0x1;            // Error interrupt enable
    static const uint32_t CR3_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t GTPR_GT =                  // Guard time value (8 bits)
        bit_field_t<8, 0xff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t GTPR_PSC =                 // Prescaler value (8 bits)
        bit_field_t<0, 0xff>::value<X>();
    static const uint32_t GTPR_RESET_VALUE = 0x0;
};

static usart2_t& USART2 = *reinterpret_cast<usart2_t*>(0x40004400);

#define HAVE_PERIPHERAL_USART2


////
//
//    Universal synchronous asynchronous receiver transmitter
//
////

struct usart6_t
{
    volatile uint32_t    SR;                   // Status register
    volatile uint32_t    DR;                   // [Read-write] Data register
    volatile uint32_t    BRR;                  // [Read-write] Baud rate register
    volatile uint32_t    CR1;                  // [Read-write] Control register 1
    volatile uint32_t    CR2;                  // [Read-write] Control register 2
    volatile uint32_t    CR3;                  // [Read-write] Control register 3
    volatile uint32_t    GTPR;                 // [Read-write] Guard time and prescaler register

    static constexpr uint32_t SR_CTS = 0x200;          // CTS flag, Read-write
    static constexpr uint32_t SR_LBD = 0x100;          // LIN break detection flag, Read-write
    static constexpr uint32_t SR_TXE = 0x80;           // Transmit data register empty, Read-only
    static constexpr uint32_t SR_TC = 0x40;            // Transmission complete, Read-write
    static constexpr uint32_t SR_RXNE = 0x20;          // Read data register not empty, Read-write
    static constexpr uint32_t SR_IDLE = 0x10;          // IDLE line detected, Read-only
    static constexpr uint32_t SR_ORE = 0x8;            // Overrun error, Read-only
    static constexpr uint32_t SR_NF = 0x4;             // Noise detected flag, Read-only
    static constexpr uint32_t SR_FE = 0x2;             // Framing error, Read-only
    static constexpr uint32_t SR_PE = 0x1;             // Parity error, Read-only
    static const uint32_t SR_RESET_VALUE = 0xc00000;

    template<uint32_t X>
    static constexpr uint32_t DR_DR =                  // Data value (9 bits)
        bit_field_t<0, 0x1ff>::value<X>();
    static const uint32_t DR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t BRR_DIV_Mantissa =        // mantissa of USARTDIV (12 bits)
        bit_field_t<4, 0xfff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t BRR_DIV_Fraction =        // fraction of USARTDIV (4 bits)
        bit_field_t<0, 0xf>::value<X>();
    static const uint32_t BRR_RESET_VALUE = 0x0;

    static constexpr uint32_t CR1_OVER8 = 0x8000;       // Oversampling mode
    static constexpr uint32_t CR1_UE = 0x2000;          // USART enable
    static constexpr uint32_t CR1_M = 0x1000;           // Word length
    static constexpr uint32_t CR1_WAKE = 0x800;         // Wakeup method
    static constexpr uint32_t CR1_PCE = 0x400;          // Parity control enable
    static constexpr uint32_t CR1_PS = 0x200;           // Parity selection
    static constexpr uint32_t CR1_PEIE = 0x100;         // PE interrupt enable
    static constexpr uint32_t CR1_TXEIE = 0x80;         // TXE interrupt enable
    static constexpr uint32_t CR1_TCIE = 0x40;          // Transmission complete interrupt enable
    static constexpr uint32_t CR1_RXNEIE = 0x20;        // RXNE interrupt enable
    static constexpr uint32_t CR1_IDLEIE = 0x10;        // IDLE interrupt enable
    static constexpr uint32_t CR1_TE = 0x8;             // Transmitter enable
    static constexpr uint32_t CR1_RE = 0x4;             // Receiver enable
    static constexpr uint32_t CR1_RWU = 0x2;            // Receiver wakeup
    static constexpr uint32_t CR1_SBK = 0x1;            // Send break
    static const uint32_t CR1_RESET_VALUE = 0x0;

    static constexpr uint32_t CR2_LINEN = 0x4000;       // LIN mode enable
    template<uint32_t X>
    static constexpr uint32_t CR2_STOP =                // STOP bits (2 bits)
        bit_field_t<12, 0x3>::value<X>();
    static constexpr uint32_t CR2_CLKEN = 0x800;        // Clock enable
    static constexpr uint32_t CR2_CPOL = 0x400;         // Clock polarity
    static constexpr uint32_t CR2_CPHA = 0x200;         // Clock phase
    static constexpr uint32_t CR2_LBCL = 0x100;         // Last bit clock pulse
    static constexpr uint32_t CR2_LBDIE = 0x40;         // LIN break detection interrupt enable
    static constexpr uint32_t CR2_LBDL = 0x20;          // lin break detection length
    template<uint32_t X>
    static constexpr uint32_t CR2_ADD =                 // Address of the USART node (4 bits)
        bit_field_t<0, 0xf>::value<X>();
    static const uint32_t CR2_RESET_VALUE = 0x0;

    static constexpr uint32_t CR3_ONEBIT = 0x800;       // One sample bit method enable
    static constexpr uint32_t CR3_CTSIE = 0x400;        // CTS interrupt enable
    static constexpr uint32_t CR3_CTSE = 0x200;         // CTS enable
    static constexpr uint32_t CR3_RTSE = 0x100;         // RTS enable
    static constexpr uint32_t CR3_DMAT = 0x80;          // DMA enable transmitter
    static constexpr uint32_t CR3_DMAR = 0x40;          // DMA enable receiver
    static constexpr uint32_t CR3_SCEN = 0x20;          // Smartcard mode enable
    static constexpr uint32_t CR3_NACK = 0x10;          // Smartcard NACK enable
    static constexpr uint32_t CR3_HDSEL = 0x8;          // Half-duplex selection
    static constexpr uint32_t CR3_IRLP = 0x4;           // IrDA low-power
    static constexpr uint32_t CR3_IREN = 0x2;           // IrDA mode enable
    static constexpr uint32_t CR3_EIE = 0x1;            // Error interrupt enable
    static const uint32_t CR3_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t GTPR_GT =                  // Guard time value (8 bits)
        bit_field_t<8, 0xff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t GTPR_PSC =                 // Prescaler value (8 bits)
        bit_field_t<0, 0xff>::value<X>();
    static const uint32_t GTPR_RESET_VALUE = 0x0;
};

static usart6_t& USART6 = *reinterpret_cast<usart6_t*>(0x40011400);

#define HAVE_PERIPHERAL_USART6


////
//
//    Window watchdog
//
////

struct wwdg_t
{
    volatile uint32_t    CR;                   // [Read-write] Control register
    volatile uint32_t    CFR;                  // [Read-write] Configuration register
    volatile uint32_t    SR;                   // [Read-write] Status register

    static constexpr uint32_t CR_WDGA = 0x80;          // Activation bit
    template<uint32_t X>
    static constexpr uint32_t CR_T =                   // 7-bit counter (MSB to LSB) (7 bits)
        bit_field_t<0, 0x7f>::value<X>();
    static const uint32_t CR_RESET_VALUE = 0x7f;

    static constexpr uint32_t CFR_EWI = 0x200;          // Early wakeup interrupt
    static constexpr uint32_t CFR_WDGTB1 = 0x100;       // Timer base
    static constexpr uint32_t CFR_WDGTB0 = 0x80;        // Timer base
    template<uint32_t X>
    static constexpr uint32_t CFR_W =                   // 7-bit window value (7 bits)
        bit_field_t<0, 0x7f>::value<X>();
    static const uint32_t CFR_RESET_VALUE = 0x7f;

    static constexpr uint32_t SR_EWIF = 0x1;           // Early wakeup interrupt flag
    static const uint32_t SR_RESET_VALUE = 0x0;

    static constexpr uint8_t PVD = 1; // PVD through EXTI line detection interrupt
    static constexpr uint8_t USART2 = 38; // USART2 event interrupt
};

static wwdg_t& WWDG = *reinterpret_cast<wwdg_t*>(0x40002c00);

#define HAVE_PERIPHERAL_WWDG


////
//
//    DMA controller
//
////

struct dma2_t
{
    volatile uint32_t    LISR;                 // [Read-only] low interrupt status register
    volatile uint32_t    HISR;                 // [Read-only] high interrupt status register
    volatile uint32_t    LIFCR;                // [Write-only] low interrupt flag clear register
    volatile uint32_t    HIFCR;                // [Write-only] high interrupt flag clear register
    volatile uint32_t    S0CR;                 // [Read-write] stream x configuration register
    volatile uint32_t    S0NDTR;               // [Read-write] stream x number of data register
    volatile uint32_t    S0PAR;                // [Read-write] stream x peripheral address register
    volatile uint32_t    S0M0AR;               // [Read-write] stream x memory 0 address register
    volatile uint32_t    S0M1AR;               // [Read-write] stream x memory 1 address register
    volatile uint32_t    S0FCR;                // stream x FIFO control register
    volatile uint32_t    S1CR;                 // [Read-write] stream x configuration register
    volatile uint32_t    S1NDTR;               // [Read-write] stream x number of data register
    volatile uint32_t    S1PAR;                // [Read-write] stream x peripheral address register
    volatile uint32_t    S1M0AR;               // [Read-write] stream x memory 0 address register
    volatile uint32_t    S1M1AR;               // [Read-write] stream x memory 1 address register
    volatile uint32_t    S1FCR;                // stream x FIFO control register
    volatile uint32_t    S2CR;                 // [Read-write] stream x configuration register
    volatile uint32_t    S2NDTR;               // [Read-write] stream x number of data register
    volatile uint32_t    S2PAR;                // [Read-write] stream x peripheral address register
    volatile uint32_t    S2M0AR;               // [Read-write] stream x memory 0 address register
    volatile uint32_t    S2M1AR;               // [Read-write] stream x memory 1 address register
    volatile uint32_t    S2FCR;                // stream x FIFO control register
    volatile uint32_t    S3CR;                 // [Read-write] stream x configuration register
    volatile uint32_t    S3NDTR;               // [Read-write] stream x number of data register
    volatile uint32_t    S3PAR;                // [Read-write] stream x peripheral address register
    volatile uint32_t    S3M0AR;               // [Read-write] stream x memory 0 address register
    volatile uint32_t    S3M1AR;               // [Read-write] stream x memory 1 address register
    volatile uint32_t    S3FCR;                // stream x FIFO control register
    volatile uint32_t    S4CR;                 // [Read-write] stream x configuration register
    volatile uint32_t    S4NDTR;               // [Read-write] stream x number of data register
    volatile uint32_t    S4PAR;                // [Read-write] stream x peripheral address register
    volatile uint32_t    S4M0AR;               // [Read-write] stream x memory 0 address register
    volatile uint32_t    S4M1AR;               // [Read-write] stream x memory 1 address register
    volatile uint32_t    S4FCR;                // stream x FIFO control register
    volatile uint32_t    S5CR;                 // [Read-write] stream x configuration register
    volatile uint32_t    S5NDTR;               // [Read-write] stream x number of data register
    volatile uint32_t    S5PAR;                // [Read-write] stream x peripheral address register
    volatile uint32_t    S5M0AR;               // [Read-write] stream x memory 0 address register
    volatile uint32_t    S5M1AR;               // [Read-write] stream x memory 1 address register
    volatile uint32_t    S5FCR;                // stream x FIFO control register
    volatile uint32_t    S6CR;                 // [Read-write] stream x configuration register
    volatile uint32_t    S6NDTR;               // [Read-write] stream x number of data register
    volatile uint32_t    S6PAR;                // [Read-write] stream x peripheral address register
    volatile uint32_t    S6M0AR;               // [Read-write] stream x memory 0 address register
    volatile uint32_t    S6M1AR;               // [Read-write] stream x memory 1 address register
    volatile uint32_t    S6FCR;                // stream x FIFO control register
    volatile uint32_t    S7CR;                 // [Read-write] stream x configuration register
    volatile uint32_t    S7NDTR;               // [Read-write] stream x number of data register
    volatile uint32_t    S7PAR;                // [Read-write] stream x peripheral address register
    volatile uint32_t    S7M0AR;               // [Read-write] stream x memory 0 address register
    volatile uint32_t    S7M1AR;               // [Read-write] stream x memory 1 address register
    volatile uint32_t    S7FCR;                // stream x FIFO control register

    static constexpr uint32_t LISR_TCIF3 = 0x8000000;    // Stream x transfer complete interrupt flag (x = 3..0)
    static constexpr uint32_t LISR_HTIF3 = 0x4000000;    // Stream x half transfer interrupt flag (x=3..0)
    static constexpr uint32_t LISR_TEIF3 = 0x2000000;    // Stream x transfer error interrupt flag (x=3..0)
    static constexpr uint32_t LISR_DMEIF3 = 0x1000000;   // Stream x direct mode error interrupt flag (x=3..0)
    static constexpr uint32_t LISR_FEIF3 = 0x400000;     // Stream x FIFO error interrupt flag (x=3..0)
    static constexpr uint32_t LISR_TCIF2 = 0x200000;     // Stream x transfer complete interrupt flag (x = 3..0)
    static constexpr uint32_t LISR_HTIF2 = 0x100000;     // Stream x half transfer interrupt flag (x=3..0)
    static constexpr uint32_t LISR_TEIF2 = 0x80000;      // Stream x transfer error interrupt flag (x=3..0)
    static constexpr uint32_t LISR_DMEIF2 = 0x40000;     // Stream x direct mode error interrupt flag (x=3..0)
    static constexpr uint32_t LISR_FEIF2 = 0x10000;      // Stream x FIFO error interrupt flag (x=3..0)
    static constexpr uint32_t LISR_TCIF1 = 0x800;        // Stream x transfer complete interrupt flag (x = 3..0)
    static constexpr uint32_t LISR_HTIF1 = 0x400;        // Stream x half transfer interrupt flag (x=3..0)
    static constexpr uint32_t LISR_TEIF1 = 0x200;        // Stream x transfer error interrupt flag (x=3..0)
    static constexpr uint32_t LISR_DMEIF1 = 0x100;       // Stream x direct mode error interrupt flag (x=3..0)
    static constexpr uint32_t LISR_FEIF1 = 0x40;         // Stream x FIFO error interrupt flag (x=3..0)
    static constexpr uint32_t LISR_TCIF0 = 0x20;         // Stream x transfer complete interrupt flag (x = 3..0)
    static constexpr uint32_t LISR_HTIF0 = 0x10;         // Stream x half transfer interrupt flag (x=3..0)
    static constexpr uint32_t LISR_TEIF0 = 0x8;          // Stream x transfer error interrupt flag (x=3..0)
    static constexpr uint32_t LISR_DMEIF0 = 0x4;         // Stream x direct mode error interrupt flag (x=3..0)
    static constexpr uint32_t LISR_FEIF0 = 0x1;          // Stream x FIFO error interrupt flag (x=3..0)
    static const uint32_t LISR_RESET_VALUE = 0x0;

    static constexpr uint32_t HISR_TCIF7 = 0x8000000;    // Stream x transfer complete interrupt flag (x=7..4)
    static constexpr uint32_t HISR_HTIF7 = 0x4000000;    // Stream x half transfer interrupt flag (x=7..4)
    static constexpr uint32_t HISR_TEIF7 = 0x2000000;    // Stream x transfer error interrupt flag (x=7..4)
    static constexpr uint32_t HISR_DMEIF7 = 0x1000000;   // Stream x direct mode error interrupt flag (x=7..4)
    static constexpr uint32_t HISR_FEIF7 = 0x400000;     // Stream x FIFO error interrupt flag (x=7..4)
    static constexpr uint32_t HISR_TCIF6 = 0x200000;     // Stream x transfer complete interrupt flag (x=7..4)
    static constexpr uint32_t HISR_HTIF6 = 0x100000;     // Stream x half transfer interrupt flag (x=7..4)
    static constexpr uint32_t HISR_TEIF6 = 0x80000;      // Stream x transfer error interrupt flag (x=7..4)
    static constexpr uint32_t HISR_DMEIF6 = 0x40000;     // Stream x direct mode error interrupt flag (x=7..4)
    static constexpr uint32_t HISR_FEIF6 = 0x10000;      // Stream x FIFO error interrupt flag (x=7..4)
    static constexpr uint32_t HISR_TCIF5 = 0x800;        // Stream x transfer complete interrupt flag (x=7..4)
    static constexpr uint32_t HISR_HTIF5 = 0x400;        // Stream x half transfer interrupt flag (x=7..4)
    static constexpr uint32_t HISR_TEIF5 = 0x200;        // Stream x transfer error interrupt flag (x=7..4)
    static constexpr uint32_t HISR_DMEIF5 = 0x100;       // Stream x direct mode error interrupt flag (x=7..4)
    static constexpr uint32_t HISR_FEIF5 = 0x40;         // Stream x FIFO error interrupt flag (x=7..4)
    static constexpr uint32_t HISR_TCIF4 = 0x20;         // Stream x transfer complete interrupt flag (x=7..4)
    static constexpr uint32_t HISR_HTIF4 = 0x10;         // Stream x half transfer interrupt flag (x=7..4)
    static constexpr uint32_t HISR_TEIF4 = 0x8;          // Stream x transfer error interrupt flag (x=7..4)
    static constexpr uint32_t HISR_DMEIF4 = 0x4;         // Stream x direct mode error interrupt flag (x=7..4)
    static constexpr uint32_t HISR_FEIF4 = 0x1;          // Stream x FIFO error interrupt flag (x=7..4)
    static const uint32_t HISR_RESET_VALUE = 0x0;

    static constexpr uint32_t LIFCR_CTCIF3 = 0x8000000;   // Stream x clear transfer complete interrupt flag (x = 3..0)
    static constexpr uint32_t LIFCR_CHTIF3 = 0x4000000;   // Stream x clear half transfer interrupt flag (x = 3..0)
    static constexpr uint32_t LIFCR_CTEIF3 = 0x2000000;   // Stream x clear transfer error interrupt flag (x = 3..0)
    static constexpr uint32_t LIFCR_CDMEIF3 = 0x1000000;  // Stream x clear direct mode error interrupt flag (x = 3..0)
    static constexpr uint32_t LIFCR_CFEIF3 = 0x400000;    // Stream x clear FIFO error interrupt flag (x = 3..0)
    static constexpr uint32_t LIFCR_CTCIF2 = 0x200000;    // Stream x clear transfer complete interrupt flag (x = 3..0)
    static constexpr uint32_t LIFCR_CHTIF2 = 0x100000;    // Stream x clear half transfer interrupt flag (x = 3..0)
    static constexpr uint32_t LIFCR_CTEIF2 = 0x80000;     // Stream x clear transfer error interrupt flag (x = 3..0)
    static constexpr uint32_t LIFCR_CDMEIF2 = 0x40000;    // Stream x clear direct mode error interrupt flag (x = 3..0)
    static constexpr uint32_t LIFCR_CFEIF2 = 0x10000;     // Stream x clear FIFO error interrupt flag (x = 3..0)
    static constexpr uint32_t LIFCR_CTCIF1 = 0x800;       // Stream x clear transfer complete interrupt flag (x = 3..0)
    static constexpr uint32_t LIFCR_CHTIF1 = 0x400;       // Stream x clear half transfer interrupt flag (x = 3..0)
    static constexpr uint32_t LIFCR_CTEIF1 = 0x200;       // Stream x clear transfer error interrupt flag (x = 3..0)
    static constexpr uint32_t LIFCR_CDMEIF1 = 0x100;      // Stream x clear direct mode error interrupt flag (x = 3..0)
    static constexpr uint32_t LIFCR_CFEIF1 = 0x40;        // Stream x clear FIFO error interrupt flag (x = 3..0)
    static constexpr uint32_t LIFCR_CTCIF0 = 0x20;        // Stream x clear transfer complete interrupt flag (x = 3..0)
    static constexpr uint32_t LIFCR_CHTIF0 = 0x10;        // Stream x clear half transfer interrupt flag (x = 3..0)
    static constexpr uint32_t LIFCR_CTEIF0 = 0x8;         // Stream x clear transfer error interrupt flag (x = 3..0)
    static constexpr uint32_t LIFCR_CDMEIF0 = 0x4;        // Stream x clear direct mode error interrupt flag (x = 3..0)
    static constexpr uint32_t LIFCR_CFEIF0 = 0x1;         // Stream x clear FIFO error interrupt flag (x = 3..0)
    static const uint32_t LIFCR_RESET_VALUE = 0x0;

    static constexpr uint32_t HIFCR_CTCIF7 = 0x8000000;   // Stream x clear transfer complete interrupt flag (x = 7..4)
    static constexpr uint32_t HIFCR_CHTIF7 = 0x4000000;   // Stream x clear half transfer interrupt flag (x = 7..4)
    static constexpr uint32_t HIFCR_CTEIF7 = 0x2000000;   // Stream x clear transfer error interrupt flag (x = 7..4)
    static constexpr uint32_t HIFCR_CDMEIF7 = 0x1000000;  // Stream x clear direct mode error interrupt flag (x = 7..4)
    static constexpr uint32_t HIFCR_CFEIF7 = 0x400000;    // Stream x clear FIFO error interrupt flag (x = 7..4)
    static constexpr uint32_t HIFCR_CTCIF6 = 0x200000;    // Stream x clear transfer complete interrupt flag (x = 7..4)
    static constexpr uint32_t HIFCR_CHTIF6 = 0x100000;    // Stream x clear half transfer interrupt flag (x = 7..4)
    static constexpr uint32_t HIFCR_CTEIF6 = 0x80000;     // Stream x clear transfer error interrupt flag (x = 7..4)
    static constexpr uint32_t HIFCR_CDMEIF6 = 0x40000;    // Stream x clear direct mode error interrupt flag (x = 7..4)
    static constexpr uint32_t HIFCR_CFEIF6 = 0x10000;     // Stream x clear FIFO error interrupt flag (x = 7..4)
    static constexpr uint32_t HIFCR_CTCIF5 = 0x800;       // Stream x clear transfer complete interrupt flag (x = 7..4)
    static constexpr uint32_t HIFCR_CHTIF5 = 0x400;       // Stream x clear half transfer interrupt flag (x = 7..4)
    static constexpr uint32_t HIFCR_CTEIF5 = 0x200;       // Stream x clear transfer error interrupt flag (x = 7..4)
    static constexpr uint32_t HIFCR_CDMEIF5 = 0x100;      // Stream x clear direct mode error interrupt flag (x = 7..4)
    static constexpr uint32_t HIFCR_CFEIF5 = 0x40;        // Stream x clear FIFO error interrupt flag (x = 7..4)
    static constexpr uint32_t HIFCR_CTCIF4 = 0x20;        // Stream x clear transfer complete interrupt flag (x = 7..4)
    static constexpr uint32_t HIFCR_CHTIF4 = 0x10;        // Stream x clear half transfer interrupt flag (x = 7..4)
    static constexpr uint32_t HIFCR_CTEIF4 = 0x8;         // Stream x clear transfer error interrupt flag (x = 7..4)
    static constexpr uint32_t HIFCR_CDMEIF4 = 0x4;        // Stream x clear direct mode error interrupt flag (x = 7..4)
    static constexpr uint32_t HIFCR_CFEIF4 = 0x1;         // Stream x clear FIFO error interrupt flag (x = 7..4)
    static const uint32_t HIFCR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t S0CR_CHSEL =               // Channel selection (3 bits)
        bit_field_t<25, 0x7>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t S0CR_MBURST =              // Memory burst transfer configuration (2 bits)
        bit_field_t<23, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t S0CR_PBURST =              // Peripheral burst transfer configuration (2 bits)
        bit_field_t<21, 0x3>::value<X>();
    static constexpr uint32_t S0CR_CT = 0x80000;         // Current target (only in double buffer mode)
    static constexpr uint32_t S0CR_DBM = 0x40000;        // Double buffer mode
    template<uint32_t X>
    static constexpr uint32_t S0CR_PL =                  // Priority level (2 bits)
        bit_field_t<16, 0x3>::value<X>();
    static constexpr uint32_t S0CR_PINCOS = 0x8000;      // Peripheral increment offset size
    template<uint32_t X>
    static constexpr uint32_t S0CR_MSIZE =               // Memory data size (2 bits)
        bit_field_t<13, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t S0CR_PSIZE =               // Peripheral data size (2 bits)
        bit_field_t<11, 0x3>::value<X>();
    static constexpr uint32_t S0CR_MINC = 0x400;         // Memory increment mode
    static constexpr uint32_t S0CR_PINC = 0x200;         // Peripheral increment mode
    static constexpr uint32_t S0CR_CIRC = 0x100;         // Circular mode
    template<uint32_t X>
    static constexpr uint32_t S0CR_DIR =                 // Data transfer direction (2 bits)
        bit_field_t<6, 0x3>::value<X>();
    static constexpr uint32_t S0CR_PFCTRL = 0x20;        // Peripheral flow controller
    static constexpr uint32_t S0CR_TCIE = 0x10;          // Transfer complete interrupt enable
    static constexpr uint32_t S0CR_HTIE = 0x8;           // Half transfer interrupt enable
    static constexpr uint32_t S0CR_TEIE = 0x4;           // Transfer error interrupt enable
    static constexpr uint32_t S0CR_DMEIE = 0x2;          // Direct mode error interrupt enable
    static constexpr uint32_t S0CR_EN = 0x1;             // Stream enable / flag stream ready when read low
    static const uint32_t S0CR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t S0NDTR_NDT =                 // Number of data items to transfer (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t S0NDTR_RESET_VALUE = 0x0;


    static const uint32_t S0PAR_RESET_VALUE = 0x0;


    static const uint32_t S0M0AR_RESET_VALUE = 0x0;


    static const uint32_t S0M1AR_RESET_VALUE = 0x0;

    static constexpr uint32_t S0FCR_FEIE = 0x80;          // FIFO error interrupt enable, Read-write
    template<uint32_t X>
    static constexpr uint32_t S0FCR_FS =                  // FIFO status (3 bits), Read-only
        bit_field_t<3, 0x7>::value<X>();
    static constexpr uint32_t S0FCR_DMDIS = 0x4;          // Direct mode disable, Read-write
    template<uint32_t X>
    static constexpr uint32_t S0FCR_FTH =                 // FIFO threshold selection (2 bits), Read-write
        bit_field_t<0, 0x3>::value<X>();
    static const uint32_t S0FCR_RESET_VALUE = 0x21;

    template<uint32_t X>
    static constexpr uint32_t S1CR_CHSEL =               // Channel selection (3 bits)
        bit_field_t<25, 0x7>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t S1CR_MBURST =              // Memory burst transfer configuration (2 bits)
        bit_field_t<23, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t S1CR_PBURST =              // Peripheral burst transfer configuration (2 bits)
        bit_field_t<21, 0x3>::value<X>();
    static constexpr uint32_t S1CR_ACK = 0x100000;       // ACK
    static constexpr uint32_t S1CR_CT = 0x80000;         // Current target (only in double buffer mode)
    static constexpr uint32_t S1CR_DBM = 0x40000;        // Double buffer mode
    template<uint32_t X>
    static constexpr uint32_t S1CR_PL =                  // Priority level (2 bits)
        bit_field_t<16, 0x3>::value<X>();
    static constexpr uint32_t S1CR_PINCOS = 0x8000;      // Peripheral increment offset size
    template<uint32_t X>
    static constexpr uint32_t S1CR_MSIZE =               // Memory data size (2 bits)
        bit_field_t<13, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t S1CR_PSIZE =               // Peripheral data size (2 bits)
        bit_field_t<11, 0x3>::value<X>();
    static constexpr uint32_t S1CR_MINC = 0x400;         // Memory increment mode
    static constexpr uint32_t S1CR_PINC = 0x200;         // Peripheral increment mode
    static constexpr uint32_t S1CR_CIRC = 0x100;         // Circular mode
    template<uint32_t X>
    static constexpr uint32_t S1CR_DIR =                 // Data transfer direction (2 bits)
        bit_field_t<6, 0x3>::value<X>();
    static constexpr uint32_t S1CR_PFCTRL = 0x20;        // Peripheral flow controller
    static constexpr uint32_t S1CR_TCIE = 0x10;          // Transfer complete interrupt enable
    static constexpr uint32_t S1CR_HTIE = 0x8;           // Half transfer interrupt enable
    static constexpr uint32_t S1CR_TEIE = 0x4;           // Transfer error interrupt enable
    static constexpr uint32_t S1CR_DMEIE = 0x2;          // Direct mode error interrupt enable
    static constexpr uint32_t S1CR_EN = 0x1;             // Stream enable / flag stream ready when read low
    static const uint32_t S1CR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t S1NDTR_NDT =                 // Number of data items to transfer (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t S1NDTR_RESET_VALUE = 0x0;


    static const uint32_t S1PAR_RESET_VALUE = 0x0;


    static const uint32_t S1M0AR_RESET_VALUE = 0x0;


    static const uint32_t S1M1AR_RESET_VALUE = 0x0;

    static constexpr uint32_t S1FCR_FEIE = 0x80;          // FIFO error interrupt enable, Read-write
    template<uint32_t X>
    static constexpr uint32_t S1FCR_FS =                  // FIFO status (3 bits), Read-only
        bit_field_t<3, 0x7>::value<X>();
    static constexpr uint32_t S1FCR_DMDIS = 0x4;          // Direct mode disable, Read-write
    template<uint32_t X>
    static constexpr uint32_t S1FCR_FTH =                 // FIFO threshold selection (2 bits), Read-write
        bit_field_t<0, 0x3>::value<X>();
    static const uint32_t S1FCR_RESET_VALUE = 0x21;

    template<uint32_t X>
    static constexpr uint32_t S2CR_CHSEL =               // Channel selection (3 bits)
        bit_field_t<25, 0x7>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t S2CR_MBURST =              // Memory burst transfer configuration (2 bits)
        bit_field_t<23, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t S2CR_PBURST =              // Peripheral burst transfer configuration (2 bits)
        bit_field_t<21, 0x3>::value<X>();
    static constexpr uint32_t S2CR_ACK = 0x100000;       // ACK
    static constexpr uint32_t S2CR_CT = 0x80000;         // Current target (only in double buffer mode)
    static constexpr uint32_t S2CR_DBM = 0x40000;        // Double buffer mode
    template<uint32_t X>
    static constexpr uint32_t S2CR_PL =                  // Priority level (2 bits)
        bit_field_t<16, 0x3>::value<X>();
    static constexpr uint32_t S2CR_PINCOS = 0x8000;      // Peripheral increment offset size
    template<uint32_t X>
    static constexpr uint32_t S2CR_MSIZE =               // Memory data size (2 bits)
        bit_field_t<13, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t S2CR_PSIZE =               // Peripheral data size (2 bits)
        bit_field_t<11, 0x3>::value<X>();
    static constexpr uint32_t S2CR_MINC = 0x400;         // Memory increment mode
    static constexpr uint32_t S2CR_PINC = 0x200;         // Peripheral increment mode
    static constexpr uint32_t S2CR_CIRC = 0x100;         // Circular mode
    template<uint32_t X>
    static constexpr uint32_t S2CR_DIR =                 // Data transfer direction (2 bits)
        bit_field_t<6, 0x3>::value<X>();
    static constexpr uint32_t S2CR_PFCTRL = 0x20;        // Peripheral flow controller
    static constexpr uint32_t S2CR_TCIE = 0x10;          // Transfer complete interrupt enable
    static constexpr uint32_t S2CR_HTIE = 0x8;           // Half transfer interrupt enable
    static constexpr uint32_t S2CR_TEIE = 0x4;           // Transfer error interrupt enable
    static constexpr uint32_t S2CR_DMEIE = 0x2;          // Direct mode error interrupt enable
    static constexpr uint32_t S2CR_EN = 0x1;             // Stream enable / flag stream ready when read low
    static const uint32_t S2CR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t S2NDTR_NDT =                 // Number of data items to transfer (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t S2NDTR_RESET_VALUE = 0x0;


    static const uint32_t S2PAR_RESET_VALUE = 0x0;


    static const uint32_t S2M0AR_RESET_VALUE = 0x0;


    static const uint32_t S2M1AR_RESET_VALUE = 0x0;

    static constexpr uint32_t S2FCR_FEIE = 0x80;          // FIFO error interrupt enable, Read-write
    template<uint32_t X>
    static constexpr uint32_t S2FCR_FS =                  // FIFO status (3 bits), Read-only
        bit_field_t<3, 0x7>::value<X>();
    static constexpr uint32_t S2FCR_DMDIS = 0x4;          // Direct mode disable, Read-write
    template<uint32_t X>
    static constexpr uint32_t S2FCR_FTH =                 // FIFO threshold selection (2 bits), Read-write
        bit_field_t<0, 0x3>::value<X>();
    static const uint32_t S2FCR_RESET_VALUE = 0x21;

    template<uint32_t X>
    static constexpr uint32_t S3CR_CHSEL =               // Channel selection (3 bits)
        bit_field_t<25, 0x7>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t S3CR_MBURST =              // Memory burst transfer configuration (2 bits)
        bit_field_t<23, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t S3CR_PBURST =              // Peripheral burst transfer configuration (2 bits)
        bit_field_t<21, 0x3>::value<X>();
    static constexpr uint32_t S3CR_ACK = 0x100000;       // ACK
    static constexpr uint32_t S3CR_CT = 0x80000;         // Current target (only in double buffer mode)
    static constexpr uint32_t S3CR_DBM = 0x40000;        // Double buffer mode
    template<uint32_t X>
    static constexpr uint32_t S3CR_PL =                  // Priority level (2 bits)
        bit_field_t<16, 0x3>::value<X>();
    static constexpr uint32_t S3CR_PINCOS = 0x8000;      // Peripheral increment offset size
    template<uint32_t X>
    static constexpr uint32_t S3CR_MSIZE =               // Memory data size (2 bits)
        bit_field_t<13, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t S3CR_PSIZE =               // Peripheral data size (2 bits)
        bit_field_t<11, 0x3>::value<X>();
    static constexpr uint32_t S3CR_MINC = 0x400;         // Memory increment mode
    static constexpr uint32_t S3CR_PINC = 0x200;         // Peripheral increment mode
    static constexpr uint32_t S3CR_CIRC = 0x100;         // Circular mode
    template<uint32_t X>
    static constexpr uint32_t S3CR_DIR =                 // Data transfer direction (2 bits)
        bit_field_t<6, 0x3>::value<X>();
    static constexpr uint32_t S3CR_PFCTRL = 0x20;        // Peripheral flow controller
    static constexpr uint32_t S3CR_TCIE = 0x10;          // Transfer complete interrupt enable
    static constexpr uint32_t S3CR_HTIE = 0x8;           // Half transfer interrupt enable
    static constexpr uint32_t S3CR_TEIE = 0x4;           // Transfer error interrupt enable
    static constexpr uint32_t S3CR_DMEIE = 0x2;          // Direct mode error interrupt enable
    static constexpr uint32_t S3CR_EN = 0x1;             // Stream enable / flag stream ready when read low
    static const uint32_t S3CR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t S3NDTR_NDT =                 // Number of data items to transfer (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t S3NDTR_RESET_VALUE = 0x0;


    static const uint32_t S3PAR_RESET_VALUE = 0x0;


    static const uint32_t S3M0AR_RESET_VALUE = 0x0;


    static const uint32_t S3M1AR_RESET_VALUE = 0x0;

    static constexpr uint32_t S3FCR_FEIE = 0x80;          // FIFO error interrupt enable, Read-write
    template<uint32_t X>
    static constexpr uint32_t S3FCR_FS =                  // FIFO status (3 bits), Read-only
        bit_field_t<3, 0x7>::value<X>();
    static constexpr uint32_t S3FCR_DMDIS = 0x4;          // Direct mode disable, Read-write
    template<uint32_t X>
    static constexpr uint32_t S3FCR_FTH =                 // FIFO threshold selection (2 bits), Read-write
        bit_field_t<0, 0x3>::value<X>();
    static const uint32_t S3FCR_RESET_VALUE = 0x21;

    template<uint32_t X>
    static constexpr uint32_t S4CR_CHSEL =               // Channel selection (3 bits)
        bit_field_t<25, 0x7>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t S4CR_MBURST =              // Memory burst transfer configuration (2 bits)
        bit_field_t<23, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t S4CR_PBURST =              // Peripheral burst transfer configuration (2 bits)
        bit_field_t<21, 0x3>::value<X>();
    static constexpr uint32_t S4CR_ACK = 0x100000;       // ACK
    static constexpr uint32_t S4CR_CT = 0x80000;         // Current target (only in double buffer mode)
    static constexpr uint32_t S4CR_DBM = 0x40000;        // Double buffer mode
    template<uint32_t X>
    static constexpr uint32_t S4CR_PL =                  // Priority level (2 bits)
        bit_field_t<16, 0x3>::value<X>();
    static constexpr uint32_t S4CR_PINCOS = 0x8000;      // Peripheral increment offset size
    template<uint32_t X>
    static constexpr uint32_t S4CR_MSIZE =               // Memory data size (2 bits)
        bit_field_t<13, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t S4CR_PSIZE =               // Peripheral data size (2 bits)
        bit_field_t<11, 0x3>::value<X>();
    static constexpr uint32_t S4CR_MINC = 0x400;         // Memory increment mode
    static constexpr uint32_t S4CR_PINC = 0x200;         // Peripheral increment mode
    static constexpr uint32_t S4CR_CIRC = 0x100;         // Circular mode
    template<uint32_t X>
    static constexpr uint32_t S4CR_DIR =                 // Data transfer direction (2 bits)
        bit_field_t<6, 0x3>::value<X>();
    static constexpr uint32_t S4CR_PFCTRL = 0x20;        // Peripheral flow controller
    static constexpr uint32_t S4CR_TCIE = 0x10;          // Transfer complete interrupt enable
    static constexpr uint32_t S4CR_HTIE = 0x8;           // Half transfer interrupt enable
    static constexpr uint32_t S4CR_TEIE = 0x4;           // Transfer error interrupt enable
    static constexpr uint32_t S4CR_DMEIE = 0x2;          // Direct mode error interrupt enable
    static constexpr uint32_t S4CR_EN = 0x1;             // Stream enable / flag stream ready when read low
    static const uint32_t S4CR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t S4NDTR_NDT =                 // Number of data items to transfer (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t S4NDTR_RESET_VALUE = 0x0;


    static const uint32_t S4PAR_RESET_VALUE = 0x0;


    static const uint32_t S4M0AR_RESET_VALUE = 0x0;


    static const uint32_t S4M1AR_RESET_VALUE = 0x0;

    static constexpr uint32_t S4FCR_FEIE = 0x80;          // FIFO error interrupt enable, Read-write
    template<uint32_t X>
    static constexpr uint32_t S4FCR_FS =                  // FIFO status (3 bits), Read-only
        bit_field_t<3, 0x7>::value<X>();
    static constexpr uint32_t S4FCR_DMDIS = 0x4;          // Direct mode disable, Read-write
    template<uint32_t X>
    static constexpr uint32_t S4FCR_FTH =                 // FIFO threshold selection (2 bits), Read-write
        bit_field_t<0, 0x3>::value<X>();
    static const uint32_t S4FCR_RESET_VALUE = 0x21;

    template<uint32_t X>
    static constexpr uint32_t S5CR_CHSEL =               // Channel selection (3 bits)
        bit_field_t<25, 0x7>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t S5CR_MBURST =              // Memory burst transfer configuration (2 bits)
        bit_field_t<23, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t S5CR_PBURST =              // Peripheral burst transfer configuration (2 bits)
        bit_field_t<21, 0x3>::value<X>();
    static constexpr uint32_t S5CR_ACK = 0x100000;       // ACK
    static constexpr uint32_t S5CR_CT = 0x80000;         // Current target (only in double buffer mode)
    static constexpr uint32_t S5CR_DBM = 0x40000;        // Double buffer mode
    template<uint32_t X>
    static constexpr uint32_t S5CR_PL =                  // Priority level (2 bits)
        bit_field_t<16, 0x3>::value<X>();
    static constexpr uint32_t S5CR_PINCOS = 0x8000;      // Peripheral increment offset size
    template<uint32_t X>
    static constexpr uint32_t S5CR_MSIZE =               // Memory data size (2 bits)
        bit_field_t<13, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t S5CR_PSIZE =               // Peripheral data size (2 bits)
        bit_field_t<11, 0x3>::value<X>();
    static constexpr uint32_t S5CR_MINC = 0x400;         // Memory increment mode
    static constexpr uint32_t S5CR_PINC = 0x200;         // Peripheral increment mode
    static constexpr uint32_t S5CR_CIRC = 0x100;         // Circular mode
    template<uint32_t X>
    static constexpr uint32_t S5CR_DIR =                 // Data transfer direction (2 bits)
        bit_field_t<6, 0x3>::value<X>();
    static constexpr uint32_t S5CR_PFCTRL = 0x20;        // Peripheral flow controller
    static constexpr uint32_t S5CR_TCIE = 0x10;          // Transfer complete interrupt enable
    static constexpr uint32_t S5CR_HTIE = 0x8;           // Half transfer interrupt enable
    static constexpr uint32_t S5CR_TEIE = 0x4;           // Transfer error interrupt enable
    static constexpr uint32_t S5CR_DMEIE = 0x2;          // Direct mode error interrupt enable
    static constexpr uint32_t S5CR_EN = 0x1;             // Stream enable / flag stream ready when read low
    static const uint32_t S5CR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t S5NDTR_NDT =                 // Number of data items to transfer (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t S5NDTR_RESET_VALUE = 0x0;


    static const uint32_t S5PAR_RESET_VALUE = 0x0;


    static const uint32_t S5M0AR_RESET_VALUE = 0x0;


    static const uint32_t S5M1AR_RESET_VALUE = 0x0;

    static constexpr uint32_t S5FCR_FEIE = 0x80;          // FIFO error interrupt enable, Read-write
    template<uint32_t X>
    static constexpr uint32_t S5FCR_FS =                  // FIFO status (3 bits), Read-only
        bit_field_t<3, 0x7>::value<X>();
    static constexpr uint32_t S5FCR_DMDIS = 0x4;          // Direct mode disable, Read-write
    template<uint32_t X>
    static constexpr uint32_t S5FCR_FTH =                 // FIFO threshold selection (2 bits), Read-write
        bit_field_t<0, 0x3>::value<X>();
    static const uint32_t S5FCR_RESET_VALUE = 0x21;

    template<uint32_t X>
    static constexpr uint32_t S6CR_CHSEL =               // Channel selection (3 bits)
        bit_field_t<25, 0x7>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t S6CR_MBURST =              // Memory burst transfer configuration (2 bits)
        bit_field_t<23, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t S6CR_PBURST =              // Peripheral burst transfer configuration (2 bits)
        bit_field_t<21, 0x3>::value<X>();
    static constexpr uint32_t S6CR_ACK = 0x100000;       // ACK
    static constexpr uint32_t S6CR_CT = 0x80000;         // Current target (only in double buffer mode)
    static constexpr uint32_t S6CR_DBM = 0x40000;        // Double buffer mode
    template<uint32_t X>
    static constexpr uint32_t S6CR_PL =                  // Priority level (2 bits)
        bit_field_t<16, 0x3>::value<X>();
    static constexpr uint32_t S6CR_PINCOS = 0x8000;      // Peripheral increment offset size
    template<uint32_t X>
    static constexpr uint32_t S6CR_MSIZE =               // Memory data size (2 bits)
        bit_field_t<13, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t S6CR_PSIZE =               // Peripheral data size (2 bits)
        bit_field_t<11, 0x3>::value<X>();
    static constexpr uint32_t S6CR_MINC = 0x400;         // Memory increment mode
    static constexpr uint32_t S6CR_PINC = 0x200;         // Peripheral increment mode
    static constexpr uint32_t S6CR_CIRC = 0x100;         // Circular mode
    template<uint32_t X>
    static constexpr uint32_t S6CR_DIR =                 // Data transfer direction (2 bits)
        bit_field_t<6, 0x3>::value<X>();
    static constexpr uint32_t S6CR_PFCTRL = 0x20;        // Peripheral flow controller
    static constexpr uint32_t S6CR_TCIE = 0x10;          // Transfer complete interrupt enable
    static constexpr uint32_t S6CR_HTIE = 0x8;           // Half transfer interrupt enable
    static constexpr uint32_t S6CR_TEIE = 0x4;           // Transfer error interrupt enable
    static constexpr uint32_t S6CR_DMEIE = 0x2;          // Direct mode error interrupt enable
    static constexpr uint32_t S6CR_EN = 0x1;             // Stream enable / flag stream ready when read low
    static const uint32_t S6CR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t S6NDTR_NDT =                 // Number of data items to transfer (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t S6NDTR_RESET_VALUE = 0x0;


    static const uint32_t S6PAR_RESET_VALUE = 0x0;


    static const uint32_t S6M0AR_RESET_VALUE = 0x0;


    static const uint32_t S6M1AR_RESET_VALUE = 0x0;

    static constexpr uint32_t S6FCR_FEIE = 0x80;          // FIFO error interrupt enable, Read-write
    template<uint32_t X>
    static constexpr uint32_t S6FCR_FS =                  // FIFO status (3 bits), Read-only
        bit_field_t<3, 0x7>::value<X>();
    static constexpr uint32_t S6FCR_DMDIS = 0x4;          // Direct mode disable, Read-write
    template<uint32_t X>
    static constexpr uint32_t S6FCR_FTH =                 // FIFO threshold selection (2 bits), Read-write
        bit_field_t<0, 0x3>::value<X>();
    static const uint32_t S6FCR_RESET_VALUE = 0x21;

    template<uint32_t X>
    static constexpr uint32_t S7CR_CHSEL =               // Channel selection (3 bits)
        bit_field_t<25, 0x7>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t S7CR_MBURST =              // Memory burst transfer configuration (2 bits)
        bit_field_t<23, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t S7CR_PBURST =              // Peripheral burst transfer configuration (2 bits)
        bit_field_t<21, 0x3>::value<X>();
    static constexpr uint32_t S7CR_ACK = 0x100000;       // ACK
    static constexpr uint32_t S7CR_CT = 0x80000;         // Current target (only in double buffer mode)
    static constexpr uint32_t S7CR_DBM = 0x40000;        // Double buffer mode
    template<uint32_t X>
    static constexpr uint32_t S7CR_PL =                  // Priority level (2 bits)
        bit_field_t<16, 0x3>::value<X>();
    static constexpr uint32_t S7CR_PINCOS = 0x8000;      // Peripheral increment offset size
    template<uint32_t X>
    static constexpr uint32_t S7CR_MSIZE =               // Memory data size (2 bits)
        bit_field_t<13, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t S7CR_PSIZE =               // Peripheral data size (2 bits)
        bit_field_t<11, 0x3>::value<X>();
    static constexpr uint32_t S7CR_MINC = 0x400;         // Memory increment mode
    static constexpr uint32_t S7CR_PINC = 0x200;         // Peripheral increment mode
    static constexpr uint32_t S7CR_CIRC = 0x100;         // Circular mode
    template<uint32_t X>
    static constexpr uint32_t S7CR_DIR =                 // Data transfer direction (2 bits)
        bit_field_t<6, 0x3>::value<X>();
    static constexpr uint32_t S7CR_PFCTRL = 0x20;        // Peripheral flow controller
    static constexpr uint32_t S7CR_TCIE = 0x10;          // Transfer complete interrupt enable
    static constexpr uint32_t S7CR_HTIE = 0x8;           // Half transfer interrupt enable
    static constexpr uint32_t S7CR_TEIE = 0x4;           // Transfer error interrupt enable
    static constexpr uint32_t S7CR_DMEIE = 0x2;          // Direct mode error interrupt enable
    static constexpr uint32_t S7CR_EN = 0x1;             // Stream enable / flag stream ready when read low
    static const uint32_t S7CR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t S7NDTR_NDT =                 // Number of data items to transfer (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t S7NDTR_RESET_VALUE = 0x0;


    static const uint32_t S7PAR_RESET_VALUE = 0x0;


    static const uint32_t S7M0AR_RESET_VALUE = 0x0;


    static const uint32_t S7M1AR_RESET_VALUE = 0x0;

    static constexpr uint32_t S7FCR_FEIE = 0x80;          // FIFO error interrupt enable, Read-write
    template<uint32_t X>
    static constexpr uint32_t S7FCR_FS =                  // FIFO status (3 bits), Read-only
        bit_field_t<3, 0x7>::value<X>();
    static constexpr uint32_t S7FCR_DMDIS = 0x4;          // Direct mode disable, Read-write
    template<uint32_t X>
    static constexpr uint32_t S7FCR_FTH =                 // FIFO threshold selection (2 bits), Read-write
        bit_field_t<0, 0x3>::value<X>();
    static const uint32_t S7FCR_RESET_VALUE = 0x21;

    static constexpr uint8_t RCC = 5; // RCC global interrupt
};

static dma2_t& DMA2 = *reinterpret_cast<dma2_t*>(0x40026400);

#define HAVE_PERIPHERAL_DMA2


////
//
//    DMA controller
//
////

struct dma1_t
{
    volatile uint32_t    LISR;                 // [Read-only] low interrupt status register
    volatile uint32_t    HISR;                 // [Read-only] high interrupt status register
    volatile uint32_t    LIFCR;                // [Write-only] low interrupt flag clear register
    volatile uint32_t    HIFCR;                // [Write-only] high interrupt flag clear register
    volatile uint32_t    S0CR;                 // [Read-write] stream x configuration register
    volatile uint32_t    S0NDTR;               // [Read-write] stream x number of data register
    volatile uint32_t    S0PAR;                // [Read-write] stream x peripheral address register
    volatile uint32_t    S0M0AR;               // [Read-write] stream x memory 0 address register
    volatile uint32_t    S0M1AR;               // [Read-write] stream x memory 1 address register
    volatile uint32_t    S0FCR;                // stream x FIFO control register
    volatile uint32_t    S1CR;                 // [Read-write] stream x configuration register
    volatile uint32_t    S1NDTR;               // [Read-write] stream x number of data register
    volatile uint32_t    S1PAR;                // [Read-write] stream x peripheral address register
    volatile uint32_t    S1M0AR;               // [Read-write] stream x memory 0 address register
    volatile uint32_t    S1M1AR;               // [Read-write] stream x memory 1 address register
    volatile uint32_t    S1FCR;                // stream x FIFO control register
    volatile uint32_t    S2CR;                 // [Read-write] stream x configuration register
    volatile uint32_t    S2NDTR;               // [Read-write] stream x number of data register
    volatile uint32_t    S2PAR;                // [Read-write] stream x peripheral address register
    volatile uint32_t    S2M0AR;               // [Read-write] stream x memory 0 address register
    volatile uint32_t    S2M1AR;               // [Read-write] stream x memory 1 address register
    volatile uint32_t    S2FCR;                // stream x FIFO control register
    volatile uint32_t    S3CR;                 // [Read-write] stream x configuration register
    volatile uint32_t    S3NDTR;               // [Read-write] stream x number of data register
    volatile uint32_t    S3PAR;                // [Read-write] stream x peripheral address register
    volatile uint32_t    S3M0AR;               // [Read-write] stream x memory 0 address register
    volatile uint32_t    S3M1AR;               // [Read-write] stream x memory 1 address register
    volatile uint32_t    S3FCR;                // stream x FIFO control register
    volatile uint32_t    S4CR;                 // [Read-write] stream x configuration register
    volatile uint32_t    S4NDTR;               // [Read-write] stream x number of data register
    volatile uint32_t    S4PAR;                // [Read-write] stream x peripheral address register
    volatile uint32_t    S4M0AR;               // [Read-write] stream x memory 0 address register
    volatile uint32_t    S4M1AR;               // [Read-write] stream x memory 1 address register
    volatile uint32_t    S4FCR;                // stream x FIFO control register
    volatile uint32_t    S5CR;                 // [Read-write] stream x configuration register
    volatile uint32_t    S5NDTR;               // [Read-write] stream x number of data register
    volatile uint32_t    S5PAR;                // [Read-write] stream x peripheral address register
    volatile uint32_t    S5M0AR;               // [Read-write] stream x memory 0 address register
    volatile uint32_t    S5M1AR;               // [Read-write] stream x memory 1 address register
    volatile uint32_t    S5FCR;                // stream x FIFO control register
    volatile uint32_t    S6CR;                 // [Read-write] stream x configuration register
    volatile uint32_t    S6NDTR;               // [Read-write] stream x number of data register
    volatile uint32_t    S6PAR;                // [Read-write] stream x peripheral address register
    volatile uint32_t    S6M0AR;               // [Read-write] stream x memory 0 address register
    volatile uint32_t    S6M1AR;               // [Read-write] stream x memory 1 address register
    volatile uint32_t    S6FCR;                // stream x FIFO control register
    volatile uint32_t    S7CR;                 // [Read-write] stream x configuration register
    volatile uint32_t    S7NDTR;               // [Read-write] stream x number of data register
    volatile uint32_t    S7PAR;                // [Read-write] stream x peripheral address register
    volatile uint32_t    S7M0AR;               // [Read-write] stream x memory 0 address register
    volatile uint32_t    S7M1AR;               // [Read-write] stream x memory 1 address register
    volatile uint32_t    S7FCR;                // stream x FIFO control register

    static constexpr uint32_t LISR_TCIF3 = 0x8000000;    // Stream x transfer complete interrupt flag (x = 3..0)
    static constexpr uint32_t LISR_HTIF3 = 0x4000000;    // Stream x half transfer interrupt flag (x=3..0)
    static constexpr uint32_t LISR_TEIF3 = 0x2000000;    // Stream x transfer error interrupt flag (x=3..0)
    static constexpr uint32_t LISR_DMEIF3 = 0x1000000;   // Stream x direct mode error interrupt flag (x=3..0)
    static constexpr uint32_t LISR_FEIF3 = 0x400000;     // Stream x FIFO error interrupt flag (x=3..0)
    static constexpr uint32_t LISR_TCIF2 = 0x200000;     // Stream x transfer complete interrupt flag (x = 3..0)
    static constexpr uint32_t LISR_HTIF2 = 0x100000;     // Stream x half transfer interrupt flag (x=3..0)
    static constexpr uint32_t LISR_TEIF2 = 0x80000;      // Stream x transfer error interrupt flag (x=3..0)
    static constexpr uint32_t LISR_DMEIF2 = 0x40000;     // Stream x direct mode error interrupt flag (x=3..0)
    static constexpr uint32_t LISR_FEIF2 = 0x10000;      // Stream x FIFO error interrupt flag (x=3..0)
    static constexpr uint32_t LISR_TCIF1 = 0x800;        // Stream x transfer complete interrupt flag (x = 3..0)
    static constexpr uint32_t LISR_HTIF1 = 0x400;        // Stream x half transfer interrupt flag (x=3..0)
    static constexpr uint32_t LISR_TEIF1 = 0x200;        // Stream x transfer error interrupt flag (x=3..0)
    static constexpr uint32_t LISR_DMEIF1 = 0x100;       // Stream x direct mode error interrupt flag (x=3..0)
    static constexpr uint32_t LISR_FEIF1 = 0x40;         // Stream x FIFO error interrupt flag (x=3..0)
    static constexpr uint32_t LISR_TCIF0 = 0x20;         // Stream x transfer complete interrupt flag (x = 3..0)
    static constexpr uint32_t LISR_HTIF0 = 0x10;         // Stream x half transfer interrupt flag (x=3..0)
    static constexpr uint32_t LISR_TEIF0 = 0x8;          // Stream x transfer error interrupt flag (x=3..0)
    static constexpr uint32_t LISR_DMEIF0 = 0x4;         // Stream x direct mode error interrupt flag (x=3..0)
    static constexpr uint32_t LISR_FEIF0 = 0x1;          // Stream x FIFO error interrupt flag (x=3..0)
    static const uint32_t LISR_RESET_VALUE = 0x0;

    static constexpr uint32_t HISR_TCIF7 = 0x8000000;    // Stream x transfer complete interrupt flag (x=7..4)
    static constexpr uint32_t HISR_HTIF7 = 0x4000000;    // Stream x half transfer interrupt flag (x=7..4)
    static constexpr uint32_t HISR_TEIF7 = 0x2000000;    // Stream x transfer error interrupt flag (x=7..4)
    static constexpr uint32_t HISR_DMEIF7 = 0x1000000;   // Stream x direct mode error interrupt flag (x=7..4)
    static constexpr uint32_t HISR_FEIF7 = 0x400000;     // Stream x FIFO error interrupt flag (x=7..4)
    static constexpr uint32_t HISR_TCIF6 = 0x200000;     // Stream x transfer complete interrupt flag (x=7..4)
    static constexpr uint32_t HISR_HTIF6 = 0x100000;     // Stream x half transfer interrupt flag (x=7..4)
    static constexpr uint32_t HISR_TEIF6 = 0x80000;      // Stream x transfer error interrupt flag (x=7..4)
    static constexpr uint32_t HISR_DMEIF6 = 0x40000;     // Stream x direct mode error interrupt flag (x=7..4)
    static constexpr uint32_t HISR_FEIF6 = 0x10000;      // Stream x FIFO error interrupt flag (x=7..4)
    static constexpr uint32_t HISR_TCIF5 = 0x800;        // Stream x transfer complete interrupt flag (x=7..4)
    static constexpr uint32_t HISR_HTIF5 = 0x400;        // Stream x half transfer interrupt flag (x=7..4)
    static constexpr uint32_t HISR_TEIF5 = 0x200;        // Stream x transfer error interrupt flag (x=7..4)
    static constexpr uint32_t HISR_DMEIF5 = 0x100;       // Stream x direct mode error interrupt flag (x=7..4)
    static constexpr uint32_t HISR_FEIF5 = 0x40;         // Stream x FIFO error interrupt flag (x=7..4)
    static constexpr uint32_t HISR_TCIF4 = 0x20;         // Stream x transfer complete interrupt flag (x=7..4)
    static constexpr uint32_t HISR_HTIF4 = 0x10;         // Stream x half transfer interrupt flag (x=7..4)
    static constexpr uint32_t HISR_TEIF4 = 0x8;          // Stream x transfer error interrupt flag (x=7..4)
    static constexpr uint32_t HISR_DMEIF4 = 0x4;         // Stream x direct mode error interrupt flag (x=7..4)
    static constexpr uint32_t HISR_FEIF4 = 0x1;          // Stream x FIFO error interrupt flag (x=7..4)
    static const uint32_t HISR_RESET_VALUE = 0x0;

    static constexpr uint32_t LIFCR_CTCIF3 = 0x8000000;   // Stream x clear transfer complete interrupt flag (x = 3..0)
    static constexpr uint32_t LIFCR_CHTIF3 = 0x4000000;   // Stream x clear half transfer interrupt flag (x = 3..0)
    static constexpr uint32_t LIFCR_CTEIF3 = 0x2000000;   // Stream x clear transfer error interrupt flag (x = 3..0)
    static constexpr uint32_t LIFCR_CDMEIF3 = 0x1000000;  // Stream x clear direct mode error interrupt flag (x = 3..0)
    static constexpr uint32_t LIFCR_CFEIF3 = 0x400000;    // Stream x clear FIFO error interrupt flag (x = 3..0)
    static constexpr uint32_t LIFCR_CTCIF2 = 0x200000;    // Stream x clear transfer complete interrupt flag (x = 3..0)
    static constexpr uint32_t LIFCR_CHTIF2 = 0x100000;    // Stream x clear half transfer interrupt flag (x = 3..0)
    static constexpr uint32_t LIFCR_CTEIF2 = 0x80000;     // Stream x clear transfer error interrupt flag (x = 3..0)
    static constexpr uint32_t LIFCR_CDMEIF2 = 0x40000;    // Stream x clear direct mode error interrupt flag (x = 3..0)
    static constexpr uint32_t LIFCR_CFEIF2 = 0x10000;     // Stream x clear FIFO error interrupt flag (x = 3..0)
    static constexpr uint32_t LIFCR_CTCIF1 = 0x800;       // Stream x clear transfer complete interrupt flag (x = 3..0)
    static constexpr uint32_t LIFCR_CHTIF1 = 0x400;       // Stream x clear half transfer interrupt flag (x = 3..0)
    static constexpr uint32_t LIFCR_CTEIF1 = 0x200;       // Stream x clear transfer error interrupt flag (x = 3..0)
    static constexpr uint32_t LIFCR_CDMEIF1 = 0x100;      // Stream x clear direct mode error interrupt flag (x = 3..0)
    static constexpr uint32_t LIFCR_CFEIF1 = 0x40;        // Stream x clear FIFO error interrupt flag (x = 3..0)
    static constexpr uint32_t LIFCR_CTCIF0 = 0x20;        // Stream x clear transfer complete interrupt flag (x = 3..0)
    static constexpr uint32_t LIFCR_CHTIF0 = 0x10;        // Stream x clear half transfer interrupt flag (x = 3..0)
    static constexpr uint32_t LIFCR_CTEIF0 = 0x8;         // Stream x clear transfer error interrupt flag (x = 3..0)
    static constexpr uint32_t LIFCR_CDMEIF0 = 0x4;        // Stream x clear direct mode error interrupt flag (x = 3..0)
    static constexpr uint32_t LIFCR_CFEIF0 = 0x1;         // Stream x clear FIFO error interrupt flag (x = 3..0)
    static const uint32_t LIFCR_RESET_VALUE = 0x0;

    static constexpr uint32_t HIFCR_CTCIF7 = 0x8000000;   // Stream x clear transfer complete interrupt flag (x = 7..4)
    static constexpr uint32_t HIFCR_CHTIF7 = 0x4000000;   // Stream x clear half transfer interrupt flag (x = 7..4)
    static constexpr uint32_t HIFCR_CTEIF7 = 0x2000000;   // Stream x clear transfer error interrupt flag (x = 7..4)
    static constexpr uint32_t HIFCR_CDMEIF7 = 0x1000000;  // Stream x clear direct mode error interrupt flag (x = 7..4)
    static constexpr uint32_t HIFCR_CFEIF7 = 0x400000;    // Stream x clear FIFO error interrupt flag (x = 7..4)
    static constexpr uint32_t HIFCR_CTCIF6 = 0x200000;    // Stream x clear transfer complete interrupt flag (x = 7..4)
    static constexpr uint32_t HIFCR_CHTIF6 = 0x100000;    // Stream x clear half transfer interrupt flag (x = 7..4)
    static constexpr uint32_t HIFCR_CTEIF6 = 0x80000;     // Stream x clear transfer error interrupt flag (x = 7..4)
    static constexpr uint32_t HIFCR_CDMEIF6 = 0x40000;    // Stream x clear direct mode error interrupt flag (x = 7..4)
    static constexpr uint32_t HIFCR_CFEIF6 = 0x10000;     // Stream x clear FIFO error interrupt flag (x = 7..4)
    static constexpr uint32_t HIFCR_CTCIF5 = 0x800;       // Stream x clear transfer complete interrupt flag (x = 7..4)
    static constexpr uint32_t HIFCR_CHTIF5 = 0x400;       // Stream x clear half transfer interrupt flag (x = 7..4)
    static constexpr uint32_t HIFCR_CTEIF5 = 0x200;       // Stream x clear transfer error interrupt flag (x = 7..4)
    static constexpr uint32_t HIFCR_CDMEIF5 = 0x100;      // Stream x clear direct mode error interrupt flag (x = 7..4)
    static constexpr uint32_t HIFCR_CFEIF5 = 0x40;        // Stream x clear FIFO error interrupt flag (x = 7..4)
    static constexpr uint32_t HIFCR_CTCIF4 = 0x20;        // Stream x clear transfer complete interrupt flag (x = 7..4)
    static constexpr uint32_t HIFCR_CHTIF4 = 0x10;        // Stream x clear half transfer interrupt flag (x = 7..4)
    static constexpr uint32_t HIFCR_CTEIF4 = 0x8;         // Stream x clear transfer error interrupt flag (x = 7..4)
    static constexpr uint32_t HIFCR_CDMEIF4 = 0x4;        // Stream x clear direct mode error interrupt flag (x = 7..4)
    static constexpr uint32_t HIFCR_CFEIF4 = 0x1;         // Stream x clear FIFO error interrupt flag (x = 7..4)
    static const uint32_t HIFCR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t S0CR_CHSEL =               // Channel selection (3 bits)
        bit_field_t<25, 0x7>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t S0CR_MBURST =              // Memory burst transfer configuration (2 bits)
        bit_field_t<23, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t S0CR_PBURST =              // Peripheral burst transfer configuration (2 bits)
        bit_field_t<21, 0x3>::value<X>();
    static constexpr uint32_t S0CR_CT = 0x80000;         // Current target (only in double buffer mode)
    static constexpr uint32_t S0CR_DBM = 0x40000;        // Double buffer mode
    template<uint32_t X>
    static constexpr uint32_t S0CR_PL =                  // Priority level (2 bits)
        bit_field_t<16, 0x3>::value<X>();
    static constexpr uint32_t S0CR_PINCOS = 0x8000;      // Peripheral increment offset size
    template<uint32_t X>
    static constexpr uint32_t S0CR_MSIZE =               // Memory data size (2 bits)
        bit_field_t<13, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t S0CR_PSIZE =               // Peripheral data size (2 bits)
        bit_field_t<11, 0x3>::value<X>();
    static constexpr uint32_t S0CR_MINC = 0x400;         // Memory increment mode
    static constexpr uint32_t S0CR_PINC = 0x200;         // Peripheral increment mode
    static constexpr uint32_t S0CR_CIRC = 0x100;         // Circular mode
    template<uint32_t X>
    static constexpr uint32_t S0CR_DIR =                 // Data transfer direction (2 bits)
        bit_field_t<6, 0x3>::value<X>();
    static constexpr uint32_t S0CR_PFCTRL = 0x20;        // Peripheral flow controller
    static constexpr uint32_t S0CR_TCIE = 0x10;          // Transfer complete interrupt enable
    static constexpr uint32_t S0CR_HTIE = 0x8;           // Half transfer interrupt enable
    static constexpr uint32_t S0CR_TEIE = 0x4;           // Transfer error interrupt enable
    static constexpr uint32_t S0CR_DMEIE = 0x2;          // Direct mode error interrupt enable
    static constexpr uint32_t S0CR_EN = 0x1;             // Stream enable / flag stream ready when read low
    static const uint32_t S0CR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t S0NDTR_NDT =                 // Number of data items to transfer (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t S0NDTR_RESET_VALUE = 0x0;


    static const uint32_t S0PAR_RESET_VALUE = 0x0;


    static const uint32_t S0M0AR_RESET_VALUE = 0x0;


    static const uint32_t S0M1AR_RESET_VALUE = 0x0;

    static constexpr uint32_t S0FCR_FEIE = 0x80;          // FIFO error interrupt enable, Read-write
    template<uint32_t X>
    static constexpr uint32_t S0FCR_FS =                  // FIFO status (3 bits), Read-only
        bit_field_t<3, 0x7>::value<X>();
    static constexpr uint32_t S0FCR_DMDIS = 0x4;          // Direct mode disable, Read-write
    template<uint32_t X>
    static constexpr uint32_t S0FCR_FTH =                 // FIFO threshold selection (2 bits), Read-write
        bit_field_t<0, 0x3>::value<X>();
    static const uint32_t S0FCR_RESET_VALUE = 0x21;

    template<uint32_t X>
    static constexpr uint32_t S1CR_CHSEL =               // Channel selection (3 bits)
        bit_field_t<25, 0x7>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t S1CR_MBURST =              // Memory burst transfer configuration (2 bits)
        bit_field_t<23, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t S1CR_PBURST =              // Peripheral burst transfer configuration (2 bits)
        bit_field_t<21, 0x3>::value<X>();
    static constexpr uint32_t S1CR_ACK = 0x100000;       // ACK
    static constexpr uint32_t S1CR_CT = 0x80000;         // Current target (only in double buffer mode)
    static constexpr uint32_t S1CR_DBM = 0x40000;        // Double buffer mode
    template<uint32_t X>
    static constexpr uint32_t S1CR_PL =                  // Priority level (2 bits)
        bit_field_t<16, 0x3>::value<X>();
    static constexpr uint32_t S1CR_PINCOS = 0x8000;      // Peripheral increment offset size
    template<uint32_t X>
    static constexpr uint32_t S1CR_MSIZE =               // Memory data size (2 bits)
        bit_field_t<13, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t S1CR_PSIZE =               // Peripheral data size (2 bits)
        bit_field_t<11, 0x3>::value<X>();
    static constexpr uint32_t S1CR_MINC = 0x400;         // Memory increment mode
    static constexpr uint32_t S1CR_PINC = 0x200;         // Peripheral increment mode
    static constexpr uint32_t S1CR_CIRC = 0x100;         // Circular mode
    template<uint32_t X>
    static constexpr uint32_t S1CR_DIR =                 // Data transfer direction (2 bits)
        bit_field_t<6, 0x3>::value<X>();
    static constexpr uint32_t S1CR_PFCTRL = 0x20;        // Peripheral flow controller
    static constexpr uint32_t S1CR_TCIE = 0x10;          // Transfer complete interrupt enable
    static constexpr uint32_t S1CR_HTIE = 0x8;           // Half transfer interrupt enable
    static constexpr uint32_t S1CR_TEIE = 0x4;           // Transfer error interrupt enable
    static constexpr uint32_t S1CR_DMEIE = 0x2;          // Direct mode error interrupt enable
    static constexpr uint32_t S1CR_EN = 0x1;             // Stream enable / flag stream ready when read low
    static const uint32_t S1CR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t S1NDTR_NDT =                 // Number of data items to transfer (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t S1NDTR_RESET_VALUE = 0x0;


    static const uint32_t S1PAR_RESET_VALUE = 0x0;


    static const uint32_t S1M0AR_RESET_VALUE = 0x0;


    static const uint32_t S1M1AR_RESET_VALUE = 0x0;

    static constexpr uint32_t S1FCR_FEIE = 0x80;          // FIFO error interrupt enable, Read-write
    template<uint32_t X>
    static constexpr uint32_t S1FCR_FS =                  // FIFO status (3 bits), Read-only
        bit_field_t<3, 0x7>::value<X>();
    static constexpr uint32_t S1FCR_DMDIS = 0x4;          // Direct mode disable, Read-write
    template<uint32_t X>
    static constexpr uint32_t S1FCR_FTH =                 // FIFO threshold selection (2 bits), Read-write
        bit_field_t<0, 0x3>::value<X>();
    static const uint32_t S1FCR_RESET_VALUE = 0x21;

    template<uint32_t X>
    static constexpr uint32_t S2CR_CHSEL =               // Channel selection (3 bits)
        bit_field_t<25, 0x7>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t S2CR_MBURST =              // Memory burst transfer configuration (2 bits)
        bit_field_t<23, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t S2CR_PBURST =              // Peripheral burst transfer configuration (2 bits)
        bit_field_t<21, 0x3>::value<X>();
    static constexpr uint32_t S2CR_ACK = 0x100000;       // ACK
    static constexpr uint32_t S2CR_CT = 0x80000;         // Current target (only in double buffer mode)
    static constexpr uint32_t S2CR_DBM = 0x40000;        // Double buffer mode
    template<uint32_t X>
    static constexpr uint32_t S2CR_PL =                  // Priority level (2 bits)
        bit_field_t<16, 0x3>::value<X>();
    static constexpr uint32_t S2CR_PINCOS = 0x8000;      // Peripheral increment offset size
    template<uint32_t X>
    static constexpr uint32_t S2CR_MSIZE =               // Memory data size (2 bits)
        bit_field_t<13, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t S2CR_PSIZE =               // Peripheral data size (2 bits)
        bit_field_t<11, 0x3>::value<X>();
    static constexpr uint32_t S2CR_MINC = 0x400;         // Memory increment mode
    static constexpr uint32_t S2CR_PINC = 0x200;         // Peripheral increment mode
    static constexpr uint32_t S2CR_CIRC = 0x100;         // Circular mode
    template<uint32_t X>
    static constexpr uint32_t S2CR_DIR =                 // Data transfer direction (2 bits)
        bit_field_t<6, 0x3>::value<X>();
    static constexpr uint32_t S2CR_PFCTRL = 0x20;        // Peripheral flow controller
    static constexpr uint32_t S2CR_TCIE = 0x10;          // Transfer complete interrupt enable
    static constexpr uint32_t S2CR_HTIE = 0x8;           // Half transfer interrupt enable
    static constexpr uint32_t S2CR_TEIE = 0x4;           // Transfer error interrupt enable
    static constexpr uint32_t S2CR_DMEIE = 0x2;          // Direct mode error interrupt enable
    static constexpr uint32_t S2CR_EN = 0x1;             // Stream enable / flag stream ready when read low
    static const uint32_t S2CR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t S2NDTR_NDT =                 // Number of data items to transfer (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t S2NDTR_RESET_VALUE = 0x0;


    static const uint32_t S2PAR_RESET_VALUE = 0x0;


    static const uint32_t S2M0AR_RESET_VALUE = 0x0;


    static const uint32_t S2M1AR_RESET_VALUE = 0x0;

    static constexpr uint32_t S2FCR_FEIE = 0x80;          // FIFO error interrupt enable, Read-write
    template<uint32_t X>
    static constexpr uint32_t S2FCR_FS =                  // FIFO status (3 bits), Read-only
        bit_field_t<3, 0x7>::value<X>();
    static constexpr uint32_t S2FCR_DMDIS = 0x4;          // Direct mode disable, Read-write
    template<uint32_t X>
    static constexpr uint32_t S2FCR_FTH =                 // FIFO threshold selection (2 bits), Read-write
        bit_field_t<0, 0x3>::value<X>();
    static const uint32_t S2FCR_RESET_VALUE = 0x21;

    template<uint32_t X>
    static constexpr uint32_t S3CR_CHSEL =               // Channel selection (3 bits)
        bit_field_t<25, 0x7>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t S3CR_MBURST =              // Memory burst transfer configuration (2 bits)
        bit_field_t<23, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t S3CR_PBURST =              // Peripheral burst transfer configuration (2 bits)
        bit_field_t<21, 0x3>::value<X>();
    static constexpr uint32_t S3CR_ACK = 0x100000;       // ACK
    static constexpr uint32_t S3CR_CT = 0x80000;         // Current target (only in double buffer mode)
    static constexpr uint32_t S3CR_DBM = 0x40000;        // Double buffer mode
    template<uint32_t X>
    static constexpr uint32_t S3CR_PL =                  // Priority level (2 bits)
        bit_field_t<16, 0x3>::value<X>();
    static constexpr uint32_t S3CR_PINCOS = 0x8000;      // Peripheral increment offset size
    template<uint32_t X>
    static constexpr uint32_t S3CR_MSIZE =               // Memory data size (2 bits)
        bit_field_t<13, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t S3CR_PSIZE =               // Peripheral data size (2 bits)
        bit_field_t<11, 0x3>::value<X>();
    static constexpr uint32_t S3CR_MINC = 0x400;         // Memory increment mode
    static constexpr uint32_t S3CR_PINC = 0x200;         // Peripheral increment mode
    static constexpr uint32_t S3CR_CIRC = 0x100;         // Circular mode
    template<uint32_t X>
    static constexpr uint32_t S3CR_DIR =                 // Data transfer direction (2 bits)
        bit_field_t<6, 0x3>::value<X>();
    static constexpr uint32_t S3CR_PFCTRL = 0x20;        // Peripheral flow controller
    static constexpr uint32_t S3CR_TCIE = 0x10;          // Transfer complete interrupt enable
    static constexpr uint32_t S3CR_HTIE = 0x8;           // Half transfer interrupt enable
    static constexpr uint32_t S3CR_TEIE = 0x4;           // Transfer error interrupt enable
    static constexpr uint32_t S3CR_DMEIE = 0x2;          // Direct mode error interrupt enable
    static constexpr uint32_t S3CR_EN = 0x1;             // Stream enable / flag stream ready when read low
    static const uint32_t S3CR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t S3NDTR_NDT =                 // Number of data items to transfer (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t S3NDTR_RESET_VALUE = 0x0;


    static const uint32_t S3PAR_RESET_VALUE = 0x0;


    static const uint32_t S3M0AR_RESET_VALUE = 0x0;


    static const uint32_t S3M1AR_RESET_VALUE = 0x0;

    static constexpr uint32_t S3FCR_FEIE = 0x80;          // FIFO error interrupt enable, Read-write
    template<uint32_t X>
    static constexpr uint32_t S3FCR_FS =                  // FIFO status (3 bits), Read-only
        bit_field_t<3, 0x7>::value<X>();
    static constexpr uint32_t S3FCR_DMDIS = 0x4;          // Direct mode disable, Read-write
    template<uint32_t X>
    static constexpr uint32_t S3FCR_FTH =                 // FIFO threshold selection (2 bits), Read-write
        bit_field_t<0, 0x3>::value<X>();
    static const uint32_t S3FCR_RESET_VALUE = 0x21;

    template<uint32_t X>
    static constexpr uint32_t S4CR_CHSEL =               // Channel selection (3 bits)
        bit_field_t<25, 0x7>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t S4CR_MBURST =              // Memory burst transfer configuration (2 bits)
        bit_field_t<23, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t S4CR_PBURST =              // Peripheral burst transfer configuration (2 bits)
        bit_field_t<21, 0x3>::value<X>();
    static constexpr uint32_t S4CR_ACK = 0x100000;       // ACK
    static constexpr uint32_t S4CR_CT = 0x80000;         // Current target (only in double buffer mode)
    static constexpr uint32_t S4CR_DBM = 0x40000;        // Double buffer mode
    template<uint32_t X>
    static constexpr uint32_t S4CR_PL =                  // Priority level (2 bits)
        bit_field_t<16, 0x3>::value<X>();
    static constexpr uint32_t S4CR_PINCOS = 0x8000;      // Peripheral increment offset size
    template<uint32_t X>
    static constexpr uint32_t S4CR_MSIZE =               // Memory data size (2 bits)
        bit_field_t<13, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t S4CR_PSIZE =               // Peripheral data size (2 bits)
        bit_field_t<11, 0x3>::value<X>();
    static constexpr uint32_t S4CR_MINC = 0x400;         // Memory increment mode
    static constexpr uint32_t S4CR_PINC = 0x200;         // Peripheral increment mode
    static constexpr uint32_t S4CR_CIRC = 0x100;         // Circular mode
    template<uint32_t X>
    static constexpr uint32_t S4CR_DIR =                 // Data transfer direction (2 bits)
        bit_field_t<6, 0x3>::value<X>();
    static constexpr uint32_t S4CR_PFCTRL = 0x20;        // Peripheral flow controller
    static constexpr uint32_t S4CR_TCIE = 0x10;          // Transfer complete interrupt enable
    static constexpr uint32_t S4CR_HTIE = 0x8;           // Half transfer interrupt enable
    static constexpr uint32_t S4CR_TEIE = 0x4;           // Transfer error interrupt enable
    static constexpr uint32_t S4CR_DMEIE = 0x2;          // Direct mode error interrupt enable
    static constexpr uint32_t S4CR_EN = 0x1;             // Stream enable / flag stream ready when read low
    static const uint32_t S4CR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t S4NDTR_NDT =                 // Number of data items to transfer (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t S4NDTR_RESET_VALUE = 0x0;


    static const uint32_t S4PAR_RESET_VALUE = 0x0;


    static const uint32_t S4M0AR_RESET_VALUE = 0x0;


    static const uint32_t S4M1AR_RESET_VALUE = 0x0;

    static constexpr uint32_t S4FCR_FEIE = 0x80;          // FIFO error interrupt enable, Read-write
    template<uint32_t X>
    static constexpr uint32_t S4FCR_FS =                  // FIFO status (3 bits), Read-only
        bit_field_t<3, 0x7>::value<X>();
    static constexpr uint32_t S4FCR_DMDIS = 0x4;          // Direct mode disable, Read-write
    template<uint32_t X>
    static constexpr uint32_t S4FCR_FTH =                 // FIFO threshold selection (2 bits), Read-write
        bit_field_t<0, 0x3>::value<X>();
    static const uint32_t S4FCR_RESET_VALUE = 0x21;

    template<uint32_t X>
    static constexpr uint32_t S5CR_CHSEL =               // Channel selection (3 bits)
        bit_field_t<25, 0x7>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t S5CR_MBURST =              // Memory burst transfer configuration (2 bits)
        bit_field_t<23, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t S5CR_PBURST =              // Peripheral burst transfer configuration (2 bits)
        bit_field_t<21, 0x3>::value<X>();
    static constexpr uint32_t S5CR_ACK = 0x100000;       // ACK
    static constexpr uint32_t S5CR_CT = 0x80000;         // Current target (only in double buffer mode)
    static constexpr uint32_t S5CR_DBM = 0x40000;        // Double buffer mode
    template<uint32_t X>
    static constexpr uint32_t S5CR_PL =                  // Priority level (2 bits)
        bit_field_t<16, 0x3>::value<X>();
    static constexpr uint32_t S5CR_PINCOS = 0x8000;      // Peripheral increment offset size
    template<uint32_t X>
    static constexpr uint32_t S5CR_MSIZE =               // Memory data size (2 bits)
        bit_field_t<13, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t S5CR_PSIZE =               // Peripheral data size (2 bits)
        bit_field_t<11, 0x3>::value<X>();
    static constexpr uint32_t S5CR_MINC = 0x400;         // Memory increment mode
    static constexpr uint32_t S5CR_PINC = 0x200;         // Peripheral increment mode
    static constexpr uint32_t S5CR_CIRC = 0x100;         // Circular mode
    template<uint32_t X>
    static constexpr uint32_t S5CR_DIR =                 // Data transfer direction (2 bits)
        bit_field_t<6, 0x3>::value<X>();
    static constexpr uint32_t S5CR_PFCTRL = 0x20;        // Peripheral flow controller
    static constexpr uint32_t S5CR_TCIE = 0x10;          // Transfer complete interrupt enable
    static constexpr uint32_t S5CR_HTIE = 0x8;           // Half transfer interrupt enable
    static constexpr uint32_t S5CR_TEIE = 0x4;           // Transfer error interrupt enable
    static constexpr uint32_t S5CR_DMEIE = 0x2;          // Direct mode error interrupt enable
    static constexpr uint32_t S5CR_EN = 0x1;             // Stream enable / flag stream ready when read low
    static const uint32_t S5CR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t S5NDTR_NDT =                 // Number of data items to transfer (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t S5NDTR_RESET_VALUE = 0x0;


    static const uint32_t S5PAR_RESET_VALUE = 0x0;


    static const uint32_t S5M0AR_RESET_VALUE = 0x0;


    static const uint32_t S5M1AR_RESET_VALUE = 0x0;

    static constexpr uint32_t S5FCR_FEIE = 0x80;          // FIFO error interrupt enable, Read-write
    template<uint32_t X>
    static constexpr uint32_t S5FCR_FS =                  // FIFO status (3 bits), Read-only
        bit_field_t<3, 0x7>::value<X>();
    static constexpr uint32_t S5FCR_DMDIS = 0x4;          // Direct mode disable, Read-write
    template<uint32_t X>
    static constexpr uint32_t S5FCR_FTH =                 // FIFO threshold selection (2 bits), Read-write
        bit_field_t<0, 0x3>::value<X>();
    static const uint32_t S5FCR_RESET_VALUE = 0x21;

    template<uint32_t X>
    static constexpr uint32_t S6CR_CHSEL =               // Channel selection (3 bits)
        bit_field_t<25, 0x7>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t S6CR_MBURST =              // Memory burst transfer configuration (2 bits)
        bit_field_t<23, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t S6CR_PBURST =              // Peripheral burst transfer configuration (2 bits)
        bit_field_t<21, 0x3>::value<X>();
    static constexpr uint32_t S6CR_ACK = 0x100000;       // ACK
    static constexpr uint32_t S6CR_CT = 0x80000;         // Current target (only in double buffer mode)
    static constexpr uint32_t S6CR_DBM = 0x40000;        // Double buffer mode
    template<uint32_t X>
    static constexpr uint32_t S6CR_PL =                  // Priority level (2 bits)
        bit_field_t<16, 0x3>::value<X>();
    static constexpr uint32_t S6CR_PINCOS = 0x8000;      // Peripheral increment offset size
    template<uint32_t X>
    static constexpr uint32_t S6CR_MSIZE =               // Memory data size (2 bits)
        bit_field_t<13, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t S6CR_PSIZE =               // Peripheral data size (2 bits)
        bit_field_t<11, 0x3>::value<X>();
    static constexpr uint32_t S6CR_MINC = 0x400;         // Memory increment mode
    static constexpr uint32_t S6CR_PINC = 0x200;         // Peripheral increment mode
    static constexpr uint32_t S6CR_CIRC = 0x100;         // Circular mode
    template<uint32_t X>
    static constexpr uint32_t S6CR_DIR =                 // Data transfer direction (2 bits)
        bit_field_t<6, 0x3>::value<X>();
    static constexpr uint32_t S6CR_PFCTRL = 0x20;        // Peripheral flow controller
    static constexpr uint32_t S6CR_TCIE = 0x10;          // Transfer complete interrupt enable
    static constexpr uint32_t S6CR_HTIE = 0x8;           // Half transfer interrupt enable
    static constexpr uint32_t S6CR_TEIE = 0x4;           // Transfer error interrupt enable
    static constexpr uint32_t S6CR_DMEIE = 0x2;          // Direct mode error interrupt enable
    static constexpr uint32_t S6CR_EN = 0x1;             // Stream enable / flag stream ready when read low
    static const uint32_t S6CR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t S6NDTR_NDT =                 // Number of data items to transfer (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t S6NDTR_RESET_VALUE = 0x0;


    static const uint32_t S6PAR_RESET_VALUE = 0x0;


    static const uint32_t S6M0AR_RESET_VALUE = 0x0;


    static const uint32_t S6M1AR_RESET_VALUE = 0x0;

    static constexpr uint32_t S6FCR_FEIE = 0x80;          // FIFO error interrupt enable, Read-write
    template<uint32_t X>
    static constexpr uint32_t S6FCR_FS =                  // FIFO status (3 bits), Read-only
        bit_field_t<3, 0x7>::value<X>();
    static constexpr uint32_t S6FCR_DMDIS = 0x4;          // Direct mode disable, Read-write
    template<uint32_t X>
    static constexpr uint32_t S6FCR_FTH =                 // FIFO threshold selection (2 bits), Read-write
        bit_field_t<0, 0x3>::value<X>();
    static const uint32_t S6FCR_RESET_VALUE = 0x21;

    template<uint32_t X>
    static constexpr uint32_t S7CR_CHSEL =               // Channel selection (3 bits)
        bit_field_t<25, 0x7>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t S7CR_MBURST =              // Memory burst transfer configuration (2 bits)
        bit_field_t<23, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t S7CR_PBURST =              // Peripheral burst transfer configuration (2 bits)
        bit_field_t<21, 0x3>::value<X>();
    static constexpr uint32_t S7CR_ACK = 0x100000;       // ACK
    static constexpr uint32_t S7CR_CT = 0x80000;         // Current target (only in double buffer mode)
    static constexpr uint32_t S7CR_DBM = 0x40000;        // Double buffer mode
    template<uint32_t X>
    static constexpr uint32_t S7CR_PL =                  // Priority level (2 bits)
        bit_field_t<16, 0x3>::value<X>();
    static constexpr uint32_t S7CR_PINCOS = 0x8000;      // Peripheral increment offset size
    template<uint32_t X>
    static constexpr uint32_t S7CR_MSIZE =               // Memory data size (2 bits)
        bit_field_t<13, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t S7CR_PSIZE =               // Peripheral data size (2 bits)
        bit_field_t<11, 0x3>::value<X>();
    static constexpr uint32_t S7CR_MINC = 0x400;         // Memory increment mode
    static constexpr uint32_t S7CR_PINC = 0x200;         // Peripheral increment mode
    static constexpr uint32_t S7CR_CIRC = 0x100;         // Circular mode
    template<uint32_t X>
    static constexpr uint32_t S7CR_DIR =                 // Data transfer direction (2 bits)
        bit_field_t<6, 0x3>::value<X>();
    static constexpr uint32_t S7CR_PFCTRL = 0x20;        // Peripheral flow controller
    static constexpr uint32_t S7CR_TCIE = 0x10;          // Transfer complete interrupt enable
    static constexpr uint32_t S7CR_HTIE = 0x8;           // Half transfer interrupt enable
    static constexpr uint32_t S7CR_TEIE = 0x4;           // Transfer error interrupt enable
    static constexpr uint32_t S7CR_DMEIE = 0x2;          // Direct mode error interrupt enable
    static constexpr uint32_t S7CR_EN = 0x1;             // Stream enable / flag stream ready when read low
    static const uint32_t S7CR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t S7NDTR_NDT =                 // Number of data items to transfer (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t S7NDTR_RESET_VALUE = 0x0;


    static const uint32_t S7PAR_RESET_VALUE = 0x0;


    static const uint32_t S7M0AR_RESET_VALUE = 0x0;


    static const uint32_t S7M1AR_RESET_VALUE = 0x0;

    static constexpr uint32_t S7FCR_FEIE = 0x80;          // FIFO error interrupt enable, Read-write
    template<uint32_t X>
    static constexpr uint32_t S7FCR_FS =                  // FIFO status (3 bits), Read-only
        bit_field_t<3, 0x7>::value<X>();
    static constexpr uint32_t S7FCR_DMDIS = 0x4;          // Direct mode disable, Read-write
    template<uint32_t X>
    static constexpr uint32_t S7FCR_FTH =                 // FIFO threshold selection (2 bits), Read-write
        bit_field_t<0, 0x3>::value<X>();
    static const uint32_t S7FCR_RESET_VALUE = 0x21;

    static constexpr uint8_t RTC_ALARM = 41; // RTC Alarms (A and B) through EXTI line interrupt
    static constexpr uint8_t RTC_WKUP = 3; // RTC Wakeup interrupt through the EXTI line
};

static dma1_t& DMA1 = *reinterpret_cast<dma1_t*>(0x40026000);

#define HAVE_PERIPHERAL_DMA1


////
//
//    General-purpose I/Os
//
////

struct gpioh_t
{
    volatile uint32_t    MODER;                // [Read-write] GPIO port mode register
    volatile uint32_t    OTYPER;               // [Read-write] GPIO port output type register
    volatile uint32_t    OSPEEDR;              // [Read-write] GPIO port output speed register
    volatile uint32_t    PUPDR;                // [Read-write] GPIO port pull-up/pull-down register
    volatile uint32_t    IDR;                  // [Read-only] GPIO port input data register
    volatile uint32_t    ODR;                  // [Read-write] GPIO port output data register
    volatile uint32_t    BSRR;                 // [Write-only] GPIO port bit set/reset register
    volatile uint32_t    LCKR;                 // [Read-write] GPIO port configuration lock register
    volatile uint32_t    AFRL;                 // [Read-write] GPIO alternate function low register
    volatile uint32_t    AFRH;                 // [Read-write] GPIO alternate function high register

    template<uint32_t X>
    static constexpr uint32_t MODER_MODER15 =             // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<30, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER14 =             // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<28, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER13 =             // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<26, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER12 =             // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<24, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER11 =             // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<22, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER10 =             // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<20, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER9 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<18, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER8 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<16, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER7 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<14, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER6 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<12, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER5 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<10, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER4 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<8, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER3 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<6, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER2 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<4, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER1 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<2, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER0 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<0, 0x3>::value<X>();
    static const uint32_t MODER_RESET_VALUE = 0x0;

    static constexpr uint32_t OTYPER_OT15 = 0x8000;        // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT14 = 0x4000;        // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT13 = 0x2000;        // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT12 = 0x1000;        // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT11 = 0x800;         // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT10 = 0x400;         // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT9 = 0x200;          // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT8 = 0x100;          // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT7 = 0x80;           // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT6 = 0x40;           // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT5 = 0x20;           // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT4 = 0x10;           // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT3 = 0x8;            // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT2 = 0x4;            // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT1 = 0x2;            // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT0 = 0x1;            // Port x configuration bits (y = 0..15)
    static const uint32_t OTYPER_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR15 =           // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<30, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR14 =           // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<28, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR13 =           // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<26, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR12 =           // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<24, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR11 =           // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<22, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR10 =           // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<20, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR9 =            // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<18, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR8 =            // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<16, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR7 =            // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<14, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR6 =            // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<12, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR5 =            // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<10, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR4 =            // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<8, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR3 =            // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<6, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR2 =            // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<4, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR1 =            // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<2, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR0 =            // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<0, 0x3>::value<X>();
    static const uint32_t OSPEEDR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR15 =             // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<30, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR14 =             // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<28, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR13 =             // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<26, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR12 =             // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<24, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR11 =             // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<22, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR10 =             // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<20, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR9 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<18, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR8 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<16, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR7 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<14, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR6 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<12, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR5 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<10, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR4 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<8, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR3 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<6, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR2 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<4, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR1 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<2, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR0 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<0, 0x3>::value<X>();
    static const uint32_t PUPDR_RESET_VALUE = 0x0;

    static constexpr uint32_t IDR_IDR15 = 0x8000;       // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR14 = 0x4000;       // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR13 = 0x2000;       // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR12 = 0x1000;       // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR11 = 0x800;        // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR10 = 0x400;        // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR9 = 0x200;         // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR8 = 0x100;         // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR7 = 0x80;          // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR6 = 0x40;          // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR5 = 0x20;          // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR4 = 0x10;          // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR3 = 0x8;           // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR2 = 0x4;           // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR1 = 0x2;           // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR0 = 0x1;           // Port input data (y = 0..15)
    static const uint32_t IDR_RESET_VALUE = 0x0;

    static constexpr uint32_t ODR_ODR15 = 0x8000;       // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR14 = 0x4000;       // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR13 = 0x2000;       // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR12 = 0x1000;       // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR11 = 0x800;        // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR10 = 0x400;        // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR9 = 0x200;         // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR8 = 0x100;         // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR7 = 0x80;          // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR6 = 0x40;          // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR5 = 0x20;          // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR4 = 0x10;          // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR3 = 0x8;           // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR2 = 0x4;           // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR1 = 0x2;           // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR0 = 0x1;           // Port output data (y = 0..15)
    static const uint32_t ODR_RESET_VALUE = 0x0;

    static constexpr uint32_t BSRR_BR15 = 0x80000000;    // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR14 = 0x40000000;    // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR13 = 0x20000000;    // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR12 = 0x10000000;    // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR11 = 0x8000000;     // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR10 = 0x4000000;     // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR9 = 0x2000000;      // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR8 = 0x1000000;      // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR7 = 0x800000;       // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR6 = 0x400000;       // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR5 = 0x200000;       // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR4 = 0x100000;       // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR3 = 0x80000;        // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR2 = 0x40000;        // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR1 = 0x20000;        // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR0 = 0x10000;        // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS15 = 0x8000;        // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS14 = 0x4000;        // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS13 = 0x2000;        // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS12 = 0x1000;        // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS11 = 0x800;         // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS10 = 0x400;         // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS9 = 0x200;          // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS8 = 0x100;          // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS7 = 0x80;           // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS6 = 0x40;           // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS5 = 0x20;           // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS4 = 0x10;           // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS3 = 0x8;            // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS2 = 0x4;            // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS1 = 0x2;            // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS0 = 0x1;            // Port x set bit y (y= 0..15)
    static const uint32_t BSRR_RESET_VALUE = 0x0;

    static constexpr uint32_t LCKR_LCKK = 0x10000;       // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK15 = 0x8000;       // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK14 = 0x4000;       // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK13 = 0x2000;       // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK12 = 0x1000;       // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK11 = 0x800;        // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK10 = 0x400;        // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK9 = 0x200;         // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK8 = 0x100;         // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK7 = 0x80;          // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK6 = 0x40;          // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK5 = 0x20;          // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK4 = 0x10;          // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK3 = 0x8;           // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK2 = 0x4;           // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK1 = 0x2;           // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK0 = 0x1;           // Port x lock bit y (y= 0..15)
    static const uint32_t LCKR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t AFRL_AFRL7 =               // Alternate function selection for port x bit y (y = 0..7) (4 bits)
        bit_field_t<28, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t AFRL_AFRL6 =               // Alternate function selection for port x bit y (y = 0..7) (4 bits)
        bit_field_t<24, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t AFRL_AFRL5 =               // Alternate function selection for port x bit y (y = 0..7) (4 bits)
        bit_field_t<20, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t AFRL_AFRL4 =               // Alternate function selection for port x bit y (y = 0..7) (4 bits)
        bit_field_t<16, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t AFRL_AFRL3 =               // Alternate function selection for port x bit y (y = 0..7) (4 bits)
        bit_field_t<12, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t AFRL_AFRL2 =               // Alternate function selection for port x bit y (y = 0..7) (4 bits)
        bit_field_t<8, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t AFRL_AFRL1 =               // Alternate function selection for port x bit y (y = 0..7) (4 bits)
        bit_field_t<4, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t AFRL_AFRL0 =               // Alternate function selection for port x bit y (y = 0..7) (4 bits)
        bit_field_t<0, 0xf>::value<X>();
    static const uint32_t AFRL_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t AFRH_AFRH15 =              // Alternate function selection for port x bit y (y = 8..15) (4 bits)
        bit_field_t<28, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t AFRH_AFRH14 =              // Alternate function selection for port x bit y (y = 8..15) (4 bits)
        bit_field_t<24, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t AFRH_AFRH13 =              // Alternate function selection for port x bit y (y = 8..15) (4 bits)
        bit_field_t<20, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t AFRH_AFRH12 =              // Alternate function selection for port x bit y (y = 8..15) (4 bits)
        bit_field_t<16, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t AFRH_AFRH11 =              // Alternate function selection for port x bit y (y = 8..15) (4 bits)
        bit_field_t<12, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t AFRH_AFRH10 =              // Alternate function selection for port x bit y (y = 8..15) (4 bits)
        bit_field_t<8, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t AFRH_AFRH9 =               // Alternate function selection for port x bit y (y = 8..15) (4 bits)
        bit_field_t<4, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t AFRH_AFRH8 =               // Alternate function selection for port x bit y (y = 8..15) (4 bits)
        bit_field_t<0, 0xf>::value<X>();
    static const uint32_t AFRH_RESET_VALUE = 0x0;

    static constexpr uint8_t SDIO = 49; // SDIO global interrupt
};

static gpioh_t& GPIOH = *reinterpret_cast<gpioh_t*>(0x40021c00);

#define HAVE_PERIPHERAL_GPIOH


////
//
//    General-purpose I/Os
//
////

struct gpioe_t
{
    volatile uint32_t    MODER;                // [Read-write] GPIO port mode register
    volatile uint32_t    OTYPER;               // [Read-write] GPIO port output type register
    volatile uint32_t    OSPEEDR;              // [Read-write] GPIO port output speed register
    volatile uint32_t    PUPDR;                // [Read-write] GPIO port pull-up/pull-down register
    volatile uint32_t    IDR;                  // [Read-only] GPIO port input data register
    volatile uint32_t    ODR;                  // [Read-write] GPIO port output data register
    volatile uint32_t    BSRR;                 // [Write-only] GPIO port bit set/reset register
    volatile uint32_t    LCKR;                 // [Read-write] GPIO port configuration lock register
    volatile uint32_t    AFRL;                 // [Read-write] GPIO alternate function low register
    volatile uint32_t    AFRH;                 // [Read-write] GPIO alternate function high register

    template<uint32_t X>
    static constexpr uint32_t MODER_MODER15 =             // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<30, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER14 =             // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<28, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER13 =             // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<26, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER12 =             // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<24, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER11 =             // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<22, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER10 =             // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<20, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER9 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<18, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER8 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<16, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER7 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<14, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER6 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<12, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER5 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<10, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER4 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<8, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER3 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<6, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER2 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<4, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER1 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<2, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER0 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<0, 0x3>::value<X>();
    static const uint32_t MODER_RESET_VALUE = 0x0;

    static constexpr uint32_t OTYPER_OT15 = 0x8000;        // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT14 = 0x4000;        // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT13 = 0x2000;        // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT12 = 0x1000;        // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT11 = 0x800;         // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT10 = 0x400;         // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT9 = 0x200;          // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT8 = 0x100;          // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT7 = 0x80;           // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT6 = 0x40;           // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT5 = 0x20;           // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT4 = 0x10;           // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT3 = 0x8;            // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT2 = 0x4;            // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT1 = 0x2;            // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT0 = 0x1;            // Port x configuration bits (y = 0..15)
    static const uint32_t OTYPER_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR15 =           // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<30, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR14 =           // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<28, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR13 =           // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<26, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR12 =           // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<24, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR11 =           // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<22, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR10 =           // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<20, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR9 =            // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<18, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR8 =            // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<16, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR7 =            // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<14, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR6 =            // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<12, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR5 =            // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<10, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR4 =            // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<8, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR3 =            // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<6, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR2 =            // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<4, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR1 =            // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<2, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR0 =            // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<0, 0x3>::value<X>();
    static const uint32_t OSPEEDR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR15 =             // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<30, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR14 =             // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<28, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR13 =             // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<26, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR12 =             // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<24, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR11 =             // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<22, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR10 =             // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<20, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR9 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<18, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR8 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<16, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR7 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<14, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR6 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<12, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR5 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<10, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR4 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<8, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR3 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<6, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR2 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<4, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR1 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<2, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR0 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<0, 0x3>::value<X>();
    static const uint32_t PUPDR_RESET_VALUE = 0x0;

    static constexpr uint32_t IDR_IDR15 = 0x8000;       // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR14 = 0x4000;       // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR13 = 0x2000;       // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR12 = 0x1000;       // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR11 = 0x800;        // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR10 = 0x400;        // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR9 = 0x200;         // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR8 = 0x100;         // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR7 = 0x80;          // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR6 = 0x40;          // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR5 = 0x20;          // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR4 = 0x10;          // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR3 = 0x8;           // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR2 = 0x4;           // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR1 = 0x2;           // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR0 = 0x1;           // Port input data (y = 0..15)
    static const uint32_t IDR_RESET_VALUE = 0x0;

    static constexpr uint32_t ODR_ODR15 = 0x8000;       // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR14 = 0x4000;       // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR13 = 0x2000;       // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR12 = 0x1000;       // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR11 = 0x800;        // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR10 = 0x400;        // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR9 = 0x200;         // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR8 = 0x100;         // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR7 = 0x80;          // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR6 = 0x40;          // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR5 = 0x20;          // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR4 = 0x10;          // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR3 = 0x8;           // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR2 = 0x4;           // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR1 = 0x2;           // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR0 = 0x1;           // Port output data (y = 0..15)
    static const uint32_t ODR_RESET_VALUE = 0x0;

    static constexpr uint32_t BSRR_BR15 = 0x80000000;    // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR14 = 0x40000000;    // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR13 = 0x20000000;    // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR12 = 0x10000000;    // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR11 = 0x8000000;     // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR10 = 0x4000000;     // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR9 = 0x2000000;      // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR8 = 0x1000000;      // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR7 = 0x800000;       // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR6 = 0x400000;       // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR5 = 0x200000;       // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR4 = 0x100000;       // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR3 = 0x80000;        // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR2 = 0x40000;        // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR1 = 0x20000;        // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR0 = 0x10000;        // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS15 = 0x8000;        // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS14 = 0x4000;        // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS13 = 0x2000;        // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS12 = 0x1000;        // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS11 = 0x800;         // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS10 = 0x400;         // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS9 = 0x200;          // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS8 = 0x100;          // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS7 = 0x80;           // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS6 = 0x40;           // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS5 = 0x20;           // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS4 = 0x10;           // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS3 = 0x8;            // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS2 = 0x4;            // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS1 = 0x2;            // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS0 = 0x1;            // Port x set bit y (y= 0..15)
    static const uint32_t BSRR_RESET_VALUE = 0x0;

    static constexpr uint32_t LCKR_LCKK = 0x10000;       // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK15 = 0x8000;       // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK14 = 0x4000;       // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK13 = 0x2000;       // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK12 = 0x1000;       // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK11 = 0x800;        // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK10 = 0x400;        // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK9 = 0x200;         // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK8 = 0x100;         // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK7 = 0x80;          // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK6 = 0x40;          // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK5 = 0x20;          // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK4 = 0x10;          // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK3 = 0x8;           // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK2 = 0x4;           // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK1 = 0x2;           // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK0 = 0x1;           // Port x lock bit y (y= 0..15)
    static const uint32_t LCKR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t AFRL_AFRL7 =               // Alternate function selection for port x bit y (y = 0..7) (4 bits)
        bit_field_t<28, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t AFRL_AFRL6 =               // Alternate function selection for port x bit y (y = 0..7) (4 bits)
        bit_field_t<24, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t AFRL_AFRL5 =               // Alternate function selection for port x bit y (y = 0..7) (4 bits)
        bit_field_t<20, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t AFRL_AFRL4 =               // Alternate function selection for port x bit y (y = 0..7) (4 bits)
        bit_field_t<16, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t AFRL_AFRL3 =               // Alternate function selection for port x bit y (y = 0..7) (4 bits)
        bit_field_t<12, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t AFRL_AFRL2 =               // Alternate function selection for port x bit y (y = 0..7) (4 bits)
        bit_field_t<8, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t AFRL_AFRL1 =               // Alternate function selection for port x bit y (y = 0..7) (4 bits)
        bit_field_t<4, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t AFRL_AFRL0 =               // Alternate function selection for port x bit y (y = 0..7) (4 bits)
        bit_field_t<0, 0xf>::value<X>();
    static const uint32_t AFRL_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t AFRH_AFRH15 =              // Alternate function selection for port x bit y (y = 8..15) (4 bits)
        bit_field_t<28, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t AFRH_AFRH14 =              // Alternate function selection for port x bit y (y = 8..15) (4 bits)
        bit_field_t<24, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t AFRH_AFRH13 =              // Alternate function selection for port x bit y (y = 8..15) (4 bits)
        bit_field_t<20, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t AFRH_AFRH12 =              // Alternate function selection for port x bit y (y = 8..15) (4 bits)
        bit_field_t<16, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t AFRH_AFRH11 =              // Alternate function selection for port x bit y (y = 8..15) (4 bits)
        bit_field_t<12, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t AFRH_AFRH10 =              // Alternate function selection for port x bit y (y = 8..15) (4 bits)
        bit_field_t<8, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t AFRH_AFRH9 =               // Alternate function selection for port x bit y (y = 8..15) (4 bits)
        bit_field_t<4, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t AFRH_AFRH8 =               // Alternate function selection for port x bit y (y = 8..15) (4 bits)
        bit_field_t<0, 0xf>::value<X>();
    static const uint32_t AFRH_RESET_VALUE = 0x0;
};

static gpioe_t& GPIOE = *reinterpret_cast<gpioe_t*>(0x40021000);

#define HAVE_PERIPHERAL_GPIOE


////
//
//    General-purpose I/Os
//
////

struct gpiod_t
{
    volatile uint32_t    MODER;                // [Read-write] GPIO port mode register
    volatile uint32_t    OTYPER;               // [Read-write] GPIO port output type register
    volatile uint32_t    OSPEEDR;              // [Read-write] GPIO port output speed register
    volatile uint32_t    PUPDR;                // [Read-write] GPIO port pull-up/pull-down register
    volatile uint32_t    IDR;                  // [Read-only] GPIO port input data register
    volatile uint32_t    ODR;                  // [Read-write] GPIO port output data register
    volatile uint32_t    BSRR;                 // [Write-only] GPIO port bit set/reset register
    volatile uint32_t    LCKR;                 // [Read-write] GPIO port configuration lock register
    volatile uint32_t    AFRL;                 // [Read-write] GPIO alternate function low register
    volatile uint32_t    AFRH;                 // [Read-write] GPIO alternate function high register

    template<uint32_t X>
    static constexpr uint32_t MODER_MODER15 =             // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<30, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER14 =             // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<28, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER13 =             // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<26, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER12 =             // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<24, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER11 =             // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<22, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER10 =             // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<20, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER9 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<18, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER8 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<16, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER7 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<14, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER6 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<12, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER5 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<10, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER4 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<8, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER3 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<6, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER2 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<4, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER1 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<2, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER0 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<0, 0x3>::value<X>();
    static const uint32_t MODER_RESET_VALUE = 0x0;

    static constexpr uint32_t OTYPER_OT15 = 0x8000;        // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT14 = 0x4000;        // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT13 = 0x2000;        // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT12 = 0x1000;        // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT11 = 0x800;         // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT10 = 0x400;         // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT9 = 0x200;          // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT8 = 0x100;          // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT7 = 0x80;           // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT6 = 0x40;           // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT5 = 0x20;           // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT4 = 0x10;           // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT3 = 0x8;            // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT2 = 0x4;            // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT1 = 0x2;            // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT0 = 0x1;            // Port x configuration bits (y = 0..15)
    static const uint32_t OTYPER_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR15 =           // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<30, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR14 =           // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<28, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR13 =           // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<26, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR12 =           // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<24, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR11 =           // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<22, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR10 =           // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<20, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR9 =            // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<18, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR8 =            // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<16, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR7 =            // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<14, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR6 =            // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<12, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR5 =            // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<10, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR4 =            // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<8, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR3 =            // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<6, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR2 =            // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<4, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR1 =            // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<2, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR0 =            // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<0, 0x3>::value<X>();
    static const uint32_t OSPEEDR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR15 =             // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<30, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR14 =             // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<28, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR13 =             // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<26, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR12 =             // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<24, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR11 =             // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<22, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR10 =             // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<20, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR9 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<18, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR8 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<16, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR7 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<14, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR6 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<12, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR5 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<10, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR4 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<8, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR3 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<6, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR2 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<4, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR1 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<2, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR0 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<0, 0x3>::value<X>();
    static const uint32_t PUPDR_RESET_VALUE = 0x0;

    static constexpr uint32_t IDR_IDR15 = 0x8000;       // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR14 = 0x4000;       // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR13 = 0x2000;       // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR12 = 0x1000;       // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR11 = 0x800;        // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR10 = 0x400;        // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR9 = 0x200;         // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR8 = 0x100;         // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR7 = 0x80;          // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR6 = 0x40;          // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR5 = 0x20;          // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR4 = 0x10;          // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR3 = 0x8;           // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR2 = 0x4;           // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR1 = 0x2;           // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR0 = 0x1;           // Port input data (y = 0..15)
    static const uint32_t IDR_RESET_VALUE = 0x0;

    static constexpr uint32_t ODR_ODR15 = 0x8000;       // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR14 = 0x4000;       // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR13 = 0x2000;       // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR12 = 0x1000;       // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR11 = 0x800;        // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR10 = 0x400;        // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR9 = 0x200;         // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR8 = 0x100;         // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR7 = 0x80;          // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR6 = 0x40;          // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR5 = 0x20;          // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR4 = 0x10;          // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR3 = 0x8;           // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR2 = 0x4;           // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR1 = 0x2;           // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR0 = 0x1;           // Port output data (y = 0..15)
    static const uint32_t ODR_RESET_VALUE = 0x0;

    static constexpr uint32_t BSRR_BR15 = 0x80000000;    // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR14 = 0x40000000;    // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR13 = 0x20000000;    // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR12 = 0x10000000;    // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR11 = 0x8000000;     // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR10 = 0x4000000;     // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR9 = 0x2000000;      // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR8 = 0x1000000;      // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR7 = 0x800000;       // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR6 = 0x400000;       // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR5 = 0x200000;       // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR4 = 0x100000;       // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR3 = 0x80000;        // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR2 = 0x40000;        // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR1 = 0x20000;        // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR0 = 0x10000;        // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS15 = 0x8000;        // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS14 = 0x4000;        // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS13 = 0x2000;        // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS12 = 0x1000;        // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS11 = 0x800;         // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS10 = 0x400;         // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS9 = 0x200;          // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS8 = 0x100;          // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS7 = 0x80;           // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS6 = 0x40;           // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS5 = 0x20;           // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS4 = 0x10;           // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS3 = 0x8;            // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS2 = 0x4;            // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS1 = 0x2;            // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS0 = 0x1;            // Port x set bit y (y= 0..15)
    static const uint32_t BSRR_RESET_VALUE = 0x0;

    static constexpr uint32_t LCKR_LCKK = 0x10000;       // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK15 = 0x8000;       // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK14 = 0x4000;       // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK13 = 0x2000;       // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK12 = 0x1000;       // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK11 = 0x800;        // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK10 = 0x400;        // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK9 = 0x200;         // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK8 = 0x100;         // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK7 = 0x80;          // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK6 = 0x40;          // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK5 = 0x20;          // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK4 = 0x10;          // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK3 = 0x8;           // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK2 = 0x4;           // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK1 = 0x2;           // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK0 = 0x1;           // Port x lock bit y (y= 0..15)
    static const uint32_t LCKR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t AFRL_AFRL7 =               // Alternate function selection for port x bit y (y = 0..7) (4 bits)
        bit_field_t<28, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t AFRL_AFRL6 =               // Alternate function selection for port x bit y (y = 0..7) (4 bits)
        bit_field_t<24, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t AFRL_AFRL5 =               // Alternate function selection for port x bit y (y = 0..7) (4 bits)
        bit_field_t<20, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t AFRL_AFRL4 =               // Alternate function selection for port x bit y (y = 0..7) (4 bits)
        bit_field_t<16, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t AFRL_AFRL3 =               // Alternate function selection for port x bit y (y = 0..7) (4 bits)
        bit_field_t<12, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t AFRL_AFRL2 =               // Alternate function selection for port x bit y (y = 0..7) (4 bits)
        bit_field_t<8, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t AFRL_AFRL1 =               // Alternate function selection for port x bit y (y = 0..7) (4 bits)
        bit_field_t<4, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t AFRL_AFRL0 =               // Alternate function selection for port x bit y (y = 0..7) (4 bits)
        bit_field_t<0, 0xf>::value<X>();
    static const uint32_t AFRL_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t AFRH_AFRH15 =              // Alternate function selection for port x bit y (y = 8..15) (4 bits)
        bit_field_t<28, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t AFRH_AFRH14 =              // Alternate function selection for port x bit y (y = 8..15) (4 bits)
        bit_field_t<24, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t AFRH_AFRH13 =              // Alternate function selection for port x bit y (y = 8..15) (4 bits)
        bit_field_t<20, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t AFRH_AFRH12 =              // Alternate function selection for port x bit y (y = 8..15) (4 bits)
        bit_field_t<16, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t AFRH_AFRH11 =              // Alternate function selection for port x bit y (y = 8..15) (4 bits)
        bit_field_t<12, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t AFRH_AFRH10 =              // Alternate function selection for port x bit y (y = 8..15) (4 bits)
        bit_field_t<8, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t AFRH_AFRH9 =               // Alternate function selection for port x bit y (y = 8..15) (4 bits)
        bit_field_t<4, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t AFRH_AFRH8 =               // Alternate function selection for port x bit y (y = 8..15) (4 bits)
        bit_field_t<0, 0xf>::value<X>();
    static const uint32_t AFRH_RESET_VALUE = 0x0;

    static constexpr uint8_t TIM1_BRK_TIM9 = 24; // TIM1 Break interrupt and TIM9 global interrupt
    static constexpr uint8_t TIM1_CC = 27; // TIM1 Capture Compare interrupt
    static constexpr uint8_t TIM1_TRG_COM_TIM11 = 26; // TIM1 Trigger and Commutation interrupts and TIM11 global interrupt
    static constexpr uint8_t TIM1_UP_TIM10 = 25; // TIM1 Update interrupt and TIM10 global interrupt
};

static gpiod_t& GPIOD = *reinterpret_cast<gpiod_t*>(0x40020c00);

#define HAVE_PERIPHERAL_GPIOD


////
//
//    General-purpose I/Os
//
////

struct gpioc_t
{
    volatile uint32_t    MODER;                // [Read-write] GPIO port mode register
    volatile uint32_t    OTYPER;               // [Read-write] GPIO port output type register
    volatile uint32_t    OSPEEDR;              // [Read-write] GPIO port output speed register
    volatile uint32_t    PUPDR;                // [Read-write] GPIO port pull-up/pull-down register
    volatile uint32_t    IDR;                  // [Read-only] GPIO port input data register
    volatile uint32_t    ODR;                  // [Read-write] GPIO port output data register
    volatile uint32_t    BSRR;                 // [Write-only] GPIO port bit set/reset register
    volatile uint32_t    LCKR;                 // [Read-write] GPIO port configuration lock register
    volatile uint32_t    AFRL;                 // [Read-write] GPIO alternate function low register
    volatile uint32_t    AFRH;                 // [Read-write] GPIO alternate function high register

    template<uint32_t X>
    static constexpr uint32_t MODER_MODER15 =             // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<30, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER14 =             // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<28, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER13 =             // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<26, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER12 =             // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<24, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER11 =             // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<22, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER10 =             // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<20, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER9 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<18, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER8 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<16, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER7 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<14, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER6 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<12, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER5 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<10, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER4 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<8, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER3 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<6, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER2 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<4, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER1 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<2, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER0 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<0, 0x3>::value<X>();
    static const uint32_t MODER_RESET_VALUE = 0x0;

    static constexpr uint32_t OTYPER_OT15 = 0x8000;        // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT14 = 0x4000;        // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT13 = 0x2000;        // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT12 = 0x1000;        // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT11 = 0x800;         // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT10 = 0x400;         // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT9 = 0x200;          // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT8 = 0x100;          // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT7 = 0x80;           // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT6 = 0x40;           // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT5 = 0x20;           // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT4 = 0x10;           // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT3 = 0x8;            // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT2 = 0x4;            // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT1 = 0x2;            // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT0 = 0x1;            // Port x configuration bits (y = 0..15)
    static const uint32_t OTYPER_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR15 =           // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<30, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR14 =           // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<28, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR13 =           // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<26, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR12 =           // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<24, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR11 =           // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<22, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR10 =           // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<20, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR9 =            // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<18, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR8 =            // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<16, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR7 =            // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<14, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR6 =            // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<12, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR5 =            // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<10, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR4 =            // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<8, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR3 =            // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<6, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR2 =            // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<4, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR1 =            // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<2, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR0 =            // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<0, 0x3>::value<X>();
    static const uint32_t OSPEEDR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR15 =             // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<30, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR14 =             // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<28, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR13 =             // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<26, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR12 =             // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<24, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR11 =             // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<22, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR10 =             // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<20, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR9 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<18, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR8 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<16, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR7 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<14, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR6 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<12, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR5 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<10, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR4 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<8, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR3 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<6, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR2 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<4, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR1 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<2, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR0 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<0, 0x3>::value<X>();
    static const uint32_t PUPDR_RESET_VALUE = 0x0;

    static constexpr uint32_t IDR_IDR15 = 0x8000;       // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR14 = 0x4000;       // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR13 = 0x2000;       // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR12 = 0x1000;       // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR11 = 0x800;        // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR10 = 0x400;        // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR9 = 0x200;         // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR8 = 0x100;         // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR7 = 0x80;          // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR6 = 0x40;          // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR5 = 0x20;          // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR4 = 0x10;          // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR3 = 0x8;           // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR2 = 0x4;           // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR1 = 0x2;           // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR0 = 0x1;           // Port input data (y = 0..15)
    static const uint32_t IDR_RESET_VALUE = 0x0;

    static constexpr uint32_t ODR_ODR15 = 0x8000;       // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR14 = 0x4000;       // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR13 = 0x2000;       // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR12 = 0x1000;       // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR11 = 0x800;        // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR10 = 0x400;        // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR9 = 0x200;         // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR8 = 0x100;         // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR7 = 0x80;          // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR6 = 0x40;          // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR5 = 0x20;          // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR4 = 0x10;          // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR3 = 0x8;           // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR2 = 0x4;           // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR1 = 0x2;           // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR0 = 0x1;           // Port output data (y = 0..15)
    static const uint32_t ODR_RESET_VALUE = 0x0;

    static constexpr uint32_t BSRR_BR15 = 0x80000000;    // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR14 = 0x40000000;    // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR13 = 0x20000000;    // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR12 = 0x10000000;    // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR11 = 0x8000000;     // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR10 = 0x4000000;     // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR9 = 0x2000000;      // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR8 = 0x1000000;      // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR7 = 0x800000;       // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR6 = 0x400000;       // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR5 = 0x200000;       // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR4 = 0x100000;       // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR3 = 0x80000;        // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR2 = 0x40000;        // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR1 = 0x20000;        // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR0 = 0x10000;        // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS15 = 0x8000;        // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS14 = 0x4000;        // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS13 = 0x2000;        // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS12 = 0x1000;        // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS11 = 0x800;         // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS10 = 0x400;         // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS9 = 0x200;          // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS8 = 0x100;          // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS7 = 0x80;           // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS6 = 0x40;           // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS5 = 0x20;           // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS4 = 0x10;           // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS3 = 0x8;            // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS2 = 0x4;            // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS1 = 0x2;            // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS0 = 0x1;            // Port x set bit y (y= 0..15)
    static const uint32_t BSRR_RESET_VALUE = 0x0;

    static constexpr uint32_t LCKR_LCKK = 0x10000;       // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK15 = 0x8000;       // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK14 = 0x4000;       // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK13 = 0x2000;       // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK12 = 0x1000;       // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK11 = 0x800;        // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK10 = 0x400;        // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK9 = 0x200;         // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK8 = 0x100;         // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK7 = 0x80;          // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK6 = 0x40;          // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK5 = 0x20;          // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK4 = 0x10;          // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK3 = 0x8;           // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK2 = 0x4;           // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK1 = 0x2;           // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK0 = 0x1;           // Port x lock bit y (y= 0..15)
    static const uint32_t LCKR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t AFRL_AFRL7 =               // Alternate function selection for port x bit y (y = 0..7) (4 bits)
        bit_field_t<28, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t AFRL_AFRL6 =               // Alternate function selection for port x bit y (y = 0..7) (4 bits)
        bit_field_t<24, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t AFRL_AFRL5 =               // Alternate function selection for port x bit y (y = 0..7) (4 bits)
        bit_field_t<20, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t AFRL_AFRL4 =               // Alternate function selection for port x bit y (y = 0..7) (4 bits)
        bit_field_t<16, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t AFRL_AFRL3 =               // Alternate function selection for port x bit y (y = 0..7) (4 bits)
        bit_field_t<12, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t AFRL_AFRL2 =               // Alternate function selection for port x bit y (y = 0..7) (4 bits)
        bit_field_t<8, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t AFRL_AFRL1 =               // Alternate function selection for port x bit y (y = 0..7) (4 bits)
        bit_field_t<4, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t AFRL_AFRL0 =               // Alternate function selection for port x bit y (y = 0..7) (4 bits)
        bit_field_t<0, 0xf>::value<X>();
    static const uint32_t AFRL_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t AFRH_AFRH15 =              // Alternate function selection for port x bit y (y = 8..15) (4 bits)
        bit_field_t<28, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t AFRH_AFRH14 =              // Alternate function selection for port x bit y (y = 8..15) (4 bits)
        bit_field_t<24, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t AFRH_AFRH13 =              // Alternate function selection for port x bit y (y = 8..15) (4 bits)
        bit_field_t<20, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t AFRH_AFRH12 =              // Alternate function selection for port x bit y (y = 8..15) (4 bits)
        bit_field_t<16, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t AFRH_AFRH11 =              // Alternate function selection for port x bit y (y = 8..15) (4 bits)
        bit_field_t<12, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t AFRH_AFRH10 =              // Alternate function selection for port x bit y (y = 8..15) (4 bits)
        bit_field_t<8, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t AFRH_AFRH9 =               // Alternate function selection for port x bit y (y = 8..15) (4 bits)
        bit_field_t<4, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t AFRH_AFRH8 =               // Alternate function selection for port x bit y (y = 8..15) (4 bits)
        bit_field_t<0, 0xf>::value<X>();
    static const uint32_t AFRH_RESET_VALUE = 0x0;

    static constexpr uint8_t TIM1_UP_TIM10 = 25; // TIM1 Update interrupt and TIM10 global interrupt
};

static gpioc_t& GPIOC = *reinterpret_cast<gpioc_t*>(0x40020800);

#define HAVE_PERIPHERAL_GPIOC


////
//
//    General-purpose I/Os
//
////

struct gpiob_t
{
    volatile uint32_t    MODER;                // [Read-write] GPIO port mode register
    volatile uint32_t    OTYPER;               // [Read-write] GPIO port output type register
    volatile uint32_t    OSPEEDR;              // [Read-write] GPIO port output speed register
    volatile uint32_t    PUPDR;                // [Read-write] GPIO port pull-up/pull-down register
    volatile uint32_t    IDR;                  // [Read-only] GPIO port input data register
    volatile uint32_t    ODR;                  // [Read-write] GPIO port output data register
    volatile uint32_t    BSRR;                 // [Write-only] GPIO port bit set/reset register
    volatile uint32_t    LCKR;                 // [Read-write] GPIO port configuration lock register
    volatile uint32_t    AFRL;                 // [Read-write] GPIO alternate function low register
    volatile uint32_t    AFRH;                 // [Read-write] GPIO alternate function high register

    template<uint32_t X>
    static constexpr uint32_t MODER_MODER15 =             // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<30, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER14 =             // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<28, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER13 =             // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<26, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER12 =             // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<24, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER11 =             // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<22, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER10 =             // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<20, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER9 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<18, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER8 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<16, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER7 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<14, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER6 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<12, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER5 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<10, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER4 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<8, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER3 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<6, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER2 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<4, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER1 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<2, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER0 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<0, 0x3>::value<X>();
    static const uint32_t MODER_RESET_VALUE = 0x280;

    static constexpr uint32_t OTYPER_OT15 = 0x8000;        // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT14 = 0x4000;        // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT13 = 0x2000;        // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT12 = 0x1000;        // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT11 = 0x800;         // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT10 = 0x400;         // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT9 = 0x200;          // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT8 = 0x100;          // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT7 = 0x80;           // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT6 = 0x40;           // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT5 = 0x20;           // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT4 = 0x10;           // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT3 = 0x8;            // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT2 = 0x4;            // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT1 = 0x2;            // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT0 = 0x1;            // Port x configuration bits (y = 0..15)
    static const uint32_t OTYPER_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR15 =           // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<30, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR14 =           // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<28, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR13 =           // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<26, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR12 =           // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<24, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR11 =           // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<22, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR10 =           // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<20, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR9 =            // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<18, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR8 =            // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<16, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR7 =            // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<14, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR6 =            // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<12, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR5 =            // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<10, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR4 =            // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<8, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR3 =            // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<6, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR2 =            // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<4, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR1 =            // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<2, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR0 =            // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<0, 0x3>::value<X>();
    static const uint32_t OSPEEDR_RESET_VALUE = 0xc0;

    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR15 =             // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<30, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR14 =             // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<28, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR13 =             // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<26, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR12 =             // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<24, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR11 =             // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<22, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR10 =             // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<20, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR9 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<18, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR8 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<16, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR7 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<14, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR6 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<12, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR5 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<10, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR4 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<8, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR3 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<6, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR2 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<4, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR1 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<2, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR0 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<0, 0x3>::value<X>();
    static const uint32_t PUPDR_RESET_VALUE = 0x100;

    static constexpr uint32_t IDR_IDR15 = 0x8000;       // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR14 = 0x4000;       // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR13 = 0x2000;       // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR12 = 0x1000;       // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR11 = 0x800;        // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR10 = 0x400;        // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR9 = 0x200;         // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR8 = 0x100;         // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR7 = 0x80;          // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR6 = 0x40;          // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR5 = 0x20;          // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR4 = 0x10;          // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR3 = 0x8;           // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR2 = 0x4;           // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR1 = 0x2;           // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR0 = 0x1;           // Port input data (y = 0..15)
    static const uint32_t IDR_RESET_VALUE = 0x0;

    static constexpr uint32_t ODR_ODR15 = 0x8000;       // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR14 = 0x4000;       // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR13 = 0x2000;       // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR12 = 0x1000;       // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR11 = 0x800;        // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR10 = 0x400;        // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR9 = 0x200;         // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR8 = 0x100;         // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR7 = 0x80;          // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR6 = 0x40;          // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR5 = 0x20;          // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR4 = 0x10;          // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR3 = 0x8;           // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR2 = 0x4;           // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR1 = 0x2;           // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR0 = 0x1;           // Port output data (y = 0..15)
    static const uint32_t ODR_RESET_VALUE = 0x0;

    static constexpr uint32_t BSRR_BR15 = 0x80000000;    // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR14 = 0x40000000;    // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR13 = 0x20000000;    // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR12 = 0x10000000;    // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR11 = 0x8000000;     // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR10 = 0x4000000;     // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR9 = 0x2000000;      // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR8 = 0x1000000;      // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR7 = 0x800000;       // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR6 = 0x400000;       // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR5 = 0x200000;       // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR4 = 0x100000;       // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR3 = 0x80000;        // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR2 = 0x40000;        // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR1 = 0x20000;        // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR0 = 0x10000;        // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS15 = 0x8000;        // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS14 = 0x4000;        // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS13 = 0x2000;        // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS12 = 0x1000;        // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS11 = 0x800;         // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS10 = 0x400;         // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS9 = 0x200;          // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS8 = 0x100;          // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS7 = 0x80;           // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS6 = 0x40;           // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS5 = 0x20;           // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS4 = 0x10;           // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS3 = 0x8;            // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS2 = 0x4;            // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS1 = 0x2;            // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS0 = 0x1;            // Port x set bit y (y= 0..15)
    static const uint32_t BSRR_RESET_VALUE = 0x0;

    static constexpr uint32_t LCKR_LCKK = 0x10000;       // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK15 = 0x8000;       // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK14 = 0x4000;       // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK13 = 0x2000;       // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK12 = 0x1000;       // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK11 = 0x800;        // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK10 = 0x400;        // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK9 = 0x200;         // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK8 = 0x100;         // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK7 = 0x80;          // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK6 = 0x40;          // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK5 = 0x20;          // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK4 = 0x10;          // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK3 = 0x8;           // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK2 = 0x4;           // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK1 = 0x2;           // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK0 = 0x1;           // Port x lock bit y (y= 0..15)
    static const uint32_t LCKR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t AFRL_AFRL7 =               // Alternate function selection for port x bit y (y = 0..7) (4 bits)
        bit_field_t<28, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t AFRL_AFRL6 =               // Alternate function selection for port x bit y (y = 0..7) (4 bits)
        bit_field_t<24, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t AFRL_AFRL5 =               // Alternate function selection for port x bit y (y = 0..7) (4 bits)
        bit_field_t<20, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t AFRL_AFRL4 =               // Alternate function selection for port x bit y (y = 0..7) (4 bits)
        bit_field_t<16, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t AFRL_AFRL3 =               // Alternate function selection for port x bit y (y = 0..7) (4 bits)
        bit_field_t<12, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t AFRL_AFRL2 =               // Alternate function selection for port x bit y (y = 0..7) (4 bits)
        bit_field_t<8, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t AFRL_AFRL1 =               // Alternate function selection for port x bit y (y = 0..7) (4 bits)
        bit_field_t<4, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t AFRL_AFRL0 =               // Alternate function selection for port x bit y (y = 0..7) (4 bits)
        bit_field_t<0, 0xf>::value<X>();
    static const uint32_t AFRL_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t AFRH_AFRH15 =              // Alternate function selection for port x bit y (y = 8..15) (4 bits)
        bit_field_t<28, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t AFRH_AFRH14 =              // Alternate function selection for port x bit y (y = 8..15) (4 bits)
        bit_field_t<24, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t AFRH_AFRH13 =              // Alternate function selection for port x bit y (y = 8..15) (4 bits)
        bit_field_t<20, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t AFRH_AFRH12 =              // Alternate function selection for port x bit y (y = 8..15) (4 bits)
        bit_field_t<16, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t AFRH_AFRH11 =              // Alternate function selection for port x bit y (y = 8..15) (4 bits)
        bit_field_t<12, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t AFRH_AFRH10 =              // Alternate function selection for port x bit y (y = 8..15) (4 bits)
        bit_field_t<8, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t AFRH_AFRH9 =               // Alternate function selection for port x bit y (y = 8..15) (4 bits)
        bit_field_t<4, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t AFRH_AFRH8 =               // Alternate function selection for port x bit y (y = 8..15) (4 bits)
        bit_field_t<0, 0xf>::value<X>();
    static const uint32_t AFRH_RESET_VALUE = 0x0;

    static constexpr uint8_t TIM1_TRG_COM_TIM11 = 26; // TIM1 Trigger and Commutation interrupts and TIM11 global interrupt
};

static gpiob_t& GPIOB = *reinterpret_cast<gpiob_t*>(0x40020400);

#define HAVE_PERIPHERAL_GPIOB


////
//
//    General-purpose I/Os
//
////

struct gpioa_t
{
    volatile uint32_t    MODER;                // [Read-write] GPIO port mode register
    volatile uint32_t    OTYPER;               // [Read-write] GPIO port output type register
    volatile uint32_t    OSPEEDR;              // [Read-write] GPIO port output speed register
    volatile uint32_t    PUPDR;                // [Read-write] GPIO port pull-up/pull-down register
    volatile uint32_t    IDR;                  // [Read-only] GPIO port input data register
    volatile uint32_t    ODR;                  // [Read-write] GPIO port output data register
    volatile uint32_t    BSRR;                 // [Write-only] GPIO port bit set/reset register
    volatile uint32_t    LCKR;                 // [Read-write] GPIO port configuration lock register
    volatile uint32_t    AFRL;                 // [Read-write] GPIO alternate function low register
    volatile uint32_t    AFRH;                 // [Read-write] GPIO alternate function high register

    template<uint32_t X>
    static constexpr uint32_t MODER_MODER15 =             // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<30, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER14 =             // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<28, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER13 =             // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<26, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER12 =             // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<24, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER11 =             // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<22, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER10 =             // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<20, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER9 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<18, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER8 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<16, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER7 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<14, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER6 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<12, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER5 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<10, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER4 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<8, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER3 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<6, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER2 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<4, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER1 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<2, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t MODER_MODER0 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<0, 0x3>::value<X>();
    static const uint32_t MODER_RESET_VALUE = 0xa8000000;

    static constexpr uint32_t OTYPER_OT15 = 0x8000;        // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT14 = 0x4000;        // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT13 = 0x2000;        // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT12 = 0x1000;        // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT11 = 0x800;         // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT10 = 0x400;         // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT9 = 0x200;          // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT8 = 0x100;          // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT7 = 0x80;           // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT6 = 0x40;           // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT5 = 0x20;           // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT4 = 0x10;           // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT3 = 0x8;            // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT2 = 0x4;            // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT1 = 0x2;            // Port x configuration bits (y = 0..15)
    static constexpr uint32_t OTYPER_OT0 = 0x1;            // Port x configuration bits (y = 0..15)
    static const uint32_t OTYPER_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR15 =           // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<30, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR14 =           // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<28, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR13 =           // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<26, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR12 =           // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<24, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR11 =           // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<22, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR10 =           // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<20, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR9 =            // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<18, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR8 =            // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<16, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR7 =            // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<14, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR6 =            // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<12, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR5 =            // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<10, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR4 =            // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<8, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR3 =            // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<6, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR2 =            // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<4, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR1 =            // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<2, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OSPEEDR_OSPEEDR0 =            // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<0, 0x3>::value<X>();
    static const uint32_t OSPEEDR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR15 =             // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<30, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR14 =             // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<28, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR13 =             // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<26, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR12 =             // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<24, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR11 =             // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<22, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR10 =             // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<20, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR9 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<18, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR8 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<16, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR7 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<14, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR6 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<12, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR5 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<10, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR4 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<8, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR3 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<6, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR2 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<4, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR1 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<2, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t PUPDR_PUPDR0 =              // Port x configuration bits (y = 0..15) (2 bits)
        bit_field_t<0, 0x3>::value<X>();
    static const uint32_t PUPDR_RESET_VALUE = 0x64000000;

    static constexpr uint32_t IDR_IDR15 = 0x8000;       // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR14 = 0x4000;       // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR13 = 0x2000;       // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR12 = 0x1000;       // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR11 = 0x800;        // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR10 = 0x400;        // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR9 = 0x200;         // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR8 = 0x100;         // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR7 = 0x80;          // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR6 = 0x40;          // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR5 = 0x20;          // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR4 = 0x10;          // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR3 = 0x8;           // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR2 = 0x4;           // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR1 = 0x2;           // Port input data (y = 0..15)
    static constexpr uint32_t IDR_IDR0 = 0x1;           // Port input data (y = 0..15)
    static const uint32_t IDR_RESET_VALUE = 0x0;

    static constexpr uint32_t ODR_ODR15 = 0x8000;       // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR14 = 0x4000;       // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR13 = 0x2000;       // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR12 = 0x1000;       // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR11 = 0x800;        // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR10 = 0x400;        // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR9 = 0x200;         // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR8 = 0x100;         // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR7 = 0x80;          // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR6 = 0x40;          // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR5 = 0x20;          // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR4 = 0x10;          // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR3 = 0x8;           // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR2 = 0x4;           // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR1 = 0x2;           // Port output data (y = 0..15)
    static constexpr uint32_t ODR_ODR0 = 0x1;           // Port output data (y = 0..15)
    static const uint32_t ODR_RESET_VALUE = 0x0;

    static constexpr uint32_t BSRR_BR15 = 0x80000000;    // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR14 = 0x40000000;    // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR13 = 0x20000000;    // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR12 = 0x10000000;    // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR11 = 0x8000000;     // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR10 = 0x4000000;     // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR9 = 0x2000000;      // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR8 = 0x1000000;      // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR7 = 0x800000;       // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR6 = 0x400000;       // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR5 = 0x200000;       // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR4 = 0x100000;       // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR3 = 0x80000;        // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR2 = 0x40000;        // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR1 = 0x20000;        // Port x reset bit y (y = 0..15)
    static constexpr uint32_t BSRR_BR0 = 0x10000;        // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS15 = 0x8000;        // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS14 = 0x4000;        // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS13 = 0x2000;        // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS12 = 0x1000;        // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS11 = 0x800;         // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS10 = 0x400;         // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS9 = 0x200;          // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS8 = 0x100;          // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS7 = 0x80;           // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS6 = 0x40;           // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS5 = 0x20;           // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS4 = 0x10;           // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS3 = 0x8;            // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS2 = 0x4;            // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS1 = 0x2;            // Port x set bit y (y= 0..15)
    static constexpr uint32_t BSRR_BS0 = 0x1;            // Port x set bit y (y= 0..15)
    static const uint32_t BSRR_RESET_VALUE = 0x0;

    static constexpr uint32_t LCKR_LCKK = 0x10000;       // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK15 = 0x8000;       // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK14 = 0x4000;       // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK13 = 0x2000;       // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK12 = 0x1000;       // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK11 = 0x800;        // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK10 = 0x400;        // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK9 = 0x200;         // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK8 = 0x100;         // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK7 = 0x80;          // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK6 = 0x40;          // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK5 = 0x20;          // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK4 = 0x10;          // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK3 = 0x8;           // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK2 = 0x4;           // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK1 = 0x2;           // Port x lock bit y (y= 0..15)
    static constexpr uint32_t LCKR_LCK0 = 0x1;           // Port x lock bit y (y= 0..15)
    static const uint32_t LCKR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t AFRL_AFRL7 =               // Alternate function selection for port x bit y (y = 0..7) (4 bits)
        bit_field_t<28, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t AFRL_AFRL6 =               // Alternate function selection for port x bit y (y = 0..7) (4 bits)
        bit_field_t<24, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t AFRL_AFRL5 =               // Alternate function selection for port x bit y (y = 0..7) (4 bits)
        bit_field_t<20, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t AFRL_AFRL4 =               // Alternate function selection for port x bit y (y = 0..7) (4 bits)
        bit_field_t<16, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t AFRL_AFRL3 =               // Alternate function selection for port x bit y (y = 0..7) (4 bits)
        bit_field_t<12, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t AFRL_AFRL2 =               // Alternate function selection for port x bit y (y = 0..7) (4 bits)
        bit_field_t<8, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t AFRL_AFRL1 =               // Alternate function selection for port x bit y (y = 0..7) (4 bits)
        bit_field_t<4, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t AFRL_AFRL0 =               // Alternate function selection for port x bit y (y = 0..7) (4 bits)
        bit_field_t<0, 0xf>::value<X>();
    static const uint32_t AFRL_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t AFRH_AFRH15 =              // Alternate function selection for port x bit y (y = 8..15) (4 bits)
        bit_field_t<28, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t AFRH_AFRH14 =              // Alternate function selection for port x bit y (y = 8..15) (4 bits)
        bit_field_t<24, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t AFRH_AFRH13 =              // Alternate function selection for port x bit y (y = 8..15) (4 bits)
        bit_field_t<20, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t AFRH_AFRH12 =              // Alternate function selection for port x bit y (y = 8..15) (4 bits)
        bit_field_t<16, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t AFRH_AFRH11 =              // Alternate function selection for port x bit y (y = 8..15) (4 bits)
        bit_field_t<12, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t AFRH_AFRH10 =              // Alternate function selection for port x bit y (y = 8..15) (4 bits)
        bit_field_t<8, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t AFRH_AFRH9 =               // Alternate function selection for port x bit y (y = 8..15) (4 bits)
        bit_field_t<4, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t AFRH_AFRH8 =               // Alternate function selection for port x bit y (y = 8..15) (4 bits)
        bit_field_t<0, 0xf>::value<X>();
    static const uint32_t AFRH_RESET_VALUE = 0x0;

    static constexpr uint8_t TIM2 = 28; // TIM2 global interrupt
};

static gpioa_t& GPIOA = *reinterpret_cast<gpioa_t*>(0x40020000);

#define HAVE_PERIPHERAL_GPIOA


////
//
//    Inter-integrated circuit
//
////

struct i2c3_t
{
    volatile uint32_t    CR1;                  // [Read-write] Control register 1
    volatile uint32_t    CR2;                  // [Read-write] Control register 2
    volatile uint32_t    OAR1;                 // [Read-write] Own address register 1
    volatile uint32_t    OAR2;                 // [Read-write] Own address register 2
    volatile uint32_t    DR;                   // [Read-write] Data register
    volatile uint32_t    SR1;                  // Status register 1
    volatile uint32_t    SR2;                  // [Read-only] Status register 2
    volatile uint32_t    CCR;                  // [Read-write] Clock control register
    volatile uint32_t    TRISE;                // [Read-write] TRISE register

    static constexpr uint32_t CR1_SWRST = 0x8000;       // Software reset
    static constexpr uint32_t CR1_ALERT = 0x2000;       // SMBus alert
    static constexpr uint32_t CR1_PEC = 0x1000;         // Packet error checking
    static constexpr uint32_t CR1_POS = 0x800;          // Acknowledge/PEC Position (for data reception)
    static constexpr uint32_t CR1_ACK = 0x400;          // Acknowledge enable
    static constexpr uint32_t CR1_STOP = 0x200;         // Stop generation
    static constexpr uint32_t CR1_START = 0x100;        // Start generation
    static constexpr uint32_t CR1_NOSTRETCH = 0x80;     // Clock stretching disable (Slave mode)
    static constexpr uint32_t CR1_ENGC = 0x40;          // General call enable
    static constexpr uint32_t CR1_ENPEC = 0x20;         // PEC enable
    static constexpr uint32_t CR1_ENARP = 0x10;         // ARP enable
    static constexpr uint32_t CR1_SMBTYPE = 0x8;        // SMBus type
    static constexpr uint32_t CR1_SMBUS = 0x2;          // SMBus mode
    static constexpr uint32_t CR1_PE = 0x1;             // Peripheral enable
    static const uint32_t CR1_RESET_VALUE = 0x0;

    static constexpr uint32_t CR2_LAST = 0x1000;        // DMA last transfer
    static constexpr uint32_t CR2_DMAEN = 0x800;        // DMA requests enable
    static constexpr uint32_t CR2_ITBUFEN = 0x400;      // Buffer interrupt enable
    static constexpr uint32_t CR2_ITEVTEN = 0x200;      // Event interrupt enable
    static constexpr uint32_t CR2_ITERREN = 0x100;      // Error interrupt enable
    template<uint32_t X>
    static constexpr uint32_t CR2_FREQ =                // Peripheral clock frequency (6 bits)
        bit_field_t<0, 0x3f>::value<X>();
    static const uint32_t CR2_RESET_VALUE = 0x0;

    static constexpr uint32_t OAR1_ADDMODE = 0x8000;     // Addressing mode (slave mode)
    template<uint32_t X>
    static constexpr uint32_t OAR1_ADD10 =               // Interface address (2 bits)
        bit_field_t<8, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OAR1_ADD7 =                // Interface address (7 bits)
        bit_field_t<1, 0x7f>::value<X>();
    static constexpr uint32_t OAR1_ADD0 = 0x1;           // Interface address
    static const uint32_t OAR1_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t OAR2_ADD2 =                // Interface address (7 bits)
        bit_field_t<1, 0x7f>::value<X>();
    static constexpr uint32_t OAR2_ENDUAL = 0x1;         // Dual addressing mode enable
    static const uint32_t OAR2_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t DR_DR =                  // 8-bit data register (8 bits)
        bit_field_t<0, 0xff>::value<X>();
    static const uint32_t DR_RESET_VALUE = 0x0;

    static constexpr uint32_t SR1_SMBALERT = 0x8000;    // SMBus alert, Read-write
    static constexpr uint32_t SR1_TIMEOUT = 0x4000;     // Timeout or Tlow error, Read-write
    static constexpr uint32_t SR1_PECERR = 0x1000;      // PEC Error in reception, Read-write
    static constexpr uint32_t SR1_OVR = 0x800;          // Overrun/Underrun, Read-write
    static constexpr uint32_t SR1_AF = 0x400;           // Acknowledge failure, Read-write
    static constexpr uint32_t SR1_ARLO = 0x200;         // Arbitration lost (master mode), Read-write
    static constexpr uint32_t SR1_BERR = 0x100;         // Bus error, Read-write
    static constexpr uint32_t SR1_TxE = 0x80;           // Data register empty (transmitters), Read-only
    static constexpr uint32_t SR1_RxNE = 0x40;          // Data register not empty (receivers), Read-only
    static constexpr uint32_t SR1_STOPF = 0x10;         // Stop detection (slave mode), Read-only
    static constexpr uint32_t SR1_ADD10 = 0x8;          // 10-bit header sent (Master mode), Read-only
    static constexpr uint32_t SR1_BTF = 0x4;            // Byte transfer finished, Read-only
    static constexpr uint32_t SR1_ADDR = 0x2;           // Address sent (master mode)/matched (slave mode), Read-only
    static constexpr uint32_t SR1_SB = 0x1;             // Start bit (Master mode), Read-only
    static const uint32_t SR1_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t SR2_PEC =                 // acket error checking register (8 bits)
        bit_field_t<8, 0xff>::value<X>();
    static constexpr uint32_t SR2_DUALF = 0x80;         // Dual flag (Slave mode)
    static constexpr uint32_t SR2_SMBHOST = 0x40;       // SMBus host header (Slave mode)
    static constexpr uint32_t SR2_SMBDEFAULT = 0x20;    // SMBus device default address (Slave mode)
    static constexpr uint32_t SR2_GENCALL = 0x10;       // General call address (Slave mode)
    static constexpr uint32_t SR2_TRA = 0x4;            // Transmitter/receiver
    static constexpr uint32_t SR2_BUSY = 0x2;           // Bus busy
    static constexpr uint32_t SR2_MSL = 0x1;            // Master/slave
    static const uint32_t SR2_RESET_VALUE = 0x0;

    static constexpr uint32_t CCR_F_S = 0x8000;         // I2C master mode selection
    static constexpr uint32_t CCR_DUTY = 0x4000;        // Fast mode duty cycle
    template<uint32_t X>
    static constexpr uint32_t CCR_CCR =                 // Clock control register in Fast/Standard mode (Master mode) (12 bits)
        bit_field_t<0, 0xfff>::value<X>();
    static const uint32_t CCR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t TRISE_TRISE =               // Maximum rise time in Fast/Standard mode (Master mode) (6 bits)
        bit_field_t<0, 0x3f>::value<X>();
    static const uint32_t TRISE_RESET_VALUE = 0x2;

    static constexpr uint8_t TIM3 = 29; // TIM3 global interrupt
    static constexpr uint8_t TIM4 = 30; // TIM4 global interrupt
    static constexpr uint8_t TIM5 = 50; // TIM5 global interrupt
};

static i2c3_t& I2C3 = *reinterpret_cast<i2c3_t*>(0x40005c00);

#define HAVE_PERIPHERAL_I2C3


////
//
//    Inter-integrated circuit
//
////

struct i2c2_t
{
    volatile uint32_t    CR1;                  // [Read-write] Control register 1
    volatile uint32_t    CR2;                  // [Read-write] Control register 2
    volatile uint32_t    OAR1;                 // [Read-write] Own address register 1
    volatile uint32_t    OAR2;                 // [Read-write] Own address register 2
    volatile uint32_t    DR;                   // [Read-write] Data register
    volatile uint32_t    SR1;                  // Status register 1
    volatile uint32_t    SR2;                  // [Read-only] Status register 2
    volatile uint32_t    CCR;                  // [Read-write] Clock control register
    volatile uint32_t    TRISE;                // [Read-write] TRISE register

    static constexpr uint32_t CR1_SWRST = 0x8000;       // Software reset
    static constexpr uint32_t CR1_ALERT = 0x2000;       // SMBus alert
    static constexpr uint32_t CR1_PEC = 0x1000;         // Packet error checking
    static constexpr uint32_t CR1_POS = 0x800;          // Acknowledge/PEC Position (for data reception)
    static constexpr uint32_t CR1_ACK = 0x400;          // Acknowledge enable
    static constexpr uint32_t CR1_STOP = 0x200;         // Stop generation
    static constexpr uint32_t CR1_START = 0x100;        // Start generation
    static constexpr uint32_t CR1_NOSTRETCH = 0x80;     // Clock stretching disable (Slave mode)
    static constexpr uint32_t CR1_ENGC = 0x40;          // General call enable
    static constexpr uint32_t CR1_ENPEC = 0x20;         // PEC enable
    static constexpr uint32_t CR1_ENARP = 0x10;         // ARP enable
    static constexpr uint32_t CR1_SMBTYPE = 0x8;        // SMBus type
    static constexpr uint32_t CR1_SMBUS = 0x2;          // SMBus mode
    static constexpr uint32_t CR1_PE = 0x1;             // Peripheral enable
    static const uint32_t CR1_RESET_VALUE = 0x0;

    static constexpr uint32_t CR2_LAST = 0x1000;        // DMA last transfer
    static constexpr uint32_t CR2_DMAEN = 0x800;        // DMA requests enable
    static constexpr uint32_t CR2_ITBUFEN = 0x400;      // Buffer interrupt enable
    static constexpr uint32_t CR2_ITEVTEN = 0x200;      // Event interrupt enable
    static constexpr uint32_t CR2_ITERREN = 0x100;      // Error interrupt enable
    template<uint32_t X>
    static constexpr uint32_t CR2_FREQ =                // Peripheral clock frequency (6 bits)
        bit_field_t<0, 0x3f>::value<X>();
    static const uint32_t CR2_RESET_VALUE = 0x0;

    static constexpr uint32_t OAR1_ADDMODE = 0x8000;     // Addressing mode (slave mode)
    template<uint32_t X>
    static constexpr uint32_t OAR1_ADD10 =               // Interface address (2 bits)
        bit_field_t<8, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OAR1_ADD7 =                // Interface address (7 bits)
        bit_field_t<1, 0x7f>::value<X>();
    static constexpr uint32_t OAR1_ADD0 = 0x1;           // Interface address
    static const uint32_t OAR1_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t OAR2_ADD2 =                // Interface address (7 bits)
        bit_field_t<1, 0x7f>::value<X>();
    static constexpr uint32_t OAR2_ENDUAL = 0x1;         // Dual addressing mode enable
    static const uint32_t OAR2_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t DR_DR =                  // 8-bit data register (8 bits)
        bit_field_t<0, 0xff>::value<X>();
    static const uint32_t DR_RESET_VALUE = 0x0;

    static constexpr uint32_t SR1_SMBALERT = 0x8000;    // SMBus alert, Read-write
    static constexpr uint32_t SR1_TIMEOUT = 0x4000;     // Timeout or Tlow error, Read-write
    static constexpr uint32_t SR1_PECERR = 0x1000;      // PEC Error in reception, Read-write
    static constexpr uint32_t SR1_OVR = 0x800;          // Overrun/Underrun, Read-write
    static constexpr uint32_t SR1_AF = 0x400;           // Acknowledge failure, Read-write
    static constexpr uint32_t SR1_ARLO = 0x200;         // Arbitration lost (master mode), Read-write
    static constexpr uint32_t SR1_BERR = 0x100;         // Bus error, Read-write
    static constexpr uint32_t SR1_TxE = 0x80;           // Data register empty (transmitters), Read-only
    static constexpr uint32_t SR1_RxNE = 0x40;          // Data register not empty (receivers), Read-only
    static constexpr uint32_t SR1_STOPF = 0x10;         // Stop detection (slave mode), Read-only
    static constexpr uint32_t SR1_ADD10 = 0x8;          // 10-bit header sent (Master mode), Read-only
    static constexpr uint32_t SR1_BTF = 0x4;            // Byte transfer finished, Read-only
    static constexpr uint32_t SR1_ADDR = 0x2;           // Address sent (master mode)/matched (slave mode), Read-only
    static constexpr uint32_t SR1_SB = 0x1;             // Start bit (Master mode), Read-only
    static const uint32_t SR1_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t SR2_PEC =                 // acket error checking register (8 bits)
        bit_field_t<8, 0xff>::value<X>();
    static constexpr uint32_t SR2_DUALF = 0x80;         // Dual flag (Slave mode)
    static constexpr uint32_t SR2_SMBHOST = 0x40;       // SMBus host header (Slave mode)
    static constexpr uint32_t SR2_SMBDEFAULT = 0x20;    // SMBus device default address (Slave mode)
    static constexpr uint32_t SR2_GENCALL = 0x10;       // General call address (Slave mode)
    static constexpr uint32_t SR2_TRA = 0x4;            // Transmitter/receiver
    static constexpr uint32_t SR2_BUSY = 0x2;           // Bus busy
    static constexpr uint32_t SR2_MSL = 0x1;            // Master/slave
    static const uint32_t SR2_RESET_VALUE = 0x0;

    static constexpr uint32_t CCR_F_S = 0x8000;         // I2C master mode selection
    static constexpr uint32_t CCR_DUTY = 0x4000;        // Fast mode duty cycle
    template<uint32_t X>
    static constexpr uint32_t CCR_CCR =                 // Clock control register in Fast/Standard mode (Master mode) (12 bits)
        bit_field_t<0, 0xfff>::value<X>();
    static const uint32_t CCR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t TRISE_TRISE =               // Maximum rise time in Fast/Standard mode (Master mode) (6 bits)
        bit_field_t<0, 0x3f>::value<X>();
    static const uint32_t TRISE_RESET_VALUE = 0x2;

    static constexpr uint8_t I2C3_ER = 73; // I2C3 error interrupt
    static constexpr uint8_t I2C3_EV = 72; // I2C3 event interrupt
};

static i2c2_t& I2C2 = *reinterpret_cast<i2c2_t*>(0x40005800);

#define HAVE_PERIPHERAL_I2C2


////
//
//    Inter-integrated circuit
//
////

struct i2c1_t
{
    volatile uint32_t    CR1;                  // [Read-write] Control register 1
    volatile uint32_t    CR2;                  // [Read-write] Control register 2
    volatile uint32_t    OAR1;                 // [Read-write] Own address register 1
    volatile uint32_t    OAR2;                 // [Read-write] Own address register 2
    volatile uint32_t    DR;                   // [Read-write] Data register
    volatile uint32_t    SR1;                  // Status register 1
    volatile uint32_t    SR2;                  // [Read-only] Status register 2
    volatile uint32_t    CCR;                  // [Read-write] Clock control register
    volatile uint32_t    TRISE;                // [Read-write] TRISE register

    static constexpr uint32_t CR1_SWRST = 0x8000;       // Software reset
    static constexpr uint32_t CR1_ALERT = 0x2000;       // SMBus alert
    static constexpr uint32_t CR1_PEC = 0x1000;         // Packet error checking
    static constexpr uint32_t CR1_POS = 0x800;          // Acknowledge/PEC Position (for data reception)
    static constexpr uint32_t CR1_ACK = 0x400;          // Acknowledge enable
    static constexpr uint32_t CR1_STOP = 0x200;         // Stop generation
    static constexpr uint32_t CR1_START = 0x100;        // Start generation
    static constexpr uint32_t CR1_NOSTRETCH = 0x80;     // Clock stretching disable (Slave mode)
    static constexpr uint32_t CR1_ENGC = 0x40;          // General call enable
    static constexpr uint32_t CR1_ENPEC = 0x20;         // PEC enable
    static constexpr uint32_t CR1_ENARP = 0x10;         // ARP enable
    static constexpr uint32_t CR1_SMBTYPE = 0x8;        // SMBus type
    static constexpr uint32_t CR1_SMBUS = 0x2;          // SMBus mode
    static constexpr uint32_t CR1_PE = 0x1;             // Peripheral enable
    static const uint32_t CR1_RESET_VALUE = 0x0;

    static constexpr uint32_t CR2_LAST = 0x1000;        // DMA last transfer
    static constexpr uint32_t CR2_DMAEN = 0x800;        // DMA requests enable
    static constexpr uint32_t CR2_ITBUFEN = 0x400;      // Buffer interrupt enable
    static constexpr uint32_t CR2_ITEVTEN = 0x200;      // Event interrupt enable
    static constexpr uint32_t CR2_ITERREN = 0x100;      // Error interrupt enable
    template<uint32_t X>
    static constexpr uint32_t CR2_FREQ =                // Peripheral clock frequency (6 bits)
        bit_field_t<0, 0x3f>::value<X>();
    static const uint32_t CR2_RESET_VALUE = 0x0;

    static constexpr uint32_t OAR1_ADDMODE = 0x8000;     // Addressing mode (slave mode)
    template<uint32_t X>
    static constexpr uint32_t OAR1_ADD10 =               // Interface address (2 bits)
        bit_field_t<8, 0x3>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t OAR1_ADD7 =                // Interface address (7 bits)
        bit_field_t<1, 0x7f>::value<X>();
    static constexpr uint32_t OAR1_ADD0 = 0x1;           // Interface address
    static const uint32_t OAR1_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t OAR2_ADD2 =                // Interface address (7 bits)
        bit_field_t<1, 0x7f>::value<X>();
    static constexpr uint32_t OAR2_ENDUAL = 0x1;         // Dual addressing mode enable
    static const uint32_t OAR2_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t DR_DR =                  // 8-bit data register (8 bits)
        bit_field_t<0, 0xff>::value<X>();
    static const uint32_t DR_RESET_VALUE = 0x0;

    static constexpr uint32_t SR1_SMBALERT = 0x8000;    // SMBus alert, Read-write
    static constexpr uint32_t SR1_TIMEOUT = 0x4000;     // Timeout or Tlow error, Read-write
    static constexpr uint32_t SR1_PECERR = 0x1000;      // PEC Error in reception, Read-write
    static constexpr uint32_t SR1_OVR = 0x800;          // Overrun/Underrun, Read-write
    static constexpr uint32_t SR1_AF = 0x400;           // Acknowledge failure, Read-write
    static constexpr uint32_t SR1_ARLO = 0x200;         // Arbitration lost (master mode), Read-write
    static constexpr uint32_t SR1_BERR = 0x100;         // Bus error, Read-write
    static constexpr uint32_t SR1_TxE = 0x80;           // Data register empty (transmitters), Read-only
    static constexpr uint32_t SR1_RxNE = 0x40;          // Data register not empty (receivers), Read-only
    static constexpr uint32_t SR1_STOPF = 0x10;         // Stop detection (slave mode), Read-only
    static constexpr uint32_t SR1_ADD10 = 0x8;          // 10-bit header sent (Master mode), Read-only
    static constexpr uint32_t SR1_BTF = 0x4;            // Byte transfer finished, Read-only
    static constexpr uint32_t SR1_ADDR = 0x2;           // Address sent (master mode)/matched (slave mode), Read-only
    static constexpr uint32_t SR1_SB = 0x1;             // Start bit (Master mode), Read-only
    static const uint32_t SR1_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t SR2_PEC =                 // acket error checking register (8 bits)
        bit_field_t<8, 0xff>::value<X>();
    static constexpr uint32_t SR2_DUALF = 0x80;         // Dual flag (Slave mode)
    static constexpr uint32_t SR2_SMBHOST = 0x40;       // SMBus host header (Slave mode)
    static constexpr uint32_t SR2_SMBDEFAULT = 0x20;    // SMBus device default address (Slave mode)
    static constexpr uint32_t SR2_GENCALL = 0x10;       // General call address (Slave mode)
    static constexpr uint32_t SR2_TRA = 0x4;            // Transmitter/receiver
    static constexpr uint32_t SR2_BUSY = 0x2;           // Bus busy
    static constexpr uint32_t SR2_MSL = 0x1;            // Master/slave
    static const uint32_t SR2_RESET_VALUE = 0x0;

    static constexpr uint32_t CCR_F_S = 0x8000;         // I2C master mode selection
    static constexpr uint32_t CCR_DUTY = 0x4000;        // Fast mode duty cycle
    template<uint32_t X>
    static constexpr uint32_t CCR_CCR =                 // Clock control register in Fast/Standard mode (Master mode) (12 bits)
        bit_field_t<0, 0xfff>::value<X>();
    static const uint32_t CCR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t TRISE_TRISE =               // Maximum rise time in Fast/Standard mode (Master mode) (6 bits)
        bit_field_t<0, 0x3f>::value<X>();
    static const uint32_t TRISE_RESET_VALUE = 0x2;

    static constexpr uint8_t I2C2_ER = 34; // I2C2 error interrupt
    static constexpr uint8_t I2C2_EV = 33; // I2C2 event interrupt
};

static i2c1_t& I2C1 = *reinterpret_cast<i2c1_t*>(0x40005400);

#define HAVE_PERIPHERAL_I2C1


////
//
//    Serial peripheral interface
//
////

struct i2s2ext_t
{
    volatile uint32_t    CR1;                  // [Read-write] control register 1
    volatile uint32_t    CR2;                  // [Read-write] control register 2
    volatile uint32_t    SR;                   // status register
    volatile uint32_t    DR;                   // [Read-write] data register
    volatile uint32_t    CRCPR;                // [Read-write] CRC polynomial register
    volatile uint32_t    RXCRCR;               // [Read-only] RX CRC register
    volatile uint32_t    TXCRCR;               // [Read-only] TX CRC register
    volatile uint32_t    I2SCFGR;              // [Read-write] I2S configuration register
    volatile uint32_t    I2SPR;                // [Read-write] I2S prescaler register

    static constexpr uint32_t CR1_BIDIMODE = 0x8000;    // Bidirectional data mode enable
    static constexpr uint32_t CR1_BIDIOE = 0x4000;      // Output enable in bidirectional mode
    static constexpr uint32_t CR1_CRCEN = 0x2000;       // Hardware CRC calculation enable
    static constexpr uint32_t CR1_CRCNEXT = 0x1000;     // CRC transfer next
    static constexpr uint32_t CR1_DFF = 0x800;          // Data frame format
    static constexpr uint32_t CR1_RXONLY = 0x400;       // Receive only
    static constexpr uint32_t CR1_SSM = 0x200;          // Software slave management
    static constexpr uint32_t CR1_SSI = 0x100;          // Internal slave select
    static constexpr uint32_t CR1_LSBFIRST = 0x80;      // Frame format
    static constexpr uint32_t CR1_SPE = 0x40;           // SPI enable
    template<uint32_t X>
    static constexpr uint32_t CR1_BR =                  // Baud rate control (3 bits)
        bit_field_t<3, 0x7>::value<X>();
    static constexpr uint32_t CR1_MSTR = 0x4;           // Master selection
    static constexpr uint32_t CR1_CPOL = 0x2;           // Clock polarity
    static constexpr uint32_t CR1_CPHA = 0x1;           // Clock phase
    static const uint32_t CR1_RESET_VALUE = 0x0;

    static constexpr uint32_t CR2_TXEIE = 0x80;         // Tx buffer empty interrupt enable
    static constexpr uint32_t CR2_RXNEIE = 0x40;        // RX buffer not empty interrupt enable
    static constexpr uint32_t CR2_ERRIE = 0x20;         // Error interrupt enable
    static constexpr uint32_t CR2_FRF = 0x10;           // Frame format
    static constexpr uint32_t CR2_SSOE = 0x4;           // SS output enable
    static constexpr uint32_t CR2_TXDMAEN = 0x2;        // Tx buffer DMA enable
    static constexpr uint32_t CR2_RXDMAEN = 0x1;        // Rx buffer DMA enable
    static const uint32_t CR2_RESET_VALUE = 0x0;

    static constexpr uint32_t SR_TIFRFE = 0x100;       // TI frame format error, Read-only
    static constexpr uint32_t SR_BSY = 0x80;           // Busy flag, Read-only
    static constexpr uint32_t SR_OVR = 0x40;           // Overrun flag, Read-only
    static constexpr uint32_t SR_MODF = 0x20;          // Mode fault, Read-only
    static constexpr uint32_t SR_CRCERR = 0x10;        // CRC error flag, Read-write
    static constexpr uint32_t SR_UDR = 0x8;            // Underrun flag, Read-only
    static constexpr uint32_t SR_CHSIDE = 0x4;         // Channel side, Read-only
    static constexpr uint32_t SR_TXE = 0x2;            // Transmit buffer empty, Read-only
    static constexpr uint32_t SR_RXNE = 0x1;           // Receive buffer not empty, Read-only
    static const uint32_t SR_RESET_VALUE = 0x2;

    template<uint32_t X>
    static constexpr uint32_t DR_DR =                  // Data register (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t DR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t CRCPR_CRCPOLY =             // CRC polynomial register (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t CRCPR_RESET_VALUE = 0x7;

    template<uint32_t X>
    static constexpr uint32_t RXCRCR_RxCRC =               // Rx CRC register (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t RXCRCR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t TXCRCR_TxCRC =               // Tx CRC register (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t TXCRCR_RESET_VALUE = 0x0;

    static constexpr uint32_t I2SCFGR_I2SMOD = 0x800;       // I2S mode selection
    static constexpr uint32_t I2SCFGR_I2SE = 0x400;         // I2S Enable
    template<uint32_t X>
    static constexpr uint32_t I2SCFGR_I2SCFG =              // I2S configuration mode (2 bits)
        bit_field_t<8, 0x3>::value<X>();
    static constexpr uint32_t I2SCFGR_PCMSYNC = 0x80;       // PCM frame synchronization
    template<uint32_t X>
    static constexpr uint32_t I2SCFGR_I2SSTD =              // I2S standard selection (2 bits)
        bit_field_t<4, 0x3>::value<X>();
    static constexpr uint32_t I2SCFGR_CKPOL = 0x8;          // Steady state clock polarity
    template<uint32_t X>
    static constexpr uint32_t I2SCFGR_DATLEN =              // Data length to be transferred (2 bits)
        bit_field_t<1, 0x3>::value<X>();
    static constexpr uint32_t I2SCFGR_CHLEN = 0x1;          // Channel length (number of bits per audio channel)
    static const uint32_t I2SCFGR_RESET_VALUE = 0x0;

    static constexpr uint32_t I2SPR_MCKOE = 0x200;        // Master clock output enable
    static constexpr uint32_t I2SPR_ODD = 0x100;          // Odd factor for the prescaler
    template<uint32_t X>
    static constexpr uint32_t I2SPR_I2SDIV =              // I2S Linear prescaler (8 bits)
        bit_field_t<0, 0xff>::value<X>();
    static const uint32_t I2SPR_RESET_VALUE = 0xa;

    static constexpr uint8_t I2C1_ER = 32; // I2C1 error interrupt
    static constexpr uint8_t I2C1_EV = 31; // I2C1 event interrupt
};

static i2s2ext_t& I2S2EXT = *reinterpret_cast<i2s2ext_t*>(0x40003400);

#define HAVE_PERIPHERAL_I2S2EXT


////
//
//    Serial peripheral interface
//
////

struct i2s3ext_t
{
    volatile uint32_t    CR1;                  // [Read-write] control register 1
    volatile uint32_t    CR2;                  // [Read-write] control register 2
    volatile uint32_t    SR;                   // status register
    volatile uint32_t    DR;                   // [Read-write] data register
    volatile uint32_t    CRCPR;                // [Read-write] CRC polynomial register
    volatile uint32_t    RXCRCR;               // [Read-only] RX CRC register
    volatile uint32_t    TXCRCR;               // [Read-only] TX CRC register
    volatile uint32_t    I2SCFGR;              // [Read-write] I2S configuration register
    volatile uint32_t    I2SPR;                // [Read-write] I2S prescaler register

    static constexpr uint32_t CR1_BIDIMODE = 0x8000;    // Bidirectional data mode enable
    static constexpr uint32_t CR1_BIDIOE = 0x4000;      // Output enable in bidirectional mode
    static constexpr uint32_t CR1_CRCEN = 0x2000;       // Hardware CRC calculation enable
    static constexpr uint32_t CR1_CRCNEXT = 0x1000;     // CRC transfer next
    static constexpr uint32_t CR1_DFF = 0x800;          // Data frame format
    static constexpr uint32_t CR1_RXONLY = 0x400;       // Receive only
    static constexpr uint32_t CR1_SSM = 0x200;          // Software slave management
    static constexpr uint32_t CR1_SSI = 0x100;          // Internal slave select
    static constexpr uint32_t CR1_LSBFIRST = 0x80;      // Frame format
    static constexpr uint32_t CR1_SPE = 0x40;           // SPI enable
    template<uint32_t X>
    static constexpr uint32_t CR1_BR =                  // Baud rate control (3 bits)
        bit_field_t<3, 0x7>::value<X>();
    static constexpr uint32_t CR1_MSTR = 0x4;           // Master selection
    static constexpr uint32_t CR1_CPOL = 0x2;           // Clock polarity
    static constexpr uint32_t CR1_CPHA = 0x1;           // Clock phase
    static const uint32_t CR1_RESET_VALUE = 0x0;

    static constexpr uint32_t CR2_TXEIE = 0x80;         // Tx buffer empty interrupt enable
    static constexpr uint32_t CR2_RXNEIE = 0x40;        // RX buffer not empty interrupt enable
    static constexpr uint32_t CR2_ERRIE = 0x20;         // Error interrupt enable
    static constexpr uint32_t CR2_FRF = 0x10;           // Frame format
    static constexpr uint32_t CR2_SSOE = 0x4;           // SS output enable
    static constexpr uint32_t CR2_TXDMAEN = 0x2;        // Tx buffer DMA enable
    static constexpr uint32_t CR2_RXDMAEN = 0x1;        // Rx buffer DMA enable
    static const uint32_t CR2_RESET_VALUE = 0x0;

    static constexpr uint32_t SR_TIFRFE = 0x100;       // TI frame format error, Read-only
    static constexpr uint32_t SR_BSY = 0x80;           // Busy flag, Read-only
    static constexpr uint32_t SR_OVR = 0x40;           // Overrun flag, Read-only
    static constexpr uint32_t SR_MODF = 0x20;          // Mode fault, Read-only
    static constexpr uint32_t SR_CRCERR = 0x10;        // CRC error flag, Read-write
    static constexpr uint32_t SR_UDR = 0x8;            // Underrun flag, Read-only
    static constexpr uint32_t SR_CHSIDE = 0x4;         // Channel side, Read-only
    static constexpr uint32_t SR_TXE = 0x2;            // Transmit buffer empty, Read-only
    static constexpr uint32_t SR_RXNE = 0x1;           // Receive buffer not empty, Read-only
    static const uint32_t SR_RESET_VALUE = 0x2;

    template<uint32_t X>
    static constexpr uint32_t DR_DR =                  // Data register (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t DR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t CRCPR_CRCPOLY =             // CRC polynomial register (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t CRCPR_RESET_VALUE = 0x7;

    template<uint32_t X>
    static constexpr uint32_t RXCRCR_RxCRC =               // Rx CRC register (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t RXCRCR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t TXCRCR_TxCRC =               // Tx CRC register (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t TXCRCR_RESET_VALUE = 0x0;

    static constexpr uint32_t I2SCFGR_I2SMOD = 0x800;       // I2S mode selection
    static constexpr uint32_t I2SCFGR_I2SE = 0x400;         // I2S Enable
    template<uint32_t X>
    static constexpr uint32_t I2SCFGR_I2SCFG =              // I2S configuration mode (2 bits)
        bit_field_t<8, 0x3>::value<X>();
    static constexpr uint32_t I2SCFGR_PCMSYNC = 0x80;       // PCM frame synchronization
    template<uint32_t X>
    static constexpr uint32_t I2SCFGR_I2SSTD =              // I2S standard selection (2 bits)
        bit_field_t<4, 0x3>::value<X>();
    static constexpr uint32_t I2SCFGR_CKPOL = 0x8;          // Steady state clock polarity
    template<uint32_t X>
    static constexpr uint32_t I2SCFGR_DATLEN =              // Data length to be transferred (2 bits)
        bit_field_t<1, 0x3>::value<X>();
    static constexpr uint32_t I2SCFGR_CHLEN = 0x1;          // Channel length (number of bits per audio channel)
    static const uint32_t I2SCFGR_RESET_VALUE = 0x0;

    static constexpr uint32_t I2SPR_MCKOE = 0x200;        // Master clock output enable
    static constexpr uint32_t I2SPR_ODD = 0x100;          // Odd factor for the prescaler
    template<uint32_t X>
    static constexpr uint32_t I2SPR_I2SDIV =              // I2S Linear prescaler (8 bits)
        bit_field_t<0, 0xff>::value<X>();
    static const uint32_t I2SPR_RESET_VALUE = 0xa;
};

static i2s3ext_t& I2S3EXT = *reinterpret_cast<i2s3ext_t*>(0x40004000);

#define HAVE_PERIPHERAL_I2S3EXT


////
//
//    Serial peripheral interface
//
////

struct spi1_t
{
    volatile uint32_t    CR1;                  // [Read-write] control register 1
    volatile uint32_t    CR2;                  // [Read-write] control register 2
    volatile uint32_t    SR;                   // status register
    volatile uint32_t    DR;                   // [Read-write] data register
    volatile uint32_t    CRCPR;                // [Read-write] CRC polynomial register
    volatile uint32_t    RXCRCR;               // [Read-only] RX CRC register
    volatile uint32_t    TXCRCR;               // [Read-only] TX CRC register
    volatile uint32_t    I2SCFGR;              // [Read-write] I2S configuration register
    volatile uint32_t    I2SPR;                // [Read-write] I2S prescaler register

    static constexpr uint32_t CR1_BIDIMODE = 0x8000;    // Bidirectional data mode enable
    static constexpr uint32_t CR1_BIDIOE = 0x4000;      // Output enable in bidirectional mode
    static constexpr uint32_t CR1_CRCEN = 0x2000;       // Hardware CRC calculation enable
    static constexpr uint32_t CR1_CRCNEXT = 0x1000;     // CRC transfer next
    static constexpr uint32_t CR1_DFF = 0x800;          // Data frame format
    static constexpr uint32_t CR1_RXONLY = 0x400;       // Receive only
    static constexpr uint32_t CR1_SSM = 0x200;          // Software slave management
    static constexpr uint32_t CR1_SSI = 0x100;          // Internal slave select
    static constexpr uint32_t CR1_LSBFIRST = 0x80;      // Frame format
    static constexpr uint32_t CR1_SPE = 0x40;           // SPI enable
    template<uint32_t X>
    static constexpr uint32_t CR1_BR =                  // Baud rate control (3 bits)
        bit_field_t<3, 0x7>::value<X>();
    static constexpr uint32_t CR1_MSTR = 0x4;           // Master selection
    static constexpr uint32_t CR1_CPOL = 0x2;           // Clock polarity
    static constexpr uint32_t CR1_CPHA = 0x1;           // Clock phase
    static const uint32_t CR1_RESET_VALUE = 0x0;

    static constexpr uint32_t CR2_TXEIE = 0x80;         // Tx buffer empty interrupt enable
    static constexpr uint32_t CR2_RXNEIE = 0x40;        // RX buffer not empty interrupt enable
    static constexpr uint32_t CR2_ERRIE = 0x20;         // Error interrupt enable
    static constexpr uint32_t CR2_FRF = 0x10;           // Frame format
    static constexpr uint32_t CR2_SSOE = 0x4;           // SS output enable
    static constexpr uint32_t CR2_TXDMAEN = 0x2;        // Tx buffer DMA enable
    static constexpr uint32_t CR2_RXDMAEN = 0x1;        // Rx buffer DMA enable
    static const uint32_t CR2_RESET_VALUE = 0x0;

    static constexpr uint32_t SR_TIFRFE = 0x100;       // TI frame format error, Read-only
    static constexpr uint32_t SR_BSY = 0x80;           // Busy flag, Read-only
    static constexpr uint32_t SR_OVR = 0x40;           // Overrun flag, Read-only
    static constexpr uint32_t SR_MODF = 0x20;          // Mode fault, Read-only
    static constexpr uint32_t SR_CRCERR = 0x10;        // CRC error flag, Read-write
    static constexpr uint32_t SR_UDR = 0x8;            // Underrun flag, Read-only
    static constexpr uint32_t SR_CHSIDE = 0x4;         // Channel side, Read-only
    static constexpr uint32_t SR_TXE = 0x2;            // Transmit buffer empty, Read-only
    static constexpr uint32_t SR_RXNE = 0x1;           // Receive buffer not empty, Read-only
    static const uint32_t SR_RESET_VALUE = 0x2;

    template<uint32_t X>
    static constexpr uint32_t DR_DR =                  // Data register (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t DR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t CRCPR_CRCPOLY =             // CRC polynomial register (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t CRCPR_RESET_VALUE = 0x7;

    template<uint32_t X>
    static constexpr uint32_t RXCRCR_RxCRC =               // Rx CRC register (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t RXCRCR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t TXCRCR_TxCRC =               // Tx CRC register (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t TXCRCR_RESET_VALUE = 0x0;

    static constexpr uint32_t I2SCFGR_I2SMOD = 0x800;       // I2S mode selection
    static constexpr uint32_t I2SCFGR_I2SE = 0x400;         // I2S Enable
    template<uint32_t X>
    static constexpr uint32_t I2SCFGR_I2SCFG =              // I2S configuration mode (2 bits)
        bit_field_t<8, 0x3>::value<X>();
    static constexpr uint32_t I2SCFGR_PCMSYNC = 0x80;       // PCM frame synchronization
    template<uint32_t X>
    static constexpr uint32_t I2SCFGR_I2SSTD =              // I2S standard selection (2 bits)
        bit_field_t<4, 0x3>::value<X>();
    static constexpr uint32_t I2SCFGR_CKPOL = 0x8;          // Steady state clock polarity
    template<uint32_t X>
    static constexpr uint32_t I2SCFGR_DATLEN =              // Data length to be transferred (2 bits)
        bit_field_t<1, 0x3>::value<X>();
    static constexpr uint32_t I2SCFGR_CHLEN = 0x1;          // Channel length (number of bits per audio channel)
    static const uint32_t I2SCFGR_RESET_VALUE = 0x0;

    static constexpr uint32_t I2SPR_MCKOE = 0x200;        // Master clock output enable
    static constexpr uint32_t I2SPR_ODD = 0x100;          // Odd factor for the prescaler
    template<uint32_t X>
    static constexpr uint32_t I2SPR_I2SDIV =              // I2S Linear prescaler (8 bits)
        bit_field_t<0, 0xff>::value<X>();
    static const uint32_t I2SPR_RESET_VALUE = 0xa;
};

static spi1_t& SPI1 = *reinterpret_cast<spi1_t*>(0x40013000);

#define HAVE_PERIPHERAL_SPI1


////
//
//    Serial peripheral interface
//
////

struct spi2_t
{
    volatile uint32_t    CR1;                  // [Read-write] control register 1
    volatile uint32_t    CR2;                  // [Read-write] control register 2
    volatile uint32_t    SR;                   // status register
    volatile uint32_t    DR;                   // [Read-write] data register
    volatile uint32_t    CRCPR;                // [Read-write] CRC polynomial register
    volatile uint32_t    RXCRCR;               // [Read-only] RX CRC register
    volatile uint32_t    TXCRCR;               // [Read-only] TX CRC register
    volatile uint32_t    I2SCFGR;              // [Read-write] I2S configuration register
    volatile uint32_t    I2SPR;                // [Read-write] I2S prescaler register

    static constexpr uint32_t CR1_BIDIMODE = 0x8000;    // Bidirectional data mode enable
    static constexpr uint32_t CR1_BIDIOE = 0x4000;      // Output enable in bidirectional mode
    static constexpr uint32_t CR1_CRCEN = 0x2000;       // Hardware CRC calculation enable
    static constexpr uint32_t CR1_CRCNEXT = 0x1000;     // CRC transfer next
    static constexpr uint32_t CR1_DFF = 0x800;          // Data frame format
    static constexpr uint32_t CR1_RXONLY = 0x400;       // Receive only
    static constexpr uint32_t CR1_SSM = 0x200;          // Software slave management
    static constexpr uint32_t CR1_SSI = 0x100;          // Internal slave select
    static constexpr uint32_t CR1_LSBFIRST = 0x80;      // Frame format
    static constexpr uint32_t CR1_SPE = 0x40;           // SPI enable
    template<uint32_t X>
    static constexpr uint32_t CR1_BR =                  // Baud rate control (3 bits)
        bit_field_t<3, 0x7>::value<X>();
    static constexpr uint32_t CR1_MSTR = 0x4;           // Master selection
    static constexpr uint32_t CR1_CPOL = 0x2;           // Clock polarity
    static constexpr uint32_t CR1_CPHA = 0x1;           // Clock phase
    static const uint32_t CR1_RESET_VALUE = 0x0;

    static constexpr uint32_t CR2_TXEIE = 0x80;         // Tx buffer empty interrupt enable
    static constexpr uint32_t CR2_RXNEIE = 0x40;        // RX buffer not empty interrupt enable
    static constexpr uint32_t CR2_ERRIE = 0x20;         // Error interrupt enable
    static constexpr uint32_t CR2_FRF = 0x10;           // Frame format
    static constexpr uint32_t CR2_SSOE = 0x4;           // SS output enable
    static constexpr uint32_t CR2_TXDMAEN = 0x2;        // Tx buffer DMA enable
    static constexpr uint32_t CR2_RXDMAEN = 0x1;        // Rx buffer DMA enable
    static const uint32_t CR2_RESET_VALUE = 0x0;

    static constexpr uint32_t SR_TIFRFE = 0x100;       // TI frame format error, Read-only
    static constexpr uint32_t SR_BSY = 0x80;           // Busy flag, Read-only
    static constexpr uint32_t SR_OVR = 0x40;           // Overrun flag, Read-only
    static constexpr uint32_t SR_MODF = 0x20;          // Mode fault, Read-only
    static constexpr uint32_t SR_CRCERR = 0x10;        // CRC error flag, Read-write
    static constexpr uint32_t SR_UDR = 0x8;            // Underrun flag, Read-only
    static constexpr uint32_t SR_CHSIDE = 0x4;         // Channel side, Read-only
    static constexpr uint32_t SR_TXE = 0x2;            // Transmit buffer empty, Read-only
    static constexpr uint32_t SR_RXNE = 0x1;           // Receive buffer not empty, Read-only
    static const uint32_t SR_RESET_VALUE = 0x2;

    template<uint32_t X>
    static constexpr uint32_t DR_DR =                  // Data register (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t DR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t CRCPR_CRCPOLY =             // CRC polynomial register (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t CRCPR_RESET_VALUE = 0x7;

    template<uint32_t X>
    static constexpr uint32_t RXCRCR_RxCRC =               // Rx CRC register (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t RXCRCR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t TXCRCR_TxCRC =               // Tx CRC register (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t TXCRCR_RESET_VALUE = 0x0;

    static constexpr uint32_t I2SCFGR_I2SMOD = 0x800;       // I2S mode selection
    static constexpr uint32_t I2SCFGR_I2SE = 0x400;         // I2S Enable
    template<uint32_t X>
    static constexpr uint32_t I2SCFGR_I2SCFG =              // I2S configuration mode (2 bits)
        bit_field_t<8, 0x3>::value<X>();
    static constexpr uint32_t I2SCFGR_PCMSYNC = 0x80;       // PCM frame synchronization
    template<uint32_t X>
    static constexpr uint32_t I2SCFGR_I2SSTD =              // I2S standard selection (2 bits)
        bit_field_t<4, 0x3>::value<X>();
    static constexpr uint32_t I2SCFGR_CKPOL = 0x8;          // Steady state clock polarity
    template<uint32_t X>
    static constexpr uint32_t I2SCFGR_DATLEN =              // Data length to be transferred (2 bits)
        bit_field_t<1, 0x3>::value<X>();
    static constexpr uint32_t I2SCFGR_CHLEN = 0x1;          // Channel length (number of bits per audio channel)
    static const uint32_t I2SCFGR_RESET_VALUE = 0x0;

    static constexpr uint32_t I2SPR_MCKOE = 0x200;        // Master clock output enable
    static constexpr uint32_t I2SPR_ODD = 0x100;          // Odd factor for the prescaler
    template<uint32_t X>
    static constexpr uint32_t I2SPR_I2SDIV =              // I2S Linear prescaler (8 bits)
        bit_field_t<0, 0xff>::value<X>();
    static const uint32_t I2SPR_RESET_VALUE = 0xa;

    static constexpr uint8_t SPI1 = 35; // SPI1 global interrupt
};

static spi2_t& SPI2 = *reinterpret_cast<spi2_t*>(0x40003800);

#define HAVE_PERIPHERAL_SPI2


////
//
//    Serial peripheral interface
//
////

struct spi3_t
{
    volatile uint32_t    CR1;                  // [Read-write] control register 1
    volatile uint32_t    CR2;                  // [Read-write] control register 2
    volatile uint32_t    SR;                   // status register
    volatile uint32_t    DR;                   // [Read-write] data register
    volatile uint32_t    CRCPR;                // [Read-write] CRC polynomial register
    volatile uint32_t    RXCRCR;               // [Read-only] RX CRC register
    volatile uint32_t    TXCRCR;               // [Read-only] TX CRC register
    volatile uint32_t    I2SCFGR;              // [Read-write] I2S configuration register
    volatile uint32_t    I2SPR;                // [Read-write] I2S prescaler register

    static constexpr uint32_t CR1_BIDIMODE = 0x8000;    // Bidirectional data mode enable
    static constexpr uint32_t CR1_BIDIOE = 0x4000;      // Output enable in bidirectional mode
    static constexpr uint32_t CR1_CRCEN = 0x2000;       // Hardware CRC calculation enable
    static constexpr uint32_t CR1_CRCNEXT = 0x1000;     // CRC transfer next
    static constexpr uint32_t CR1_DFF = 0x800;          // Data frame format
    static constexpr uint32_t CR1_RXONLY = 0x400;       // Receive only
    static constexpr uint32_t CR1_SSM = 0x200;          // Software slave management
    static constexpr uint32_t CR1_SSI = 0x100;          // Internal slave select
    static constexpr uint32_t CR1_LSBFIRST = 0x80;      // Frame format
    static constexpr uint32_t CR1_SPE = 0x40;           // SPI enable
    template<uint32_t X>
    static constexpr uint32_t CR1_BR =                  // Baud rate control (3 bits)
        bit_field_t<3, 0x7>::value<X>();
    static constexpr uint32_t CR1_MSTR = 0x4;           // Master selection
    static constexpr uint32_t CR1_CPOL = 0x2;           // Clock polarity
    static constexpr uint32_t CR1_CPHA = 0x1;           // Clock phase
    static const uint32_t CR1_RESET_VALUE = 0x0;

    static constexpr uint32_t CR2_TXEIE = 0x80;         // Tx buffer empty interrupt enable
    static constexpr uint32_t CR2_RXNEIE = 0x40;        // RX buffer not empty interrupt enable
    static constexpr uint32_t CR2_ERRIE = 0x20;         // Error interrupt enable
    static constexpr uint32_t CR2_FRF = 0x10;           // Frame format
    static constexpr uint32_t CR2_SSOE = 0x4;           // SS output enable
    static constexpr uint32_t CR2_TXDMAEN = 0x2;        // Tx buffer DMA enable
    static constexpr uint32_t CR2_RXDMAEN = 0x1;        // Rx buffer DMA enable
    static const uint32_t CR2_RESET_VALUE = 0x0;

    static constexpr uint32_t SR_TIFRFE = 0x100;       // TI frame format error, Read-only
    static constexpr uint32_t SR_BSY = 0x80;           // Busy flag, Read-only
    static constexpr uint32_t SR_OVR = 0x40;           // Overrun flag, Read-only
    static constexpr uint32_t SR_MODF = 0x20;          // Mode fault, Read-only
    static constexpr uint32_t SR_CRCERR = 0x10;        // CRC error flag, Read-write
    static constexpr uint32_t SR_UDR = 0x8;            // Underrun flag, Read-only
    static constexpr uint32_t SR_CHSIDE = 0x4;         // Channel side, Read-only
    static constexpr uint32_t SR_TXE = 0x2;            // Transmit buffer empty, Read-only
    static constexpr uint32_t SR_RXNE = 0x1;           // Receive buffer not empty, Read-only
    static const uint32_t SR_RESET_VALUE = 0x2;

    template<uint32_t X>
    static constexpr uint32_t DR_DR =                  // Data register (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t DR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t CRCPR_CRCPOLY =             // CRC polynomial register (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t CRCPR_RESET_VALUE = 0x7;

    template<uint32_t X>
    static constexpr uint32_t RXCRCR_RxCRC =               // Rx CRC register (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t RXCRCR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t TXCRCR_TxCRC =               // Tx CRC register (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t TXCRCR_RESET_VALUE = 0x0;

    static constexpr uint32_t I2SCFGR_I2SMOD = 0x800;       // I2S mode selection
    static constexpr uint32_t I2SCFGR_I2SE = 0x400;         // I2S Enable
    template<uint32_t X>
    static constexpr uint32_t I2SCFGR_I2SCFG =              // I2S configuration mode (2 bits)
        bit_field_t<8, 0x3>::value<X>();
    static constexpr uint32_t I2SCFGR_PCMSYNC = 0x80;       // PCM frame synchronization
    template<uint32_t X>
    static constexpr uint32_t I2SCFGR_I2SSTD =              // I2S standard selection (2 bits)
        bit_field_t<4, 0x3>::value<X>();
    static constexpr uint32_t I2SCFGR_CKPOL = 0x8;          // Steady state clock polarity
    template<uint32_t X>
    static constexpr uint32_t I2SCFGR_DATLEN =              // Data length to be transferred (2 bits)
        bit_field_t<1, 0x3>::value<X>();
    static constexpr uint32_t I2SCFGR_CHLEN = 0x1;          // Channel length (number of bits per audio channel)
    static const uint32_t I2SCFGR_RESET_VALUE = 0x0;

    static constexpr uint32_t I2SPR_MCKOE = 0x200;        // Master clock output enable
    static constexpr uint32_t I2SPR_ODD = 0x100;          // Odd factor for the prescaler
    template<uint32_t X>
    static constexpr uint32_t I2SPR_I2SDIV =              // I2S Linear prescaler (8 bits)
        bit_field_t<0, 0xff>::value<X>();
    static const uint32_t I2SPR_RESET_VALUE = 0xa;

    static constexpr uint8_t SPI2 = 36; // SPI2 global interrupt
};

static spi3_t& SPI3 = *reinterpret_cast<spi3_t*>(0x40003c00);

#define HAVE_PERIPHERAL_SPI3


////
//
//    Serial peripheral interface
//
////

struct spi4_t
{
    volatile uint32_t    CR1;                  // [Read-write] control register 1
    volatile uint32_t    CR2;                  // [Read-write] control register 2
    volatile uint32_t    SR;                   // status register
    volatile uint32_t    DR;                   // [Read-write] data register
    volatile uint32_t    CRCPR;                // [Read-write] CRC polynomial register
    volatile uint32_t    RXCRCR;               // [Read-only] RX CRC register
    volatile uint32_t    TXCRCR;               // [Read-only] TX CRC register
    volatile uint32_t    I2SCFGR;              // [Read-write] I2S configuration register
    volatile uint32_t    I2SPR;                // [Read-write] I2S prescaler register

    static constexpr uint32_t CR1_BIDIMODE = 0x8000;    // Bidirectional data mode enable
    static constexpr uint32_t CR1_BIDIOE = 0x4000;      // Output enable in bidirectional mode
    static constexpr uint32_t CR1_CRCEN = 0x2000;       // Hardware CRC calculation enable
    static constexpr uint32_t CR1_CRCNEXT = 0x1000;     // CRC transfer next
    static constexpr uint32_t CR1_DFF = 0x800;          // Data frame format
    static constexpr uint32_t CR1_RXONLY = 0x400;       // Receive only
    static constexpr uint32_t CR1_SSM = 0x200;          // Software slave management
    static constexpr uint32_t CR1_SSI = 0x100;          // Internal slave select
    static constexpr uint32_t CR1_LSBFIRST = 0x80;      // Frame format
    static constexpr uint32_t CR1_SPE = 0x40;           // SPI enable
    template<uint32_t X>
    static constexpr uint32_t CR1_BR =                  // Baud rate control (3 bits)
        bit_field_t<3, 0x7>::value<X>();
    static constexpr uint32_t CR1_MSTR = 0x4;           // Master selection
    static constexpr uint32_t CR1_CPOL = 0x2;           // Clock polarity
    static constexpr uint32_t CR1_CPHA = 0x1;           // Clock phase
    static const uint32_t CR1_RESET_VALUE = 0x0;

    static constexpr uint32_t CR2_TXEIE = 0x80;         // Tx buffer empty interrupt enable
    static constexpr uint32_t CR2_RXNEIE = 0x40;        // RX buffer not empty interrupt enable
    static constexpr uint32_t CR2_ERRIE = 0x20;         // Error interrupt enable
    static constexpr uint32_t CR2_FRF = 0x10;           // Frame format
    static constexpr uint32_t CR2_SSOE = 0x4;           // SS output enable
    static constexpr uint32_t CR2_TXDMAEN = 0x2;        // Tx buffer DMA enable
    static constexpr uint32_t CR2_RXDMAEN = 0x1;        // Rx buffer DMA enable
    static const uint32_t CR2_RESET_VALUE = 0x0;

    static constexpr uint32_t SR_TIFRFE = 0x100;       // TI frame format error, Read-only
    static constexpr uint32_t SR_BSY = 0x80;           // Busy flag, Read-only
    static constexpr uint32_t SR_OVR = 0x40;           // Overrun flag, Read-only
    static constexpr uint32_t SR_MODF = 0x20;          // Mode fault, Read-only
    static constexpr uint32_t SR_CRCERR = 0x10;        // CRC error flag, Read-write
    static constexpr uint32_t SR_UDR = 0x8;            // Underrun flag, Read-only
    static constexpr uint32_t SR_CHSIDE = 0x4;         // Channel side, Read-only
    static constexpr uint32_t SR_TXE = 0x2;            // Transmit buffer empty, Read-only
    static constexpr uint32_t SR_RXNE = 0x1;           // Receive buffer not empty, Read-only
    static const uint32_t SR_RESET_VALUE = 0x2;

    template<uint32_t X>
    static constexpr uint32_t DR_DR =                  // Data register (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t DR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t CRCPR_CRCPOLY =             // CRC polynomial register (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t CRCPR_RESET_VALUE = 0x7;

    template<uint32_t X>
    static constexpr uint32_t RXCRCR_RxCRC =               // Rx CRC register (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t RXCRCR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t TXCRCR_TxCRC =               // Tx CRC register (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t TXCRCR_RESET_VALUE = 0x0;

    static constexpr uint32_t I2SCFGR_I2SMOD = 0x800;       // I2S mode selection
    static constexpr uint32_t I2SCFGR_I2SE = 0x400;         // I2S Enable
    template<uint32_t X>
    static constexpr uint32_t I2SCFGR_I2SCFG =              // I2S configuration mode (2 bits)
        bit_field_t<8, 0x3>::value<X>();
    static constexpr uint32_t I2SCFGR_PCMSYNC = 0x80;       // PCM frame synchronization
    template<uint32_t X>
    static constexpr uint32_t I2SCFGR_I2SSTD =              // I2S standard selection (2 bits)
        bit_field_t<4, 0x3>::value<X>();
    static constexpr uint32_t I2SCFGR_CKPOL = 0x8;          // Steady state clock polarity
    template<uint32_t X>
    static constexpr uint32_t I2SCFGR_DATLEN =              // Data length to be transferred (2 bits)
        bit_field_t<1, 0x3>::value<X>();
    static constexpr uint32_t I2SCFGR_CHLEN = 0x1;          // Channel length (number of bits per audio channel)
    static const uint32_t I2SCFGR_RESET_VALUE = 0x0;

    static constexpr uint32_t I2SPR_MCKOE = 0x200;        // Master clock output enable
    static constexpr uint32_t I2SPR_ODD = 0x100;          // Odd factor for the prescaler
    template<uint32_t X>
    static constexpr uint32_t I2SPR_I2SDIV =              // I2S Linear prescaler (8 bits)
        bit_field_t<0, 0xff>::value<X>();
    static const uint32_t I2SPR_RESET_VALUE = 0xa;

    static constexpr uint8_t SPI3 = 51; // SPI3 global interrupt
};

static spi4_t& SPI4 = *reinterpret_cast<spi4_t*>(0x40013400);

#define HAVE_PERIPHERAL_SPI4


////
//
//    Serial peripheral interface
//
////

struct spi5_t
{
    volatile uint32_t    CR1;                  // [Read-write] control register 1
    volatile uint32_t    CR2;                  // [Read-write] control register 2
    volatile uint32_t    SR;                   // status register
    volatile uint32_t    DR;                   // [Read-write] data register
    volatile uint32_t    CRCPR;                // [Read-write] CRC polynomial register
    volatile uint32_t    RXCRCR;               // [Read-only] RX CRC register
    volatile uint32_t    TXCRCR;               // [Read-only] TX CRC register
    volatile uint32_t    I2SCFGR;              // [Read-write] I2S configuration register
    volatile uint32_t    I2SPR;                // [Read-write] I2S prescaler register

    static constexpr uint32_t CR1_BIDIMODE = 0x8000;    // Bidirectional data mode enable
    static constexpr uint32_t CR1_BIDIOE = 0x4000;      // Output enable in bidirectional mode
    static constexpr uint32_t CR1_CRCEN = 0x2000;       // Hardware CRC calculation enable
    static constexpr uint32_t CR1_CRCNEXT = 0x1000;     // CRC transfer next
    static constexpr uint32_t CR1_DFF = 0x800;          // Data frame format
    static constexpr uint32_t CR1_RXONLY = 0x400;       // Receive only
    static constexpr uint32_t CR1_SSM = 0x200;          // Software slave management
    static constexpr uint32_t CR1_SSI = 0x100;          // Internal slave select
    static constexpr uint32_t CR1_LSBFIRST = 0x80;      // Frame format
    static constexpr uint32_t CR1_SPE = 0x40;           // SPI enable
    template<uint32_t X>
    static constexpr uint32_t CR1_BR =                  // Baud rate control (3 bits)
        bit_field_t<3, 0x7>::value<X>();
    static constexpr uint32_t CR1_MSTR = 0x4;           // Master selection
    static constexpr uint32_t CR1_CPOL = 0x2;           // Clock polarity
    static constexpr uint32_t CR1_CPHA = 0x1;           // Clock phase
    static const uint32_t CR1_RESET_VALUE = 0x0;

    static constexpr uint32_t CR2_TXEIE = 0x80;         // Tx buffer empty interrupt enable
    static constexpr uint32_t CR2_RXNEIE = 0x40;        // RX buffer not empty interrupt enable
    static constexpr uint32_t CR2_ERRIE = 0x20;         // Error interrupt enable
    static constexpr uint32_t CR2_FRF = 0x10;           // Frame format
    static constexpr uint32_t CR2_SSOE = 0x4;           // SS output enable
    static constexpr uint32_t CR2_TXDMAEN = 0x2;        // Tx buffer DMA enable
    static constexpr uint32_t CR2_RXDMAEN = 0x1;        // Rx buffer DMA enable
    static const uint32_t CR2_RESET_VALUE = 0x0;

    static constexpr uint32_t SR_TIFRFE = 0x100;       // TI frame format error, Read-only
    static constexpr uint32_t SR_BSY = 0x80;           // Busy flag, Read-only
    static constexpr uint32_t SR_OVR = 0x40;           // Overrun flag, Read-only
    static constexpr uint32_t SR_MODF = 0x20;          // Mode fault, Read-only
    static constexpr uint32_t SR_CRCERR = 0x10;        // CRC error flag, Read-write
    static constexpr uint32_t SR_UDR = 0x8;            // Underrun flag, Read-only
    static constexpr uint32_t SR_CHSIDE = 0x4;         // Channel side, Read-only
    static constexpr uint32_t SR_TXE = 0x2;            // Transmit buffer empty, Read-only
    static constexpr uint32_t SR_RXNE = 0x1;           // Receive buffer not empty, Read-only
    static const uint32_t SR_RESET_VALUE = 0x2;

    template<uint32_t X>
    static constexpr uint32_t DR_DR =                  // Data register (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t DR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t CRCPR_CRCPOLY =             // CRC polynomial register (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t CRCPR_RESET_VALUE = 0x7;

    template<uint32_t X>
    static constexpr uint32_t RXCRCR_RxCRC =               // Rx CRC register (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t RXCRCR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t TXCRCR_TxCRC =               // Tx CRC register (16 bits)
        bit_field_t<0, 0xffff>::value<X>();
    static const uint32_t TXCRCR_RESET_VALUE = 0x0;

    static constexpr uint32_t I2SCFGR_I2SMOD = 0x800;       // I2S mode selection
    static constexpr uint32_t I2SCFGR_I2SE = 0x400;         // I2S Enable
    template<uint32_t X>
    static constexpr uint32_t I2SCFGR_I2SCFG =              // I2S configuration mode (2 bits)
        bit_field_t<8, 0x3>::value<X>();
    static constexpr uint32_t I2SCFGR_PCMSYNC = 0x80;       // PCM frame synchronization
    template<uint32_t X>
    static constexpr uint32_t I2SCFGR_I2SSTD =              // I2S standard selection (2 bits)
        bit_field_t<4, 0x3>::value<X>();
    static constexpr uint32_t I2SCFGR_CKPOL = 0x8;          // Steady state clock polarity
    template<uint32_t X>
    static constexpr uint32_t I2SCFGR_DATLEN =              // Data length to be transferred (2 bits)
        bit_field_t<1, 0x3>::value<X>();
    static constexpr uint32_t I2SCFGR_CHLEN = 0x1;          // Channel length (number of bits per audio channel)
    static const uint32_t I2SCFGR_RESET_VALUE = 0x0;

    static constexpr uint32_t I2SPR_MCKOE = 0x200;        // Master clock output enable
    static constexpr uint32_t I2SPR_ODD = 0x100;          // Odd factor for the prescaler
    template<uint32_t X>
    static constexpr uint32_t I2SPR_I2SDIV =              // I2S Linear prescaler (8 bits)
        bit_field_t<0, 0xff>::value<X>();
    static const uint32_t I2SPR_RESET_VALUE = 0xa;
};

static spi5_t& SPI5 = *reinterpret_cast<spi5_t*>(0x40015000);

#define HAVE_PERIPHERAL_SPI5


////
//
//    Nested Vectored Interrupt Controller
//
////

struct nvic_t
{
    volatile uint32_t    ISER0;                // [Read-write] Interrupt Set-Enable Register
    volatile uint32_t    ISER1;                // [Read-write] Interrupt Set-Enable Register
    volatile uint32_t    ISER2;                // [Read-write] Interrupt Set-Enable Register
    reserved_t<29>       _0;
    volatile uint32_t    ICER0;                // [Read-write] Interrupt Clear-Enable Register
    volatile uint32_t    ICER1;                // [Read-write] Interrupt Clear-Enable Register
    volatile uint32_t    ICER2;                // [Read-write] Interrupt Clear-Enable Register
    reserved_t<29>       _1;
    volatile uint32_t    ISPR0;                // [Read-write] Interrupt Set-Pending Register
    volatile uint32_t    ISPR1;                // [Read-write] Interrupt Set-Pending Register
    volatile uint32_t    ISPR2;                // [Read-write] Interrupt Set-Pending Register
    reserved_t<29>       _2;
    volatile uint32_t    ICPR0;                // [Read-write] Interrupt Clear-Pending Register
    volatile uint32_t    ICPR1;                // [Read-write] Interrupt Clear-Pending Register
    volatile uint32_t    ICPR2;                // [Read-write] Interrupt Clear-Pending Register
    reserved_t<29>       _3;
    volatile uint32_t    IABR0;                // [Read-only] Interrupt Active Bit Register
    volatile uint32_t    IABR1;                // [Read-only] Interrupt Active Bit Register
    volatile uint32_t    IABR2;                // [Read-only] Interrupt Active Bit Register
    reserved_t<61>       _4;
    volatile uint32_t    IPR0;                 // [Read-write] Interrupt Priority Register
    volatile uint32_t    IPR1;                 // [Read-write] Interrupt Priority Register
    volatile uint32_t    IPR2;                 // [Read-write] Interrupt Priority Register
    volatile uint32_t    IPR3;                 // [Read-write] Interrupt Priority Register
    volatile uint32_t    IPR4;                 // [Read-write] Interrupt Priority Register
    volatile uint32_t    IPR5;                 // [Read-write] Interrupt Priority Register
    volatile uint32_t    IPR6;                 // [Read-write] Interrupt Priority Register
    volatile uint32_t    IPR7;                 // [Read-write] Interrupt Priority Register
    volatile uint32_t    IPR8;                 // [Read-write] Interrupt Priority Register
    volatile uint32_t    IPR9;                 // [Read-write] Interrupt Priority Register
    volatile uint32_t    IPR10;                // [Read-write] Interrupt Priority Register
    volatile uint32_t    IPR11;                // [Read-write] Interrupt Priority Register
    volatile uint32_t    IPR12;                // [Read-write] Interrupt Priority Register
    volatile uint32_t    IPR13;                // [Read-write] Interrupt Priority Register
    volatile uint32_t    IPR14;                // [Read-write] Interrupt Priority Register
    volatile uint32_t    IPR15;                // [Read-write] Interrupt Priority Register
    volatile uint32_t    IPR16;                // [Read-write] Interrupt Priority Register
    volatile uint32_t    IPR17;                // [Read-write] Interrupt Priority Register
    volatile uint32_t    IPR18;                // [Read-write] Interrupt Priority Register
    volatile uint32_t    IPR19;                // [Read-write] Interrupt Priority Register


    static const uint32_t ISER0_RESET_VALUE = 0x0;


    static const uint32_t ISER1_RESET_VALUE = 0x0;


    static const uint32_t ISER2_RESET_VALUE = 0x0;


    static const uint32_t ICER0_RESET_VALUE = 0x0;


    static const uint32_t ICER1_RESET_VALUE = 0x0;


    static const uint32_t ICER2_RESET_VALUE = 0x0;


    static const uint32_t ISPR0_RESET_VALUE = 0x0;


    static const uint32_t ISPR1_RESET_VALUE = 0x0;


    static const uint32_t ISPR2_RESET_VALUE = 0x0;


    static const uint32_t ICPR0_RESET_VALUE = 0x0;


    static const uint32_t ICPR1_RESET_VALUE = 0x0;


    static const uint32_t ICPR2_RESET_VALUE = 0x0;


    static const uint32_t IABR0_RESET_VALUE = 0x0;


    static const uint32_t IABR1_RESET_VALUE = 0x0;


    static const uint32_t IABR2_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t IPR0_IPR_N0 =              // IPR_N0 (8 bits)
        bit_field_t<0, 0xff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t IPR0_IPR_N1 =              // IPR_N1 (8 bits)
        bit_field_t<8, 0xff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t IPR0_IPR_N2 =              // IPR_N2 (8 bits)
        bit_field_t<16, 0xff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t IPR0_IPR_N3 =              // IPR_N3 (8 bits)
        bit_field_t<24, 0xff>::value<X>();
    static const uint32_t IPR0_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t IPR1_IPR_N0 =              // IPR_N0 (8 bits)
        bit_field_t<0, 0xff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t IPR1_IPR_N1 =              // IPR_N1 (8 bits)
        bit_field_t<8, 0xff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t IPR1_IPR_N2 =              // IPR_N2 (8 bits)
        bit_field_t<16, 0xff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t IPR1_IPR_N3 =              // IPR_N3 (8 bits)
        bit_field_t<24, 0xff>::value<X>();
    static const uint32_t IPR1_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t IPR2_IPR_N0 =              // IPR_N0 (8 bits)
        bit_field_t<0, 0xff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t IPR2_IPR_N1 =              // IPR_N1 (8 bits)
        bit_field_t<8, 0xff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t IPR2_IPR_N2 =              // IPR_N2 (8 bits)
        bit_field_t<16, 0xff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t IPR2_IPR_N3 =              // IPR_N3 (8 bits)
        bit_field_t<24, 0xff>::value<X>();
    static const uint32_t IPR2_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t IPR3_IPR_N0 =              // IPR_N0 (8 bits)
        bit_field_t<0, 0xff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t IPR3_IPR_N1 =              // IPR_N1 (8 bits)
        bit_field_t<8, 0xff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t IPR3_IPR_N2 =              // IPR_N2 (8 bits)
        bit_field_t<16, 0xff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t IPR3_IPR_N3 =              // IPR_N3 (8 bits)
        bit_field_t<24, 0xff>::value<X>();
    static const uint32_t IPR3_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t IPR4_IPR_N0 =              // IPR_N0 (8 bits)
        bit_field_t<0, 0xff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t IPR4_IPR_N1 =              // IPR_N1 (8 bits)
        bit_field_t<8, 0xff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t IPR4_IPR_N2 =              // IPR_N2 (8 bits)
        bit_field_t<16, 0xff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t IPR4_IPR_N3 =              // IPR_N3 (8 bits)
        bit_field_t<24, 0xff>::value<X>();
    static const uint32_t IPR4_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t IPR5_IPR_N0 =              // IPR_N0 (8 bits)
        bit_field_t<0, 0xff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t IPR5_IPR_N1 =              // IPR_N1 (8 bits)
        bit_field_t<8, 0xff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t IPR5_IPR_N2 =              // IPR_N2 (8 bits)
        bit_field_t<16, 0xff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t IPR5_IPR_N3 =              // IPR_N3 (8 bits)
        bit_field_t<24, 0xff>::value<X>();
    static const uint32_t IPR5_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t IPR6_IPR_N0 =              // IPR_N0 (8 bits)
        bit_field_t<0, 0xff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t IPR6_IPR_N1 =              // IPR_N1 (8 bits)
        bit_field_t<8, 0xff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t IPR6_IPR_N2 =              // IPR_N2 (8 bits)
        bit_field_t<16, 0xff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t IPR6_IPR_N3 =              // IPR_N3 (8 bits)
        bit_field_t<24, 0xff>::value<X>();
    static const uint32_t IPR6_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t IPR7_IPR_N0 =              // IPR_N0 (8 bits)
        bit_field_t<0, 0xff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t IPR7_IPR_N1 =              // IPR_N1 (8 bits)
        bit_field_t<8, 0xff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t IPR7_IPR_N2 =              // IPR_N2 (8 bits)
        bit_field_t<16, 0xff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t IPR7_IPR_N3 =              // IPR_N3 (8 bits)
        bit_field_t<24, 0xff>::value<X>();
    static const uint32_t IPR7_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t IPR8_IPR_N0 =              // IPR_N0 (8 bits)
        bit_field_t<0, 0xff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t IPR8_IPR_N1 =              // IPR_N1 (8 bits)
        bit_field_t<8, 0xff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t IPR8_IPR_N2 =              // IPR_N2 (8 bits)
        bit_field_t<16, 0xff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t IPR8_IPR_N3 =              // IPR_N3 (8 bits)
        bit_field_t<24, 0xff>::value<X>();
    static const uint32_t IPR8_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t IPR9_IPR_N0 =              // IPR_N0 (8 bits)
        bit_field_t<0, 0xff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t IPR9_IPR_N1 =              // IPR_N1 (8 bits)
        bit_field_t<8, 0xff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t IPR9_IPR_N2 =              // IPR_N2 (8 bits)
        bit_field_t<16, 0xff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t IPR9_IPR_N3 =              // IPR_N3 (8 bits)
        bit_field_t<24, 0xff>::value<X>();
    static const uint32_t IPR9_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t IPR10_IPR_N0 =              // IPR_N0 (8 bits)
        bit_field_t<0, 0xff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t IPR10_IPR_N1 =              // IPR_N1 (8 bits)
        bit_field_t<8, 0xff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t IPR10_IPR_N2 =              // IPR_N2 (8 bits)
        bit_field_t<16, 0xff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t IPR10_IPR_N3 =              // IPR_N3 (8 bits)
        bit_field_t<24, 0xff>::value<X>();
    static const uint32_t IPR10_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t IPR11_IPR_N0 =              // IPR_N0 (8 bits)
        bit_field_t<0, 0xff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t IPR11_IPR_N1 =              // IPR_N1 (8 bits)
        bit_field_t<8, 0xff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t IPR11_IPR_N2 =              // IPR_N2 (8 bits)
        bit_field_t<16, 0xff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t IPR11_IPR_N3 =              // IPR_N3 (8 bits)
        bit_field_t<24, 0xff>::value<X>();
    static const uint32_t IPR11_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t IPR12_IPR_N0 =              // IPR_N0 (8 bits)
        bit_field_t<0, 0xff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t IPR12_IPR_N1 =              // IPR_N1 (8 bits)
        bit_field_t<8, 0xff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t IPR12_IPR_N2 =              // IPR_N2 (8 bits)
        bit_field_t<16, 0xff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t IPR12_IPR_N3 =              // IPR_N3 (8 bits)
        bit_field_t<24, 0xff>::value<X>();
    static const uint32_t IPR12_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t IPR13_IPR_N0 =              // IPR_N0 (8 bits)
        bit_field_t<0, 0xff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t IPR13_IPR_N1 =              // IPR_N1 (8 bits)
        bit_field_t<8, 0xff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t IPR13_IPR_N2 =              // IPR_N2 (8 bits)
        bit_field_t<16, 0xff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t IPR13_IPR_N3 =              // IPR_N3 (8 bits)
        bit_field_t<24, 0xff>::value<X>();
    static const uint32_t IPR13_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t IPR14_IPR_N0 =              // IPR_N0 (8 bits)
        bit_field_t<0, 0xff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t IPR14_IPR_N1 =              // IPR_N1 (8 bits)
        bit_field_t<8, 0xff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t IPR14_IPR_N2 =              // IPR_N2 (8 bits)
        bit_field_t<16, 0xff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t IPR14_IPR_N3 =              // IPR_N3 (8 bits)
        bit_field_t<24, 0xff>::value<X>();
    static const uint32_t IPR14_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t IPR15_IPR_N0 =              // IPR_N0 (8 bits)
        bit_field_t<0, 0xff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t IPR15_IPR_N1 =              // IPR_N1 (8 bits)
        bit_field_t<8, 0xff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t IPR15_IPR_N2 =              // IPR_N2 (8 bits)
        bit_field_t<16, 0xff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t IPR15_IPR_N3 =              // IPR_N3 (8 bits)
        bit_field_t<24, 0xff>::value<X>();
    static const uint32_t IPR15_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t IPR16_IPR_N0 =              // IPR_N0 (8 bits)
        bit_field_t<0, 0xff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t IPR16_IPR_N1 =              // IPR_N1 (8 bits)
        bit_field_t<8, 0xff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t IPR16_IPR_N2 =              // IPR_N2 (8 bits)
        bit_field_t<16, 0xff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t IPR16_IPR_N3 =              // IPR_N3 (8 bits)
        bit_field_t<24, 0xff>::value<X>();
    static const uint32_t IPR16_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t IPR17_IPR_N0 =              // IPR_N0 (8 bits)
        bit_field_t<0, 0xff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t IPR17_IPR_N1 =              // IPR_N1 (8 bits)
        bit_field_t<8, 0xff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t IPR17_IPR_N2 =              // IPR_N2 (8 bits)
        bit_field_t<16, 0xff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t IPR17_IPR_N3 =              // IPR_N3 (8 bits)
        bit_field_t<24, 0xff>::value<X>();
    static const uint32_t IPR17_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t IPR18_IPR_N0 =              // IPR_N0 (8 bits)
        bit_field_t<0, 0xff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t IPR18_IPR_N1 =              // IPR_N1 (8 bits)
        bit_field_t<8, 0xff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t IPR18_IPR_N2 =              // IPR_N2 (8 bits)
        bit_field_t<16, 0xff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t IPR18_IPR_N3 =              // IPR_N3 (8 bits)
        bit_field_t<24, 0xff>::value<X>();
    static const uint32_t IPR18_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t IPR19_IPR_N0 =              // IPR_N0 (8 bits)
        bit_field_t<0, 0xff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t IPR19_IPR_N1 =              // IPR_N1 (8 bits)
        bit_field_t<8, 0xff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t IPR19_IPR_N2 =              // IPR_N2 (8 bits)
        bit_field_t<16, 0xff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t IPR19_IPR_N3 =              // IPR_N3 (8 bits)
        bit_field_t<24, 0xff>::value<X>();
    static const uint32_t IPR19_RESET_VALUE = 0x0;
};

static nvic_t& NVIC = *reinterpret_cast<nvic_t*>(0xe000e100);

#define HAVE_PERIPHERAL_NVIC


////
//
//    Floting point unit
//
////

struct fpu_t
{
    volatile uint32_t    FPCCR;                // [Read-write] Floating-point context control register
    volatile uint32_t    FPCAR;                // [Read-write] Floating-point context address register
    volatile uint32_t    FPSCR;                // [Read-write] Floating-point status control register

    static constexpr uint32_t FPCCR_LSPACT = 0x1;         // LSPACT
    static constexpr uint32_t FPCCR_USER = 0x2;           // USER
    static constexpr uint32_t FPCCR_THREAD = 0x8;         // THREAD
    static constexpr uint32_t FPCCR_HFRDY = 0x10;         // HFRDY
    static constexpr uint32_t FPCCR_MMRDY = 0x20;         // MMRDY
    static constexpr uint32_t FPCCR_BFRDY = 0x40;         // BFRDY
    static constexpr uint32_t FPCCR_MONRDY = 0x100;       // MONRDY
    static constexpr uint32_t FPCCR_LSPEN = 0x40000000;   // LSPEN
    static constexpr uint32_t FPCCR_ASPEN = 0x80000000;   // ASPEN
    static const uint32_t FPCCR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t FPCAR_ADDRESS =             // Location of unpopulated floating-point (29 bits)
        bit_field_t<3, 0x1fffffff>::value<X>();
    static const uint32_t FPCAR_RESET_VALUE = 0x0;

    static constexpr uint32_t FPSCR_IOC = 0x1;            // Invalid operation cumulative exception bit
    static constexpr uint32_t FPSCR_DZC = 0x2;            // Division by zero cumulative exception bit.
    static constexpr uint32_t FPSCR_OFC = 0x4;            // Overflow cumulative exception bit
    static constexpr uint32_t FPSCR_UFC = 0x8;            // Underflow cumulative exception bit
    static constexpr uint32_t FPSCR_IXC = 0x10;           // Inexact cumulative exception bit
    static constexpr uint32_t FPSCR_IDC = 0x80;           // Input denormal cumulative exception bit.
    template<uint32_t X>
    static constexpr uint32_t FPSCR_RMode =               // Rounding Mode control field (2 bits)
        bit_field_t<22, 0x3>::value<X>();
    static constexpr uint32_t FPSCR_FZ = 0x1000000;       // Flush-to-zero mode control bit:
    static constexpr uint32_t FPSCR_DN = 0x2000000;       // Default NaN mode control bit
    static constexpr uint32_t FPSCR_AHP = 0x4000000;      // Alternative half-precision control bit
    static constexpr uint32_t FPSCR_V = 0x10000000;       // Overflow condition code flag
    static constexpr uint32_t FPSCR_C = 0x20000000;       // Carry condition code flag
    static constexpr uint32_t FPSCR_Z = 0x40000000;       // Zero condition code flag
    static constexpr uint32_t FPSCR_N = 0x80000000;       // Negative condition code flag
    static const uint32_t FPSCR_RESET_VALUE = 0x0;

    static constexpr uint8_t FPU = 81; // Floating point unit interrupt
};

static fpu_t& FPU = *reinterpret_cast<fpu_t*>(0xe000ef34);

#define HAVE_PERIPHERAL_FPU


////
//
//    Memory protection unit
//
////

struct mpu_t
{
    volatile uint32_t    TYPER;                // [Read-only] MPU type register
    volatile uint32_t    CTRL;                 // [Read-only] MPU control register
    volatile uint32_t    RNR;                  // [Read-write] MPU region number register
    volatile uint32_t    RBAR;                 // [Read-write] MPU region base address register
    volatile uint32_t    RASR;                 // [Read-write] MPU region attribute and size register

    static constexpr uint32_t TYPER_SEPARATE = 0x1;       // Separate flag
    template<uint32_t X>
    static constexpr uint32_t TYPER_DREGION =             // Number of MPU data regions (8 bits)
        bit_field_t<8, 0xff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t TYPER_IREGION =             // Number of MPU instruction regions (8 bits)
        bit_field_t<16, 0xff>::value<X>();
    static const uint32_t TYPER_RESET_VALUE = 0x800;

    static constexpr uint32_t CTRL_ENABLE = 0x1;         // Enables the MPU
    static constexpr uint32_t CTRL_HFNMIENA = 0x2;       // Enables the operation of MPU during hard fault
    static constexpr uint32_t CTRL_PRIVDEFENA = 0x4;     // Enable priviliged software access to default memory map
    static const uint32_t CTRL_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t RNR_REGION =              // MPU region (8 bits)
        bit_field_t<0, 0xff>::value<X>();
    static const uint32_t RNR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t RBAR_REGION =              // MPU region field (4 bits)
        bit_field_t<0, 0xf>::value<X>();
    static constexpr uint32_t RBAR_VALID = 0x10;         // MPU region number valid
    template<uint32_t X>
    static constexpr uint32_t RBAR_ADDR =                // Region base address field (27 bits)
        bit_field_t<5, 0x7ffffff>::value<X>();
    static const uint32_t RBAR_RESET_VALUE = 0x0;

    static constexpr uint32_t RASR_ENABLE = 0x1;         // Region enable bit.
    template<uint32_t X>
    static constexpr uint32_t RASR_SIZE =                // Size of the MPU protection region (5 bits)
        bit_field_t<1, 0x1f>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t RASR_SRD =                 // Subregion disable bits (8 bits)
        bit_field_t<8, 0xff>::value<X>();
    static constexpr uint32_t RASR_B = 0x10000;          // memory attribute
    static constexpr uint32_t RASR_C = 0x20000;          // memory attribute
    static constexpr uint32_t RASR_S = 0x40000;          // Shareable memory attribute
    template<uint32_t X>
    static constexpr uint32_t RASR_TEX =                 // memory attribute (3 bits)
        bit_field_t<19, 0x7>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t RASR_AP =                  // Access permission (3 bits)
        bit_field_t<24, 0x7>::value<X>();
    static constexpr uint32_t RASR_XN = 0x10000000;      // Instruction access disable bit
    static const uint32_t RASR_RESET_VALUE = 0x0;
};

static mpu_t& MPU = *reinterpret_cast<mpu_t*>(0xe000ed90);

#define HAVE_PERIPHERAL_MPU


////
//
//    SysTick timer
//
////

struct stk_t
{
    volatile uint32_t    CTRL;                 // [Read-write] SysTick control and status register
    volatile uint32_t    LOAD;                 // [Read-write] SysTick reload value register
    volatile uint32_t    VAL;                  // [Read-write] SysTick current value register
    volatile uint32_t    CALIB;                // [Read-write] SysTick calibration value register

    static constexpr uint32_t CTRL_ENABLE = 0x1;         // Counter enable
    static constexpr uint32_t CTRL_TICKINT = 0x2;        // SysTick exception request enable
    static constexpr uint32_t CTRL_CLKSOURCE = 0x4;      // Clock source selection
    static constexpr uint32_t CTRL_COUNTFLAG = 0x10000;  // COUNTFLAG
    static const uint32_t CTRL_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t LOAD_RELOAD =              // RELOAD value (24 bits)
        bit_field_t<0, 0xffffff>::value<X>();
    static const uint32_t LOAD_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t VAL_CURRENT =             // Current counter value (24 bits)
        bit_field_t<0, 0xffffff>::value<X>();
    static const uint32_t VAL_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t CALIB_TENMS =               // Calibration value (24 bits)
        bit_field_t<0, 0xffffff>::value<X>();
    static constexpr uint32_t CALIB_SKEW = 0x40000000;    // SKEW flag: Indicates whether the TENMS value is exact
    static constexpr uint32_t CALIB_NOREF = 0x80000000;   // NOREF flag. Reads as zero
    static const uint32_t CALIB_RESET_VALUE = 0x0;
};

static stk_t& STK = *reinterpret_cast<stk_t*>(0xe000e010);

#define HAVE_PERIPHERAL_STK


////
//
//    System control block
//
////

struct scb_t
{
    volatile uint32_t    CPUID;                // [Read-only] CPUID base register
    volatile uint32_t    ICSR;                 // [Read-write] Interrupt control and state register
    volatile uint32_t    VTOR;                 // [Read-write] Vector table offset register
    volatile uint32_t    AIRCR;                // [Read-write] Application interrupt and reset control register
    volatile uint32_t    SCR;                  // [Read-write] System control register
    volatile uint32_t    CCR;                  // [Read-write] Configuration and control register
    volatile uint32_t    SHPR1;                // [Read-write] System handler priority registers
    volatile uint32_t    SHPR2;                // [Read-write] System handler priority registers
    volatile uint32_t    SHPR3;                // [Read-write] System handler priority registers
    volatile uint32_t    SHCRS;                // [Read-write] System handler control and state register
    volatile uint32_t    CFSR_UFSR_BFSR_MMFSR; // [Read-write] Configurable fault status register
    volatile uint32_t    HFSR;                 // [Read-write] Hard fault status register
    reserved_t<1>        _0;
    volatile uint32_t    MMFAR;                // [Read-write] Memory management fault address register
    volatile uint32_t    BFAR;                 // [Read-write] Bus fault address register
    volatile uint32_t    AFSR;                 // [Read-write] Auxiliary fault status register

    template<uint32_t X>
    static constexpr uint32_t CPUID_Revision =            // Revision number (4 bits)
        bit_field_t<0, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CPUID_PartNo =              // Part number of the processor (12 bits)
        bit_field_t<4, 0xfff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CPUID_Constant =            // Reads as 0xF (4 bits)
        bit_field_t<16, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CPUID_Variant =             // Variant number (4 bits)
        bit_field_t<20, 0xf>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t CPUID_Implementer =         // Implementer code (8 bits)
        bit_field_t<24, 0xff>::value<X>();
    static const uint32_t CPUID_RESET_VALUE = 0x410fc241;

    template<uint32_t X>
    static constexpr uint32_t ICSR_VECTACTIVE =          // Active vector (9 bits)
        bit_field_t<0, 0x1ff>::value<X>();
    static constexpr uint32_t ICSR_RETTOBASE = 0x800;    // Return to base level
    template<uint32_t X>
    static constexpr uint32_t ICSR_VECTPENDING =         // Pending vector (7 bits)
        bit_field_t<12, 0x7f>::value<X>();
    static constexpr uint32_t ICSR_ISRPENDING = 0x400000;// Interrupt pending flag
    static constexpr uint32_t ICSR_PENDSTCLR = 0x2000000;// SysTick exception clear-pending bit
    static constexpr uint32_t ICSR_PENDSTSET = 0x4000000;// SysTick exception set-pending bit
    static constexpr uint32_t ICSR_PENDSVCLR = 0x8000000;// PendSV clear-pending bit
    static constexpr uint32_t ICSR_PENDSVSET = 0x10000000;// PendSV set-pending bit
    static constexpr uint32_t ICSR_NMIPENDSET = 0x80000000;// NMI set-pending bit.
    static const uint32_t ICSR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t VTOR_TBLOFF =              // Vector table base offset field (21 bits)
        bit_field_t<9, 0x1fffff>::value<X>();
    static const uint32_t VTOR_RESET_VALUE = 0x0;

    static constexpr uint32_t AIRCR_VECTRESET = 0x1;      // VECTRESET
    static constexpr uint32_t AIRCR_VECTCLRACTIVE = 0x2;  // VECTCLRACTIVE
    static constexpr uint32_t AIRCR_SYSRESETREQ = 0x4;    // SYSRESETREQ
    template<uint32_t X>
    static constexpr uint32_t AIRCR_PRIGROUP =            // PRIGROUP (3 bits)
        bit_field_t<8, 0x7>::value<X>();
    static constexpr uint32_t AIRCR_ENDIANESS = 0x8000;   // ENDIANESS
    template<uint32_t X>
    static constexpr uint32_t AIRCR_VECTKEYSTAT =         // Register key (16 bits)
        bit_field_t<16, 0xffff>::value<X>();
    static const uint32_t AIRCR_RESET_VALUE = 0x0;

    static constexpr uint32_t SCR_SLEEPONEXIT = 0x2;    // SLEEPONEXIT
    static constexpr uint32_t SCR_SLEEPDEEP = 0x4;      // SLEEPDEEP
    static constexpr uint32_t SCR_SEVEONPEND = 0x10;    // Send Event on Pending bit
    static const uint32_t SCR_RESET_VALUE = 0x0;

    static constexpr uint32_t CCR_NONBASETHRDENA = 0x1; // Configures how the processor enters Thread mode
    static constexpr uint32_t CCR_USERSETMPEND = 0x2;   // USERSETMPEND
    static constexpr uint32_t CCR_UNALIGN__TRP = 0x8;   // UNALIGN_ TRP
    static constexpr uint32_t CCR_DIV_0_TRP = 0x10;     // DIV_0_TRP
    static constexpr uint32_t CCR_BFHFNMIGN = 0x100;    // BFHFNMIGN
    static constexpr uint32_t CCR_STKALIGN = 0x200;     // STKALIGN
    static const uint32_t CCR_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t SHPR1_PRI_4 =               // Priority of system handler 4 (8 bits)
        bit_field_t<0, 0xff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t SHPR1_PRI_5 =               // Priority of system handler 5 (8 bits)
        bit_field_t<8, 0xff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t SHPR1_PRI_6 =               // Priority of system handler 6 (8 bits)
        bit_field_t<16, 0xff>::value<X>();
    static const uint32_t SHPR1_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t SHPR2_PRI_11 =              // Priority of system handler 11 (8 bits)
        bit_field_t<24, 0xff>::value<X>();
    static const uint32_t SHPR2_RESET_VALUE = 0x0;

    template<uint32_t X>
    static constexpr uint32_t SHPR3_PRI_14 =              // Priority of system handler 14 (8 bits)
        bit_field_t<16, 0xff>::value<X>();
    template<uint32_t X>
    static constexpr uint32_t SHPR3_PRI_15 =              // Priority of system handler 15 (8 bits)
        bit_field_t<24, 0xff>::value<X>();
    static const uint32_t SHPR3_RESET_VALUE = 0x0;

    static constexpr uint32_t SHCRS_MEMFAULTACT = 0x1;    // Memory management fault exception active bit
    static constexpr uint32_t SHCRS_BUSFAULTACT = 0x2;    // Bus fault exception active bit
    static constexpr uint32_t SHCRS_USGFAULTACT = 0x8;    // Usage fault exception active bit
    static constexpr uint32_t SHCRS_SVCALLACT = 0x80;     // SVC call active bit
    static constexpr uint32_t SHCRS_MONITORACT = 0x100;   // Debug monitor active bit
    static constexpr uint32_t SHCRS_PENDSVACT = 0x400;    // PendSV exception active bit
    static constexpr uint32_t SHCRS_SYSTICKACT = 0x800;   // SysTick exception active bit
    static constexpr uint32_t SHCRS_USGFAULTPENDED = 0x1000;// Usage fault exception pending bit
    static constexpr uint32_t SHCRS_MEMFAULTPENDED = 0x2000;// Memory management fault exception pending bit
    static constexpr uint32_t SHCRS_BUSFAULTPENDED = 0x4000;// Bus fault exception pending bit
    static constexpr uint32_t SHCRS_SVCALLPENDED = 0x8000;// SVC call pending bit
    static constexpr uint32_t SHCRS_MEMFAULTENA = 0x10000;// Memory management fault enable bit
    static constexpr uint32_t SHCRS_BUSFAULTENA = 0x20000;// Bus fault enable bit
    static constexpr uint32_t SHCRS_USGFAULTENA = 0x40000;// Usage fault enable bit
    static const uint32_t SHCRS_RESET_VALUE = 0x0;

    static constexpr uint32_t CFSR_UFSR_BFSR_MMFSR_IACCVIOL = 0x2;       // Instruction access violation flag
    static constexpr uint32_t CFSR_UFSR_BFSR_MMFSR_MUNSTKERR = 0x8;      // Memory manager fault on unstacking for a return from exception
    static constexpr uint32_t CFSR_UFSR_BFSR_MMFSR_MSTKERR = 0x10;       // Memory manager fault on stacking for exception entry.
    static constexpr uint32_t CFSR_UFSR_BFSR_MMFSR_MLSPERR = 0x20;       // MLSPERR
    static constexpr uint32_t CFSR_UFSR_BFSR_MMFSR_MMARVALID = 0x80;     // Memory Management Fault Address Register (MMAR) valid flag
    static constexpr uint32_t CFSR_UFSR_BFSR_MMFSR_IBUSERR = 0x100;      // Instruction bus error
    static constexpr uint32_t CFSR_UFSR_BFSR_MMFSR_PRECISERR = 0x200;    // Precise data bus error
    static constexpr uint32_t CFSR_UFSR_BFSR_MMFSR_IMPRECISERR = 0x400;  // Imprecise data bus error
    static constexpr uint32_t CFSR_UFSR_BFSR_MMFSR_UNSTKERR = 0x800;     // Bus fault on unstacking for a return from exception
    static constexpr uint32_t CFSR_UFSR_BFSR_MMFSR_STKERR = 0x1000;      // Bus fault on stacking for exception entry
    static constexpr uint32_t CFSR_UFSR_BFSR_MMFSR_LSPERR = 0x2000;      // Bus fault on floating-point lazy state preservation
    static constexpr uint32_t CFSR_UFSR_BFSR_MMFSR_BFARVALID = 0x8000;   // Bus Fault Address Register (BFAR) valid flag
    static constexpr uint32_t CFSR_UFSR_BFSR_MMFSR_UNDEFINSTR = 0x10000; // Undefined instruction usage fault
    static constexpr uint32_t CFSR_UFSR_BFSR_MMFSR_INVSTATE = 0x20000;   // Invalid state usage fault
    static constexpr uint32_t CFSR_UFSR_BFSR_MMFSR_INVPC = 0x40000;      // Invalid PC load usage fault
    static constexpr uint32_t CFSR_UFSR_BFSR_MMFSR_NOCP = 0x80000;       // No coprocessor usage fault.
    static constexpr uint32_t CFSR_UFSR_BFSR_MMFSR_UNALIGNED = 0x1000000;// Unaligned access usage fault
    static constexpr uint32_t CFSR_UFSR_BFSR_MMFSR_DIVBYZERO = 0x2000000;// Divide by zero usage fault
    static const uint32_t CFSR_UFSR_BFSR_MMFSR_RESET_VALUE = 0x0;

    static constexpr uint32_t HFSR_VECTTBL = 0x2;        // Vector table hard fault
    static constexpr uint32_t HFSR_FORCED = 0x40000000;  // Forced hard fault
    static constexpr uint32_t HFSR_DEBUG_VT = 0x80000000;// Reserved for Debug use
    static const uint32_t HFSR_RESET_VALUE = 0x0;


    static const uint32_t MMFAR_RESET_VALUE = 0x0;


    static const uint32_t BFAR_RESET_VALUE = 0x0;


    static const uint32_t AFSR_RESET_VALUE = 0x0;
};

static scb_t& SCB = *reinterpret_cast<scb_t*>(0xe000ed00);

#define HAVE_PERIPHERAL_SCB


////
//
//    Nested vectored interrupt controller
//
////

struct nvic_stir_t
{
    volatile uint32_t    STIR;                 // [Read-write] Software trigger interrupt register

    template<uint32_t X>
    static constexpr uint32_t STIR_INTID =               // Software generated interrupt ID (9 bits)
        bit_field_t<0, 0x1ff>::value<X>();
    static const uint32_t STIR_RESET_VALUE = 0x0;
};

static nvic_stir_t& NVIC_STIR = *reinterpret_cast<nvic_stir_t*>(0xe000ef00);

#define HAVE_PERIPHERAL_NVIC_STIR


////
//
//    Floating point unit CPACR
//
////

struct fpu_cpacr_t
{
    volatile uint32_t    CPACR;                // [Read-write] Coprocessor access control register

    template<uint32_t X>
    static constexpr uint32_t CPACR_CP =                  // CP (4 bits)
        bit_field_t<20, 0xf>::value<X>();
    static const uint32_t CPACR_RESET_VALUE = 0x0;
};

static fpu_cpacr_t& FPU_CPACR = *reinterpret_cast<fpu_cpacr_t*>(0xe000ed88);

#define HAVE_PERIPHERAL_FPU_CPACR


////
//
//    System control block ACTLR
//
////

struct scb_actrl_t
{
    volatile uint32_t    ACTRL;                // [Read-write] Auxiliary control register

    static constexpr uint32_t ACTRL_DISMCYCINT = 0x1;     // DISMCYCINT
    static constexpr uint32_t ACTRL_DISDEFWBUF = 0x2;     // DISDEFWBUF
    static constexpr uint32_t ACTRL_DISFOLD = 0x4;        // DISFOLD
    static constexpr uint32_t ACTRL_DISFPCA = 0x100;      // DISFPCA
    static constexpr uint32_t ACTRL_DISOOFP = 0x200;      // DISOOFP
    static const uint32_t ACTRL_RESET_VALUE = 0x0;
};

static scb_actrl_t& SCB_ACTRL = *reinterpret_cast<scb_actrl_t*>(0xe000e008);

#define HAVE_PERIPHERAL_SCB_ACTRL


template<typename PERIPHERAL> struct peripheral_traits {};

template<> struct peripheral_traits<adc1_t>
{
    static void enable() { RCC.APB2ENR |= rcc_t::APB2ENR_ADC1EN; }
    static void disable() { RCC.APB2ENR &= ~rcc_t::APB2ENR_ADC1EN; }
};

template<> struct peripheral_traits<crc_t>
{
    static void enable() { RCC.AHB1ENR |= rcc_t::AHB1ENR_CRCEN; }
    static void disable() { RCC.AHB1ENR &= ~rcc_t::AHB1ENR_CRCEN; }
    static void reset() { RCC.AHB1RSTR |= rcc_t::AHB1RSTR_CRCRST; }
};

template<> struct peripheral_traits<pwr_t>
{
    static void enable() { RCC.APB1ENR |= rcc_t::APB1ENR_PWREN; }
    static void disable() { RCC.APB1ENR &= ~rcc_t::APB1ENR_PWREN; }
    static void reset() { RCC.APB1RSTR |= rcc_t::APB1RSTR_PWRRST; }
};

template<> struct peripheral_traits<sdio_t>
{
    static void enable() { RCC.APB2ENR |= rcc_t::APB2ENR_SDIOEN; }
    static void disable() { RCC.APB2ENR &= ~rcc_t::APB2ENR_SDIOEN; }
    static void reset() { RCC.APB2RSTR |= rcc_t::APB2RSTR_SDIORST; }
};

template<> struct peripheral_traits<syscfg_t>
{
    static void enable() { RCC.APB2ENR |= rcc_t::APB2ENR_SYSCFGEN; }
    static void disable() { RCC.APB2ENR &= ~rcc_t::APB2ENR_SYSCFGEN; }
    static void reset() { RCC.APB2RSTR |= rcc_t::APB2RSTR_SYSCFGRST; }
};

template<> struct peripheral_traits<tim1_t>
{
    static void enable() { RCC.APB2ENR |= rcc_t::APB2ENR_TIM1EN; }
    static void disable() { RCC.APB2ENR &= ~rcc_t::APB2ENR_TIM1EN; }
    static void reset() { RCC.APB2RSTR |= rcc_t::APB2RSTR_TIM1RST; }
};

template<> struct peripheral_traits<tim10_t>
{
    static void enable() { RCC.APB2ENR |= rcc_t::APB2ENR_TIM10EN; }
    static void disable() { RCC.APB2ENR &= ~rcc_t::APB2ENR_TIM10EN; }
    static void reset() { RCC.APB2RSTR |= rcc_t::APB2RSTR_TIM10RST; }
};

template<> struct peripheral_traits<tim11_t>
{
    static void enable() { RCC.APB2ENR |= rcc_t::APB2ENR_TIM11EN; }
    static void disable() { RCC.APB2ENR &= ~rcc_t::APB2ENR_TIM11EN; }
    static void reset() { RCC.APB2RSTR |= rcc_t::APB2RSTR_TIM11RST; }
};

template<> struct peripheral_traits<tim2_t>
{
    static void enable() { RCC.APB1ENR |= rcc_t::APB1ENR_TIM2EN; }
    static void disable() { RCC.APB1ENR &= ~rcc_t::APB1ENR_TIM2EN; }
    static void reset() { RCC.APB1RSTR |= rcc_t::APB1RSTR_TIM2RST; }
};

template<> struct peripheral_traits<tim3_t>
{
    static void enable() { RCC.APB1ENR |= rcc_t::APB1ENR_TIM3EN; }
    static void disable() { RCC.APB1ENR &= ~rcc_t::APB1ENR_TIM3EN; }
    static void reset() { RCC.APB1RSTR |= rcc_t::APB1RSTR_TIM3RST; }
};

template<> struct peripheral_traits<tim4_t>
{
    static void enable() { RCC.APB1ENR |= rcc_t::APB1ENR_TIM4EN; }
    static void disable() { RCC.APB1ENR &= ~rcc_t::APB1ENR_TIM4EN; }
    static void reset() { RCC.APB1RSTR |= rcc_t::APB1RSTR_TIM4RST; }
};

template<> struct peripheral_traits<tim5_t>
{
    static void enable() { RCC.APB1ENR |= rcc_t::APB1ENR_TIM5EN; }
    static void disable() { RCC.APB1ENR &= ~rcc_t::APB1ENR_TIM5EN; }
    static void reset() { RCC.APB1RSTR |= rcc_t::APB1RSTR_TIM5RST; }
};

template<> struct peripheral_traits<tim9_t>
{
    static void enable() { RCC.APB2ENR |= rcc_t::APB2ENR_TIM9EN; }
    static void disable() { RCC.APB2ENR &= ~rcc_t::APB2ENR_TIM9EN; }
    static void reset() { RCC.APB2RSTR |= rcc_t::APB2RSTR_TIM9RST; }
};

template<> struct peripheral_traits<usart1_t>
{
    static void enable() { RCC.APB2ENR |= rcc_t::APB2ENR_USART1EN; }
    static void disable() { RCC.APB2ENR &= ~rcc_t::APB2ENR_USART1EN; }
    static void reset() { RCC.APB2RSTR |= rcc_t::APB2RSTR_USART1RST; }
};

template<> struct peripheral_traits<usart2_t>
{
    static void enable() { RCC.APB1ENR |= rcc_t::APB1ENR_USART2EN; }
    static void disable() { RCC.APB1ENR &= ~rcc_t::APB1ENR_USART2EN; }
};

template<> struct peripheral_traits<usart6_t>
{
    static void enable() { RCC.APB2ENR |= rcc_t::APB2ENR_USART6EN; }
    static void disable() { RCC.APB2ENR &= ~rcc_t::APB2ENR_USART6EN; }
    static void reset() { RCC.APB2RSTR |= rcc_t::APB2RSTR_USART6RST; }
};

template<> struct peripheral_traits<wwdg_t>
{
    static void enable() { RCC.APB1ENR |= rcc_t::APB1ENR_WWDGEN; }
    static void disable() { RCC.APB1ENR &= ~rcc_t::APB1ENR_WWDGEN; }
    static void reset() { RCC.APB1RSTR |= rcc_t::APB1RSTR_WWDGRST; }
};

template<> struct peripheral_traits<dma2_t>
{
    static void enable() { RCC.AHB1ENR |= rcc_t::AHB1ENR_DMA2EN; }
    static void disable() { RCC.AHB1ENR &= ~rcc_t::AHB1ENR_DMA2EN; }
    static void reset() { RCC.AHB1RSTR |= rcc_t::AHB1RSTR_DMA2RST; }
};

template<> struct peripheral_traits<dma1_t>
{
    static void enable() { RCC.AHB1ENR |= rcc_t::AHB1ENR_DMA1EN; }
    static void disable() { RCC.AHB1ENR &= ~rcc_t::AHB1ENR_DMA1EN; }
    static void reset() { RCC.AHB1RSTR |= rcc_t::AHB1RSTR_DMA1RST; }
};

template<> struct peripheral_traits<gpioh_t>
{
    static void enable() { RCC.AHB1ENR |= rcc_t::AHB1ENR_GPIOHEN; }
    static void disable() { RCC.AHB1ENR &= ~rcc_t::AHB1ENR_GPIOHEN; }
    static void reset() { RCC.AHB1RSTR |= rcc_t::AHB1RSTR_GPIOHRST; }
};

template<> struct peripheral_traits<gpioe_t>
{
    static void enable() { RCC.AHB1ENR |= rcc_t::AHB1ENR_GPIOEEN; }
    static void disable() { RCC.AHB1ENR &= ~rcc_t::AHB1ENR_GPIOEEN; }
    static void reset() { RCC.AHB1RSTR |= rcc_t::AHB1RSTR_GPIOERST; }
};

template<> struct peripheral_traits<gpiod_t>
{
    static void enable() { RCC.AHB1ENR |= rcc_t::AHB1ENR_GPIODEN; }
    static void disable() { RCC.AHB1ENR &= ~rcc_t::AHB1ENR_GPIODEN; }
    static void reset() { RCC.AHB1RSTR |= rcc_t::AHB1RSTR_GPIODRST; }
};

template<> struct peripheral_traits<gpioc_t>
{
    static void enable() { RCC.AHB1ENR |= rcc_t::AHB1ENR_GPIOCEN; }
    static void disable() { RCC.AHB1ENR &= ~rcc_t::AHB1ENR_GPIOCEN; }
    static void reset() { RCC.AHB1RSTR |= rcc_t::AHB1RSTR_GPIOCRST; }
};

template<> struct peripheral_traits<gpiob_t>
{
    static void enable() { RCC.AHB1ENR |= rcc_t::AHB1ENR_GPIOBEN; }
    static void disable() { RCC.AHB1ENR &= ~rcc_t::AHB1ENR_GPIOBEN; }
    static void reset() { RCC.AHB1RSTR |= rcc_t::AHB1RSTR_GPIOBRST; }
};

template<> struct peripheral_traits<gpioa_t>
{
    static void enable() { RCC.AHB1ENR |= rcc_t::AHB1ENR_GPIOAEN; }
    static void disable() { RCC.AHB1ENR &= ~rcc_t::AHB1ENR_GPIOAEN; }
    static void reset() { RCC.AHB1RSTR |= rcc_t::AHB1RSTR_GPIOARST; }
};

template<> struct peripheral_traits<i2c3_t>
{
    static void enable() { RCC.APB1ENR |= rcc_t::APB1ENR_I2C3EN; }
    static void disable() { RCC.APB1ENR &= ~rcc_t::APB1ENR_I2C3EN; }
    static void reset() { RCC.APB1RSTR |= rcc_t::APB1RSTR_I2C3RST; }
};

template<> struct peripheral_traits<i2c2_t>
{
    static void enable() { RCC.APB1ENR |= rcc_t::APB1ENR_I2C2EN; }
    static void disable() { RCC.APB1ENR &= ~rcc_t::APB1ENR_I2C2EN; }
    static void reset() { RCC.APB1RSTR |= rcc_t::APB1RSTR_I2C2RST; }
};

template<> struct peripheral_traits<i2c1_t>
{
    static void enable() { RCC.APB1ENR |= rcc_t::APB1ENR_I2C1EN; }
    static void disable() { RCC.APB1ENR &= ~rcc_t::APB1ENR_I2C1EN; }
    static void reset() { RCC.APB1RSTR |= rcc_t::APB1RSTR_I2C1RST; }
};

template<> struct peripheral_traits<spi1_t>
{
    static void enable() { RCC.APB2ENR |= rcc_t::APB2ENR_SPI1EN; }
    static void disable() { RCC.APB2ENR &= ~rcc_t::APB2ENR_SPI1EN; }
    static void reset() { RCC.APB2RSTR |= rcc_t::APB2RSTR_SPI1RST; }
};

template<> struct peripheral_traits<spi2_t>
{
    static void enable() { RCC.APB1ENR |= rcc_t::APB1ENR_SPI2EN; }
    static void disable() { RCC.APB1ENR &= ~rcc_t::APB1ENR_SPI2EN; }
    static void reset() { RCC.APB1RSTR |= rcc_t::APB1RSTR_SPI2RST; }
};

template<> struct peripheral_traits<spi3_t>
{
    static void enable() { RCC.APB1ENR |= rcc_t::APB1ENR_SPI3EN; }
    static void disable() { RCC.APB1ENR &= ~rcc_t::APB1ENR_SPI3EN; }
    static void reset() { RCC.APB1RSTR |= rcc_t::APB1RSTR_SPI3RST; }
};

template<> struct peripheral_traits<spi4_t>
{
    static void enable() { RCC.APB2ENR |= rcc_t::APB2ENR_SPI4EN; }
    static void disable() { RCC.APB2ENR &= ~rcc_t::APB2ENR_SPI4EN; }
};

}

struct interrupt
{
    static inline void enable() { __asm volatile ("cpsie i"); }
    static inline void disable() { __asm volatile ("cpsid i"); }

    enum interrupt_t
    { RESET = -15
    , NMI = -14
    , HARDFAULT = -13
    , MEMMANAGE = -12
    , BUSFAULT = -11
    , USAGEFAULT = -10
    , SVCALL = -5
    , DEBUG = -4
    , PENDSV = -2
    , SYSTICK = -1
    , PVD = 1
    , TAMP_STAMP = 2
    , RTC_WKUP = 3
    , FLASH = 4
    , RCC = 5
    , EXTI0 = 6
    , EXTI1 = 7
    , EXTI2 = 8
    , EXTI3 = 9
    , EXTI4 = 10
    , ADC = 18
    , EXTI9_5 = 23
    , TIM1_BRK_TIM9 = 24
    , TIM1_UP_TIM10 = 25
    , TIM1_TRG_COM_TIM11 = 26
    , TIM1_CC = 27
    , TIM2 = 28
    , TIM3 = 29
    , TIM4 = 30
    , I2C1_EV = 31
    , I2C1_ER = 32
    , I2C2_EV = 33
    , I2C2_ER = 34
    , SPI1 = 35
    , SPI2 = 36
    , USART1 = 37
    , USART2 = 38
    , EXTI15_10 = 40
    , RTC_ALARM = 41
    , OTG_FS_WKUP = 42
    , SDIO = 49
    , TIM5 = 50
    , SPI3 = 51
    , OTG_FS = 67
    , I2C3_EV = 72
    , I2C3_ER = 73
    , FPU = 81
    , SPI4 = 84
    };
};
