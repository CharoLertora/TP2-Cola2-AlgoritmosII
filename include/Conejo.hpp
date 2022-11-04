#ifndef _CONEJO_HPP_
#define _CONEJO_HPP_

#include <string>
#include "Animal.hpp"

using namespace std;

class Conejo: public Animal{

    //Métodos
public:
    //Constructor con parámetros
    //pre: - 
    //pos: Construye un objeto conejo con su respectivo nombre, edad, tamanio, especie y personalidad.
    Conejo(string nombre, int edad, string tamanio, string especie, string personalidad);
};

#endif