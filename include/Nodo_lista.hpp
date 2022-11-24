#ifndef _NODO_HPP_
#define _NODO_HPP_
#include "Animal.hpp"
#include "Vertice.hpp"
#include "Mapa.hpp"


class Nodo {

    //Atributos
private:
    Vertice* vertice;
    Nodo* siguiente;

    //Métodos
public:

    Nodo(int numero, string tipo_terreno);
/*
    //Constructor
    //pre:-
    //pos: Crea un nodo y guarda el vertice ingresado.
    Nodo(Vertice* vertice);
*/
    //pre:-
    //pos: Devuelve la dirección del vertice guardado en el nodo.
    Vertice* obtener_vertice();

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