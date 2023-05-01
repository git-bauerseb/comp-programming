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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while (true) {
		int n,m;
		cin >> n >> m;
		if (n == 0 && m == 0) break;

		set<int> jack;
		set<int> jill;

		for (int i = 0; i != n; ++i) {int num; cin >> num; jack.insert(num);}
		for (int j = 0; j != m; ++j) {int num; cin >> num; jill.insert(num);}

		vector<int> common;
		set_intersection(jack.begin(), jack.end(),
				jill.begin(),jill.end(), back_inserter(common));

		cout << common.size() << "\n";
	}

	return 0;
}
