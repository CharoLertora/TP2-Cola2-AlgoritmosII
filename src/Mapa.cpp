#include <iostream>
#include "../include/Mapa.hpp"

void llenar_primera_fila(char terreno[MAX_TERRENO][MAX_TERRENO]) {

    terreno[0][0] = CAMINO;
    terreno[0][1] = PRECIPICIO;
    terreno[0][2] = TIERRA;
    terreno[0][3] = TIERRA;
    terreno[0][4] = TIERRA;
    terreno[0][5] = TIERRA;
    terreno[0][6] = TIERRA;
    terreno[0][7] = TIERRA;
}

void llenar_segunda_fila(char terreno[MAX_TERRENO][MAX_TERRENO]) {

    terreno[1][0] = CAMINO;
    terreno[1][1] = TIERRA;
    terreno[1][2] = TIERRA;
    terreno[1][3] = TIERRA;
    terreno[1][4] = PRECIPICIO;
    terreno[1][5] = PRECIPICIO;
    terreno[1][6] = PRECIPICIO;
    terreno[1][7] = PRECIPICIO;
}

void llenar_tercera_fila(char terreno[MAX_TERRENO][MAX_TERRENO]) {

    terreno[2][0] = CAMINO;
    terreno[2][1] = CAMINO;
    terreno[2][2] = CAMINO;
    terreno[2][3] = CAMINO;
    terreno[2][4] = CAMINO;
    terreno[2][5] = TIERRA;
    terreno[2][6] = MONTANIA;
    terreno[2][7] = MONTANIA;
}

void llenar_cuarta_fila(char terreno[MAX_TERRENO][MAX_TERRENO]) {

    terreno[3][0] = TIERRA;
    terreno[3][1] = TIERRA;
    terreno[3][2] = TIERRA;
    terreno[3][3] = TIERRA;
    terreno[3][4] = CAMINO;
    terreno[3][5] = TIERRA;
    terreno[3][6] = MONTANIA;
    terreno[3][7] = MONTANIA;
}

void llenar_quinta_fila(char terreno[MAX_TERRENO][MAX_TERRENO]) {

    terreno[4][0] = MONTANIA;
    terreno[4][1] = MONTANIA;
    terreno[4][2] = MONTANIA;
    terreno[4][3] = TIERRA;
    terreno[4][4] = CAMINO;
    terreno[4][5] = TIERRA;
    terreno[4][6] = MONTANIA;
    terreno[4][7] = MONTANIA;
}

void llenar_sexta_fila(char terreno[MAX_TERRENO][MAX_TERRENO]) {

    terreno[5][0] = TIERRA;
    terreno[5][1] = TIERRA;
    terreno[5][2] = TIERRA;
    terreno[5][3] = TIERRA;
    terreno[5][4] = CAMINO;
    terreno[5][5] = TIERRA;
    terreno[5][6] = MONTANIA;
    terreno[5][7] = MONTANIA;
}

void llenar_septima_fila(char terreno[MAX_TERRENO][MAX_TERRENO]) {

    terreno[6][0] = TIERRA;
    terreno[6][1] = PRECIPICIO;
    terreno[6][2] = PRECIPICIO;
    terreno[6][3] = PRECIPICIO;
    terreno[6][4] = CAMINO;
    terreno[6][5] = TIERRA;
    terreno[6][6] = MONTANIA;
    terreno[6][7] = MONTANIA;
}

void llenar_octava_fila(char terreno[MAX_TERRENO][MAX_TERRENO]) {

    terreno[7][0] = TIERRA;
    terreno[7][1] = TIERRA;
    terreno[7][2] = TIERRA;
    terreno[7][3] = TIERRA;
    terreno[7][4] = CAMINO;
    terreno[7][5] = CAMINO;
    terreno[7][6] = CAMINO;
    terreno[7][7] = CAMINO;
}

Mapa::Mapa() {

    llenar_primera_fila(terreno);
    llenar_segunda_fila(terreno);
    llenar_tercera_fila(terreno);
    llenar_cuarta_fila(terreno);
    llenar_quinta_fila(terreno);
    llenar_sexta_fila(terreno);
    llenar_septima_fila(terreno);
    llenar_octava_fila(terreno);
}

void Mapa::mostrar_mapa() {

    for (int i = 0; i < MAX_TERRENO; i++) {
        for (int j = 0; j < MAX_TERRENO; j++) {
            cout << terreno[i][j] << " ";
        }
        cout << endl;
    }
}
