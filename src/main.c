#include "pico/stdlib.h"

#define LED_PIN PICO_DEFAULT_LED_PIN

#define UNIT_MS 200

void letter_dots(const int dots);
void letter_dashes(const int dashes);

int main()
{
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    while (true) {
        letter_dots(3);
        sleep_ms(3 * UNIT_MS);
        letter_dashes(3);
        sleep_ms(3 * UNIT_MS);
        letter_dots(3);
        sleep_ms(7 * UNIT_MS);
    }
}

void letter_dots(const int dots)
{
    for (int i = 0; i < dots; i++) {
        gpio_put(LED_PIN, 1);
        sleep_ms(UNIT_MS);
        gpio_put(LED_PIN, 0);
        sleep_ms(UNIT_MS);
    }
}

void letter_dashes(const int dashes)
{
    for (int i = 0; i < dashes; i++) {
        gpio_put(LED_PIN, 1);
        sleep_ms(3 * UNIT_MS);
        gpio_put(LED_PIN, 0);
        sleep_ms(3 * UNIT_MS);
    }
}
