#include <iostream>
#include "nodo.h"

using namespace std;


Nodo::Nodo(Animal animalito){
    animal = animalito;
    siguiente = 0;
}

Animal Nodo::obtener_animal(){
    return animal;
}

Nodo* Nodo::obtener_siguiente(){
    return siguiente;
}

void Nodo::asignar_siguiente(Nodo* s){
    siguiente = s;
}

void Nodo::asignar_animal(Animal animalito){
    animal = animalito;
}