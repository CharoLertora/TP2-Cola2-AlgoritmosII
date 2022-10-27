#ifndef _GATO_HPP_
#define _GATO_HPP_

#include <string>
#include "Animal.hpp"

using namespace std;

class Gato: public Animal{

    //Métodos
public:
    Gato(string nombre, int edad, string tamanio, string especie, string personalidad);
};

#endif