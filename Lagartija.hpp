#ifndef _LAGARTIJA_HPP_
#define _LAGARTIJA_HPP_

#include <string>
#include "Animal.hpp"

using namespace std;

class Lagartija: public Animal{

    //Métodos
public:
    //Constructor con parámetros
    //pre: - 
    //pos: Construye un objeto lagartija con su respectivo nombre, edad, tamanio, especie y personalidad.
    Lagartija(string nombre, int edad, string tamanio, string especie, string personalidad);
};

#endif