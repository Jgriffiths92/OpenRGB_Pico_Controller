#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "openrgb_protocol.h"


// Define GPIO pins for 4 RGB ports (change as needed for your board)
#define RGB1_R 2
#define RGB1_G 3
#define RGB1_B 4
#define RGB2_R 5
#define RGB2_G 6
#define RGB2_B 7
#define RGB3_R 8
#define RGB3_G 9
#define RGB3_B 10
#define RGB4_R 11
#define RGB4_G 12
#define RGB4_B 13

void set_all_rgb(const uint8_t rgb[12]) {
    pwm_set_gpio_level(RGB1_R, rgb[0] * 257);
    pwm_set_gpio_level(RGB1_G, rgb[1] * 257);
    pwm_set_gpio_level(RGB1_B, rgb[2] * 257);
    pwm_set_gpio_level(RGB2_R, rgb[3] * 257);
    pwm_set_gpio_level(RGB2_G, rgb[4] * 257);
    pwm_set_gpio_level(RGB2_B, rgb[5] * 257);
    pwm_set_gpio_level(RGB3_R, rgb[6] * 257);
    pwm_set_gpio_level(RGB3_G, rgb[7] * 257);
    pwm_set_gpio_level(RGB3_B, rgb[8] * 257);
    pwm_set_gpio_level(RGB4_R, rgb[9] * 257);
    pwm_set_gpio_level(RGB4_G, rgb[10] * 257);
    pwm_set_gpio_level(RGB4_B, rgb[11] * 257);
}

int main() {
    stdio_init_all();
    // Initialize PWM for all RGB pins
    const uint RGB_PINS[12] = {
        RGB1_R, RGB1_G, RGB1_B,
        RGB2_R, RGB2_G, RGB2_B,
        RGB3_R, RGB3_G, RGB3_B,
        RGB4_R, RGB4_G, RGB4_B
    };
    for (int i = 0; i < 12; ++i) {
        gpio_set_function(RGB_PINS[i], GPIO_FUNC_PWM);
        uint slice = pwm_gpio_to_slice_num(RGB_PINS[i]);
        pwm_set_enabled(slice, true);
    }

    openrgb_init(set_all_rgb);
    while (1) {
        openrgb_task();
    }
    return 0;
}
