#ifndef _LAGARTIJA_H_
#define _LAGARTIJA_H_

#include <string>
#include "Animal.h"

using namespace std;

class Lagartija: public Animal{

    //Métodos
public:
    Lagartija(string nombre, int edad, string tamanio, string especie, string personalidad);
};

#endif