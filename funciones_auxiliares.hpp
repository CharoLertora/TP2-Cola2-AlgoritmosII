#ifndef _FUNCIONES_AUXILIARES_
#define _FUNCIONES_AUXILIARES_
#include "Lista.hpp"
#include <string>
#include <iostream>
#include "Sistema.hpp"

using namespace std;

/*
 * pre: 
    + El parámetro 'posicion_buscado' debe estar inicializado en 1.

 * pos: devolverá true en caso de que 'nombre_buscado' sea igual a alguno de los nombres de la lista de animales, o false en caso contrario.
*/
bool es_nombre_existente(string nombre_buscado, Lista *lista, int &posicion_buscado);

//pre: -
//pos: va a devolver true en caso de que la respuesta coincida con si/Si, y false en cualquier otro caso.
bool es_respuesta_valida(string respuesta);

//pre: el parámetro 'especie' debe estar previamente inicializado y debe contener valores válidos.
//pos: Devuelve un string con la inicial del animal correspondiente
string especie_a_inicial(string especie);

//Pre: el parámetro '*animal' debe apuntar a una variable previamente inicializada y debe contener valores válidos.
//Pos: Muestra por pantalla el animal con sus datos.
void mostrar_datos_animal(Animal *animal);

//pre: 'nombre' debe estar previamente inicializado y contener algún valor.
//pos: devolverá true si el animal ya existe en la reserva, sino false.
bool existe_en_la_reserva(Lista *lista, string nombre);

//pre: -
//pos: devolverá true si el usuario quiere ingresar otro nombre, sino false.
bool quiere_ingresar_otro_nombre();

//pre: -
//pos: Valida que 'nombre' no este en la lista de animalesn y pedirá uno nuevo hasta si es encontrado.
void validar_nombre(Lista *lista, string &nombre);

//pre: -
//pos: devolverá true en el caso de que 'tamanio' se encuentre dentro de las opciones permitidas, y false en caso contrario.
bool es_tamanio_valido(string tamanio);

//pre: -
//pos: verificará que 'tamanio' sea válida y, en caso de no cumplirse, se le solicitará al usuario que ingrese el valor nuevamente.
void validar_tamanio(string &tamanio);

//pre: -
//pos: devolverá true en el caso de que 'personalidad' se encuentre dentro de las opciones permitidas, y false en caso contrario.
bool es_personalidad_valida(string personalidad);

//pre: -
//pos: verificará que 'personalidad' sea válida y, en caso de no cumplirse, se le solicitará al usuario que ingrese el valor nuevamente.
void validar_personalidad(string &personalidad);

//pre: -
//pos: devolverá true en el caso de que 'especie' se encuentre dentro de las opciones permitidas, y false en caso contrario.
bool es_especie_valida(string especie);

//pre: -
//pos: verificará que la especie sea válida y, en caso de no cumplirse, se le solicitará al usuario que ingrese el valor nuevamente.
void validar_especie(string &especie);

//pre: -
//pos: Devuelve true si hay caracteres que no son numericos, sino false.
bool hay_letras(string edad);

//pre: -
//pos: Validará que la edad no contenga letras.
void validar_edad(string &edad);

//pre: los parámetros edad, tamanio, especie y personalidad deben estar previamente inicializados y ser pasados por referencia.
//pos: Pregunta al usuario los datos del animal y valida que sean correctos.
void preguntar_datos_animal(string &edad, string &tamanio, string &especie, string &personalidad,Lista* lista_animales);

/*
 * pre: 
    + 'nombre_buscado' debe estar previamente inicializado.
    + 'posicion_buscado' debe estar inicializado en 1.

 * pos:
    + Va a recorrer la lista de animales y devolverá un msj. por pantalla al usuario según cada caso:
        - Avisará si la lista está vacía.
        - Avisará en el caso de que el nombre no se encuentre en la lista.
        - Avisará y mostrará los datos del animal en caso de que haya sido encontrado en la lista.
*/
void revisar_lista_animales(Lista *lista, string &nombre_buscado, int &posicion_buscado);

//pre: -
//pos: Solicitará el nombre del animal a adoptar y, en el caso de que el usuario desee adoptarlo, se eleminará de la lista de animales.
void realizar_adopcion(Lista *lista);

//pre: 'opcion' debe estar previamente inicializado y ser pasado por referencia.
//pos: Le pregunta al usuario si desea cuidar al animal o saltearlo y una vez que su respuesta es vàlida, la guarda.
void pedir_respuesta(int &opcion);

//pre: los parámetros 'opcion' y 'animal' deben estar previamente inicializados y contener valores válidos.
//pos: Dependiendo la opción seleccionada, baña o alimenta al animal ingresado.
void realizar_cuidado(int opcion, Animal* animal);

//pre: 'espacio' debe estar previamente inicializado y ser pasado por referencia.
//pos: se encarga de verificar que el espacio ingresado por el usuario no contenga letras ni números negativos.
void validar_espacio(string &espacio);

#endif //_FUNCIONES_AUXILIARES_HPP_