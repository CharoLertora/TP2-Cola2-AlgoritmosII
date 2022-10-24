#ifndef _CONEJO_H_
#define _CONEJO_H_

#include <string>
#include "Animal.h"

using namespace std;

class Conejo: public Animal{

    //Métodos
public:
    Conejo(string nombre, int edad, string tamanio, string especie, string personalidad);
};

#endif