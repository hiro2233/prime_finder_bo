program prime_number_sucre;
{$mode objfpc}
uses
    sysutils, math;

function _is_integer(param : Real) : boolean;
var
    fractpart : Real;
begin
    fractpart := trunc(param);
    if (fractpart <> param) then
    begin
        result := false;
    end
    else
    begin
        result := true;
    end;
end;

function _prime(x : LongInt) : boolean;
var
    z, i : LongInt;
    r : Real;
begin
    if (((trunc((x - 1) / 3.0 ) mod 2) = 0) and _is_integer((x - 1) / 3.0 )) then
    begin
        z := ceil((sqrt(x)-1) / 3.0);
        result := true;
        for i := 1 to (z + 1) do
        begin
            r := (2*(x - 1) - 6*i + IntPower(-1, i)-1) / (6 * i + 3 - IntPower(-1, i));
            if (_is_integer(r)) then
            begin
                result := false;
                break;
            end;
        end;
    end
    else if (((trunc((x - 2) / 3.0) mod 2) <> 0) and _is_integer((x - 2) / 3.0)) then
    begin
        z := ceil((sqrt((x-1))-1) / 3.0);
        result := true;
        for i := 1 to z do
        begin
            r := (2*(x - 2) - 6*i + IntPower(-1, i) + 1) / (6 * i + 3 - IntPower(-1, i));
            if (_is_integer(r)) then
            begin
                result := false;
                break;
            end;
        end;
    end
    else begin
        result := false;
    end;
end;

function _formula_1(x : LongInt) : LongInt;
var
    count, i : LongInt;
begin
    if (x < 5) then
    begin
        result := 0;
    end;

    count := 4;

    for i := 5 to x do
    begin
        if (_prime(i)) then
        begin
            count += 1;
        end;
    end;

    result := count;
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
    i : LongInt;
    dat : LongInt;
    time_init, time_end : LongInt;

begin
    InitArray();
    ts := DateTimeToTimeStamp(Now);
        Writeln('');
        Writeln('METODO SUCRE (PASCAL)');
        Writeln('');

    time_init := ts.Time;

    for i := 0 to 4 do
    begin
        dat := _formula_1(values[i]);
        Writeln('LA CANTIDAD DE PRIMOS MENORES A ', values[i], ' ES: ', dat);
    end;

    ts := DateTimeToTimeStamp(Now);
    time_end :=  ts.Time;
    Writeln('');
    Writeln('Procesado en: ' + FloatToStrF((time_end - time_init) / 1000, ffFixed, -1, -1) + ' segundos');
    Writeln('');

end.

