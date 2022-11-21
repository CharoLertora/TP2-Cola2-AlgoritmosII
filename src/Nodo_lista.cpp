#include <iostream>
#include "../include/Nodo_lista.hpp"

using namespace std;

Nodo::Nodo(Vertice* vertice) {
    this->vertice = vertice;
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