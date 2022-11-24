#ifndef _GRAFO_HPP_
#define _GRAFO_HPP_
#include "Vertice.hpp"
#include "Lista.hpp"
#include "Camino_minimo.hpp"

const int INFINITO = 999999;
class Grafo {
    //Atributos:
private:
    Lista *vertices; 
    int** matriz_adyacencia;
    Camino_minimo* algoritmo;

    //Métodos:
public:
    Grafo();

    void agregar_vertice(int numero, string tipo_terreno);
    
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
    void agregar_camino(int origen, int destino, int peso);

    ~Grafo();

};



#endif