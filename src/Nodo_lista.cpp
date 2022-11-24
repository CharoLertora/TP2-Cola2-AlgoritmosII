#include <iostream>
#include "../include/Nodo_lista.hpp"

using namespace std;

Nodo::Nodo(int numero, string tipo_tierra) {
    this->vertice = new Vertice(numero, tipo_tierra);
    siguiente = 0;
}

Vertice* Nodo::obtener_vertice() {
    return vertice;
}

Nodo* Nodo::obtener_siguiente() {
    return siguiente;
}

void Nodo::asignar_siguiente(Nodo* s) {
    siguiente = s;
}

Nodo::~Nodo () {
    delete vertice;
}