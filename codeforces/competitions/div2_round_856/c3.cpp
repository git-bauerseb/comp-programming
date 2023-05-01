#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

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

const int N_MAX = 100'002;
int A[N_MAX];

void solution() {
	int n;
	cin >> n;

	for (int i = 0; i != n; ++i) cin >> A[i];

	for (int i = 0; i != n; ++i) {
		auto it = lower_bound(A, A + i, -1, [](int element, int value {
			int pos = &;
			return element / (&element - A);			
		}));
	}
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
