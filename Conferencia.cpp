#include <iostream>
#include "Evento.h"
#include "Conferencia.h"

using namespace std;

Conferencia::Conferencia(string nombre, string tema):Evento(nombre) {
    this -> tema = tema;
}

string Conferencia::getTema() {
	return tema;
}

void Conferencia::setTema(string tema) {
	this -> tema = tema;
}

string Conferencia::toString() {
	return "Conferencia - Nombre: "+getNombre()+" - Tema: "+getTema();
}
