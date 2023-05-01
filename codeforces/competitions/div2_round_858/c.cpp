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
#define vll vector<long long>

#define si set<int>
#define sl set<long>

// Output
template <typename T>
void print_v(vector<T>& v) {cout << "{"; for (auto& x : v) cout << x << " "; cout << "\n";}

void solution() {
	int n; cin >> n;
	ll mean = 0;
	vll nums(2*n); for (int i = 0; i != 2*n; ++i) {cin >> nums[i]; mean += nums[i];}
	mean /= 2*n;
	sort(nums.begin(), nums.end());
	ll minDiff = 0;

	// For 2 elements => use mean
	if (n == 1) {
		minDiff = abs(nums[0] - mean) + abs(nums[1] - mean);
	} else {
		// Odd case, only good array is [0,...,0]
		if (n % 2 == 1) {
			for (auto& e : nums) minDiff += abs(e);
		// In the even case, there are two good arrays:
		//   [0,...,0]
		//   [-1,...,-1,n]
		// Try both and use minimum
		} else {
			ll zeroDiff = 0;
			ll nonZeroDiff = 0;
			ll twosDiff = 0;
			for (int i = 0; i != 2*n; ++i) {
				zeroDiff += abs(nums[i]);
				twosDiff += abs(nums[i] - 2);
				if (i == 2*n - 1)
					nonZeroDiff += abs(nums[i] - n);
				else 
					nonZeroDiff += abs(nums[i] + 1);
			}


			minDiff = min(zeroDiff, nonZeroDiff);
			if (n == 2) minDiff = min(minDiff, twosDiff);
		}
	}

	cout << minDiff << "\n";
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
