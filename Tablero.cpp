#include <iostream>
#include "clases/Tablero.h"
#include <vector>

using namespace std;

vector<vector<char>> Tablero::crearTablero() {
    vector<vector<char>> tablero(3, vector<char>(3));
    int aux = 0;
    //se asignan posiciones al tablero
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
            //se imprime el contenido del tablero
            cout << tablero[i][j] << " | ";
            }
        cout << "\n-------------\n";
        }
}

bool Tablero::verificador(int lugar, vector<vector<char>> tablero) {
    //se obtiene fila y columna con calculo basico
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
        //se coloca el marcador
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
    //parte siendo la X
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
        } else if (!verificador(lugar, tablero)) {
            cout << "Lugar invalido, reingrese\n";
            i--;
        } else if (verificador(lugar, tablero)) {
            //ya verificado el movimiento recien se marca
            tablero = Marcador(lugar, tablero, marcadorActual);
            //se revisa si hay ganador
            ganador = revisarEstado(tablero, jugadorActual);
            //se cambia de jugador
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
    crearTablero();
}



//implementacion IA al tablero

void Tablero::ejecucionJuegoIA(vector<vector<char>> tablero) {
    int jugadorActual = 1;
    //el jugador humano (nosotros) es el caracter O
    char marcadorActual = 'O';
    int ganador;
    mostrarTablero(tablero);
    for (int i=0; i<9; i++) {
        cout << "Es tu turno, marca tu posicion: ";
        int lugar;
        cin >> lugar;
        if (verificador(lugar, tablero)) {
            //en esta funcion se vrifica el marcador del jugador y se marca, y luego en el mismo if se coloca la posicion de la IA
            tablero = Marcador(lugar, tablero, marcadorActual);
            mostrarTablero(tablero);
            ganador = revisarEstado(tablero, jugadorActual);
            jugadorActual = cambioTurnoJugador(jugadorActual);
            tablero = moverIA(tablero);
            i++;
            mostrarTablero(tablero);
            //luego de cada movimiento se verifica ganador
            ganador = revisarEstado(tablero, jugadorActual);
            jugadorActual = cambioTurnoJugador(jugadorActual);
        } else {
            cout << "Movimiento inválido. Reingresa." << endl;
            i--;
        }
        if (ganador == 1) {
            cout<<"Has ganado"<<endl;
            break;
        } else if (ganador == 2) {
            cout<<"Has perdido"<<endl;
            break;
        }       
    }
    if (ganador==0) {
        cout<<"Empate"<<endl;
    }
    crearTablero();
}

int Tablero::evaluarTablero(vector<vector<char>> tablero) { 
    // Revisar filas para X o O ganador 
    for (int fila = 0; fila < 3; fila++) { 
        if (tablero[fila][0] == tablero[fila][1] && tablero[fila][1] == tablero[fila][2]) { 
            if (tablero[fila][0] == 'X') {return 10;} 
            // X gana 
            else if (tablero[fila][0] == 'O') {return -10;} 
            // O gana 
            } 
    } 
    // Revisar columnas para X o O ganador 
    for (int columna = 0; columna < 3; columna++) { 
        if (tablero[0][columna] == tablero[1][columna] && tablero[1][columna] == tablero[2][columna]) { 
            if (tablero[0][columna] == 'X') {return 10;} 
            // X gana 
            else if (tablero[0][columna] == 'O') {return -10;} 
            // O gana 
            } 
    } 
    // Revisar diagonales para X o O ganador 
    if (tablero[0][0] == tablero[1][1] && tablero[1][1] == tablero[2][2]) { 
        if (tablero[0][0] == 'X') {return 10;} 
        // X gana 
        else if (tablero[0][0] == 'O') {return -10;}
        // O gana 
        } 
    if (tablero[0][2] == tablero[1][1] && tablero[1][1] == tablero[2][0]) { 
        if (tablero[0][2] == 'X') {return 10;} 
        // X gana 
        else if (tablero[0][2] == 'O') {return -10;} 
        // O gana 
        }
        // Si no hay ganador
        return 0;
}

int Tablero::miniMax(vector<vector<char>> tablero, int profundidad, bool esMax) { 
    int puntaje = evaluarTablero(tablero); 
    // Si X ha ganado el juego
    if (puntaje == 10) {return puntaje - profundidad;} 
    // Si O ha ganado el juego 
    if (puntaje == -10) {return puntaje + profundidad;} 
    // Si no hay más movimientos y nadie ha ganado es empte
    if (tableroOcupado(tablero)) {return 0;} 
    // Si es el turno del X
    if (esMax) { 
        int mejor = -1000; 
        for (int i = 0; i < 3; i++) { 
            for (int j = 0; j < 3; j++) { 
                if (tablero[i][j] != 'O' && tablero[i][j] != 'X') { 
                    char valorInicial = tablero[i][j];
                    tablero[i][j] = 'X'; 
                    // X 
                    mejor = max(mejor, miniMax(tablero, profundidad + 1, !esMax)); 
                    tablero[i][j] = valorInicial; 
                } 
            } 
        } 
        return mejor; 
    } 
    // Si es el turno del O
    else { 
        int mejor = 1000; 
        for (int i = 0; i < 3; i++) { 
            for (int j = 0; j < 3; j++) { 
                if (tablero[i][j] != 'O' && tablero[i][j] != 'X') {
                    char valorInicial = tablero[i][j]; 
                    tablero[i][j] = 'O'; 
                    // O 
                    mejor = min(mejor, miniMax(tablero, profundidad + 1, !esMax)); 
                    tablero[i][j] = valorInicial; 
                } 
            } 
        } 
        return mejor; 
    } 
}

vector<vector<char>> Tablero::moverIA(vector<vector<char>> tablero) { 
    int mejorValor = -1000; 
    int mejorFila = -1; 
    int mejorColumna = -1; 
    for (int i = 0; i < 3; i++) { 
        for (int j = 0; j < 3; j++) { 
            if (tablero[i][j] != 'O' && tablero[i][j] != 'X') {
                char valorInicial = tablero[i][j]; 
                tablero[i][j] = 'X'; 
                // IA es X 
                int movimientoValor = miniMax(tablero, 0, false); 
                tablero[i][j] = valorInicial; 
                if (movimientoValor > mejorValor) { 
                    mejorFila = i; mejorColumna = j; 
                    mejorValor = movimientoValor; 
                } 
            } 
        } 
    } 
    tablero[mejorFila][mejorColumna] = 'X';
    return tablero;
    // IA coloca su movimiento
}
bool Tablero::tableroOcupado(vector<vector<char>> tablero) { 
    for (int i = 0; i < 3; i++) { 
        for (int j = 0; j < 3; j++) { 
            if (tablero[i][j] != 'X' && tablero[i][j] != 'O') { 
                return false; 
            } 
        } 
    } 
    return true; 
}