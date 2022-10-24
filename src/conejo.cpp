#include <iostream>
#include <string>
#include "conejo.h"

using namespace std;

const string COMIDA_CONEJO = "Lechuga";

Conejo::Conejo(){
    comida = COMIDA_CONEJO;
    requiere_ducha = true;
}