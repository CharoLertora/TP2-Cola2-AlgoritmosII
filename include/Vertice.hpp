#ifndef _VERTICE_HPP_
#define _VERTICE_HPP_
#include <iostream>
#include "Animal.hpp"

const int COSTO_MONTANIA = 5;
const int COSTO_PRECIPICIO = 40;
const int COSTO_CAMINO = 1;
const int COSTO_TIERRA = 2;

class Vertice{
    //Atributos:
private:
    Animal* animal;
    bool hay_animal;
    int fila;
    int columna;
    Vertice* arriba;
    Vertice* abajo;
    Vertice* derecha;
    Vertice* izquierda;
    int gasto_combustible;
    string tipo_terreno;

    //Métodos:
public:
    Vertice(int fila, int columna, string tipo_terreno);

    void asignar_animal(Animal* animal);

    int costo_viaje(Vertice* destino);

    int obtener_fila();

    int obtener_columna();
};

#endif