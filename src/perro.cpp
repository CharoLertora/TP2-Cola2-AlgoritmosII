#include <iostream>
#include <string>
#include "../include/perro.hpp"

using namespace std;

const string COMIDA_PERRO = "Huesos";

Perro::Perro(string nombre, int edad, string tamanio, string especie, string personalidad) : Animal(nombre, edad, tamanio, especie, personalidad) {
    comida = COMIDA_PERRO;
    requiere_ducha = true;
}
