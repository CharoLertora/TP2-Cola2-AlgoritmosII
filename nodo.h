#ifndef _NODO_H_
#define _NODO_H_
#include "animal.h"


class Nodo {

    //Atributos
private:
    Animal animal;
    Nodo* siguiente;

    //Métodos

public:
    Nodo(Animal animalito);
    Animal obtener_animal();
    Nodo* obtener_siguiente();
    void asignar_animal(Animal animalito);
    void asignar_siguiente(Nodo* s);
};

#endif