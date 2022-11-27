#include <iostream>
#include "../include/Sistema.hpp"
#include "../include/Perro.hpp"
#include "../include/Gato.hpp"
#include "../include/Caballo.hpp"
#include "../include/Roedor.hpp"
#include "../include/Conejo.hpp"
#include "../include/Erizo.hpp"
#include "../include/Lagartija.hpp"
#include "../include/funciones_auxiliares.hpp"
#include "../include/funciones_del_menu.hpp"
#include "../include/Mapa.hpp"
#include "../include/quicksort.hpp"

Sistema::Sistema() {

    partida_terminada = false;
    arbol_animales = new Arbol_B(3); 
    vehiculo = new Auto();
    llenar_arbol(arbol_animales);
}

void Sistema::inicializar_sistema(Sistema sistema) {

    mostrar_menu();
    int opcion = pedir_opcion();
    validar_opcion(opcion);

    while(opcion != GUARDAR_Y_SALIR && !partida_terminada){
        procesar_opcion(sistema, opcion);
        mostrar_menu();
        opcion = pedir_opcion();
        validar_opcion(opcion);   
        verificar_si_partida_continua(arbol_animales); 
    }

    guardar_y_salir(sistema.obtener_arbol_animales());
    delete sistema.obtener_arbol_animales();
}

Arbol_B* Sistema::obtener_arbol_animales() {
    return this->arbol_animales;
}

void Sistema::agregar_animal(Arbol_B *arbol_animales, string nombre, int edad, string tamanio, string especie, string personalidad) {
  
    if (especie == INICIAL_PERRO){
        especie = ESPECIE_PERRO;
        Perro* perro = new Perro(nombre, edad, tamanio, especie, personalidad);
        arbol_animales->insertar(perro);

    }else if (especie == INICIAL_GATO){
        especie = ESPECIE_GATO;
        Gato* gato = new Gato(nombre, edad, tamanio, especie, personalidad);
        arbol_animales->insertar(gato);

    }else if (especie == INICIAL_CABALLO){
        especie = ESPECIE_CABALLO;
        Caballo* caballo = new Caballo(nombre, edad, tamanio, especie, personalidad);
        arbol_animales->insertar(caballo);

    }else if (especie == INICIAL_ROEDOR){
        especie = ESPECIE_ROEDOR;
        Roedor* roedor = new Roedor(nombre, edad, tamanio, especie, personalidad);
        arbol_animales->insertar(roedor);

    }else if (especie == INICIAL_CONEJO){
        especie = ESPECIE_CONEJO;
        Conejo* conejo = new Conejo(nombre, edad, tamanio, especie, personalidad);
        arbol_animales->insertar(conejo);

    }else if (especie == INICIAL_ERIZO){
        especie = ESPECIE_ERIZO;
        Erizo* erizo = new Erizo(nombre, edad, tamanio, especie, personalidad);
        arbol_animales->insertar(erizo);

    }else {
        especie = ESPECIE_LAGARTIJA;
        Lagartija* lagartija = new Lagartija(nombre, edad, tamanio, especie, personalidad);
        arbol_animales->insertar(lagartija);
    }
}

void Sistema::llenar_arbol(Arbol_B *arbol_animales) {
  
    ifstream archivo_animales(ARCHIVO_ANIMALES);
    
    if (!archivo_animales.is_open()){
        cout << "No se ha encontrado un archivo, se creará uno llamado: " << ARCHIVO_ANIMALES << endl;
        archivo_animales.open(ARCHIVO_ANIMALES, ios::out);
        archivo_animales.close();
        archivo_animales.open(ARCHIVO_ANIMALES, ios::in);
    }

    string nombre, edad, tamanio, especie, personalidad;
    int num_edad;

    while (getline (archivo_animales, nombre, ',')){ 
        getline (archivo_animales, edad, ',');
        getline (archivo_animales, tamanio, ',');
        getline (archivo_animales, especie, ',');
        getline (archivo_animales, personalidad);
        num_edad = stoi(edad);
        agregar_animal(arbol_animales, nombre, num_edad, tamanio, especie, personalidad);
    }
    archivo_animales.close();
}

void Sistema::listar_animales(Arbol_B *arbol_animales) {
  
    if (arbol_animales->vacio()) {
        cout << "NUESTRO ÁRBOL DE ANIMALES ESTÁ VACIO, AGREGUE UN ANIMAL POR FAVOR <3" << endl;

    }else {
        cout <<  '\t' <<  "***********ANIMALES***********" << '\n' << endl;
        arbol_animales->imprimir();
    }
}

void Sistema::rescatar_animal(Arbol_B *arbol_animales) {
    
    Mapa mapa_juego(vehiculo);
    mapa_juego.mostrar_mapa();

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

void Sistema::revisar_arbol_animales(Arbol_B *arbol, string &nombre_buscado){

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

bool Sistema::es_nombre_valido(string palabra){
    
    bool es_nombre_valido = true;
    for (int i = 0; i < int(palabra.length()); i++){
        if ((palabra[i] < 'a' || palabra[i] > 'z') && (palabra[i] < 'A' || palabra[i] > 'Z')){
            es_nombre_valido = false;
        }
    }
    return es_nombre_valido;
}

void Sistema::validar_nombre_animal(string &nombre){
    
    while(!es_nombre_valido(nombre)){
        cout << "\nEl nombre ingresado no es válida, acuérdese que no puede contener numeros o caracteres del tipo @-() etc" << endl;
        cout << "\nNombre: ";
        getline(cin, nombre);
    }
}

void Sistema::validar_edad(string &edad) {
    
    while (hay_letras(edad)){
        cout << "\nLa edad ingresada no válida, acuérdese que la edad es sólo con números" << endl;
        cout << "\nEdad: ";
        getline(cin, edad);
    }
}

void Sistema::buscar_animal(Arbol_B *arbol_animales){
 
    string respuesta;
    string nombre_buscado;

    do {
        revisar_arbol_animales(arbol_animales, nombre_buscado);

        cout << "\t ¿Desea buscar otro animal? (Rta: Si/No):" << endl;
        cin >> respuesta;

    }while (es_respuesta_valida(respuesta)); 
}


void Sistema::reajustar(Animal** vector, int& max_vector){
    int cantidad_maxima_animales = max_vector * 2;
    Animal** nuevo_vector_animales = new Animal*[cantidad_maxima_animales];

    for (int i = 0; i < max_vector; i++){
        nuevo_vector_animales[i] = vector[i];
    }

    if (max_vector != 0){
        delete[] vector;
    }
    vector  = nuevo_vector_animales;
    max_vector = cantidad_maxima_animales; 
}

void Sistema::realizar_adopcion(Arbol_B *arbol){
    
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

void Sistema::adoptar_animal(Arbol_B *arbol_animales) {
    
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

void Sistema::cambiar_hambre_higiene(Arbol_B *arbol_animales) {
    arbol_animales->actualizar_hambre_higiene();
}

void Sistema::elegir_individualmente(Arbol_B *arbol_animales) {
    arbol_animales->cuidar_animales();
}

void Sistema::guardar_y_salir(Arbol_B *arbol) {

    fstream archivo_animales(ARCHIVO_ANIMALES);
    string inicial_especie;
    arbol->guardar(archivo_animales);
    archivo_animales.close();
}

void Sistema::verificar_si_partida_continua(Arbol_B *arbol_animales){
 
    arbol_animales->revisar_hambre_higiene();
    int cant_escapes = arbol_animales->obtener_cantidad_de_escapes();
    if (cant_escapes >= CANT_MAXIMA_ESCAPES){
        partida_terminada = true;
        imprimir_msje_partida_perdida();
    }
}

void Sistema::cargar_combustible(){
    vehiculo->cargar_combustible();
}

Auto* Sistema::obtener_auto(){
    return vehiculo;
}