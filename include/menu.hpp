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
    //Atributos


    //Métodos:
public:

    //Pre: -
    //Pos: Imprime por pantalla el menu del programa
    void mostrar_menu();

    //Pre: -
    //Post: Devuelve la opcion ingresada por el usuario.
    int pedir_opcion();

    //Pre: 'opcion' debe ser pasada por referencia.
    //Post: Valida que 'opcion' esté dentro de las opciones del menu, sino vuelve a preguntar.
    void validar_opcion(int &opcion);

    //Pre: -
    //Post: Muestra por pantalla el submenu de la opción "Cuidar animales"
    void mostrar_submenu();

    //Pre: 'opcion' debe ser pasada por referencia.
    //Post: Valida que 'opcion' esté dentro de las opciones del submenu, sino vuelve a preguntar.
    void validar_opcion_submenu(int &opcion);

    //Pre: 'opcion' debe estar previamente inicializado.
    //Post: Dependiendo de la opcion, se accede a distintas funcionalidades del programa
    void procesar_opcion(Arbol_B *arbol_animales, int opcion, Auto *vehiculo);

    //pre:-
    //pos: Muestra por pantalla todos los animales de la arbol_animales, si esta vacia muestra un mensaje.
    void listar_animales(Arbol_B *arbol_animales);

    void mostrar_datos_rescate(Auto *vehiculo, Mapa mapa);

    void mostrar_opciones(Mapa mapa_juego);

    void pedir_respuesta(int &respuesta);

    void elegir_animal(int &animal, Mapa mapa);
    
    void rescatar_animal(Arbol_B *arbol_animales, Auto *vehiculo);

    // pre: -
    // pos: devolverá true en caso de que 'nombre_buscado' sea igual a alguno de los nombres no eliminados de la lista de animales, o false en caso contrario.
    bool es_nombre_existente(string nombre_buscado, Arbol_B *arbol);

    //pre: -
    //pos: Verificará si el nombre ingresado se encuentra en el árbol. Si eso ocurre le mostrará al usuario los datos del animal correspondiente, de lo contrario, también le notificará al usuario.
    void revisar_arbol_animales(Arbol_B *arbol, string &nombre_buscado);
    
    //pre: -
    //pos: va a devolver true en caso de que la respuesta coincida con si/Si, y false en cualquier otro caso.
    bool es_respuesta_valida(string respuesta);

    //pre: -
    //pos: buscará el animal solicitado por el usuario las veces que lo desee.
    void buscar_animal(Arbol_B *arbol_animales);

    //pre:-
    //pos: Le muestra al usuario cada animal de la lista y le pregunta si desea cuidarlo o saltearlo.
    void elegir_individualmente(Arbol_B *arbol_animales);

    //Pre: 'opcion' debe estar previamente inicializado.
    //Post: Dependiendo de la opcion, se accede a distintas funcionalidades del programa
    void procesar_opcion_submenu(Arbol_B *arbol_animales, int opcion);

    //Pre: 'sistema' debe estar previamente inicializado.
    //Post: Lleva al usuario al submenu y procesará las diferentes respuestas mientras no vuelva al inicio
    void abrir_submenu(Arbol_B *arbol_animales);

    //pre: -
    ///pos: Le pregunta al usuario el nombre del animal que desea adoptar y en caso de que sea un nombre válido, marca ese animal como "adoptado" y le notifica al usuario.
    void realizar_adopcion(Arbol_B *arbol);

    //pre: -
    //pos: Devuelve true si hay caracteres que no son numericos, sino false.
    bool hay_letras(string edad);

    //pre: 'espacio' debe estar previamente inicializado y ser pasado por referencia.
    //pos: se encarga de verificar que el espacio ingresado por el usuario no contenga letras ni números negativos.
    void validar_espacio(string &espacio);

    //pre:-
    //pos: solicita al usuario el espacio en metros cuadrados donde vivirá el animal a adoptar y le mostrará las opciones disponibles. Luego, llamará al procedimiento correspondiente para finalizar el proceso de adopción.
    void adoptar_animal(Arbol_B *arbol_animales);

    //pre:-
    //pos: solicita al usuario la cantidad de combustible que desea cargar y luego, cargara el tanque con dicha cantidad.
    void cargar_combustible(Auto *vehiculo);
};

#endif //_MENU_HPP_