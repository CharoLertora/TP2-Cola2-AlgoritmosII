#ifndef _GRAFO_HPP_
#define _GRAFO_HPP_
#include "Vertice.hpp"
#include "Lista.hpp"

const int VACIO = 0;

class Grafo {
    //Atributos:
private:
    Lista *vertices; 
    int cant_vertices;

    //Métodos:
public:

    Grafo();

    void agregar_vertice(int fila, int columna, string tipo_terreno);

    Lista* obtener_vertices();
    
    Vertice* encontrar_vertice(int fila, int columna);

    ~Grafo();
};

#endif //_GRAFO_HPP_