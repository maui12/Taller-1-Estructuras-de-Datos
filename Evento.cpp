#include <iostream>
#include <list>
#include "Evento.h"
#include "Asistente.h"

using namespace std;

Evento::Evento(string nombre) {
	this -> nombre = nombre;

}

string Evento::getNombre() {
	return nombre;
}

void Evento::setNombre(string nombre) {
	this ->nombre = nombre;
}

void Evento::agregarAsistente(Asistente* asistente) {
	asistentes.push_back(asistente);
}

string toString(){
	return "";
}



