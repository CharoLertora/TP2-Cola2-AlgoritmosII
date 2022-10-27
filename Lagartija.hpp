#ifndef _LAGARTIJA_HPP_
#define _LAGARTIJA_HPP_

#include <string>
#include "Animal.hpp"

using namespace std;

class Lagartija: public Animal{

    //Métodos
public:
    Lagartija(string nombre, int edad, string tamanio, string especie, string personalidad);
};

#endif