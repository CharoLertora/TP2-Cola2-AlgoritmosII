#include <iostream>
#include "sistema.h"



void agregar_animal(Lista *lista, string nombre, int edad, string tamanio, string especie, string personalidad){
   
    if (especie == INICIAL_PERRO){
        especie = ESPECIE_PERRO;
        Perro* perro = new Perro(nombre, edad, tamanio, especie, personalidad);
        lista->alta(perro, 1);
    }else if (especie == INICIAL_GATO){
        especie = ESPECIE_GATO;
        Gato* gato = new Gato(nombre, edad, tamanio, especie, personalidad);
        lista->alta(gato, 1);
    }else if (especie == INICIAL_CABALLO){
        especie = ESPECIE_CABALLO;
        Caballo* caballo = new Caballo(nombre, edad, tamanio, especie, personalidad);
        lista->alta(caballo, 1);
    }else if (especie == INICIAL_ROEDOR){
        especie = ESPECIE_ROEDOR;
        Roedor* roedor = new Roedor(nombre, edad, tamanio, especie, personalidad);
        lista->alta(roedor, 1);
    }else if (especie == INICIAL_CONEJO){
        especie = ESPECIE_CONEJO;
        Conejo* conejo = new Conejo(nombre, edad, tamanio, especie, personalidad);
        lista->alta(conejo, 1);
    }else if (especie == INICIAL_ERIZO){
        especie = ESPECIE_ERIZO;
        Erizo* erizo = new Erizo(nombre, edad, tamanio, especie, personalidad);
        lista->alta(erizo, 1);
    }else {
        especie = ESPECIE_LAGARTIJA;
        Lagartija* lagartija = new Lagartija(nombre, edad, tamanio, especie, personalidad);
        lista->alta(lagartija, 1);
    }
}

void llenar_lista (Lista *lista){

    ifstream archivo_animales(ARCHIVO_ANIMALES);
    
    if (!archivo_animales.is_open()){
        cout << "No se ha encontrado un archivo, se creará uno llamado: " << ARCHIVO_ANIMALES << endl;
        archivo_animales.open(ARCHIVO_ANIMALES, ios::out);
        archivo_animales.close();
        archivo_animales.open(ARCHIVO_ANIMALES, ios::in);
    }

    string nombre, edad, tamanio, especie, personalidad;
    int num_edad;

    while (getline (archivo_animales, nombre, ',')){ 
        getline (archivo_animales, edad, ',');
        getline (archivo_animales, tamanio, ',');
        getline (archivo_animales, especie, ',');
        getline (archivo_animales, personalidad);
        num_edad = stoi(edad);
        agregar_animal(lista, nombre, num_edad, tamanio, especie, personalidad);
    }
    archivo_animales.close();
}

bool es_respuesta_valida(string respuesta) {
    return (respuesta == "si") || (respuesta == "Si");
}


string especie_a_inicial(string especie){
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

//Precondiciones: Posicion tiene que ser menor al tope del vector
//Postcondiciones: Muestra por pantalla el libro completo(Nombre, Genero y Puntaje).
void mostrar_datos_animal(Animal* animal){

    cout << '\t' <<  "******************************" << endl
         
         << '\t' << "* Nombre: " << animal->obtener_nombre()  <<  endl
         << '\t' << "* Edad: " << animal->obtener_edad() << endl
         << '\t' << "* Tamaño: " << animal->obtener_tamanio() << endl
         << '\t' << "* Especie: " << animal->obtener_especie() << endl
         << '\t' << "* Personalidad: " << animal->obtener_personalidad() << endl
         << '\t' << "* Hambre: " << animal->obtener_hambre() << endl
         << '\t' << "* Higiene: " << animal->obtener_higiene() << endl
         << '\t' <<"******************************" << "\n" << endl
         << '\n' << endl;
}

void listar_animales(Lista *lista_animales){

    if(lista_animales->vacia()){
        cout << "LISTA VACIA, AGREGUE UN ANIMAL POR FAVOR <3" << endl;
    }else{
        cout <<  '\t' <<  "***********ANIMALES***********" << '\n' << endl;
        for (int i = 1; i < lista_animales->obtener_cantidad(); i++){
            mostrar_datos_animal(lista_animales->consulta(i));
        }
    }
}

bool existe_en_la_reserva(Lista *lista, string nombre){
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

bool quiere_ingresar_otro_nombre(){
    bool quiere_ingresar_otro = false;
    string ingreso;
    cout << "Animal ya existe en Reserva" << endl;
    cout << "Quiere ingresar otro nombre? Si/No\n" << endl << "Respuesta: ";
    getline(cin, ingreso);
    if(es_respuesta_valida(ingreso)){
        quiere_ingresar_otro = true;
    }
    return quiere_ingresar_otro;
}

void validar_nombre(Lista *lista, string &nombre){
    while (existe_en_la_reserva(lista, nombre)){
        cout << "Ya existe el animal en el refugio, ingresa otro nombre: ";
        getline(cin >> ws, nombre);
    }
}

void validar_tamanio(string &tamanio){
    while (!(tamanio == TAMANIO_DIMINUTO || tamanio == TAMANIO_PEQUENIO || tamanio == TAMANIO_MEDIANO || tamanio == TAMANIO_GRANDE || tamanio == TAMANIO_GIGANTE)){
        cout << "\nTamaño ingresado no es correcto, ingrese un tamaño valido" << endl
             << "Acuerdese que los tamaños validos son: " << endl
             << "\n-Diminuto \n-Pequeño \n-Mediano \n-Grande \n-Gigante\n" << endl << "\nTamaño: ";
        getline(cin >> ws, tamanio);
    }
}



void validar_personalidad(string &personalidad){
    while (!(personalidad == PERSONALIDAD_DORMILON || personalidad == PERSONALIDAD_JUEGUETON || personalidad == PERSONALIDAD_SOCIABLE || personalidad == PERSONALIDAD_TRAVIESO)){
        cout << "\nPersonalidad no valida, acordate que las personalidades validas son: " << endl
             << "\n-Dormilón \n-Juguetón \n-Sociable \n-Travieso\n" << endl << "\nPersonalidad: ";
        getline(cin >> ws, personalidad);
    }
}

void validar_especie(string &especie){
    while (!(especie == INICIAL_PERRO || especie == ESPECIE_PERRO || especie == INICIAL_GATO || especie == ESPECIE_GATO
    || especie == INICIAL_CABALLO || especie == ESPECIE_CABALLO || especie == INICIAL_ROEDOR || especie == ESPECIE_ROEDOR || especie == INICIAL_CONEJO || especie == ESPECIE_CONEJO 
    || especie == INICIAL_ERIZO || especie == ESPECIE_ERIZO || especie == INICIAL_LAGARTIJA || especie == ESPECIE_LAGARTIJA)){
        cout << "\nEspecie no valida, ingresa una especie valida, acordate que podes poner la incial en mayuscula o"
                "la especie completa con la inicial en mayuscula"
             << endl
             << "\n-Perro \n-Gato \n-Caballo \n-Roedor \n-Conejo \n-Erizo \n-Lagartija\n" << endl << "\nEspecie: ";
        getline(cin >> ws, especie);
    }
}

bool hay_letras_en_edad(string edad){
    bool hay_letras = false;
    for (int i = 0; i < int(edad.length()); i++){
        if (edad[i] < '0' || edad[i] > '9'){
            hay_letras = true;
        }
    }
    return hay_letras;
}

void validar_edad(string &edad){
    while (hay_letras_en_edad(edad)){
        cout << "\nEdad ingresada no valida, acordate que la edad es solo con numeros" << endl;
        cout << "\nEdad: ";
        getline(cin, edad);
    }
}

void preguntar_datos_animal(string &nombre, string &edad, string &tamanio, string &especie, string &personalidad,Lista* lista_animales){

    cout << "\nIngresa la edad: " << "\nEdad: ";
    getline(cin, edad);
    validar_edad(edad);

    cout << "\nIngresa el tamaño, acordate que los tamaños aceptados son:" << endl
         << "\n-Diminuto \n-Pequeño \n-Mediano \n-Grande \n-Gigante\n" << endl << "\nTamaño: ";
    getline(cin >> ws, tamanio);
    validar_tamanio(tamanio);

    cout << "\nIngresa la personalidad, acordate que las personalidades permitidas son las siguientes: \n" << endl
         << "\n-Dormilón \n-Juguetón \n-Sociable \n-Travieso\n" << endl << "\nPersonalidad: ";
    getline(cin >> ws, personalidad);
    validar_personalidad(personalidad);

    cout << "\nIngrese la especie, puede poner la inicial en mayuscula o la palabra completa acuerde que las especies permitidas son: " << endl
         << "\n-Perro \n-Gato \n-Caballo \n-Roedor \n-Conejo \n-Erizo \n-Lagartija\n" << endl << "\nEspecie: ";
    getline(cin >> ws, especie);
    validar_especie(especie);
}

void rescatar_animal(Lista *lista_animales){
    string nombre, edad, tamanio, especie, personalidad;
    bool ir_a_menu = false;
    cout << "\nIngresa el nombre del animal a rescatar: " << "\nNombre: ";
    getline(cin >> ws, nombre);
    while(!ir_a_menu){

        if(!existe_en_la_reserva(lista_animales, nombre)){
            ir_a_menu = true;
            preguntar_datos_animal(nombre, edad, tamanio, especie, personalidad, lista_animales);
            agregar_animal(lista_animales, nombre, stoi(edad), tamanio, especie_a_inicial(especie), personalidad);
        }else if(existe_en_la_reserva(lista_animales, nombre) && !quiere_ingresar_otro_nombre()){
            ir_a_menu = true;
        }else{
            cout << "\nIngresa el nombre del animal a rescatar: " << "\nNombre: ";
            getline(cin >> ws, nombre);
        }
    }
}
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

void revisar_lista_animales(Lista *lista, string &nombre_buscado, int &posicion_buscado) {
    
    posicion_buscado = POSICION_INICIAL;
    cout << endl << "Ingrese el nombre del animal que desea buscar por favor: " << endl;
    cin >> nombre_buscado;

    if (lista->vacia()) {

        cout << endl << "\t -- Lo sentimos, no hay animales en esta lista, no tenemos nada que buscar. --" << endl;

    } else if(!es_nombre_existente(nombre_buscado, lista, posicion_buscado)) {

        cout << endl << "-- El nombre que ingresaste no se encuentra en nuestra lista de animales :( --" << endl;
    } else {

        cout << endl << "\t -- Animalito encontrado! Sus datos son: --" << endl;
        mostrar_datos_animal(lista->consulta(posicion_buscado));
    }
}

void buscar_animal(Lista *lista) {

    string respuesta;
    string nombre_buscado;
    int posicion_buscado;

    do {
        revisar_lista_animales(lista, nombre_buscado, posicion_buscado);

        cout << "\t Desea buscar otro animal? (Rta: Si/No):" << endl;
        cin >> respuesta;

    } while(es_respuesta_valida(respuesta)); 
}

//Pre: el parámetro espacio debe ser mayor a 0.
void mostrar_animales_disponibles(int espacio, Lista *lista) {

    if (espacio >= 50) {
            listar_animales(lista);

    } else {
        
        for (int i = 1; i <= lista->obtener_cantidad(); i++) {
        
            if ((lista->consulta(i)->obtener_tamanio() == "grande") && (espacio >= 20)) {
                mostrar_datos_animal(lista->consulta(i));

            } else if ((lista->consulta(i)->obtener_tamanio() == "mediano") && (espacio >= 10)) {
                mostrar_datos_animal(lista->consulta(i));

            } else if ((lista->consulta(i)->obtener_tamanio() == "pequeño") && (espacio > 2)) {
                mostrar_datos_animal(lista->consulta(i));

            } else if ((lista->consulta(i)->obtener_tamanio() == "diminuto") && (espacio > 0)) {
                mostrar_datos_animal(lista->consulta(i));
            } 

        }
    }
}

void realizar_adopcion(Lista *lista) {
            
    string nombre_adoptado;
    int posicion = 1;

    cout << "\t Genial! :D Ingrese el nombre del animalito que le gustaría adoptar: " << endl << endl;
    cin >> nombre_adoptado;

    if (es_nombre_existente(nombre_adoptado, lista, posicion)) {
        mostrar_datos_animal(lista->consulta(posicion));
        cout << "\t HA SIDO ADOPTADO CON ÉXITO! Esperamos que sean muy felices." << endl;
        lista->baja(posicion);
    }
}

void adoptar_animal(Lista *lista) {
    
    int espacio;
    string respuesta;

    cout << "\t Ingrese el espacio en metros cuadrados del cual dispondrá el animalito para vivir (NO INGRESAR NÚMEROS MENORES A 0): " << endl;
    cin >> espacio;

    mostrar_animales_disponibles(espacio, lista);

    cout << "\t Desea adoptar a alguno de estos animalitos?: " << endl;
    cin >> respuesta;

    if (es_respuesta_valida(respuesta)) {
        
        realizar_adopcion(lista);

    } else {
        cout << "\t Lamentamos que no quieras adoptar ninguno de nuestros animalitos :( " << endl
             << "\t Te esperamos nuevamente!" << endl;
    }
}

void cambiar_hambre_higiene(Lista *lista) {

    for (int i = 1; i < lista->obtener_cantidad() + 1; i++){
        lista->consulta(i)->aumentar_hambre();
        lista->consulta(i)->reducir_higiene();
   }
}