#ifndef _SISTEMA_HPP_
#define _SISTEMA_HPP_

#include <fstream>
#include <cstring>
#include "Lista.hpp"
#include "Animal.hpp"


using namespace std;

const string ARCHIVO_ANIMALES = "animales.csv";

const string INICIAL_PERRO = "P";
const string INICIAL_GATO = "G";
const string INICIAL_CABALLO = "C";
const string INICIAL_ROEDOR = "R";
const string INICIAL_CONEJO = "O";
const string INICIAL_ERIZO = "E";
const string INICIAL_LAGARTIJA = "L";

const string ESPECIE_PERRO = "Perro";
const string ESPECIE_GATO = "Gato";
const string ESPECIE_CABALLO = "Caballo";
const string ESPECIE_ROEDOR = "Roedor";
const string ESPECIE_CONEJO = "Conejo";
const string ESPECIE_ERIZO = "Erizo";
const string ESPECIE_LAGARTIJA = "Lagartija";

const string TAMANIO_DIMINUTO = "diminuto";
const string TAMANIO_PEQUENIO = "pequeño";
const string TAMANIO_MEDIANO = "mediano";
const string TAMANIO_GRANDE = "grande";
const string TAMANIO_GIGANTE = "gigante";

const string PERSONALIDAD_DORMILON = "Dormilon";
const string PERSONALIDAD_JUEGUETON = "Jugueton";
const string PERSONALIDAD_SOCIABLE = "Sociable";
const string PERSONALIDAD_TRAVIESO = "Travieso";

const char PRIMER_NUMERO_ASCII = '0';
const char ULTIMO_NUMERO_ASCII = '9';
const int BANIAR_ANIMAL = 1;
const int ALIMENTAR_ANIMAL = 2;
const int SALTEAR_ANIMAL = 3;


class Sistema {

    //Atributos
private:
    Lista* lista_animales;
    
    //Métodos
public:
    //Constructor
    //pre:-
    //pos: Construye un objeto sistema
    Sistema();

    //pre: 'sistema' debe estar previamente inicializado.
    //pos: Inicializa el programa, mostrando el menu y llamando a las funciones correspondiente del programa
    void inicializar_sistema(Sistema sistema);

    //pre:-
    //pos: Devuelve la lista de animales.
    Lista* obtener_lista_animales();

    //pre:-
    //pos: Aumenta el hambre y reduce la higiene de todos los animales de la lista_animales
    void cambiar_hambre_higiene(Lista *lista_animales);

    //pre:-
    //pos: Muestra por pantalla todos los animales de la lista_animales, si esta vacia muestra un mensaje.
    void listar_animales(Lista *lista_animales);

    //pre:-
    //pos: Rescata un animal, preguntandole al usuario un nombre, edad, especie, personalidad y tamanio con su validacion correspondiente
    void rescatar_animal(Lista *lista_animales);

    //pre: -
    //pos: buscará el animal solicitado por el usuario las veces que lo desee.
    void buscar_animal(Lista *lista_animales);

    //pre:-
    //pos: Le muestra al usuario cada animal de la lista y le pregunta si desea cuidarlo o saltearlo.
    void elegir_individualmente(Lista *lista_animales);

    //pre:-
    //pos: Baja el hambre de todos los animales de la lista a 0%.
    void alimentar_animales(Lista *lista_animales);

    //pre:-
    //pos: Sube la hiigiene de todos los animales de la lista al 100%.
    void baniar_animales(Lista *lista_animales);

    //pre:-
    //pos: solicita al usuario el espacio en metros cuadrados donde vivirá el animal a adoptar y le mostrará las opciones disponibles. Luego, llamará al procedimiento correspondiente para finalizar el proceso de adopción.
    void adoptar_animal(Lista *lista_animales);
    
    //pre: -
    //pos: cargará toda la información que se encuentre en la lista de animales en el archivo animales.csv.
    void guardar_y_salir(Lista *lista_animales);

private:

    //pre: Los párametros nombre, edad, especie, tamanio y personalidad, que serán los atributos del animal, deben estar inicializados.
    //pos: Agrega el animal ingresado a la lista de animales.
    void agregar_animal(Lista *lista_animales, string nombre, int edad, string tamanio, string especie, string personalidad);

    //pre: '*lista_animales' debe apuntar al atributo de la clase Sistema el cuál debe estar previamente inicializado.
    //pos: Llenará la lista con los animales que encuentre en el archivo. En caso de no haber archivo, creará uno.
    void llenar_lista (Lista *lista_animales);
    
    //pre: 'espacio' debe estar previamente inicializado y debe contener un número entero mayor a 0.
    //post: mostrará por pantalla todos los animales que pueden habitar en el espacio indicado.
    void mostrar_animales_disponibles(int espacio, Lista *lista_animales);

};

#endif //_SISTEMA_H_
