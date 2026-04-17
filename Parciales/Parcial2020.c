/*Una empresa de reparto de encomiendas almacena en una lista doblemente enlazada LDP los
paquetes pendientes de distribución. Cada elemento de la lista posee: nombre de zona (cadena de 2),
código de paquete (entero), destinatario (cadena de 50), alto (en cm), largo (en cm) y peso (real, en
kgs).
Los docks de carga están representados en una lista simplemente enlazada LSD, cada nodo tiene un
id de dock (ordenado ascendente, cadena de 5), nombre de la zona (las zonas no se repiten), espacio
total (en m2

) y una pila con paquetes con la siguiente información en cada elemento: código de

paquete, peso (en kg), destinatario.
Se pide
a) definir los tipos de la pila (estática) y de las listas
b) utilizando los operadores del TDA Pila, mediante un subprograma por cada ítem resolver:
i) Dadas las lista LDP y LSD, localice un paquete en LDP pendiente de reparto y cárguelo en la lista,
para cargar el paquete debe verificarse no sólo la zona, sino que el dock tenga espacio disponible
considerando los paquetes ya cargados. El paquete irá a la última posición de la pila
correspondiente sin cambiar el orden de los que ya estaban y será retirado de LDP.
ii) A partir de la lista LSD, eliminar el paquete codP que se sabe podría estar en las zonas Z1 o Z2 o
en ninguna. Hallar e informar el peso promedio de los paquetes que permanecieron en el dock de
la zona en la que estaba codP (codP, Z1 y Z2 son datos solicitados al operador).
c) escribir el main con únicamente las invocaciones a los subprogramas definidos en b). */
