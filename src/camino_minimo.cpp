#include "../include/camino_minimo.hpp"

Camino_minimo::Camino_minimo(int** matriz_grafo) {

    this->matriz_adyacencia = matriz_grafo;
    this->distancias = new int*[MAX_MATRIZ];
    this->caminos = new int*[MAX_MATRIZ];
}

void Camino_minimo::inicializar_matrices() {

    for(int i = 0; i < MAX_MATRIZ; i++){
        distancias[i] = new int[MAX_MATRIZ];
        caminos[i] = new int[MAX_MATRIZ];
    }

    for (int i = 0; i < MAX_MATRIZ; i++) {
        for (int j = 0; j < MAX_MATRIZ; j++) {
            distancias[i][j] = matriz_adyacencia[i][j];
            caminos[i][j] = j;
        }
    }
}

void Camino_minimo::calcular_caminos_minimos() {

    for (int k = 0; k < MAX_MATRIZ; k++) {
        for (int i = 0; i < MAX_MATRIZ; i++) {
            for (int j = 0; j < MAX_MATRIZ; j++) {

                if ((distancias[i][j] > distancias[i][k] + distancias[k][j]) && (distancias[k][j] != INFINITO && distancias[i][k] != INFINITO) ) {

                    distancias[i][j] = distancias[i][k] + distancias[k][j];
                    caminos[i][j] = caminos[i][k];
                }
            }
        }
    }
}

void Camino_minimo::mostrar_matrices() {
    
    cout << "Matriz de distancias:      ||           Matriz de caminos:" << endl;
    string fila_distancias;
    string fila_caminos;
    for(int i = 0; i < MAX_MATRIZ; i++){
        for(int j = 0; j < MAX_MATRIZ * 2; j++) {
            if(j == MAX_MATRIZ * 2 - 1){
                fila_distancias += "            ||           ";
                fila_caminos += "\n";
            } else if(j % 2 == 0){
                if(distancias[i][j/2] == INFINITO){
                    fila_distancias += "∞";
                } else {
                    fila_distancias += to_string(distancias[i][j/2]);
                }

                if(caminos[i][j/2] == POSICION_NO_ENCONTRADA){
                    fila_caminos += "-";
                } else {
                    fila_caminos += to_string(caminos[i][j/2]);
                }
            } else{
                fila_caminos += "|";
                fila_distancias += "|";
            }
        }
        cout << fila_distancias << fila_caminos;
        fila_distancias = "";
        fila_caminos = "";
    }
    cout << endl;
}

int Camino_minimo::calcular_costo(int origen, int destino) {
    return distancias[origen][destino];
}

int Camino_minimo::convertir_a_fila(int origen) {
    return origen / MAX_TERRENO;
}

int Camino_minimo::convertir_a_columna(int origen) {
    return origen % MAX_TERRENO;
}

void Camino_minimo::calcular_recorrido(int origen, int destino, int filas_camino[MAX_MATRIZ], int columnas_camino[MAX_MATRIZ], int &cantidad_recorrida) {

    if(caminos[origen][destino] == POSICION_NO_ENCONTRADA){
        cout << "No hay un camino que conecte " <<  origen << " con " << destino;
        
    } else {

        origen = caminos[origen][destino];
        
        filas_camino[cantidad_recorrida] = convertir_a_fila(origen);
        columnas_camino[cantidad_recorrida] = convertir_a_columna(origen);
        
        while (origen != destino){
            origen = caminos[origen][destino];
            cantidad_recorrida++;
            filas_camino[cantidad_recorrida] = convertir_a_fila(origen);
            columnas_camino[cantidad_recorrida] = convertir_a_columna(origen);
        };
    }
    cout << endl;
}

void Camino_minimo::liberar_matrices() {
    
    if(distancias != nullptr && caminos != nullptr){
        for(int i = 0; i < MAX_MATRIZ; i++){
            delete[] distancias[i];
            delete[] caminos[i];
        }
        delete[] distancias;
        delete[] caminos;

        distancias = nullptr;
        caminos = nullptr;
    }
}

Camino_minimo::~Camino_minimo() {
    
    liberar_matrices();
}

