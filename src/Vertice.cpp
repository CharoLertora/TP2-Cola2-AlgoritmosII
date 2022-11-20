#include <iostream>
#include "../include/Vertice.hpp"
#include "../include/Mapa.hpp"


int combustible(char tipo_terreno){

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

Vertice::Vertice(int fila, int columna, char tipo_terreno){
    
    this->fila = fila;
    this->columna = columna;
    this->tipo_terreno = tipo_terreno;
    this->hay_animal = false;
    this->gasto_combustible = combustible(tipo_terreno);
}

void Vertice::asignar_animal(Animal* animal){
    this->animal = animal;
    this->hay_animal = true;
}