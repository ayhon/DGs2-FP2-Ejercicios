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

using pi = pair<int, int>;
using vi = vector<int>;
using vpi = vector<pi>;
using vvi = vector<vi>;
using vvpi = vector<vpi>;
using pl = pair<long long, long long>;
using vl = vector<long long>;
using vpl = vector<pl>;
using vvl = vector<vl>;
using vvpl = vector<vpl>;

/*
pi rec(vi const& v, vi const& w, int ini, int fin) {
	// CASO BASE:
	if(fin -ini == 1) return {ini, ini};

	if(v[ini] < w[ini] && v[fin-1] < w[fin-1]) return {-1,0};
	if(v[ini] > w[ini] && v[fin-1] > w[fin-1]) return {-1,0};

	if(fin-ini == 2){
		pi res = {ini, fin-1};
		if(v[ini] == w[ini]) res.second = ini;
		if(v[fin-1] == w[fin-1]) res.first = fin-1; 
		return res;
	} 

	int mid = (fin+ini)/2;
	pi res = rec(v,w,ini,mid);
	if(res.first == -1) return rec(v,w,ini,mid);
	else return res;
}
*/

/*
pi rec(vi const& v, vi const& w, int ini, int fin)  {
	if(v[ini] < w[ini] && v[fin] < w[fin]) return {-1, 0};
	if(v[ini] > w[ini] && v[fin] > w[fin]) return {-1, v.size()};
	if(v[ini] == w[ini]) return {ini, ini};
	if(v[fin] == w[fin]) return {fin, fin};
	if(fin-ini == 1) return {ini, fin};
	else {
		int mid = ini + (fin-ini)/2;
		if(v[mid] == w[mid]) return {mid, mid};
		else {
			pi res1 = rec(v, w, ini, mid), res2;
			if (res1.first == -1)
				res2 = rec(v, w, mid, fin);
			else
				return res1;
			if (res2.first == -1)
				return {mid, mid};
			else
				return res2;
		}
	}
}
*/

// TODO: Se podría haber hecho con el vector resta, comprobando el signo
pi res(vi const& v, vi const& w, int ini, int fin)  {
	int mid = ini + (fin-ini)/2;
	if(fin - ini <= 1) {
		if (v[ini] < w[ini] && v[fin] < w[fin])
			return {fin, fin+1};
		if (v[ini] > w[ini] && v[fin] > w[fin])
			return {ini-1, ini};
		if(v[ini] == w[ini]) return {ini, ini};
		if(v[fin] == w[fin]) return {fin, fin};
		else {
			return {ini, fin};
		}
	}
	if(v[mid] == w[mid])
		return {mid, mid};
	else if(v[mid] > w[mid])
		return res (v,w, ini, mid);
	else if(v[mid] < w[mid])
		return res(v,w, mid, fin);
}


bool resuelveCaso() {
	int n; cin >> n;
	if(n == 0) return false;

	vi f(n), g(n);
	for(int & e: f) cin >> e;
	for(int & e: g) cin >> e;

	// v es el creciente, w el decreciente
	vi* v; vi* w;
	if(f.front() <= f.back()) {
		v = &f;
		w = &g;
	}
	else {
		v = &g;
		w = &f;
	}

	pi sol;
	sol = res(*v, *w, 0, n-1);
	
	cout << (sol.first == sol.second? "SI " : "NO " + to_string(sol.first) + " ") << sol.second << '\n';
	
	return true;
}

int main() {
	while(resuelveCaso());
	return 0;
}