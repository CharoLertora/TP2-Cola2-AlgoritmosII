#ifndef _CABALLO_HPP_
#define _CABALLO_HPP_

#include <string>
#include "Animal.hpp"

using namespace std;

class Caballo: public Animal{

    //Métodos
public:
    Caballo(string nombre, int edad, string tamanio, string especie, string personalidad);
};

#endif