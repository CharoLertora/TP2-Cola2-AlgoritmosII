#include "../include/funciones_del_menu.hpp"
#include "../include/Sistema.hpp"
#include <fstream>
#include <sstream>

using namespace std;

void mostrar_menu() {

    cout << endl << endl << endl;
    cout  << "\t" <<'\t' << "MENU" << endl
    << '\t' << "1. Listar animales" << endl
    << '\t' << "2. Rescatar animal" << endl
    << '\t' << "3. Buscar animal" << endl
    << '\t' << "4. Cuidar animal" << endl
    << '\t' << "5. Adoptar animal" << endl
    << '\t' << "6. Guardar y salir" << endl;
}

int pedir_opcion() {

    int opcion;
    cout << "\n" << '\t' << "¿Qué acción quiere realizar?" << endl;
    cin >> opcion;
    
    return opcion;
}

void validar_opcion(int &opcion) {

    bool es_opcion_valida = opcion > 0 && opcion < CANTIDAD_DE_OPCIONES;

    while(!es_opcion_valida){
        cout << "La opción elegida no es válida, por favor intente de nuevo: " << endl;
        cin >> opcion;
        es_opcion_valida = opcion > 0 && opcion < CANTIDAD_DE_OPCIONES;
    }
}

void mostrar_submenu() {

    cout << endl << endl;
    cout << '\t' << "1. Elegir indivualmente a qué animales cuidar" << endl
    << '\t' << "2. Alimentar a todos los animales" << endl
    << '\t' << "3. Bañar a todos los animales" << endl
    << '\t' << "4. Regresar al inicio" << endl;
}

void validar_opcion_submenu(int &opcion) {

    bool es_opcion_valida = opcion > 0 && opcion < CANTIDAD_DE_OPCIONES_SUBMENU;

    while(!es_opcion_valida){

        cout << "La opción elegida no es válida, por favor intente de nuevo: " << endl;
        cin >> opcion;
        es_opcion_valida = opcion > 0 && opcion < CANTIDAD_DE_OPCIONES_SUBMENU;
    }
}

void procesar_opcion_submenu(Sistema sistema, int opcion) {

    switch(opcion) {

        case ELEGIR_INDIVIDUALMENTE:
            sistema.elegir_individualmente(sistema.obtener_lista_animales());
            break;

        case ALIMENTAR_TODOS:
            sistema.alimentar_animales(sistema.obtener_lista_animales());
            break;

        case BANIAR_TODOS:
            sistema.baniar_animales(sistema.obtener_lista_animales());
            break;
    }
}

void abrir_submenu(Sistema sistema) {

    mostrar_submenu();
    int opcion = pedir_opcion();
    validar_opcion_submenu(opcion);

    while(opcion != REGRESAR_INICIO){

        procesar_opcion_submenu(sistema, opcion);
        mostrar_submenu();
        opcion = pedir_opcion();
        validar_opcion_submenu(opcion);
    }
}

void procesar_opcion(Sistema sistema, int opcion) {

    sistema.cambiar_hambre_higiene(sistema.obtener_lista_animales());

    switch(opcion){

        case LISTAR_ANIMALES:
            sistema.listar_animales(sistema.obtener_lista_animales());
            break;

        case RESCATAR_ANIMAL:
            sistema.rescatar_animal(sistema.obtener_lista_animales());
            break;

        case BUSCAR_ANIMAL:
            sistema.buscar_animal(sistema.obtener_lista_animales());
            break;

        case CUIDAR_ANIMALES:
            abrir_submenu(sistema);
            break;
            
        case ADOPTAR_ANIMAL:
            sistema.adoptar_animal(sistema.obtener_lista_animales());
            break;
    }
}