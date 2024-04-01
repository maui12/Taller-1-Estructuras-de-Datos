#include <iostream>
#include "Asistente.h"

using namespace std;

int main() {
    Asistente* a1 = new Asistente("mauricio",21);

    cout<<a1->getNombre()<<endl;
    cout<<a1->getEdad()<<endl;
    cout<<&a1<<"hola"<<endl;


    return 0;
}
