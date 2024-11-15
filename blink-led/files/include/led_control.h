#ifndef LED_CONTROL_H
#define LED_CONTROL_H

#include <libubox/uloop.h>

void toggle_led(struct uloop_timeout *t);
void setup_led_toggle();

#endif
