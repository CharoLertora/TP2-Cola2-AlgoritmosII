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

bool hay_animal(string terreno[MAX_TERRENO][MAX_TERRENO], int fila, int columna){
    return (terreno[fila][columna] == IMAGEN_PERRO || terreno[fila][columna] == IMAGEN_GATO || terreno[fila][columna] == IMAGEN_CABALLO || terreno[fila][columna] == IMAGEN_CONEJO || terreno[fila][columna] == IMAGEN_ROEDOR || terreno[fila][columna] == IMAGEN_ERIZO || terreno[fila][columna] == IMAGEN_LAGARTIJA);
}

int numero_random(int rango, int minimo){
    
    srand ((unsigned)time(NULL));
    int numero = rand() % rango + minimo;
    return numero; 
}

void ubicar_auto(string terreno[MAX_TERRENO][MAX_TERRENO]){

    terreno[0][0] = AUTO;
}

void copiar_animales(Grafo *grafo, Animal *animal, int fila, int columna){

    Vertice *vertice = grafo->encontrar_vertice(fila, columna);
    if (vertice != NULL){
        vertice->asignar_animal(animal); 
    }
}

void ubicar_animal(Animal* animal, string terreno[MAX_TERRENO][MAX_TERRENO], Grafo* grafo){

    int fila = 0;
    int columna = 0;
    
    do {
        fila = numero_random(8, 0);
        columna = numero_random(8, 0);
    }while(hay_animal(terreno, fila, columna) || terreno[fila][columna] == AUTO);

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

    //copiar_animales(grafo, animal, fila, columna);
}

void ubicar_animales(string terreno[MAX_TERRENO][MAX_TERRENO], Animal* animales_a_rescatar[MAX_ANIMALES], Grafo* grafo){
    
    for (int i = 0; i < MAX_ANIMALES; i++){
        ubicar_animal(animales_a_rescatar[i], terreno, grafo);
    }
}

string tamanio_random() {
    
    int numero = numero_random(5, 1);

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

string personalidad_random() {
    
    int numero = numero_random(4, 1);

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

void cargar_animal(Animal* animal_random, string nombre, string tamanio, string personalidad, int edad) {

    string especie;
    int numero = numero_random(7, 1);

    if (numero == 1) {
        especie = ESPECIE_PERRO;
        Perro* perro = new Perro(nombre, edad, tamanio, especie, personalidad);
        animal_random = perro;

    } else if (numero == 2) {
        especie = ESPECIE_GATO;
        Gato* gato = new Gato(nombre, edad, tamanio, especie, personalidad);
        animal_random = gato;

    } else if (numero == 3) {
        especie = ESPECIE_CABALLO;
        Caballo* caballo = new Caballo(nombre, edad, tamanio, especie, personalidad);
        animal_random = caballo;

    } else if (numero == 4) {
        especie = ESPECIE_ROEDOR;
        Roedor* roedor = new Roedor(nombre, edad, tamanio, especie, personalidad);
        animal_random = roedor;

    } else if (numero == 5) {
        especie = ESPECIE_CONEJO;
        Conejo* conejo = new Conejo(nombre, edad, tamanio, especie, personalidad);
        animal_random = conejo;

    } else if (numero == 6) {
        especie = ESPECIE_ERIZO;
        Erizo* erizo = new Erizo(nombre, edad, tamanio, especie, personalidad);
        animal_random = erizo;

    } else {
        especie = ESPECIE_LAGARTIJA;
        Lagartija* lagartija = new Lagartija(nombre, edad, tamanio, especie, personalidad);
        animal_random = lagartija;
    }
}

void generar_animal_random(Animal* animal_random) {
    
    string nombre = NOMBRE_RESCATADO;
    string tamanio = tamanio_random();
    string personalidad = personalidad_random();
    int edad = numero_random(40, 0);
    
    cargar_animal(animal_random, nombre, tamanio, personalidad, edad);
}

void llenar_vector(Animal* animales_a_rescatar[MAX_ANIMALES]) {

    for (int i = 0; i < MAX_ANIMALES; i++) {
        generar_animal_random(animales_a_rescatar[i]);
    }
/*
    animales_a_rescatar[0] = new Gato("Firulais", 2, "Gigante", "Gato", "Sociable");
    animales_a_rescatar[1] = new Perro("Doggo", 7, "Grande", "Perro", "Sociable");
    animales_a_rescatar[2] = new Caballo("Tincho", 2, "Mediano", "Caballo", "Travieso");
    animales_a_rescatar[3] = new Erizo("Juanito", 11, "Diminuto", "Erizo", "Dormilón");
    animales_a_rescatar[4] = new Conejo("Blanca", 7, "Pequeño", "Conejo", "Sociable");
*/
}

Mapa::Mapa() {

    grafo = new Grafo();
    llenar_vector(animales_a_rescatar);
    llenar_primera_fila(terreno);
    llenar_segunda_fila(terreno);
    llenar_tercera_fila(terreno);
    llenar_cuarta_fila(terreno);
    llenar_quinta_fila(terreno);
    llenar_sexta_fila(terreno);
    llenar_septima_fila(terreno);
    llenar_octava_fila(terreno);
    //copiar_en_grafo(grafo);
    cout << "Especie: " << animales_a_rescatar[0]->obtener_especie() <<endl;
    /*
    ubicar_auto(terreno);
    ubicar_animales(terreno, animales_a_rescatar, grafo);
    */
}

void Mapa::mostrar_mapa() {

    for (int i = 0; i < MAX_TERRENO; i++) {
        for (int j = 0; j < MAX_TERRENO; j++) {
            cout << terreno[i][j] << " ";
        }
        cout << endl;
    }
}

void Mapa::copiar_en_grafo(Grafo *grafo){
    
    for (int i = 0; i < MAX_TERRENO; i++) {
        for (int j = 0; j < MAX_TERRENO; j++) {
            grafo->agregar_vertice(i, j, terreno [i][j]);
        }
    }    
}

