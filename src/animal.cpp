#include <iostream>
#include <string>
#include "../include/animal.hpp"

using namespace std;

const string PERSONALIDAD_DORMILONA = "dormilon";
const string PERSONALIDAD_JUGUETONA = "jugueton";
const string PERSONALIDAD_SOCIABLE = "sociable";
const string PERSONALIDAD_TRAVIESA = "travieso";

Animal::Animal(){
    hambre = HAMBRE_MINIMA;
    higiene = HIGIENE_MAXIMA;
    eliminado = false;
    adoptado = false;
}

Animal::Animal(string nombre, int edad, string tamanio, string especie, string personalidad) {
    
    this->nombre = nombre;
    this->edad = edad;
    this->tamanio = tamanio;
    this->especie = especie;
    this->personalidad = personalidad;
    eliminado = false;

    hambre = HAMBRE_MINIMA;
    higiene = HIGIENE_MAXIMA;
}

void Animal::alimentar() {
    hambre = HAMBRE_MINIMA;
}

void Animal::baniar() {
    higiene = HIGIENE_MAXIMA;
}

string Animal::obtener_nombre() {
    return nombre;
}

int Animal::obtener_edad() {
    return edad;
}

int Animal::obtener_higiene() {
    return higiene;
}

int Animal::obtener_hambre() {
    return hambre;
}

string Animal::obtener_especie() {
    return especie;
}

string Animal::obtener_tamanio() {
    return tamanio;
}

string Animal::obtener_personalidad() {
    return personalidad;
}

void Animal::asignar_nombre(string nombre){
    this->nombre = nombre;
}

void Animal::aumentar_hambre() {

    if (hambre < HAMBRE_MAXIMA) {

        if (obtener_personalidad() == PERSONALIDAD_DORMILONA){
            hambre = hambre + (AUMENTO_HAMBRE / 2);

        } else if (obtener_personalidad() == PERSONALIDAD_JUGUETONA){
            hambre = hambre + (AUMENTO_HAMBRE * 2);

        } else {
            hambre = hambre + AUMENTO_HAMBRE;
        }
    }
}
   

void Animal::reducir_higiene() {

    if (requiere_ducha && higiene > HIGIENE_MINIMA) {
        if (obtener_personalidad() == PERSONALIDAD_SOCIABLE) {
            higiene = higiene - (REDUCCION_HIGIENE / 2);

        } else if (obtener_personalidad() == PERSONALIDAD_TRAVIESA) {
            higiene = higiene - (REDUCCION_HIGIENE * 2);

        } else {
            higiene = higiene - REDUCCION_HIGIENE;
        }
    }
}

string Animal::obtener_comida() {
    return comida;
}

bool Animal::obtener_requiere_ducha() {
    return requiere_ducha;
}

bool Animal::esta_eliminado(){
    return eliminado;
}

bool Animal::esta_adoptado() {
    return adoptado;
}

void Animal::eliminar(){
    eliminado = true;
}

void Animal::adoptar() {
    adoptado = true;
}