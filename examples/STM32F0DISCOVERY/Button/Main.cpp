#include <timer.h>
#include <button.h>
#include <gpio.h>

using namespace hal::timer;
using namespace hal::gpio;

typedef button_t<PA0> btn;
typedef timer_t<6> aux;

typedef output_t<PC8> led_a;
typedef output_t<PC9> led_b;

template<> void handler<interrupt::TIM6_DAC>()
{
    aux::clear_uif();
    btn::update();
}

int main()
{
    btn::setup<pull_down>();
    aux::setup(100, 1000);
    aux::update_interrupt_enable();
    led_a::setup();
    led_b::setup();
    int i = 0;

    hal::nvic<interrupt::TIM6_DAC>::enable();
    interrupt::enable();

    for (;;)
    {
        if (btn::read())
            ++i;

        led_a::write(i & 1);
        led_b::write(i & 2);
    }
}

