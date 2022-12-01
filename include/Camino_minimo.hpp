#ifndef _CAMINO_MINIMO_HPP_
#define _CAMINO_MINIMO_HPP_
#include <iostream>
#include <string>
//#include "Vertice.hpp"
//#include "Lista.hpp"
//#include "Grafo.hpp"


class Camino_minimo {
    //Atributos
    private:
        int** matriz_adyacencia;
        //Lista* vertices;
        //int cantidad_vertices;
        //bool* vertices_visitados;
        int** distancias;
        int** caminos;
    
    //Métodos
    public:

        Camino_minimo(int** matriz_grafo);

        void inicializar_matrices();

        void calcular_caminos_minimos();

        void mostrar_matrices();

        void liberar_matrices();

        ~Camino_minimo();
/*
        //Pre: la lista de vértices y la matriz de adyacencia deben estar previamente cargadas.
        //Post: inicializará los atributos de la clase Camino_mínimo.
        Camino_minimo(Lista* vertices, int** matriz_adyacencia);

        //Pre: -
        //Post: muestra por pantalla el camino mínimo entre el origen y el destino, detallando su recorrido y peso. (HACER)
        void camino_minimo(int origen, int destino);

        //Pre: -
        //Post: pone todos los valores del vector vertices_visitados en "false" menos el origen.
        void inicializar_visitados(int numero_origen);

        //Pre: -
        //Post: pone las distancias igual que infinito a excepción de la distancia del origen hacia él mismo, que será igual a 0.
        void inicializar_distancias(int numero_origen);

        //Pre: -
        //Post: llena el vector de recorrido con -1 (posición no encontrada).
        void inicializar_recorrido();
*/
        

};


#endif // _CAMINO_MINIMO_HPP_