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

void solution() {
    int n,m,b; cin >> n >> m >> b;
    int mo = 1E9;
    int ev = -1E9;
    for (int i = 0; i < n; ++i) {
        int pr; cin >> pr;
        mo = min(mo, pr);
    }

    int bT = b;
    int qu = b / mo;
    int rem = b - qu * mo;
    for (int i = 0; i < m; ++i) {
        int pr; cin >> pr;
        ev = max(ev, pr);
    }

    cout << max(bT, (ev * qu + rem)) << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    solution();

	return 0;
}
