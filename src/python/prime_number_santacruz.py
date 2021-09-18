# **************************************************************
# * Name:      prime_number_santacruz.py
# * Purpose:   Prime number finder and generator.
# * Author:    Hiroshi Takey F. (hiro2233) <htakey@gmail.com>
# * Created:   2021-09-13
# **************************************************************

from math import ceil, floor, sqrt

import time

def is_prime(x):
    if(x < 1):
        return False
    top = int(sqrt(x)) + 1
    i = 0
    for i in range(2, top):
        if (x % i == 0):
            return False
    return (x % i != 0)

def prime_scz(nr):
    cnt = 2
    for i in range(5, nr):
        if is_prime(i):
            cnt += 1
    if (nr <= 3):
        cnt = 1
    return cnt

numbers_to_find = [10, 100, 1000, 10000, 10000000]

print("\nMETODO SANTA CRUZ (PYTHON)\n")

init_time = time.time()

for nf in numbers_to_find:
    print("LA CANTIDAD DE PRIMOS MENORES A ", {nf}, " ES: ", {prime_scz(nf)})

print("\nProcesado en: ", time.time() - init_time, " segundos\n")
