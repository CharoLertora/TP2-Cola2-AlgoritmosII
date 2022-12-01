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
    bool adoptado;
    int edad;
    int hambre;
    int higiene;

    // Métodos:
public:

    //Constructor sin parametros
    //Pre: - 
    //Post: Construye un objeto animal con el hambre en 0, la higiene en 100 y ocupado en false.
    Animal();

    //Constructor con parametros
    //Pre: - 
    //Post: Construye un objeto animal con su respectivo nombre, edad, tamanio, especie y personalidad, con el hambre en 0, la higiene en 100 y ocupado en false.
    Animal(string nombre, int edad, string tamanio, string especie, string personalidad);

    //Pre: -
    //Post: Atributo hambre del animal vuelve a 0%.
    void alimentar();

    //Pre: -
    //Post: Atributo higiene del animal vuelve a 100%.
    void baniar();

    //Pre: -
    //Post: Devuelve el atributo requiere_ducha del animal.
    bool obtener_requiere_ducha();

    //Pre: -
    //Post: Devuelve el atributo edad del animal.
    int obtener_edad();

    //Pre: -
    //Post: Devuelve el atributo higiene del animal.
    int obtener_higiene();

    //Pre: -
    //Post: Devuelve el atributo hambre del animal.
    int obtener_hambre();

    //Pre: -
    //Post: Devuelve el atributo nombre del animal.
    string obtener_nombre();

    //Pre: -
    //Post: Devuelve el especie higiene del animal.
    string obtener_especie();

    //Pre: -
    //Post: Devuelve el tamanio higiene del animal.
    string obtener_tamanio();

    //Pre: -
    //Post: Devuelve el atributo personalidad del animal.
    string obtener_personalidad();

    //Pre: El string ingresado debe estar inicializado y ser válido.
    //Post: Asigna el string ingresado como nombre del animal.
    void asignar_nombre(string nombre);

    //Pre: -
    //Post: Aumenta el hambre del animal segun su personalidad.
    void aumentar_hambre();

    //Pre: -
    //Post: Reduce la higiene del animal segun su personalidad.
    void reducir_higiene();

    //Pre: -
    //Post: Devuelve el atributo comida del animal.
    string obtener_comida();

    bool esta_eliminado();

    bool esta_adoptado();

    void eliminar();

    void adoptar();
};

#endif