#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <tuple>
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

const int N_MAX = 20001;
int R[N_MAX];

// Kadane algorithm
tuple<int,int,int> kadane(int n) {
	int glob, locl, sL, eL, sG, eG;
	glob = 0; locl = 0; sL = 0; eL = 0; sG = 0; eG = 0;
	for (int i = 0; i < n; ++i) {
		locl += R[i];
		if (locl > glob) {
			glob = locl;
			sG = sL;
			eG = eL;
		} else if (locl == glob && abs(eL - sL) > abs(eG - sG)) {
			sG = sL;
			eG = eL;
		}

		if (locl < 0) {
			sL = i+1;
			locl = 0;
		}

		eL++;
	}

	return make_tuple(sG, eG, glob);
}


void solution() {
	int routes; cin >> routes;
	int idx = 1;

	while (routes--) {
		int r; cin >> r;
		for (int i = 0; i != r-1; ++i) cin >> R[i];

		auto t = kadane(r-1);

		if (get<2>(t) <= 0) {
			printf("Route %d has no nice parts\n", idx);
		} else {
			printf("The nicest part of route %d is between stops %d and %d\n",
				idx, get<0>(t)+1, get<1>(t)+2);
		}

		idx++;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	solution();

	return 0;
}
