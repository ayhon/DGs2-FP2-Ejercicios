#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <stack>
#include <set>
#include <algorithm> 
using namespace std; 
using tMatrix = vector<vector<char>>;

const pair<int,int> dir8[8] = {
	{0,1}, 
	{1,0}, 
	{0,-1}, 
	{-1,0}, 
	{1,1}, 
	{-1,1}, 
	{1,-1}, 
	{-1,-1}
};

bool dentro(int x, int y, tMatrix const& m) {
	return x >= 0 && y >= 0 &&
		x < m.size() && y < m[0].size();
}

bool dirSearch(pair<int, int> & q, pair<int, int> & k, tMatrix const& tablero, pair<int, int> dir) {
	bool stop = false;
	for(int i = q.first + dir.first, j = q.second + dir.second; dentro(i,j,tablero) && !stop; i+=dir.first, j+=dir.second) {
		if(i == k.first && j == k.second) return true;
		if(tablero[i][j] == 'X') stop = true;
	}
	return false;
}

void resuelveCaso() {
	tMatrix tablero(8, vector<char> (8));
	bool gana = false;

	pair<int, int> posRey, posReina;
	for(int i = 0; i < 8; i++) {
		for(int j = 0; j < 8; j++) {
			cin >> tablero[i][j];
			if(tablero[i][j] == 'R')
				posRey = make_pair(i,j);
			else if (tablero[i][j] == 'A') {
				posReina = make_pair(i,j);
			}
		}
	}
	int i;
	for(i = 0; i < 8 && !dirSearch(posReina, posRey, tablero, dir8[i]); i++);

	cout << (i==8? "SIN " : "") << "JAQUE\n";
}

int main() {
	int T; cin >> T;
	for (int i = 1; i <= T; i++) {
		resuelveCaso();
	}
	return 0;
}


