#include <iostream>
#include <string>
#include "roedor.h"

using namespace std;

const string COMIDA_ROEDOR = "Queso";

Roedor::Roedor(){
    comida = COMIDA_ROEDOR;
    requiere_ducha = false;
}