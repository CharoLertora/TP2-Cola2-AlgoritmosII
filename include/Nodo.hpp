#ifndef NODO
#define NODO
#include <iostream>
#include "Animal.hpp"

const int MAX_CLAVES  = 2;
const int MAX_HIJOS = 3;

class Nodo_arbol_B{
	//Atributos:
private:
    string *claves; 
    Animal **animales; 
	Nodo_arbol_B **hijos; 
	int grado;   
	int cant_claves;     
	bool es_hoja; 

	//Métodos:
public:
	Nodo_arbol_B(int grado, bool es_hoja);   // Constructor

	void inicializar_vectores();

	void insertar_cuando_no_este_lleno(Animal* animal_a_insertar);

	//funcion separar. el hijo debe estar completo caudno se llame
	void dividir_nodo(int i, Nodo_arbol_B *nodo_b);

	void imprimir_segun_espacio(int espacio);

	void cuidar_animales(int &opcion);

	Nodo_arbol_B* buscar(string nombre, int &i); //devuelve null si no esta

	void agregar_elementos_al_vector(Animal** vector, int& indice);

	void imprimir_animal(int indice);

	void guardar(fstream& archivo);

	int obtener_cant_claves();

	string obtener_clave(int indice);

	Animal* obtener_animal(int indice);

	Nodo_arbol_B* obtener_hijo(int indice);

	void asignar_clave(int indice, string nombre);

	void asignar_animal(int indice, Animal *animal);

	void asignar_hijo(int indice, Nodo_arbol_B *nodo);

	void aumentar_cant_claves();

	void disminuir_cant_claves();

	bool es_nodo_hoja();

	//pre: el parámetro 'especie' debe estar previamente inicializado y debe contener valores válidos.
    //pos: Devuelve un string con la inicial de la especie correspondiente.
    string especie_a_inicial(string especie);

	~Nodo_arbol_B();
};

#endif