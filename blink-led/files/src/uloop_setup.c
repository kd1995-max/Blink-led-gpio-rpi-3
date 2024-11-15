#include "uloop_setup.h"
#include <libubox/uloop.h>

void uloop_setup() {
    uloop_init();
}

void uloop_teardown() {
    uloop_done();
}
