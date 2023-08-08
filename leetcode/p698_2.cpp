#include <iostream>
#include <vector>
#include <bitset>
#include <map>

using namespace std;

/*
class Solution {
    public:

        bool canPartitionKSubsets(vector<int>& nums, int k) {
            const int n = nums.size();

            int tSum = 0;
            for (int i = 0; i < n; ++i) {
                tSum += nums[i];
            }

            int pSum = tSum / k;
            vector<int> sets;
            sets.resize(k, 0);

            return rec(nums, sets, 0, pSum);
        }

        bool rec(vector<int>& nums, vector<int>& sets, int idx, int pSum) {
            const int n = nums.size();
            const int k = sets.size();
            if (idx >= n) {
                for (auto& e : sets) {
                    if (e != pSum) {
                        return false;
                    }
                }
                return true;
            }

            for (int i = 0; i < k; ++i) {
                
                if (sets[i] + nums[idx] <= pSum) {
                    sets[i] += nums[idx];

                    if (rec(nums, sets, idx+1, pSum)) {
                        return true;
                    }

                    sets[i] -= nums[idx];
                }
            }

            return false;
        }
};
*/

// WRONG by doing k searches
// Counter example: 1,1,1,1,2,2,2,2, k = 4
//      => Valid solution: (1,2), (1,2), (1,2), (1,2)
/*
class Solution {

    public:
        bool canPartitionKSubsets(vector<int>& nums, int k) {
            const int n = nums.size();

            int tSum = 0;
            for (int i = 0; i < n; ++i) {tSum += nums[i];}

            if (tSum % k != 0) {return false;}

            int pSum = tSum / k;
            bitset<16> taken;

            for (int i = 0; i < k; ++i) {
                if (!findSubset(nums, taken, 0, 0, pSum)) {
                    return false;
                }

            }

            return true;
        }


        bool findSubset(vector<int>& nums, bitset<16>& taken, int idx, int cSum, int pSum) {
            if (idx >= nums.size()) {
                return cSum == pSum;
            }

            if (!taken[idx] && cSum + nums[idx] <= pSum) {
                cSum += nums[idx];
                taken[idx] = 1;

                if (findSubset(nums, taken, idx+1, cSum, pSum)) {
                    return true;
                }

                taken[idx] = 0;
                cSum -= nums[idx];
            }

            if (findSubset(nums, taken, idx+1, cSum, pSum)) {
                return true;
            }

            return false;
        }
};
*/

class Solution {
    public:
        bool canPartitionKSubsets(vector<int>& nums, int k) {
            const int n = nums.size();
            bitset<16> taken;

            int tSum = 0; for (auto& e : nums) tSum += e;

            if (tSum % k != 0) {return false;}

            int pSum = tSum / k;
            return rec(nums, taken, 0, 0, pSum);
        }

        bool rec(vector<int>& nums, bitset<16>& taken, int idx, int cSum, int pSum) {
            if (taken.count() == nums.size()) {
                return cSum == pSum;
            }

            if (idx >= nums.size()) {
                if (cSum != pSum) {return false;}
                else {
                    return rec(nums, taken, 0, 0, pSum);
                }
            }

            if (rec(nums, taken, idx+1, cSum, pSum)) {return true;}
            else if (taken[idx] != 1 && cSum + nums[idx] <= pSum) {
                taken[idx] = 1;
                cSum += nums[idx];

                if (rec(nums, taken, idx+1, cSum, pSum)) {
                    return true;
                }

                taken[idx] = 0;
                cSum -= nums[idx];
            }

            return false;
        }
};


int main() {

    vector<int> nums{3,2,1,3,6,1,4,8,10,8,9,1,7,9,8,1};
    
    Solution solution{};
    bool c = solution.canPartitionKSubsets(nums, 9);
    cout << c << "\n";

    return 0;
}
