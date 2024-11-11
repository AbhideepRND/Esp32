#include "freertos/FreeRTOS.h"
#include "esp_wifi.h"
#include "esp_system.h"
#include "esp_event.h"
#include "esp_event_loop.h"
#include "nvs_flash.h"
#include "driver/gpio.h"

#include "reg_neo_pix.h"
#include <esp_netif.h>
#include <esp_now.h>

void app_main(void)
{

    while (true) {
    	rgb_led_wifi_app_started();
		vTaskDelay(1000 / portTICK_PERIOD_MS);
		rgb_led_http_server_started();
		vTaskDelay(1000 / portTICK_PERIOD_MS);
		rgb_led_wifi_connect();
		vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

