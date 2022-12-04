#include "../include/quicksort.hpp"
#include <iostream>

void Ordenamiento::ordenar(Animal** &animal_vector, int tope){
    ordenamiento(animal_vector, 0, (tope - 1));
}

void Ordenamiento::ordenamiento(Animal** &animal_vector, int bajo, int alto){
    
    if (bajo < alto){
        // pi: Indice de particion (cuando el pivote esta en su lugar)
        int pi = particion(animal_vector, bajo, alto);
 
        ordenamiento(animal_vector, bajo, pi - 1);
        ordenamiento(animal_vector, pi + 1, alto);
    }
}

int Ordenamiento::particion(Animal** &animal_vector, int bajo, int alto){
    
    int pivote = animal_vector[alto]->obtener_edad();

    // Indice del elemento mas chico que indica la posicion del pivote por el momento
    int i = (bajo - 1); 
 
    for (int j = bajo; j <= alto - 1; j++){
        // Si el elemento actual es mas chico que el pivote
        if (animal_vector[j]->obtener_edad() > pivote){
            // Entonces intercambio el elemento actual por el que esta a la derecha
            // de la posicion actual del pivote
            // (paso el elemento a la mitad izquierda)
            i++;
            intercambiar_elementos(animal_vector[i], animal_vector[j]);
        }
    }
    intercambiar_elementos(animal_vector[i + 1], animal_vector[alto]);
    return (i + 1);
}

void Ordenamiento::intercambiar_elementos(Animal* &A, Animal* &B) {
    
    Animal* aux = A;
    A = B;
    B = aux;
}