#include <iostream>
#include <string>
#include "animal.h"

using namespace std;

const string PERSONALIDAD_DORMILONA = "dormilon";
const string PERSONALIDAD_JUGUETONA = "jugueton";
const string PERSONALIDAD_SOCIABLE = "sociable";
const string PERSONALIDAD_TRAVIESA = "travieso";

const int HAMBRE_MINIMA = 0;
const int HIGIENE_MAXIMA = 100;
const int AUMENTO_HAMBRE = 10;
const int REDUCCION_HIGIENE = 10;

Animal::Animal(){
    hambre = HAMBRE_MINIMA;
    higiene = HIGIENE_MAXIMA;
}

void Animal::alimentar(){
    hambre = HAMBRE_MINIMA;
}

void Animal::baniar(){
    higiene = HIGIENE_MAXIMA;
}

void Animal::asignar_edad(int edad){
    this->edad = edad;
}

void Animal::asignar_nombre(string nombre){
    this->nombre = nombre;
}

void Animal::asignar_especie(string especie){
    this->especie = especie;
}

void Animal::asignar_tamanio(string tamanio){
    this->tamanio = tamanio;
}


void Animal::asignar_personalidad(string personalidad){
    this->personalidad = personalidad;
}

string Animal::obtener_nombre(){
    return nombre;
}

int Animal::obtener_edad(){
    return edad;
}

int Animal::obtener_higiene(){
    return higiene;
}

int Animal::obtener_hambre(){
    return hambre;
}

string Animal::obtener_especie(){
    return especie;
}

string Animal::obtener_tamanio(){
    return tamanio;
}

string Animal::obtener_personalidad(){
    return personalidad;
}

void Animal::aumentar_hambre(){
    if (obtener_personalidad() == PERSONALIDAD_DORMILONA){
        hambre = hambre + (AUMENTO_HAMBRE / 2);
    }else if (obtener_personalidad() == PERSONALIDAD_JUGUETONA){
        hambre = hambre + (AUMENTO_HAMBRE * 2);
    }else {
        hambre = hambre + AUMENTO_HAMBRE;
    }
}

void Animal::reducir_higiene(){
    if (obtener_personalidad() == PERSONALIDAD_SOCIABLE){
        higiene = higiene - (REDUCCION_HIGIENE / 2);
    }else if (obtener_personalidad() == PERSONALIDAD_TRAVIESA){
        higiene = higiene - (REDUCCION_HIGIENE * 2);
    }else {
        higiene = higiene - REDUCCION_HIGIENE;
    }
}

string Animal::obtener_comida(){
    return comida;
}

bool Animal::debe_ducharse(){
    return requiere_ducha;
}