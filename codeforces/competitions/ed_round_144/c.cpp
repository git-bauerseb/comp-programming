#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

// Constants
#define MOD 998'244'353L

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

// Consider l = 4, r = 100
//
// Largest sequence is if only multiplying by 2: k, 2k, 4k, 8k, 16k, ...
//  - find largest power of 2 (m) such that k*2^m <= r
//

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int tt;
	cin >> tt;
	while (tt--) {
		int l,r;
		cin >> l >> r;
		int m = 0;
		int l_cpy1 = l;
		while (l_cpy1 <= r) {m++; l_cpy1 <<= 1;}
		int maxLen = m;
		int totalNum = 0;

		int u = r / (1 << (m-1));
		if (u >= l) {
			totalNum += (u - l + 1);
		}


		u = r / ((1 << (m-2)) * 3);
		if (u >= l) {
			totalNum += (u - l + 1) * (m-1);
		}

		printf("%d %d\n", maxLen, totalNum);
	}

	return 0;
}
