#include <iostream>
#include "clases .h/tablero.h"

using namespace std;

void mostrarTablero() {
    cout << "-------------\n";
    for (int i = 0; i < 3; i++) {
        cout << "| ";
        for (int j = 0; j < 3; j++) {
            cout << tablero[i][j] << " | ";
            }
        cout << "\n-------------\n";
        }
}

bool verificador(int lugar) {
    int fil = (lugar - 1) / 3;
    int col = (lugar - 1) % 3;
    if (tablero[fil][col] != 'X' && tablero[fil][col] != 'O') {
        tablero[fil][col] = marcadorActual;
        return true;
    }
    return false;
}

int revisarEstado() {
    // filas
    for (int i = 0; i < 3; i++) {
        if (tablero[i][0] == tablero[i][1] && tablero[i][1] == tablero[i][2]) return jugadorActual;
    }
    // columnas
    for (int i = 0; i < 3; i++) {
        if (tablero[0][i] == tablero[1][i] && tablero[1][i] == tablero[2][i]) return jugadorActual;
    }
    // cruzados
    if (tablero[0][0] == tablero[1][1] && tablero[1][1] == tablero[2][2]) return jugadorActual;
    if (tablero[0][2] == tablero[1][1] && tablero[1][1] == tablero[2][0]) return jugadorActual;

    return 0;
}

void cambioTurno() {
    if (marcadorActual == 'X') {marcadorActual = 'O';}
    else {marcadorActual = 'X';}

    if (jugadorActual == 1) {jugadorActual = 2;}
    else {jugadorActual = 1;}
}

void ejecucionJuego() {
    char marcadorUno = 'X';
    jugadorActual = 1;
    marcadorActual = marcadorUno;
    int ganador;

    mostrarTablero();


    for (int i = 0; i < 9; i++) {
        cout << "Turno del jugador " << jugadorActual << ", marca tu posicion: ";
        int lugar;
        cin >> lugar;

        if (lugar < 1 || lugar > 9) {
            cout << "Lugar invalido, reingrese\n";
            i--;
        }

        if (!verificador(lugar)) {
            cout << "Lugar invalido, reingrese\n";
            i--;
        }

        mostrarTablero();

        ganador = revisarEstado();

        if (ganador == 1) {
            cout << "Gana jugador 1.\n";
            break;
        }
        if (ganador == 2) {
            cout << "Gana jugador 2. \n";
            break;
        }

        cambioTurno();
    }

    if (ganador == 0) {
        cout << "Es un empate.\n";
    }


}

int main() {

    bool ciclo = true;
    int opcion;
    char marcadorActual;
    char jugadorActual;
    tablero* tablero = new tablero;
    tablero->crearTablero();
    while (ciclo) {
        cout<<"------------------------\nSeleccione modo a jugar\n------------------------"<<endl;
        cout<<"------------------------\n1.- Jugador vs Jugador.\n2.- Jugador vs IA.\n3.- Jugador vs IA Poda Alfa-Beta.\n4.- Salir.\n------------------------"<<endl;
        cin>>opcion;
        switch (opcion) {
            case 1:
                ejecucionJuego();
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                ciclo = false;
                break;
        }
    }


    return 0;
}