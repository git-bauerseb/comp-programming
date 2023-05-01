#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

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

const int N_MAX = 101;
int MAT[N_MAX][N_MAX];


void solution() {
	int n; cin >> n;
	// numeric_limits not supported
	// int ma = numeric_limits<int>::min();
	int ma = -128 * 100 * 100;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			int num; cin >> num;
			MAT[i][j] = num;
			if (i > 1) MAT[i][j] += MAT[i-1][j];
			if (j > 1) MAT[i][j] += MAT[i][j-1];
			if (i > 1 && j > 1) MAT[i][j] -= MAT[i-1][j-1];
			ma = max(ma, MAT[i][j]);
		}
	}

	for (int i = 1; i <= n; ++i)
	   	for (int j = 1; j <= n; ++j) {
			for (int k = 0; k < i; ++k)
				for (int m = 0; m < j; ++m)
					ma = max(ma, MAT[i][j] - MAT[k][j] - MAT[i][m] + MAT[k][m]);
		}


	cout << ma << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	solution();

	return 0;
}
