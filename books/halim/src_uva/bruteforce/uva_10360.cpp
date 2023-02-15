// author: Sebastian Bauer
// Date: Feb 15, 2023
//
// Problem UVa 10360 - Rat Attack 

#include <bits/stdc++.h>

using namespace std;

#define IN_BOUNDS(i,j,x,y,d) (abs((i)-(x)) <= (d) && abs((j) - (y)) <= (d))

const int M_SIZE = 1025;
const int N = 20000;

int d,n;
int rats[N][3];

int killed[M_SIZE][M_SIZE];

void solution() {
	
	// For each rat population
	// Dont iterate over all locations
	//   - just over x-d, ..., x+d and y-d, ..., y+d
	for (int i = 0; i != n; ++i) {
		int x = rats[i][0];
		int y = rats[i][1];
		int pop = rats[i][2];

		for (int i = max(0,x-d); i <= min(M_SIZE-1,x+d); ++i)
		   for (int j = max(0,y-d); j <= min(M_SIZE-1,y+d); ++j)
			   killed[i][j] += pop; 

	}

	int maxExt = -1;
	int xMax, yMax;

	for (int x = 0; x < M_SIZE; ++x)
		for (int y = 0; y < M_SIZE; ++y)
			if (killed[x][y] > maxExt) {
				maxExt = killed[x][y];
				xMax = x;
				yMax = y;
			}

	cout << xMax << " " << yMax << " " << maxExt << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	
	while (t--) {
		cin >> d;
		cin >> n;
		for (int i = 0; i != n; ++i)
			cin >> rats[i][0] >> rats[i][1] >> rats[i][2];

		solution();

		// Dont forget to set memory to 0 in order to get correct maximum
		memset(killed, 0, sizeof(killed));
	}


	return 0;
}
