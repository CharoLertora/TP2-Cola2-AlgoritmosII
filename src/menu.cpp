#include "../include/Sistema.hpp"
#include "../include/menu.hpp"
#include "../include/Mapa.hpp"
#include <fstream>
#include <sstream>

using namespace std;

void Menu::mostrar_menu() {

    cout << endl << endl << endl;
    cout  << "\t" <<'\t' << "MENU" << endl
    << '\t' << "1. Listar animales" << endl
    << '\t' << "2. Rescatar animal" << endl
    << '\t' << "3. Buscar animal" << endl
    << '\t' << "4. Cuidar animal" << endl
    << '\t' << "5. Adoptar animal" << endl
    << '\t' << "6. Cargar combustible" << endl
    << '\t' << "7. Guardar y salir" << endl;
}

int Menu::pedir_opcion() {

    int opcion;
    cout << "\n" << '\t' << "¿Qué acción quiere realizar?" << endl;
    cin >> opcion;
    
    return opcion;
}

void Menu::validar_opcion(int &opcion) {

    bool es_opcion_valida = opcion > 0 && opcion < CANTIDAD_DE_OPCIONES;

    while(!es_opcion_valida){
        cout << "La opción elegida no es válida, por favor intente de nuevo: " << endl;
        cin >> opcion;
        es_opcion_valida = opcion > 0 && opcion < CANTIDAD_DE_OPCIONES;
    }
}

void Menu::mostrar_submenu() {

    cout << endl << endl;
    cout << '\t' << "1. Elegir indivualmente a qué animales cuidar" << endl
    << '\t' << "2. Regresar al inicio" << endl;
}

void Menu::validar_opcion_submenu(int &opcion) {

    bool es_opcion_valida = opcion > 0 && opcion < CANTIDAD_DE_OPCIONES_SUBMENU;

    while(!es_opcion_valida){

        cout << "La opción elegida no es válida, por favor intente de nuevo: " << endl;
        cin >> opcion;
        es_opcion_valida = opcion > 0 && opcion < CANTIDAD_DE_OPCIONES_SUBMENU;
    }
}

void Menu::elegir_individualmente(Arbol_B *arbol_animales) {
    arbol_animales->cuidar_animales();
}

void Menu::procesar_opcion_submenu(Arbol_B *arbol, int opcion) {

    if (opcion == ELEGIR_INDIVIDUALMENTE){
        elegir_individualmente(arbol);
    }
}

void Menu::abrir_submenu(Arbol_B *arbol) {

    mostrar_submenu();
    int opcion = pedir_opcion();
    validar_opcion_submenu(opcion);

    while(opcion != REGRESAR_INICIO){
        procesar_opcion_submenu(arbol, opcion);
        mostrar_submenu();
        opcion = pedir_opcion();
        validar_opcion_submenu(opcion);
    }
}

void Menu::procesar_opcion(Arbol_B *arbol, int opcion, Auto *vehiculo) {

    switch(opcion){

        case LISTAR_ANIMALES:
            listar_animales(arbol);
            break;

        case RESCATAR_ANIMAL:
            rescatar_animal(arbol, vehiculo);
            break;

        case BUSCAR_ANIMAL:
            buscar_animal(arbol);
            break;

        case CUIDAR_ANIMALES:
            abrir_submenu(arbol);
            break;
            
        case ADOPTAR_ANIMAL:
            adoptar_animal(arbol);
            break;

        case CARGAR_COMBUSTIBLE:
            cargar_combustible(vehiculo);
            break;
    }
}


void Menu::listar_animales(Arbol_B *arbol_animales) {
  
    if (arbol_animales->vacio()) {
        cout << "NUESTRO ÁRBOL DE ANIMALES ESTÁ VACIO, AGREGUE UN ANIMAL POR FAVOR <3" << endl;

    }else {
        cout <<  '\t' <<  "***********ANIMALES***********" << '\n' << endl;
        arbol_animales->imprimir();
    }
}

void Menu::mostrar_datos_rescate(Auto *vehiculo, Mapa mapa){

    cout << "Combustible disponible = " << vehiculo->combustible_actual() << endl;
    cout << "Animales a rescatar = 5" << endl << endl;
}

void Menu::rescatar_animal(Arbol_B *arbol_animales, Auto *vehiculo) {
    
    Mapa mapa_juego(vehiculo);
    mapa_juego.mostrar_mapa();
    mostrar_datos_rescate(vehiculo, mapa_juego);

    /*
    string nombre, edad, tamanio, especie, personalidad;
    bool ir_a_menu = false;
    cout << "\nIngrese el nombre del animal a rescatar: " << "\nNombre: ";
    getline(cin >> ws, nombre);
    validar_nombre_animal(nombre);

    while (!ir_a_menu) {
        if (!existe_en_la_reserva(arbol_animales, nombre)) {
            ir_a_menu = true;
            preguntar_datos_animal(edad, tamanio, especie, personalidad);
            agregar_animal(arbol_animales, nombre, stoi(edad), tamanio, especie_a_inicial(especie), personalidad);
            cout << "\n¡ANIMAL RESCATADO CON ÉXITO!" << endl;

        }else if (existe_en_la_reserva(arbol_animales, nombre) && !quiere_ingresar_otro_nombre()) {
            ir_a_menu = true;

        }else {
            cout << "\nIngrese el nombre del animal a rescatar: " << "\nNombre: ";
            getline(cin >> ws, nombre);
        }
    }
    */
}

bool Menu::es_nombre_existente(string nombre_buscado, Arbol_B *arbol){   
    
    int indice = 0;
    bool encontrado = false;
    Nodo_arbol_B* nodo_encontrado = arbol->buscar_en_el_arbol(nombre_buscado, indice);
        if (nodo_encontrado != NULL){
            encontrado = true;
        }

    return encontrado;
}

void Menu::revisar_arbol_animales(Arbol_B *arbol, string &nombre_buscado){

    cout << endl << "Ingrese el nombre del animal que desea buscar por favor: " << endl;
    cin >> nombre_buscado;

    if (arbol->vacio()) {
        cout << endl << "\t -- Lo sentimos, no hay animales en esta lista, no tenemos nada que buscar. --" << endl;

    }else if (!es_nombre_existente(nombre_buscado, arbol)) {
        cout << endl << "-- El nombre que ingresó no se encuentra en nuestra lista de animales :( --" << endl;
    
    }else {
        int indice = 0;
        cout << endl << "\t -- ¡Animalito encontrado! Sus datos son: --" << endl;
        arbol->buscar_en_el_arbol(nombre_buscado, indice)->imprimir_animal(indice);
    }
}

bool Menu::es_respuesta_valida(string respuesta) {
    return (respuesta == "si") || (respuesta == "Si");
}

void Menu::buscar_animal(Arbol_B *arbol_animales){
 
    string respuesta;
    string nombre_buscado;

    do {
        revisar_arbol_animales(arbol_animales, nombre_buscado);

        cout << "\t ¿Desea buscar otro animal? (Rta: Si/No):" << endl;
        cin >> respuesta;

    }while (es_respuesta_valida(respuesta)); 
}

void Menu::realizar_adopcion(Arbol_B *arbol){
    
    string nombre_adoptado;
    int posicion = 0;

    cout << "\t Genial! :D Ingrese el nombre del animalito que le gustaría adoptar: " << endl << endl;
    cin >> nombre_adoptado;

    if (es_nombre_existente(nombre_adoptado, arbol)){
        arbol->adoptar(nombre_adoptado);
        cout << "\t ¡HA SIDO ADOPTADO CON ÉXITO! Esperamos que sean muy felices." << endl << endl;
        arbol->buscar_en_el_arbol(nombre_adoptado, posicion)->imprimir_animal(posicion);
    }
}

bool Menu::hay_letras(string palabra) {

    bool hay_letras = false;
    for (int i = 0; i < int(palabra.length()); i++){
        if (palabra[i] < PRIMER_NUMERO_ASCII || palabra[i] > ULTIMO_NUMERO_ASCII){
            hay_letras = true;
        }
    }
    return hay_letras;
}

void Menu::validar_espacio(string &espacio) {
    
    while(hay_letras(espacio)){
        cout << "Espacio no válido, utlice números positivos, por favor!" << endl;
        getline(cin, espacio);
    }
}

void Menu::adoptar_animal(Arbol_B *arbol_animales) {
    
    string espacio;
    string respuesta;

    cout << "\t Ingrese el espacio en metros cuadrados del cual dispondrá el animalito para vivir" << endl;
    cout << "\t (NO INGRESAR NÚMEROS MENORES A 0): " << endl;
 
    getline(cin >> ws, espacio);
    validar_espacio(espacio);
    arbol_animales->imprimir_por_espacio_y_edad(stoi(espacio));
   
    cout << "\t ¿Desea adoptar a alguno de estos animalitos? (Rta: si/no):" << endl;
    cin >> respuesta;

    if (es_respuesta_valida(respuesta)) {
        realizar_adopcion(arbol_animales);
        
    }else {
        cout << "\t Lamentamos que no quiera adoptar ninguno de nuestros animalitos :( " << endl
            << "\t ¡Te esperamos nuevamente!" << endl;
    }
}

void Menu::cargar_combustible(Auto *vehiculo){
    vehiculo->cargar_combustible();
}