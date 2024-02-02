
#include <stdio.h>
#include <stdlib.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_task_wdt.h"
#include <esp_log.h>

esp_task_wdt_config_t wdt_config={
									.timeout_ms=5000,
									.idle_core_mask=1<<0,
									.trigger_panic=false
									};

TaskHandle_t task_handle;

void reset_task(void *arg)
{
    //Subscribe this task to TWDT, then check if it is subscribed
    esp_task_wdt_init(&wdt_config);
    esp_task_wdt_add(NULL);
    
	char *tag="reset-task";
    while(1){
        //reset the watchdog every  1 second
        ESP_LOGI(tag,"Runnning...");
        esp_task_wdt_reset();  //This comment is responnsible weather wdt will be reset or not?
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}



void app_main(void)
{
	printf("Initialize TWDT\n");

	xTaskCreate(reset_task,"reset_task",2*1024,NULL,5,&task_handle);

	vTaskDelay(pdMS_TO_TICKS(10000));
	
	printf("After 10 sec delay\n");
	
	
    vTaskDelete(task_handle);
    esp_task_wdt_delete(task_handle);
    esp_task_wdt_deinit();  
   
	
	printf("reset task deleted, unsubscribed and WDT deinitialized...\n");

}





