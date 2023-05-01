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
    vi a(n); for (int i = 0; i < n; ++i) cin >> a[i];
    vi b(n); for (int i = 0; i < n; ++i) cin >> b[i];

    if (n == 1) {cout << "YES\n"; return;}

    int cAMax = a[0];
    int cBMax = b[0];

    for (int i = 1; i < n; ++i) {
        if (cBMax >= cAMax && a[i] >= b[i]) swap(a[i], b[i]);
        if (cAMax >= cBMax && b[i] >= a[i]) swap(a[i], b[i]);

        cAMax = max(cAMax, a[i]);
        cBMax = max(cBMax, b[i]);
    }

    if (a[n-1] >= cAMax && b[n-1] >= cBMax ||
            (a[n-1] >= cBMax && b[n-1] >= cAMax)) cout << "YES\n";
    else cout << "NO\n";
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
