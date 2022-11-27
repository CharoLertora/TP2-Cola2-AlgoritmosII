#include "../include/funciones_auxiliares.hpp"
#include "../include/Arbol_b.hpp"
#include "../include/quicksort.hpp"

bool es_nombre_existente(string nombre_buscado, Arbol_B *arbol){   
    
    int indice = 0;
    bool encontrado = false;
    Nodo_arbol_B* nodo_encontrado = arbol->buscar_en_el_arbol(nombre_buscado, indice);
        if (nodo_encontrado != NULL){
            encontrado = true;
        }

    return encontrado;
}

bool es_respuesta_valida(string respuesta) {
    return (respuesta == "si") || (respuesta == "Si");
}

bool existe_en_la_reserva(Arbol_B *arbol, string nombre) {
    
    bool existe_en_reserva = false;
    int i = 0;

    if (arbol->buscar_en_el_arbol(nombre, i) != NULL){
        existe_en_reserva = true;
    }

    return existe_en_reserva;
}

bool quiere_ingresar_otro_nombre() {
   
    bool quiere_ingresar_otro = false;
    string ingreso;

    cout << "Ese animal ya existe en nuestra Reserva" << endl;
    cout << "¿Desea ingresar otro nombre? Si/No\n" << endl << "Respuesta: ";
    getline(cin, ingreso);

    if(es_respuesta_valida(ingreso)){
        quiere_ingresar_otro = true;
    }

    return quiere_ingresar_otro;
}

void validar_nombre(Arbol_B *arbol, string &nombre) {
   
    while (existe_en_la_reserva(arbol, nombre)){
        cout << "Ya existe ese animal en el refugio, ingresa otro nombre: ";
        getline(cin >> ws, nombre);
    }
}


bool es_tamanio_valido(string tamanio) {
    return (tamanio == TAMANIO_DIMINUTO || tamanio == TAMANIO_PEQUENIO || tamanio == TAMANIO_MEDIANO || tamanio == TAMANIO_GRANDE || tamanio == TAMANIO_GIGANTE);
}

void validar_tamanio(string &tamanio) {
   
    while (!es_tamanio_valido(tamanio)){
        cout << "\nEl tamaño ingresado no es correcto, ingrese un tamaño válido" << endl
             << "Acuérdese que los tamaños válidos son: " << endl
             << "\n-Diminuto \n-Pequeño \n-Mediano \n-Grande \n-Gigante\n" << endl << "\nTamaño: ";
        getline(cin >> ws, tamanio);
    }
}

bool es_personalidad_valida(string personalidad) {
    return (personalidad == PERSONALIDAD_DORMILON || personalidad == PERSONALIDAD_JUEGUETON || personalidad == PERSONALIDAD_SOCIABLE || personalidad == PERSONALIDAD_TRAVIESO);
}

void validar_personalidad(string &personalidad) {

    while (!es_personalidad_valida(personalidad)){
        cout << "\nPersonalidad no válida, acuérdese que las personalidades válidas son: " << endl
             << "\n-Dormilon \n-Jugueton \n-Sociable \n-Travieso\n" << endl << "\nPersonalidad: ";
        getline(cin >> ws, personalidad);
    }
}

bool es_especie_valida(string especie) {
    return (especie == INICIAL_PERRO || especie == ESPECIE_PERRO || especie == INICIAL_GATO || especie == ESPECIE_GATO
    || especie == INICIAL_CABALLO || especie == ESPECIE_CABALLO || especie == INICIAL_ROEDOR || especie == ESPECIE_ROEDOR || especie == INICIAL_CONEJO || especie == ESPECIE_CONEJO 
    || especie == INICIAL_ERIZO || especie == ESPECIE_ERIZO || especie == INICIAL_LAGARTIJA || especie == ESPECIE_LAGARTIJA);
}

void validar_especie(string &especie) {
    
    while (!es_especie_valida(especie)){
        cout << "\nEspecie no válida, ingrese una especie válida, acuérdese que puede poner la incial en mayúscula o"
                "la especie completa con la inicial en mayúscula"
             << endl
             << "\n-Perro \n-Gato \n-Caballo \n-Roedor \n-Conejo \n-Erizo \n-Lagartija\n" << endl << "\nEspecie: ";
        getline(cin >> ws, especie);
    }
}

bool hay_letras(string palabra) {

    bool hay_letras = false;
    for (int i = 0; i < int(palabra.length()); i++){
        if (palabra[i] < PRIMER_NUMERO_ASCII || palabra[i] > ULTIMO_NUMERO_ASCII){
            hay_letras = true;
        }
    }
    return hay_letras;
}


string obtener_estado_adopcion(bool esta_adoptado) {
    
    if (esta_adoptado) {
        return ADOPTADO;
    }
    return NO_ADOPTADO;
}

void mostrar_datos_animal(Animal* animal){
    
    string  estado_adopcion = obtener_estado_adopcion(animal->esta_adoptado());
    cout << '\t' <<  "******************************" << endl
         << '\t' << "* Nombre: " << animal->obtener_nombre()  <<  endl
         << '\t' << "* Edad: " << animal->obtener_edad() << endl
         << '\t' << "* Tamaño: " << animal->obtener_tamanio() << endl
         << '\t' << "* Especie: " << animal->obtener_especie() << endl
         << '\t' << "* Personalidad: " << animal->obtener_personalidad() << endl
         << '\t' << "* Hambre: " << animal->obtener_hambre() << "%" << endl
         << '\t' << "* Higiene: " << animal->obtener_higiene() << "%" << endl
         << '\t' << "* Estado de adopción: " << estado_adopcion << endl
         << '\t' <<"******************************" << "\n" << endl
         << '\n' << endl;
}

/*
void preguntar_datos_animal(string &edad, string &tamanio, string &especie, string &personalidad) {
    cout << "\nIngrese la edad: " << "\nEdad: ";
    getline(cin, edad);
    validar_edad(edad);

    cout << "\nIngrese el tamaño, acuérdese que los tamaños aceptados son: " << endl << endl
         << "\t(POR FAVOR, NO INGRESAR LETRAS MAYÚSCULAS)" << endl
         << "\n-diminuto \n-pequeño \n-mediano \n-grande \n-gigante\n" << endl << "\nTamaño: ";
    getline(cin >> ws, tamanio);
    validar_tamanio(tamanio);

    cout << "\nIngrese la personalidad, acuérdese que las personalidades permitidas son las siguientes: " << endl << endl
         << "\t(POR FAVOR, INGRESAR PRIMERA LETRA EN MAYÚSCULA)" << endl
         << "\n-Dormilon \n-Jugueton \n-Sociable \n-Travieso\n" << endl << "\nPersonalidad: ";
    getline(cin >> ws, personalidad);
    validar_personalidad(personalidad);

    cout << "\nIngrese la especie, puede poner la inicial en mayúscula o la palabra completa. Acuérdese que las especies permitidas son: " << endl << endl
         << "\t \t(POR FAVOR, INGRESAR PRIMERA LETRA EN MAYÚSCULA)" << endl
         << "\n-Perro \n-Gato \n-Caballo \n-Roedor \n-Conejo \n-Erizo \n-Lagartija\n" << endl << "\nEspecie: ";
    getline(cin >> ws, especie);
    validar_especie(especie);
}*/

void validar_espacio(string &espacio) {
    
    while(hay_letras(espacio)){
        cout << "Espacio no válido, utlice números positivos, por favor!" << endl;
        getline(cin, espacio);
    }
}

void avisar_usuario_escapes(Animal *animal, int cantidad_de_escapes){
    
    cout << "¡OH NO! " << animal->obtener_nombre() << " ha escapado de la reserva porque ";
    if (animal->obtener_hambre() == HAMBRE_MAXIMA && animal->obtener_higiene() == HIGIENE_MINIMA){
		cout << "tenía mucha hambre y necesitaba bañarse." << endl;
	}else if (animal->obtener_hambre() == HAMBRE_MAXIMA){
		cout << "necesitaba alimentarse." << endl;
	}else {
		cout << "no aguantaba más sin bañarse." << endl;
	}

    if (CANT_MAXIMA_ESCAPES - cantidad_de_escapes > 0){
		cout << "Si " << (CANT_MAXIMA_ESCAPES - cantidad_de_escapes) << " animal(es) más escapa/n, la reserva será clausurada." << endl << endl;
	}
}