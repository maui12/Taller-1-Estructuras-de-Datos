#include <iostream>
#include "Asistente.h"

using namespace std;

Asistente::Asistente(string nombre,int edad) {
    this -> nombre = nombre;
    this -> edad = edad;
}

string Asistente::getNombre() {
    return nombre;
}

string Asistente::getEdad() {
    return edad;
}