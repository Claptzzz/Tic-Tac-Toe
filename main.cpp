#include <iostream>
#include "clases/Tablero.h"
#include <vector>

using namespace std;

int main() {

    bool ciclo = true;
    int opcion;
    Tablero* tab = new Tablero();
    vector<vector<char>> tablero = tab->crearTablero();
    while (ciclo) {
        cout<<"------------------------\nSeleccione modo a jugar\n------------------------"<<endl;
        cout<<"------------------------\n1.- Jugador vs Jugador.\n2.- Jugador vs IA.\n3.- Jugador vs IA Poda Alfa-Beta.\n4.- Salir.\n------------------------"<<endl;
        cin>>opcion;
        switch (opcion) {
            case 1:
                tab->ejecucionJuego(tablero);
                break;
            case 2:
                tab->ejecucionJuegoIA(tablero);
                break;
            case 3:
                break;
            case 4:
                ciclo = false;
                break;
            default: 
                cout << "Opción no válida. Reingrese." << endl;
                break;
        }
    }
    delete tab;

    return 0;
}