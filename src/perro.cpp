#include <iostream>
#include <string>
#include "perro.h"

using namespace std;

const string COMIDA_PERRO = "Huesos";

Perro::Perro(){
    comida = COMIDA_PERRO;
    requiere_ducha = true;
}
