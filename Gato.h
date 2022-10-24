#ifndef _GATO_H_
#define _GATO_H_

#include <string>
#include "Animal.h"

using namespace std;

class Gato: public Animal{

    //Métodos
public:
    Gato(string nombre, int edad, string tamanio, string especie, string personalidad);
};

#endif