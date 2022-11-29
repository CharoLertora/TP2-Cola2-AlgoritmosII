#include "../include/Camino_minimo.hpp"

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

    Lista* cola_de_prioridad;
    cola_de_prioridad->agregar(numero_origen, "camino", 0);

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
