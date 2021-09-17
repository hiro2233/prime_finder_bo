/***************************************************************
  * Purpose:   Prime number finder and generator.
  * Author:    Hiroshi Takey F. (hiro2233) <htakey@gmail.com>
  * Created:   2021-09-13
  **************************************************************/

#include "prime_number_santacruz.h"
#include "uart.h"

static CLPrime_number_scz prime_number_scz;

void CLPrime_number_scz::_init_uart(uint32_t baud)
{
    init_uart(baud);
}

bool CLPrime_number_scz::_is_integer(double param)
{
    double fractpart;
    double intpart;

    fractpart = modf(param , &intpart);
    if (fractpart > 0.0f) {
        return false;
    } else {
        return true;
    }
}

bool CLPrime_number_scz::is_prime(uint32_t x)
{
    if (x < 1) {
        return false;
    }

    uint32_t top = int(sqrt(x)) + 1;
    uint32_t i;
    for (i = 2; i < top; i++) {
        if (x % i == 0) {
            return false;
        }
    }

    return (x % i != 0);
}

uint32_t CLPrime_number_scz::prime_scz(uint32_t nr)
{
    uint32_t cnt = 2;

    for (uint32_t i = 5; i < nr; i++) {
        if (is_prime(i)) {
            cnt += 1;
        }
    }

    if (nr <= 3) {
        cnt = 1;
    }

    return cnt;
}

void CLPrime_number_scz::setup(void)
{
    _init_uart(115200);
 
    printf("\nMETODO SANTA CRUZ (ARDUINO)\n\n");

    uint32_t values[5] = {10, 100, 1000, 10000, 100000};

    uint32_t time_now = millis();
    for (uint8_t nf = 0; nf < 5; nf++) {
        int dat;
        dat = prime_scz(values[nf]);
        printf("LA CANTIDAD DE PRIMOS MENORES A {%lu}  ES:  {%d}\n", values[nf], dat);
    }

    printf("\nProcesado en: %d segundos\n", (millis() - time_now) / 1000);
}

void CLPrime_number_scz::loop(void)
{
    delay(1000);
}

void setup(void);
void loop(void);

void setup(void)
{
    prime_number_scz.setup();
}

void loop(void)
{
    prime_number_scz.loop();
}

