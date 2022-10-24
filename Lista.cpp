#include <iostream>
#include "Lista.h"
#include "Nodo.h"

using namespace std;

Lista::Lista (){
    primero = 0;
    cantidad = 0;
}

Nodo* Lista::encontrar_nodo(int pos){
    int contador = 1;
    Nodo* nodo = primero;
    while (contador != pos){
        nodo = nodo->obtener_siguiente();
        contador++;
    }
    return nodo;
}

void Lista::alta (Animal* animal, int pos){
    Nodo* nuevo = new Nodo(animal);
    if (pos == 1){
        nuevo->asignar_siguiente(primero);
        primero = nuevo;
    }else if (pos == cantidad + 1){
        Nodo* ultimo = encontrar_nodo(pos - 1);
        ultimo->asignar_siguiente(nuevo);        
    }else {
        Nodo* nodo = encontrar_nodo(pos);
        Nodo* anterior = encontrar_nodo(pos - 1);
        nuevo->asignar_siguiente(nodo);
        anterior->asignar_siguiente(nuevo);
    }
    cantidad++;
}

void Lista::baja (int pos){
    Nodo* auxiliar;
    if (pos == 1){
        auxiliar = primero;
        primero = primero->obtener_siguiente();
    }else if (pos == cantidad){
        auxiliar = encontrar_nodo(pos);
        Nodo* anteultimo = encontrar_nodo(pos - 1);
        anteultimo->asignar_siguiente(0);
    }else {
        auxiliar = encontrar_nodo(pos);
        Nodo* anterior = encontrar_nodo(pos - 1);
        anterior->asignar_siguiente(auxiliar->obtener_siguiente());
    }
    cantidad--;
    delete auxiliar;
}

Animal* Lista::consulta (int pos){
    Nodo* nodo_buscado = encontrar_nodo(pos);
    return nodo_buscado->obtener_animal();
}

bool Lista::vacia (){
    return (cantidad == 0);
}

Lista::~Lista (){
    while (!vacia()){
        baja(1); 
    }
}