#include <iostream>
#include <cstring>
#include <stdio.h>

#include <algorithm>
#include <vector>
#include <set>

using namespace std;

// Debug
#define DEBUG 0

// Constants
#define MOD 1'000'000'007

// Simple types
#define ll long long
#define ld long double

// Aggeragte types
#define pii pair<int,int>
#define pll pair<long,long>

#define vi vector<int>
#define vl vector<long>

#define si set<int>
#define sl set<long>

// Output
template <typename T>
void print_v(vector<T>& v) {cout << "{"; for (auto& x : v) cout << x << " "; cout << "\n";}

vector<pair<int,int>> dir = {{0,0},{0,1},{1,0},{0,-1},{-1,0}};

const int N_MAX = 3;
int MAT[N_MAX][N_MAX];

void click(char c) {
	if (c >= 'a' && c <= ('a' + 9)) {
	int idx = c - 'a';
	int yPos = idx / 3;
	int xPos = idx % 3;
	for (auto& d : dir) {
		int nX = xPos + d.first;
		int nY = yPos + d.second;
		if (nX >= 0 && nX < 3 && nY >= 0 && nY < 3)
			MAT[nY][nX] = (MAT[nY][nX] + 1) % 10;
	}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	char* lptr = NULL;
	size_t size = 0;
	ssize_t read;
	int c = 1;

	while ((read = getline(&lptr, &size, stdin)) > 0) {
		string s(lptr, lptr + read-1);
		cout << "Case #" << (c++) << ":\n";
		for (char& c : s) click(c);	
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				cout << MAT[i][j]; if (j != 2) cout << " ";
			}
			cout << "\n";
		}

		memset(MAT, 0, sizeof(MAT));
	}

	return 0;
}
