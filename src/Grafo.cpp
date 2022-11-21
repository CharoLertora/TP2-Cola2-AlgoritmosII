#include <iostream>
#include "../include/Grafo.hpp"


Grafo::Grafo(){
    
    vertices = new Lista();
    cant_vertices = 0;
}

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
        if (vertices->consulta(i)->obtener_fila() == fila && vertices->consulta(i)->obtener_columna() == columna){
            encontrado = true;
        }else {
            i++;
        }
    }
    
    if (encontrado){
        return vertices->consulta(i);
    }else{
        return NULL;
    }
}