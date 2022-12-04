#include "../include/Arbol_b.hpp"
#include "../include/funciones_auxiliares.hpp"
#include "../include/Sistema.hpp"
#include "../include/quicksort.hpp"

#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

Arbol_B::Arbol_B(int grado){

	raiz = NULL;  
	this->grado = grado;
	cantidad_de_escapes = 0;
	cantidad_de_animales = 0;
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
		raiz->asignar_clave(0, animal_a_insertar->obtener_nombre());
		raiz->asignar_animal(0, animal_a_insertar); 
		raiz->aumentar_cant_claves();  
		cantidad_de_animales++;
	}else {
		
		if (raiz->obtener_cant_claves() == 2 * grado - 1){
	
			Nodo_arbol_B *nuevo_nodo = new Nodo_arbol_B(grado, false);

			//hago q la raiz sea hija
			nuevo_nodo->asignar_hijo(0, raiz);

			//separo
			nuevo_nodo->dividir_nodo(0, raiz);

			// nueva raiz tiene 2 hijos  decido cual de los hijos
			// va a tener una llave/clave nueva
			int i = 0;
			if (nuevo_nodo->obtener_clave(0) < animal_a_insertar->obtener_nombre())
				i++;
			nuevo_nodo->obtener_hijo(i)->insertar_cuando_no_este_lleno(animal_a_insertar);
			cantidad_de_animales++;

			// cambio raiz
			raiz = nuevo_nodo;

		}else {  //si la raiz no esta llena, llamo a insertar etc para la raiz
			raiz->insertar_cuando_no_este_lleno(animal_a_insertar);
			cantidad_de_animales++;

		}
	}
}

void Arbol_B::adoptar(string nombre) {

	int indice = 0;
	Nodo_arbol_B* nodo_encontrado = buscar_en_el_arbol(nombre, indice);

	if (!(nodo_encontrado->obtener_animal(indice)->esta_adoptado())) {
		nodo_encontrado->obtener_animal(indice)->adoptar();
	}else {
		cout << endl << "\tEste animalito ya fue adoptado, por favor inténtelo de nuevo :)" << endl;
	}
}

bool Arbol_B::vacio(){
	return (raiz == NULL);
}

void Arbol_B::actualizar_hambre_higiene(){
	recorrer_arbol(raiz, ACTUALIZAR_HAMBRE_HIGIENE); 
}

void Arbol_B::realizar_cuidado(int opcion, Animal* animal) {
  
    if (opcion == BANIAR_ANIMAL){
        if(animal->obtener_requiere_ducha()){
            animal->baniar();
            cout << endl << '\t' << "¡" << animal->obtener_nombre() << " ha sido bañado/a!" << endl << endl;
        }else{
            cout << endl << '\t' << "¡" << animal->obtener_nombre() << " no requiere ducha!" << endl << endl;
        }

    }else if (opcion == ALIMENTAR_ANIMAL){
        animal->alimentar();
        cout << endl << '\t' << "¡" << animal->obtener_nombre() << " ha sido alimentado/a!" << endl;
        cout << '\t' << "¡" << animal->obtener_comida() << " fue su alimento!" << endl << endl;
    }
}

void Arbol_B::pedir_respuesta(int &opcion) {    
   
    cout << endl << '\t' << "¿Qué desea hacer?" << endl
    << '\t' << "1. Bañar a este animal." << endl
    << '\t' << "2. Alimentar a este animal." << endl
    << '\t' << "3. Saltear a este animal." << endl
    << '\t' << "4. Volver al inicio." << endl << endl;

    cin >> opcion;
    while (opcion < BANIAR_ANIMAL || opcion > VOLVER_INICIO){
        cout << endl << '\t' << "Esa no es una de las opciones válidas, intente de nuevo: ";
        cin >> opcion;
    }
}

void Arbol_B::cuidar_individualmente(Nodo_arbol_B *nodo, int &opcion){

	int i;
	for (i = 0; i < nodo->obtener_cant_claves(); i++){
		if (!nodo->es_nodo_hoja()){ 
			cuidar_individualmente(nodo->obtener_hijo(i), opcion);
		}

		if (opcion != VOLVER_INICIO && !nodo->obtener_animal(i)->esta_adoptado()){
			nodo->imprimir_animal(i);
			pedir_respuesta(opcion);
		}
			
		if (opcion != SALTEAR_ANIMAL && opcion != VOLVER_INICIO){
			realizar_cuidado(opcion, nodo->obtener_animal(i));
		}	
	}

	if (!nodo->es_nodo_hoja() && opcion != VOLVER_INICIO){
		cuidar_individualmente(nodo->obtener_hijo(i), opcion);
	}
}

void Arbol_B::cuidar_animales(){
	
	int opcion = 0;
	cuidar_individualmente(raiz, opcion);
}


void Arbol_B::imprimir_por_espacio_y_edad(int espacio){
   
    int tope = obtener_cantidad_animales();
    Animal** vector = new Animal*[tope];
    int indice = 0;
    agregar_elementos_al_vector(vector, indice);
    Ordenamiento ordenamiento;
    ordenamiento.ordenar(vector, tope);
    
    for (int i = 0; i < tope; i++){

        if (espacio >= ESPACIO_MAXIMO) {
            mostrar_datos_animal(vector[i]);

        }else if (vector[i]->obtener_tamanio() == TAMANIO_GRANDE && espacio >= ESPACIO_GRANDE) {
            mostrar_datos_animal(vector[i]);

        }else if (vector[i]->obtener_tamanio() == TAMANIO_MEDIANO && espacio >= ESPACIO_MEDIANO) {
            mostrar_datos_animal(vector[i]);

        }else if (vector[i]->obtener_tamanio() == TAMANIO_PEQUENIO && espacio > ESPACIO_PEQUENIO) {
            mostrar_datos_animal(vector[i]);

        }else if (vector[i]->obtener_tamanio() == TAMANIO_DIMINUTO && espacio > ESPACIO_DIMINUTO) {
            mostrar_datos_animal(vector[i]);
        } 
    }
    delete[] vector;
    
}

void Arbol_B::imprimir_segun_espacio(int espacio){
	imprimir_por_espacio_y_edad(espacio);
}

void Arbol_B::revisar_hambre_higiene(){
	recorrer_arbol(raiz, REVISAR_HAMBRE_HIGIENE);
}

int Arbol_B::obtener_cantidad_de_escapes(){
	return cantidad_de_escapes;
}

void Arbol_B::guardar(fstream& archivo){

	if (raiz != NULL){
		raiz->guardar(archivo);
	}
}

void Arbol_B::agregar_elementos_al_vector(Animal** vector, int& tope){
	
	if (raiz != NULL){
		raiz->agregar_elementos_al_vector(vector, tope);
	}
}

int Arbol_B::obtener_cantidad_animales(){
	return cantidad_de_animales;
}

void Arbol_B::imprimir(){
	recorrer_arbol(raiz, LISTAR);
}

void Arbol_B::realizar_accion(Animal *animal, int accion_a_realizar){

    if (!animal->esta_eliminado()){
		switch(accion_a_realizar){

			case LISTAR:
				mostrar_datos_animal(animal);
				break;

			case ACTUALIZAR_HAMBRE_HIGIENE:
				animal->aumentar_hambre();
				animal->reducir_higiene();	
				break;

			case REVISAR_HAMBRE_HIGIENE:
				if (animal->obtener_higiene() == HIGIENE_MINIMA || animal->obtener_hambre() == HAMBRE_MAXIMA){
					animal->eliminar();
					cantidad_de_escapes++;
					avisar_usuario_escapes(animal, cantidad_de_escapes);
				}
				break;
		}
	}
}

void Arbol_B::recorrer_arbol(Nodo_arbol_B *nodo, int accion_a_realizar){
	
	int i;
	for (i = 0; i < nodo->obtener_cant_claves(); i++){
		if (!nodo->es_nodo_hoja()){ 
			recorrer_arbol(nodo->obtener_hijo(i), accion_a_realizar);
		}
		realizar_accion(nodo->obtener_animal(i), accion_a_realizar);
	}	

	if (!nodo->es_nodo_hoja()){
		recorrer_arbol(nodo->obtener_hijo(i), accion_a_realizar);
	}
}

Arbol_B::~Arbol_B(){
	delete raiz;
}