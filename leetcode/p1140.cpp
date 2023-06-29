#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>


using namespace std;

// dp[start][m]
int dp[103][203];

class Solution {
    public:
        int stoneGameII(vector<int>& piles) {
            const int n = piles.size();

            memset(dp, -1, sizeof(dp));

            vector<int> pSum(n, 0);
            pSum[0] = piles[0];

            for (int i = 1; i < n; ++i) pSum[i] = pSum[i-1] + piles[i];
        
            return rec(pSum, 0, 1);
        }

        // For a player starting at position 'start' with given 'm' value,
        // return the maximum number of stones that he can pick.
        //
        // pSum: prefix sum of stone piles
        int rec(vector<int>& pSum, int start, int m) {
            const int n = pSum.size();
            int rem = n - start;

            // There are no piles left, so we can't take anything
            if (start >= n) {return 0;}

            int& entry = dp[start][m];
            if (entry >= 0) {return entry;}

            // We can take everything which is optimal because enemy can
            // then take nothing
            if (rem <= 2*m) {
                entry = pSum[n-1] - (start == 0 ? 0 : pSum[start-1]);
                return entry;
            }

            int mAmount = 0;

            for (int x = 1; x <= min(rem, 2*m); ++x) {

                // Player takes next x piles starting at start
                // pile[start], ..., pile[start + x - 1]
                int cSum = pSum[start + x - 1] - (start == 0 ? 0 : pSum[start - 1]);
                int m1 = max(m, x);

                int minSecond = 1 << 28;

                for (int y = 1; y <= min(rem-x,2*m1); ++y) {

                    // Enemy now takes next y piles starting at start + x
                    // pile[start + x], ..., pile[start + x + y - 1]
                    
                    // New m dependent on y
                    int m2 = max(m1, y);


                    // After that player can again take stones starting at pile
                    // pile[start + x + y]
                    int player2Move = rec(pSum, start + x + y, m2); 
                
                    minSecond = min(player2Move, minSecond);
                }

                mAmount = max(cSum + minSecond, mAmount);
            }

            entry = mAmount;
            return entry;
        }
};

int main() {
    
    vector<int> nums{1,10,21,30};
    
    Solution solution{};
    int m = solution.stoneGameII(nums);
    cout << m << "\n";
    return 0;
}
