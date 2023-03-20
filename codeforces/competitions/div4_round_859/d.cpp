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

const int N_MAX = 200002;
ll ft[N_MAX];

#define LSOne(x) (x & (-x))

int rsq(int b) {
	int sum = 0;
	for (; b; b -= LSOne(b)) sum += ft[b];
	return sum;
}

ll rsq(int a, int b) {return rsq(b) - (a == 1 ? 0 : rsq(a-1));}

void adjust(int k, int v) {
	for (; k < N_MAX; k += LSOne(k))
		ft[k] += v;
}


void solution() {
	int n, q; cin >> n >> q;
	ll tSum = 0;
	for (int i = 1; i <= n; ++i) {
		ll num; cin >> num;
		tSum += num;
		adjust(i, num);
	}

	for (int i = 0; i != q; ++i) {
		int l,r;
		ll k;   
		cin >> l >> r >> k;
		ll sSum = rsq(l,r);
		ll cSum = tSum - sSum + (r - l + 1) * k;
		if (cSum % 2 == 1) cout << "YES\n";
		else cout << "NO\n";
	}

	memset(ft, 0, sizeof(ft));
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
