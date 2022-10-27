#include <iostream>
#include "sistema.h"

int main() {

    Lista lista;
    llenar_lista(lista);

    buscar_animal(lista);
    
    lista.~Lista();

}