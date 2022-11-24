#include "../include/Camino_minimo.hpp"

Camino_minimo::Camino_minimo(Lista* vertices, int** matriz_adyacencia) {

    this->vertices = vertices;
    this->matriz_adyacencia = matriz_adyacencia;
    cantidad_vertices= vertices->obtener_cantidad();
    vertices_visitados = new bool[cantidad_vertices];
    recorrido = new int[cantidad_vertices];
}