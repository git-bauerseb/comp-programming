#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
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

const int N_MAX = 200001;
ll NUMS[N_MAX];
ll A[N_MAX];

void solution() {
	int n; cin >> n;
	for (int i = 0; i != n; ++i) {
		cin >> NUMS[i];
	}

	if (n == 1) {cout << (NUMS[0] == 1 ? "YES" : "NO") << "\n"; return;}

	sort(NUMS, NUMS+n);
	A[0] = 1;
	ll tSum = 1;
	if (NUMS[0] != 1) {cout << "NO\n"; return;}
	for (int i = 1; i != n; ++i) {
		A[i] = tSum;
		if (NUMS[i] > A[i]) {
			cout << "NO\n"; return;
		}

		tSum += NUMS[i];
	}

	cout << "YES\n";
	memset(A, 0, sizeof(A));
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
