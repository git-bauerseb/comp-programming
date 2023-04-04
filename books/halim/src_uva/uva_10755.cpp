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

const int N_MAX = 22;

// Coordinates (x,y,z)
ll H[N_MAX][N_MAX][N_MAX];

// Naive solution with prefix sums
// O(n^6)
void solution() {
    int a,b,c; cin >> a >> b >> c;
    for (int i = 0; i < a; ++i) {
        for (int j = 0; j < b; ++j) {
            for (int k = 0; k < c; ++k) {
                ll num; cin >> num;
                H[i][j][k] = num;
            
                // Get sum from left 
                if (i > 0) H[i][j][k] += H[i-1][j][k];
                // Get sum from below
                if (j > 0) H[i][j][k] += H[i][j-1][k];
                // Get sum from front
                if (k > 0) H[i][j][k] += H[i][j][k-1];

                // Inclusion-exclusion principle
                if (i && j) H[i][j][k] -= H[i-1][j-1][k];
                if (j && k) H[i][j][k] -= H[i][j-1][k-1];
                if (i && k) H[i][j][k] -= H[i-1][j][k-1];
                if (i && j && k) H[i][j][k] += H[i-1][j-1][k-1];
            }
        }
    }

    ll m = -100*1E9;

    // Loop through every position (i,j,k)
    for (int i = 0; i < a; ++i) {
        for (int j = 0; j < b; ++j) {
            for (int k = 0; k < c; ++k) {
                // Calculate value for parallelepiped for each prevous position (x,y,z)
                for (int x = 0; x <= i; ++x) {
                    for (int y = 0; y <= j; ++y) {
                        for (int z = 0; z <= k; ++z) {
                                ll val = H[i][j][k];
                                if (x) val -= H[x-1][j][k];
                                if (y) val -= H[i][y-1][k];
                                if (z) val -= H[i][j][z-1];
                                if (x && y) val += H[x-1][y-1][k];
                                if (y && z) val += H[i][y-1][z-1];
                                if (x && z) val += H[x-1][j][z-1];
                                if (x && y && z) val -= H[x-1][y-1][z-1];
                                m = max(m, val);
                        }
                    }
                }
            }
        }
    }

    cout << max(m, H[a-1][b-1][c-1]) << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int tt;
	cin >> tt;
	while (tt--) {
		solution();
        if (tt) cout << "\n";
	}

	return 0;
}
