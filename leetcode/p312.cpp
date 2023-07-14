#include <iostream>
#include <vector>
#include <bitset>
#include <cstring>
#include <unordered_map>

using namespace std;

/*
// TLE solution
class Solution {
    public:
        int maxCoins(vector<int>& nums) {
            bitset<100> mask;
            int r = rec(mask, nums);

            return r;
        }

        int rec(bitset<100>& mask, vector<int>& nums) {
            const int n = nums.size();
            int free = nums.size() - mask.count();
            
            if (m_memo.count(mask) > 0) return m_memo[mask];

            if (free == 0) {
                return 0;
            }
            
            int m = -1;

            for (int i = 0; i < nums.size(); ++i) {
                
                if (!mask[i]) {
                    int v = nums[i];
                    // Find left neighbour
                    int lN = 1;
                    for (int j = i-1; j >= 0; --j) {if (!mask[j]) {lN = nums[j]; break;}}
                    int rN = 1;
                    for (int j = i+1; j < n; ++j) {if (!mask[j]) {rN = nums[j]; break;}}

                    mask[i] = 1;
                    m = max(m, rec(mask, nums) + v * lN * rN);
                    mask[i] = 0;
                }

            }

            m_memo[mask] = m;
            return m;
        }

        unordered_map<bitset<100>,int> m_memo;
};
*/


int dp[320][320];

class Solution {

    public:
        int maxCoins(vector<int>& a) {
            const int n = a.size();           
            const int OFF = 3;
            memset(dp, 0, sizeof(dp));
            for (int i = n-1; i >= 0; --i) {
                int cl = i-1 < 0 ? 1 : a[i-1];
                int cr = i+1 >= n ? 1 : a[i+1];
                dp[i+OFF][i+OFF] = a[i] * cl * cr;
                for (int j = i; j < n; ++j) {
                    int m = -1;
                    for (int k = i; k <= j; ++k) {
                        int l = (i == 0) ? 1 : a[i-1];
                        int r = (j == (n-1)) ? 1 : a[j+1];
                        m = max(m, dp[i+OFF][k-1+OFF] + dp[k+1+OFF][j+OFF] + a[k] * l * r);
                    }
                    dp[i+OFF][j+OFF] = m;
                }
            }
            return dp[0+OFF][n-1+OFF];
        }
};


int main() {
    vector<int> nums{1,5,8};
    Solution solution{};
    int r = solution.maxCoins(nums);
    cout << r << "\n";

    return 0;
}
