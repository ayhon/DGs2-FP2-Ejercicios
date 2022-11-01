// Autor: Fernando I Leal Sánchez
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * LOGICA DE LA FUNCIÓN
 *
 * 	CASOS BASE
 * minimo_positivo(v,ini, fin) = ini si fin-ini<= 1 y v[ini] >=0
 * minimo_positivo(v,ini, fin) = fin-1 si fin-ini<= 1 y v[ini] <0
 *
 * 	CASO RECURSIVO
 * minimo_positivo(v,ini,fin) = minimo_positivo(v,ini,mid) si v[mid]>= 0
 * minimo_positivo(v,ini,fin) = minimo_positivo(v,ini,fin) si v[mid]< 0
 *
 */

int resolver(vector<int> & v, int ini, int fin) {
	if(fin - ini <= 1) {
		int res;
		if(v[ini] >= 0) 
			res = ini;
		else 
			res = fin;
		return res;
	}
	
	int mid = (fin+ini)/2, res;

	if(v[mid] >= 0)
		res = resolver(v,ini,mid);
	else 
		res = resolver(v, mid, fin);
	return res;
}

bool resuelveCaso() {
	int n; cin >> n;
	if(!cin) return false;
	else if (n==0) {
		cout << "0\n"; 
		return true;
	}

	vector<int> v(n);
	for(int & e : v) cin >> e;

	int sol = resolver(v, 0, v.size());
	cout << sol <<'\n';
	
	return true;
}

int main() {
	while(resuelveCaso());
	return 0;
}


