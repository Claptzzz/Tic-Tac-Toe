#pragma one
#include <iostream>
#include <vector>

using namespace std;

class Tablero {
    public:
        //funciones basicas
        vector<vector<char>> crearTablero();
        void mostrarTablero(vector<vector<char>> tablero);
        bool verificador(int lugar, vector<vector<char>> tablero);
        int revisarEstado(vector<vector<char>> tablero, int jugadorActual);
        char cambioTurnoMarcador(char marcadorActual);
        int cambioTurnoJugador(int jugadorActual);
        void ejecucionJuego(vector<vector<char>> tablero);
        vector<vector<char>> Marcador(int lugar, vector<vector<char>> tablero, char marcadorActual);
        //funciones IA
        int miniMax(vector<vector<char>> tablero, int profundidad, bool esMax);
        int evaluarTablero(vector<vector<char>> tablero);
        vector<vector<char>> moverIA(vector<vector<char>> tablero);
        bool tableroOcupado(vector<vector<char>> tablero);
        void ejecucionJuegoIA(vector<vector<char>> tablero);
};