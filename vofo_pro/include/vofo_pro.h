#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_log.h"
#include "esp_err.h"
#include "driver/uart.h"
#include "string.h"
#include "driver/gpio.h"


void vofo_pro_uart_init(uart_port_t uart_num, int txd_pin, int rxd_pin);
esp_err_t send_vofo_por_float_data(uart_port_t uart_num, const float *data, size_t len);

