#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <libubox/uloop.h>
#include "gpio.h"
#include "led_control.h"
#include "uloop_setup.h"

void cleanup(int sig) {
    gpio_cleanup();
    printf("GPIO cleared.\n");
    uloop_end();
}

int main() {
    // Initialize GPIO and set direction
    gpio_init();
    gpio_set_direction("out");

    // Set up cleanup on program interrupt (CTRL+C)
    signal(SIGINT, cleanup);

    // Initialize uloop and start LED toggling
    uloop_init();
    setup_led_toggle();
    uloop_run();

    // Cleanup on exit
    uloop_done();
    cleanup(0);  // Ensure cleanup if uloop exits normally
    return 0;
}
