#ifndef _ARBOL_B_HPP_
#define _ARBOL_B_HPP_

#include "../include/Nodo.hpp"

const int CANT_MAXIMA_ESCAPES = 3;

enum acciones {
    LISTAR = 1,
    ACTUALIZAR_HAMBRE_HIGIENE,
	REVISAR_HAMBRE_HIGIENE,
    IMPRIMIR_SEGUN_ESPACIO,
	CUIDAR
};

class Arbol_B{
	Nodo_arbol_B *raiz; 
	int grado;  
	int cantidad_de_escapes;
	int cantidad_de_animales;

public:

	Arbol_B(int grado);

	void imprimir();

	Nodo_arbol_B* buscar_en_el_arbol(string nombre, int &i);

	void insertar(Animal* animal_a_insertar);

	void eliminar(string nombre_animal);

	void adoptar(string nombre_animal);

	bool vacio();

	void actualizar_hambre_higiene();

	void cuidar_animales();

	void mostrar_segun_espacio(Nodo_arbol_B *nodo, int espacio);

	void imprimir_segun_espacio(int espacio);

	void revisar_hambre_higiene();

	int obtener_cantidad_de_escapes();

	void agregar_elementos_al_vector(Animal** vector, int& tope);

	int obtener_cantidad_animales();

	void guardar(fstream& archivo);

	void eliminar(Nodo_arbol_B *nodo);

	void recorrer_arbol(Nodo_arbol_B *nodo, int accion_a_realizar);

	void realizar_accion(Animal *animal, int accion_a_realizar);

	void cuidar_individualmente(Nodo_arbol_B *nodo, int &opcion);

	~Arbol_B();
};

#endif