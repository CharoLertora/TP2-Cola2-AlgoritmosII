#ifndef _PERRO_H_
#define _PERRO_H_

#include <string>
#include "Animal.h"

using namespace std;

class Perro: public Animal{
    
    //Métodos
public:
    Perro(string nombre, int edad, string tamanio, string especie, string personalidad);
};

#endif