#include "../include/funciones_auxiliares.hpp"
#include "../include/Arbol_b.hpp"

string obtener_estado_adopcion(bool esta_adoptado) {
    
    if (esta_adoptado) {
        return ADOPTADO;
    }
    return NO_ADOPTADO;
}

void mostrar_datos_animal(Animal* animal){

    if (!animal->esta_eliminado()){
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