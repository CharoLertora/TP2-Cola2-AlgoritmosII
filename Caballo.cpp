#include <iostream>
#include <string>
#include "Caballo.h"

using namespace std;

const string COMIDA_CABALLO = "Manzanas";

Caballo::Caballo(string nombre, int edad, string tamanio, string especie, string personalidad) : Animal(nombre, edad, tamanio, especie, personalidad){
    comida = COMIDA_CABALLO;
    requiere_ducha = true;
}