#include "Animal.hpp"
using namespace std;

class QuickSort {
public:
    void sort(Animal** &animal_vector, int tope);

private:  
    void swapElements(Animal* &a, Animal* &b);
    int partition (Animal** &animal_vector, int low, int high);
    void quickSort(Animal** &animal_vector, int low, int high);
};