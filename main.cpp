#include <iostream>
#include "Sistema.hpp"


int main() {

    Sistema sistema;
    sistema.inicializar_sistema(sistema.obtener_lista_animales());
    return 0;
}