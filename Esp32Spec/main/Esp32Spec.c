/*
 * SPDX-FileCopyrightText: 2010-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */

 #include <stdio.h>
 #include <inttypes.h>
 #include "sdkconfig.h"
 #include "freertos/FreeRTOS.h"
 #include "freertos/task.h"
 #include "esp_system.h"
 #include "spi_flash_mmap.h"
 #include "esp_heap_caps.h"
 #include "esp_log.h"
 #include "esp_chip_info.h"
 #include "esp_flash.h"
 #include "MemoryStatus.c"
 
 int intParam = 8;
 
 void app_task(void *pvParam)
 {
 
        printf("Executing the task1!\n");
        vTaskDelay(3000 / portTICK_PERIOD_MS);
 
        printf("Executing the task2!\n");
        vTaskDelay(3000 / portTICK_PERIOD_MS);
 
        printf("Executing the task3!\n");
        vTaskDelay(3000 / portTICK_PERIOD_MS);
 
        printf("Executing the task4!\n");
        vTaskDelay(3000 / portTICK_PERIOD_MS);
        vTaskDelete(NULL);
        printf("Executing the task5!\n");
 }
 
 void app_task_integer(void * pvParam)
 {
        
        //configASSERT( ( ( uint32_t ) pvParam ) == 8 );
        //printf("Value:  %p\n", (void*)pvParam );
        int *param = ( int *) pvParam;
        
        
        if (param != NULL){
            printf("In app task integer !\n");
            printf("Executing task integer= %d!\n", *param);
        }
        //vTaskDelay(3000 / portTICK_PERIOD_MS);
       UBaseType_t stackWatermark = uxTaskGetStackHighWaterMark(NULL);
       printf("Task stack high watermark: %u words\n", stackWatermark);
        vTaskDelete(NULL);
 }
 
 /* void app_task_integer_array(void *pvParam)
 {
        int *param = (int *) pvParam;
        int counter = 0;
        while (*(param+counter) != NULL)
        {
               printf("Executing task integer array %d!\n", *(param+counter));
               counter++;
        }
        vTaskDelete(NULL);
        
 } */
 
 
 
 
 void app_main(void)
 {
 
        printf("Hello world!\n");
        //xTaskCreate(app_task_integer, "TaskInt", 1024, (void*) &pam_int, 1, NULL);
        xTaskCreatePinnedToCore(memory_status, "MemStatus", 2048, NULL, 1, NULL, 0);
       vTaskDelay(3000 / portTICK_PERIOD_MS);
 }
 