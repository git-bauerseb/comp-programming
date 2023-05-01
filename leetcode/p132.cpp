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

int memo[2003][2003];

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


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    Solution solution{};
    int mCut = solution.minCut("abcdefg");
    cout << mCut << "\n";
	return 0;
}
