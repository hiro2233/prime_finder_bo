function is_prime(x)
{
    if (x < 1) {
        return false;
    }

    var top = parseInt(Math.sqrt(x)) + 1;
    var i;
    for (i = 2; i < top; i++) {
        if (x % i == 0) {
            return false;
        }
    }

    return (x % i != 0);
}
function prime_scz(nr)
{
    var cnt = 2;

    for (var i = 5; i < nr; i++) {
        if (is_prime(i)) {
            cnt += 1;
        }
    }

    if (nr <= 3) {
        cnt = 1;
    }

    return cnt;
}

function run()
{
    document.getElementById("headtitle").innerHTML = "METODO SANTA CRUZ (JAVASCRIPT)" + "<br/>"
    var values = [10, 100, 1000, 10000, 10000000];

    var init_time = performance.now();

    for (var i = 0; i < 5; i++) {
        var dat;
        dat = prime_scz(values[i]);
        document.getElementById("messages").innerHTML += "LA CANTIDAD DE PRIMOS MENORES A &emsp;{" + values[i] + "}&emsp; ES: &emsp;{" + dat + "}&emsp;" + "<br/>";
    }

    var end_time = performance.now();
    var time_sec = (end_time - init_time) / 1000;

    document.getElementById("messages").innerHTML += "<br/>" + "Procesado en: " +  time_sec + " segundos";
}

Concurrent.Thread.create(run);
