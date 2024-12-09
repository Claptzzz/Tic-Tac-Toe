# Tic-Tac-Toe

README
CODIGO CREADO POR LOS INTEGRANTES:
Nicolas Antonio Rojas Bustos, 21.295.708-9, nicolas.rojas11@alumnos.ucn.cl, paralelo C2
Ramses Balthazar Quintanilla Paez, 21.620.464-6, ramses.quintanilla@alumnos.ucn.cl, paralelo C2

Algoritmo MiniMAx:
El algoritmo MiniMax es una tecnica utilizada en diferentes tipos de juegos para la implementación de inteligencia artificial.
Este algoritmo busca explorar los diferentes movimientos disponibles en una partida, uno que le suma puntaje al primer jugador (+1 max),
y otro que minimiza el puntaje al primer jugador (-1 min) por lo tanto el primer jugador busca maximizar su puntaje mientras que el segundo jugador
busca reducirlo, de esta manera ganando el que haya cumplido mejor su objetivo (o empate en tal de ser el caso). Este algoritmo funciona a base de un arbol
que genera y muestra todas las posibles jugadas donde a cada una se le asigna un puntaje (puntaje mencionado anteriormente), por lo tanto cada hoja queda con un puntaje
asignado.

Poda Alfa-Beta:
La poda alfa-beta es una mejora al algortimo de minimax ya que, busca reducir significativamente la cantidad de nodos explorados. Como bien sabemos
el algoritmo MiniMax busca explorar y encontrar el puntaje mayor y menor, lo que hace la poda es guardar dos varibales alfa (el puntaje mayor) y beta
(el puntaje menor), gracias a esto puede ir comparando los valores de los nodos siguientes, y si encuentra alguno que tenga los valores entre esos dos 
(osea sin conseguir un nuevo puntaje mayor o menor) deja de recorrerlos (ya que no afectan en la deicision final) para asi minimizar su busqueda y aumentra su eficiencia.

              (Inicio)
            /    |      \ 
           /     |       \
          /      |        \
         /       |         \
       X1        X2        X3
      / | \     / | \     /|\
     /  |  \   /  |  \   / | \
    O1  O2 O3 O1 O2 O3 O1 O2 O3
   /|\ /|\ /|\ /|\ /|\ /|\ /|\ /|\
  . . . . . . . . . . . . . . . . .
