#ifndef _SISTEMA_HPP_
#define _SISTEMA_HPP_

#include <fstream>
#include <cstring>
#include "Lista.hpp"
#include "Animal.hpp"
#include "Perro.hpp"
#include "Gato.hpp"
#include "Caballo.hpp"
#include "Roedor.hpp"
#include "Conejo.hpp"
#include "Erizo.hpp"
#include "Lagartija.hpp"

using namespace std;

const string ARCHIVO_ANIMALES = "animales.csv";

const string INICIAL_PERRO = "P";
const string INICIAL_GATO = "G";
const string INICIAL_CABALLO = "C";
const string INICIAL_ROEDOR = "R";
const string INICIAL_CONEJO = "C";
const string INICIAL_ERIZO = "E";
const string INICIAL_LAGARTIJA = "L";

const string ESPECIE_PERRO = "Perro";
const string ESPECIE_GATO = "Gato";
const string ESPECIE_CABALLO = "Caballo";
const string ESPECIE_ROEDOR = "Roedor";
const string ESPECIE_CONEJO = "Conejo";
const string ESPECIE_ERIZO = "Erizo";
const string ESPECIE_LAGARTIJA = "Lagartija";

const string TAMANIO_DIMINUTO = "diminuto";
const string TAMANIO_PEQUENIO = "pequeño";
const string TAMANIO_MEDIANO = "mediano";
const string TAMANIO_GRANDE = "grande";
const string TAMANIO_GIGANTE = "gigante";

const string PERSONALIDAD_DORMILON = "Dormilon";
const string PERSONALIDAD_JUEGUETON = "Jugueton";
const string PERSONALIDAD_SOCIABLE = "Sociable";
const string PERSONALIDAD_TRAVIESO = "Travieso";



void agregar_animal(Lista *lista, string nombre, int edad, string tamanio, string especie, string personalidad);

void llenar_lista (Lista *lista);
void listar_animales(Lista *lista);
void rescatar_animal(Lista *lista);
void buscar_animal(Lista *lista);
void cambiar_hambre_higiene(Lista *lista);
void adoptar_animal(Lista *lista);
void guardar_y_salir(Lista *lista);


#endif //_SISTEMA_H_
