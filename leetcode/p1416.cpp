#include <iostream>
#include <string>
#include <cstring>

using namespace std;

const int MOD = 1'000'000'007;


// dp[i] := Number of ways to partition suffix s[i], ..., s[n-1] into numbers s.t.
//          number is in range [1,k]
//
//
int dp[100'005];
class Solution {
    public:
        int numberOfArrays(string s, int k) {
            memset(dp, 0, sizeof(dp));
            const int n = s.size();

            // Base case
            // Valid suff
            for (int i = n-1; i >= max(0, n-11); --i) {
                dp[i] = isValidNumber(s, i, n-1, k) ? 1 : 0;
            }


            for (int i = n-1; i >= 0; --i) {
                for (int j = i; j < min(n, i+11); ++j) {
                    if (isValidNumber(s, i, j, k))
                        dp[i] = (dp[i] + dp[j+1]) % MOD;
                }
            }

            return dp[0];
        }

        bool isValidNumber(string& s, int start, int end, int k) {
            if (s[start] == '0') return false;

            int ptr = end;

            long long expo = 1LL;
            long long num = 0LL;

            while (ptr >= start) {
                num += expo * static_cast<long long>(s[ptr] - '0');
                expo *= 10;
                ptr--;
            }

            return 1 <= num && num <= k;
        }
};

int main() {

    string s("1000");

    Solution solution{};
    int w = solution.numberOfArrays(s, 1000);
    cout << w << "\n";

    return 0;
}
