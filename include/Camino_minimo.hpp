#ifndef _CAMINO_MINIMO_HPP_
#define _CAMINO_MINIMO_HPP_
#include <iostream>
#include <string>

class Camino_minimo {
    //Atributos
    private:
        int** matriz_adyacencia;
        int** distancias;
        int** caminos;
    
    //Métodos
    public:

        Camino_minimo(int** matriz_grafo);

        void inicializar_matrices();

        void calcular_caminos_minimos();

        void mostrar_matrices();

        void liberar_matrices();

        int calcular_costo(int origen, int destino);

        void mostrar_camino(int origen, int destino);

        ~Camino_minimo();        

};


#endif // _CAMINO_MINIMO_HPP_