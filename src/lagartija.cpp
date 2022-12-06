#include <iostream>
#include <string>
#include "../include/lagartija.hpp"

using namespace std;

const string COMIDA_LAGARTIJA = "Insectos";

Lagartija::Lagartija(string nombre, int edad, string tamanio, string especie, string personalidad) : Animal(nombre, edad, tamanio, especie, personalidad) {
    comida = COMIDA_LAGARTIJA;
    requiere_ducha = false;
}