#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <array>

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
	array<int,2> a[n];
	for (int i = 0; i < n; ++i) cin >> a[i][0] >> a[i][1];

	// Sort array
	sort(a, a+n);

	int max_[n+1];
	max_[n] = -2e9;
	max_[n-1] = a[n-1][1];
	for (int i = n - 2; i >= 0; i--)
		max_[i] = max(max_[i+1], a[i][1]);

	int mn = 1e9;
	set<int> s;
	for (int i = 0; i < n; i++) {
		int k = max_[i+1];
		mn = min(mn, abs(a[i][0] - k));
		auto it = s.lower_bound(a[i][0]);
		if (it != s.end()) {
			mn = min(mn, abs(a[i][0] - max(k, *it)));
		}

		if (it != s.begin()) {
			it--;
			mn = min(mn, abs(a[i][0] - max(k, *it)));
		}

		s.insert(a[i][1]);
	}

	cout << mn << "\n";
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
