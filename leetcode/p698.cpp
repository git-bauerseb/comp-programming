#include <bits/stdc++.h>

using namespace std;

class Solution {
	public:
		bool recBacktracking(vector<int>& nums, vector<int>& parts, int idx, int k) {
			bool cached = false;
			for (int i = 0; i != k; ++i) {cached &= DP[i][parts[i]] != -1;}
			if (cached) {
				return DP[0][parts[0]] == 1;
			}
			
			if (nums.size() == idx) {
				for (int i = 1; i != k; ++i)
					if (parts[i] != parts[i-1]) {
					   	for (int i = 0; i != k; ++i) {DP[i][parts[i]] = 0;}
						return false;
					}

				for (int i = 0; i != k; ++i) DP[i][parts[i]] = 1;
				return true;
			}

			for (int i = 0; i != k; ++i) {
				if (parts[i] + nums[idx] <= m_psum) {
					parts[i] += nums[idx];
					if (recBacktracking(nums, parts, idx+1, k)) {
						for (int i = 0; i != k; ++i) DP[i][parts[i]] = 1;
					   	return true;
					} else {
						for (int i = 0; i != k; ++i) DP[i][parts[i]] = 0;
					}
					parts[i] -= nums[idx];
				}
			}

			return false;
		}

		bool canPartitionKSubsets(vector<int>& nums, int k) {
			memset(DP, -1, sizeof(DP));
			vector<int> parts(k);
			for (auto& e : nums) m_psum += e;
			if (m_psum % k != 0) return false;
			m_psum /= k;
			return recBacktracking(nums, parts, 0, k);
		}

	private:
		int m_psum = 0;
		int DP[16][16001];

};

int main() {

	vector<int> n{354,1983,167,2655,73,927,470,485,1035,405,1358,1944,3404,4078,2500,577};
	Solution solution{};
	bool r = solution.canPartitionKSubsets(n, 5);
	cout << r << "\n";
	return 0;
}
