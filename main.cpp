#include <iostream>

using namespace std;

int main() {

    bool ciclo = true;
    int opcion;
    while (ciclo) {
        cout<<"------------------------\nSeleccione modo a jugar\n------------------------"<<endl;
        cout<<"------------------------\n1.- Jugador vs Jugador.\n2.- Jugador vs IA.\n3.- Jugador vs IA Poda Alfa-Beta.\n4.- Salir.\n------------------------"<<endl;
        cin>>opcion;
        switch (opcion) {
            case 1:
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