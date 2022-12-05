#ifndef _MAPA_HPP_
#define _MAPA_HPP_
#include "Animal.hpp"
#include "Grafo.hpp"
#include "Auto.hpp"

using namespace std;

const int MAX_ESPECIES = 7;
const int MAX_ANIMALES = 5;
const int MAX_PERSONALIDADES = 4;
const int MAX_TAMANIOS = 5;
const int MAX_EDAD = 100;

const string ARCHIVO_ANIMALES_A_RESCATAR = "animales_a_rescatar.csv";

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
    int animales_rescatados;
    Grafo *grafo;
    Auto *vehiculo;
    coordenada posicion_animales[MAX_ANIMALES];

//Métodos:
public:

    //Pre: -
    //Post: construirá el mapa de juego disponible.
    Mapa(Auto *vehiculo);

    //Pre: el mapa debe estar previamente cargado.
    //Post: mostrara el mapa disponible por pantalla.
    void mostrar_mapa();

    //Pre: -
    //Post: Devuelve el vector "animales" del Mapa.
    Animal* obtener_vector_animales(); 

    //Pre: -
    //Post: Muestra en una lista los animales que deben ser rescatados.
    void mostrar_listado_animales();

    //Pre: "indice" debe ser inicializado previamente.
    //Post: Le asigna el valor correspondiente a "fila" y "columna", representando la posición en la que se encuentre el animal del vector "animales_a_rescatar" 
    //que se encuentre en el indice ingresado.
    void obtener_coords_animal(int indice, int &fila, int &columna);

    //Pre: -
    //Post: Devuelve la cantidad de animales que aun no han sido rescatados.
    int animales_sin_rescatar();

    //Pre: "indice" debe ser inicializado previamente.
    //Post: Se encarga de eliminar el animal rescatado de la lista de animales por rescatar y devuelve dicho animal.
    Animal* rescatar_animal(int indice);

    //Pre: 
    //  + fila_origen y columna_origen deben corresponder a las coordenadas que el auto tenga en el terreno.
    //  + fila_destino y columna_destino deben corresponder a las coordenadas de la ubicación que debería moverse el auto en el terreno.
    //Post: devuelve el costo que tendrá en combustible el auto para moverse de su lugar de origen al destino.
    int costo_viaje(int fila_origen, int columna_origen, int fila_destino, int columna_destino);

    //Pre: fila y columna deben ser coordenadas válidas y ambos vectores, filas_camino y columnas_camino, deben ser inicializados previamente.
    //Post: Devolverá true en caso de que la fila y columna ingresada corresponda a alguna de las coordenadas del camino minimo.
    bool fue_recorrido(int fila, int columna, int filas_camino[MAX_MATRIZ], int columnas_camino[MAX_MATRIZ], int cantidad_recorrida);
    
    //Pre: 
    //  + fila_origen y columna_origen deben corresponder a las coordenadas que el auto tenga en el terreno.
    //  + fila_destino y columna_destino deben corresponder a las coordenadas de la ubicación que debería moverse el auto en el terreno.
    //Post: consigue las coordenadas de cada lugar que va ocupando el auto desde su lugar de origen hasta llegar al destino, y lo marca en el mapa, mostrandoselo al usuario.
    void marcar_camino_recorrido(int fila_origen, int columna_origen, int fila_destino, int columna_destino);

    //Destructor
    //Pre: -
    //Post: Libera la memoria ocupada por el Mapa y sus atributos.  
    ~Mapa();

private:

    //Pre: "indice" debe ser inicializado previamente.
    //Post: 
    void viajar(int indice);

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
    //Post: Crea un animal de la especie correspondiente a la generada de manera random, guardandolo en el vector "animales".
    void cargar_animal(int numero, Animal* &animal_random, string nombre, string tamanio, string personalidad, int edad);

    //Pre: "especies" debe estar inicializado, al igual que "numero".
    //Post: Genera especies de manera random hasta llegar a una que no se encuentre repetida.
    void validar_especie(int especies[MAX_ANIMALES], int &numero, int numero_animal);

    //Pre: "especies" debe estar inicializado, al igual que "numero".
    //Post: Verifica que el numero ingresado no se repita, para que las especies de los animales sean diferentes.
    bool ya_salio(int especies[MAX_ANIMALES], int numero);

    //Pre: Todos los parametros deben ser previamente inicializados.
    //Post: Guarda la posición de cada animal en el indice del vector correspondiente-
    void guardar_posicion_animales(int indice, int fila, int columna);

    //Pre: fila y columna deben estar dentro del rango de MAX_TERRENO
    //Post: devuelve true en el caso de que la fila y la columna pasadas por parámetro coincidan con la ubicación del auto en el terreno. Devuelve false en caso contrario.
    bool esta_auto(int fila, int columna);

    //Pre: -
    //Post: Ubica de manera random cada animal en una posición del terreno, corroborando que no se encuentre en la misma posición que el auto u otro animal. 
    void ubicar_animal(int i, Animal* animal, Grafo* grafo);

    //Pre: Tanto "rango" como "minimo" deben estar inicializados.
    //Post: Genera un numero random respetando el rango y el minimo ingresado. 
    int numero_random(int rango, int minimo);

    //Pre: Tanto "fila" como "columna" deben tener valores válidos.
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

    //Pre: los vectores filas_camino y columnas_camino más el parámetro cantidad_recorrida deben estar inicializados y cargados anteriormente.
    //Post: remarca en el terreno el camino mínimo que siguió el auto para rescatar al animal solicitado por el usuario.
    void remarcar_terreno(int filas_camino[MAX_MATRIZ], int columnas_camino[MAX_MATRIZ], int cantidad_recorrida);

};  

#endif //_MAPA_HPP