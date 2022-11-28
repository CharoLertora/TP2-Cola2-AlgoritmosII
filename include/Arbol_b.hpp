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

    //pre: los parámetros 'opcion' y 'animal' deben estar previamente inicializados y contener valores válidos.
    //pos: Dependiendo la opción seleccionada, baña o alimenta al animal ingresado.
    void realizar_cuidado(int opcion, Animal* animal);

	//pre: 'opcion' debe estar previamente inicializado y ser pasado por referencia.
    //pos: Le pregunta al usuario si desea cuidar al animal o saltearlo y una vez que su respuesta es vàlida, la guarda.
    void pedir_respuesta(int &opcion);

	void cuidar_individualmente(Nodo_arbol_B *nodo, int &opcion);

	void imprimir_por_espacio_y_edad(int espacio);

	void eliminar_nodos(Nodo_arbol_B *nodo);

	~Arbol_B();
};

#endif