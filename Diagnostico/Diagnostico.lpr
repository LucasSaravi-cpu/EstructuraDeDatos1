{Desarrollar un procedimiento en Pascal que desde un archivo de texto NUMEROS.TXT cargue datos en una
matriz de NxN enteros (N está en la primera línea del archivo, y en la siguiente están los NxN números).


Desarrollar un procedimiento que genere un arreglo A de registros donde cada uno posea los siguientes
campos: fila, columna y valor. En el arreglo estarán sólo los elementos de la matriz y su posición que cumplen
que: el elemento es múltiplo del que se encuentra en la columna anterior y múltiplo del que se encuentra en
la columna siguiente. (no considerar los elementos en la columna 1 ni en la columna N)
Desarrollar una función que, a partir de la matriz generada, obtenga y retorne la cantidad de elementos pares
en la diagonal secundaria.
Escribir el programa principal que invoque a los subprogramas desarrollados y que muestre el vector A. Definir
los tipos y variables que considere necesarios}


program Diagnostico;



Type
    TR = record
    fila , columna , numero:integer;
    end;

TV=array[1..10] of TR;
TM=array[1..10,1..10] of integer;





Procedure LeeMatriz(Var Mat:TM; Var N:byte);
Var
i,j: byte;
arch:text;
Begin
assign(arch,'numeros.txt');
reset(Arch);
readln(arch,N);

For i:= 1 to N do
  begin
  For J:= 1 to N do
   Begin
   read(arch,mat[i,j])
   end;
  readln(arch);
  end;
end;







procedure GeneraArreglo(mat:tm;N:byte;var A:tv ;var l:byte );
var
i,j:byte;
begin
L:=0;

    for i:=1 to  n do
     begin
     for j:=2 to  n do     //salto la primera columna ya que es lo que me pide
       begin
       if  ( mat[i,j-1] mod mat[i,j] = 0) and  ( mat[i,j+1] mod mat[i,j] = 0) and (j<n)  then
           begin
           L:=L+1;
           A[L].numero:=mat[i,j];
           A[L].fila:= i;
           A[L].columna:=j;
           end;
       end;
      end;

    end;



Procedure EscribeVector(B:TV;l:byte);
var
  i:byte;
begin
  for i:=1 to l do
      write( B[i].numero:4) ;
end;






Function CantidadDePares(mat:tm;n:byte):byte;
var
cont,i,j:byte;

begin
cont:=0;



   for i:=1 to n do

    begin



    if (mat[i,n-i+1] mod 2 =0) then
        begin
       cont:=cont+1;

        end;



    end;

CantidadDePares:=Cont;

end;


var
 A:tv;
mat:TM;
L,n:byte;


begin
  LeeMatriz (Mat,n);

  writeln('La cantida de pares en la diagonal secundaria es ' , CantidadDePares(mat,n));
  writeln;

  GeneraArreglo(mat,n,A,l);

  writeln('el vector generado es ' );
  Escribevector(A,l);

  readln;

end.

