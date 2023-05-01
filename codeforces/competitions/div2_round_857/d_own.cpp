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

// Idea: Order does not matter, so sort array (sort in pairs such that a[i], b[i]
// stay together)
//
// - Now suppose we choose a[i] as the maximum for first friend
// - Need to determine maximum for second friend 
//   - it cannot be b[i] since we only visit one store for each i = 0, ..., n-1
// - it can either be b[0], ...., b[i-1] OR b[i+1], ..., b[n-1]
// - we need to be sure that when we choose b[k] that no other b[j] is greater
//   otherwise we would need to choose this also sinc we fixed our choice for A to be a[i]
//   - for this we compute maximum suffix mSuff s.t. mSuff[i] contains the greatest value
//     for b[i], b[i+1], ..., b[n-1]
//   - we now search for first element in s >= a[i] (lower_bound(a[i].first)
void solution() {
	int n; cin >> n;

	// Read in numbers
	vector<pair<int,int>> a(n);
	for (int i = 0; i != n; ++i) cin >> a[i].first >> a[i].second;
	sort(a.begin(), a.end());

	// Maximum suffix in second dimension
	// Suffix calculated AFTER sorting -> before sorting would be invalid
	vector<int> mSuff(n+1); mSuff[n] = -MOD;
	for (int i = n-1; i != 0; --i) mSuff[i] = max(mSuff[i+1], a[i].second);

	set<int> s;
	int ans = MOD;

	for (int i = 0; i < n; ++i) {
		auto it = s.lower_bound(a[i].first);

		if (it != s.end() && *it >= mSuff[i+1]) {
			ans = min(ans, abs(*it - a[i].first));
		}

		if (it != s.begin() && *(--it) >= mSuff[i+1]) {
			ans = min(ans, abs(*it - a[i].first));
		}

		if (i+1 < n) {
			ans = min(ans, abs(a[i].first - mSuff[i+1]));
		}

		if (ans == 0) break;
		s.insert(a[i].second);
	}
	cout << ans << "\n";
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
