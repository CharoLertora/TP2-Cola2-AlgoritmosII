#ifndef _MENU_HPP_
#define _MENU_HPP_
#include <iostream>
#include "Lista.hpp"
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

//Precondciones:
//Postcondiciones: Imprime por pantalla el menu del programa
void mostrar_menu();

//Precondciones:
//Postcondiciones: Dependiendo de la opcion, se accede a distinas funcionalidades del programa
void procesar_opcion(Lista *lista_animales, int opcion);

//Precondciones:
//Postcondiciones: Devuelve la opcion ingresada por el usuario
int pedir_opcion();

//Precondciones:
//Postcondiciones: Valida que la opcion sea valida en el menu, sino vuelve a preguntar
void validar_opcion(int &opcion);

#endif