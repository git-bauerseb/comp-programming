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
    int n; cin >> n;
    vi org(n); for (int i = 0; i < n; ++i) cin >> org[i];
    vi ne(n); for (int i = 0; i < n; ++i) cin >> ne[i];

    int pos = -1;

    for (int i = 0; i < n; ++i) {
        if (org[i] != ne[i]) {pos = i; break;}
    }

    int s = pos;
    int e = pos;
    while (s > 0 && ne[s] >= ne[s-1]) s--;
    while (e < n-1 && ne[e] <= ne[e+1]) e++;

    printf("%d %d\n", s+1, e+1);
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
