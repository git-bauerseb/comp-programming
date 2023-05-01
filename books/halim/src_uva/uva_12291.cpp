#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>

using namespace std;

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

const int N_MAX = 11;

bool LARGE[N_MAX][N_MAX];
bool SMALL[N_MAX][N_MAX];

bool BUFF[N_MAX][N_MAX];
bool OCC[N_MAX][N_MAX];

int n, m;

void placeTile(bool buffer[][N_MAX], bool tile[][N_MAX],
		int xP, int yP, int xStart, int yStart, int width, int height) {
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			if (tile[i+yStart][j+xStart])
				buffer[i+yP][j+xP] = tile[i+yStart][j+xStart];
		}
	}	
}

void clearTile(bool buffer[][N_MAX], bool tile[][N_MAX], int xP, int yP,
		int xStart, int yStart, int width, int height) {
	for (int i = 0; i < height; ++i)
		for (int j = 0; j < width; ++j)
			if (tile[i+yStart][j+xStart]) buffer[i+yP][j+xP] = false;
}

bool overlap(bool buffer[][N_MAX], bool tile[][N_MAX], int xP, int yP,
		int xStart, int yStart, int width, int height) {
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			if (i+yP < n && j+xP < n && buffer[i+yP][j+xP] == true && tile[i+yStart][j+xStart] == true)
				return true;
		}
	}
	return false;
}

bool equals(bool b1[][N_MAX], bool b2[][N_MAX], int n) {
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (b1[i][j] != b2[i][j]) return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while (true) {
		cin >> n >> m;
		if (n == 0 && m == 0) break;


		// Tight bound on width/height of big piece
		int lWidth = 0, lHeight = 0;
		int lXStart = 12, lXEnd = -1;
		int lYStart = 12, lYEnd = -1;
		
		// Tight bound on width/height of small piece

		// Read in large
		for (int i = 0; i != n; ++i) {
			bool found = false;
			for (int j = 0; j != n; ++j) {
				char c; cin >> c;
				if (c == '*') {
					found = true;
					LARGE[i][j] = true;
					lXStart = min(lXStart, j);
					lXEnd = max(lXEnd, j);
				}
			}

			if (found) {
				lYStart = min(lYStart, i);
				lYEnd = max(lYEnd, i);
			}
		}


		// Read in small piece
		int sXStart = 12, sXEnd = -1;
		int sYStart = 12, sYEnd = -1;
		for (int i = 0; i != m; ++i) {
			bool found = false;
			for (int j = 0; j != m; ++j) {
				char c; cin >> c;
				if (c == '*') {
					found = true;
					SMALL[i][j] = true;
					sXStart = min(sXStart, j);
					sXEnd = max(sXEnd, j);
				}
			}

			if (found) {
				sYStart = min(sYStart, i);
				sYEnd = max(sYEnd, i);
			}
		}

		
		int sHeight = sYEnd - sYStart+1;	// Height of small piece
		int sWidth = sXEnd - sXStart+1; // Width of small piece
		if (sHeight <= 0 || sWidth <= 0) {cout << "0\n"; continue;} 
		
		
		// Place first tile
		// Place second tile such that it does not overlap first tile
		// Check if those tiles equal the large figure
		bool poss = false;
		for (int i = 0; i < max(n, n - sHeight); ++i) {
			for (int j = 0; j < max(n, n - sWidth); ++j) {
				placeTile(BUFF, SMALL, i, j, sXStart, sYStart, sWidth, sHeight);	
				for (int u = 0; u < max(n, n - sHeight); ++u) {
					for (int v = 0; v < max(n, n - sWidth); ++v) {
						if (u == i && v == j) continue;
						if (!overlap(BUFF, SMALL, u, v, sXStart, sYStart, sWidth, sHeight)) {
							placeTile(BUFF, SMALL, u, v, sXStart, sYStart, sWidth, sHeight);	
							if (equals(LARGE, BUFF, n)) {
								poss = true;
								goto end;
							} 
							
							clearTile(BUFF, SMALL, u, v, sXStart, sYStart, sWidth, sHeight);
						}
					}
				}

				clearTile(BUFF, SMALL, i, j, sXStart, sYStart, sWidth, sHeight);
			}
		}

		end:
		cout << (poss ? "1" : "0") << "\n";
		memset(BUFF, false, sizeof(BUFF));
		memset(LARGE, false, sizeof(LARGE));
		memset(SMALL, false, sizeof(SMALL));
	}

	return 0;
}
