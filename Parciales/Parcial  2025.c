/*Un evento de Café y Música (COFMUS) a desarrollarse en MdP está gestionando los espacios y alquileres mediante una lista doblemente enlazada con el siguiente diseño:
• IdEspacio (ANU10, ordenado, no se repite)
• Superficie (en M2, desde 100 aproximadamente disponibles)
• Techado (S/N, si tiene techo)
• Escenario (S/N, tiene escenario para músicos?)
• ValorM2 ($/m2, si tiene techo, el valor se incrementa en un 20%)
• Sublista de empresas que ya han contratado:
  ? CodigoEmp (ANU10, puede repetirse)
  ? SuperficieContratada (en M2)

En un archivo de texto PEDIDOS.DAT se encuentran los pedidos pendientes de análisis para el evento, en cada elemento se tiene CodigoEmp, M2MIN, M2MAX, RequiereTecho (S/N), RequiereEscenario (S/N)

A) Desarrollar en C subprogramas (utilizando el TDA Pila y TDA Cola cuando corresponda) para:

i) Procesar el archivo analizando los espacios de L y, si hubiera algún espacio disponible (*) se irán asignando los pedidos solicitados y el resto de los requerimientos del pedido sean satisfechos almacenándolos en una pila con la leyenda “Sin espacio”. Se deberán procesar todos los pedidos del archivo y generar el archivo C con los siguientes datos: CodigoEmp, SuperficieSolicitada, RequiereTecho y/o Escenario (S/N).

(*) El pedido deberá insertarse en la sublista contratando la máxima cantidad posible de m2 respecto de los solicitados.

ii) Por el éxito del evento se han contratado 2 galpones techados (el 1 tiene escenario y el 2 no). Se han subdividido en parcelas las mismas se han almacenado en una pila P con la siguiente información: IdEspacio (no ordenado, no se repite), Galpón (1 o 2), Superficie. El costo del metro cuadrado es T y se encuentra definido como constante en la librería costos.h. Se pide: procesar P de forma recursiva insertando los nuevos espacios en L solo si las parcelas tienen al menos N m2 (K dato). P puede perderse.

iii) Se anuncia tormenta para el día del evento y los espacios no techados con escenario se deben dar de baja de L, mostrar el valor de alquiler que se perderá por estas bajas en cada espacio.

B) [RESOLVER EN EL REVERSO DE ESTA HOJA] Definir el tipo de la cola suponiéndola estática e indicar en qué archivo estaría esa definición. Definir el tipo de la pila suponiéndola dinámica e indicar en qué archivo estaría esa definición. Escribir el main.c completo con las invocaciones, declaraciones, definiciones, inicializaciones, etc. Pero no escribir el código para la carga inicial de L y ni de PEDIDOS.DAT ni de P.*/