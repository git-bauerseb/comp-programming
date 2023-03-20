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

#define LSOne(x) ((x) & (-x))

// Output
template <typename T>
void print_v(vector<T>& v) {cout << "{"; for (auto& x : v) cout << x << " "; cout << "\n";}

const int N_MAX = 200001;
bool VALID[N_MAX];

int ft[N_MAX];

void adjust(int b, int v) {
	for (; b < N_MAX; b += LSOne(b)) ft[b] += v;
}

int rsq(int b) {
	int sum = 0;
	for (; b; b -= LSOne(b)) sum += ft[b];
	return sum;
}

int rsq(int a, int b) {
	return rsq(b) - (a == 1 ? 0 : rsq(a-1));
}

int query(int l, int r) {
	cout << "? " << (r - l + 1) << " ";
	for (int i = l; i <= r; ++i) {
		cout << i << " ";
	}
	cout << "\n";
	int weight;
	cin >> weight;
	return weight;
}

void solution() {
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		int num; cin >> num;
		adjust(i, num);
	}

	int l = 1;
	int r = n;

	while (l < r) {
		int m = l + (r-l) / 2;
		int weight = query(l, m);
		int nWeight = rsq(l,m);
		if (weight == nWeight) {
			l = m+1;
		} else {
			r = m;
		}
	}

	cout << "! " << l << "\n";
	memset(ft, 0, sizeof(ft));
}

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		solution();
	}

	return 0;
}
