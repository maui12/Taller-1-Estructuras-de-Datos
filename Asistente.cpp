#include <iostream>
#include "Asistente.h"
#include "Evento.h"

using namespace std;

Asistente::Asistente(string nombre,int edad) {
    this -> nombre = nombre;
    this -> edad = edad;
    this -> eventos = new Evento[50];
}

Asistente::Asistente() {}

string Asistente::getNombre() {
    return nombre;
}

int Asistente::getEdad() {
    return edad;
}

void Asistente::setNombre(string nombre) {
	this -> nombre = nombre;
}

void Asistente::setEdad(int edad) {
    this -> edad = edad;
}

void Asistente::agregarEvento(Evento* evento) {

}
