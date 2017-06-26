Nombres: Ana Karina Alvarez Ojeda, Nicolás Pérez Poblete.
Ayudante: Katherine Negrete.


Programa de automatas.

Informacion: El programa debe ser ejecutado y compilado en Windows ya que tiene comandos que linux no acepta.
Segundo, se recomienta tener una pantalla amplia para ver de mejor manera lo que muestra el programa por pantalla.


NOTA: Los archivos de ejemplo son "DFA" y "NFA", para agregarlos al programa se debe copiar el contenido de uno de estos archivos y pegarlo en el archivo " automata.txt " que es el archivo
principal del programa. CUIDAR QUE NO QUEDEN ESPACIOS DE MAS O SALTOS DE LINEA AL FINAL DEL ARCHIVO.

NOTA: El programa esta enfoncado a convertir un NFA a un DFA. ( no quiere decir que el resto no funcione ), ademas que se debe
ejecutar en windows.
NOTA: El DFA puede ser con cualquier tipo de string los estados y las transiciones, pero el NFA que se ingresa en el archivo o por pantalla deben ser numeros.
El programa acepta un NFA de maximo 10 estados: de 0 a 9 ya que la potencia de 2 elevado a 10 es inmensa.


Especificaciones:

* El programa esta diseñado para funcionar efectivamente miestras se sigan los siguientes pasos:
  1.- No ingresar numeros en ves de letras o letras en vez de numeros. El usuario debe leer bien 
      los pasos que pide el programa cuando ingresa una opcion. por falta de tiempo el programa
      no valida entradas erroneas indicando que el usuario se sale de los parametros. Siga al pie
      de la letra las instrucciones.
  2.- Si va a leer un automata desde un archivo debe estar seguro(a) de que esta bien escrito.

Ejemplo:

DFA:

2 -> Cantidad de estados.
2 -> Cantidad de strings.
a -> string del lenguaje.
b -> string del lenguaje.
0 1 / -> El 0 representa el estado inicial, el 1 el estado final, el / le indica al programa que no hay mas estados finales. podria tambien ser asi -> 0 1 2 / -> 0 estado inicial, 1 y 2 estados finales.
0 a 1 -> Estado-transicion-estado/destino.
0 b 0 -> Estado-transicion-estado/destino.
1 a 1 -> Estado-transicion-estado/destino.
1 b 1 -> Estado-transicion-estado/destino.


NFA:

Los estados deben estar ordenados por string, primero todos con a, luego todos con b y asi.


3 -> Cantidad de estados.
2 -> Cantidad de strings.
a -> string del lenguaje.
b -> string del lenguaje.
0 2 / -> El 0 representa el estado inicial, el 2 el estado final, el / le indica al programa que no hay mas estados finales
0 a [ ] -> si el estado no va a ningun otro estado con el string se denota asi.
1 a [ 1 2 ] -> si el estado va a un conjunto de estado, generalmente por las transiciones vacias, se denota asi.
2 a [ 0 1 ] 
0 b [ 1 ] -> si el estado va a un solo estado destino, tambien se denota asi.
1 b [ 0 2 ]
2 b [ ]
 
NOTA: No puede haber ningun espacio si salto de linea demas dentro del archivo de texto para que el programa funcione de manera optima.

Forma de programacion al ingresarlo.
La diferencia entre ambos automatas es que el programa solo reconoce desde el archivo, no reconoce al ingresarlo inmediatamente,
es por eso que primero si se quiere ingresar un automata, el programa pregunta que tipo, si DFA o NFA, esto solo es para guardarlo
en un archivo automata.txt, si se quiere ver el automata ingresado se debe poner la opcion leer desde un archivo, asi el programa
lo leera y mostrara un DFA normal, o un NFA primero y luego su DFA asociado siguiendo los pasos vistos en clases.
Luego de crear un DFA asociado al NFA ingresado, este es guardado en un archivo exclusivo para este automata. automata_DFA.

NOTA: El estado [ 0 1 2 2 ] es lo mismo que el estado [ 0 1 2 ], no se valido la repeticion de los numeros por falta de tiempo.


Esa fue la forma de realizar el trabajo de automatas. Hay muchas mas.