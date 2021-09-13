#pragma once

#include <math.h>
#include <stdio.h>

class CLPrime_number_scz {
public:

    void setup(void);
    void loop(void);
    uint32_t prime_scz(uint32_t nr);
    bool is_prime(uint32_t x);

private:
    bool _is_integer(double param);
    void _init_uart(uint32_t baud);
};

