#include <iostream>
#include "sistema.h"



void agregar_animal(Lista *lista, string nombre, int edad, string tamanio, string especie, string personalidad){
   
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

void llenar_lista (Lista *lista){

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

bool es_respuesta_valida(string respuesta) {
    return (respuesta == "si") || (respuesta == "Si");
}

string especie_completa(string especie){
    string especie_completa;
    if(especie == INICIAL_PERRO){
        especie_completa = ESPECIE_PERRO;

    }else if(especie == INICIAL_GATO){
        especie_completa = ESPECIE_GATO;

    }else if(especie == INICIAL_CABALLO){
        especie_completa = ESPECIE_CABALLO;

    }else if(especie == INICIAL_ROEDOR){
        especie_completa = ESPECIE_ROEDOR;

    }else if(especie == INICIAL_CONEJO){
        especie_completa = ESPECIE_CONEJO;

    }else if(especie == INICIAL_ERIZO){
        especie_completa = ESPECIE_ERIZO;

    }else if(especie == INICIAL_LAGARTIJA){
        especie_completa = ESPECIE_LAGARTIJA;
    }
    return especie_completa;
}

//Precondiciones: Posicion tiene que ser menor al tope del vector
//Postcondiciones: Muestra por pantalla el libro completo(Nombre, Genero y Puntaje).
void mostrar_datos_animal(Animal* animal){

    cout << '\t' <<  "******************************" << endl
         
         << '\t' << "* Nombre: " << animal->obtener_nombre()  <<  endl
         << '\t' << "* Edad: " << animal->obtener_edad() << endl
         << '\t' << "* Tamaño: " << animal->obtener_tamanio() << endl
         << '\t' << "* Especie: " << animal->obtener_especie() << endl
         << '\t' << "* Personalidad: " << animal->obtener_personalidad() << endl
         << '\t' << "* Hambre: " << animal->obtener_hambre() << endl
         << '\t' << "* Higiene: " << animal->obtener_higiene() << endl
         << '\t' <<"******************************" << "\n" << endl
         << '\n' << endl;
}

void listar_animales(Lista *lista_animales){

    cout <<  '\t' <<  "***********ANIMALES***********" << '\n' << endl;
    for (int i = 1; i < lista_animales->obtener_cantidad(); i++){
        mostrar_datos_animal(lista_animales->consulta(i));
    }
}

bool es_nombre_existente(string nombre_buscado, Lista *lista, int &posicion_buscado) {
    
    bool encontrado = false;
    
    while(!encontrado && posicion_buscado <= lista->obtener_cantidad()) {

        if (lista->consulta(posicion_buscado)->obtener_nombre() == nombre_buscado) {
            encontrado = true;
            
        } else {
            posicion_buscado++;
        }
    }
    return encontrado;
}

void revisar_lista_animales(Lista *lista, string &nombre_buscado, int &posicion_buscado) {
    
    posicion_buscado = POSICION_INICIAL;
    cout << endl << "Ingrese el nombre del animal que desea buscar por favor: " << endl;
    cin >> nombre_buscado;

    if (lista->vacia()) {

        cout << endl << "\t -- Lo sentimos, no hay animales en esta lista, no tenemos nada que buscar. --" << endl;

    } else if(!es_nombre_existente(nombre_buscado, lista, posicion_buscado)) {

        cout << endl << "-- El nombre que ingresaste no se encuentra en nuestra lista de animales :( --" << endl;
    } else {

        cout << endl << "\t -- Animalito encontrado! Sus datos son: --" << endl;
        mostrar_datos_animal(lista->consulta(posicion_buscado));
    }
}

void buscar_animal(Lista *lista) {

    string respuesta;
    string nombre_buscado;
    int posicion_buscado;

    do {
        revisar_lista_animales(lista, nombre_buscado, posicion_buscado);

        cout << "\t Desea buscar otro animal? (Rta: Si/No):" << endl;
        cin >> respuesta;

    } while(es_respuesta_valida(respuesta)); 
}

//Pre: el parámetro espacio debe ser mayor a 0.
void mostrar_animales_disponibles(int espacio, Lista *lista) {

    if (espacio >= 50) {
            listar_animales(lista);

    } else {
        
        for (int i = 1; i <= lista->obtener_cantidad(); i++) {
        
            if ((lista->consulta(i)->obtener_tamanio() == "grande") && (espacio >= 20)) {
                mostrar_datos_animal(lista->consulta(i));

            } else if ((lista->consulta(i)->obtener_tamanio() == "mediano") && (espacio >= 10)) {
                mostrar_datos_animal(lista->consulta(i));

            } else if ((lista->consulta(i)->obtener_tamanio() == "pequeño") && (espacio > 2)) {
                mostrar_datos_animal(lista->consulta(i));

            } else if ((lista->consulta(i)->obtener_tamanio() == "diminuto") && (espacio > 0)) {
                mostrar_datos_animal(lista->consulta(i));
            } 

        }
    }
}

void realizar_adopcion(Lista *lista) {
            
    string nombre_adoptado;
    int posicion = 1;

    cout << "\t Genial! :D Ingrese el nombre del animalito que le gustaría adoptar: " << endl << endl;
    cin >> nombre_adoptado;

    if (es_nombre_existente(nombre_adoptado, lista, posicion)) {
        mostrar_datos_animal(lista->consulta(posicion));
        cout << "\t HA SIDO ADOPTADO CON ÉXITO! Esperamos que sean muy felices." << endl;
        lista->baja(posicion);
    }
}

void adoptar_animal(Lista *lista) {
    
    int espacio;
    string respuesta;

    cout << "\t Ingrese el espacio en metros cuadrados del cual dispondrá el animalito para vivir (NO INGRESAR NÚMEROS MENORES A 0): " << endl;
    cin >> espacio;

    mostrar_animales_disponibles(espacio, lista);

    cout << "\t Desea adoptar a alguno de estos animalitos?: " << endl;
    cin >> respuesta;

    if (es_respuesta_valida(respuesta)) {
        
        realizar_adopcion(lista);

    } else {
        cout << "\t Lamentamos que no quieras adoptar ninguno de nuestros animalitos :( " << endl
             << "\t Te esperamos nuevamente!" << endl;
    }
}

