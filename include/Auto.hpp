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

    //Constructor sin párametros
    // pre: -
    // post: crea un Auto con el tanque lleno y su posicion actual en nullptr.
    Auto();

    void asignar_posicion(Vertice *pos_actual);

    void desplazarse(Vertice *destino);

    // pre: -
    // post: se encarga de preguntar al usuario la cantidad de combustible que desea ingresar el usuario y en caso de que la misma sea válida llena el tanque con esa cantidad.
    void cargar_combustible();

    // pre: -
    // post: devuelve la cantidad actual de combustible que posee el auto.
    int combustible_actual();

    //pre: -
    //post: le pide al usuario que ingrese la cantidad de combustible que desea cargarle al auto.
    void pedir_cantidad(int &cantidad);

    //pre: -
    //post: se encarga de validar de que la cantidad ingresada por el usuario sea correcta y le pedirá que vuelva a ingresarla en caso de que no lo sea.
    void validar_cantidad(int &cantidad);

    // pre: -
    // post: reduce la cantidad de combustible restandole REDUCCION_COMBUSTIBLE.
    void reducir_combustible();

};

#endif