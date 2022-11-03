#include <iostream>
#include <string>
#include "Conejo.hpp"

using namespace std;

const string COMIDA_CONEJO = "Lechuga";

Conejo::Conejo(string nombre, int edad, string tamanio, string especie, string personalidad) : Animal(nombre, edad, tamanio, especie, personalidad) {
    comida = COMIDA_CONEJO;
    requiere_ducha = true;
}