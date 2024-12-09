#pragma one
#include <iostream>
#include <vector>

using namespace std;

class Tablero {
    public:
        vector<vector<char>> crearTablero();
        void mostrarTablero(vector<vector<char>> tablero);
        bool verificador(int lugar, vector<vector<char>> tablero, char marcadorActual);
        int revisarEstado(vector<vector<char>> tablero, int jugadorActual);
        char cambioTurnoMarcador(char marcadorActual);
        int cambioTurnoJugador(int jugadorActual);
        void ejecucionJuego(vector<vector<char>> tablero);
        vector<vector<char>> Marcador(int lugar, vector<vector<char>> tablero, char marcadorActual);
};