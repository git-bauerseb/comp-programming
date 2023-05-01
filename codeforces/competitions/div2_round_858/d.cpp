#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

// Constants
#define MOD 998'244'353

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

const int N_MAX = 500001;
ll NUMS[N_MAX];
ll dp1[N_MAX];

void solution() {
	int n; cin >> n;
	for (int i = 1; i < n; ++i) cin >> NUMS[i];

	dp1[1] = 1;
	for (int i = 2; i <= n; ++i) {
		dp1[i] = (dp1[i-1] * (i-1 - NUMS[i-1])) % MOD;
	}

	ll prev = 0;
	for (int i = 1; i < n; ++i) {
		prev = ((i)*prev + (!NUMS[i])*dp1[i]) % MOD;
		cout << prev << " ";
	}

	cout << "\n";
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
