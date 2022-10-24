#include <iostream>
#include <string>
#include "Perro.h"

using namespace std;

const string COMIDA_PERRO = "Huesos";

Perro::Perro(){
    comida = COMIDA_PERRO;
    requiere_ducha = true;
}
