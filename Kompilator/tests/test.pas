program example(input, output);
var x, y: integer;

function funname(a, b: integer): integer;
var lo, la: integer;

begin
la := a + 1 * 2 / (12 - 9) mod 4 div 2;
if  a > 5  then
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

program example(input, output);

var x, y: real;
var a, b: integer;

begin

a:=12.12;
b:=31.12;
x:=12.21;
y:=42.123;
write(a,b,x,y);

a:= not 0;
write(a);
a:= not 112;
write(a)

end.





