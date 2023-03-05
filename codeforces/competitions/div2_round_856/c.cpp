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

ll fac(int n) {
	if (n == 0) return 1;
	int i = 1;
	for (ll j = 2; j <= n; ++j) {i *= j;}
	return i;
}


const int N_MAX = 100001;
ll nums[N_MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
	
		for (int i = 0; i != n; ++i) cin >> nums[i];

		// For each a1, ..., ai find maximum length of max score subsequence
		for (int i = 0; i < n; ++i) {
			int l = 0;
			int r = i;

			while (l < r) {
				int m = l + (r-l)/2;
				int num = nums[m];
				if (num / (i - m + 1) > 0) {
					r = m;
				} else {
					l = m+1;
				}
			}

			cout << (i - r + 1);
			if (i != (n-1)) cout << " ";
		}

		cout << "\n";
	}

	return 0;
}
