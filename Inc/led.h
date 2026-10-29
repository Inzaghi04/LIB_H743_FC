#ifndef LED_H
#define LED_H

#include <stdbool.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
    LED_OK = 0,
    LED_ERR
} led_stat_t;

typedef void (*led_write_fn)(void *port, bool level);

typedef struct
{
    led_write_fn write;
    void *port;
    bool active_high;
} led_config_t;

typedef struct
{
    led_config_t cfg;
    bool is_on;
} led_t;

led_stat_t led_init(led_t *led, const led_config_t *cfg);
led_stat_t led_on(led_t *led);
led_stat_t led_off(led_t *led);
led_stat_t led_toggle(led_t *led);
led_stat_t led_set(led_t *led, bool on);
bool led_is_on(const led_t *led);

#ifdef __cplusplus
}
#endif


#endif /* LED_H */
