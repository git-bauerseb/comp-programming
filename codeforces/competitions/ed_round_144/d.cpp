#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

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

// Idea
//  - Sliding window of size k:
//
#define LSOne(x) (x & (-x))

const int N = 200'002;
ll ft[N];

void adjust(int idx, int value) {
	while (idx <= N) {
		ft[idx] += value;
		idx += LSOne(idx);
	}
}

ll rsq(int idx) {
	ll csum = 0;
	while (idx >= 1) {
		csum += ft[idx];
		idx -= LSOne(idx);
	}
	return csum;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int tt;
	cin >> tt;
	while (tt--) {
		int n,k,x;
		cin >> n >> k >> x;
	
		for (int i = 1; i <= n; ++i) {
		   	ll num;
			cin >> num;
			adjust(i, num);
		}

		ll largest = 0;

		for (int i = 1; i <= n-k+1; i++) {
			ll upper = rsq(i+k-1);
			ll down = (i == 1 ? 0 : rsq(i-1));

			largest = max(largest, upper-down + k * x);
		}

		printf("%lld\n", largest);
		memset(ft, sizeof(ft), 0);
	}

	return 0;
}
