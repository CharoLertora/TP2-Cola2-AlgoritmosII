#include "menu.hpp"
#include "listar_animales.hpp"
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

void procesar_opcion(Lista &lista_animales, int opcion){

    switch(opcion){
        case LISTAR_ANIMALES:
            listar_animales(lista_animales);
            break;
        case RESCATAR_ANIMAL:
            //funcion rescartar animal
            break;
        case BUSCAR_ANIMAL:
            //funcion buscar animal
            break;
        case CUIDAR_ANIMAL:
            //funcion cuidar animal
            break;
        case ADOPTAR_ANIMAL:
            //funcion adoptar
            break;
        case GUARDAR_Y_SALIR:
            //funcion guardar y salir
            break;
    }
}

int pedir_opcion(){
    int opcion;
    cout << "\n" << '\t' << "Que accion queres realizar?" << endl;
    cin >> opcion;
    
    return opcion;
}

void validar_opcion(int &opcion){
    bool es_opcion_valida = opcion > 0 && opcion <= CANTIDAD_DE_OPCIONES;
    while(!es_opcion_valida){
        cout << "La opcion elegida no es valida, por favor intente de nuevo: " << endl;
        cin >> opcion;
        es_opcion_valida = opcion > 0 && opcion < CANTIDAD_DE_OPCIONES;
    }
}

