#ifndef _ANIMAL_HPP_
#define _ANIMAL_HPP_

#include <string>

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
    int edad;
    int hambre;
    int higiene;

    // Métodos:
public:

    //Constructor con parametros
    //pre: - 
    //pos: Construye un objeto animal con su respectivo nombre, edad, tamanio, especie y personalidad
    Animal(string nombre, int edad, string tamanio, string especie, string personalidad);

    //pre: -
    //pos: Atributo hambre del animal vuelve a 0.
    void alimentar();

    //pre: -
    //pos: Atributo higiene del animal vuelve a 100.
    void baniar();

    //pre: - 
    //pos: Atributo edad del animal es igual al int edad pasada por parametro.
    void asignar_edad(int edad);

    //pre: -
    //pos: Atributo nombre del animal es igual al string nombre pasado por parametro.
    void asignar_nombre(string nombre);

    //pre: -
    //pos: Atributo especie del animal es igual a string especie pasado por parametro.
    void asignar_especie(string especie);

    //pre: -
    //pos: Atributo tamanio del animal es igual al string tamanio pasado por parametro.
    void asignar_tamanio(string tamanio);

    //pre: -
    //pos: Atributo personalidad del animal es igual al string personalidad pasado por parametro.
    void asignar_personalidad(string personalidad);

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
};

#endif