#include "gpio.h"
#include "led_control.h"
#include <libubox/uloop.h>

static int led_on = 0;
struct uloop_timeout led_timer;

void toggle_led(struct uloop_timeout *t) {
    led_on = !led_on;
    gpio_write(led_on);

    // Reset timer for 1 second
    uloop_timeout_set(&led_timer, 1000);
}

void setup_led_toggle() {
    led_timer.cb = toggle_led;
    uloop_timeout_set(&led_timer, 1000);  // Initial delay for 1 second
}
