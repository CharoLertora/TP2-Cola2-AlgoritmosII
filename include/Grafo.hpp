#ifndef _GRAFO_HPP_
#define _GRAFO_HPP_
//#include "Vertice.hpp"
//#include "Lista.hpp"
#include "Camino_minimo.hpp"
//#include "Mapa.hpp"

using namespace std;

const string TIERRA = "🌳"; 
const string CAMINO = "🟨";
const string MONTANIA = "⛰️ ";
const string PRECIPICIO = "🕳 ";
const string AUTO = "🚘";
const int COSTO_MONTANIA = 5;
const int COSTO_PRECIPICIO = 40;
const int COSTO_CAMINO = 1;
const int COSTO_TIERRA = 2;

const int MAX_TERRENO = 8;
const int MAX_MATRIZ = MAX_TERRENO * MAX_TERRENO;
const int INFINITO = 99;
class Grafo {
    //Atributos:
private:
    //Lista *vertices; 
    int** matriz_adyacencia;
    Camino_minimo* algoritmo;

    //Métodos:
public:
    Grafo();

    Grafo(string terreno[MAX_TERRENO][MAX_TERRENO]);

    void calcular_adyacentes(int** matriz_adyacencia, int fila, int col, string terreno[MAX_TERRENO][MAX_TERRENO]);
    
    void mostrar_matriz_adyacencia(int** matriz_adyacencia);

    void inicializar_matriz_adyacencia();

    void cargar_matriz();

    int calcular_vertice(int fila, int columna);

    bool es_vertice_valido(int fila, int columna);

    int calcular_camino_minimo(int origen, int destino);

    void liberar_matriz_adyacente();
/*
    void agregar_vertice(int numero);

    //Pre: -
    //Post: agranda dinámicamente la matriz de adyacencia.
    void agrandar_matriz_adyacencia();

    //Pre: la matriz que se le envíe deberá tener su memoria reservada previamente.
    //Post: copia la matriz de adyacencia en la nueva matriz.
    void copiar_matriz_adyacente(int **nueva_matriz);

    //Pre: -
    //Post: inicializa un nuevo vértice en la matriz de adyacencia con un valor de infinito y completa la diagonal de 0.
    void inicializar_nuevo_vertice(int** nueva_matriz);

    //Pre: -
    //Post: libera la memoria de la matriz de adyacencia.
    void liberar_matriz_adyacente();

    //Pre: el peso tiene que ser un valor positivo.
    //Post: Ajusta la matriz de adyacencia con el peso ingresado.
    void agregar_camino(int numero_origen, int numero_destino, int peso);

    
     *Pre: 
        + Se debe tener un algoritmo para calcular el camino mínimo previamente elegido.
        + Tienen que existir tanto el origen como el destino.
     *Post: muestra el camino mínimo desde un origen a un destino.
    
    void camino_minimo(int numero_origen, int numero_destino);
    
    //Pre: -
    //Post: utilizará el algoritmos de Dijkstra para que crear el camino mínimo entre vértices.
    void crear_algoritmo_camino();
*/

    ~Grafo();

};



#endif