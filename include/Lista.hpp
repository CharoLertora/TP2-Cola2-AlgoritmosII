#ifndef _LISTA_HPP_
#define _LISTA_HPP_
#include "Nodo_lista.hpp"

const int POSICION_INICIAL = 1;

using namespace std;

class Lista {

    //Atributos
private:
    Nodo* primero;
    int cantidad;

    //Métodos
public:
    //Constructor 
    //pre: - 
    //pos: Construye una lista con cantidad en 0 y primero null.
    Lista();

    //pre: La posiciòn ingresada debe ser válida, es decir, no puede ser menor a uno ni mayor a la "cantidad actual de vertices + 1".
    //pos: Agrega un nuevo nodo a la lista en la posiciòn ingresada y guarda "dentro" un vertice.
    void alta(Vertice* vertice, int pos);

    //pre: Debe haber un nodo en la posición ingresada.
    //pos: Elimina el nodo que se encuentra en la posición ingresada.
    void baja(int pos);

    //pre: - 
    //pos: Devuelve la cantidad de vertices que hay en la lista.
    int obtener_cantidad();

    //pre: Debe haber un nodo en la posición ingresada.
    //pos: Devuelve la dirección del vertice que se encuentra en el nodo en la posición ingresada.
    Vertice* consulta(int pos);

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