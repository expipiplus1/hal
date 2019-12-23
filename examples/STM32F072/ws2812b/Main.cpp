////
//
//      Drive WS2812B using SPI peripheral
//
////

#include "ws2812b.h"

#include <dma.h>
#include <hal.h>
#include <spi.h>
#include <timer.h>

#include <algorithm>
#include <cstdint>

using hal::sys_tick;
using namespace hal::timer;
using namespace hal::dma;
using namespace hal::spi;
using namespace ws2812b;

const int num_leds = 16;

typedef timer_t<3> tim_a;
typedef ws2812b_t<dma_t<1>, 5, spi_t<2, PB13, PB15>, num_leds, inverted>
    ws2812b_a;

void loop();

template <> void handler<interrupt::TIM3>() {
  tim_a::clear_uif();
  loop();
}

int main() {
  ws2812b_a::setup();

  color cs[num_leds];
  for (int j = 0; j < num_leds; ++j) {
    cs[j] = color{0, 0, 0};
  }

  // TODO: Determine why just clearing once doesn't work!
  ws2812b_a::writeColors(cs);
  sys_tick::delay_ms(1);
  ws2812b_a::writeColors(cs);

  sys_tick::delay_ms(300);

  tim_a::setup(100, 480);
  tim_a::update_interrupt_enable();
  hal::nvic<interrupt::TIM3>::enable();
  interrupt::enable();

  for (;;)
    ;
}

template <typename T> T clamp(T x, T l = 0, T u = 1) {
  return std::max(std::min(x, u), l);
}

color rainbow(int t) {
  const int d = t & 1023; // angle in 1/1024s
  const int g = clamp(std::min((d - (0 * 1024 / 6)) * 256 * 6 / 1024,
                               (-d + (4 * 1024 / 6)) * 256 * 6 / 1024),
                      0, 255);
  const int b = clamp(std::min((d - (2 * 1024 / 6)) * 256 * 6 / 1024,
                               (-d + (6 * 1024 / 6)) * 256 * 6 / 1024),
                      0, 255);
  const int r = clamp(std::max((d - (4 * 1024 / 6)) * 256 * 6 / 1024,
                               (-d + (2 * 1024 / 6)) * 256 * 6 / 1024),
                      0, 255);
  return color{static_cast<uint8_t>(r), static_cast<uint8_t>(g),
               static_cast<uint8_t>(b)};
}

// Fade in a color over the first 1024 time units
color fadeIn(color f(int), int t) {
  color c = f(t);
  t = clamp(t, 0, 1000);
  if (t < 1024) {
    c.r = c.r * t / 1024;
    c.g = c.g * t / 1024;
    c.b = c.b * t / 1024;
  }
  return c;
}

void loop() {
  static uint32_t i = 0;
  const uint8_t brightnessScale = 4;

  i++;

  color cs[num_leds];
  for (int j = 0; j < num_leds; ++j) {
    cs[j] = fadeIn(rainbow, i - (1024 / num_leds) * j) / brightnessScale;
  }

  ws2812b_a::writeColors(cs);
}
