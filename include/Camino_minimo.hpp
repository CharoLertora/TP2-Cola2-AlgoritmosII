#ifndef _CAMINO_MINIMO_HPP_
#define _CAMINO_MINIMO_HPP_
#include <iostream>
#include <string>
#include "Vertice.hpp"
#include "Lista.hpp"

class Camino_minimo {
    //Atributos
    private:
        int** matriz_adyacencia;
        Lista* vertices;
        int cantidad_vertices;
        bool* vertices_visitados;
        int* distancia;
        int* recorrido;
    
    //Métodos
    public:
        Camino_minimo(Lista* vertices, int** matriz_adyacencia);

        ~Camino_minimo();

};


#endif // _CAMINO_MINIMO_HPP_