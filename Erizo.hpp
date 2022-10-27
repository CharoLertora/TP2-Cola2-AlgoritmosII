#ifndef _ERIZO_HPP_
#define _ERIZO_HPP_

#include <string>
#include "Animal.hpp"

using namespace std;

class Erizo: public Animal{

    //Métodos
public:
    Erizo(string nombre, int edad, string tamanio, string especie, string personalidad);
};

#endif