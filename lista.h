#ifndef _LISTA_H_
#define _LISTA_H_
#include "nodo.h"

using namespace std;

class Lista {

    //Atributos
private:
    Nodo* primero;
    int cantidad;

    //Métodos
public:
    Lista();
    void alta(Animal animal);
    Animal baja(int pos);
    Animal consulta(int pos);
    bool vacia();
    ~Lista();

private:
    Nodo* encontrar_nodo(int pos);
};

#endif