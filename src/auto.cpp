#include <iostream>
#include "../include/auto.hpp"

Auto::Auto(){
    combustible = TANQUE_LLENO;
    posicion.fila = POS_INICIAL;
    posicion.columna = POS_INICIAL;
}

void Auto::validar_cantidad(int &cantidad){

    while(cantidad < 0 || cantidad > TANQUE_LLENO){
        cout << endl << "Esa no es una cantidad de combustible válida" << endl;
        cout << "Su respueste debe estar entre 0 y " << TANQUE_LLENO << "." << endl;
        cout << "Vuelva a intentarlo: ";
        cin >> cantidad;
    }

    while(cantidad + combustible > TANQUE_LLENO){
        cout << endl << "¡No se puede cargar tanta cantidad!" << endl;
        cout << "Lo máximo que se puede cargar para llenar el tanque es: " << (TANQUE_LLENO - combustible) << endl << endl;
        cout << "Intentá de nuevo: ";
        cin >> cantidad;
    }
}

void Auto::pedir_cantidad(int &cantidad){

    cout << "Tu tanque actualmente tiene " << combustible << " de combustible" << endl;
    cout << "Recuerde que el tanque puede tener como máximo " << TANQUE_LLENO << " de combustible." << endl;
    cout << "Ingrese la cantidad de combustible que desea cargar: ";
    cin >> cantidad;

    validar_cantidad(cantidad);
}

void Auto::cargar_combustible(){

    int cantidad = 0;   
    if (combustible == TANQUE_LLENO){
        cout << "¡No se puede cargar combustible ya que tanque está lleno!" << endl;
    }else {
        pedir_cantidad(cantidad);
        combustible = combustible + cantidad;
        cout << endl << '\t' << "¡Se ha cargado el tanque con éxito!" << endl;
        cout << '\t' << "Ahora el tanque tiene " << combustible << " de combustible." << endl << endl;
    }
}

int Auto::combustible_actual(){
    return combustible;
}

void Auto::reducir_combustible(int reduccion){
    combustible = combustible - reduccion;
}

void Auto::asignar_posicion(coordenada nueva_pos){
    posicion.fila = nueva_pos.fila;
    posicion.columna = nueva_pos.columna;
}

coordenada Auto::obtener_pos(){
    return posicion;
}