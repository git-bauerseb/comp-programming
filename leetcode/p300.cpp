#include <bits/stdc++.h>

using namespace std;

// O(n^2) solution
/*
class Solution {
	public:
		int lengthOfLIS(vector<int>& nums) {
			const int n = nums.size();
			vector<int> dp(n);
			dp[0] = 1;
			for (int i = 1; i < n; ++i) {
				int m = 1;
				for (int j = i-1; j >= 0; j--) {
					if (nums[i] > nums[j]) {
						m = max(m, dp[j]+1);
					}
				}

				dp[i] = m;
			}

			int m = 1; for (auto& e : dp) m = max(m, e);
			return m;	
		}
};
*/

// O(n log n) solution
class Solution {
	public:
		int lengthOfLIS(vector<int>& nums) {
			const int n = nums.size();
			int len = 1;
			vector<int> a(n);
			a[0] = nums[0];

			for (int i = 1; i < n; ++i) {
				auto it = lower_bound(a.begin(), a.begin()+len, nums[i]);
				if (it == a.begin()+len) {
					a[len++] = nums[i];
				} else {
					*it = nums[i];
				}
			}
			return len;
		}
};


int main() {

	vector<int> nums{10,9,2,5,3,7,101,18};
	Solution solution{};
	int l = solution.lengthOfLIS(nums);
	cout << l << "\n";

	return 0;
}

