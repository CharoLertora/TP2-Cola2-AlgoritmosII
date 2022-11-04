#ifndef _MENU_HPP_
#define _MENU_HPP_
#include <iostream>
#include "Lista.hpp"
#include "Sistema.hpp"
#include "Perro.hpp"
#include "Gato.hpp"
#include "Lagartija.hpp"
#include "Erizo.hpp"
#include "Caballo.hpp"
#include "Roedor.hpp"
#include "Conejo.hpp"

enum Opcion_menu {
    LISTAR_ANIMALES = 1,
    RESCATAR_ANIMAL,
    BUSCAR_ANIMAL,
    CUIDAR_ANIMALES,
    ADOPTAR_ANIMAL,
    GUARDAR_Y_SALIR,
    CANTIDAD_DE_OPCIONES
};

enum Opcion_submenu {
    ELEGIR_INDIVIDUALMENTE = 1,
    ALIMENTAR_TODOS,
    BANIAR_TODOS,
    REGRESAR_INICIO,
    CANTIDAD_DE_OPCIONES_SUBMENU
};

//Pre: -
//Pos: Imprime por pantalla el menu del programa
void mostrar_menu();

//Pre: -
//Post: Devuelve la opcion ingresada por el usuario.
int pedir_opcion();

//Pre: 'opcion' debe ser pasada por referencia.
//Post: Valida que 'opcion' esté dentro de las opciones del menu, sino vuelve a preguntar.
void validar_opcion(int &opcion);

//Pre: -
//Post: Muestra por pantalla el submenu de la opción "Cuidar animales"
void mostrar_submenu();

//Pre: 'opcion' debe ser pasada por referencia.
//Post: Valida que 'opcion' esté dentro de las opciones del submenu, sino vuelve a preguntar.
void validar_opcion_submenu(int &opcion);

//Pre: 'opcion' debe estar previamente inicializado.
//Post: Dependiendo de la opcion, se accede a distintas funcionalidades del programa
void procesar_opcion(Sistema sistema, int opcion);

//Pre: 'opcion' debe estar previamente inicializado.
//Post: Dependiendo de la opcion, se accede a distintas funcionalidades del programa
void procesar_opcion_submenu(Sistema sistema, int opcion);

//Pre: 'sistema' debe estar previamente inicializado.
//Post: Lleva al usuario al submenu y procesará las diferentes respuestas mientras no vuelva al inicio
void abrir_submenu(Sistema sistema);

#endif //_MENU_HPP_