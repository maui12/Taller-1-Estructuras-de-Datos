#include <iostream>
#include "Sistema.h"
#include "Evento.h"
#include "Asistente.h"

using namespace std;

Sistema::Sistema() {
	this -> eventos;
	this -> asistentes;
}

void Sistema::CrearEvento() {
	cout<<"=====Crear un nuevo Evento====="<<endl;
	cout<<"Ingrese nombre del nuevo evento: "<<endl;
	string nombre;
	cin >> nombre;

	Evento* evento = new Evento(nombre);

	eventos.push_front(evento);

	cout<<"Evento creado"<<endl;
}


