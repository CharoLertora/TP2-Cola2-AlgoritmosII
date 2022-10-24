#include <iostream>
#include <string>
#include "Conejo.h"

using namespace std;

const string COMIDA_CONEJO = "Lechuga";

Conejo::Conejo(){
    comida = COMIDA_CONEJO;
    requiere_ducha = true;
}