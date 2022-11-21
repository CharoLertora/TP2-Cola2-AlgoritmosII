#ifndef _AUTO_HPP_
#define _AUTO_HPP_
#include "Vertice.hpp"

const int TANQUE_LLENO = 100;
const int REDUCCION_COMBUSTIBLE = 5;

class Auto {
    //Atributos:
private:
    int combustible;
    Vertice *pos_actual;

    //Métodos:
public:
    Auto();

    void asignar_posicion(Vertice *pos_actual);

    void desplazarse(Vertice *destino);

    void cargar_combustible();

    int combustible_actual();

    void pedir_cantidad(int &cantidad);

    void reducir_combustible();

};

#endif