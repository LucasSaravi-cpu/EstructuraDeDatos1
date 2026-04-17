/*Durante el último Censo se recorrieron las viviendas para registrar datos de los habitantes del Municipio de
Gral Pueyrredón. Cada vivienda está identificada de manera unívoca por su Nomenclatura Catastral y, a su vez,
el municipio se encuentra dividido en 120 zonas.
Se cuenta entonces con la información del censo del 2022 en un archivo de texto y del anterior (2010) en una
lista simplemente enlazada con la siguiente estructura:

• Zona (1..120) (ordenada, no se repite)
• Descripción (Cadena de 20)
• Sublista de viviendas censadas
  ○ Nomenclatura Catastral (cadena de 20)
  ○ Cant de Habitantes
  ○ Censo Electrónico (S/N) (todos tienen N pues en 2010 no había censo electrónico)

a) Desarrollar los siguientes requerimientos modularizando adecuadamente:

(4p) I) Procesar los datos del nuevo censo a partir del archivo de texto CENSO2022.TXT (ordenado por
Zona) en el que cada línea posee información de las viviendas a censar: Zona (1..120), código de censo
(Cadena de 6), Nomenclatura Catastral (Cadena de 20), Cantidad de Habitantes (contiene 0 si no pudo
censarse), Censo Electrónico (1 o 0). Cada vivienda censada debería si hubiera correspondido
teniendo en cuenta que: si la vivienda no había sido censada en 2010 deberá agregarse colocando los datos
correspondientes, en cambio si ya se hubiera censado debería actualizarse los datos de habitantes y censo
electrónico, si correspondiese. Si aparecieran zonas que no están en la lista de 2010, dichas viviendas no se
colocarán en la lista simple, sino que se colocarán en una Pila que contendrá en cada elemento: Zona,
Nomenclatura Catastral y Cantidad de Habitantes.

Durante la actualización de la lista se deberá generar un arreglo de 120 elementos (V[k-1] corresponde a
Zona k) que en cada posición contenga: cantidad de viviendas censadas electrónicamente y cantidad de
viviendas que no existían en 2010 (considerar acá incluso las que se volcaron a la Pila).

(2,5p) II) A partir del vector generado en a) I) hallar mediante un único recorrido recursivo la cantidad de
zonas que no poseen nuevas viviendas en 2022 y la cantidad total de viviendas censadas electrónicamente en
todas las zonas que terminan en 0 (10, 20, etc)

(2p) III) Se ha detectado un error en la vivienda NC de la zona Z, si la misma se encuentra en la lista,
eliminarla e informar cuántos habitantes tenía cargados, sino informar que no se ha encontrado. (NC y Z datos
de entrada)

(1p) b) escribir el main.c completa que haga las invocaciones a los subprogramas definidos en a) además de las
operaciones de inicialización de estructuras necesarias, invocación a funciones de carga de las mismas (que
no se desarrollan)

(0,5p) c) definir el tipo de la pila estática utilizada en la solución */
