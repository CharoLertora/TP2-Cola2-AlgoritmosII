#include <iostream>
#include "../include/Lista.hpp"
#include "../include/Nodo_lista.hpp"

using namespace std;


Lista::Lista () {
    primero = 0;
    ultimo = 0;
    cantidad = 0;
}

Nodo* Lista::encontrar_nodo(int pos) {

    int contador = POSICION_INICIAL;
    Nodo* nodo = primero;
    while (contador != pos) {
        nodo = nodo->obtener_siguiente();
        contador++;
    }
    return nodo;
}

void Lista::agregar(int numero) {

    Nodo* nuevo_nodo = new Nodo(numero);

    if (primero == nullptr) {
        primero = nuevo_nodo;
        ultimo = primero;
        
    } else {
        ultimo->asignar_siguiente(nuevo_nodo);
        ultimo = nuevo_nodo;
    }
    cantidad++;
}
/*
void Lista::agregar(int numero, int peso) {
    
    Nodo* nuevo_nodo = new Nodo(numero);

    if (primero == nullptr) {
        primero = nuevo_nodo;
        ultimo = primero;
        primero->asignar_peso(peso);
    } else {
        if (nuevo_nodo->obtener_peso() < ultimo->obtener_peso()) {
            
            Nodo* aux = ultimo;
            ultimo = nuevo_nodo;
            ultimo->asignar_siguiente(aux);
        } else {
            ultimo->asignar_siguiente(nuevo_nodo);
            ultimo = nuevo_nodo;
        }
    }
    cantidad++;
}
*/
int Lista::obtener_posicion(int numero) {
    
    bool encontrado = false;
    int i = 0;
    Nodo* auxiliar = primero;
    
    while (!encontrado && i < cantidad) {
        if (auxiliar->obtener_numero() == numero) {
            encontrado = true;
        }
        i++;
        auxiliar = auxiliar->obtener_siguiente();
    }

    if (!encontrado) {
        return POSICION_NO_ENCONTRADA;
    }
    return i - 1;
}

Nodo* Lista::obtener_primero() {
    return this->primero;
}

//Ver si se puede modificar o borrar.
void Lista::baja (int pos) {

    Nodo* auxiliar;
    if (pos == POSICION_INICIAL) {
        auxiliar = primero;
        primero = primero->obtener_siguiente();

    } else if (pos == cantidad) {
        auxiliar = encontrar_nodo(pos);
        Nodo* anteultimo = encontrar_nodo(pos - 1);
        anteultimo->asignar_siguiente(0);

    } else {
        auxiliar = encontrar_nodo(pos);
        Nodo* anterior = encontrar_nodo(pos - 1);
        anterior->asignar_siguiente(auxiliar->obtener_siguiente());
    }
    cantidad--;
    delete auxiliar;
}

int Lista::obtener_cantidad () {
    return cantidad;
}


bool Lista::vacia () {
    return (cantidad == 0);
}

Lista::~Lista () {
    
    Nodo* siguiente;
    while (primero != nullptr) {
        siguiente = primero->obtener_siguiente();
        delete primero;
        primero = siguiente;
    }
}