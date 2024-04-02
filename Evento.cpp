#include <iostream>
#include "Evento.h"

using namespace std;

Evento::Evento(string nombre) {
	this -> nombre = nombre;
	asistentes[100];
}

string Evento::getNombre() {
	return nombre;
}

void Evento::setNombre(string nombre) {
	this ->nombre = nombre;
}

void agregarAsistente(Asistente asistente) {

}
