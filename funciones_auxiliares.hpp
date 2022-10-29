#ifndef _FUNCIONES_AUXILIARES_
#define _FUNCIONES_AUXILIARES_
#include "Lista.hpp"
#include <string>
#include "Sistema.hpp"

bool es_nombre_existente(string nombre_buscado, Lista *lista, int &posicion_buscado);

bool es_respuesta_valida(string respuesta);

string especie_a_inicial(string especie);

void mostrar_datos_animal(Animal *animal);

bool existe_en_la_reserva(Lista *lista, string nombre);

bool quiere_ingresar_otro_nombre();

void validar_nombre(Lista *lista, string &nombre);

void validar_tamanio(string &tamanio);

void validar_personalidad(string &personalidad);

void validar_especie(string &especie);

bool hay_letras_en_edad(string edad);

void validar_edad(string &edad);

void preguntar_datos_animal(string &nombre, string &edad, string &tamanio, string &especie, string &personalidad,Lista* lista_animales);

void revisar_lista_animales(Lista *lista, string &nombre_buscado, int &posicion_buscado);

void realizar_adopcion(Lista *lista);

void pedir_respuesta(int &opcion);

void realizar_cuidado(int opcion, Animal* animal);

void validar_espacio(string &espacio);

#endif //_FUNCIONES_AUXILIARES_HPP_