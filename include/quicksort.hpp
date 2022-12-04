#include "Animal.hpp"
using namespace std;

class Ordenamiento {
    //Métodos:
public:

    //Pre: "&animal_vector" debe estar previamente inicializado y contener valores válidos. Lo mismo para "tope".
    //Post: Llama a la función necesaria para ordenar el vector por edad.
    void ordenar(Animal** &animal_vector, int tope);

private:  

    //Pre: "&animal_vector" debe estar previamente inicializado y contener valores válidos. Lo mismo para "alto" y "bajo".
    //Post: Se llamará a sí misma y a la función necesaria hasta que el vector se encuentre totalmente ordenado.
    void ordenamiento(Animal** &animal_vector, int bajo, int alto);

    //Pre: "&animal_vector" debe estar previamente inicializado y contener valores válidos. Lo mismo para "alto" y "bajo".
    //Post: Asigna la edad del último animal como pivote y coloca los elementos a la izquierda o a la derecha del mismo dependiendo si la edad es mayor o menor respectivamente.
    int particion(Animal** &animal_vector, int bajo, int alto);

    //Pre: ambos parámetros deben estar previamente inicializados y contener valores válidos.
    //Post: Intercambia los valores de "a" y "b" entre ellos.
    void intercambiar_elementos(Animal* &a, Animal* &b);
};
