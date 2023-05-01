#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>

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

void solution() {
	int n; cin >> n;
	
	int zeros = 0;
	int ones = 0;
	int greater = 0;
	
	for (int i = 0; i != n; ++i) {
		int num; cin >> num; zeros += num == 0 ? 1 : 0;
		ones += num == 1 ? 1 : 0;
		greater += num > 1 ? 1 : 0;
	}

	if (zeros <= (n+1)/2) {cout << "0\n";}
	else {
		if (ones < 1 || greater > 0) cout << "1\n";
		else cout << "2\n";
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
