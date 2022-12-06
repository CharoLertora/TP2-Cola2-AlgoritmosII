#ifndef _GRAFO_HPP_
#define _GRAFO_HPP_

#include "camino_minimo.hpp"

using namespace std;

class Grafo {
    //Atributos:
private:
    int** matriz_adyacencia;
    Camino_minimo* algoritmo;

    //Métodos:
private: 
    
    //Pre: la matriz de adyacencia debe estar previamente inicializada
    //Post: carga la matriz adyacente del grafo con todos sus vértices correspondientes al terreno.
    void calcular_adyacentes(int** matriz_adyacencia, int fila, int col, string terreno[MAX_TERRENO][MAX_TERRENO]);
    
    //Pre: la matriz de adyacencia debe estar previamente cargada.
    //Post: muestra la matriz de adyacencia por pantalla.
    void mostrar_matriz_adyacencia(int** matriz_adyacencia);

    //Pre: - 
    //Post: inicializa la matriz de adyacencia del grafo.
    void inicializar_matriz_adyacencia();

    //Pre: -
    //Post: carga la matriz adyacente del grafo con todos sus vértices en infinito y la diagonal principal en 0.
    void cargar_matriz();
    
    //Pre: -
    //Post: verifica que la fila y la columna del terreno que se pasan por parámetro, estén dentro del rango de MAX_TERRENO.
    bool es_vertice_valido(int fila, int columna);

    //Pre: -
    //Post: liberá la memoria ocupada por la matriz de adyacencia del grafo.
    void liberar_matriz_adyacente();

public:

    //Pre: -
    //Post: construye un grafo sin parámetros.
    Grafo();

    //Pre: el parámetro terreno debe estar inicializado y estar cargado previamente.
    //Post: construye un grafo con parámetros.
    Grafo(string terreno[MAX_TERRENO][MAX_TERRENO]);

    //Pre: -
    //Post: calculará el vértice correspondiente según la fila y la columna del terreno que se estén pasando como parámetros.
    int calcular_vertice(int fila, int columna);

    //Pre: origen y destino deben ser vértices existentes en la matriz adyacente del grafo.
    //Post: calcula el costo mínimo que tendrá el camino desde el origen hasta el destino pasados por parámetro.
    int calcular_camino_minimo(int origen, int destino);

    void calcular_coordenadas_camino(int origen, int destino, int filas_camino[MAX_MATRIZ], int columnas_camino[MAX_MATRIZ], int &cantidad_recorrida);

    //Pre: -
    //Post: destructor del grafo. Libera la memoria solicitada para la creación del grafo.
    ~Grafo();

};

#endif