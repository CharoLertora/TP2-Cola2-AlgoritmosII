#ifndef _LISTA_HPP_
#define _LISTA_HPP_
#include "Nodo.hpp"

const int POSICION_INICIAL = 1;

using namespace std;

class Lista {

    //Atributos
private:
    Nodo* primero;
    int cantidad;

    //Métodos
public:
    Lista();
    void alta(Animal* animal, int pos);
    void baja(int pos);
    int obtener_cantidad();
    Animal* consulta(int pos);
    bool vacia();
    ~Lista();

private:
    Nodo* encontrar_nodo(int pos);
};

#endif