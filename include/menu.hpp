#ifndef _MENU_HPP_
#define _MENU_HPP_
#include <iostream>
#include "Sistema.hpp"
#include "Perro.hpp"
#include "Gato.hpp"
#include "Lagartija.hpp"
#include "Erizo.hpp"
#include "Caballo.hpp"
#include "Roedor.hpp"
#include "Conejo.hpp"
#include "Mapa.hpp"

const int RESCATAR_ANIMAL = 1;
const int VOLVER_AL_INICIO = 2;

enum Opcion_menu {
    LISTAR_ANIMALES = 1,
    RESCATAR_ANIMALES,
    BUSCAR_ANIMAL,
    CUIDAR_ANIMALES,
    ADOPTAR_ANIMAL,
    CARGAR_COMBUSTIBLE,
    GUARDAR_Y_SALIR,
    CANTIDAD_DE_OPCIONES
};

enum Opcion_submenu {
    ELEGIR_INDIVIDUALMENTE = 1,
    REGRESAR_INICIO,
    CANTIDAD_DE_OPCIONES_SUBMENU
};

class Menu {
    //Atributos:
private:
    Mapa *mapa;

    //Métodos:
public:

    Menu(Auto *vehiculo);

    //Pre: -
    //Post: Imprime por pantalla el menu del programa
    void mostrar_menu();

    //Pre: -
    //Post: Devuelve la opcion ingresada por el usuario.
    int pedir_opcion();

    //Pre: 'opcion' debe ser pasada por referencia.
    //Post: Valida que 'opcion' esté dentro de las opciones del menu, sino vuelve a preguntar.
    void validar_opcion(int &opcion);

    //Pre: 'opcion' debe estar previamente inicializado.
    //Post: Dependiendo de la opcion, se accede a distintas funcionalidades del programa
    void procesar_opcion(Arbol_B *arbol_animales, int opcion, Auto *vehiculo);


    ~Menu();

private:

    //Pre: -
    //Post: Muestra por pantalla el submenu de la opción "Cuidar animales"
    void mostrar_submenu();

    //Pre: 'opcion' debe ser pasada por referencia.
    //Post: Valida que 'opcion' esté dentro de las opciones del submenu, sino vuelve a preguntar.
    void validar_opcion_submenu(int &opcion);

    //Pre:-
    //Post: Muestra por pantalla todos los animales de la arbol_animales, si esta vacia muestra un mensaje.
    void listar_animales(Arbol_B *arbol_animales);

    //Pre: Ambos objetos deben estar inicializados.
    //Post: Muestra por pantalla la cantidad de combustible disponible y los animales a rescatar.
    void mostrar_datos_rescate(Auto *vehiculo);

    //Pre: -
    //Post: Le muestra al usuario sus opciones.
    void mostrar_opciones();

    //Pre:-
    //Post: Le pide al usuario que ingrese una respuesta válida y no dejará de hacerlo hasta que lo haga.
    void pedir_respuesta(int &respuesta);

    //Pre:-
    //Post: Le pide al usuario que ingrese el número del animal que desea rescatar y no dejará de pedirselo hasta que ingrese un valor válido.
    void elegir_animal(int &animal);

    //Pre:-
    //Post: Le notificará al usuario que el combustible es infuciente para rescatar a ese animal y lw preguntará si desea rescatar a otro.
    void combustible_insuficiente(int &respuesta, int costo, Auto *vehiculo);

    /*
     *Pre: 
        + respuesta debe estar previamente inicializado y ser pasado por referencia.
        + costo debe ser un valor entero y positivo.
        + vehiculo debe estar previamente inicializado.
     *Post: imprimirá por pantalla un mensaje para el usuario en el caso de que tenga el combustible suficiente para rescatar al animal que eligió.
    */
    void combustible_suficiente(int &respuesta, int costo, Auto *vehiculo);

    //Pre: "palabra" debe estar inicializado.
    //Post: Devuelve true si el nombre es valido, un nombre es valido solo cuando esta compuesto de letras minusculas o mayusculas o ambas, sino false.
    bool es_nombre_valido(string palabra);

    //Pre: "nombre" debe estar inicializado.
    //Post: Valida que el nombre solo tenga letras minusculas o mayusculas o ambas, y que no sea un nombre ya existente en la reserva, sino te pide que vuelvas a ingresar otro nombre.
    void validar_nombre_animal(string &nombre, Arbol_B *arbol_animales);

    //Pre: Todos los parámetros deben ser previamente inicializados.
    //Post: Llevará a cabo el rescate del animal seleccionado, llamando a las funciones necesarias para sacarlo del mapa y agregarlo al arbol de animales.
    void realizar_rescate(Arbol_B *arbol_animales, Auto *vehiculo, int animal, int costo);
    
    //Pre: Ambos parámetros deben ser previamente inicializados.
    //Post: Le mostrará al usuario el mapa y le preguntará si desea salvar a alguno de los animales, llevando a cabo el rescate en caso de que sea posible.
    void rescatar_animal(Arbol_B *arbol_animales, Auto *vehiculo);

    //Pre: -
    //Post: devolverá true en caso de que 'nombre_buscado' sea igual a alguno de los nombres no eliminados del arbol de animales, o false en caso contrario.
    bool es_nombre_existente(string nombre_buscado, Arbol_B *arbol);

    //Pre: -
    //Post: Verificará si el nombre ingresado se encuentra en el árbol. Si eso ocurre le mostrará al usuario los datos del animal correspondiente, de lo contrario, también le notificará al usuario.
    void revisar_arbol_animales(Arbol_B *arbol, string &nombre_buscado);
    
    //Pre: -
    //Post: buscará el animal solicitado por el usuario las veces que lo desee.
    void buscar_animal(Arbol_B *arbol_animales);

    //Pre:-
    //Post: Le muestra al usuario cada animal de la lista y le pregunta si desea cuidarlo o saltearlo.
    void elegir_individualmente(Arbol_B *arbol_animales);

    //Pre: 'opcion' debe estar previamente inicializado.
    //Post: Dependiendo de la opcion, se accede a distintas funcionalidades del programa
    void procesar_opcion_submenu(Arbol_B *arbol_animales, int opcion);

    //Pre: 'sistema' debe estar previamente inicializado.
    //Post: Lleva al usuario al submenu y procesará las diferentes respuestas mientras no vuelva al inicio
    void abrir_submenu(Arbol_B *arbol_animales);

    //Pre: -
    ///Post: Le pregunta al usuario el nombre del animal que desea adoptar y en caso de que sea un nombre válido, marca ese animal como "adoptado" y le notifica al usuario.
    void realizar_adopcion(Arbol_B *arbol);

    //Pre: -
    //Post: Devuelve true si hay caracteres que no son numericos, sino false.
    bool hay_letras(string edad);

    //Pre: 'espacio' debe estar previamente inicializado y ser pasado por referencia.
    //Post: se encarga de verificar que el espacio ingresado por el usuario no contenga letras ni números negativos.
    void validar_espacio(string &espacio);

    //Pre:-
    //Post: solicita al usuario el espacio en metros cuadrados donde vivirá el animal a adoptar y le mostrará las opciones disponibles. Luego, llamará al procedimiento correspondiente para finalizar el proceso de adopción.
    void adoptar_animal(Arbol_B *arbol_animales);

    //Pre:-
    //Post: solicita al usuario la cantidad de combustible que desea cargar y luego, cargara el tanque con dicha cantidad.
    void cargar_combustible(Auto *vehiculo);
};

#endif //_MENU_HPP_