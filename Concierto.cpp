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
