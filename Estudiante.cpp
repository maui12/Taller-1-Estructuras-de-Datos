#include <iostream>
#include "Asistente.h"
#include "Estudiante.h"

using namespace std;

class Estudiante::Asistente(string nombre,int edad,string institucion):Asistente(nombre,edad){
    this -> institucion = institucion;
}
string Estudiante::getInstitucion(){
    return institucion;
}
void Estudiante::setInstitucion(string institucion){
    this -> institucion = institucion;
}