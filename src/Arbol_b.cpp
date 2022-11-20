#include "../include/Arbol_b.hpp"

#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

//constructor 
Arbol_B::Arbol_B(int grado){
	raiz = NULL;  
	this->grado = grado;
	cantidad_de_escapes = 0;
}

void Arbol_B::imprimir(){
	if (raiz != NULL){
		raiz->imprimir();
	}
}

Nodo_arbol_B* Arbol_B::buscar_en_el_arbol(string nombre, int &i){
	if(raiz != NULL){
		return raiz->buscar(nombre, i);
	}
	return NULL;
}


void Arbol_B::insertar(Animal *animal_a_insertar){
	if (raiz == NULL){
		
		raiz = new Nodo_arbol_B(grado, true);
		raiz->claves[0] = animal_a_insertar->obtener_nombre();
		raiz->animales[0] = animal_a_insertar; 
		raiz->cant_claves++;  
	}else{
		
		if (raiz->cant_claves == 2 * grado - 1){
	
			Nodo_arbol_B *nuevo_nodo = new Nodo_arbol_B(grado, false);

			//hago q la raiz sea hija
			nuevo_nodo->hijos[0] = raiz;

			//separo
			nuevo_nodo->dividir_nodo(0, raiz);

			// nueva raiz tiene 2 hijos  decido cual de los hijos
			// va a tener una llave/clave nueva
			int i = 0;
			if (nuevo_nodo->claves[0] < animal_a_insertar->obtener_nombre())
				i++;
			nuevo_nodo->hijos[i]->insertar_cuando_no_este_lleno(animal_a_insertar);

			// cambio raiz raiz
			raiz = nuevo_nodo;
		}else{  //si la raiz no esta llena, llamo a insertar etc para la raiz
			raiz->insertar_cuando_no_este_lleno(animal_a_insertar);
		}
	}
}

void Arbol_B::eliminar(string nombre){
	int indice = 0;
	Nodo_arbol_B* nodo_encontrado = buscar_en_el_arbol(nombre, indice);
	if (nodo_encontrado != NULL){
		if (nodo_encontrado->animales[indice]->esta_eliminado()){
			cout << "Este animal ya no es parte de nuestra reserva, ya fue adoptado :)" << endl;
		}else {
			nodo_encontrado->animales[indice]->eliminar();
			nodo_encontrado->cant_claves--;
		}
		
	}else {
		cout << "¡Ese animal no forma parte de nuestra reserva!" << endl;
	}
}


bool Arbol_B::vacio(){
	return (raiz == NULL);
}

void Arbol_B::actualizar_hambre_higiene(){
	raiz->actualizar_hambre_higiene(); 
}

void Arbol_B::cuidar_animales(){
	raiz->cuidar_animales();
}

void Arbol_B::imprimir_segun_espacio(int espacio){
	raiz->imprimir_segun_espacio(espacio);
}

void Arbol_B::revisar_hambre_higiene(){
	raiz->revisar_hambre_higiene(cantidad_de_escapes);
}

int Arbol_B::obtener_cantidad_de_escapes(){
	return cantidad_de_escapes;
}