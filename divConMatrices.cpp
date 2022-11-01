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

bool dentro(int x, int y, vector<vector<int>> & mat) {
	return x >= 0 && y >= 0 &&
		x < mat.size() && y < mat[0].size();
}

void filas(int a, int b, vector<vector<int>> & mat) {
	int p = a-1, q = b-1;
	for(int i = 0; i < mat[0].size(); i++) {
		swap(mat[p][i], mat[q][i]);
	}
}

void columnas(int a, int b, vector<vector<int>> & mat) {
	int p = a-1, q = b-1;
	for(int i = 0; i < mat.size(); i++) {
		swap(mat[i][p], mat[i][q]);
	}
}

void cruz(int a, int b, int val, vector<vector<int>> & mat) {
	int f = a-1, c = b-1;
	if(dentro(f,c,mat)) mat[f][c] = val;
	for(int i = f, j = c; dentro(i,j, mat); i++, j++) mat[i][j] = val;
	for(int i = f, j = c; dentro(i,j, mat); i--, j++) mat[i][j] = val;
	for(int i = f, j = c; dentro(i,j, mat); i++, j--) mat[i][j] = val;
	for(int i = f, j = c; dentro(i,j, mat); i--, j--) mat[i][j] = val;
}

void rotarFila(int a, vector<vector<int>> & mat) {
	int f = abs(a)-1;
	if(a>0) {
		int tmp = mat[f].back();
		for(int i = mat[0].size()-1; i >= 1; i--) {
			mat[f][i] = mat[f][i-1];
		}
		mat[f].front() = tmp;
	}
	else  {
		int tmp = mat[f].front();
		for(int i = 1; i < mat[0].size(); i++) {
			mat[f][i-1] = mat[f][i];
		}
		mat[f].back() = tmp;
	}
}

void rotarCol(int b, vector<vector<int>> & mat) {
	int c = abs(b)-1;
	if(b>0) {
		int tmp = mat.back()[c];
		for(int i = mat.size()-1; i >= 1; i--) {
			mat[i][c] = mat[i-1][c];
		}
		mat.front()[c] = tmp;
	}
	else  {
		int tmp = mat.front()[c];
		for(int i = 1; i < mat.size(); i++) {
			mat[i-1][c] = mat[i][c];
		}
		mat.back()[c] = tmp;
	}
}

bool resuelveCaso() {
	int n, m; cin >> n >> m;
	if(n == 0 && m == 0) return false;
	vector<vector<int>> mat(n, vector<int> (m));
	for(auto & vct : mat)
		for(int & e : vct)
			cin >> e;
	int T; cin >> T;
	for(int i = 0; i < T; i++) {
		string cmd; cin >> cmd;
		int op1, op2;
		if(cmd == "filas") {
			cin >> op1 >> op2;
			filas(op1,op2,mat);
		}
		else if(cmd == "columnas" ) {
			cin >> op1 >> op2;
			columnas(op1,op2,mat);
		}
		else if(cmd == "cruz" ) {
			int op3; cin >> op1 >> op2 >> op3;
			cruz(op1,op2, op3,mat);
		}
		else if(cmd == "rotarFila" ) {
			cin >> op1 ;
			rotarFila(op1,mat);
		}
		else if(cmd == "rotarCol" ) {
			cin >> op1 ;
			rotarCol(op1,mat);
		}
	}
	for(auto vct : mat) {
		for(int e : vct) {
			cout << e << " ";
		}
		cout << '\n';
	}
	cout << "---\n";

	return true;
}

int main() {
	while(resuelveCaso());
	return 0;
}


