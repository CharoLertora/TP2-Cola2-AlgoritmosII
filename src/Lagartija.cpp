#include <iostream>
#include <string>
#include "Lagartija.h"

using namespace std;

const string COMIDA_LAGARTIJA = "Insectos";

Lagartija::Lagartija(){
    comida = COMIDA_LAGARTIJA;
    requiere_ducha = false;
}