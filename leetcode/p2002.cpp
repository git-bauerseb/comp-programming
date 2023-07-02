#include <string>
#include <vector>

#include <iostream>

using namespace std;

#define SET(x, i) ((x) & (1 << (i)))

class Solution {

    public:
        int maxProduct(string s) {
            const int n = s.size();

            int res = -1;

            for (int i = 0; i < (1 << n); ++i) {
                // Fix first palindrome
                if (isPalindrome(i, s)) {
                    int len = __builtin_popcount(i);
                    
                    int l = longestPalindromeSubseq(i, s);
                    res = max(res, len * l);
                }
            }

            return res;
        }

        int longestPalindromeSubseq(int mask, string s) {
            int n = s.length() - __builtin_popcount(mask);
            if (n <= 0) return 0;

            int dp[n][n];
            for (int i = 0; i < n; i++) {dp[i][i] = 1;}
            for (int i = 0; i < n; i++) {
                for (int j = i - 1; j >= 0; j--) {
                    dp[i][j] = 0;
                }
            }
            for (int i = n-2; i >= 0; i--) {
                for (int j = i+1; j < n; j++) {
                    if (getChar(mask, s, i) == getChar(mask, s, j)) {
                        dp[i][j] = 2 + dp[i+1][j-1];
                    } else {
                        dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                    }
                }
            }
            return dp[0][n-1];
        }

        char getChar(int mask, string& s, int idx) {
            
            int c_idx = 0;
            int i = 0;
            for (c_idx = 0; c_idx <= idx; ++c_idx, ++i) {
                while (i < s.size() && SET(mask, i)) ++i;
            }

            return s[i-1];
        }

        // Given a mask, check whether string at mask positions (=1)
        // is palindrome
        bool isPalindrome(int mask, string& s) {
            int l = 0;
            int r = s.size()-1;
            while (l < r) {
                // Go to next position
                while (l < s.size() && !SET(mask, l)) l++;
                while (r >= 0 && !SET(mask, r)) r--;
                if (l < r && s[l] != s[r]) return false;
            
                l++;
                r--;
            }

            return true;
        }
};

int main() {

    Solution solution{};
    int l = solution.maxProduct("leetcodecom");
    cout << l << "\n";
}
