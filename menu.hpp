#ifndef MENU_HPP
#define MENU_HPP
#include <iostream>
#include "Lista.h"
#include "Perro.h"
#include "Gato.h"
#include "Lagartija.h"
#include "Erizo.h"
#include "Caballo.h"
#include "Roedor.h"
#include "Conejo.h"

enum Opcion_menu {
    LISTAR_ANIMALES = 1,
    RESCATAR_ANIMAL,
    BUSCAR_ANIMAL,
    CUIDAR_ANIMAL,
    ADOPTAR_ANIMAL,
    GUARDAR_Y_SALIR,
    CANTIDAD_DE_OPCIONES
};

//Precondciones:
//Postcondiciones: Imprime por pantalla el menu del programa
void mostrar_menu();

//Precondciones:
//Postcondiciones: Dependiendo de la opcion, se accede a distinas funcionalidades del programa
void procesar_opcion(Lista &lista_animales, int opcion);

//Precondciones:
//Postcondiciones: Devuelve la opcion ingresada por el usuario
int pedir_opcion();

//Precondciones:
//Postcondiciones: Valida que la opcion sea valida, sino vuelve a preguntar
void validar_opcion(int &opcion);

#endif