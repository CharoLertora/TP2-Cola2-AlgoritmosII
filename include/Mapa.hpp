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

const string TIERRA = "🟨"; 
const string CAMINO = "⬜";
const string MONTANIA = "🟫";
const string PRECIPICIO = "⬛";
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

struct coordenada {
    int fila;
    int columna;
};

class Mapa {

    //Atributos:
private:
    string terreno[MAX_TERRENO][MAX_TERRENO];
    Animal *animales_a_rescatar[MAX_ANIMALES];
    int animales_rescatados;
    Grafo *grafo;
    Auto *vehiculo;
    coordenada coordenadas[MAX_ANIMALES];

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

    //Pre: -
    //Post: Devuelve el vector "animales" del Mapa.
    Animal* obtener_vector_animales(); 

    void mostrar_listado_animales();

    void obtener_coords_animal(int indice, int &fila, int &columna);

    int animales_sin_rescatar();

    //Destructor
    //Pre: -
    //Post: Libera la memoria ocupada por el Mapa y sus atributos.  
    ~Mapa();

private:

    //Pre: -
    //Post: Llena el vector de animales con diferentes animales generados de manera random.
    void llenar_vector();

    //Pre: -
    //Post: Copia los datos del terreno en el grafo.
    void copiar_en_grafo();   

    //Pre: - 
    //Post: Le asigna cada animal del vector "animales" una posicion en el terreno.
    void ubicar_animales();

    //Pre: -
    //Post: Le asigna una posición en el terreno al vehiculo.
    void ubicar_auto();

    //Pre: -
    //Post: Crea un animal de la especie correspondiente a la generada de manera random, guardandolo en el vector "animales".
    void cargar_animal(int numero, Animal* &animal_random, string nombre, string tamanio, string personalidad, int edad);

    //Pre: "especies" debe estar inicializado, al igual que "numero".
    //Post: Genera especies de manera random hasta llegar a una que no se encuentre repetida.
    void validar_especie(int especies[MAX_ANIMALES], int &numero, int numero_animal);

    //Pre: "especies" debe estar inicializado, al igual que "numero".
    //Post: Verifica que el numero ingresado no se repita, para que las especies de los animales sean diferentes.
    bool ya_salio(int especies[MAX_ANIMALES], int numero);

    void guardar_coordenadas(int indice, int fila, int columna);

    //Pre: -
    //Post: Ubica de manera random cada animal en una posición del terreno, corroborando que no se encuentre en la misma posición que el auto u otro animal. 
    void ubicar_animal(int i, Animal* animal, Grafo* grafo);

    void copiar_animales(Grafo *grafo, Animal *animal, int fila, int columna);

    //Pre: Tanto "rango" como "minimo" deben estar inicializados.
    //Post: Genera un numero random respetando el rango y el minimo ingresado. 
    int numero_random(int rango, int minimo);

    //Pre: -
    //Post: Corrobora que en el espacio del terreno correspondiente a la fila y columna ingresada no se encuentre ningún animal.
    bool hay_animal(int fila, int columna);

    //Pre: -
    //Post: Genera una especie random entre las posibles.
    string especie_random();

    //Pre: -
    //Post: Genera una personalidad random entre las posibles.
    string personalidad_random();

    //Pre: -
    //Post: Genera un tamaño random entre los posibles.
    string tamanio_random();
};  

#endif //_MAPA_HPP