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

int minMoney;

// Memo for TD DP
const int MONEY_MAX = 201;
const int GARNET_MAX = 21;
int DP[MONEY_MAX][GARNET_MAX];

void shop(int M, vector<vector<int>> g, int c) {
	if (M >= 0 && c >= g.size()) {
		minMoney = min(minMoney, M);
		return;
	}
	for (auto& e : g[c]) {
		if (M-e >= 0) {
			shop(M-e, g, c+1);
		}
	}
}

void recBacktrackingSol() {
	int M, C; cin >> M >> C;
	vector<vector<int>> garnets;
	minMoney = 1 << 20;
	for (int i = 0; i != C; ++i) {
		int k; cin >> k;
		vector<int> nums;
		nums.resize(k);
		for (int j = 0; j != k; ++j) {
			cin >> nums[j];
		}

		garnets.push_back(nums);
	}

	shop(M, garnets, 0);
	if (M-minMoney < 0) cout << "no solution\n";
	else
	cout << (M-minMoney) << "\n";
}

int tdShop(int M, vector<vector<int>> g, int c) {
	if (M >= 0 && c == g.size()) {
		return M; 
	}

	if (DP[M][c] != -1) {return DP[M][c];}

	int m = 1 << 20;
	for (auto& e : g[c]) {
		if (M-e >= 0)
		m = min(m, tdShop(M-e, g, c+1));
	}

	DP[M][c] = m;
	return m;
}

void tdDPSolution() {
	int M, C; cin >> M >> C;
	vector<vector<int>> garnets;
	for (int i = 0; i != C; ++i) {
		int k; cin >> k;
		vector<int> nums; nums.resize(k);
		for (int j = 0; j != k; ++j) {
			cin >> nums[j];
		}
		garnets.push_back(nums);
	}

	// Initialize DP
	memset(DP, -1, sizeof(DP));
	int m = tdShop(M, garnets, 0);
	if (m > M) cout << "no solution\n"; else cout << (M-m) << "\n";
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int tt;
	cin >> tt;
	while (tt--) {
		// recBacktrackingSol();
		tdDPSolution();
	}

	return 0;
}
