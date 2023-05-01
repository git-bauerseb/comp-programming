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
// int DP[MONEY_MAX][GARNET_MAX];

bool REACHABLE[GARNET_MAX][MONEY_MAX];

// Store predecessor to construct optimal solution
int PRED[GARNET_MAX][MONEY_MAX];

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

void printShop(int M, vector<vector<int>> g, int c) {
	if (M <= 0 || c == g.size()) return;
	
	for (auto& e : g[c]) {
		if (tdShop(M - e, g, c+1) == DP[M][c]) {
			cout << DP[M][c] << "\n";
			printShop(M-e, g, c+1);
			break;
		}
	}
}

/*
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

void buDPSolution() {
	int M, C; cin >> M >> C;
	vector<vector<int>> garnets;
	for (int i = 0; i != C; ++i) {
		int k; cin >> k;
		vector<int> nums; nums.resize(k);
		for (int j = 0; j != k; ++j) {cin >> nums[j];}
		garnets.push_back(nums);
	}

	int idx = 0;
	for (auto& e : garnets[0]) {
		REACHABLE[0][e] = true;
	}

	for (int i = 1; i != garnets.size(); ++i) {
 		for (int m = 0; m <= M; ++m) {
		  	for (auto& e : garnets[i]) {
			   if (REACHABLE[i-1][m] && m+e <= M) {
					REACHABLE[i][m+e] = true;
			   }
		  }
	   }	   
	}

	bool found = false;
	for (int i = M; i >= 0; --i) {
		if (REACHABLE[C-1][i]) {found = true; cout << i; break;}
	}

	if (!found) {cout << "no solution";}
	cout << "\n";
}
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int tt;
	cin >> tt;
	while (tt--) {
		// recBacktrackingSol();
		// tdDPSolution();
		// memset(REACHABLE, false, sizeof(REACHABLE));
		// buDPSolution();
	}

	return 0;
}
