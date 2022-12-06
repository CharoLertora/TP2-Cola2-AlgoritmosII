#ifndef _ERIZO_HPP_
#define _ERIZO_HPP_

#include <string>
#include "animal.hpp"

using namespace std;

class Erizo: public Animal{

    //Métodos
public:
    //Constructor con parámetros
    //pre: - 
    //pos: Construye un objeto erizo con su respectivo nombre, edad, tamanio, especie y personalidad.
    Erizo(string nombre, int edad, string tamanio, string especie, string personalidad);
};

#endif