#include <iostream>
#include "../include/Vertice.hpp"
#include "../include/Mapa.hpp"


int combustible(string tipo_terreno){

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

Vertice::Vertice(int fila, int columna, string tipo_terreno){
    
    this->fila = fila;
    this->columna = columna;
    this->tipo_terreno = tipo_terreno;
    this->hay_animal = false;
    this->gasto_combustible = combustible(tipo_terreno);
    arriba = NULL;
    abajo = NULL;
    derecha = NULL;
    izquierda = NULL;
}

void Vertice::asignar_animal(Animal* animal){
    this->animal = animal;
    this->hay_animal = true;
}

int Vertice::obtener_fila(){
    return fila;
}

int Vertice::obtener_columna(){
    return columna;
}