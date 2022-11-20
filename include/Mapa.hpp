#ifndef _MAPA_HPP_
#define _MAPA_HPP_

using namespace std;

const int MAX_TERRENO = 8;
const char TIERRA = 'T'; 
const char CAMINO = 'C';
const char MONTANIA = 'M';
const char PRECIPICIO = 'P';

class Mapa {

    //Atributos:
    private:
        char terreno[MAX_TERRENO][MAX_TERRENO];

    //Métodos:
    public:

        //Pre: -
        //Post: construirá el mapa de juego disponible.
        Mapa();

        //Pre: el mapa debe estar previamente cargado.
        //Post: mostrara el mapa disponible por pantalla.
        void mostrar_mapa();

        //Pre: La matriz debe estar inicializada y cargada con toda la información necesaria previamente.
        //Post: Devolverá el tipo de terreno que representa la casilla en la que se encuentra.
        char obtener_tipo_terreno();
    
};  

#endif //_MAPA_HPP