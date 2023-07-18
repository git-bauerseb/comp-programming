#include <iostream>
#include <string>
#include <cstring>
#include <vector>

const int MOD = 1'000'000'007;

using namespace std;

/*
const int M_SIZE = 300;

// dp[i][l] := Number of ways to split prefix s0, ..., si into valid numbers s.t.
//             "length" of last number is l (and last number is also valid).
int dp[200][200];

// Prefix:
// pref[i][l] := Number of ways to split prefix s0, ..., si into valid numbers s.t.
//               largest number has length <= l
int pref[200][200];

// eq[i][j]
// Longest common prefix of string s[i], .... and s[j], ....
int eq[200][200];
*/

// Solution Correct
// Time complexity: O(n^3)
// => TLE
//
// Improvement
//   - Prefix sum
//   - Fast string comparison
//   => O(n^2)
class Solution {
    public:
        void preprocess(string& s) {
            const int n = s.size();
            for (int i = n-1; i >= 0; --i) {
                for (int j = n-1; j >= 0; --j) {
                    if (s[i] == s[j]) {
                        eq[i][j] = eq[i+1][j+1] + 1;
                    }
                }
            }
        }

        int numberOfCombinations(string s) {
            const int n = s.size();


            // Edge case
            if (n == 1 && s[0] != '0') {return 1;}

            /*
            memset(dp, 0, sizeof(dp));
            memset(pref, 0, sizeof(pref));
            memset(eq, 0, sizeof(eq));
            */
            dp.resize(n+1, vector<int>(n+1, 0));
            pref.resize(n+1, vector<int>(n+1, 0));
            eq.resize(n+1, vector<int>(n+1, 0));

            preprocess(s);

             int answer = 0;

            // Base case
            for (int i = 0; i < n; ++i) {
                dp[i][i+1] = s[0] != '0';
                pref[i][i+1] = s[0] != '0';
            }

            for (int i = 1; i < n; ++i) {

                for (int l = 1; l <= n; ++l) {pref[i-1][l] = (pref[i-1][l-1]+dp[i-1][l]) % MOD;}

                for (int j = i; j >= 0; --j) {
                    const int k = i - j + 1;


                    // Current number starts with '0', so cannot use
                    if (i - k  + 1 < 0 || s[i - k + 1] == '0') {continue;}
                    if (i - k >= 0) {dp[i][k] = (dp[i][k] + pref[i-k][k - 1]) % MOD;}

                    if (i-2*k+1 >= 0 && smallerEqual(s, i-2*k+1, i-k+1, k)) {
                        dp[i][k] = (dp[i][k] + dp[i - k][k]) % MOD;
                    }

                    if (i == n-1) {
                        answer = (answer + dp[i][k]) % MOD;
                    }
                }
            }

            return answer;

        }

        // True if number starting at position 'start1' is <= 
        // number starting at position 'start2'
        bool smallerEqual(string& s, int start1, int start2, int l) {
            // Optimization
            int pref = eq[start1][start2];
            if (pref >= l) return true;
            if (s[start1+pref] <= s[start2+pref]) return true;
            return false;
            
            
           /*
           for (int i = 0; i < l; ++i) {
                if (s[start1 + i] > s[start2 + i]) return false;
                else if (s[start1 + i] < s[start2 + i]) return true;
           }
           return true;
           */
       }

       vector<vector<int>> eq;
       vector<vector<int>> pref;
       vector<vector<int>> dp;
};


// INPUT: 9286124525
//
// 928 612 4525
// 
// MISSING: 9 28 61 24525
// 92 861 24525
// 9 2861 24525
//
// 9 286 124525
// 9286 124525
//
// 9 28 6124525
// 928 6124525
//
// 92 86124525
//
// 9 286124525
//
// 9286124525
//


// 9 286
int main() {

    Solution solution{};
    int n = solution.numberOfCombinations("3242415415206436110371293870051627136111554");
    cout << n << "\n";

    return 0;
}
