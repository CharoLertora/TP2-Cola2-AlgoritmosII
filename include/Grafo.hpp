#ifndef _GRAFO_HPP_
#define _GRAFO_HPP_

#include "Camino_minimo.hpp"


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
class Grafo {
    //Atributos:
private:
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

    ~Grafo();

};



#endif