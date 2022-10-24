#ifndef _ERIZO_H_
#define _ERIZO_H_

#include <string>
#include "Animal.h"

using namespace std;

class Erizo: public Animal{

    //Métodos
public:
    Erizo(string nombre, int edad, string tamanio, string especie, string personalidad);
};

#endif