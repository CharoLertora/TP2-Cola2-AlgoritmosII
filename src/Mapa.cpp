#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../include/Mapa.hpp"
#include "../include/Perro.hpp"
#include "../include/Gato.hpp"
#include "../include/Caballo.hpp"
#include "../include/Roedor.hpp"
#include "../include/Conejo.hpp"
#include "../include/Erizo.hpp"
#include "../include/Lagartija.hpp"
#include "../include/funciones_auxiliares.hpp"
#include "../include/Grafo.hpp"

const string NOMBRE_RESCATADO = "SIN NOMBRE";

void llenar_primera_fila(string terreno[MAX_TERRENO][MAX_TERRENO]) {

    terreno[0][0] = CAMINO;
    terreno[0][1] = PRECIPICIO;
    terreno[0][2] = TIERRA;
    terreno[0][3] = TIERRA;
    terreno[0][4] = TIERRA;
    terreno[0][5] = TIERRA;
    terreno[0][6] = TIERRA;
    terreno[0][7] = TIERRA;
}

void llenar_segunda_fila(string terreno[MAX_TERRENO][MAX_TERRENO]) {

    terreno[1][0] = CAMINO;
    terreno[1][1] = TIERRA;
    terreno[1][2] = TIERRA;
    terreno[1][3] = TIERRA;
    terreno[1][4] = PRECIPICIO;
    terreno[1][5] = PRECIPICIO;
    terreno[1][6] = PRECIPICIO;
    terreno[1][7] = PRECIPICIO;
}

void llenar_tercera_fila(string terreno[MAX_TERRENO][MAX_TERRENO]) {

    terreno[2][0] = CAMINO;
    terreno[2][1] = CAMINO;
    terreno[2][2] = CAMINO;
    terreno[2][3] = CAMINO;
    terreno[2][4] = CAMINO;
    terreno[2][5] = TIERRA;
    terreno[2][6] = MONTANIA;
    terreno[2][7] = MONTANIA;
}

void llenar_cuarta_fila(string terreno[MAX_TERRENO][MAX_TERRENO]) {

    terreno[3][0] = TIERRA;
    terreno[3][1] = TIERRA;
    terreno[3][2] = TIERRA;
    terreno[3][3] = TIERRA;
    terreno[3][4] = CAMINO;
    terreno[3][5] = TIERRA;
    terreno[3][6] = MONTANIA;
    terreno[3][7] = MONTANIA;
}

void llenar_quinta_fila(string terreno[MAX_TERRENO][MAX_TERRENO]) {

    terreno[4][0] = MONTANIA;
    terreno[4][1] = MONTANIA;
    terreno[4][2] = MONTANIA;
    terreno[4][3] = TIERRA;
    terreno[4][4] = CAMINO;
    terreno[4][5] = TIERRA;
    terreno[4][6] = MONTANIA;
    terreno[4][7] = MONTANIA;
}

void llenar_sexta_fila(string terreno[MAX_TERRENO][MAX_TERRENO]) {

    terreno[5][0] = TIERRA;
    terreno[5][1] = TIERRA;
    terreno[5][2] = TIERRA;
    terreno[5][3] = TIERRA;
    terreno[5][4] = CAMINO;
    terreno[5][5] = TIERRA;
    terreno[5][6] = MONTANIA;
    terreno[5][7] = MONTANIA;
}

void llenar_septima_fila(string terreno[MAX_TERRENO][MAX_TERRENO]) {

    terreno[6][0] = TIERRA;
    terreno[6][1] = PRECIPICIO;
    terreno[6][2] = PRECIPICIO;
    terreno[6][3] = PRECIPICIO;
    terreno[6][4] = CAMINO;
    terreno[6][5] = TIERRA;
    terreno[6][6] = MONTANIA;
    terreno[6][7] = MONTANIA;
}

void llenar_octava_fila(string terreno[MAX_TERRENO][MAX_TERRENO]) {

    terreno[7][0] = TIERRA;
    terreno[7][1] = TIERRA;
    terreno[7][2] = TIERRA;
    terreno[7][3] = TIERRA;
    terreno[7][4] = CAMINO;
    terreno[7][5] = CAMINO;
    terreno[7][6] = CAMINO;
    terreno[7][7] = CAMINO;
}

bool Mapa::hay_animal(int fila, int columna){
    return (terreno[fila][columna] == IMAGEN_PERRO || terreno[fila][columna] == IMAGEN_GATO || terreno[fila][columna] == IMAGEN_CABALLO || terreno[fila][columna] == IMAGEN_CONEJO || terreno[fila][columna] == IMAGEN_ROEDOR || terreno[fila][columna] == IMAGEN_ERIZO || terreno[fila][columna] == IMAGEN_LAGARTIJA);
}

int Mapa::numero_random(int rango, int minimo){
    
    srand ((unsigned)time(NULL));
    int numero = rand() % rango + minimo;
    return numero; 
}

void Mapa::ubicar_auto(){

    terreno[0][0] = AUTO;
    vehiculo->asignar_posicion(grafo->encontrar_vertice(0,0));
}

void Mapa::copiar_animales(Grafo *grafo, Animal *animal, int fila, int columna){

    Vertice *vertice = grafo->encontrar_vertice(fila, columna);
    if (vertice != NULL){
        vertice->asignar_animal(animal); 
    }
}

void Mapa::guardar_coordenadas(int indice, int fila, int columna){

    coordenadas[indice].fila = fila;
    coordenadas[indice].columna = columna;
}

void Mapa::mostrar_listado_animales(){

    if (animales_rescatados < MAX_ANIMALES){
        cout << "ANIMALES POR RESCATAR: " << endl;
        for (int i = 0; i < animales_sin_rescatar(); i++){
        cout << (i + 1) << ". " << animales_a_rescatar[i]->obtener_especie() << endl;
        }
    }

    cout << endl << endl;
}

int Mapa::animales_sin_rescatar(){
    return (MAX_ANIMALES - animales_rescatados);
}

void Mapa::obtener_coords_animal(int indice, int &fila, int &columna){

    fila = coordenadas[indice - 1].fila;
    columna = coordenadas[indice - 1].columna;
}

void Mapa::ubicar_animal(int indice, Animal* animal, Grafo* grafo){

    int fila = 0;
    int columna = 0;
    
    do {
        fila = numero_random(MAX_TERRENO, 0);
        columna = numero_random(MAX_TERRENO, 0);
    }while(hay_animal(fila, columna) || terreno[fila][columna] == AUTO);

    if (animal->obtener_especie() == ESPECIE_PERRO){
        terreno[fila][columna] = IMAGEN_PERRO;
    }else if (animal->obtener_especie() == ESPECIE_GATO){
        terreno[fila][columna] = IMAGEN_GATO;
    }else if (animal->obtener_especie() == ESPECIE_CABALLO){
        terreno[fila][columna] = IMAGEN_CABALLO;
    }else if (animal->obtener_especie() == ESPECIE_CONEJO){
        terreno[fila][columna] = IMAGEN_CONEJO;
    }else if (animal->obtener_especie() == ESPECIE_ROEDOR){
        terreno[fila][columna] = IMAGEN_ROEDOR;
    }else if (animal->obtener_especie() == ESPECIE_ERIZO){
        terreno[fila][columna] = IMAGEN_ERIZO;
    }else {
        terreno[fila][columna] = IMAGEN_LAGARTIJA;
    } 

    guardar_coordenadas(indice, fila, columna);
    copiar_animales(grafo, animal, fila, columna);
}

void Mapa::ubicar_animales(){
    
    for (int i = 0; i < MAX_ANIMALES; i++){
        ubicar_animal(i, animales_a_rescatar[i], grafo);
    }
}

string Mapa::tamanio_random() {
    
    int numero = numero_random(MAX_TAMANIOS, 1);

    switch (numero){
    case 1:
        return TAMANIO_DIMINUTO;
        break;
    case 2:
        return TAMANIO_PEQUENIO;
        break;
    case 3:
        return TAMANIO_MEDIANO;
        break;
    case 4:
        return TAMANIO_GRANDE;
        break;
    default:
        return TAMANIO_GIGANTE;
        break;
    }
}

string Mapa::personalidad_random() {
    
    int numero = numero_random(MAX_PERSONALIDADES, 1);

    switch (numero){
    case 1:
        return PERSONALIDAD_DORMILON;
        break;
    case 2:
        return PERSONALIDAD_JUEGUETON;
        break;
    case 3:
        return PERSONALIDAD_SOCIABLE;
        break;
    default:
        return PERSONALIDAD_TRAVIESO;
        break;
    }
}

string Mapa::especie_random() {
    
    int numero = numero_random(MAX_ESPECIES, 1);

    switch (numero){
    case 1:
        return ESPECIE_PERRO;
        break;
    case 2:
        return ESPECIE_GATO;
        break;
    case 3:
        return ESPECIE_CABALLO;
        break;
    case 4:
        return ESPECIE_ROEDOR;
        break;
    case 5:
        return ESPECIE_CONEJO;
        break;
    case 6:
        return ESPECIE_ERIZO;
        break;
    default:
        return ESPECIE_LAGARTIJA;
        break;
    }
}

bool Mapa::ya_salio(int especies[MAX_ANIMALES], int numero){
    bool salio = false;
    if (especies[0] != 0){
        for (int i = 0; i < MAX_ANIMALES; i++){
            if (especies[i] == numero){
                salio = true;
            }
        }
    }
    return salio;

}

void Mapa::validar_especie(int especies[MAX_ANIMALES], int &numero, int numero_animal){
        
    while (ya_salio(especies, numero)){
        numero = numero_random(MAX_ESPECIES, 1);
    }

    especies[numero_animal] = numero;
}

void Mapa::cargar_animal(int numero, Animal* &animal_random, string nombre, string tamanio, string personalidad, int edad) {

    string especie;

    if (numero == INDICE_PERRO) {
        especie = ESPECIE_PERRO;
        animal_random = new Perro(nombre, edad, tamanio, especie, personalidad);

    } else if (numero == INDICE_GATO) {
        especie = ESPECIE_GATO;
        animal_random = new Gato(nombre, edad, tamanio, especie, personalidad);

    } else if (numero == INDICE_CABALLO) {
        especie = ESPECIE_CABALLO;
        animal_random = new Caballo(nombre, edad, tamanio, especie, personalidad);

    } else if (numero == INDICE_ROEDOR) {
        especie = ESPECIE_ROEDOR;
        animal_random = new Roedor(nombre, edad, tamanio, especie, personalidad);

    } else if (numero == INDICE_CONEJO) {
        especie = ESPECIE_CONEJO;
        animal_random = new Conejo(nombre, edad, tamanio, especie, personalidad);

    } else if (numero == INDICE_ERIZO) {
        especie = ESPECIE_ERIZO;
        animal_random = new Erizo(nombre, edad, tamanio, especie, personalidad);

    } else {
        especie = ESPECIE_LAGARTIJA;
        animal_random = new Lagartija(nombre, edad, tamanio, especie, personalidad);
    }
}

void Mapa::llenar_vector() {
    
    string nombre = NOMBRE_RESCATADO;
    string tamanio;
    string personalidad;
    int edad;
    int especies[MAX_ANIMALES];
    for (int i = 0; i < MAX_ANIMALES; i++){
        especies[i] = 0;
    }

    for (int i = 0; i < MAX_ANIMALES; i++) {

        tamanio = tamanio_random();
        personalidad = personalidad_random();
        edad = numero_random(MAX_EDAD, 0);
        int numero = numero_random(MAX_ESPECIES, 1);
        validar_especie(especies, numero, i);

        cargar_animal(numero, *(&animales_a_rescatar[i]), nombre, tamanio, personalidad, edad);
    }
}

void Mapa::viajar(int indice){
    
}

Animal* Mapa::rescatar_animal(int indice){

    viajar(indice - 1);
    Animal *animal_rescatado = animales_a_rescatar[indice - 1];
    int i = indice - 1;
    while (i < animales_sin_rescatar() - 1){
        animales_a_rescatar[i] = animales_a_rescatar[i + 1]; 
        i++;
    }
    animales_rescatados++;
    

    return animal_rescatado;
}

Mapa::Mapa(Auto* vehiculo) {

    this->vehiculo = vehiculo;
    grafo = new Grafo();
    animales_rescatados = 0;
    llenar_vector();
    llenar_primera_fila(terreno);
    llenar_segunda_fila(terreno);
    llenar_tercera_fila(terreno);
    llenar_cuarta_fila(terreno);
    llenar_quinta_fila(terreno);
    llenar_sexta_fila(terreno);
    llenar_septima_fila(terreno);
    llenar_octava_fila(terreno);
    copiar_en_grafo();
    ubicar_auto();
    ubicar_animales();
}

void Mapa::mostrar_mapa() {

    for (int i = 0; i < MAX_TERRENO; i++) {
        for (int j = 0; j < MAX_TERRENO; j++) {
            cout << terreno[i][j] << " ";
        }
        cout << endl;
    }
}

void Mapa::copiar_en_grafo(){
    
    for (int i = 0; i < MAX_TERRENO; i++) {
        for (int j = 0; j < MAX_TERRENO; j++) {
            grafo->agregar_vertice(i, j, terreno [i][j]);
        }
    }    
}

/*
Mapa::~Mapa() {

    for (int i = 0; i < MAX_ANIMALES; i++) {
        delete animales_a_rescatar[i];
    }

    delete grafo;
}*/
