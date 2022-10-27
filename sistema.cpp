#include <iostream>
#include "sistema.h"



void agregar_animal(Lista &lista, string nombre, int edad, string tamanio, string especie, string personalidad){
   
    if (especie == INICIAL_PERRO){
        especie = ESPECIE_PERRO;
        Perro* perro = new Perro(nombre, edad, tamanio, especie, personalidad);
        lista.alta(perro, 1);
    }else if (especie == INICIAL_GATO){
        especie = ESPECIE_GATO;
        Gato* gato = new Gato(nombre, edad, tamanio, especie, personalidad);
        lista.alta(gato, 1);
    }else if (especie == INICIAL_CABALLO){
        especie = ESPECIE_CABALLO;
        Caballo* caballo = new Caballo(nombre, edad, tamanio, especie, personalidad);
        lista.alta(caballo, 1);
    }else if (especie == INICIAL_ROEDOR){
        especie = ESPECIE_ROEDOR;
        Roedor* roedor = new Roedor(nombre, edad, tamanio, especie, personalidad);
        lista.alta(roedor, 1);
    }else if (especie == INICIAL_CONEJO){
        especie = ESPECIE_CONEJO;
        Conejo* conejo = new Conejo(nombre, edad, tamanio, especie, personalidad);
        lista.alta(conejo, 1);
    }else if (especie == INICIAL_ERIZO){
        especie = ESPECIE_ERIZO;
        Erizo* erizo = new Erizo(nombre, edad, tamanio, especie, personalidad);
        lista.alta(erizo, 1);
    }else {
        especie = ESPECIE_LAGARTIJA;
        Lagartija* lagartija = new Lagartija(nombre, edad, tamanio, especie, personalidad);
        lista.alta(lagartija, 1);
    }
}

void llenar_lista (Lista &lista){

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

bool es_nombre_existente(string nombre_buscado, Lista &lista, int &posicion_buscado) {
    
    bool encontrado = false;
    
    while(!encontrado && posicion_buscado <= lista.obtener_cantidad()) {

        if (lista.consulta(posicion_buscado)->obtener_nombre() == nombre_buscado) {
            encontrado = true;
            
        } else {
            posicion_buscado++;
        }
    }

    return encontrado;
}

void mostrar_animal(Animal* animal) {
    
    cout << endl << "-------------------" << endl;
    cout << "Su nombre es: " << animal->obtener_nombre() << endl <<
    "Edad: " << animal->obtener_edad() << endl <<
    "Su tamaño: " << animal->obtener_tamanio() << endl <<
    "La especie que lo deifne es: " << animal->obtener_especie() << endl <<
    "Tiene una personalidad: " << animal->obtener_personalidad() << endl <<
    "Se alimenta a base de: " << animal->obtener_comida() << endl;
}

void buscar_animal(Lista &lista) {

    string respuesta;
    string nombre_buscado;
    int posicion_buscado;

    do {
        posicion_buscado = 1;
        cout << endl << "Ingrese el nombre del animal que desea buscar por favor: " << endl;
        cin >> nombre_buscado;

        if (lista.vacia()) {

            cout << endl << "\t -- Lo sentimos, no hay animales en esta lista, no tenemos nada que buscar. --" << endl;

        } else if(!es_nombre_existente(nombre_buscado, lista, posicion_buscado)) {

            cout << endl << "-- El nombre que ingresaste no se encuentra en nuestra lista de animales :( --" << endl;
        } else {

            cout << endl << "\t -- Animalito encontrado! Sus datos son: " << endl;
            mostrar_animal(lista.consulta(posicion_buscado));
        }

        cout << "\t Desea buscar otro animal? (Rta: Si/No):" << endl;
        cin >> respuesta;

    } while(es_respuesta_valida(respuesta)); 
}