#include "../include/Camino_minimo.hpp"
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

const int MAX_TERRENO = 8;
const int MAX_MATRIZ = MAX_TERRENO*MAX_TERRENO;
const int POSICION_NO_ENCONTRADA = -1;
const int INFINITO = 99;

Camino_minimo::Camino_minimo(int** matriz_grafo) {

    this->matriz_adyacencia = matriz_grafo;
    this->distancias = new int*[MAX_MATRIZ];
    this->caminos = new int*[MAX_MATRIZ];
}

void Camino_minimo::inicializar_matrices() {

    for(int i = 0; i < MAX_MATRIZ; i++){
        distancias[i] = new int[MAX_MATRIZ];
        caminos[i] = new int[MAX_MATRIZ];
    }

    for (int i = 0; i < MAX_MATRIZ; i++) {
        for (int j = 0; j < MAX_MATRIZ; j++) {
            distancias[i][j] = matriz_adyacencia[i][j];
            caminos[i][j] = j;
        }
    }
}

void Camino_minimo::calcular_caminos_minimos() {

    for (int k = 0; k < MAX_MATRIZ; k++) {
        for (int i = 0; i < MAX_MATRIZ; i++) {
            for (int j = 0; j < MAX_MATRIZ; j++) {

                if ((distancias[i][j] > distancias[i][k] + distancias[k][j]) && (distancias[k][j] != INFINITO && distancias[i][k] != INFINITO) ) {

                    distancias[i][j] = distancias[i][k] + distancias[k][j];
                    caminos[i][j] = caminos[i][k];
                }
            }
        }
    }
}

void Camino_minimo::mostrar_matrices() {
    
    cout << "Matriz de distancias:      ||           Matriz de caminos:" << endl;
    string fila_distancias;
    string fila_caminos;
    for(int i = 0; i < MAX_MATRIZ; i++){
        for(int j = 0; j < MAX_MATRIZ * 2; j++) {
            if(j == MAX_MATRIZ * 2 - 1){
                fila_distancias += "            ||           ";
                fila_caminos += "\n";
            } else if(j % 2 == 0){
                if(distancias[i][j/2] == INFINITO){
                    fila_distancias += "∞";
                } else {
                    fila_distancias += to_string(distancias[i][j/2]);
                }

                if(caminos[i][j/2] == POSICION_NO_ENCONTRADA){
                    fila_caminos += "-";
                } else {
                    fila_caminos += to_string(caminos[i][j/2]);
                }
            } else{
                fila_caminos += "|";
                fila_distancias += "|";
            }
        }
        cout << fila_distancias << fila_caminos;
        fila_distancias = "";
        fila_caminos = "";
    }
    cout << endl;
}

int Camino_minimo::calcular_costo(int origen, int destino) {
    return distancias[origen][destino];
}

void Camino_minimo::liberar_matrices() {
    
    for (int i = 0; MAX_MATRIZ; i++) {
        delete[] distancias[i];
        delete[] caminos[i];
    }
    delete[] distancias;
    delete[] caminos;
}

Camino_minimo::~Camino_minimo() {
    
    liberar_matrices();
    distancias = nullptr;
    caminos = nullptr;
}
/*
Camino_minimo::Camino_minimo(Lista* vertices, int** matriz_adyacencia) {

    this->vertices = vertices;
    this->matriz_adyacencia = matriz_adyacencia;
    cantidad_vertices= vertices->obtener_cantidad();
    vertices_visitados = new bool[cantidad_vertices];
    recorrido = new int[cantidad_vertices];
    distancia = new int[cantidad_vertices];
}

void Camino_minimo::inicializar_visitados(int numero_origen) {

    for (int i = 0; i < cantidad_vertices; i++) {
        vertices_visitados[i] = false;
    }
    vertices_visitados[numero_origen] = true;
}

void Camino_minimo::inicializar_distancias(int numero_origen) {
    
    for (int i = 0; i < cantidad_vertices; i++) {
        distancia[i] = INFINITO;
    }
    distancia[numero_origen] = 0;
}

void Camino_minimo::inicializar_recorrido() {

    for (int i = 0; i < cantidad_vertices; i++) {
        recorrido[i] = POSICION_NO_ENCONTRADA;
    }
}



void Camino_minimo::camino_minimo(int numero_origen, int numero_destino) {

    inicializar_visitados(numero_origen);
    inicializar_distancias(numero_origen);
    inicializar_recorrido();

    //Lista* cola_de_prioridad;
    //cola_de_prioridad->agregar(numero_origen, "camino", 0);

    int actual;
    int adyacente;
    int peso;

    while (!cola_de_prioridad->vacia()) {
        actual = cola_de_prioridad->obtener_primero()->obtener_numero();
        cola_de_prioridad->baja(actual);

        if(vertices_visitados[actual]) continue;
        vertices_visitados[actual] = true;

        for(int i = 0; i < matriz_adyacencia[actual][i]; i++) {
            adyacente = matriz_adyacencia[actual][i];
        }
    }
}
    */

