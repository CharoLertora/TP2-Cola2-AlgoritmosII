#ifndef _SISTEMA_HPP_
#define _SISTEMA_HPP_

#include <fstream>
#include <cstring>
#include "Lista.hpp"
#include "Animal.hpp"
#include "menu.hpp"

using namespace std;

const string ARCHIVO_ANIMALES = "animales.csv";

const string INICIAL_PERRO = "P";
const string INICIAL_GATO = "G";
const string INICIAL_CABALLO = "C";
const string INICIAL_ROEDOR = "R";
const string INICIAL_CONEJO = "C";
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

const int BANIAR_ANIMAL = 1;
const int ALIMENTAR_ANIMAL = 2;
const int SALTEAR_ANIMAL = 3;


class Sistema {

    private:
        Lista* lista_animales;
    
    public:
        Sistema();
        void inicializar_sistema(Lista *lista_animales);
        Lista* obtener_lista_animales();

    private:
        void agregar_animal(Lista *lista_animales, string nombre, int edad, string tamanio, string especie, string personalidad);
        void llenar_lista (Lista *lista_animales);
        void listar_animales(Lista *lista_animales);
        void rescatar_animal(Lista *lista_animales);
        void buscar_animal(Lista *lista_animales);
        void elegir_individualmente(Lista *lista_animales);
        void alimentar_animales(Lista *lista_animales);
        void baniar_animales(Lista *lista_animales);
        void mostrar_animales_disponibles(int espacio, Lista *lista_animales);
        void adoptar_animal(Lista *lista_animales);
        void cambiar_hambre_higiene(Lista *lista_animales);
        void guardar_y_salir(Lista *lista_animales);

        //Precondciones:
        //Postcondiciones: Dependiendo de la opcion, se accede a distinas funcionalidades del programa
        void procesar_opcion(Lista *lista_animales, int opcion);

        //Precondciones:
        //Postcondiciones: Dependiendo de la opcion, se accede a distinas funcionalidades del programa
        void procesar_opcion_submenu(Lista* lista_animales, int opcion);

        //Precondciones:
        //Postcondiciones: Lleva al usuario al submenu y procesará las diferentes respuestas mientras no vuelva al inicio
        void abrir_submenu(Lista *lista_animales);

};

#endif //_SISTEMA_H_
