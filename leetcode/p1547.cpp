#include <iostream>
#include <vector>
#include <map>

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
            m_cuts = move(cuts);
            int minCost = dp(0,n);
            return minCost;
        }

        // DOING THE ACTUAL WORK :-)
        //
        //
        int dp(int left, int right) {
            if (left + 1 == right) return 0;
            if (m_memo.count({left,right}) > 0) return m_memo[{left, right}];
        
            int ans = 2e9;
            for (int i = 0; i < m_cuts.size(); ++i) {
                if (m_cuts[i] > left && m_cuts[i] < right) {
                    int leftCut = dp(left, m_cuts[i]);
                    int rightCut = dp(m_cuts[i], right);
                    ans = min(leftCut + rightCut + right - left, ans);
                }
            }

            if (ans == 2e9) ans = 0;
            m_memo[{left, right}] = ans;
            return ans;
        }

    private:
        map<pair<int,int>, int> m_memo;
        vector<int> m_cuts;
};

int main() {
    vector<int> nums{5,6,1,4,2};
    Solution solution{};

    int ans = solution.minCost(9, nums);
    cout << ans << "\n";
    return 0;
}
