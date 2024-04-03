#include <iostream>
#include "Evento.h"
#include "Asistente.h"

using namespace std;

Evento::Evento(string nombre) {
	this -> nombre = nombre;
	//asistentes = new Asistente*[100];
	this -> asistentes = new Asistente[100];
}

Evento::Evento() {}

string Evento::getNombre() {
	return nombre;
}

void Evento::setNombre(string nombre) {
	this ->nombre = nombre;
}

void agregarAsistente(Asistente asistente) {

}
