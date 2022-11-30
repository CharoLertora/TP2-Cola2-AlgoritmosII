#ifndef _MAPA_HPP_
#define _MAPA_HPP_
#include "Animal.hpp"
#include "Grafo.hpp"
#include "Auto.hpp"

using namespace std;

const int MAX_TERRENO = 8;
const int MAX_ESPECIES = 7;
const int MAX_ANIMALES = 5;
const int MAX_PERSONALIDADES = 4;
const int MAX_TAMANIOS = 5;
const int MAX_EDAD = 100;

const string ARCHIVO_ANIMALES_A_RESCATAR = "animales_a_rescatar.csv";

const string TIERRA = "🌳"; 
const string CAMINO = "🟨";
const string MONTANIA = "⛰️ ";
const string PRECIPICIO = "🕳 ";
const string AUTO = "🚘";

const int INDICE_PERRO = 1;
const int INDICE_GATO = 2;
const int INDICE_CABALLO = 3;
const int INDICE_ROEDOR = 4;
const int INDICE_CONEJO = 5;
const int INDICE_ERIZO = 6;
const int INDICE_LAGARTIJA = 7;


const string IMAGEN_PERRO = "🐶";
const string IMAGEN_GATO = "🐱";
const string IMAGEN_CABALLO = "🐎";
const string IMAGEN_CONEJO = "🐰";
const string IMAGEN_ERIZO = "🦔";
const string IMAGEN_ROEDOR = "🐭";
const string IMAGEN_LAGARTIJA = "🦎";


class Mapa {

    //Atributos:
private:
    string terreno[MAX_TERRENO][MAX_TERRENO];
    Animal *animales_a_rescatar[MAX_ANIMALES];
    Grafo *grafo;
    Auto *vehiculo;

//Métodos:
public:
    //Pre: -
    //Post: construirá el mapa de juego disponible.
    Mapa(Auto *vehiculo);

    //Pre: el mapa debe estar previamente cargado.
    //Post: mostrara el mapa disponible por pantalla.
    void mostrar_mapa();

    //Pre: La matriz debe estar inicializada y cargada con toda la información necesaria previamente.
    //Post: Devolverá el tipo de terreno que representa la casilla en la que se encuentra.
    char obtener_tipo_terreno();

    Animal* obtener_vector_animales(); 

    void ubicar_auto();

    ~Mapa();

private:

    void llenar_vector();

    void copiar_en_grafo();   

    void ubicar_animales();

    void cargar_animal(int numero, Animal* &animal_random, string nombre, string tamanio, string personalidad, int edad);

    void validar_especie(int especies[MAX_ANIMALES], int &numero, int numero_animal);

    bool ya_salio(int especies[MAX_ANIMALES], int numero);

    void ubicar_animal(Animal* animal, Grafo* grafo);

    void copiar_animales(Grafo *grafo, Animal *animal, int fila, int columna);

    int numero_random(int rango, int minimo);

    bool hay_animal(int fila, int columna);

    string especie_random();

    string personalidad_random();

    string tamanio_random();
};  

#endif //_MAPA_HPP