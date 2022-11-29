#include <iostream>
#include "../include/Vertice.hpp"
#include "../include/Mapa.hpp"



Vertice::Vertice(int numero){
    this->numero = numero;

}

int Vertice::obtener_numero() {
    return numero;
}

Vertice::~Vertice() {
    
}