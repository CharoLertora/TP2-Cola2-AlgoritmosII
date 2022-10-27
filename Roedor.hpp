#ifndef _ROEDOR_HPP_
#define _ROEDOR_HPP_

#include <string>
#include "Animal.hpp"

using namespace std;

class Roedor: public Animal{

    //Métodos
public:
    Roedor(string nombre, int edad, string tamanio, string especie, string personalidad);
};

#endif