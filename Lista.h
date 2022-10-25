#ifndef _LISTA_H_
#define _LISTA_H_
#include "Nodo.h"

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