#include "Animal.hpp"
using namespace std;

class QuickSort {
public:
    void ordenar(Animal** &animal_vector, int tope);

private:  
    void intercambiar_elementos(Animal* &a, Animal* &b);
    int particionar (Animal** &animal_vector, int low, int high);
    void quickSort(Animal** &animal_vector, int low, int high);
};