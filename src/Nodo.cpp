#include <iostream>
#include "../include/Nodo.hpp"

using namespace std;

Nodo::Nodo(Animal* animal) {
    this->animal = animal;
    siguiente = 0;
}

Animal* Nodo::obtener_animal() {
    return animal;
}

Nodo* Nodo::obtener_siguiente() {
    return siguiente;
}

void Nodo::asignar_siguiente(Nodo* s) {
    siguiente = s;
}

Nodo::~Nodo () {
    delete animal;
}