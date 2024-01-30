#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <esp_log.h>
#define K 1024

void Task_Handler(void *arg);
/*void Task2_Handler(void *arg);
void Task3_Handler(void *arg);
void Task4_Handler(void *arg);
void Task5_Handler(void *arg);
void Task6_Handler(void *arg);
void Task7_Handler(void *arg);*/

void app_main(void)
{
xTaskCreate(Task_Handler,"Task1",2*K,(void*)"Task1",0,NULL);
xTaskCreate(Task_Handler,"Task2",2*K,(void*)"Task2",10,NULL);
xTaskCreate(Task_Handler,"Task3",2*K,(void*)"Task3",4,NULL);
xTaskCreate(Task_Handler,"Task4",2*K,(void*)"Task4",1,NULL);
xTaskCreate(Task_Handler,"Task5",2*K,(void*)"Task5",7,NULL);
xTaskCreate(Task_Handler,"Task6",2*K,(void*)"Task6",6,NULL);
xTaskCreate(Task_Handler,"Task7",2*K,(void*)"Task7",8,NULL);
}
void Task_Handler(void *tag)
{
char *label=(char*)tag;
while(1)
{
ESP_LOGI(label,"Running...on Core %d",xPortGetCoreID());
vTaskDelay(1000/portTICK_PERIOD_MS);
}
vTaskDelete(NULL);
}
