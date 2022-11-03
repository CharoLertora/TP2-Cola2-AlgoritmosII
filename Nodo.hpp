#ifndef _NODO_HPP_
#define _NODO_HPP_
#include "Animal.hpp"


class Nodo {

    //Atributos
private:
    Animal* animal;
    Nodo* siguiente;

    //Métodos
public:
    //Constructor
    //pre:-
    //pos: Crea un nodo y guarda el animal ingresado.
    Nodo(Animal* animal);

    //pre:-
    //pos: Devuelve la dirección del animal guardado en el nodo.
    Animal* obtener_animal();

    //pre:-
    //pos: Devuelve la dirección al siguiente nodo.
    Nodo* obtener_siguiente();

    //pre:-
    //pos: Asigna el siguiente nodo.
    void asignar_siguiente(Nodo* s);

    //Destructor
    //pre: - 
    //pos: Libera el espacio de memoria ocupado por el nodo.
    ~Nodo();
};

#endif