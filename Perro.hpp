#ifndef _PERRO_HPP_
#define _PERRO_HPP_

#include <string>
#include "Animal.hpp"

using namespace std;

class Perro: public Animal{
    
    //Métodos
public:
    Perro(string nombre, int edad, string tamanio, string especie, string personalidad);
};

#endif