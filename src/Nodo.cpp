#include "../include/Nodo.hpp"
#include <iostream>
using namespace std;

// Constructor 
Nodo_arbol_B::Nodo_arbol_B(int grado, bool es_hoja){
	this->grado= grado;
	this->es_hoja = es_hoja;

	claves = new string[2 * grado - 1];
	animales = new Animal *[2 * grado - 1];
	hijos = new Nodo_arbol_B *[2 * grado];

	cant_claves = 0;
}


void Nodo_arbol_B::imprimir(){

	int i;
	for (i = 0; i < cant_claves; i++){
		//si no es hoja va a los hijos antes d imprimir claves
		if (!es_hoja)
			hijos[i]->imprimir();
		if (!animales[i]->esta_eliminado()){
			cout << "================================" << endl;
			cout << "Nombre: " << claves[i] << endl;
			cout << "Edad: " << animales[i]->obtener_edad() << endl;
			cout << "Especie: " << animales[i]->obtener_especie() << endl;
			cout << "Personalidad: " << animales[i]->obtener_personalidad() << endl;
			cout << "Tamaño: " << animales[i]->obtener_tamanio() << endl;
			cout << "================================" << endl << endl;
		}		
	}


	if (!es_hoja){
		hijos[i]->imprimir();
	}
}


Nodo_arbol_B *Nodo_arbol_B::buscar(string nombre){
	int i = 0;
	while (i < cant_claves && nombre > claves[i]){
		i++;
	}
	// devuelve el nodo si el valor buscado es igual a clave[i]
	if (claves[i] == nombre){
		return this;
	}

	// si es hoja, devolver null
	if (es_hoja){
		return NULL;
	}
	// mueve hacia el hijo apropiado
	return hijos[i]->buscar(nombre);
}





void Nodo_arbol_B::insertar_cuando_no_este_lleno(Animal* animal_a_insertar){
	int i = cant_claves - 1;

	
	if (es_hoja){
		//encuentra la pos de la nueva clave para insertar y mueve todas las clave en +1
		
		while (i >= 0 && claves[i] > animal_a_insertar->obtener_nombre()){
			claves[i + 1] = claves[i];
            animales[i + 1] = animales[i];
			i--;
		}

		//inserta la clave en la nueva pos
		claves[i + 1] = animal_a_insertar->obtener_nombre();
        animales[i + 1] = animal_a_insertar;
		cant_claves++;
	}else{//si este nodo no es hoja
		//encuentra al hijo que va a tener la clave 
		while (i >= 0 && claves[i] > animal_a_insertar->obtener_nombre())
			i--;

		// chequea si esta completo el nood
		if (hijos[i + 1]->cant_claves == 2 * grado - 1){
			//divide si esta lleno
			dividir_nodo(i + 1, hijos[i + 1]);

			//dps de dividir se fija q lado va a tener la clave
			if (claves[i + 1] < animal_a_insertar->obtener_nombre()){
				i++;
			}
		}
		hijos[i + 1]->insertar_cuando_no_este_lleno(animal_a_insertar);
	}
}


void Nodo_arbol_B::dividir_nodo(int i, Nodo_arbol_B *nodo_b)
{
	//crea nodo nodo_c con grado- 1 claves
	Nodo_arbol_B *nodo_c = new Nodo_arbol_B(nodo_b->grado, nodo_b->es_hoja);
	nodo_c->cant_claves = grado - 1;

	// copia de b a c las claves
	for (int j = 0; j < grado - 1; j++){
        nodo_c->claves[j] = nodo_b->claves[j + grado];
        nodo_c->animales[j] = nodo_b->animales[j + grado];
    }


	// copia hijos de b a c
	if (!nodo_b->es_hoja){
		for (int j = 0; j < grado; j++)
			nodo_c->hijos[j] = nodo_b->hijos[j + grado];
	}

	// baja la cantidad d llaves
	nodo_b->cant_claves = grado - 1;

	// como este nodo va a tener un hijo, crea espacio
	for (int j = cant_claves; j >= i + 1; j--)
		hijos[j + 1] = hijos[j];

	// junta nodo_c con hijos[etc]
	hijos[i + 1] = nodo_c;


	//hace espacio
	for (int j = cant_claves - 1; j >= i; j--){
		claves[j + 1] = claves[j];
        animales[j + 1] = animales[j];
    }

	claves[i] = nodo_b->claves[grado - 1];
	animales[i] = nodo_b->animales[grado - 1];


	cant_claves++;
}
