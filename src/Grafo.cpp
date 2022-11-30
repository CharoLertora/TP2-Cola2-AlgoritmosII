#include <iostream>
#include "../include/Grafo.hpp"

/*
Grafo::Grafo(){

    matriz_adyacencia = nullptr;
    vertices = new Lista();
    algoritmo = nullptr;
}
*/

int calcular_peso(string tipo_terreno) {

    if (tipo_terreno == MONTANIA){
        return COSTO_MONTANIA;
    }else if (tipo_terreno == PRECIPICIO){
        return COSTO_PRECIPICIO;
    }else if (tipo_terreno == CAMINO){
        return COSTO_CAMINO;
    }else {
        return COSTO_TIERRA;
    }
}

int Grafo::calcular_vertice(int fila, int columna) {
    return (MAX_TERRENO * fila) + columna;
}

void Grafo::calcular_adyacentes(int** matriz_adyacencia, int fila, int columna, string terreno[MAX_TERRENO][MAX_TERRENO]) {

    int origen = calcular_vertice(fila, columna);

    if (fila == 0 && columna == 0) {
        matriz_adyacencia[origen][calcular_vertice(fila, columna+1)] = calcular_peso(terreno[fila][columna+1]);
        matriz_adyacencia[origen][calcular_vertice(fila+1, columna)] = calcular_peso(terreno[fila+1][columna]);
    } else if (fila == 7 && columna == 0) {
        matriz_adyacencia[origen][calcular_vertice(fila, columna+1)] = calcular_peso(terreno[fila][columna+1]);
        matriz_adyacencia[origen][calcular_vertice(fila-1, columna)] = calcular_peso(terreno[fila-1][columna]);
    } else if (fila == 0 && columna == 7) {
        matriz_adyacencia[origen][calcular_vertice(fila, columna-1)] = calcular_peso(terreno[fila][columna-1]);
        matriz_adyacencia[origen][calcular_vertice(fila+1, columna)] = calcular_peso(terreno[fila+1][columna]);
    } else if (fila == 7 && columna == 7) {
        matriz_adyacencia[origen][calcular_vertice(fila, columna-1)] = calcular_peso(terreno[fila][columna-1]);
        matriz_adyacencia[origen][calcular_vertice(fila-1, columna)] = calcular_peso(terreno[fila-1][columna]);
    } else if (fila == 0) {
        matriz_adyacencia[origen][calcular_vertice(fila, columna+1)] = calcular_peso(terreno[fila][columna+1]);
        matriz_adyacencia[origen][calcular_vertice(fila+1, columna)] = calcular_peso(terreno[fila+1][columna]);
        matriz_adyacencia[origen][calcular_vertice(fila, columna-1)] = calcular_peso(terreno[fila][columna-1]);
    } else if (columna == 0) {
        matriz_adyacencia[origen][calcular_vertice(fila, columna+1)] = calcular_peso(terreno[fila][columna+1]);
        matriz_adyacencia[origen][calcular_vertice(fila+1, columna)] = calcular_peso(terreno[fila+1][columna]);
        matriz_adyacencia[origen][calcular_vertice(fila-1, columna)] = calcular_peso(terreno[fila-1][columna]);
    } else if (fila == 7) {
        matriz_adyacencia[origen][calcular_vertice(fila, columna+1)] = calcular_peso(terreno[fila][columna+1]);
        matriz_adyacencia[origen][calcular_vertice(fila-1, columna)] = calcular_peso(terreno[fila-1][columna]);
        matriz_adyacencia[origen][calcular_vertice(fila, columna-1)] = calcular_peso(terreno[fila][columna-1]);
    } else if (columna == 7) {
        matriz_adyacencia[origen][calcular_vertice(fila, columna-1)] = calcular_peso(terreno[fila][columna-1]);
        matriz_adyacencia[origen][calcular_vertice(fila+1, columna)] = calcular_peso(terreno[fila+1][columna]);
        matriz_adyacencia[origen][calcular_vertice(fila-1, columna)] = calcular_peso(terreno[fila-1][columna]);
    } else {
        matriz_adyacencia[origen][calcular_vertice(fila, columna-1)] = calcular_peso(terreno[fila][columna-1]);
        matriz_adyacencia[origen][calcular_vertice(fila+1, columna)] = calcular_peso(terreno[fila+1][columna]);
        matriz_adyacencia[origen][calcular_vertice(fila-1, columna)] = calcular_peso(terreno[fila-1][columna]);
        matriz_adyacencia[origen][calcular_vertice(fila, columna+1)] = calcular_peso(terreno[fila][columna+1]);
    }

}

void Grafo::cargar_matriz() {

    for (int i = 0; i < MAX_MATRIZ; i++) {
        for (int j = 0; j < MAX_MATRIZ; j++) {
            if (i == j) {
                matriz_adyacencia[i][j] = 0;    
            } else {
                matriz_adyacencia[i][j] = INFINITO;
            }
        }
    }
}

void Grafo::inicializar_matriz_adyacencia() {

    this->matriz_adyacencia = new int*[MAX_MATRIZ];
    for(int i = 0; i < MAX_MATRIZ; i++){
        this->matriz_adyacencia[i] = new int[MAX_MATRIZ];
    }
    cargar_matriz();
}

Grafo::Grafo(string terreno[MAX_TERRENO][MAX_TERRENO]) {

    inicializar_matriz_adyacencia();

    for (int i = 0; i < MAX_TERRENO; i++) {
        for (int j = 0; j < MAX_TERRENO; j++) {
            calcular_adyacentes(matriz_adyacencia, i, j, terreno);
        }
    }

    mostrar_matriz_adyacencia(matriz_adyacencia);
}

void Grafo::mostrar_matriz_adyacencia(int** matriz_adyacencia) {

    cout << "Matriz de adyacencia:" << endl;
    for(int i = 0; i < MAX_MATRIZ; i++){
        for(int j = 0; j < MAX_MATRIZ * 2; j++) {
            if(j == MAX_MATRIZ * 2 - 1){
                cout << endl;
            } else if(j % 2 == 0){
                if(matriz_adyacencia[i][j/2] == INFINITO){
                    cout << "∞";
                } else {
                    cout << matriz_adyacencia[i][j/2];
                }
            } else{
                cout << "|";
            }
        }
    }
    cout << endl;
    /*
    for(int i = 0; i < MAX_MATRIZ; i++) {
        for(int j = 0; j < MAX_MATRIZ; j++) {
            cout << matriz_adyacencia[i][j] << " ";
        }
        cout << endl;
    }
    */
}

/*
void Grafo::agregar_vertice(int numero){

    agrandar_matriz_adyacencia();
    vertices->agregar(numero);

}

void Grafo:: agrandar_matriz_adyacencia() {
    int** matriz_auxiliar;
    int nueva_cantidad_vertices = vertices->obtener_cantidad() + 1;

    matriz_auxiliar = new int*[nueva_cantidad_vertices];
    
    for (int i = 0; i < nueva_cantidad_vertices; i++) {
        matriz_auxiliar[i] = new int[nueva_cantidad_vertices];
    }

    copiar_matriz_adyacente(matriz_auxiliar);
    inicializar_nuevo_vertice(matriz_auxiliar);
    liberar_matriz_adyacente();
    matriz_adyacencia = matriz_auxiliar;
}

void Grafo::copiar_matriz_adyacente(int** nueva_matriz) {

    for(int i = 0; i < vertices->obtener_cantidad(); i++) {
        for (int j = 0; j < vertices->obtener_cantidad(); j++) {
            nueva_matriz[i][j] = matriz_adyacencia[i][j];
        }
    }
}

void Grafo::inicializar_nuevo_vertice(int** nueva_matriz) {
    
    for (int i = 0; i < vertices->obtener_cantidad(); i++) {
        nueva_matriz[vertices->obtener_cantidad()][i] = INFINITO;
        nueva_matriz[i][vertices->obtener_cantidad()] = INFINITO;
    }
    nueva_matriz[vertices->obtener_cantidad()][vertices->obtener_cantidad()] = 0;
}

void Grafo::liberar_matriz_adyacente() {

    for (int i = 0; vertices->obtener_cantidad(); i++) {
        delete[] matriz_adyacencia[i];
    }
    delete[] matriz_adyacencia;
}

void Grafo::agregar_camino(int numero_origen, int numero_destino, int peso) {

    int posicion_origen = vertices->obtener_posicion(numero_origen);
    int posicion_destino = vertices->obtener_posicion(numero_destino);

    if (posicion_origen == POSICION_NO_ENCONTRADA) {
        cout << endl << "El vértice " << numero_origen << " no existe en el grafo." << endl;
    }
    if (posicion_destino == POSICION_NO_ENCONTRADA) {
        cout << endl << "El vértice " << numero_destino << " no existe en el grafo." << endl;
    }

    if (!(posicion_destino == POSICION_NO_ENCONTRADA || posicion_destino == POSICION_NO_ENCONTRADA)) {
        matriz_adyacencia[posicion_origen][posicion_destino] = peso;
        matriz_adyacencia[posicion_destino][posicion_origen] = peso;
    }
}

void Grafo::crear_algoritmo_camino() {
    delete algoritmo;
    algoritmo = new Camino_minimo(vertices, matriz_adyacencia);
}

void Grafo::camino_minimo(int numero_origen, int numero_destino) {

    int posicion_origen = vertices->obtener_posicion(numero_origen);
    int posicion_destino = vertices->obtener_posicion(numero_destino);

    if (!(posicion_destino == POSICION_NO_ENCONTRADA || posicion_origen == POSICION_NO_ENCONTRADA)) {
        algoritmo->camino_minimo(numero_origen, numero_destino);
    }
}

Grafo::~Grafo() {

    liberar_matriz_adyacente();
    matriz_adyacencia = nullptr;
    delete vertices;
    delete algoritmo;
}
*/

/*
void Grafo::agregar_vertice(int fila, int columna, string tipo_terreno){
    Vertice *vertice = new Vertice(fila, columna, tipo_terreno);
    vertices->alta(vertice, cant_vertices + 1);
    cant_vertices++;
}

Lista* Grafo::obtener_vertices(){
    return vertices;
}

Vertice* Grafo::encontrar_vertice(int fila, int columna){
    int i = 0;
    bool encontrado = false; 
    while (!encontrado && i < cant_vertices){
        if ((vertices->consulta(i + 1)->obtener_fila() == fila) && (vertices->consulta(i + 1)->obtener_columna() == columna)){
            encontrado = true;
        }else {
            i++;
        }
    }
    
    if (encontrado){
        return vertices->consulta(i + 1);
    }else{
        return NULL;
    }
}

*/