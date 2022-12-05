#ifndef _CAMINO_MINIMO_HPP_
#define _CAMINO_MINIMO_HPP_
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

const string TIERRA = "🟨"; 
const string CAMINO = "⬜";
const string MONTANIA = "🟫";
const string PRECIPICIO = "⬛";
const string AUTO = "🚘";
const int COSTO_MONTANIA = 5;
const int COSTO_PRECIPICIO = 40;
const int COSTO_CAMINO = 1;
const int COSTO_TIERRA = 2;

const int MAX_TERRENO = 8;
const int MAX_MATRIZ = MAX_TERRENO * MAX_TERRENO;
const int INFINITO = 99;
const int POSICION_NO_ENCONTRADA = -1;
class Camino_minimo {
    //Atributos
    private:
        int** matriz_adyacencia;
        int** distancias;
        int** caminos;
    
    //Métodos
    private:
        
        //Pre: -
        //Post: muestra las matrices de distancias y caminos por pantalla.
        void mostrar_matrices();

        //Pre: -
        //Post: libera la memoria ocupada por las matrices del Camino_minimo.
        void liberar_matrices();

        int pasar_a_fila(int origen);

        int pasar_a_columna(int origen);

    public:

        //Pre: el parámetro matriz_grafo debe estar previamente inicializado y cargado.
        //Post: construye un Camino_minimo con parámetros.
        Camino_minimo(int** matriz_grafo);

        //Pre: -
        //Post: se encarga de inicializar las matrices de distancias y caminos del Camino_minimo.
        void inicializar_matrices();

        //Pre: las matrices de distancias y caminos deben estar previamente inicializadas.
        //Post: se encarga de cargar las matrices de distancias y caminos con sus valores correspondientes.
        void calcular_caminos_minimos();

        //Pre: los parámetros origen y destino deben corresponder a un vértice válido de la matriz de distancias.
        //Post: devuelve el costo que tendrá ir desde el origen al destino.
        int calcular_costo(int origen, int destino);

        //Pre: origen y destino deben corresponder a valores válidos de la matriz de caminos.
        //Post: mostrará el camino que recorre el auto con respecto a los vértices de la matriz de adyacencia.
        void mostrar_camino(int origen, int destino, int filas_camino[MAX_MATRIZ], int columnas_camino[MAX_MATRIZ], int &cantidad_recorrida);

        //Pre: -
        //Post: libera la memoria utilizada por el Camino_minimo.
        ~Camino_minimo();        

};

#endif // _CAMINO_MINIMO_HPP_