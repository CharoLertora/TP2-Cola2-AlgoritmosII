#ifndef _CABALLO_H_
#define _CABALLO_H_

#include <string>
#include "Animal.h"

using namespace std;

class Caballo: public Animal{

    //Métodos
public:
    Caballo(string nombre, int edad, string tamanio, string especie, string personalidad);
};

#endif