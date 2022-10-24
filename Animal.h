#ifndef _ANIMAL_H_
#define _ANIMAL_H_

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
    Animal(string nombre, int edad, string tamanio, string especie, string personalidad);
    void alimentar();
    void baniar();
    void asignar_edad(int edad);
    void asignar_nombre(string nombre);
    void asignar_especie(string especie);
    void asignar_tamanio(string tamanio);
    void asignar_personalidad(string personalidad);
    int obtener_edad();
    int obtener_higiene();
    int obtener_hambre();
    string obtener_nombre();
    string obtener_especie();
    string obtener_tamanio();
    string obtener_personalidad();
    void aumentar_hambre();
    void reducir_higiene();
    string obtener_comida();
};

#endif