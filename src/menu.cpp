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
    << '\t' << "2. Rescatar animales" << endl
    << '\t' << "3. Buscar animal" << endl
    << '\t' << "4. Cuidar animales" << endl
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

        case RESCATAR_ANIMALES:
            cout << "Cargando..." << endl; 
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
    cout << "Animales a rescatar = " << mapa.animales_sin_rescatar() << endl << endl;
}

void Menu::mostrar_opciones(Mapa mapa_juego){

    cout << '\t' << "¿Qué desea hacer?" << endl
    << '\t' << "1. Rescatar algún animal" << endl
    << '\t' << "2. Volver al inicio" << endl;
}

void Menu::pedir_respuesta(int &respuesta){
    
    cin >> respuesta;

    while (respuesta > NO || respuesta < SI){
        cout << '\t' << "Esa no es una respuesta válida" << endl
        << '\t' << "Ingrese (1) si la respuesta es afirmativa o (2) si la respuesta es negativa." << endl
        << '\t' << "Intentelo de nuevo: ";
        cin >> respuesta;
    }
}

void Menu::elegir_animal(int &animal, Mapa mapa){

    cout << '\t' << "Ingrese el número correspondiente al animal que desea salvar: ";
    cin >> animal;

    while (animal > mapa.animales_sin_rescatar() || animal <= 0){
        cout << '\t' << "Esa no es una respuesta válida, intentelo de nuevo: ";
        cin >> animal;
    }
}

void Menu::combustible_insuficiente(int &respuesta, int costo, Auto *vehiculo){

    cout << '\t' << "No hay suficiente combustible para rescatar a ese animal" << endl
    << '\t' << "El viaje cuesta " << costo << " de combustible, y sólo hay " << vehiculo->combustible_actual() 
    << " en el tanque." << endl
    << '\t' << "¿Quiere rescatar a otro animal?" << endl
    << '\t' << "1. Si     2. No" << endl;
    pedir_respuesta(respuesta);
}

void Menu::combustible_suficiente(int &respuesta, int costo, Auto *vehiculo){

    cout << '\t' << "El viaje cuesta " << costo << " de combustible. En el tanque hay " << vehiculo->combustible_actual() << "." << endl
    << '\t' << "Es decir, luego del viaje quedará " << (vehiculo->combustible_actual() - costo) << " de combustible." << endl
    << '\t' << "¿Desea rescatar a este animal o desea rescatar a otro?" << endl
    << '\t' << "1. Rescatar a este animal     2. Volver al menú" << endl;
    pedir_respuesta(respuesta);
}

bool Menu::es_nombre_valido(string palabra){
    
    bool es_nombre_valido = true;
    for (int i = 0; i < int(palabra.length()); i++){
        if ((palabra[i] < 'a' || palabra[i] > 'z') && (palabra[i] < 'A' || palabra[i] > 'Z')){
            es_nombre_valido = false;
        }
    }
    return es_nombre_valido;
}

void Menu::validar_nombre_animal(string &nombre, Arbol_B *arbol_animales){
    
    while(!es_nombre_valido(nombre)){
        cout << '\t' << "El nombre ingresado no es válido, acuérdese que no puede contener numeros o caracteres del tipo @-() etc" << endl;
        cout << '\t' << "Nombre: ";
        cin >> nombre;
    }

        while (es_nombre_existente(nombre, arbol_animales)){
        cout << '\t' << "Ese nombre ya partenece a otro de los animalitos de nuestra reserva" << endl
        << '\t' << "Intente con otro:";
        cin >> nombre;
    }
}

void Menu::realizar_rescate(Mapa &mapa_juego, Arbol_B *arbol_animales, Auto *vehiculo, int animal, int costo){

    string nombre;
    Animal* animal_rescatado = mapa_juego.rescatar_animal(animal);
    cout << '\t' << "¡Ha rescatado a un animal!" << endl
    << '\t' << "¿Qué nombre desea ponerle?" << endl;
    cin >> nombre;
    validar_nombre_animal(nombre, arbol_animales);
    animal_rescatado->asignar_nombre(nombre);
    arbol_animales->insertar(animal_rescatado);
    vehiculo->reducir_combustible(costo);
}

int Menu::calcular_costo_camino(Mapa mapa_juego, Auto *vehiculo, int &animal, int &fila, int &columna) {
    
    mapa_juego.mostrar_mapa();
    mapa_juego.mostrar_listado_animales();
    elegir_animal(animal, mapa_juego);
    mapa_juego.obtener_coords_animal(animal, fila, columna);

    return mapa_juego.costo_viaje(vehiculo->obtener_pos().fila, vehiculo->obtener_pos().columna, fila, columna);
}

void Menu::notificar_rescate(int &respuesta) {

    cout << '\t' << "¡Animal rescatado con éxito!" << endl
    << '\t' << "Ya forma parte de nuestra reserva :)" << endl << endl
    << '\t' << "¿Desea rescatar a otro animal?" << endl
    << '\t' << "1. Si     2. No" << endl;
    
    pedir_respuesta(respuesta);
}

void Menu::rescatar_animal(Arbol_B *arbol_animales, Auto *vehiculo) {
    
    int respuesta = 0;
    Mapa mapa_juego(vehiculo);
    mapa_juego.mostrar_mapa();
    mostrar_datos_rescate(vehiculo, mapa_juego);
    mostrar_opciones(mapa_juego);
    pedir_respuesta(respuesta);

    while (respuesta == RESCATAR_ANIMAL && mapa_juego.obtener_animales_sin_rescatar() != 0) {
        
        int fila = 0;
        int columna = 0;
        int animal = 0;
        int costo_camino = calcular_costo_camino(mapa_juego, vehiculo, animal, fila, columna);

        mapa_juego.marcar_camino_recorrido(vehiculo->obtener_pos().fila, vehiculo->obtener_pos().columna, fila, columna);

        if (costo_camino > vehiculo->combustible_actual()) {
            combustible_insuficiente(respuesta, costo_camino, vehiculo);
        } else {
            combustible_suficiente(respuesta, costo_camino, vehiculo);
            if (respuesta == SI){
                realizar_rescate(mapa_juego, arbol_animales, vehiculo, animal, costo_camino);
                notificar_rescate(respuesta);
            }
        }
    }

    if (mapa_juego.obtener_animales_sin_rescatar() == 0) {
        cout << endl << '\t' << " ¡YA HAS RESCATADO A TODOS LOS ANIMALES!" << endl
        << '\t' << "GRACIAS POR DARLES UN NUEVO HOGAR <3" << endl << endl;
    }
    cout << '\t' << "Volviendo al menú..." << endl << endl;
    mapa_juego.~Mapa();
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

void Menu::buscar_animal(Arbol_B *arbol_animales){
 
    int respuesta;
    string nombre_buscado;

    do {
        revisar_arbol_animales(arbol_animales, nombre_buscado);

        cout << "\t ¿Desea buscar otro animal?" << endl
        << "\t 1. Si        2. No" << endl;
        pedir_respuesta(respuesta);

    }while (respuesta == SI); 
}

void Menu::realizar_adopcion(Arbol_B *arbol){
    
    string nombre_adoptado;
    int posicion = 0;

    cout << "\t Genial! :D Ingrese el nombre del animalito que le gustaría adoptar: " << endl << endl;
    cin >> nombre_adoptado;

    while (!es_nombre_existente(nombre_adoptado, arbol)){
        cout << '\t' << "Ese nombre no es válido. Ingrese un nombre que aparezca en la lista." << endl;
        cin >> nombre_adoptado;
    }

    arbol->adoptar(nombre_adoptado);
    cout << "\t ¡HA SIDO ADOPTADO CON ÉXITO! Esperamos que sean muy felices." << endl << endl;
    arbol->buscar_en_el_arbol(nombre_adoptado, posicion)->imprimir_animal(posicion);
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
    int respuesta;

    cout << "\t Ingrese el espacio en metros cuadrados del cual dispondrá el animalito para vivir" << endl;
    cout << "\t (NO INGRESAR NÚMEROS MENORES A 0): " << endl;
 
    getline(cin >> ws, espacio);
    validar_espacio(espacio);
    arbol_animales->imprimir_por_espacio_y_edad(stoi(espacio));
   
    cout << "\t ¿Desea adoptar a alguno de estos animalitos?" << endl
    << "\t 1. Si        2. No" << endl;
    pedir_respuesta(respuesta);

    if (respuesta == SI) {
        realizar_adopcion(arbol_animales);
        
    }else {
        cout << "\t Lamentamos que no quiera adoptar ninguno de nuestros animalitos :( " << endl
            << "\t ¡Te esperamos nuevamente!" << endl;
    }
}

void Menu::cargar_combustible(Auto *vehiculo){
    vehiculo->cargar_combustible();
}