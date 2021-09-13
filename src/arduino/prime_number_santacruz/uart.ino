
#include "uart.h"

int uart_putchar(char c, FILE *stream)
{
    Serial.write(c) ;
    return 0 ;
}

void init_uart(uint32_t baud)
{
    Serial.begin(baud);
    fdev_setup_stream (&uartout, uart_putchar, NULL, _FDEV_SETUP_WRITE);
    stdout = &uartout ;
}

