#include <iostream>
#include <string>
#include <cstring>

const int MOD = 1'000'000'007;
using namespace std;

// int dp[1004][1004];

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
/*
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
*/

int dp[1004][1004];
int pref[1004];

class Solution {
    public:
        int beautifulPartitions(string s, int k, int minLength) {
            memset(dp, 0, sizeof(dp));
            memset(pref, 0, sizeof(pref));

            const int n = s.size();

            minLength = max(2, minLength);

            // Base cases
            for (int i = 0; i < n; ++i) {dp[i][0] = 1;}
            for (int i = n-minLength; i >= 0; --i) {
                dp[i][1] = validSubstring(s, i, n-1) ? 1 : 0;
            }

            // Transitions
            for (int p = 1; p < k; ++p) {
                
                for (int j = n-minLength; j >= 0; --j) {
                    pref[j] = pref[j+1];
                    if (!charIsPrime(s[j])) {
                        pref[j] = (pref[j] + dp[j+1][p]) % MOD;
                    }
                } 
                
                for (int i = n-minLength; i >= 0; --i) {
                    if (!charIsPrime(s[i])) continue;
                    dp[i][p+1] = pref[i+minLength-1];
                }
            }

            return dp[0][k];
        }

        bool charIsPrime(char c) {return c == '2' || c == '3' || c == '5' || c == '7';}
        bool validSubstring(string& s, int start, int end) {
            return charIsPrime(s[start]) && !charIsPrime(s[end]);
        }
};

// Word    2 3 5 4 2 1 8 5 1 3 1
// Idx     0 1 2 3 4 5 6 7 8 9 10

int main() {
    Solution solution{};
    int v = solution.beautifulPartitions("2958", 2, 2);
    cout << v << "\n";
    return 0;
}
