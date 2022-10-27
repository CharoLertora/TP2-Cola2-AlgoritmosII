#ifndef _CONEJO_HPP_
#define _CONEJO_HPP_

#include <string>
#include "Animal.hpp"

using namespace std;

class Conejo: public Animal{

    //Métodos
public:
    Conejo(string nombre, int edad, string tamanio, string especie, string personalidad);
};

#endif