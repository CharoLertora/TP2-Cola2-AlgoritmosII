#ifndef _GATO_HPP_
#define _GATO_HPP_

#include <string>
#include "animal.hpp"

using namespace std;

class Gato: public Animal{

    //Métodos
public:
    //Constructor con parámetros
    //pre: - 
    //pos: Construye un objeto gato con su respectivo nombre, edad, tamanio, especie y personalidad.
    Gato(string nombre, int edad, string tamanio, string especie, string personalidad);
};

#endif