#include <iostream>
#include "Sistema.hpp"
#include "Perro.hpp"
#include "Gato.hpp"
#include "Caballo.hpp"
#include "Roedor.hpp"
#include "Conejo.hpp"
#include "Erizo.hpp"
#include "Lagartija.hpp"
#include "funciones_auxiliares.hpp"

Sistema::Sistema() {

    lista_animales = new Lista; 
    llenar_lista(lista_animales);
}

void Sistema::inicializar_sistema(Lista *lista) {

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
}

Lista* Sistema::obtener_lista_animales() {
    return this->lista_animales;
}

void Sistema::agregar_animal(Lista *lista, string nombre, int edad, string tamanio, string especie, string personalidad){
   
    if (especie == INICIAL_PERRO){
        especie = ESPECIE_PERRO;
        Perro* perro = new Perro(nombre, edad, tamanio, especie, personalidad);
        lista->alta(perro, 1);
    }else if (especie == INICIAL_GATO){
        especie = ESPECIE_GATO;
        Gato* gato = new Gato(nombre, edad, tamanio, especie, personalidad);
        lista->alta(gato, 1);
    }else if (especie == INICIAL_CABALLO){
        especie = ESPECIE_CABALLO;
        Caballo* caballo = new Caballo(nombre, edad, tamanio, especie, personalidad);
        lista->alta(caballo, 1);
    }else if (especie == INICIAL_ROEDOR){
        especie = ESPECIE_ROEDOR;
        Roedor* roedor = new Roedor(nombre, edad, tamanio, especie, personalidad);
        lista->alta(roedor, 1);
    }else if (especie == INICIAL_CONEJO){
        especie = ESPECIE_CONEJO;
        Conejo* conejo = new Conejo(nombre, edad, tamanio, especie, personalidad);
        lista->alta(conejo, 1);
    }else if (especie == INICIAL_ERIZO){
        especie = ESPECIE_ERIZO;
        Erizo* erizo = new Erizo(nombre, edad, tamanio, especie, personalidad);
        lista->alta(erizo, 1);
    }else {
        especie = ESPECIE_LAGARTIJA;
        Lagartija* lagartija = new Lagartija(nombre, edad, tamanio, especie, personalidad);
        lista->alta(lagartija, 1);
    }
}

void Sistema::llenar_lista (Lista *lista){

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
        agregar_animal(lista, nombre, num_edad, tamanio, especie, personalidad);
    }
    archivo_animales.close();
}

void Sistema::listar_animales(Lista *lista_animales){

    if(lista_animales->vacia()){
        cout << "LISTA VACIA, AGREGUE UN ANIMAL POR FAVOR <3" << endl;
    }else{
        cout <<  '\t' <<  "***********ANIMALES***********" << '\n' << endl;
        for (int i = 1; i < lista_animales->obtener_cantidad() + 1; i++){
            mostrar_datos_animal(lista_animales->consulta(i));
        }
    }
}

void Sistema::rescatar_animal(Lista *lista_animales){
    string nombre, edad, tamanio, especie, personalidad;
    bool ir_a_menu = false;
    cout << "\nIngrese el nombre del animal a rescatar: " << "\nNombre: ";
    getline(cin >> ws, nombre);
    while(!ir_a_menu){

        if(!existe_en_la_reserva(lista_animales, nombre)){
            ir_a_menu = true;
            preguntar_datos_animal(nombre, edad, tamanio, especie, personalidad, lista_animales);
            agregar_animal(lista_animales, nombre, stoi(edad), tamanio, especie_a_inicial(especie), personalidad);
        }else if(existe_en_la_reserva(lista_animales, nombre) && !quiere_ingresar_otro_nombre()){
            ir_a_menu = true;
        }else{
            cout << "\nIngrese el nombre del animal a rescatar: " << "\nNombre: ";
            getline(cin >> ws, nombre);
        }
    }
}


void Sistema::buscar_animal(Lista *lista) {

    string respuesta;
    string nombre_buscado;
    int posicion_buscado;

    do {
        revisar_lista_animales(lista, nombre_buscado, posicion_buscado);

        cout << "\t ¿Desea buscar otro animal? (Rta: Si/No):" << endl;
        cin >> respuesta;

    } while(es_respuesta_valida(respuesta)); 
}

//Pre: el parámetro espacio debe ser mayor a 0.
void Sistema::mostrar_animales_disponibles(int espacio, Lista *lista) {
    
    if (espacio >= 50) {
        listar_animales(lista);

    } else {
        
        for (int i = POSICION_INICIAL; i <= lista->obtener_cantidad(); i++) {
            
            if ((lista->consulta(i)->obtener_tamanio() == TAMANIO_GRANDE) && (espacio >= 20)) {
                mostrar_datos_animal(lista->consulta(i));

            } else if ((lista->consulta(i)->obtener_tamanio() == TAMANIO_MEDIANO) && (espacio >= 10)) {
                mostrar_datos_animal(lista->consulta(i));

            } else if ((lista->consulta(i)->obtener_tamanio() == TAMANIO_PEQUENIO) && (espacio > 2)) {
                mostrar_datos_animal(lista->consulta(i));

            } else if ((lista->consulta(i)->obtener_tamanio() == TAMANIO_DIMINUTO) && (espacio > 0)) {
                mostrar_datos_animal(lista->consulta(i));
            } 

        }
    }
}

void Sistema::adoptar_animal(Lista *lista) {
    string esp;
    //int espacio;
    string respuesta;

    cout << "\t Ingrese el espacio en metros cuadrados del cual dispondrá el animalito para vivir" << endl;
    cout << "\t (NO INGRESAR NÚMEROS MENORES A 0): " << endl;
    //cin >> espacio;
    getline(cin >> ws,esp);
    validar_espacio(esp);
    mostrar_animales_disponibles(stoi(esp), lista);

   
    cout << "\t ¿Desea adoptar a alguno de estos animalitos? (Rta: si/no):" << endl;
    cin >> respuesta;

    if (es_respuesta_valida(respuesta)) {
        
        realizar_adopcion(lista);

    } else {
        cout << "\t Lamentamos que no quiera adoptar ninguno de nuestros animalitos :( " << endl
            << "\t ¡Te esperamos nuevamente!" << endl;
        }

}

void Sistema::cambiar_hambre_higiene(Lista *lista) {

    for (int i = 1; i < lista->obtener_cantidad() + 1; i++){
        lista->consulta(i)->aumentar_hambre();
        lista->consulta(i)->reducir_higiene();
   }
}

void Sistema::elegir_individualmente(Lista *lista_animales){
    int opcion = 0;    
    for (int i = POSICION_INICIAL; i < lista_animales->obtener_cantidad(); i++){
        mostrar_datos_animal(lista_animales->consulta(i));
        pedir_respuesta(opcion);
        if (opcion != SALTEAR_ANIMAL){
            realizar_cuidado(opcion, lista_animales->consulta(i));
        }
    }
    cout << endl << '\t' << "----HAS LLEGADO AL FINAL DE LA LISTA----" << endl << endl;
}

void Sistema::alimentar_animales(Lista *lista_animales){
    for (int i = POSICION_INICIAL; i < lista_animales->obtener_cantidad(); i++){
        lista_animales->consulta(i)->alimentar();
    }
    cout << endl << '\t' << "¡Todos los animales han sido alimentados! :)" << endl << endl;
}

void Sistema::baniar_animales(Lista *lista) {

    for (int i = POSICION_INICIAL; i < lista->obtener_cantidad(); i++) {
        lista->consulta(i)->baniar();
    }
    cout << endl << '\t' << "¡Todos los animales que necesitaban bañarse han sido higienizados! :)" << endl << endl;
}

void Sistema::guardar_y_salir(Lista *lista) {

    ofstream archivo_animales(ARCHIVO_ANIMALES);
    string inicial_especie;

    for (int i = POSICION_INICIAL; i <= lista->obtener_cantidad(); i++) {
        inicial_especie = especie_a_inicial(lista->consulta(i)->obtener_especie());
        
        archivo_animales << lista->consulta(i)->obtener_nombre() << ",";
        archivo_animales << lista->consulta(i)->obtener_edad() << ",";
        archivo_animales << lista->consulta(i)->obtener_tamanio() << ",";
        archivo_animales << inicial_especie << ",";
        archivo_animales << lista->consulta(i)->obtener_personalidad() << "\n";
    }
    lista->baja(POSICION_INICIAL);
    lista = nullptr;
}

void Sistema::procesar_opcion_submenu(Lista* lista_animales, int opcion){
    switch(opcion){
        case ELEGIR_INDIVIDUALMENTE:
            elegir_individualmente(lista_animales);
            break;
        case ALIMENTAR_TODOS:
            alimentar_animales(lista_animales);
            break;
        case BANIAR_TODOS:
            baniar_animales(lista_animales);
            break;
    }
}

void Sistema::abrir_submenu(Lista *lista){
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

void Sistema::procesar_opcion(Lista *lista_animales, int opcion){
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
    }
}

