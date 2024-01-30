#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
void hello_task(void *pvParameter)
{
	while(1)
	{
	    printf("Hello world!\n");
	    vTaskDelay(100 / portTICK_PERIOD_MS);
	}
	vTaskDelete(NULL);
}
void blinky(void *pvParameter)
{
    while(1)
	{
	    printf("Blinky!\n");
	    vTaskDelay(100 / portTICK_PERIOD_MS);
	}
	vTaskDelete(NULL);
}
void app_main()
{
    xTaskCreate(&hello_task, "hello_task", 1024*5, NULL, 5, NULL);
    xTaskCreate(&blinky, "blinky", 1024*5,NULL,5,NULL );
}
