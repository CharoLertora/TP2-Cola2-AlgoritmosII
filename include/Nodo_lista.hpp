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
    int peso;

    //Métodos
public:

    //Pre: -
    //Post: crea un nodo con el peso = 0 por defecto.
    Nodo(int numero);

    /*//Pre: -
    //Post: crea un nodo con el peso indicado por parámetro.
    Nodo(int numero, int peso);
*/
    //pre:-
    //pos: Devuelve la dirección al siguiente nodo.
    Nodo* obtener_siguiente();

    //Pre: -
    //Post: devuelve el número el nodo actual.
    int obtener_numero();

    //Pre: peso debe ser un número positivo.
    //Post: le asignará al parámetro peso del nodo el valor pasado por atributo.
    void asignar_peso(int peso);

    //Pre: -
    //Post: devuelve el peso del nodo actual.
    int obtener_peso();

    //pre:-
    //pos: Asigna el siguiente nodo.
    void asignar_siguiente(Nodo* s);

    //Destructor
    //pre: - 
    //pos: Libera el espacio de memoria ocupado por el nodo.
    ~Nodo();
};

#endif