#include <iostream>
#include <vector>
#include <map>
#include <cstring>

using namespace std;

/*
int dp[5002][302];
class Solution {
    
    public:
        int change(int amount, vector<int>& coins) {
            const int n = coins.size();
            std::fill(&dp[0][0], &dp[0][0] + sizeof(dp) / sizeof(dp[0][0]), -1);
            return rec(0, amount, 0, coins);
        }


        int rec(int amount, int target, int idx, vector<int>& c) {
            if (amount > target) {return 0;}

            int& entry = dp[amount][idx];
            if (entry != -1) return entry;

            if (amount == target) {entry = 1; return 1;}

            int w = 0;
            for (int i = idx; i < c.size(); ++i) {
                w += rec(amount + c[i], target, i, c);
            }

            entry =  w;
            return w;
        }

};
*/


// Solution with Bottom-Up DP
int dp[502][302];

// dp[m][i] := number of ways to get amount 'm' when considering numbers a[1], ..., a[i]
//
//
// dp[m][0] = 0
//   - no way to get amount m if not using any number
// dp[0][...] = 1
//   - exactly one way to get empty amount => not using any number at all
//
//
// dp[m][i] = dp[m][i-1] + dp[m-a[i]][i]
//   - either we get amount with numbers a1, ..., a[i-1]
//   - or we get m-a[i] and then add number a[i]
//
//
// E.g. a = {1,2,5}
//      m = 4
//
// dp[1][1] = dp[1][0] + dp[0][1] = 0 + 1 = 1
// dp[2][1] = dp[2][0] + dp[1][1] = 0 + 1 = 1
// dp[2][2] = dp[2][1] + dp[0][2] = 1 + 1 = 2
class Solution {

    public:
        int change(int amount, vector<int>& coins) {
            const int n = coins.size();
            memset(dp, 0, sizeof(dp));

            for (int i = n-1; i >= 0; --i) {
                dp[0][i] = 1;
            }

            // Why those lines?
            for (int m = 0; m <= amount; ++m) {
                if (m % coins[0] == 0)
                    dp[m][0] = 1;
            }

            for (int i = 1; i < n; ++i) {
                for (int m = 0; m <= amount; ++m) {
                    if (m - coins[i] >= 0) {
                        dp[m][i] = dp[m - coins[i]][i] + dp[m][i-1];
                    } else {
                        dp[m][i] = dp[m][i-1];
                    }
                }
            }

            return dp[amount][n-1];
        }
};



int main() {
    vector<int> c{2};
    Solution solution{};
    int m = solution.change(3, c);
    cout << m << "\n";

    return 0;
}
