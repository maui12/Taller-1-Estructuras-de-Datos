#include <iostream>
#include "Evento.h"
#include "Taller.h"

using namespace std;

Taller::Taller(string nombre, string ubicacion):Evento(nombre) {
    this -> ubicacion = ubicacion;
}

string Taller::getUbicacion() {
	return ubicacion;
}

void Taller::setUbicacion(string ubicacion) {
	this -> ubicacion = ubicacion;
}

string Taller::toString() {

	return "Taller - Nombre: "+getNombre()+" - Ubicacion: "+getUbicacion();
}

string Taller::getAtributoEvento() {
	return ubicacion;
}
int Taller::getTipo() {
	return 3;
}
