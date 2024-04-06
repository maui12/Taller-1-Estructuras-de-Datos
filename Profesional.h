#pragma once
#include <iostream>
#include "Asistente.h"


using namespace std;

class Profesional:public Asistente {

	private:
		string ocupacion;
	public:
		Profesional(string nombre, int edad, string ocupacion);
		string getOcupacion();
		void setOcupacion(string ocupacion);
		string toStringAsistente();
		int yoSoy();
		string getAtributo();
};
