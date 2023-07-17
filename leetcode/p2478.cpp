#include <iostream>
#include <string>
#include <cstring>

const int MOD = 1'000'000'007;
using namespace std;

int dp[1004][1004];

// Correct DP solution
// => Time complexity: O(n^3)
// => TLE
//
// After optimization
// => TLE when combining inputs

// dp[i][p] := Number of ways to partition suffix s[i], ..., s[n-1] into p substrings
//             s.t. each substring satisfies condition.
//
// Transition:
//  dp[i][p] = sum_j dp[j+1][p-1] s.t. substring s[i], ..., s[j] satisfies condition
//
class Solution {

    public:
        int beautifulPartitions(string s, int k, int minLength) {
            memset(dp, 0, sizeof(dp));
            const int n = s.size();

            minLength = max(2, minLength);

            // Base case
            // String has length n
            // Substring from i to n-1 has length n-1-i+1 = n-i
            //
            // n-i == minLength <=> i = n - minLength
            for (int i = 0; i < n; ++i) {
                dp[i][0] = 1;
            }

            for (int i = n-minLength; i >= 0; --i) {
                dp[i][1] = validSubstring(s, i, n-1) ? 1 : 0;
            }


            for (int p = 1; p < k; ++p) {
                for (int i = n-1; i >= 0; --i) {
                    
                    if (!charIsPrime(s[i])) continue;
                    
                    for (int j = i + minLength - 1; j < n; ++j) {
                        if (!charIsPrime(s[j])) {
                            dp[i][p+1] = (dp[i][p+1] + dp[j+1][p]) % MOD;
                        }
                    }
                }
            }


            return dp[0][k];
        }


        bool charIsPrime(char c) {
            return c == '2' || c == '3' || c == '5' || c == '7';
        }

        bool validSubstring(string& s, int start, int end) {
            return charIsPrime(s[start]) && !charIsPrime(s[end]);
        }
};

int main() {
    Solution solution{};
    int v = solution.beautifulPartitions("23542185131", 3, 3);
    cout << v << "\n";
    return 0;
}
