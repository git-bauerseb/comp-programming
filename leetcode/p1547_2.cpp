#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <algorithm>

using namespace std;

// Brute force/Complete search:
//  - Look at every cut not done then execute and save minimum
//  - O(n!) = O(n!)[Different arr. of cuts] * O(1) [calculate minimum]
//  foreach (cut) do
//    cut at position (split into left/right + add value right - left)
//
// DP
//  - idea -> same as complete search
//  - memo[left][right] := minimum cost for cutting stick s[left], ..., s[right]
//
//  Len = 10
//  Cuts: 2 4 8
//
//  Seq1 : 2 4 8    10 -> (0-2,2-10) -> (0-2,2-4,4-10) -> (0-2,2-4,8-10)
//  Seq2 : 4 2 8    10 -> (0-4,4-10) -> (0-2,2-4,4-10) -> ...
//
//  n cuts -> (n+2)*(n+2) = O(n^2)
//    => TOTAL RUNTIME: O(n^2)[States] * O(n)[Runtime per state] = O(n^3) 
class Solution {
    public:
        // GOOD DESCRIPTION :-)
        int minCost(int n, vector<int>& cuts) {
            sort(cuts.begin(), cuts.end());
            memset(memo, -1, sizeof memo); 
            m_a[0] = 0;
            for (int i = 1; i <= cuts.size(); ++i) m_a[i] = cuts[i-1];
            m_a[cuts.size()+1] = n;
            int ans = dp(0, cuts.size()+1);
            return ans;
        }

        // DOING THE ACTUAL WORK :-)
        //
        //
        int dp(int left, int right) {
            if (left + 1 == right) return 0;
            int& ans = memo[left][right];
            if (ans != -1) return ans;
            ans = 999'999'999;
            for (int i = left + 1; i < right; ++i) {
                int lCut = dp(left, i);
                int rCut = dp(i, right);
                ans = min(ans, lCut + rCut + m_a[right] - m_a[left]);
            }

            return ans;
        }

    private:
        int memo[105][105];
        int m_a[105];
};


int main() {
    vector<int> nums{5,6,1,4,2};
    Solution solution{};
    int ans = solution.minCost(9, nums);
    cout << ans << "\n";


    return 0;
}
