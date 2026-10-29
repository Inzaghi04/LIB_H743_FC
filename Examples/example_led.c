/*
 * Example: use led.h
 */
#include "stm32h7xx_hal.h"      /* or "stm32f4xx_hal.h" */
#include "led.h"

static void led_write(void *port, bool level)
{
    HAL_GPIO_WritePin((GPIO_TypeDef *)port, GPIO_PIN_0, level ? GPIO_PIN_SET : GPIO_PIN_RESET);
}

static led_t led;

int main(void)
{
    HAL_Init();
    SystemClock_Config();
    MX_GPIO_Init();

    led_config_t cfg = {
        .write       = led_write,
        .port        = GPIOB,
        .active_high = true,
    };
    led_init(&led, &cfg);

    while (1)
    {
        led_toggle(&led);
        HAL_Delay(500);
    }
}
