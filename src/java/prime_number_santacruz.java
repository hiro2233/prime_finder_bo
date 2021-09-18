
class prime_number_santacruz
{
    public static boolean is_prime(long x)
    {
        if (x < 1) {
            return false;
        }

        long top = (long)(Math.sqrt(x)) + 1;
        long i;
        for (i = 2; i < top; i++) {
            if (x % i == 0) {
                return false;
            }
        }

        return (x % i != 0);
    }

    public static long prime_scz(long nr)
    {
        long cnt = 2;

        for (long i = 5; i < nr; i++) {
            if (is_prime(i)) {
                cnt += 1;
            }
        }

        if (nr <= 3) {
            cnt = 1;
        }

        return cnt;
    }

    public static void main(String args[])
    {
        double time_init = System.currentTimeMillis();;

        System.out.println("\nSANTA CRUZ (JAVA)\n");

        long[] values = {10, 100, 1000, 10000, 10000000};

        for (int nf = 0; nf < 5; nf++) {
            long dat;
            dat = prime_scz(values[nf]);
            System.out.println("LA CANTIDAD DE PRIMOS MENORES A {" + values[nf] + "} ES: {" + dat + "}");
        }

        double time_end = System.currentTimeMillis();
        System.out.println("\nProcesado en: " + ((time_end - time_init) / 1000) +  " segundos\n\n");
    }
}
