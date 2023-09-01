#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

const int MOD = 1'000'000'007;

/*
    dp[i] := Number of ways to decode s[1], ..., s[i] (1 indexed)


    11106

    111 => 1 1 1
        => 1 11
        => 11 1

    1*
*/
class Solution {
public:
    int numDecodings(string s) {
        const int n = s.size();
    
        vector<long long> dp(3,0);
        dp[1] = 1;
        dp[0] = 1;

        for (int i = 1; i <= n; ++i) {
            char curr = s[i-1];

            if (curr >= '1' && curr <= '9') {
                dp[2] += dp[1];
            } else if (curr == '*') {
                dp[2] += 9*dp[1];
            }

            dp[2] %= MOD;
            
            // Use 2 characters
            if (i >= 2) {
                char prev = s[i-2];
                if (prev == '*') {
                    if (curr == '*') {
                        dp[2] += 15*dp[0];   
                    } else {
                        long long toAdd = (curr <= '6') ? 2 : 1;
                        dp[2] += toAdd*dp[0];
                    }
                    dp[2] %= MOD;
                } else {
                    if (prev <= '0' || prev > '2') {
                        ;
                    } else if (prev == '1') {
                        long long toAdd = curr == '*' ? 9 : 1;
                        dp[2] += toAdd*dp[0];
                        dp[2] %= MOD;
                    } else {
                        if (curr == '*') {
                            dp[2] += 6*dp[0];
                        } else if (curr >= '0' && curr <= '6') {
                            dp[2] += dp[0];
                        }
                        dp[2] %= MOD;
                    }
                }
            }

            dp[0] = dp[1];
            dp[1] = dp[2];
            dp[2] = 0;
        }

        return dp[1];
    }
};

/*
    
    **
     => * *
     => **


     * * => {1,...,9} x {1,...,9} => 81
     ** => 15
*/
int main() {
    Solution s{};
    cout << s.numDecodings("***") << "\n";
    return 0;
}
