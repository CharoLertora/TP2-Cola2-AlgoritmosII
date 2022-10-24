#ifndef _ROEDOR_H_
#define _ROEDOR_H_

#include <string>
#include "Animal.h"

using namespace std;

class Roedor: public Animal{

    //Métodos
public:
    Roedor(string nombre, int edad, string tamanio, string especie, string personalidad);
};

#endif