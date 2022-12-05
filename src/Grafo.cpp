#include <iostream>
#include "../include/Grafo.hpp"


Grafo::Grafo(){

    matriz_adyacencia = nullptr;
    algoritmo = nullptr;
}

Grafo::Grafo(string terreno[MAX_TERRENO][MAX_TERRENO]) {

    inicializar_matriz_adyacencia();
    for (int i = 0; i < MAX_TERRENO; i++) {
        for (int j = 0; j < MAX_TERRENO; j++) {
            calcular_adyacentes(matriz_adyacencia, i, j, terreno);
        }
    }

    this->algoritmo = nullptr;
}

int calcular_peso(string tipo_terreno) {

    if (tipo_terreno == MONTANIA){
        return COSTO_MONTANIA;
    }else if (tipo_terreno == PRECIPICIO){
        return COSTO_PRECIPICIO;
    }else if (tipo_terreno == CAMINO){
        return COSTO_CAMINO;
    }else {
        return COSTO_TIERRA;
    }
}

int Grafo::calcular_vertice(int fila, int columna) {
    return (MAX_TERRENO * fila) + columna;
}

bool Grafo::es_vertice_valido(int fila, int columna) {
    return ((columna != -1) && (columna != MAX_TERRENO) && (fila != -1) && (fila != MAX_TERRENO));
}

void Grafo::calcular_adyacentes(int** matriz_adyacencia, int fila, int columna, string terreno[MAX_TERRENO][MAX_TERRENO]) {

    int origen = calcular_vertice(fila, columna);

    if (es_vertice_valido(fila, columna+1)) {
        matriz_adyacencia[origen][calcular_vertice(fila, columna+1)] = calcular_peso(terreno[fila][columna+1]);
    }
    if (es_vertice_valido(fila, columna-1)) {
        matriz_adyacencia[origen][calcular_vertice(fila, columna-1)] = calcular_peso(terreno[fila][columna-1]);
    }
    if (es_vertice_valido(fila+1, columna)) {
        matriz_adyacencia[origen][calcular_vertice(fila+1, columna)] = calcular_peso(terreno[fila+1][columna]);
    }
    if (es_vertice_valido(fila-1, columna)) {
        matriz_adyacencia[origen][calcular_vertice(fila-1, columna)] = calcular_peso(terreno[fila-1][columna]);
    }
}

void Grafo::cargar_matriz() {

    for (int i = 0; i < MAX_MATRIZ; i++) {
        for (int j = 0; j < MAX_MATRIZ; j++) {
            if (i == j) {
                matriz_adyacencia[i][j] = 0;    
            } else {
                matriz_adyacencia[i][j] = INFINITO;
            }
        }
    }
}

void Grafo::inicializar_matriz_adyacencia() {

    this->matriz_adyacencia = new int*[MAX_MATRIZ];
    for(int i = 0; i < MAX_MATRIZ; i++){
        this->matriz_adyacencia[i] = new int[MAX_MATRIZ];
    }
    cargar_matriz();
}

void Grafo::mostrar_matriz_adyacencia(int** matriz_adyacencia) {

    cout << "Matriz de adyacencia:" << endl;
    for(int i = 0; i < MAX_MATRIZ; i++){
        for(int j = 0; j < MAX_MATRIZ * 2; j++) {
            if(j == MAX_MATRIZ * 2 - 1){
                cout << endl;
            } else if(j % 2 == 0){
                if(matriz_adyacencia[i][j/2] == INFINITO){
                    cout << "∞";
                } else {
                    cout << matriz_adyacencia[i][j/2];
                }
            } else{
                cout << "|";
            }
        }
    }
    cout << endl;
}

int Grafo::calcular_camino_minimo(int origen, int destino) {

    this->algoritmo = new Camino_minimo(matriz_adyacencia);
    algoritmo->inicializar_matrices();
    algoritmo->calcular_caminos_minimos();
    
    return algoritmo->calcular_costo(origen, destino);
}

void Grafo::liberar_matriz_adyacente() {

    for (int i = 0; MAX_MATRIZ; i++) {
        delete[] matriz_adyacencia[i];
    }
    delete[] matriz_adyacencia;
}

Grafo::~Grafo() {

    liberar_matriz_adyacente();
    matriz_adyacencia = nullptr;
    delete algoritmo;
}
