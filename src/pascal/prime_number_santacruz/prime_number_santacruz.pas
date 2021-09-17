program prime_number_santacruz;
{$mode objfpc}
uses
    sysutils, math;

function is_prime(x : LongInt) : boolean;
var
    i, top : LongInt;
begin
    if (x < 1) then
    begin
        result := false;
    end;

    top := trunc(sqrt(x)) + 1;

    for i := 2 to top do
    begin
        if (x mod i = 0) then
        begin
            result := false;
            break;
        end;
    end;

    result := ((x mod i) <> 0);
end;

function prime_scz(nr : LongInt) : LongInt;
var
    cnt, i : LongInt;
begin
    cnt := 2;

    for i := 5 to nr do
    begin
        if (is_prime(i)) then
        begin
            cnt += 1;
        end;
    end;

    if (nr <= 3) then
    begin
        cnt := 1;
    end;

    result := cnt;
end;

Var
    values : array[0..4] of LongInt;

procedure InitArray;
begin
    values[0] := 10;
    values[1] := 100;
    values[2] := 1000;
    values[3] := 10000;
    values[4] := 10000000;
end;

var
    ts : TTimeStamp;
    nf : LongInt;
    dat : LongInt;
    time_init, time_end : LongInt;

begin
    InitArray();
    ts := DateTimeToTimeStamp(Now);
        Writeln('');
        Writeln('METODO SANTA CRUZ (PASCAL)');
        Writeln('');

    time_init := ts.Time;

    for nf := 0 to 4 do
    begin
        dat := prime_scz(values[nf]);
        Writeln('LA CANTIDAD DE PRIMOS MENORES A ', values[nf], ' ES: ', dat);
    end;

    ts := DateTimeToTimeStamp(Now);
    time_end :=  ts.Time;
    Writeln('');
    Writeln('Procesado en: ' + FloatToStrF((time_end - time_init) / 1000, ffFixed, -1, -1) + ' segundos');
    Writeln('');

end.

