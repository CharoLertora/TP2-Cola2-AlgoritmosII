#include "../include/quicksort.hpp"

#include <iostream>

void QuickSort::ordenar(Animal** &animal_vector, int tope) {
    quickSort(animal_vector, 0, (tope - 1));
}

void QuickSort::quickSort(Animal** &animal_vector, int low, int high){
    if (low < high){
        // pi: Indice de particion (cuando el pivote esta en su lugar)
        int pi = particionar(animal_vector, low, high);
 
        quickSort(animal_vector, low, pi - 1);
        quickSort(animal_vector, pi + 1, high);
    }
}

int QuickSort::particionar(Animal** &animal_vector, int low, int high)
{
    int pivot = animal_vector[high]->obtener_edad();

    // Indice del elemento mas chico que indica la posicion del pivote por el momento
    int i = (low - 1); 
 
    for (int j = low; j <= high - 1; j++){
        // Si el elemento actual es mas chico que el pivote
        if (animal_vector[j]->obtener_edad() > pivot){
            // Entonces intercambio el elemento actual por el que esta a la derecha
            // de la posicion actual del pivote
            // (paso el elemento a la mitad izquierda)
            i++;
            intercambiar_elementos(animal_vector[i], animal_vector[j]);
        }
    }
    intercambiar_elementos(animal_vector[i + 1], animal_vector[high]);
    return (i + 1);
}

void QuickSort::intercambiar_elementos(Animal* &A, Animal* &B) {
    Animal* aux = A;
    A = B;
    B = aux;
}