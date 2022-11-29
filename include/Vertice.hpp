#ifndef _VERTICE_HPP_
#define _VERTICE_HPP_
#include <iostream>
#include "Mapa.hpp"


class Vertice {
    //Atributos:
    private:
        int numero;

    //Métodos:
    public:
        Vertice(int numero);

        int obtener_numero();

        ~Vertice();
};

#endif