#include <iostream>
#include <vector>

using namespace std;

// dp[i] := Maximum AND sum after slots, encoded by i, are occupied.
//
// Each slot -> 2 bits
//
// 11 00 00 00 .. 00
// ^^
// 2 elements in first slot
class Solution {
    public:
        vector<vector<short>> dp;
        
        int maximumANDSum(vector<int>& nums, int numSlots) {
            dp.resize(1 << (2*numSlots), vector<short>(2*45+1, -1));
            return rec(nums, numSlots, 0, 0, 0);
        }

        int rec(vector<int>& nums, int s, int csum, int occ, int idx) {
            if (idx >= nums.size()) {
                return csum;
            }

            short& entry = dp[occ][csum];
            if (entry > -1) return entry;

            entry = 0;

            for (int i = 0; i < s; ++i) {
                if (((occ >> (2*i)) & 0b11) != 0b11) {
                    int hm = 0;

                    if (((occ >> (2*i)) & 0b11) == 1) {
                        hm = 2;
                        occ |= (0b11 << (2*i));
                    } else {
                        occ |= (1 << (2*i));
                        hm = 1;
                    }

                    int nsum = (i+1) & nums[idx];
                    entry = max((int)entry, rec(nums, s, csum + nsum, occ, idx+1));
                
                    if (hm == 2) {
                        occ &= ~(0b10 << (2*i));
                    } else {
                        occ &= ~(0b11 << (2*i));
                    }
                }
            }

            return entry;
        }
};

int main() {
    vector<int> nums{1,2,3,4,5,6};
    Solution solution{};
    cout << solution.maximumANDSum(nums, 3) << "\n";
    return 0;
}
