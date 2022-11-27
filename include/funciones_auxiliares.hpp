#ifndef _FUNCIONES_AUXILIARES_
#define _FUNCIONES_AUXILIARES_
#include <string>
#include <iostream>
#include "Sistema.hpp"

using namespace std;


// pre: -
// pos: devolverá true en caso de que 'nombre_buscado' sea igual a alguno de los nombres no eliminados de la lista de animales, o false en caso contrario.
bool es_nombre_existente(string nombre_buscado, Arbol_B *arbol);

//pre: -
//pos: va a devolver true en caso de que la respuesta coincida con si/Si, y false en cualquier otro caso.
bool es_respuesta_valida(string respuesta);

//pre: 'nombre' debe estar previamente inicializado y contener algún valor.
//pos: devolverá true si el animal ya existe en la reserva, sino false.
bool existe_en_la_reserva(Arbol_B *arbol, string nombre);

//pre: -
//pos: devolverá true si el usuario quiere ingresar otro nombre, sino false.
bool quiere_ingresar_otro_nombre();

//pre: -
//pos: Valida que 'nombre' no este en la lista de animalesn y pedirá uno nuevo hasta si es encontrado.
void validar_nombre(Arbol_B *arbol, string &nombre);

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

//pre: el parámetro "esta_adoptado" debe estar inicializado
//pos: devuelve un mensaje expresando el estado de adopción del animal.
string obtener_estado_adopcion(bool esta_adoptado);

//Pre: el parámetro '*animal' debe apuntar a una variable previamente inicializada y debe contener valores válidos.
//Pos: Muestra por pantalla el animal con sus datos.
void mostrar_datos_animal(Animal *animal);

//pre: los parámetros edad, tamanio, especie y personalidad deben estar previamente inicializados y ser pasados por referencia.
//pos: Pregunta al usuario los datos del animal y valida que sean correctos.
void preguntar_datos_animal(string &edad, string &tamanio, string &especie, string &personalidad);

/*
 * pre: 
    + 'nombre_buscado' debe estar previamente inicializado.

 * pos:
    + Va a recorrer la lista de animales y devolverá un msj. por pantalla al usuario según cada caso:
        - Avisará si la lista está vacía.
        - Avisará en el caso de que el nombre no se encuentre en la lista.
        - Avisará y mostrará los datos del animal en caso de que haya sido encontrado en la lista.
*/

//pre: 'espacio' debe estar previamente inicializado y ser pasado por referencia.
//pos: se encarga de verificar que el espacio ingresado por el usuario no contenga letras ni números negativos.
void validar_espacio(string &espacio);

void avisar_usuario_escapes(Animal *animal, int cantidad_de_escapes);

void imprimir_por_edad(Arbol_B* arbol);

#endif //_FUNCIONES_AUXILIARES_HPP_