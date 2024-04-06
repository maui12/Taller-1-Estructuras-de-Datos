#include <iostream>
#include <list>
#include <fstream>
#include <sstream>
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

void Sistema::leer() {
	ifstream archivo("Asistentes.txt");
	    string linea;
	    while (getline(archivo, linea)) {
			stringstream ss(linea);
			string tipo, nombre, atributo;
	        int edad;
	        getline(ss, tipo, ',');
	        getline(ss, nombre, ',');
	        ss >> edad;
	        ss.ignore();
	        getline(ss, atributo);
			Asistente* asistente;
				if(tipo=="Profesional"){
					asistente = new Profesional(nombre,edad,atributo);
				}
				else if(tipo=="Estudiante"){
					asistente = new Estudiante(nombre,edad,atributo);
				}
				else if(tipo=="Artista"){
					asistente = new Artista(nombre,edad,atributo);
				}else{
					cout<<tipo<<": no es un tipo valido de Asistente."<<endl;
				}
			asistentes.push_back(asistente);
	    }
	    archivo.close();

		ifstream archivo2("Evento.txt");
	    string linea2;
	    while (getline(archivo2, linea2)) {
			stringstream ss(linea2);
			string tipo, nombre, atributo;
			int duracion;
	        getline(ss, tipo, ',');
	        getline(ss, nombre, ',');
			if(tipo=="Concierto"){
				ss >> duracion;
	        	ss.ignore();
			}else{
	        getline(ss, atributo);
			}
			Evento* evento;
				if(tipo=="Concierto"){
					evento = new Concierto(nombre,duracion);
				}
				else if(tipo=="Conferencia"){
					evento = new Conferencia(nombre,atributo);
				}
				else if(tipo=="Taller"){
					evento = new Taller(nombre,atributo);
				}else{
					cout<<tipo<<": no es un tipo valido de Asistente."<<endl;
				}
			eventos.push_back(evento);

		}
		archivo2.close();
		return;
	}


void Sistema::guardarCambios() {
	 fstream archivo;
	 archivo.open("Asistentes.txt", ios::out);

	 if(archivo.is_open()) {
		 Asistente* a;
		 string linea;
		 for(list<Asistente*>::iterator it = asistentes.begin(); it != asistentes.end(); it++ ){
		 	a = *it;
		 	switch(a->yoSoy()) {
		 	case 1:
		 		linea = "Artista,"+a->getNombre()+","+to_string(a->getEdad())+","+a->getAtributo();
		 		break;
		 	case 2:
		 		linea = "Estudiante,"+a->getNombre()+","+to_string(a->getEdad())+","+a->getAtributo();
		 		break;
		 	case 3:
		 		linea = "Profesional,"+a->getNombre()+","+to_string(a->getEdad())+","+a->getAtributo();
		 		break;
		 	}
		 	archivo << linea + "\n";
		 }

	 }

	 archivo.close();

	 fstream archivo1;
	 archivo1.open("Evento.txt", ios::out);

	 if(archivo1.is_open()) {
		 Evento* e;
		 string linea;
		 for(list<Evento*>::iterator it = eventos.begin(); it != eventos.end(); it++ ){
			 e = *it;
			 switch(e->getTipo()) {
			 case 1:
				 linea = "Concierto,"+e->getNombre()+","+e->getAtributoEvento();
				 break;
			 case 3:
				 linea = "Taller,"+e->getNombre()+","+e->getAtributoEvento();
				 break;
			 case 2:
				 linea = "Conferencia,"+e->getNombre()+","+e->getAtributoEvento();
				 break;
			 }
			 archivo1 << linea + "\n";
		 }
	}
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
void Sistema::menuInformes(){
	while(true){
		cout<<"1.- Lista de Eventos programados "<<endl;
		cout<<"2.- Lista de Asistentes registrados para cada evento "<<endl;
		cout<<"3.- Estadisticas de Asistencia a Eventos "<<endl;
		cout<<"4.- Detalles de asistentes "<<endl;
		cout<<"5.- Detalles de un evento "<<endl;
		cout<<"6.- salir "<<endl;
			int tipo;
			cin >> tipo;
		switch(tipo) {
				case 1:
					printEventos();
					break;
				case 2:
					asistentePorEvento();
					break;
				case 3:
					estadisticasEventosAsistencia();
					break;
				case 4:
					estadisticasAsistentes();
					break;
				case 5:
					
					break;
				case 6:
					return;
					break;
				}
	}
}
void Sistema::estadisticasEventosAsistencia(){
	int contador = 0;
	Evento* e;
	for(list<Evento*>::iterator it = eventos.begin(); it != eventos.end(); it++ ){
		e = *it;
		cout<<"["<<contador<<"]"<<" Evento: "<<e->getNombre()<<"- cantidad asistentes: "<<e->getNumeroAsistente()<<endl;
		contador++;
	}
}

void Sistema::estadisticasAsistentes(){
	int contArtista= 0;
	int contEstudiante= 0;
	int contProfesional= 0;
	int contNoDef= 0;
	int contador = 0;
	int edades = 0;
	Asistente* a;
	for(list<Asistente*>::iterator it = asistentes.begin(); it != asistentes.end(); it++ ){
		a = *it;
		edades += a->getEdad();
		contador++;
		switch(a->yoSoy()) {
			case 1:
				contArtista++;
				break;
			case 2:
				contEstudiante++;
				break;
			case 3:
				contProfesional++;
				break;
			case 0:
				contNoDef++;
				break;
			}
	}
	int mayor=0;
	string mayorclase= "no definido";
	string segundaclase = "no definido";
	if(contArtista>mayor){
		segundaclase = mayorclase;
		mayorclase = "Artista";

	}else if(contEstudiante>mayor){
		segundaclase = mayorclase;
		mayorclase = "Estudiante";
	
	}else if(contProfesional>mayor){
		segundaclase = mayorclase;
		mayorclase = "Profesional";
	
	}
	cout<<"edad promedio Asistentes: "<<(edades/contador)<<" - Clases mas comunes: "<<mayorclase<< ", "<<segundaclase<<endl; 
}
void Sistema::asistentePorEvento(){
	Evento* e;
	for(list<Evento*>::iterator it = eventos.begin(); it != eventos.end(); it++ ){
		e = *it;
		list<Asistente*> listaAsis = e->getAsistentes();
		cout<<"Asistentes registrados en el evento: "<<e->getNombre()<<endl;
		Asistente* a;
		int contador = 0;
		for(list<Asistente*>::iterator it2 = listaAsis.begin(); it2 != listaAsis.end(); it2++ ){
			a = *it2;
			cout<<"["<<contador++<<"] "<<a->toStringAsistente()<<endl;
		}
		cout<<"--------------------------"<<endl;

	}
}
//g++ Asistente.cpp Artista.cpp Estudiante.cpp Profesional.cpp Evento.cpp Concierto.cpp Conferencia.cpp Taller.cpp Sistema.cpp main.cpp 
