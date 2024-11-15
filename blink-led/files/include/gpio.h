#ifndef GPIO_H
#define GPIO_H

void gpio_init();
void gpio_cleanup();
void gpio_set_direction(const char *direction);
void gpio_write(int value);

#endif
