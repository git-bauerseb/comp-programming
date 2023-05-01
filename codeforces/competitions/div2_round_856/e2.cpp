#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

// Constants
#define MOD 1000000007
#define MOD2 998244353

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
int A[N_MAX];

vector<vector<int>> adjL;

ll fast_pow(ll b, ll e) {
	ll res = 1;
	while (e > 0) {
		if (e % 2 == 1) {
			res = res * b % MOD;
		}

		b = b * b % MOD;
		e /= 2;
	}
	return res;
}

void solution() {
	int n; cin >> n;
	
	ll H = 0;

	for (int i = 0; i < n-1; ++i) {cin >> A[i]; H += A[i] * fast_pow(MOD2, i) % MOD;}
	for (int i = 0; i < n-1; ++i) {int s,t; cin >> s >> t; adjL[s].push_back(t);
	adjL[t].push_back(s);}


}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solution();
	return 0;
}
