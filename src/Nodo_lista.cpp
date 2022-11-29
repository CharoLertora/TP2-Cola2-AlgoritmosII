#include <iostream>
#include "../include/Nodo_lista.hpp"

using namespace std;

Nodo::Nodo(int numero) {
    this->vertice = new Vertice(numero);
    this->siguiente = 0;
    this->peso = 0;
}

/*
Nodo::Nodo(int numero, int peso) {
    this->vertice = new Vertice(numero, peso);
    this->siguiente = 0;
    this->peso = peso;
}
*/
void Nodo::asignar_peso(int peso) {
    this->peso = peso;
}

int Nodo::obtener_peso() {
    return this->peso;
}

Nodo* Nodo::obtener_siguiente() {
    return siguiente;
}

void Nodo::asignar_siguiente(Nodo* s) {
    siguiente = s;
}

int Nodo::obtener_numero() {
    return this->vertice->obtener_numero();
}

Nodo::~Nodo () {
    delete vertice;
}