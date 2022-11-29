#ifndef _LISTA_HPP_
#define _LISTA_HPP_
#include "Nodo_lista.hpp"

const int POSICION_INICIAL = 1;
const int POSICION_NO_ENCONTRADA = -1;

using namespace std;

class Lista {

    //Atributos
private:
    Nodo* primero;
    Nodo* ultimo;
    int cantidad;

    //Métodos
public:
    //Constructor 
    //pre: - 
    //pos: Construye una lista con cantidad en 0 y primero null.
    Lista();

    //Pre: -
    //Post: agrega un nuevo elemento a la lista.
    void agregar(int numero);

    //Pre: el peso debe estar previamente calculado.
    //Post: agrega un nuevo elemento a lista pero de forma ordenada según el peso menor.
    void agregar(int numero, int peso);
    
    //Pre: -
    //Post: devuelve el nodo inicial de la lista.
    Nodo* obtener_primero();

    //Pre: -
    //Post: devolverá la posición en la que se encuentra el número recibido o -1 si no lo
    int obtener_posicion(int numero);

    //pre: Debe haber un nodo en la posición ingresada.
    //pos: Elimina el nodo que se encuentra en la posición ingresada.
    void baja(int pos);

    //pre: - 
    //pos: Devuelve la cantidad de vertices que hay en la lista.
    int obtener_cantidad();

    //pre: - 
    //pos: Devuelve true si la lista está vacía y false en caso contrario.
    bool vacia();

    //Destructor
    //pre: - 
    //pos: Libera el espacio de memoria ocupado por la lista.
    ~Lista();

private:
    //pre: Debe haber un nodo en la posición ingresada.
    //pos: Devuelve la dirección del nodo que se encuentra en la posición ingresada.
    Nodo* encontrar_nodo(int pos);

};

#endif