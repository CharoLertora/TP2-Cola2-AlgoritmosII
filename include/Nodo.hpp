#ifndef NODO
#define NODO
#include <iostream>
#include "Animal.hpp"
const int LLAVES_MAX_CANT = 3;


class Nodo_arbol_B{
protected:
    string *claves;  // claves//llaves
    Animal **animales;
	int grado;      // grado del arbol, supongo q para el tp3 es 3
	Nodo_arbol_B **hijos; // hijos
	int cant_claves;     
	bool es_hoja; 
public:

	
	Nodo_arbol_B(int grado, bool es_hoja);   // Constructor

	int obtener_grado();
	int obtener_cantidad();
	Nodo_arbol_B** obtener_hijos();
	bool obtener_es_hoja();
	Animal** obtener_animales();
	string* obtener_claves();
	void aumentar_claves();
	void reducir_claves();
	void insertar_cuando_no_este_lleno(Animal* animal_a_insertar);

	//funcion separar. el hijo debe estar completo caudno se llame
	void dividir_nodo(int i, Nodo_arbol_B *nodo_b);

	void imprimir();

	void imprimir_animal(int &i);

	void imprimir_segun_espacio(int espacio);

	void cuidar_animales(int &opcion);

	Nodo_arbol_B* buscar(string nombre, int &i); //devuelve null si no esta

	void actualizar_hambre_higiene();

	void agregar_elementos_al_vector(Animal** vector, int& indice);

	void revisar_hambre_higiene(int &cantidad_de_escapes);

	void guardar(fstream& archivo);

	~Nodo_arbol_B();
};

#endif