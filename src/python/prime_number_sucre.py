# This code was published originally from here:
# https://drive.google.com/file/d/1p2nQXw7cAWlFlbc3VRl1N0aKxTDZrCju/view


from math import ceil, floor, sqrt
import time

def Cantidad(x):
    pi_ = ceil(0.5 * floor((2 * x + (-1) ** x - 6 * c_(x) + 5) / 3))
    return int(pi_)

def prime_(x):
    if ((((x - 1) / 3 )% 2) == 0) and ((x - 1) / 3 ).is_integer():
        z = ceil((sqrt(x)-1) / 3)
        for i in range(1, z + 1):
            r = (2*(x - 1) - 6*i + (-1) ** i-1) / (6 * i + 3 - (-1) ** i)
            if r.is_integer():
                return False
        return True
    elif (((x - 2) / 3) % 2) != 0 and ((x - 2) / 3).is_integer():
        z = ceil((sqrt(x-1)-1) / 3)
        for i in range(1, z):
            r = (2*(x - 2) - 6*i + (-1) ** i+1) / (6 * i + 3 - (-1) ** i)
            if r.is_integer():
                return False
        return True
    else:
        return False

def formula_1(x):
    if (x < 5):
        pass
    count = 2
    for i in range(5, x):
        if prime_(i):
            count += 1
    return count

values = [10, 100, 1000, 10000, 10000000]

print("\nMETODO SUCRE (PYTHON)\n")

start_time = time.time()

for v in values:
    print("LA CANTIDAD DE PRIMOS MENORES A ", {v}, " ES: ", {formula_1(v)})

print("\nProcesado en: ", time.time() - start_time, " segundos\n")
