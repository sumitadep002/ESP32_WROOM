#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_log.h"
#include "driver/uart.h"
#include "string.h"
#include "driver/gpio.h"
#include "esp_intr_alloc.h"


//funciton TAGs
#define APP_MAIN_TAG "app_main"
#define UART_INIT_TAG "uart_init"
#define RX_TASK_TAG "rx_task"
char rx_buffer[1025]={};



/*
 * define gpios to be used for uart tx/rx
 */
#define UART_TX_PIN_16 GPIO_NUM_16
#define UART_RX_PIN_17 GPIO_NUM_17
#define RX_BUF_SIZE 1024

void uart_init(uart_port_t uart_number);

void uart_intr_handler(void *arg)
{
printf("Uart intrupt handler\n");
}



///static void uart_rx_task(void *arg);
void delay(int amount);
int Mills_To_Tick(int Tick_Count);

void app_main(void)
{
uart_init(UART_NUM_2);
esp_log_level_set(RX_TASK_TAG, ESP_LOG_INFO);
while(1)
	{
	int timeout = Mills_To_Tick(1000);
    int rxBytes = uart_read_bytes(UART_NUM_2, rx_buffer, RX_BUF_SIZE, timeout);
    if (rxBytes > 0) {
        rx_buffer[rxBytes] = '\0';
        ESP_LOGI(RX_TASK_TAG, "Read %d bytes: '%s'", rxBytes, rx_buffer);
    }
	}
}

void uart_init(uart_port_t uart_num)
{

uart_config_t uart_config = {
.baud_rate = 115200,
.data_bits = UART_DATA_8_BITS,
.parity = UART_PARITY_DISABLE,
.stop_bits = UART_STOP_BITS_1,
.flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
};
// Configure UART parameters
ESP_ERROR_CHECK(uart_driver_install(uart_num, RX_BUF_SIZE , 0, 0, NULL, 0));
ESP_ERROR_CHECK(uart_param_config(uart_num, &uart_config));
ESP_ERROR_CHECK(uart_set_pin(uart_num, UART_TX_PIN_16, UART_RX_PIN_17, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE));
ESP_ERROR_CHECK(uart_isr_register(uart_num,uart_intr_handler, NULL, ESP_INTR_FLAG_LEVEL1, NULL));
////ESP_ERROR_CHECK(uart_intr_config(uart_num,&uart_intr_config));
ESP_ERROR_CHECK(uart_enable_rx_intr(uart_num));
}

void delay(int delay)
{
vTaskDelay(Mills_To_Tick(delay));
}



int Mills_To_Tick(int Tick_Count)
{
return (Tick_Count / portTICK_PERIOD_MS);
}
