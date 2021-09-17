function _prime(x)
{
    if (((((x - 1) / 3.0 ) % 2) == 0) && Number.isInteger((x - 1) / 3.0 )) {
        var z = Math.ceil((Math.sqrt(x)-1) / 3.0);
        for (var i = 1; i < (z + 1); i++) {
            var r = (2*(x - 1) - 6*i + Math.pow(-1, i)-1) / (6 * i + 3 - Math.pow(-1, i));
            if (Number.isInteger(r)) {
                return false;
            }
        }
        return true;
    } else if (((((x - 2) / 3.0) % 2) != 0) && Number.isInteger((x - 2) / 3.0)) {
        var z = Math.ceil((Math.sqrt((x-1))-1) / 3.0);
        for (var i = 1; i < z; i++) {
            var r = (2*(x - 2) - 6*i + Math.pow(-1, i) + 1) / (6 * i + 3 - Math.pow(-1, i));
            if (Number.isInteger(r)) {
                return false;
            }
        }
        return true;
    } else {
        return false;
    }
}

function _formula_1(x)
{
    if (x < 5) {
        return 0;
    }

    var count = 2;

    for (var i = 5; i < x; i++) {
        if (_prime(i)) {
            count += 1;
        }
    }

    return count;
}

function run()
{
    document.getElementById("headtitle").innerHTML = "METODO SUCRE (JAVASCRIPT)" + "<br/>"
    var values = [10, 100, 1000, 10000, 10000000];

    var init_time = performance.now();

    for (var i = 0; i < 5; i++) {
        var dat;
        dat = _formula_1(values[i]);
        document.getElementById("messages").innerHTML += "LA CANTIDAD DE PRIMOS MENORES A &emsp;{" + values[i] + "}&emsp; ES: &emsp;{" + dat + "}&emsp;" + "<br/>";
    }

    var end_time = performance.now();
    var time_sec = (end_time - init_time) / 1000;

    document.getElementById("messages").innerHTML += "<br/>" + "Procesado en: " +  time_sec + " segundos";
}

Concurrent.Thread.create(run);
