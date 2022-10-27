#include <iostream>
#include "sistema.hpp"
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
    guardar_y_salir(lista);
    delete lista;

    return 0;
}