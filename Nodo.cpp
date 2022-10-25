#include <iostream>
#include "Nodo.h"

using namespace std;


Nodo::Nodo(Animal* animal){
    this->animal = animal;
    siguiente = 0;
}

Animal* Nodo::obtener_animal(){
    return animal;
}

Nodo* Nodo::obtener_siguiente(){
    return siguiente;
}

void Nodo::asignar_siguiente(Nodo* s){
    siguiente = s;
}

void Nodo::asignar_animal(Animal* animalito){
    animal = animalito;
}

Nodo::~Nodo (){
    delete animal;
}