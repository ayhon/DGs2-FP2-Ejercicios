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

struct tDato {
	string id = "";
	int cant = 0;
};

struct myOrder{
	bool operator() (tDato* d1, tDato * d2) {
		return d1->id < d2->id;
	}
};

bool binSearch(tDato & dato, vector<tDato*> const& cargo, int ini, int fin, int & pos) {
	if(fin - ini <= 1){
		pos = (cargo[ini]->id < dato.id? ini+1 : ini );
		return cargo[ini]->id == dato.id;
	} 
	pos = (fin+ini)/2;
	if(cargo[pos]->id == dato.id) return true;
	else if (cargo[pos]->id < dato.id)
		return binSearch(dato, cargo, pos, fin, pos);
	else if (cargo[pos]->id > dato.id)
		return binSearch(dato, cargo, ini, pos, pos);
	return false;
}

void insertar(vector<tDato*> & cargo, tDato* dato)  {
	int pos = cargo.size();
	if(binSearch(*dato, cargo, 0, cargo.size(), pos)) {
		cargo[pos]->cant += dato->cant;
		delete dato;
	}
	else {
		cargo.push_back(cargo.back());
		for(int i = cargo.size() - 2; i > pos; i--) {
			cargo[i] = cargo[i-1];
		}
		cargo[pos] = dato;
	}
}

bool resuelveCaso() {
	int n; cin >> n;
	if(!cin) return false;

	vector<tDato*> cargo(n);

	for(auto & it : cargo) {
		tDato* aux = new tDato;
		cin >> aux->id >> aux->cant;

		it = aux;
	}

	int k; cin >> k;
	for(int i = 0; i < k; i++) {
		tDato* aux = new tDato;
		cin >> aux->id >> aux->cant;

		insertar(cargo, aux);
	}

	for(int i = 0; i < cargo.size(); i++) {
		cout << cargo[i]->id << " " << cargo[i]->cant << '\n';
	}
	cout << "---\n";
	return true;
}

int main() {
	while(resuelveCaso());
	return 0;
}


