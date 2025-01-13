#include <stdio.h>
#include "pico/stdlib.h"

#define led_pin_red 13

int time_point = 200;
int time_dot = 800;
int time_dot_and_dash_interval = 125;
int time_letter_range = 250;
int time_ciclo = 3000;

int x = 1;


void morse_S()
{
    for (int i = 0; i < 3; i++)
    {
        gpio_put(led_pin_red, true);
        sleep_ms(time_point);
        printf(".");
        gpio_put(led_pin_red, false);
        sleep_ms(time_dot_and_dash_interval);
    }
    printf(" ");
}

void morse_O()
{
    for (int i = 0; i < 3; i++)
    {
        gpio_put(led_pin_red, true);
        sleep_ms(time_dot);
        printf("-");
        gpio_put(led_pin_red, false);
        sleep_ms(time_dot_and_dash_interval);
    }
    printf(" ");
}

int main()
{
    stdio_init_all();
    gpio_init(led_pin_red);
    gpio_set_dir(led_pin_red, GPIO_OUT);


    while (true)
    {
        printf("Sinal SOS: ");
        morse_S();
        sleep_ms(time_letter_range);
        morse_O();
        sleep_ms(time_letter_range);
        morse_S();
        sleep_ms(time_ciclo);
        printf("\n");
    }
}
