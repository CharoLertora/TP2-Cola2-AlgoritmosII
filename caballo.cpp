#include <iostream>
#include <string>
#include "caballo.h"

using namespace std;

const string COMIDA_CABALLO = "Manzanas";

Caballo::Caballo(){
    comida = COMIDA_CABALLO;
    requiere_ducha = true;
}