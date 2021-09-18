
class prime_number_sucre
{
    public static boolean _is_integer(double param)
    {
        double fractpart;
        double intpart;

        fractpart = (double)(long)(param);
        if (fractpart != param) {
            return false;
        } else {
            return true;
        }
    }

    public static boolean _prime(long x)
    {
        if ((((long)((x - 1) / 3.0f ) % 2) == 0) && _is_integer((x - 1) / 3.0f )) {
            long z = (long)Math.ceil((Math.sqrt(x)-1) / 3.0f);
            for (long i = 1; i < (z + 1); i++) {
                double r = (2*(x - 1) - 6*i + Math.pow(-1, i)-1) / (6 * i + 3 - Math.pow(-1, i));
                if (_is_integer(r)) {
                    return false;
                }
            }
            return true;
        } else if ((((long)((x - 2) / 3.0f) % 2) != 0) && _is_integer((x - 2) / 3.0f)) {
            long z = (long)Math.ceil((Math.sqrt((x-1))-1) / 3.0f);
            for (long i = 1; i < z; i++) {
                double r = (2*(x - 2) - 6*i + Math.pow(-1, i) + 1) / (6 * i + 3 - Math.pow(-1, i));
                if (_is_integer(r)) {
                    return false;
                }
            }
            return true;
        } else {
            return false;
        }
    }

    public static long _formula_1(long x)
    {
        if (x < 5) {
            return 0;
        }

        long count = 2;

        for (long i = 5; i < x; i++) {
            if (_prime(i)) {
                count += 1;
            }
        }

        return count;
    }

    public static void main(String args[])
    {
        double time_init = System.currentTimeMillis();;

        System.out.println("\nMETODO SUCRE (JAVA)\n");

        long[] values = {10, 100, 1000, 10000, 10000000};

        for (int i = 0; i < 5; i++) {
            long dat;
            dat = _formula_1(values[i]);
            System.out.println("LA CANTIDAD DE PRIMOS MENORES A {" + values[i] + "} ES: {" + dat + "}");
        }

        double time_end = System.currentTimeMillis();
        System.out.println("\nProcesado en: " + ((time_end - time_init) / 1000) +  " segundos\n\n");
    }
}
