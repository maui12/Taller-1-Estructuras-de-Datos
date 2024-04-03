#include <iostream>
#include "Asistente.h"
#include "Profesional.h"

using namespace std;

class Profesional::Asistente(string nombre,int edad,string ocupacion):Asistente(nombre,edad){
    this -> ocupacion = ocupacion;
}
string Profesional::getOcupacion(){
    return ocupacion;
}
void Profesional::setOcupacion(string ocupacion){
    this -> ocupacion = ocupacion;
}
