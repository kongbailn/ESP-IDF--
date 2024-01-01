#include <stdio.h>
#include "vofo_pro.h"

static const unsigned char tail[4] = {0x00, 0x00, 0x80, 0x7f};

void vofo_pro_uart_init(uart_port_t uart_num, int txd_pin, int rxd_pin)
{
    const uart_config_t uart_config = {
        .baud_rate = 115200,
        .data_bits = UART_DATA_8_BITS,
        .parity = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
        .source_clk = UART_SCLK_DEFAULT,
    };
    // We won't use a buffer for sending data.
    uart_driver_install(uart_num, 1024 * 2, 0, 0, NULL, 0);
    uart_param_config(uart_num, &uart_config);
    ESP_ERROR_CHECK(uart_set_pin(uart_num, txd_pin, rxd_pin, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE));
}
esp_err_t send_vofo_por_float_data(uart_port_t uart_num, const float *data, size_t len)
{
    uart_write_bytes(uart_num, (const void *)data, len * 4);
    uart_write_bytes(uart_num, (void *)tail, 4);
    return ESP_OK;
}
