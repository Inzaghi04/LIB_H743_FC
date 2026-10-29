#include "led.h"

static void led_apply(led_t *led, bool on)
{
    bool level = (on == led->cfg.active_high);
    led->cfg.write(led->cfg.port, level);
    led->is_on = on;
}

led_stat_t led_init(led_t *led, const led_config_t *cfg)
{
    if (led == NULL || cfg == NULL || cfg->write == NULL)
    {
        return LED_ERR;
    }
    led->cfg = *cfg;
    led_apply(led, false);
    return LED_OK;
}

led_stat_t led_set(led_t *led, bool on)
{
    if (led == NULL || led->cfg.write == NULL)
    {
        return LED_ERR;
    }
    led_apply(led, on);
    return LED_OK;
}

led_stat_t led_on(led_t *led)
{
    return led_set(led, true);
}

led_stat_t led_off(led_t *led)
{
    return led_set(led, false);
}

led_stat_t led_toggle(led_t *led)
{
    if (led == NULL)
    {
        return LED_ERR;
    }
    return led_set(led, !led->is_on);
}

bool led_is_on(const led_t *led)
{
    return (led != NULL) && led->is_on;
}
