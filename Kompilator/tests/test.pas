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

==============================================

program example(input, output);

var x, y: integer;

function gcd(a, b: integer): integer;

begin

if b = 0 then gcd := a

else gcd := gcd(b, a mod b) end;

begin

read(x, y);

write(gcd(x, y)) end.

=============================================