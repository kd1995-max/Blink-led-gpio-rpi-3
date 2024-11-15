#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "gpio.h"

#define LED_PIN "17"
#define GPIO_EXPORT "/sys/class/gpio/export"
#define GPIO_UNEXPORT "/sys/class/gpio/unexport"
#define GPIO_DIR "/sys/class/gpio/gpio" LED_PIN "/direction"
#define GPIO_VAL "/sys/class/gpio/gpio" LED_PIN "/value"

void gpio_init() {
    int fd = open(GPIO_EXPORT, O_WRONLY);
    write(fd, LED_PIN, sizeof(LED_PIN) - 1);
    close(fd);
}

void gpio_cleanup() {
    int fd = open(GPIO_VAL, O_WRONLY);
    write(fd, "0", 1);
    close(fd);

    fd = open(GPIO_UNEXPORT, O_WRONLY);
    write(fd, LED_PIN, sizeof(LED_PIN) - 1);
    close(fd);
}

void gpio_set_direction(const char *direction) {
    int fd = open(GPIO_DIR, O_WRONLY);
    write(fd, direction, 3);
    close(fd);
}

void gpio_write(int value) {
    int fd = open(GPIO_VAL, O_WRONLY);
    write(fd, value ? "1" : "0", 1);
    close(fd);
}

