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

void Lista::agregar(int numero, string tipo_terreno) {

    Nodo* nuevo_nodo = new Nodo(numero, tipo_terreno);

    if (primero == nullptr) {
        primero = nuevo_nodo;
        ultimo = primero;
    } else {
        ultimo->asignar_siguiente(nuevo_nodo);
        ultimo = nuevo_nodo;
    }
    cantidad++;
}


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

Vertice* Lista::consulta (int pos) {
    Nodo* nodo_buscado = encontrar_nodo(pos);
    return nodo_buscado->obtener_vertice();
}

bool Lista::vacia () {
    return (cantidad == 0);
}

Lista::~Lista () {
    while (!vacia()) {
        baja(1); 
    }
}