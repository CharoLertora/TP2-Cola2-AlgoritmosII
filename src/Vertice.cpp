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

Vertice::Vertice(int numero, string tipo_terreno){
    this->numero = numero;
    this->tipo_terreno = tipo_terreno;
}

int Vertice::obtener_numero() {
    return numero;
}

string Vertice::obtener_terreno() {
    return tipo_terreno;
}


Vertice::~Vertice() {
    
}