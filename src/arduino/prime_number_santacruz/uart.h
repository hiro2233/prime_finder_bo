#pragma once

static FILE uartout = {0};
int uart_putchar (char c, FILE *stream);
void init_uart(uint32_t baud);

