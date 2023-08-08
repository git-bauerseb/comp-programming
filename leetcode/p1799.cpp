// Observations
//
// - Index of operation irrelevant
//   - finding max. gcd; can rearrange s.t. operations maximal
//
//   => Reduced to find the pairing s.t. sum of gcd's maximized
#include <iostream>
#include <vector>
#include <bitset>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <map>

using namespace std;

class Solution {

    public:
        int maxScore(vector<int>& nums) {
            const int n = nums.size();
            bitset<20> mask;
            int m = rec(mask, nums, 0);
            return m;
        }

        int rec(bitset<20>& mask, vector<int>& nums, int gcdSum) {
            if (m_memo.count(static_cast<int>(mask.to_ulong())) > 0) {
                return m_memo[static_cast<int>(mask.to_ulong())];
            }

            const int n = nums.size();
            if (mask.count() == n) {
                return gcdSum;
            }

            int m = 0;

            for (int i = 0; i < n; ++i) {
                if (!mask[i]) {
                    mask[i] = 1;
                    for (int j = 0; j < n; ++j) {
                        if (!mask[j]) {
                            mask[j] = 1;
                            int n1 = nums[i];
                            int n2 = nums[j];
                            int l_gcd = std::gcd(n1, n2);
                            int result = rec(mask, nums, l_gcd + gcdSum);
                            m = max(result, m);
                            mask[j] = 0;
                        }
                    }
                    mask[i] = 0;
                }
            }

            m_memo[static_cast<int>(mask.to_ulong())] = m;
            return m;
        } 

    private:
        vector<int> m_gcds;
        int m_gcdSum;

        // (bitset, sum) lookup
        map<int,int> m_memo;
};

int main() {

    vector<int> nums{1,2,3,4,5,6};
    Solution solution{};
    int m = solution.maxScore(nums);
    cout << m << "\n";
    return 0;
}
