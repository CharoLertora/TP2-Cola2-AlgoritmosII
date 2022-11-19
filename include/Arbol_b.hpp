#ifndef _ARBOL_B_
#define _ARBOL_B_

#include "../include/Nodo.hpp"


class Arbol_B{
	Nodo_arbol_B *raiz; 
	int grado;  //grado del arbol, creo que para nuestro TP tiene que ser 3

public:
	// Constructor 
	Arbol_B(int grado);

	void imprimir(); //imprime, no se si anda bien

	Nodo_arbol_B* buscar_en_el_arbol(string nombre);

	void insertar(Animal* animal_a_insertar);

	void eliminar(string nombre_animal);

	bool vacio();

	void actualizar_hambre_higiene();
};

#endif