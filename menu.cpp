#include "menu.hpp"
#include "sistema.hpp"
#include <fstream>
#include <sstream>
using namespace std;

void mostrar_menu(){
    cout << endl << endl << endl;
    cout  << "\t" <<'\t' << "MENU" << endl
    << '\t' << "1. Listar animales" << endl
    << '\t' << "2. Rescatar animal" << endl
    << '\t' << "3. Buscar animal" << endl
    << '\t' << "4. Cuidar animal" << endl
    << '\t' << "5. Adoptar animal" << endl
    << '\t' << "6. Guardar y salir" << endl;
}


int pedir_opcion(){
    int opcion;
    cout << "\n" << '\t' << "¿Qué acción quiere realizar?" << endl;
    cin >> opcion;
    
    return opcion;
}

void validar_opcion(int &opcion){
    bool es_opcion_valida = opcion > 0 && opcion < CANTIDAD_DE_OPCIONES;
    while(!es_opcion_valida){
        cout << "La opción elegida no es válida, por favor intente de nuevo: " << endl;
        cin >> opcion;
        es_opcion_valida = opcion > 0 && opcion < CANTIDAD_DE_OPCIONES;
    }
}

void mostrar_submenu(){
    cout << endl << endl;
    cout << '\t' << "1. Elegir indivualmente a qué animales cuidar" << endl
    << '\t' << "2. Alimentar a todos los animales" << endl
    << '\t' << "3. Bañar a todos los animales" << endl
    << '\t' << "4. Regresar al inicio" << endl;
}

void validar_opcion_submenu(int &opcion){
    bool es_opcion_valida = opcion > 0 && opcion < CANTIDAD_DE_OPCIONES_SUBMENU;
    while(!es_opcion_valida){
        cout << "La opción elegida no es válida, por favor intente de nuevo: " << endl;
        cin >> opcion;
        es_opcion_valida = opcion > 0 && opcion < CANTIDAD_DE_OPCIONES_SUBMENU;
    }
}

void procesar_opcion_submenu(Lista* lista_animales, int opcion){
    switch(opcion){
        case ELEGIR_INDIVIDUALMENTE:
            elegir_individualmente(lista_animales);
            break;
        case ALIMENTAR_TODOS:
            alimentar_animales(lista_animales);
            break;
        case BANIAR_TODOS:
            //baniar_animales(lista_animales);
            break;
    }
}

void abrir_submenu(Lista *lista){
    mostrar_submenu();
    int opcion = pedir_opcion();
    validar_opcion_submenu(opcion);
    while(opcion != REGRESAR_INICIO){
        procesar_opcion_submenu(lista, opcion);
        mostrar_submenu();
        opcion = pedir_opcion();
        validar_opcion_submenu(opcion);
    }
}

void procesar_opcion(Lista *lista_animales, int opcion){
    cambiar_hambre_higiene(lista_animales);
    switch(opcion){
        case LISTAR_ANIMALES:
            listar_animales(lista_animales);
            break;
        case RESCATAR_ANIMAL:
            rescatar_animal(lista_animales);
            break;
        case BUSCAR_ANIMAL:
            buscar_animal(lista_animales);
            break;
        case CUIDAR_ANIMALES:
            abrir_submenu(lista_animales);
            break;
        case ADOPTAR_ANIMAL:
            adoptar_animal(lista_animales);
            break;
        case GUARDAR_Y_SALIR:
            //funcion guardar y salir
            break;
    }
}