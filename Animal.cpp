#include <iostream>
#include <string>
#include "Animal.hpp"

using namespace std;

const string PERSONALIDAD_DORMILONA = "dormilon";
const string PERSONALIDAD_JUGUETONA = "jugueton";
const string PERSONALIDAD_SOCIABLE = "sociable";
const string PERSONALIDAD_TRAVIESA = "travieso";

const int HAMBRE_MINIMA = 0;
const int HAMBRE_MAXIMA = 100;
const int HIGIENE_MINIMA = 0;
const int HIGIENE_MAXIMA = 100;
const int AUMENTO_HAMBRE = 10;
const int REDUCCION_HIGIENE = 10;



Animal::Animal(string nombre, int edad, string tamanio, string especie, string personalidad){
    this->nombre = nombre;
    this->edad = edad;
    this->tamanio = tamanio;
    this->especie = especie;
    this->personalidad = personalidad;

    hambre = HAMBRE_MINIMA;
    higiene = HIGIENE_MAXIMA;
}

void Animal::alimentar(){
    hambre = HAMBRE_MINIMA;
}

void Animal::baniar(){
    higiene = HIGIENE_MAXIMA;
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
    if(hambre < HAMBRE_MAXIMA){
        if (obtener_personalidad() == PERSONALIDAD_DORMILONA){
            hambre = hambre + (AUMENTO_HAMBRE / 2);
    }else if (obtener_personalidad() == PERSONALIDAD_JUGUETONA){
            hambre = hambre + (AUMENTO_HAMBRE * 2);
    }else {
            hambre = hambre + AUMENTO_HAMBRE;
    }
}
    }
   

void Animal::reducir_higiene(){
    if (requiere_ducha && higiene > HIGIENE_MINIMA){
        if (obtener_personalidad() == PERSONALIDAD_SOCIABLE){
            higiene = higiene - (REDUCCION_HIGIENE / 2);
        }else if (obtener_personalidad() == PERSONALIDAD_TRAVIESA){
            higiene = higiene - (REDUCCION_HIGIENE * 2);
        }else {
            higiene = higiene - REDUCCION_HIGIENE;
        }
    }
}

string Animal::obtener_comida(){
    return comida;
}

bool Animal::obtener_requiere_ducha(){
    return requiere_ducha;
}
