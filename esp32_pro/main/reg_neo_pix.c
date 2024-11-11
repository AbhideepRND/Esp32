/*
 * reg_neo_pix.c
 *
 *  Created on: 08-Nov-2024
 *      Author: Abhideep
 */

#include <stdbool.h>
#include <stdio.h>

#include "driver/ledc.h"
#include "reg_neo_pix.h"
#include "ws2811.h"
#include "driver/gpio.h"

led_strip_t *strip;

bool g_pwm_init_handle = false;

static void rgb_led_pwm_init(void) {
	strip = led_strip_init(RMT_CHANNEL_0, RGB_NEO_PIXEL_GPIO,
			NEO_PIXEL_COUNT);

	if (!strip) {
		printf("Failed to initialize LED strip\n");
		return;
	}

	g_pwm_init_handle = true;
}


/**
 * Sets the RGB color.
 */
static void rgb_led_set_color(uint8_t red, uint8_t green, uint8_t blue)
{
	// Value should be 0 - 255 for 8 bit number
	for (int i = 0; i < NEO_PIXEL_COUNT; i++) {
		led_strip_set_pixel(strip, i, red, green, blue);
	}
	led_strip_refresh(strip);
}

void rgb_led_wifi_app_started(void)
{
	if (g_pwm_init_handle == false)
	{
		rgb_led_pwm_init();
	}

	rgb_led_set_color(255, 102, 255);
}

void rgb_led_http_server_started(void)
{
	if (g_pwm_init_handle == false)
	{
		rgb_led_pwm_init();
	}

	rgb_led_set_color(204, 255, 51);
}


void rgb_led_wifi_connect(void)
{
	if (g_pwm_init_handle == false)
	{
		rgb_led_pwm_init();
	}

	rgb_led_set_color(0, 255, 153);
}
