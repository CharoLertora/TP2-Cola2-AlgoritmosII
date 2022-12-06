#include <iostream>
#include "../include/Sistema.hpp"
#include "../include/Perro.hpp"
#include "../include/Gato.hpp"
#include "../include/Caballo.hpp"
#include "../include/Roedor.hpp"
#include "../include/Conejo.hpp"
#include "../include/Erizo.hpp"
#include "../include/Lagartija.hpp"
#include "../include/funciones_auxiliares.hpp"
#include "../include/Mapa.hpp"

Sistema::Sistema()
{

    partida_terminada = false;
    arbol_animales = new Arbol_B(2);
    vehiculo = new Auto();
    llenar_arbol(arbol_animales);
}

void Sistema::inicializar_sistema(Sistema sistema)
{

    menu.mostrar_menu();
    int opcion = menu.pedir_opcion();
    menu.validar_opcion(opcion);

    while (opcion != GUARDAR_Y_SALIR && !partida_terminada) {
        cambiar_hambre_higiene(arbol_animales);
        vehiculo->reducir_combustible(REDUCCION_COMBUSTIBLE);
        menu.procesar_opcion(arbol_animales, opcion, vehiculo);
        verificar_si_partida_continua(arbol_animales);
        
        if (!partida_terminada) {
            menu.mostrar_menu();
            opcion = menu.pedir_opcion();
            menu.validar_opcion(opcion);
        }
    }
    guardar_y_salir(arbol_animales);
    
    if (opcion == GUARDAR_Y_SALIR) {
        cout << endl
        << "¡Hasta la próxima!" << endl
        << endl;
    }

    delete arbol_animales;
    delete vehiculo;
}

void Sistema::agregar_animal(Arbol_B *arbol_animales, string nombre, int edad, string tamanio, string especie, string personalidad)
{

    if (especie == INICIAL_PERRO)
    {
        especie = ESPECIE_PERRO;
        Perro *perro = new Perro(nombre, edad, tamanio, especie, personalidad);
        arbol_animales->insertar(perro);
    }
    else if (especie == INICIAL_GATO)
    {
        especie = ESPECIE_GATO;
        Gato *gato = new Gato(nombre, edad, tamanio, especie, personalidad);
        arbol_animales->insertar(gato);
    }
    else if (especie == INICIAL_CABALLO)
    {
        especie = ESPECIE_CABALLO;
        Caballo *caballo = new Caballo(nombre, edad, tamanio, especie, personalidad);
        arbol_animales->insertar(caballo);
    }
    else if (especie == INICIAL_ROEDOR)
    {
        especie = ESPECIE_ROEDOR;
        Roedor *roedor = new Roedor(nombre, edad, tamanio, especie, personalidad);
        arbol_animales->insertar(roedor);
    }
    else if (especie == INICIAL_CONEJO)
    {
        especie = ESPECIE_CONEJO;
        Conejo *conejo = new Conejo(nombre, edad, tamanio, especie, personalidad);
        arbol_animales->insertar(conejo);
    }
    else if (especie == INICIAL_ERIZO)
    {
        especie = ESPECIE_ERIZO;
        Erizo *erizo = new Erizo(nombre, edad, tamanio, especie, personalidad);
        arbol_animales->insertar(erizo);
    }
    else
    {
        especie = ESPECIE_LAGARTIJA;
        Lagartija *lagartija = new Lagartija(nombre, edad, tamanio, especie, personalidad);
        arbol_animales->insertar(lagartija);
    }
}

void Sistema::llenar_arbol(Arbol_B *arbol_animales)
{

    ifstream archivo_animales(ARCHIVO_ANIMALES);

    if (!archivo_animales.is_open())
    {
        cout << "No se ha encontrado un archivo, se creará uno llamado: " << ARCHIVO_ANIMALES << endl;
        archivo_animales.open(ARCHIVO_ANIMALES, ios::out);
        archivo_animales.close();
        archivo_animales.open(ARCHIVO_ANIMALES, ios::in);
    }

    string nombre, edad, tamanio, especie, personalidad;
    int num_edad;

    while (getline(archivo_animales, nombre, ','))
    {
        getline(archivo_animales, edad, ',');
        getline(archivo_animales, tamanio, ',');
        getline(archivo_animales, especie, ',');
        getline(archivo_animales, personalidad);
        num_edad = stoi(edad);
        agregar_animal(arbol_animales, nombre, num_edad, tamanio, especie, personalidad);
    }
    archivo_animales.close();
}

void Sistema::cambiar_hambre_higiene(Arbol_B *arbol_animales)
{
    arbol_animales->actualizar_hambre_higiene();
}

void Sistema::guardar_y_salir(Arbol_B *arbol)
{

    fstream archivo_animales(ARCHIVO_ANIMALES);
    string inicial_especie;
    arbol->guardar(archivo_animales);
    archivo_animales.close();
}

void Sistema::verificar_si_partida_continua(Arbol_B *arbol_animales)
{

    arbol_animales->revisar_hambre_higiene();
    int cant_escapes = arbol_animales->obtener_cantidad_de_escapes();
    if (cant_escapes >= CANT_MAXIMA_ESCAPES)
    {
        partida_terminada = true;
        imprimir_msje_partida_perdida();
    }
}

void Sistema::imprimir_msje_partida_perdida()
{

    cout << '\t' << "Se han escapado demasiados animales de la reserva" << endl;
    cout << '\t' << '\t' << "Tristemente será CLAUSURADA :(" << endl
         << endl;
}

Auto *Sistema::obtener_auto()
{
    return vehiculo;
}