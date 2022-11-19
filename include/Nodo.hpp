#ifndef NODO
#define NODO
#include <iostream>
#include "Animal.hpp"
const int LLAVES_MAX_CANT = 3;


class Nodo_arbol_B{

public:
    string *claves;  // claves//llaves
    Animal **animales;
	int grado;      // grado del arbol, supongo q para el tp3 es 3
	Nodo_arbol_B **hijos; // hijos
	int cant_claves;     
	bool es_hoja; 
	Nodo_arbol_B(int grado, bool es_hoja);   // Constructor

	void insertar_cuando_no_este_lleno(Animal* animal_a_insertar);

	//funcion separar. el hijo debe estar completo caudno se llame
	void dividir_nodo(int i, Nodo_arbol_B *nodo_b);

	void imprimir();

	Nodo_arbol_B* buscar(string nombre); //devuelve null si no esta

	
};

#endif