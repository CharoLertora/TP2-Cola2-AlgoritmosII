#ifndef _PERRO_HPP_
#define _PERRO_HPP_

#include <string>
#include "Animal.hpp"

using namespace std;

class Perro: public Animal{
    
    //Métodos
public:
    //Constructor con parámetros
    //pre: - 
    //pos: Construye un objeto perro con su respectivo nombre, edad, tamanio, especie y personalidad.
    Perro(string nombre, int edad, string tamanio, string especie, string personalidad);
};

#endif