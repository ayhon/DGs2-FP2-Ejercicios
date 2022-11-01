#include <iostream>
#include "listaopciones.h"
using namespace std;

ostream & operator<< (ostream & out, tListaOpciones & lista) {
	string separacion = "--------------------------------\n";
	cout << separacion;
	for(int i = 0; i < lista.size(); i++) {
		cout << "Viaje: " << lista[i].OpcPlaya->name << " y " << lista[i].OpcSierra->name << ", precio: " << lista[i].cost << '\n';
		cout << separacion;
	}
	return out;
}

// Libera la memoria de la lista
void liberar(tListaOpciones & lista) {
	for(int i = 0; i < lista.size(); i++) {
		delete lista[i].OpcPlaya;
		lista[i].OpcPlaya = nullptr;
		delete lista[i].OpcSierra;
		lista[i].OpcSierra = nullptr;
	}
}


// Añade una nueva opción a la lista de opciones
void nuevoViaje(tListaOpciones & lista, tListaLugares & playas, tListaLugares & sierras) {
	string nombre;
	tOpc nuevo; lista.push_back(nuevo);
	cout << "   Elige un lugar con playas\n";
	cout << playas << '\n';

	cout << "> "; cin >> nombre;
	int pos = buscar(playas, nombre);
	while(pos==-1) {
		cout << "> "; cin >> nombre;
		pos = buscar(playas, nombre);
	}
	nuevo.OpcPlaya = &playas[pos];
	nuevo.cost = playas[pos].cost;

	cout <<"   Elige un lugar con sierras\n";
	cout << sierras <<'\n';

	cout << "> "; cin >> nombre;
	pos = buscar(sierras, nombre);
	while(pos == -1) {
		cout << "> "; cin >> nombre;
		pos = buscar(sierras, nombre);
	}
	nuevo.OpcSierra = &sierras[pos];
	nuevo.cost += sierras[pos].cost;

	int i;
	for(i = lista.size()-1; i > 0 && nuevo.cost < lista[i-1].cost; i--) {
		lista[i] = lista[i-1];
	}
	lista[i] = nuevo;
}
