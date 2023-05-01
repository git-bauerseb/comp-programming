#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <limits>

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
	int minDiff = MOD;

	vector<pair<int,int>> nums(n);

	for (int i = 0; i != n; i++) {
		int a, b; cin >> a >> b;
		nums[i].first = a;
		nums[i].second = b;
	}

	sort(nums.begin(), nums.end());

	for (int i = 0; i != n; ++i) {
		int curr = nums[i].second;

		// Binary search on first gift
		if (i > 0) {
			int l = 0; int r = i-1;
			while (l < r) {
				int m = l + (r - l) / 2;
				if (nums[m].first < curr) {l = m+1;}
				else {r = m;}
			}

			minDiff = min(minDiff, abs(curr - nums[l].first));
		}

		if (i < n-1) {
			int l = i+1; int r = n-1;
			while (l < r) {
				int m = l + (r - l) / 2;
				if (nums[m].first < curr) {l = m+1;}
				else {r = m;}
			}

			minDiff = min(minDiff, abs(curr - nums[l].first));
		}
	}

	cout << minDiff << "\n";
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
