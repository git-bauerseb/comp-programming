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
void print_v(vector<T>& v) {cout << "{"; for (auto& x : v) cout << x << " "; cout << "\n";}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int M;
	cin >> M;

	while (M--) {
		int N, K;
		cin >> N >> K;

		bitset<10> coins;		

		// 0 - less
		// 1 - greater
		// 2 - equal
		vector<tuple<vector<int>, vector<int>, char>> weighting;
		weighting.resize(K);

		for (int i = 0; i != K; ++i) {
			int pi;
			cin >> pi;




			for (int j = 0; j != pi; ++j) {
				int idx;
				cin >> idx;
				get<0>(weighting[i]).push_back(idx);
			}

			for (int j = 0; j != pi; ++j) {
				int idx;
				cin >> idx;
				get<1>(weighting[i]).push_back(idx);
			}

			cin >> get<2>(weighting[i]);
		}


		for (auto& e : weighting) {
			switch (get<2>(e)) {
				case '<':
					for (auto& co : get<0>(e)) {coins[co] = 1;} break;
				case '>':
					for (auto& co : get<1>(e)) {coins[co] = 1;} break;
				case '=':
					for (auto& co : get<0>(e)) coins[co] = 1;
					for (auto& co : get<1>(e)) coins[co] = 1;
					break;
			}
		}


		int idx = 0;
		for (int i = 1; i <= N; ++i) {
			if (!coins[i] && idx <= 0) idx = i;
			else if (!coins[i] && idx >= 0) {idx = 0; break;}
		}

		cout << idx << "\n"; if (M != 0) cout << "\n";
	}

	return 0;
}
