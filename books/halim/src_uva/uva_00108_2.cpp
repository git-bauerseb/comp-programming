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

const int N_MAX = 102;
int A[N_MAX][N_MAX];

/*
 	0  -2  -7  0
	9   2  -6  2
	-4  1  -4  1
	-1  8   0  -2


	0  -2  -7   0
	9   0  -13  2
	5   1  -17  3
	4   9  -17  1

*/
void solution() {
	int n; cin >> n;

	// Calculate column prefix
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			int num; cin >> num;
			A[i][j] = num + A[i-1][j];
		}
	}


	int gSum = 0;

	/*
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {cout << A[i][j] << " ";}
		cout << "\n";
	}
	*/

	// For each coordinate pair
	// O(n^5) algorithm
	/*
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= i; ++j) {
			for (int k = 1; k <= n; ++k) {
				for (int m = 1; m <= k; ++m) {
					int sum = 0;
					for (int l = j; l <= i; ++l) {
						sum += A[k][l] - A[m-1][l];
					}

					gSum = max(sum, gSum);
				}
			}	
		}
	}
	*/

	// O(n^3) algorithm
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= i; ++j) {
			int sum = 0;
			for (int k = 1; k <= n; ++k) {
				sum += A[i][k] - A[j-1][k];
				gSum = max(gSum, sum);
				if (sum < 0) sum = 0;
			}
		}
	}
	cout << gSum << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	solution();

	return 0;
}
