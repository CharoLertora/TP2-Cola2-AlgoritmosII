#ifndef _AUTO_HPP_
#define _AUTO_HPP_
#include <iostream>

using namespace std;

struct coordenada {
    int fila;
    int columna;
};

const int TANQUE_LLENO = 100;
const int REDUCCION_COMBUSTIBLE = 5;
const int POS_INICIAL = 0;

class Auto {
    //Atributos:
private:
    int combustible;
    coordenada posicion;

    //Métodos:
public:

    //Constructor sin párametros
    //Pre: -
    //Post: crea un Auto con el tanque lleno y su posicion actual en nullptr.
    Auto();

    //Pre: -
    //Post: se encarga de preguntar al usuario la cantidad de combustible que desea ingresar el usuario y en caso de que la misma sea válida llena el tanque con esa cantidad.
    void cargar_combustible();

    //Pre: -
    //Post: devuelve la cantidad actual de combustible que posee el auto.
    int combustible_actual();

    //Pre: -
    //Post: le pide al usuario que ingrese la cantidad de combustible que desea cargarle al auto.
    void pedir_cantidad(int &cantidad);

    //Pre: -
    //Post: se encarga de validar de que la cantidad ingresada por el usuario sea correcta y le pedirá que vuelva a ingresarla en caso de que no lo sea.
    void validar_cantidad(int &cantidad);

    //Pre: -
    //Post: reduce la cantidad de combustible restandole REDUCCION_COMBUSTIBLE.
    void reducir_combustible();

    //Pre: "nueva_pos" debe ser previamente inicializada.
    //Post: Le asigna una nueva posición al auto.
    void asignar_posicion(coordenada nueva_pos);

    //Pre: -
    //Post: Devuelve las coordenadas de la actual posición del auto.
    coordenada obtener_pos();
};

#endif