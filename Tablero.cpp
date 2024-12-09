#include <iostream>
#include "clases/Tablero.h"
#include <vector>

using namespace std;

vector<vector<char>> Tablero::crearTablero() {
    vector<vector<char>> tablero(3, vector<char>(3));
    int aux = 0;
    char numeros[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    for (int i=0;i<3;i++) {
        for(int a=0;a<3;a++) {
            tablero[i][a] = numeros[aux];
            aux++;
        }
    }
    return tablero;
}

void Tablero::mostrarTablero(vector<vector<char>> tablero) {
    cout << "-------------\n";
    for (int i = 0; i < 3; i++) {
        cout << "| ";
        for (int j = 0; j < 3; j++) {
            cout << tablero[i][j] << " | ";
            }
        cout << "\n-------------\n";
        }
}

bool Tablero::verificador(int lugar, vector<vector<char>> tablero, char marcadorActual) {
    int fil = (lugar - 1) / 3;
    int col = (lugar - 1) % 3;
    if (tablero[fil][col] != 'X' && tablero[fil][col] != 'O') {
        return true;
    }
    return false;
}

vector<vector<char>> Tablero::Marcador(int lugar, vector<vector<char>> tablero, char marcadorActual) {
    int fil = (lugar - 1) / 3;
    int col = (lugar - 1) % 3;
    if (tablero[fil][col] != 'X' && tablero[fil][col] != 'O') {
        tablero[fil][col] = marcadorActual;
        return tablero;
    }
    return tablero;
}

int Tablero::revisarEstado(vector<vector<char>> tablero, int jugadorActual) {
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

char Tablero::cambioTurnoMarcador(char marcadorActual) {
    if (marcadorActual == 'X') {marcadorActual = 'O';}
    else {marcadorActual = 'X';}
    return marcadorActual;
}

int Tablero::cambioTurnoJugador(int jugadorActual) {
    if (jugadorActual == 1) {jugadorActual = 2;}
    else {jugadorActual = 1;}
    return jugadorActual;
}

void Tablero::ejecucionJuego(vector<vector<char>> tablero) {
    int jugadorActual = 1;
    char marcadorActual = 'X';
    int ganador;

    mostrarTablero(tablero);


    for (int i = 0; i < 9; i++) {
        cout << "Turno del jugador " << jugadorActual << ", marca tu posicion: ";
        int lugar;
        cin >> lugar;

        if (lugar < 1 || lugar > 9) {
            cout << "Lugar invalido, reingrese\n";
            i--;
        } else if (!verificador(lugar, tablero, marcadorActual)) {
            cout << "Lugar invalido, reingrese\n";
            i--;
        } else if (verificador(lugar, tablero, marcadorActual)) {
            tablero = Marcador(lugar, tablero, marcadorActual);
            ganador = revisarEstado(tablero, jugadorActual);
            marcadorActual= cambioTurnoMarcador(marcadorActual);
            jugadorActual= cambioTurnoJugador(jugadorActual); 
            }

        if (ganador == 1) {
            cout << "Gana jugador 1.\n";
            break;
        }

        if (ganador == 2) {
            cout << "Gana jugador 2. \n";
            break;
        }
        
        mostrarTablero(tablero);
    }

    if (ganador == 0) {
        cout << "Es un empate.\n";
    }
}