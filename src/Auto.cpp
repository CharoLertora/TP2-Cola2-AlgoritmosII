#include <iostream>
#include "../include/Auto.hpp"

Auto::Auto(Vertice *pos_actual){
    this->pos_actual = pos_actual;
    combustible = TANQUE_LLENO;
}

void Auto::pedir_cantidad(int &cantidad){

    cout << "Tu tanque actualmente tiene " << combustible << " de combustible" << endl;
    cout << "Recuerde que el tanque puede tener como máximo " << TANQUE_LLENO << " de combustible." << endl;
    cout << "Ingrese la cantidad de combustible que desea cargar: ";
    cin >> cantidad;

    while(cantidad < 0 || cantidad > TANQUE_LLENO){
        cout << "Esa no es una cantidad de combustible válida" << endl;
        cout << "Recuerde que el tanque puede tener como máximo " << TANQUE_LLENO << " de combustible." << endl;
        cout << "Vuelva a intentarlo: ";
        cin >> cantidad;
    }
}

void Auto::cargar_combustible(int cantidad){
   
    if (combustible == TANQUE_LLENO){
        cout << "¡No se puede cargar combustible ya que tanque está lleno!" << endl;
    }else {
        pedir_cantidad(cantidad);
        if (combustible + cantidad <= TANQUE_LLENO){
            combustible = combustible + cantidad;
        }else {
            cout << "¡No se puede cargar esa cantidad!" << endl;
            cout << "Lo máximo que se puede cargar para llenar el tanque es: " << (TANQUE_LLENO - combustible) << endl << endl;
            cargar_combustible(cantidad);
        }
    }
}

int Auto::combustible_actual(){
    return combustible;
}
