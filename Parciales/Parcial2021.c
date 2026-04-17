/*Un condominio gestiona las reservas de sus lugares comunes (quincho, gimnasio, spa, etc.) mediante una lista simplemente enlazada, donde cada nodo representa un lugar 
común que cuenta con una sublista de reservas para el mes en curso, realizadas por los habitantes del condominio.
·    Espacio (0..19) (ordenada, no se repite)
·    Descripcion (Cadena de 20)
·    Máxima cantidad de reservas diarias
·    Sublista de reservas
      o   Código Vecino (Cadena de 4)
      o   DiaReserva (1..31, ordenada por este criterio)

Se tiene además una matriz MRes de 31x20 que contiene la cantidad actual de reservas de cada espacio (valor ≥ 0), en la posición [i,j] se encuentra la cantidad de reservas
del espacio j del día i-1.

a) Desarrollar un programa que implemente los siguientes requerimientos modularizando adecuadamente:
   i) Procesar las nuevas reservas a partir del archivo de texto RESERVAS.TXT en el que cada línea posee: día a reservar (1..31), número de espacio común (0..19), código de vecino y 
cantidad de reservas anteriores realizadas (≥ 0). Cada reserva deberá agregarse a la sublista  correspondiente, teniendo en cuenta no superar el límite de reservas del espacio y que 
no se aceptan reservas de vecinos que tengan más de X (dato) reservas anteriores realizadas además MRes.
Las reservas excluidas únicamente por no haber posibilidad de mas reservas en el espacio requerido, deberán colocarse en una Cola de reservas en suspenso (cada elemento de la cola contendrá los mismos datos que se extrajeron del archivo de texto).
Informar cuántas reservas no se aceptaron únicamente por haber sido solicitadas por vecinos que habían hecho más reservas de las aceptadas.
   ii) Determinar recorriendo de forma recursiva MRes, el espacio común de número impar (1, 3, 5, etc) que tiene la mayor cantidad de reservas para este mes.
   iii) Quitar de la lista, las reservas de la primera quincena eliminándolas de las sublistas que correspondan, manteniendo el resto de las reservas. Informar la cantidad de reservas liberadas y el lugar común que ha liberado la mayor cantidad de reservas.
   Si un lugar común quedara sin reservas, no se eliminará de la lista de lugares comunes.  Actualizar MRes.

b) Escribir el main completo que haga las invocaciones a los subprogramas definidos en a) y a las funciones de inicialización que considere necesarias pero no desarrollarlas.

c) Definir los tipos necesarios para resolver este problema y los tipos que deberían estar en el TdaCola.h (asumiendo que la cola es estática) */
