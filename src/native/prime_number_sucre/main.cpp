#include <math.h>
#include <stdio.h>
#include <inttypes.h>
#include <stdint.h>
#include <sys/times.h>
#include <sys/time.h>
#include <time.h>

static struct {
    struct timeval start_time;
} state_tv;

uint64_t millis()
{
    struct timeval tp;
    gettimeofday(&tp, NULL);
    uint64_t ret = 1.0e6 * ((tp.tv_sec + (tp.tv_usec * 1.0e-6)) -
                            (state_tv.start_time.tv_sec +
                             (state_tv.start_time.tv_usec * 1.0e-6)));
    return ret / 1000;
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

int main(int argc, char* const argv[])
{
    gettimeofday(&state_tv.start_time, NULL);

    printf("\nMETODO SUCRE (NATIVE)\n\n");

    uint32_t values[5] = {10, 100, 1000, 10000, 1000000};

    double time_now = millis();
    for (uint8_t i = 0; i < 5; i++) {
        int dat;
        dat = _formula_1(values[i]);
        printf("LA CANTIDAD DE PRIMOS MENORES A {%u}  ES:  {%d}\n", values[i], dat);
    }

    printf("\nProcesado en: %f segundos\n", ((double)millis() - time_now) / 1000);
}
