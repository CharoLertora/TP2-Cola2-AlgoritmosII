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

	//Constructor
	//Pre: Tanto "grado" como "es_hoja" deben estar inic ializados.
    //Post: Crea un nodo con todos sus punteros apuntando a null, con su grado correspondiente y su atributo "es_hoja" en true o false dependiendo lo ingresado.
	Nodo_arbol_B(int grado, bool es_hoja);   // Constructor

	//Pre: El nodo no debe encontrarse lleno.
    //Post: Se encarga de ingresar el animal en el nodo/hijo correspondiente, respetando el orden.
	void insertar_cuando_no_este_lleno(Animal* animal_a_insertar);

	//Pre: El nodo bede encontrarse lleno.
    //Post: Divivide el nodo en dos, pasando los datos e hijos necesarios al "nuevo" nodo.
	void dividir_nodo(int i, Nodo_arbol_B *nodo_b);

	//Pre: "espacio" debe tener un valor válido.
    //Post: Imprime los animales correspondientes al espacio ingresado, es decir, los animales con el tamaño adecuado para el espacio disponible.
	void imprimir_segun_espacio(int espacio);

	//Pre: Indice debe ser previamente inicializado.
    //Post: Llama a la función necesaria para imprimir los datos del animal que se encuentra en la posición vector animales correspondiente a el indice inresado.
	void imprimir_animal(int indice);

	//Pre: -
    //Post: Le permite ver al usuario cada animal del árbol que no haya sido adoptado/eliminado y bañarlo, alimentarlo o saltearlo. 
	void cuidar_animales(int &opcion);

	//Pre: -
    //Post: Busca en el árbol una clave que coincida con el nombre ingresado y devuelve el nodo donde lo encuentra. En caso de no encontrarlo, devuelve null.
	Nodo_arbol_B* buscar(string nombre, int &i); 

	//Pre: -
    //Post: Devuelve la cantidad de claves en el nodo.
	int obtener_cant_claves();

	//Pre: Indice debe ser previamente inicializado.
    //Post: Devuelve la clave que se encuentra en la posición del vector "claves" correspondiente al indice ingresado.
	string obtener_clave(int indice);

	//Pre: Indice debe ser previamente inicializado.
    //Post: Devuelve el animal que se encuentra en la posición del vector "animales" correspondiente al indice ingresado.
	Animal* obtener_animal(int indice);

	//Pre: Indice debe ser previamente inicializado.
    //Post: Devuelve el nodo que se encuentra en la posición del vector "hijos" correspondiente al indice ingresado.
	Nodo_arbol_B* obtener_hijo(int indice);

	//Pre: "Indice" y "nombre" deben ser previamente inicializados.
    //Post: Asigna el string ingresado como clave en la posición del vector "claves" correspondiente al indice ingresado.
	void asignar_clave(int indice, string nombre);

	//Pre: "Indice" y "animal" deben ser previamente inicializados.
    //Post: Asigna el animal en la posición del vector "animales" correspondiente al indice ingresado.
	void asignar_animal(int indice, Animal *animal);

	//Pre: "Indice" y "nodo" deben ser previamente inicializados.
    //Post: Asigna el nodo en la posición del vector "hijos" correspondiente al indice ingresado.
	void asignar_hijo(int indice, Nodo_arbol_B *nodo);

	//Pre: -
    //Post: Aumenta la cantidad de claves del nodo +1.
	void aumentar_cant_claves();

	//Pre: -
    //Post: Disminuye la cantidad de claves del nodo -1.
	void disminuir_cant_claves();

	//Pre: "es_hoja" debe estar inicializado.
    //Post: Devuelve el atributo "es_hoja" del nodo.
	bool es_nodo_hoja();

	//Pre: -
    //Post: Agrega en orden todos los animales del árbol en el vector ingresado.
	void agregar_elementos_al_vector(Animal** vector, int& indice);

	//Pre: -
    //Post: Se encarga de guardar en el archivo los datos de todos los animales en el árbol.
	void guardar(fstream& archivo);

	//Destructor
	//Pre: -
    //Post: Libera toda la memoria que ocupa el nodo y sus atributos.
	~Nodo_arbol_B();

private:

	//pre: el parámetro 'especie' debe estar previamente inicializado y debe contener valores válidos.
    //pos: Devuelve un string con la inicial de la especie correspondiente.
    string especie_a_inicial(string especie);
};

#endif