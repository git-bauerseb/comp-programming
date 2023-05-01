#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>

using namespace std;

// Constants
#define MOD 1'000'000'007

// Simple types
#define ll long long
#define ld long double

// Aggeragte types
#define pii pair<int,int>
#define pll pair<long,long>

#define vi vector<int>
#define vl vector<long>

#define si set<int>
#define sl set<long>

// Output
template <typename T>
void print_v(vector<T>& v) {cout << "{"; for (auto& x : v) cout << x << " "; cout << "\n";}

//  dp[i] := longest valid parentheses substring ending at position i
//
//          )   (   )   (   )   ) 
// State:   0   1   2   1   4   0
//
//          (   )   (   (   )   )
// State:   1   2   1   1   2   6
//
//          (   )   (    )    )    (
// State:   1   2   1    4    0    1
//          
//   
//          (   (   (   )  (   )    )    )    )
// State:   1   1   1   2  1   4    5    6    0
//
//          (   (   )
// State:   1   1   2
//
//          0   1   2   3
//          (   (   )   )
// State:   1   1   2   
//  
//
//  dp[0] = s[0] == ')' ? 0 : 1
//
//  if s[i] == '(': dp[i] = 1
//  if s[i] == ')':
//    - Check if previous element is '('
//      - If yes, then dp[i] = dp[i-1]+1
//      - If no, look back dp[i-1] and check s[dp[i-1]] == '('
//        -> if yes: dp[i] = dp[i-1]+1+dp[dp[i-1]-1]
//      - Else: dp[i] = 0
//
//  Observation:
//    - valid parenthesis can only start with '(' not ')'
class Solution {

    public:
        int longestValidParentheses(string s) {
            const int n = s.size();
            vector<int> dp(n, 0);
            int max_ = 0;
            for (int i = 1; i < n; ++i) {   
                if (s[i] == ')') {
                    if (s[i-1] == '(') {
                        dp[i] = 2;
                        if (i > 1)
                            dp[i] += dp[i-2];
                    } else {
                        int lookback = i-dp[i-1]-1;
                        if (lookback >= 0 && s[lookback] == '(') {
                            dp[i] = 2 + dp[i-1];

                            if (lookback-1 >= 0)
                                dp[i] += dp[lookback-1];
                        }
                    }
                }

                max_ = max(max_, dp[i]);
            }

            return max_;
        }

};


int main() {
    Solution solution{};
    int l = solution.longestValidParentheses(")))(())()))))");
    cout << l << "\n";
	return 0;
}
