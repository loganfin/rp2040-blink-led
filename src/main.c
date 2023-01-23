#include "boards/adafruit_feather_rp2040.h"
#include "pico/stdlib.h"

#define LED_PIN PICO_DEFAULT_LED_PIN

int main()
{
    const int dot_ms = 200;
    const int dash_ms = 400;
    int wait_ms = 0;
    int counter = 0;

    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    while (true) {
        if (counter == 0) {
            wait_ms = dot_ms;
        }
        else if (counter == 3) {
            wait_ms = dash_ms;
        }
        gpio_put(LED_PIN, 1);
        sleep_ms(wait_ms);
        gpio_put(LED_PIN, 0);
        sleep_ms(wait_ms);
        counter++;
        if (counter > 5) {
            counter = 0;
        }
    }
}
