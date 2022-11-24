#include <iostream>
#include "../include/Grafo.hpp"


Grafo::Grafo(){

    matriz_adyacencia = nullptr;
    vertices = new Lista();
    algoritmo = nullptr;
}

void Grafo::agregar_vertice(int numero, string tipo_terreno){

    agrandar_matriz_adyacencia();
    vertices->agregar(numero, tipo_terreno);

}

void Grafo:: agrandar_matriz_adyacencia() {
    int** matriz_auxiliar;
    int nueva_cantidad_vertices = vertices->obtener_cantidad() + 1;

    matriz_auxiliar = new int*[nueva_cantidad_vertices];
    
    for (int i = 0; i < nueva_cantidad_vertices; i++) {
        matriz_auxiliar[i] = new int[nueva_cantidad_vertices];
    }

    copiar_matriz_adyacente(matriz_auxiliar);
    inicializar_nuevo_vertice(matriz_auxiliar);
    liberar_matriz_adyacente();
    matriz_adyacencia = matriz_auxiliar;
}

void Grafo::copiar_matriz_adyacente(int** nueva_matriz) {

    for(int i = 0; i < vertices->obtener_cantidad(); i++) {
        for (int j = 0; j < vertices->obtener_cantidad(); j++) {
            nueva_matriz[i][j] = matriz_adyacencia[i][j];
        }
    }
}

void Grafo::inicializar_nuevo_vertice(int** nueva_matriz) {
    
    for (int i = 0; i < vertices->obtener_cantidad(); i++) {
        nueva_matriz[vertices->obtener_cantidad()][i] = INFINITO;
        nueva_matriz[i][vertices->obtener_cantidad()] = INFINITO;
    }
    nueva_matriz[vertices->obtener_cantidad()][vertices->obtener_cantidad()] = 0;
}

void Grafo::liberar_matriz_adyacente() {

    for (int i = 0; vertices->obtener_cantidad(); i++) {
        delete[] matriz_adyacencia[i];
    }
    delete[] matriz_adyacencia;
}

void Grafo::agregar_camino(int origen, int destino, int peso) {
    
}

Grafo::~Grafo() {

    liberar_matriz_adyacente();
    matriz_adyacencia = nullptr;
    delete vertices;
    delete algoritmo;
}


/*
void Grafo::agregar_vertice(int fila, int columna, string tipo_terreno){
    Vertice *vertice = new Vertice(fila, columna, tipo_terreno);
    vertices->alta(vertice, cant_vertices + 1);
    cant_vertices++;
}

Lista* Grafo::obtener_vertices(){
    return vertices;
}

Vertice* Grafo::encontrar_vertice(int fila, int columna){
    int i = 0;
    bool encontrado = false; 
    while (!encontrado && i < cant_vertices){
        if ((vertices->consulta(i + 1)->obtener_fila() == fila) && (vertices->consulta(i + 1)->obtener_columna() == columna)){
            encontrado = true;
        }else {
            i++;
        }
    }
    
    if (encontrado){
        return vertices->consulta(i + 1);
    }else{
        return NULL;
    }
}

*/