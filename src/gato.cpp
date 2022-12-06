#include <iostream>
#include <string>
#include "../include/gato.hpp"

using namespace std;

const string COMIDA_GATO = "Atún";

Gato::Gato(string nombre, int edad, string tamanio, string especie, string personalidad) : Animal(nombre, edad, tamanio, especie, personalidad) {
    comida = COMIDA_GATO;
    requiere_ducha = false;
}