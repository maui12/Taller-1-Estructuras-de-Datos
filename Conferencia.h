#pragma once
#include <iostream>
#include "Evento.h"

using namespace std;

class Conferencia:public Evento {

	private:
		string tema;
	public:
		Conferencia(string nombre, string tema);
		string getTema();
		void setTema(string tema);
		string toString();
		string getAtributoEvento();
		int getTipo();
};
