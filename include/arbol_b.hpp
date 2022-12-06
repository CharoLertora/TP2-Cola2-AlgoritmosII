#ifndef _ARBOL_B_HPP_
#define _ARBOL_B_HPP_

#include "../include/nodo.hpp"

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
	//Constructor
	//Pre:
	//Post: Construye un Arbol_B del grado ingresado.
	Arbol_B(int grado);

	//Pre:
	//Post: Imprime todo el contenido del arbol.
	void imprimir();

	//Pre:
	//Post: Busca en el arbol una clave que coincida con el string ingresado y no se encuentre "eliminada", en caso de encontrarla, devuelve el nodo en el que se encuentra, sino devuelve null.
	Nodo_arbol_B* buscar_en_el_arbol(string nombre, int &i);

	//Pre: El animal debe estar previamente inicializado y contener valor válidos.
	//Post: Inserta el animal dentro del nodo correspondiente dentro del arbol.
	void insertar(Animal* animal_a_insertar);

	//Pre: El string ingresado debe estar previamente inicializado.
	//Post: Encuentra el animal que corresponda a la clave que coincida con el string ingresado y lo marca como "eliminado".
	void eliminar(string nombre_animal);

	//Pre: El string ingresado debe estar previamente inicializado.
	//Post: Encuentra el animal que corresponda a la clave que coincida con el string ingresado y lo marca como "adoptado".
	void adoptar(string nombre_animal);

	//Pre:
	//Post: Devuelve true en caso de que la raiz del arbol apunte a null, es decir que esté vacio. En caso contrario devuelve false.
	bool vacio();

	//Pre:
	//Post: Llama a la funcion necesaria que recorre el arbol, actualizando el estado de higiene y hambre de cada animal que se encuentra en él.
	void actualizar_hambre_higiene();

	//Pre:
	//Post: Llama a la funcion necesaria que le muestra al usuario cada uno de los animales del árbol permitiendole bañarlos, alimentarlos o saltearlos.
	void cuidar_animales();

	//Pre: "espacio" debe ser inicializado previamente y debe contener un valor válido.
	//Post: Llama a la funcion necesaria para mostrar los animales del arbol que pueden habitar en el espacio ingresado.
	void imprimir_segun_espacio(int espacio);

	//Pre:
	//Post: Llama a la función necesaria para que recorra el árbol, revisando si algun animal tiene su higiene en HIGIENE_MINIMA o su hambre en HAMBRE_MAXIMA, en caso de ser asì, lo marca como eliminado y le notifica al usuario.
	void revisar_hambre_higiene();

	//Pre:
	//Post: Devuelve el atributo "cantidad_de_escapes".
	int obtener_cantidad_de_escapes();

	//Pre: Ambos parámetros deben ser previamente inicializados.
	//Post: Llama a la función necesaria para agregar al vector ingresado todos los animales del arbol.
	void agregar_elementos_al_vector(Animal** vector, int& tope);

	//Pre:
	//Post: Devuelve el atributo "cantidad_de_animales".
	int obtener_cantidad_animales();

	//Pre:
	//Post: Llama a la función necesaria para guardar en el archivo todos los datos del arbol actualizados.
	void guardar(fstream& archivo);

	//Pre: Ambos parámetros deben ser válidos y estar previamente inicializados.
	//Post: Recorre todo el arbol y dependiendo de "accion_a_realizar" llama a la función correspondiente con cada animal.
	void recorrer_arbol(Nodo_arbol_B *nodo, int accion_a_realizar);

	//Pre: Ambos parámetros deben ser válidos y estar previamente inicializados.
	//Post: Dependiendo de la "accion_a_realizar", muestra los datos del animal, verifica su estado o actualiza su estado. (Siendo su estado los niveles de hambre e higiene). 
	void realizar_accion(Animal *animal, int accion_a_realizar);

    //Pre: los parámetros 'opcion' y 'animal' deben estar previamente inicializados y contener valores válidos.
    //Post: Dependiendo la opción seleccionada, baña o alimenta al animal ingresado.
    void realizar_cuidado(int opcion, Animal* animal);

	//Pre: 'opcion' debe estar previamente inicializado y ser pasado por referencia.
    //Post: Le pregunta al usuario si desea cuidar al animal o saltearlo y una vez que su respuesta es vàlida, la guarda.
    void pedir_respuesta(int &opcion);

	//Pre: Ambos parámetros deben ser válidos y estar previamente inicializados.
	//Post: Muestra indvidualmente a cada animal, permitiendole al usuario elegir qué hacer con él. Puede bañarlo, alimentarlo o saltearlo.
	void cuidar_individualmente(Nodo_arbol_B *nodo, int &opcion);

	//Pre: "espacio" debe ser inicializado previamente y debe contener un valor válido.
	//Post: Muestra los animales del arbol que pueden habitar en el espacio ingresado, y los imprime de forma ordenada, del animal más viejo al más joven.
	void imprimir_por_espacio_y_edad(int espacio);

	//Destructor
	//Pre: -
	//Post: Libera el espacio de memoria ocupado por los nodos del arbol.
	~Arbol_B();
};

#endif