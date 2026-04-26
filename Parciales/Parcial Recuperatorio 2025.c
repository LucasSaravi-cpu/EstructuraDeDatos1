/*Un sistema de una empresa de transporte lleva las reparaciones a realizar de su flota en una lista simplemente enlazada, LV (con la siguiente estructura:
• IdVehiculo (1..150, no se repite)
• Tipo (1.5, 1 utilitario, 2 Traffic, 3 Camioneta, 4 Camion, 5 Camion c/acoplado)
• CostoManoDeObra (numérico)
• Sublista de repuestos
  ? CodigoRepuesto (ANU de 10, no se repite)
  ? Cantidad (entero)

En una lista circular LCS, tiene el stock de repuestos, con la siguiente estructura:
• CodigoRepuesto (ANU de 10, no se repite)
• Costo (numérico)
• Cantidad (entero)

A) Desarrollar en lenguaje C subprogramas (utilizando el TDA Cola cuando corresponda) para cada vehículo que haya stock de repuestos para repararlo:
i) Eliminarlo de LV, actualizar la cantidad de LCS y generar una cola C con el siguiente registro:
  IdVehiculo, CostoTotalReparacion.

ii) Generar archivo binario REPARACIONES.DAT con la siguiente estructura: IdVehiculo, CostoManoObra, CodigoRepuesto, CostoRepuesto, Cantidad

iii) Mostrar el siguiente listado:

LISTA DE REPARACIONES POSIBLES

ID VEHICULO  COSTO DE REPUESTOS  COSTO DE MANO  VEHICULO TIPO
999     $999999.99      $999999.99     Utilitario
999     $999999.99      $999999.99     Utilitario

CANT REPARACIONES POSIBLES: 9999
COSTO TOTAL DE REPUESTOS: $999999.99
COSTO TOTAL DE MANO DE OBRA: $999999.99
VEHICULOS QUE NO SE REPARAN: 999

iv) Generar una matriz A de 150 x 5 (IdVehiculo x Tipo) con el importe total de reparación.

v) A partir de la matriz, verificar si existe un tipo de vehículo que no tenga ninguno en reparación posible. [Debe resolverse mediante un único recorrido recursivo. El uso de ciclos en este inciso, lo anulará]

B) (RESOLVER EN EL REVERSO DE ESTA HOJA) Definir el tipo de la lista suponiéndola dinámica e indicar en qué archivos estaría ese diseño. Escribir el main.c completo con las invocaciones, declaraciones, definiciones, inicializaciones, etc. Pero no escribir el código para la carga inicial de LV ni de LCS.*/