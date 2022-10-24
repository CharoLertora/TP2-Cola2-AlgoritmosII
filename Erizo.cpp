#include <iostream>
#include <string>
#include "Erizo.h"

using namespace std;

const string COMIDA_ERIZO = "Insectos";

Erizo::Erizo(string nombre, int edad, string tamanio, string especie, string personalidad) : Animal(nombre, edad, tamanio, especie, personalidad){
    comida = COMIDA_ERIZO;
    requiere_ducha = true;
}