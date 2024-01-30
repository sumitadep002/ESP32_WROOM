#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/event_groups.h>
#include <string.h>
#include <esp_log.h>


#define K 1024

#define BIT_0 (1<<0)
#define BIT_1 (1<<1)
#define BIT_2 (1<<2)



#define TASK0_Bits BIT_0
#define TASK1_Bits BIT_1
#define TASK2_Bits BIT_2

static void Task0_Handler(void *arg);
static void Task1_Handler(void *arg);
static void Task2_Handler(void *arg);
static void Event_Handler(void *arg);

//can store upto  8 to 24 depending whether configUSE_16_BIT_TICKS is set to 1 or 0 respectively
EventGroupHandle_t event_group;
void create_event(void);

void app_main(void)
{
create_event();
xTaskCreate(Task0_Handler,"Task0", 2*K, NULL, 5, NULL);
xTaskCreate(Task1_Handler,"Task1", 2*K, NULL, 6, NULL);
xTaskCreate(Task2_Handler,"Task2", 2*K, NULL, 7, NULL);
xTaskCreate(Event_Handler,"Task_Event", 2*K, NULL, 2, NULL);
while(1)
{
printf("Everything is done\n");
vTaskDelay(1000/portTICK_PERIOD_MS);
}

}

void create_event()
{
 event_group= xEventGroupCreate();
 if(event_group == NULL)
 {
 while(1)
 {
 printf("event group not created\n");
 vTaskDelay(1000 / portTICK_PERIOD_MS);
 }
 }
 else
 printf("event group created succefully\n");
}



void Task0_Handler(void *arg)
{
char *tag="TASK0";
vTaskDelay(10000/portTICK_PERIOD_MS);
ESP_LOGI(tag,"Running...");
ESP_LOGI(tag,"Setting Event bits");
xEventGroupSetBits(event_group,TASK0_Bits);
vTaskDelete(NULL);
}
void Task1_Handler(void *arg)
{
char *tag="TASK1";
vTaskDelay(5000/portTICK_PERIOD_MS);
ESP_LOGI(tag,"Running...");
ESP_LOGI(tag,"Setting Event bits");
xEventGroupSetBits(event_group,TASK1_Bits);
vTaskDelete(NULL);
}
void Task2_Handler(void *arg)
{
char *tag="TASK2";
vTaskDelay(10000/portTICK_PERIOD_MS);
ESP_LOGI(tag,"Running...");
ESP_LOGI(tag,"Setting Event bits");
xEventGroupSetBits(event_group,TASK2_Bits);
vTaskDelete(NULL);
}
void Event_Handler()
{
EventBits_t Event_Bits;
Event_Bits=xEventGroupWaitBits(event_group,TASK0_Bits | TASK1_Bits | TASK2_Bits, pdTRUE, pdTRUE, portMAX_DELAY);
if((Event_Bits & (TASK0_Bits | TASK2_Bits | TASK1_Bits)) == (TASK1_Bits | TASK2_Bits | TASK0_Bits))
ESP_LOGI("TASK_EVENT","Task 0 to 2 are executed succefully");
ESP_LOGI("TASK_EVENT","Deleting Event_Task");
vTaskDelete(NULL);
}
