#include <iostream>
#include <string>
#include "../include/roedor.hpp"

using namespace std;

const string COMIDA_ROEDOR = "Queso";

Roedor::Roedor(string nombre, int edad, string tamanio, string especie, string personalidad) : Animal(nombre, edad, tamanio, especie, personalidad) {
    comida = COMIDA_ROEDOR;
    requiere_ducha = false;
}