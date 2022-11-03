#include "funciones_auxiliares.hpp"

bool es_nombre_existente(string nombre_buscado, Lista *lista, int &posicion_buscado) {
    
    bool encontrado = false;
    
    while(!encontrado && posicion_buscado <= lista->obtener_cantidad()) {

        if (lista->consulta(posicion_buscado)->obtener_nombre() == nombre_buscado) {
            encontrado = true;
            
        } else {
            posicion_buscado++;
        }
    }
    return encontrado;
}

bool es_respuesta_valida(string respuesta) {
    return (respuesta == "si") || (respuesta == "Si");
}


string especie_a_inicial(string especie) {
    
    string inicial_especie;
    if(especie == INICIAL_PERRO || especie == ESPECIE_PERRO){
        inicial_especie = INICIAL_PERRO;

    }else if(especie == INICIAL_GATO || especie == ESPECIE_GATO){
        inicial_especie = INICIAL_GATO;

    }else if(especie == INICIAL_CABALLO || especie == ESPECIE_CABALLO){
        inicial_especie = INICIAL_CABALLO;

    }else if(especie == INICIAL_ROEDOR || especie == ESPECIE_ROEDOR){
        inicial_especie = INICIAL_ROEDOR;

    }else if(especie == INICIAL_CONEJO || especie == ESPECIE_CONEJO){
        inicial_especie = INICIAL_CONEJO;

    }else if(especie == INICIAL_ERIZO || especie == ESPECIE_ERIZO){
        inicial_especie = INICIAL_ERIZO;

    }else if(especie == INICIAL_LAGARTIJA || especie == ESPECIE_LAGARTIJA){
        inicial_especie = INICIAL_LAGARTIJA;
    }
    return inicial_especie;
}


void mostrar_datos_animal(Animal *animal) {

    cout << '\t' <<  "******************************" << endl
         
         << '\t' << "* Nombre: " << animal->obtener_nombre()  <<  endl
         << '\t' << "* Edad: " << animal->obtener_edad() << endl
         << '\t' << "* Tamaño: " << animal->obtener_tamanio() << endl
         << '\t' << "* Especie: " << animal->obtener_especie() << endl
         << '\t' << "* Personalidad: " << animal->obtener_personalidad() << endl
         << '\t' << "* Hambre: " << animal->obtener_hambre() << "%" << endl
         << '\t' << "* Higiene: " << animal->obtener_higiene() << "%" << endl
         << '\t' <<"******************************" << "\n" << endl
         << '\n' << endl;
}


bool existe_en_la_reserva(Lista *lista, string nombre) {
    
    bool existe_en_reserva = false;
    int i = 1;

    while(!existe_en_reserva && i <= lista->obtener_cantidad()){

        if(lista->consulta(i)->obtener_nombre() == nombre){
            existe_en_reserva = true;
        }
        i++;
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

void validar_nombre(Lista *lista, string &nombre) {

    while (existe_en_la_reserva(lista, nombre)){

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

bool es_nombre_valido(string palabra){
    
    bool es_nombre_valido = true;
    for (int i = 0; i < int(palabra.length()); i++){
        if ((palabra[i] < 'a' || palabra[i] > 'z') && (palabra[i] < 'A' || palabra[i] > 'Z')){
            es_nombre_valido = false;
        }
    }
    return es_nombre_valido;
}

void validar_nombre_animal(string &nombre){
    while(!es_nombre_valido(nombre)){
        cout << "\nEl nombre ingresado no es válida, acuérdese que no puede contener numeros o caracteres del tipo @-() etc" << endl;
        cout << "\nNombre: ";
        getline(cin, nombre);
    }
}
void validar_edad(string &edad) {

    while (hay_letras(edad)){
        cout << "\nLa edad ingresada no válida, acuérdese que la edad es sólo con números" << endl;
        cout << "\nEdad: ";
        getline(cin, edad);
    }
}


void preguntar_datos_animal(string &edad, string &tamanio, string &especie, string &personalidad, Lista* lista_animales) {

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
}

void revisar_lista_animales(Lista *lista, string &nombre_buscado, int &posicion_buscado) {
    
    posicion_buscado = POSICION_INICIAL;
    cout << endl << "Ingrese el nombre del animal que desea buscar por favor: " << endl;
    cin >> nombre_buscado;

    if (lista->vacia()) {
        cout << endl << "\t -- Lo sentimos, no hay animales en esta lista, no tenemos nada que buscar. --" << endl;

    } else if(!es_nombre_existente(nombre_buscado, lista, posicion_buscado)) {
        cout << endl << "-- El nombre que ingresó no se encuentra en nuestra lista de animales :( --" << endl;
    
    } else {
        cout << endl << "\t -- ¡Animalito encontrado! Sus datos son: --" << endl;
        mostrar_datos_animal(lista->consulta(posicion_buscado));
    }
}

void realizar_adopcion(Lista *lista) {
            
    string nombre_adoptado;
    int posicion = POSICION_INICIAL;

    cout << "\t Genial! :D Ingrese el nombre del animalito que le gustaría adoptar: " << endl << endl;
    cin >> nombre_adoptado;

    if (es_nombre_existente(nombre_adoptado, lista, posicion)) {
        mostrar_datos_animal(lista->consulta(posicion));
        cout << "\t ¡HA SIDO ADOPTADO CON ÉXITO! Esperamos que sean muy felices." << endl;
        lista->baja(posicion);
    }
}

void pedir_respuesta(int &opcion) {
    
    cout << endl << '\t' << "¿Qué desea hacer con este animal?" << endl
    << '\t' << "1. Bañarlo." << endl
    << '\t' << "2. Alimentarlo." << endl
    << '\t' << "3. Saltearlo." << endl << endl;

    cin >> opcion;
    while (opcion < BANIAR_ANIMAL || opcion > SALTEAR_ANIMAL){
        cout << endl << '\t' << "Esa no es una de las opciones válidas, intente de nuevo: ";
        cin >> opcion;
    }
}

void realizar_cuidado(int opcion, Animal* animal) {

    if (opcion == BANIAR_ANIMAL){
        if(animal->obtener_requiere_ducha()){
            animal->baniar();
            cout << endl << '\t' << "¡" << animal->obtener_nombre() << " ha sido bañado/a!" << endl << endl;
        }else{
            cout << endl << '\t' << "¡" << animal->obtener_nombre() << " No requiere ducha" << endl << endl;
        }

    }else if (opcion == ALIMENTAR_ANIMAL){
        animal->alimentar();
        cout << endl << '\t' << "¡" << animal->obtener_nombre() << " ha sido alimentado/a!" << endl << endl;
        cout << endl << '\t' << "¡" << animal->obtener_comida() << " fue su alimento/a!" << endl << endl;
    }
}

void validar_espacio(string &espacio) {

    while(hay_letras(espacio)){
        cout << "Espacio no valido, utlice numeros positivos por favor. Gracias!!" << endl;
        getline(cin, espacio);
    }
}
