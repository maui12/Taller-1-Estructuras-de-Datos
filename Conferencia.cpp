#include <iostream>
#include "Evento.h"
#include "Conferencia.h"

using namespace std;

class Conferencia::Conferencia(string nombre, string tema):Evento(nombre) {
    this -> tema = tema;
};

int Conferencia::getTema() {
	return tema;
}

void Conferencia::setTema(string tema) {
	this -> tema = tema;
}
