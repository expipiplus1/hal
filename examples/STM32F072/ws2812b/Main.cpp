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
#include <cstdlib>

using hal::sys_tick;
using namespace hal::timer;
using namespace hal::dma;
using namespace hal::spi;
using namespace ws2812b;

const int num_leds = 16;

typedef timer_t<3> tim_a;
typedef ws2812b_t<dma_t<1>, 5, spi_t<2, PB13, PB15>, num_leds, inverted>
    ws2812b_a;

// The upper 1k of flash
volatile uint16_t *flash_rw = reinterpret_cast<volatile uint16_t*>(0x0800FC00);

void loop();

enum mode_t{
    rainbowCycle
  , greenAndRed
  , mode_last
};

mode_t cycleMode();

template <> void handler<interrupt::TIM3>() {
  tim_a::clear_uif();
  loop();
}

static mode_t mode;

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
  srand(static_cast<unsigned>(1));

  mode = cycleMode();
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

void unlockFlash(){
  static bool unlocked = false;
  if (!unlocked) {
    while ((device::FLASH.SR & device::flash_t::SR_BSY) != 0)
      ;
    if ((device::FLASH.CR & device::flash_t::CR_LOCK) != 0) {
      device::FLASH.KEYR = 0x45670123;
      device::FLASH.KEYR = 0xCDEF89AB;
    }
    unlocked = true;
  }
}

void eraseFlashPage(volatile uint16_t *p){
  unlockFlash();

  device::FLASH.CR |= device::flash_t::CR_PER;
  device::FLASH.AR = reinterpret_cast<uint32_t>(p);
  device::FLASH.CR |= device::flash_t::CR_STRT;
  while ((device::FLASH.SR & device::flash_t::SR_BSY) !=
         0)  {
  }
  if ((device::FLASH.SR & device::flash_t::SR_EOP) != 0)  {
    device::FLASH.SR = device::flash_t::SR_EOP;
  } else {
  }
  device::FLASH.CR &= ~device::flash_t::CR_PER;
}

void writeFlash(const uint16_t x, volatile uint16_t *p) {
  unlockFlash();

  device::FLASH.CR |= device::flash_t::CR_PG;
  *p = x;
  while ((device::FLASH.SR & device::flash_t::SR_BSY) != 0)
    ;

  if ((device::FLASH.SR & device::flash_t::SR_EOP) != 0) {
    device::FLASH.SR = device::flash_t::SR_EOP;
  }
  device::FLASH.CR &= ~device::flash_t::CR_PG;
}

mode_t cycleMode(){
  mode = static_cast<mode_t>(flash_rw[0]);
  unlockFlash();
  eraseFlashPage(&flash_rw[0]);
  writeFlash((mode+1) % mode_last, &flash_rw[0]);
  return mode;
}

void loop(){
  static uint32_t i = 0;
  const uint8_t brightnessScale = 8;

  i++;

  static color cs[num_leds] = {};

  switch (mode){
    case rainbowCycle:
      for (int j = 0; j < num_leds; ++j) {
        cs[j] = fadeIn(rainbow, i - (1024 / num_leds) * j);
      }
      break;
    case greenAndRed:
      if((i&0x7) == 0){
        for (int j = 0; j < num_leds; ++j) {
          cs[j].r = cs[j].r == 0 ? 0 : cs[j].r - 1;
          cs[j].g = cs[j].g == 0 ? 0 : cs[j].g - 1;
          cs[j].b = cs[j].b == 0 ? 0 : cs[j].b - 1;
        }
      }
      for (int j = 0; j < num_leds; ++j) {
        if ((rand() & 0x3fff) == 0){
          cs[j].r = clamp(cs[j].r + 255, 0, 255);
        }
        if ((rand() & 0x3fff) == 1){
          cs[j].g = clamp(cs[j].g + 255, 0, 255);
        }
        if ((rand() & 0xffff) == 2){
          cs[j].b = clamp(cs[j].b + 255, 0, 255);
        }
        if ((rand() & 0xffff) == 4){
          cs[j].r = clamp(cs[j].r + 255, 0, 255);
          cs[j].g = clamp(cs[j].g + 165, 0, 255);
        }
      }
      break;
    default:
      for (int j = 0; j < num_leds; ++j) {
        cs[j] = color{0,255,0};
      }
      break;
  }

  color scaled[num_leds];
  for(int j = 0; j < num_leds; ++j) {
    scaled[j] = cs[j] / brightnessScale;
  }

  ws2812b_a::writeColors(scaled);
}
