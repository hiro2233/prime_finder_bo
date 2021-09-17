#include <math.h>
#include <stdio.h>

static FILE uartout = {0} ;

static int uart_putchar(char c, FILE *stream)
{
    Serial.write(c) ;
    return 0 ;
}

bool _is_integer(double param)
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

bool _prime(uint32_t x)
{
    if ((((uint32_t)((x - 1) / 3.0f ) % 2) == 0) && _is_integer((x - 1) / 3.0f )) {
        uint32_t z = ceil((sqrt(x)-1) / 3.0f);
        for (uint32_t i = 1; i < (z + 1); i++) {
            double r = (2*(x - 1) - 6*i + pow(-1, i)-1) / (6 * i + 3 - pow(-1, i));
            if (_is_integer(r)) {
                return false;
            }
        }
        return true;
    } else if ((((uint32_t)((x - 2) / 3.0f) % 2) != 0) && _is_integer((x - 2) / 3.0f)) {
        uint32_t z = ceil((sqrt((x-1))-1) / 3.0f);
        for (uint32_t i = 1; i < z; i++) {
            double r = (2*(x - 2) - 6*i + pow(-1, i) + 1) / (6 * i + 3 - pow(-1, i));
            if (_is_integer(r)) {
                return false;
            }
        }
        return true;
    } else {
        return false;
    }
}

uint32_t _formula_1(uint32_t x)
{
    if (x < 5) {
        return 0;
    }

    uint32_t count = 2;

    for (uint32_t i = 5; i < x; i++) {
        if (_prime(i)) {
            count += 1;
        }
    }

    return count;
}

void setup(void)
{
    Serial.begin(115200);

    fdev_setup_stream (&uartout, uart_putchar, NULL, _FDEV_SETUP_WRITE);
    stdout = &uartout ;

    printf("\nMETODO SUCRE (ARDUINO)\n\n");

    uint32_t values[5] = {10, 100, 1000, 10000, 100000};

    uint32_t time_now = millis();
    for (uint8_t i = 0; i < 5; i++) {
        int dat;
        dat = _formula_1(values[i]);
        printf("LA CANTIDAD DE PRIMOS MENORES A {%lu}  ES:  {%d}\n", values[i], dat);
    }

    printf("\nProcesado en: %d segundos\n", (millis() - time_now) / 1000);
}

void loop(void)
{
    delay(1000);
}

