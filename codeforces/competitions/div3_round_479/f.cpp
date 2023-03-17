#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
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

const int N_MAX = 200001;
int NUMS[N_MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n; cin >> n;
	for (int i = 0; i != n; ++i) cin >> NUMS[i];

	map<int,int> m;
	m[NUMS[0]] = 1;

	int mLen = 1;
	int mEl = NUMS[0];

	for (int i = 1; i != n; ++i) {
		int cur = NUMS[i];
		if (m.count(cur-1) > 0) {
			int len = m[cur-1];
			m[cur] = len + 1;
			if (mLen < len+1) {
				mLen = len+1;
				mEl = cur;
			}
		} else {
			m[cur] = 1;
		}
	}

	cout << mLen << "\n";
	int cur = mEl - mLen + 1;
	for (int i = 0; i != n; ++i) {
		if (NUMS[i] == cur) {
			cout << (i+1) << " ";
			cur++;
		}
	}

	cout << "\n";
	return 0;
}
