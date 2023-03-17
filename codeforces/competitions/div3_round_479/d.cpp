#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <stdint.h>

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
#define vll vector<long long>
#define vllu vector<uint64_t>

#define si set<int>
#define sl set<long>

// Output
template <typename T>
void print_v(vector<T>& v) {cout << "{"; for (auto& x : v) cout << x << " "; cout << "\n";}

const int N_MAX = 101;
bool USED[N_MAX];

bool rec(vll& nums, vll& order, int nUsed) {
	const int n = nums.size();
	if (nUsed == n) return true;
	ll top = order.back();
	for (int i = 0; i != n; ++i) {
		if (top % 3 == 0 && (nums[i] == top / 3L) && !USED[i]) {
			USED[i] = true;
			order.push_back(nums[i]);
			if (rec(nums, order, nUsed+1)) {return true;}
			USED[i] = false;
			order.pop_back();
		} else if (nums[i] == 2L*top && !USED[i]) {
			USED[i] = true;
			order.push_back(nums[i]);
			if (rec(nums, order, nUsed+1)) {return true;}
			order.pop_back();
			USED[i] = false;
		}
	}

	return false;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n; cin >> n;

	vll nums(n); for (int i = 0; i != n; ++i) cin >> nums[i];
	sort(nums.begin(), nums.end());

	vll order;

	for (int i = 0; i != n; ++i) {
		order.push_back(nums[i]);
		USED[i] = true;
		if (rec(nums, order, 1)) break;
		USED[i] = false;
		order.pop_back();
	}

	for (int i = 0; i != n-1; ++i) cout << order[i] << " ";
	cout << order[n-1] << "\n";	


	return 0;
}
