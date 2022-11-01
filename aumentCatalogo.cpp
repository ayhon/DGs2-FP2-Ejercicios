#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <cmath>
#include <climits>
#include <stack>
#include <set>
#include <algorithm>
using namespace std;

struct tDatos {
	string id = "";
	int cant = 0;
};

struct tCargo {
	tDatos* data = nullptr;
	int cont = 0;
	int capacity = 0;
};

bool binSearch(const tDatos * cargo, tDatos const& target, int & pos, int ini, int fin) {
	if(ini >= fin-1) return cargo[pos].id == target.id;
	pos = ini + (fin-ini)/2;
	if(cargo[pos].id == target.id) return true;
	else if(cargo[pos].id < target.id) 
		return binSearch(cargo, target, pos, pos, fin);
	else if(cargo[pos].id > target.id) 
		return binSearch(cargo, target, pos, ini, pos);
	return false;
}

bool binSearch(tCargo const& cargo, tDatos const& target, int & pos) {
	pos = cargo.cont;
	return binSearch(cargo.data, target, pos, 0, cargo.cont);
}

void inicializar(tCargo & cargo, int size = 0) {
	cargo.data = new tDatos[size];
	cargo.capacity = size;
	cargo.cont = 0;
}

void ampliarCargo(tCargo & cargo) {
	cargo.capacity *= 2;
	tDatos * newdata = new tDatos[cargo.capacity];
	for(int i = 0; i < cargo.cont; i++) {
		newdata[i] = cargo.data[i];
	}
	delete[] cargo.data;
	cargo.data = newdata;
}

void insertar(tCargo & cargo, tDatos & dato) {
	int pos;
	if(binSearch(cargo, dato, pos)) {
		cargo.data[pos].cant += dato.cant;
	} 
	else {
		if(cargo.cont >= cargo.capacity) 
			ampliarCargo(cargo);

		for(int i = cargo.cont; i > pos; i--) 
			cargo.data[i] = cargo.data[i-1];

		cargo.data[pos] = dato;
		cargo.cont++;
	}
}

bool resuelveCaso() {
	int n; cin >> n;
	if(!cin) return false;

	tCargo cargo;
	inicializar(cargo, n);
	for(int i = 0; i < n; i++) {
		tDatos aux;
		cin >> aux.id >> aux.cant;

		insertar(cargo, aux);
	}

	int k; cin >> k;
	for(int i = 0; i < k; i++) {
		tDatos input;
		cin >> input.id >> input.cant;

		insertar(cargo, input);
	}

	for(int i = 0; i < cargo.cont; i++) {
		cout << cargo.data[i].id << " " << cargo.data[i].cant << '\n';
	}

	delete[] cargo.data;
	
	cout << "---\n";
	return true;
}

int main() {
	while(resuelveCaso());
	return 0;
}
