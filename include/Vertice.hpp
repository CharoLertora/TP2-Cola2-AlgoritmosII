#ifndef _VERTICE_HPP_
#define _VERTICE_HPP_
#include <iostream>
#include "Mapa.hpp"

const int COSTO_MONTANIA = 5;
const int COSTO_PRECIPICIO = 40;
const int COSTO_CAMINO = 1;
const int COSTO_TIERRA = 2;

class Vertice {
    //Atributos:
    private:
        int numero;
        string tipo_terreno;

    //Métodos:
    public:
        Vertice(int numero, string tipo_terreno);

        int obtener_numero();

        string obtener_terreno();


        ~Vertice();
};

#endif