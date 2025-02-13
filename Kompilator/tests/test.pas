program example(input, output);
var x, y: integer;

function funname(a, b: integer): integer;
var lo, la: integer;

begin
la := a+1;
if a > 5 then
    b := 2
else
    la := funname(a+2, b+2);

funname := la
end;

begin
read(x, y);
y := funname(x, 12);
write(y) 
end.

