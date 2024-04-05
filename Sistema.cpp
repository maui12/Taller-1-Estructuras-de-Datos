#include <iostream>
#include <list>
#include <vector>
#include "Sistema.h"
#include "Evento.h"
#include "Asistente.h"
#include "Conferencia.h"
#include "Concierto.h"
#include "Taller.h"
#include "Profesional.h"
#include "Estudiante.h"
#include "Artista.h"

using namespace std;



Sistema::Sistema() {
}

void Sistema::CrearEvento() {
	cout<<"=====Crear un nuevo Evento===== \nElija el tipo de evento: \n1)Conferencia 2)Concierto 3)Taller"<<endl;
	int tipo;
	cin >> tipo;

	if(tipo != 1 && tipo != 2 && tipo != 3) {
		cout<<"Dato invalido";
		return;
	}

	cout<<"Ingrese nombre del nuevo evento: "<<endl;
	string nombre;
	cin >> nombre;

	string atributo;
	Evento* evento;

	switch(tipo) {
	case 1:
		cout<<"Conferencia: señale el tema: "<<endl;
		cin >> atributo;
		evento = new Conferencia(nombre,atributo);
		break;
	case 2:
		cout<<"Concierto: señale la duracion: "<<endl;
		cin >> atributo;
		evento = new Concierto(nombre,stoi(atributo));

		break;
	case 3:
		cout<<"Taller: señale la ubicacion: "<<endl;
		cin >> atributo;
		evento = new Taller(nombre,atributo);
		break;

	}

	eventos.push_back(evento);

	cout<<"Evento creado"<<endl;
}

void Sistema::registrarAsistente() {

	Asistente* asistente = determinarAsistente();
	if(asistente == NULL) {
		return;
	}
	int resp;
	cout<<"¿Quiere inscribir eventos a este asistente?\n1)Si 2)No"<<endl;
	cin >> resp;

	if(resp==1) {
		if(eventos.size() == 0) {
			cout<<"No hay eventos"<<endl;
			return;
		}
		cout<<"Seleccione un evento: "<<endl;

		printEventos();

		int seleccion;
		cin >> seleccion;

		Evento* eventoActual = getEventoPorIndex(eventos, seleccion);
		eventoActual->agregarAsistente(asistente);
		asistente->agregarEvento(eventoActual);

		cout<<"Asistente inscrito al Evento"<<endl;

	}


}

void Sistema::consultarAsistentes() {
	cout<<"Lista de Asistentes:"<<endl;
	printAsistentes();
}

void Sistema::printAsistentes() {
	int contador = 0;
	Asistente* a;
	for(list<Asistente*>::iterator it = asistentes.begin(); it != asistentes.end(); it++ ){
		a = *it;
		cout<<contador<<") "<<a->toStringAsistente()<<endl;
		contador++;
	}
}

void Sistema::printEventos() {
	int contador = 0;
	Evento* e;
	for(list<Evento*>::iterator it = eventos.begin(); it != eventos.end(); it++ ){
		e = *it;
		cout<<contador<<") "<<e->toString()<<endl;
		contador++;
	}
}

Evento* Sistema::getEventoPorIndex(list<Evento*> eventos,int i) {
	list<Evento*>::iterator it = eventos.begin();
	for(int j=0; j<i;j++){
		++it;
	}
	return *it;
}

Asistente* Sistema::getAsistentePorNombre(list<Asistente*> asistentes,string nombre) {
    for(list<Asistente*>::iterator it = asistentes.begin(); it != asistentes.end(); it++ ){
        Asistente* a = *it;
        if(a->getNombre() == nombre) {
            return a;
        }
    }
    return NULL;
}

Asistente* Sistema::determinarAsistente() {
	cout<<"Desea registrar un nuevo Asistente o uno ya existente? \n1)Nuevo 2)Existente"<<endl;
	int resp;
	cin >> resp;

	if(resp == 1) {
		cout<<"=====Registrar nuevo Asistente===== \nElija de asistente: \n1)Profesional 2)Estudiante 3)Artista"<<endl;
		int tipo;
		cin >> tipo;

		if(tipo != 1 && tipo != 2 && tipo != 3) {
			cout<<"Dato invalido";
			return NULL;
		}
		cout<<"Ingrese nombre del asistente: "<<endl;
		string nombre;
		cin >> nombre;

		cout<<"Ingrese edad del asistente: "<<endl;
		int edad;
		cin >> edad;

		string atributo;
		Asistente* asistente;

		switch(tipo) {
			case 1:
				cout<<"Profesional: señale la ocupacion: "<<endl;
				cin >> atributo;
				asistente = new Profesional(nombre,edad,atributo);
				break;
			case 2:
				cout<<"Estudiante: indique la institucion: "<<endl;
				cin >> atributo;
				asistente = new Estudiante(nombre,edad,atributo);
				break;
			case 3:
				cout<<"Artista: indique el nombre artistico: "<<endl;
				cin >> atributo;
				asistente = new Artista(nombre,edad,atributo);
				break;
			}

		asistentes.push_back(asistente);
		cout<<"Asistente creado"<<endl;
		return asistente;
	}


	else if(resp == 2) {
		cout<<"Indique el nombre del asistente: "<<endl;
		string nombre;
		cin >> nombre;

		Asistente* asistenteEncontrado = getAsistentePorNombre(asistentes, nombre);

		if(asistenteEncontrado == NULL) {
			cout<< "Asistente no encontrado"<<endl;
			return NULL;
		}

		cout<< asistenteEncontrado->getNombre()<<": Asistente encontrado"<<endl;

		return asistenteEncontrado;
	}

	return NULL;

}



