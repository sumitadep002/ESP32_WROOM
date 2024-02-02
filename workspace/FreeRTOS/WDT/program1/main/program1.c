#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <esp_log.h>

static void Task_Handler(void *arg)
{
char *tag="Task-Loop";
while(1)
{
ESP_LOGI(tag,"Running...");
}
}


void app_main(void)
{
xTaskCreate(Task_Handler,"Task-loop",2*1024,NULL,5,NULL);
}
