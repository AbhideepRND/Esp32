/*
 * reg_neo_pix.h
 *
 *  Created on: 08-Nov-2024
 *      Author: Abhideep
 */

#ifndef MAIN_REG_NEO_PIX_H_
#define MAIN_REG_NEO_PIX_H_

#define RGB_NEO_PIXEL_GPIO		18

#define NEO_PIXEL_COUNT 		1

//Define RGB Channel
#define RGB_LED_CHANNEL_MAX 	3

//Structure of RGB LED
typedef struct {

	int channel;
	int gpio;
	int mode;
	int timer_index;
} ledc_info_t;

/**
 * Color to indicate WiFi application has started.
 */

void rgb_led_wifi_app_started(void);


/**
 * Color combination of Http Server Status
 */

void rgb_led_http_server_started(void);

/**
 * Color combination of Wifi Connect
 */

void rgb_led_wifi_connect(void);

/**
 * Color combination of Wifi disconnect
 */

void rgb_led_wifi_disconnect(void);

#endif /* MAIN_REG_NEO_PIX_H_ */
