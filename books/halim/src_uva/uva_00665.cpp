#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <tuple>
#include <bitset>

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
void print_v(vector<T>& v) {cout << "{"; for (auto& x : v) cout << x << " "; cout << "}\n";}

// Idea
// <, > operators are not important as it is not known whether the false coin
// is heavier or lighter.
//
// Consider 3 coins and 1 measurement, 1 < 3
//  => then either 1 could be the false coin or 3
//  => if we additionally know 1 = 2 then 3 is the false coin (which is heavier)
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int M;
	cin >> M;

	while (M--) {
		int N, K;
		cin >> N >> K;

		bool coins[103] = {false};
		int left[103] = {0};
		int right[103] = {0};

		for (int i = 0; i != K; ++i) {
			int pi;
			cin >> pi;
			for (int j = 0; j != pi; ++j) {cin >> left[j];}
			for (int j = 0; j != pi; ++j) {cin >> right[j];}
			char c;
			cin >> c;
			if (c == '=')
				for (int i = 0; i != pi; ++i) coins[left[i]] = coins[right[i]] = true;
		}



		int cnt = 0;
		int ans = 0;
		for (int i = 1; i <= N; ++i) {
			if (!coins[i]) {cnt++; ans = i;}
		}


		if (cnt > 1 || cnt == 0) cout << "0\n";
		else cout << ans << "\n";
		if (M) cout << "\n";
	}

	return 0;
}
