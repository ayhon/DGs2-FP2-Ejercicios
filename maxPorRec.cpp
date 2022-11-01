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

int resolver(vector<int> & v, int ini, int fin) {
	if(fin - ini <= 2) return max(v[ini], v[fin-1]);

	int mid = ini + (fin-ini)/2;
	return max(resolver(v, ini, mid), resolver(v, mid, fin));
}

bool resuelveCaso() {
	int n; cin >> n; 
	if(!cin) return false;

	vector<int> v(n);
	for(int & elem : v) cin >> elem;

	cout << resolver(v, 0, v.size()) << '\n';

	return true;
}

int main() {
	while(resuelveCaso());
	return 0;
}


