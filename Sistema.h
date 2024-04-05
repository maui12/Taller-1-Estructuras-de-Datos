#pragma once
#include <iostream>
#include "Evento.h"
#include "Asistente.h"
#include <list>

using namespace std;

class Sistema {
	private:
		list<Evento*> eventos;
		list<Asistente*> asistentes;
	public:
		Sistema();
		void CrearEvento();
		void registrarAsistente();
		void consultarAsistentes();

		void printAsistentes();
		void printEventos();
		Evento* getEventoPorIndex(list<Evento*> eventos,int i);
		Asistente* getAsistentePorNombre(list<Asistente*> asistentes,string nombre);
		Asistente* determinarAsistente();
};
