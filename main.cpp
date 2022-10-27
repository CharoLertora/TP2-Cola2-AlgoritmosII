#include <iostream>
#include "sistema.h"
#include "menu.hpp"

int main() {

    Lista* lista = new Lista; 
    llenar_lista(lista);

    mostrar_menu();
    int opcion = pedir_opcion();
    validar_opcion(opcion);
    while(opcion != GUARDAR_Y_SALIR){
        procesar_opcion(lista, opcion);
        mostrar_menu();
        opcion = pedir_opcion();
        validar_opcion(opcion);
    }
    return 0;

    //buscar_animal(lista);
    
    //lista.~Lista();

}