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

//  Idea: Brute Force O(n^3)
//      - for each pair of rows, check if the gap between them
void solution() {
    int n, u, v; cin >> n >> u >> v;

    // Col. index of obstacle in row
    vector<int> obs(n);
    bool same = true;

    for (int i = 0; i < n; ++i) {
        cin >> obs[i];

        if (i > 0 && obs[i] != obs[i-1]) same = false;
    }

    int cost = 2E9 + 2;

    // All obstacles in same column
    //  => need to move right/left & up/down 
    if (same) {
        cost = min(u + v, v+v);
    } else {
        cost = min(u,v);
        bool found = false;
        for (int i = 0; i < n-1; ++i) {
            if (abs(obs[i] - obs[i+1]) > 1) {cost = 0; break;}
        }
    }

    cout << cost << "\n";
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
