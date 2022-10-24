#include <iostream>
#include <string>
#include "Gato.h"

using namespace std;

const string COMIDA_GATO = "Atún";

Gato::Gato(){
    comida = COMIDA_GATO;
    requiere_ducha = false;
}