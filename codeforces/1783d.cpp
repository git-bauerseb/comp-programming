#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

int main() {

	int s;
	cin >> s;

	vector<int> nums(s);

	for (int i = 0; i != s; ++i)
		cin >> nums[i];

	vector<int> dp(s,0);
	dp[0] = 1;
	
	vector<bool> zero(s,false);

	for (int i = 1; i != s-1; ++i) {
		// Calculate if array can be zero at next position
		zero[i+1] = (nums[i] + nums[i+1] == 0) || (nums[i+1] - nums[i] == 0);
		if (zero[i]) {
			dp[i] = (2*dp[i-1] - 1) % MOD;
		} else {
			dp[i] = (2*dp[i-1]) % MOD;
		}
	}

	cout << dp[s-2] << "\n";
	return 0;
}
