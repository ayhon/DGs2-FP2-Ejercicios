#include <iostream>
#include <iomanip>
#include "listalugares.h"
using namespace std;

const int COLSIZE = 10;

istream & operator>> (istream & in, tListaLugares l) {
	int size; in >> size;
	for(int i = 0; i < size; i++) {
		tLugar nuevo;
		in >> nuevo.name >> nuevo.cost;
		l.push_back(nuevo);
	}
	return in;
}
ostream & operator<< (ostream & out, tListaLugares l) {
	cout << right << setw(COLSIZE) << "Nombre";
	cout << right << setw(COLSIZE) << "Precio\n";
	for(int i = 0; i < l.size(); i++){
		cout << right << setw(COLSIZE) << l[i].name;
		cout << right << setw(COLSIZE) << l[i].cost << '\n';
	}
	return out;
}
int buscar(tListaLugares const& lista, string const& nombre, int idx) {
	if(idx == lista.size()) return -1;
	if(lista[idx].name == nombre) return idx;
	else return buscar(lista, nombre, idx+1);
}

int buscar(tListaLugares const& lista, string const& nombre) {
	return buscar(lista, nombre, 0);
}
