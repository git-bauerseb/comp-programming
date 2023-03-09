#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <stdint.h>

using namespace std;

// Constants
#define MOD 549755813888

// Simple types
#define ll int64_t
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

const int N_MAX = 200;
const int M_MAX = 200;

ll B[N_MAX][M_MAX];


void check(int n, int m) {
	for (int i = 0; i != n-1; i++) {
		for (int j = 0; j != m-1; j++) {
			int a = B[i][j];
			int b = B[i][j+1];
			int c = B[i+1][j];
			int d = B[i+1][j+1];
			if ((a^b^c^d) != 0) {
				cout << "ERROR " << a << " " << b << " " << c << " " << d << "\n";
				goto end;
			}
		}
	}

	end:
		return;
}

ll ilog2(ll num) {
	ll res = 0;
	while (num > 0) {res++; num >>= 1;}
	return res;
}

void solution() {
	int n,m; cin >> n >> m;
	for (int y = 0; y < n; y+=2) {
		for (int x = 0; x < m; x+=2) {
			B[y][x] = (y << 10) | (x);
			if (x < m-1) B[y][x+1] = (y << 10) | (x+1);
			if (y < n-1) B[y+1][x] = ((y+1) << 10) | (x);
			if (y < n-1 && x < m-1) B[y+1][x+1] = ((y+1) << 10) | (x+1);
		}
	}

	// check(n,m);
	
	
	cout << n*m << "\n";
	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < m; ++x) {
			cout << B[y][x]; if (x != (m-1)) cout << " ";
		}
		cout << "\n";
	}
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int tt;
	cin >> tt;
	while (tt--) {
		solution();
	}

	return 0;
}
