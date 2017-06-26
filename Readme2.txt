Nombres: Ana Karina Alvarez Ojeda, Nicolás Pérez Poblete.
Ayudante: Katherine Negrete.


Programa de automatas.

Informacion: El programa debe ser ejecutado y compilado en Windows ya que tiene comandos que linux no acepta.
Segundo, se recomienta tener una pantalla amplia para ver de mejor manera lo que muestra el programa por pantalla.


Se le agregaron 3 opciones al programa realizado anteriormente:

* El programa puede leer una gramatica desde un archivo de texto de la siguiente forma:

2 -> Cantidad de Letras "mayusculas" que representan el estado inicial y los otros, el programa les llama gramaticas.
2 -> Cantidad de terminales de la gramatica.
S T -> Las "gramaticas" en orden segun la linea en que se encuentran.
a b -> Terminales especificos.
S - a T b | b /    -> Aqui se ve que al final de la linea se denota con un "/", esto es para saber el final de ésta.
T - T a | E /      -> Mismo caso para esto.

Los ejemplos de las gramaticas dentro de archivos de texto son ejemplo1.txt y ejemplo2.txt, sacados del libro.

* El programa recibe manualmente una gramatica que ingrese el usuario:

Primero se pide el nombre donde se desea guardar la gramatica, luego se puede abrir el mismo archivo con la opcion de cargar
gramatica desde un archivo de texto y el programa lo transformara a un automata de pila.

pasos para ingresar la gramatica: (ejemplo)

(1) Pide numero de "Gramaticas", en este caso 1.
(2) Pide numero de Terminales, en este caso 2.
(3) Pide la o las "gramaticas" especificas, en este caso como solo hay una es "S"
(4) Pide las terminales especificas, en este caso seran 0 y 1
(5) Pide ahora la secuencia de la gramatica, hay que ingresarlas una por una en cada linea:

S - 0 S 1 | E  -> en este orden, el S y luego el guion siempre deben ir.
Para finalizar el ingreso de una linea, se debe ingresar un "/" para denotar el final de la linea:
S - 0 S 1 | E /

Finalmente en el archivo de texto quedara asi:


1
2
S
0 1
S - 0 S 1 | E /


* Tercer y ultima funcion es leer un automata de pila dentro de un archivo de texto:

Al momento que el usuario lee una gramatica desde un archivo X, el programa le pide inmediatamente un
nombre para el nuevo archivo que se creará y será dode se escribirá el Automata de pila.

Ejemplo de guardado de un automata de pila:

(qStart) --- [E,E -> $] ---> ( 0 ) ---- [E,E ->0] ---> (qLoop) |
(qLoop) --- [1,1 -> E] ---> (qLoop) |
(qLoop) --- [S,S -> E] ---> (qLoop) |
(qLoop) --- [E,0 -> E] ---> (qLoop) |
(qLoop) --- [E,0 -> 1] ---> ( 1 ) |
( 1 ) --- [E,E -> S] ---> ( 2 ) |
( 2 ) --- [E,E -> 0] ---> (qLoop) |
(qLoop) --- [E,$ -> E] ---> (Qacept) |