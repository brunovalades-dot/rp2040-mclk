#include "pico/stdlib.h"
#include "hardware/pwm.h"

int main() {
    const uint GPIO_MCLK = 14;
    gpio_set_function(GPIO_MCLK, GPIO_FUNC_PWM);
    uint slice = pwm_gpio_to_slice_num(GPIO_MCLK);

    pwm_set_clkdiv(slice, 1.0f);      // No clock division
    pwm_set_wrap(slice, 10);          // 125 MHz / 11 ≈ 11.36 MHz
    pwm_set_chan_level(slice, PWM_CHAN_A, 5); // 50% duty cycle
    pwm_set_enabled(slice, true);

    while (true) {
        tight_loop_contents(); // Keep running
    }
}
