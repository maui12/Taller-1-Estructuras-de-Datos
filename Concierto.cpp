#include <iostream>
#include "Evento.h"
#include "Concierto.h"

using namespace std;

Concierto::Concierto(string nombre,int duracion):Evento(nombre) {

	this -> duracion = duracion;
}

int Concierto::getDuracion() {
	return duracion;
}

void Concierto::setDuracion(int duracion) {
	this -> duracion = duracion;
}

string Concierto::toString() {

	return "Concierto - Nombre: "+getNombre()+" - Duracion: "+to_string(getDuracion());

}

string Concierto::getAtributoEvento() {
	return to_string(duracion);
}

int Concierto::getTipo() {
	return 1;
}
