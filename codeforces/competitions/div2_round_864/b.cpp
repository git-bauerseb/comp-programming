#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>

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

const int N_MAX = 1002;
int P[N_MAX][N_MAX];

void solution() {
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> P[i][j];
        }
    }

    int diff = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if (P[i][j] != P[n-i-1][n-j-1]) {
                diff++;
            }   
        }
    }
    
    if (diff == k 
        || (diff < k && (k-diff) % 2 == 0)
        || (diff > k && (diff-k) % 2 == 0 && k != 0)
        ) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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
        memset(P, 0, sizeof P);
	}

	return 0;
}
