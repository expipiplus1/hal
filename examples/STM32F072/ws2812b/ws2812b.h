#pragma once

#include <dma.h>
#include <spi.h>

#include <cstdint>

namespace ws2812b {

using namespace hal::spi;
using namespace hal::dma;

// Use if the data signal to the ws2812b goes through an inverter
enum polarity { inverted, non_inverted };

struct color {
  uint8_t g, r, b;
  color operator/(uint8_t x) {
    return color{static_cast<uint8_t>(g / x), static_cast<uint8_t>(r / x),
                 static_cast<uint8_t>(b / x)};
  }
};

// This ws2812b interface uses an SPI MOSI pin to generate the PWM waveform to
// send the colors.
template <typename DMA, uint8_t DMA_CH, typename SPI, int NUM_LEDS,
          polarity POLARITY = non_inverted>
struct ws2812b_t {
  typedef SPI spi;
  typedef DMA dma;

  static void setup() {
    spi::template setup<mode_0, msb_first, fpclk_16, high_speed>();
    dma::setup();
  }

  static void writeColors(const color cs[NUM_LEDS]) {
    for (int i = 0; i < NUM_LEDS; ++i) {
      const color &c = cs[i];
      // For some reason the lower few bits of red do not work and cause
      // artifacts
      const uint32_t cs[3] = {ws2812bComponent(c.g),
                              ws2812bComponent(c.r & 0xf8),
                              ws2812bComponent(c.b)};

      for (int j = 0; j < 3; ++j) {
        ws2812bBuffer[9 * i + 3 * j + 0] = cs[j] >> 16;
        ws2812bBuffer[9 * i + 3 * j + 1] = cs[j] >> 8;
        ws2812bBuffer[9 * i + 3 * j + 2] = cs[j] >> 0;
      }
    }

    dma::template disable<DMA_CH>();
    dma::template mem_to_periph<DMA_CH, uint8_t, dma_type_size<uint8_t>(),
                                not_circular>(
        ws2812bBuffer, 9 * NUM_LEDS,
        reinterpret_cast<volatile uint32_t *>(spi::getDest()));
    dma::template enable<DMA_CH>();
  }

private:
  // Insert two zeros before each bit of the input
  static uint32_t spreadBits3(const uint8_t x) {
    uint32_t r = x;
    // Move the upper four bits such that the fifth lsb bit is in the correct
    // position (4th position to 12th), mask out the bits in the middle
    r = (r | (r << 8)) & 0b000000001111000000001111;
    // Move the upper 2 bits of each four such that third lsb is in the correct
    // position (2nd position to 6th), mask out the extra added bits
    r = (r | (r << 4)) & 0b000011000011000011000011;
    // Move the upper bit of each pair such that it is in the correct position
    // and mask out the extra bits
    r = (r | (r << 2)) & 0b001001001001001001001001;
    return r;
  }

  // Given an 8 bit color, construct a 24 bit value which approximated the PWM
  // waveform encoding that color
  static uint32_t ws2812bComponent(const uint8_t c) {
    const uint32_t r =
        spreadBits3(0xff) << 2 | spreadBits3(c) << 1 | spreadBits3(0x00) << 0;
    return POLARITY == inverted ? ~r : r;
  }

  static inline uint8_t ws2812bBuffer[NUM_LEDS * 9];
};

} // namespace ws2812b
