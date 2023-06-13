#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>

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

// int memo[2003][2003];

/*
// TLE
class Solution {
    public:
        int minCut(string s) {
            const int n = s.size();
            // memset(memo, -1, sizeof memo);
            for (int i = 0; i <= n; ++i) {
                for (int j = i+1; j <= n; ++j) {
                    memo[i][j] = 1E8;
                    for (int k = i+1; k <= j; ++k) {
                        memo[i][j] = min(memo[i][j],memo[i][k] + memo[k][j] + 1);
                    }
                }
            }
            
            return memo[0][n];
            // return rec(s, 0, n);
        }


        // Minimum cuts to partition s[left], ..., s[right-1] into palindrome
        int rec(string& s, int left, int right) {
            if (memo[left][right] != -1) return memo[left][right];
            int& ans = memo[left][right];

            if (isPalindrome(s, left, right-1)) {ans = 0; return ans;}
            if (left >= right) {ans = 0; return 0;}
            if (left+1 == right) {ans = 0; return 0;}
            ans = 1E8;
            // Make cut at i
            //   -> split string into s[left], ..., s[i]
            //    & s[i], ..., s[right]
            //   => rec(left, i)
            //   => rec(i, right)
            for (int i = left+1; i < right; ++i) {
                int minLeft = rec(s, left, i);
                int minRight = rec(s, i, right);
                ans = min(minLeft+minRight+1, ans);
            }
            return ans;
        }


    private:
        inline bool isPalindrome(string& s, int start, int end) {
            while (start < end) {
                if (s[start] != s[end]){return false;}
                start++;
                end--;
            }

            return true;
        }
};
*/

// WRONG IDEA
// Idea: Calculate longest palindrome ending at every index
//       Traverse back and count number of palindromes
//       Result is num palindromes - 1
// Wrong answer on: cabababcbc

/*
class Solution {

    public:
        int minCut(string s) {
            const int n = s.size();

            // Determine length of longest palindrome ending at index i
            vector<int> dp(n+1, 0);
            dp[0] = 0;
            dp[1] = 1;

            for (int i = 2; i <= n; ++i) {
                int& entry = dp[i];
                entry = s[i-1] == s[i-2] ? 2 : 1;
                entry = s[i-1] == s[i - 1 - dp[i-1]] ? dp[i-1] + 1 : entry;

                if (i - 2 - dp[i-1] >= 0) {
                    char prev = s[i - 2 - dp[i-1]];
                    entry = s[i-1] == prev ? dp[i-1] + 2 : entry;
                }
            }

            int minCuts = 0;
            int rem = n;

            while (rem > 0) {
                rem -= dp[rem];
                minCuts++;
            }

            return minCuts-1;
        }
};
*/

// Time: O(n^3)

/*
class Solution {

    public:
        int minCut(string s) {
            const int n = s.size();
            m_s = s;

            m_memo.resize(n+1, vector<int>(n+1, -1));
            m_palin.resize(n+1, vector<bool>(n+1, false));
            setup();
            return topDown(0, s.size()-1);
        }

    private:
        
        void setup() {
            const int n = m_s.size();
            for (int i = 0; i < n; ++i) {m_palin[i][i] = true;}
            for (int i = 0; i < n-1; ++i) {m_palin[i][i+1] = m_s[i] == m_s[i+1];}
            
            // String s[i, ...., j] is palindrome if s[i] == s[j] and
            // s[i+1, ..., j-1] is palindrome
            for (int k = 2; k < n; ++k) {
                for (int i = 0; i + k < n; ++i) {
                    m_palin[i][i+k] = m_s[i] == m_s[i+k] && m_palin[i+1][i+k-1];
                }
            }
        }

        // Minimum number of cuts to partition s[start, ..., end] into palindromes
        int topDown(int start, int end) {
            int& entry = m_memo[start][end];
            if (entry >= 0) return entry;
            if (m_palin[start][end]) {entry = 0; return 0;}
            
            // not necessary, as m_palin[start][start] is true
            // if (end == start) {entry = 0; return 0;}
            
            if (end == start+1) {
                entry = m_s[start] != m_s[end] ? 1 : 0;
                return entry;
            }

            int m = 1 << 29;

            for (int pos = start; pos < end; ++pos) {
                m = min(m, topDown(start, pos) + topDown(pos+1, end) + 1);
            }

            entry = m;
            return m;
        }

        vector<vector<int>> m_memo;
        
        // m_palin[i][j] = true iff s[i, ..., j] is palindrome
        vector<vector<bool>> m_palin;
        
        string m_s;
};
*/


class Solution {

    public:
        int minCut(string s) {
            m_s = s;
            setup();

            const int n = m_s.size();
            vector<int> dp(n+1, 10000);

            for (int i = 0; i < n; ++i) {
                int& entry = dp[i];
                if (m_pal[0][i]) {entry = 0; continue;}

                for (int j = i; j >= 1; --j) {
                    if (m_pal[j][i])
                        entry = min(entry, dp[j-1] + 1);
                }
            }

            return dp[n-1];
        }

        void setup() {
            const int n = m_s.size();
            m_pal.resize(n+1, vector<bool>(n+1, false));
        
            for (int i = 0; i < n; ++i) {m_pal[i][i] = true;}
            for (int i = 0; i < n-1; ++i) {m_pal[i][i+1] = m_s[i] == m_s[i+1];}
            for (int j = 2; j < n; ++j) {
                for (int i = 0; i + j < n; ++i) {
                    m_pal[i][i+j] = m_pal[i+1][i+j-1] && m_s[i] == m_s[i+j];
                }
            }
        }

    private:
        string m_s;
        vector<vector<bool>> m_pal;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    Solution solution{};
    int mCut = solution.minCut("aabbc");
    cout << mCut << "\n";
	return 0;
}
