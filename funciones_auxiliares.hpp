#ifndef _FUNCIONES_AUXILIARES_
#define _FUNCIONES_AUXILIARES_
#include "Lista.hpp"
#include <string>
#include <iostream>
#include "Sistema.hpp"

using namespace std;

bool es_nombre_existente(string nombre_buscado, Lista *lista, int &posicion_buscado);

bool es_respuesta_valida(string respuesta);

//pre:
//pos: Devuelve un string con la inicial del animal correspondiente
string especie_a_inicial(string especie);

//Pre: 
//Pos: Muestra por pantalla el animal con sus datos.
void mostrar_datos_animal(Animal *animal);

//pre:
//pos: Devuelve la variable booleana 'existe_en_reserva' con verdadero si el animal existe en la reserva, sino falso.
bool existe_en_la_reserva(Lista *lista, string nombre);

//pre:
//pos: Devuelve la variable booleana 'quiere_ingresar_otro' con verdadero si el usuario quiere ingresar otro nombre, sino falso.
bool quiere_ingresar_otro_nombre();

//pre:
//pos: Valida que el nombre no este en el refugio hasta que el nombre ingresdo no este en la reserva.
void validar_nombre(Lista *lista, string &nombre);

//pre:
//pos: Valida el tamaño hasta que sea valido
void validar_tamanio(string &tamanio);

//pre:
//pos: Valida la personalidad hasta que sea valida
void validar_personalidad(string &personalidad);

//pre:
//pos: Valida la especie hasta que sea valida
void validar_especie(string &especie);

//pre:
//pos: Devuelve la variable booleana 'hay_letras' con verdadero si hay caracteres que no son numericos, sino falso.
bool hay_letras_en_string(string edad);

//pre:
//pos: Valida la edad hasta que sea válida.
void validar_edad(string &edad);

//pre:
//pos: Pregunta al usuario los datos del animal y valida que sean validos.
void preguntar_datos_animal(string &edad, string &tamanio, string &especie, string &personalidad,Lista* lista_animales);

void revisar_lista_animales(Lista *lista, string &nombre_buscado, int &posicion_buscado);

void realizar_adopcion(Lista *lista);

//pre:
//pos: Le pregunta al usuario si desea cuidar al animal o saltearlo y una vez que su respuesta es vàlida, la guarda.
void pedir_respuesta(int &opcion);

//pre:
//pos: Dependiendo la opción seleccionada, baña o alimenta al animal ingresado.
void realizar_cuidado(int opcion, Animal* animal);

void validar_espacio(string &espacio);

#endif //_FUNCIONES_AUXILIARES_HPP_