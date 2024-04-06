#include <iostream>
#include "Asistente.h"
#include "Estudiante.h"

using namespace std;

Estudiante::Estudiante(string nombre,int edad,string institucion):Asistente(nombre,edad){
    this -> institucion = institucion;
}
string Estudiante::getInstitucion(){
    return institucion;
}
void Estudiante::setInstitucion(string institucion){
    this -> institucion = institucion;
}

string Estudiante::toStringAsistente() {
	return "Estudiante - Nombre: "+getNombre()+" - Institucion: "+getInstitucion();
}
int Estudiante::yoSoy(){
    return 2;
}

string Estudiante::getAtributo() {
	return institucion;
}
