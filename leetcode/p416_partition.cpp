#include <bits/stdc++.h>

using namespace std;


/*
 	S = 10
	[1,1,1,1,1,2,2,2,2,2]

	1, ,1  -> remaining = 8
	1,1,0  -> remaining = 8
*/
class Solution {
	public:
		bool knapsack(vector<int>& nums, int index, int remaining) {
			if (m_lookup.count({index, remaining}) > 0) {
				return m_lookup[{index, remaining}];
			}

			if (remaining < 0) {
				m_lookup.insert({{index, remaining}, false});
				return false;
			}
				
			if (index == nums.size()) {
				bool c = remaining == 0;	
				m_lookup.insert({{index, remaining}, c});
				return c;
			}

			if (knapsack(nums, index+1, remaining - nums[index])) {
				m_lookup.insert({{index+1, remaining - nums[index]}, true});
				return true;
			}
			
			bool res = knapsack(nums, index+1, remaining);
			m_lookup.insert({{index+1, remaining}, false});
			return res;
		}


		bool canPartition(vector<int>& nums) {
			int sum = 0; for (auto& e : nums) sum += e;
			if (sum % 2 != 0) return false;
			int S = sum / 2;

			return knapsack(nums, 0, S);
		}

	private:
		map<pair<int,int>,bool> m_lookup;

};

int main() {

	vector<int> nums;
	for (int i = 1; i <= 100; ++i) {nums.push_back(i);}

	Solution solution{};
	bool c = solution.canPartition(nums);
	cout << c << "\n";

	return 0;
}
