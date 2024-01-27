#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_log.h"
#include "driver/uart.h"
#include "string.h"
#include "driver/gpio.h"

/*
 * define gpios to be used for uart tx/rx
 */
#define UART_TX_PIN_16 GPIO_NUM_16
#define UART_RX_PIN_17 GPIO_NUM_17

#define RX_BUF_SIZE 1024

//Note: Do not select UART_NUM_0 because it is connected wth default UART bridge
#define UART_DEVICE UART_NUM_2

void uart2_init();
int uart_send(const char* logName, const char* data);
static void uart_send_task(void *arg);

void delay(uint16_t delay);


void app_main(void)
{
printf("Configuring the uart2, TX=GPIO_16 and RX=GPIO_17, baudrate=115200\n");
uart2_init();



printf("Creating send task....\n");
xTaskCreate(uart_send_task,"uart_tx_task",1024*2,NULL, configMAX_PRIORITIES - 2, NULL);

}



void uart2_init()
{
const int uart_num = UART_DEVICE;
uart_config_t uart_config = {
.baud_rate = 115200,
.data_bits = UART_DATA_8_BITS,
.parity = UART_PARITY_DISABLE,
.stop_bits = UART_STOP_BITS_1,
.flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
};
// Configure UART parameters
ESP_ERROR_CHECK(uart_driver_install(UART_DEVICE, RX_BUF_SIZE , 0, 0, NULL, 0));
ESP_ERROR_CHECK(uart_param_config(uart_num, &uart_config));
ESP_ERROR_CHECK(uart_set_pin(UART_DEVICE, UART_TX_PIN_16, UART_RX_PIN_17, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE));
}


void delay(uint16_t delay)
{
vTaskDelay(delay / portTICK_PERIOD_MS);
}

int uart_send(const char* logName, const char* data)
{
    const int len = strlen(data);
    const int txBytes = uart_write_bytes(UART_DEVICE, data, len);
    ESP_LOGI(logName, "Wrote %d bytes", txBytes);
    return txBytes;
}

void uart_send_task(void *arg)
{
    static const char *TX_TASK_TAG = "TX_TASK";
    esp_log_level_set(TX_TASK_TAG, ESP_LOG_INFO);
    while (1) {
        uart_send(TX_TASK_TAG, "Hello world\r\n");
        delay(1000);
    }
}
