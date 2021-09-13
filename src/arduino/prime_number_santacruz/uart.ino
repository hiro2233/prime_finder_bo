
#include "uart.h"

int uart_putchar (char c, FILE *stream)
{
    Serial.write(c) ;
    return 0 ;
}

