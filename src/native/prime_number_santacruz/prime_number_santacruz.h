#pragma once

#include <math.h>
#include <stdio.h>
#include <inttypes.h>
#include <stdint.h>
#include <sys/times.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>

class CLPrime_number_scz {
public:

    void run(void);
    uint32_t prime_scz(uint32_t nr);
    bool is_prime(uint32_t x);

private:

};
