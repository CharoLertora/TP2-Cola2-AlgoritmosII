#ifndef _ANIMAL_HPP_
#define _ANIMAL_HPP_

#include <string>

const int HAMBRE_MINIMA = 0;
const int HAMBRE_MAXIMA = 100;
const int HIGIENE_MINIMA = 0;
const int HIGIENE_MAXIMA = 100;
const int AUMENTO_HAMBRE = 10;
const int REDUCCION_HIGIENE = 10;

using namespace std;

class Animal {

    //Atributos:
protected:
    string nombre;
    string tamanio;
    string especie;
    string personalidad;
    string comida;
    bool requiere_ducha;
    bool eliminado;
    int edad;
    int hambre;
    int higiene;

    // Métodos:
public:

    //Constructor sin parametros
    //pre: - 
    //pos: Construye un objeto animal con el hambre en 0, la higiene en 100 y ocupado en false.
    Animal();

    //Constructor con parametros
    //pre: - 
    //pos: Construye un objeto animal con su respectivo nombre, edad, tamanio, especie y personalidad, con el hambre en 0, la higiene en 100 y ocupado en false.
    Animal(string nombre, int edad, string tamanio, string especie, string personalidad);

    //pre: -
    //pos: Atributo hambre del animal vuelve a 0%.
    void alimentar();

    //pre: -
    //pos: Atributo higiene del animal vuelve a 100%.
    void baniar();

    //pre: -
    //pos: Devuelve el atributo requiere_ducha del animal.
    bool obtener_requiere_ducha();

    //pre: -
    //pos: Devuelve el atributo edad del animal.
    int obtener_edad();

    //pre: -
    //pos: Devuelve el atributo higiene del animal.
    int obtener_higiene();

    //pre: -
    //pos: Devuelve el atributo hambre del animal.
    int obtener_hambre();

    //pre: -
    //pos: Devuelve el atributo nombre del animal.
    string obtener_nombre();

    //pre: -
    //pos: Devuelve el especie higiene del animal.
    string obtener_especie();

    //pre: -
    //pos: Devuelve el tamanio higiene del animal.
    string obtener_tamanio();

    //pre: -
    //pos: Devuelve el atributo personalidad del animal.
    string obtener_personalidad();

    //pre: -
    //pos: Aumenta el hambre del animal segun su personalidad.
    void aumentar_hambre();

    //pre: -
    //pos: Reduce la higiene del animal segun su personalidad.
    void reducir_higiene();

    //pre: -
    //pos: Devuelve el atributo comida del animal.
    string obtener_comida();

    bool esta_eliminado();

    void eliminar();
};

#endif