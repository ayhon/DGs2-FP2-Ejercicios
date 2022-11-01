#ifndef LISTALUGARES_H
#define LISTALUGARES_H

#include <iostream>
#include <vector>
using namespace std;

struct tLugar{
	string name;
	int cost;
};
using tListaLugares = vector<tLugar>;

istream & operator>> (istream & in, tListaLugares lista);
ostream & operator<< (ostream & out, tListaLugares lista);

// Busca recursivamente en la lista el elemento con el nombre
int buscar(tListaLugares const& lista, string const& nombre);

#endif
