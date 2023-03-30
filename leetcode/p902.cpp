#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;
using ll = long long;

class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string num = std::to_string(n);
        vector<int> d;
        for (auto& e : digits) {
            d.push_back(atoi(e.c_str()));
        }    

        // dp[...][0] - Unbounded
        // dp[...][1] - Bounded
        ll dp[20][2];
        memset(dp, 0, sizeof dp);
        const int m = num.size();

        dp[m][0] = 1;
        dp[m][1] = 1;
        for (int i = m-1; i >= 0; --i) {
            for (int t = 0; t < 2; ++t) {
                int dig = num[i] - '0';

                // dp[...][1]
                if (t) {
                    for (auto& e : d) {
                        if (e < dig)
                            dp[i][t] += dp[i+1][0];
                        if (e == dig)
                            dp[i][t] += dp[i+1][1]; 
                    }               
                // dp[...][0]
                } else {
                    dp[i][t] += d.size() * dp[i+1][0];
                }
            }
        }

        ll ans = dp[0][1];
        for (int i = m-1; i > 0; --i)
            ans += dp[i][0];
        return static_cast<int>(ans);
    }
};

int main() {
    vector<string> digits{"1", "3", "5", "7"};

    Solution solution{};
    int sol = solution.atMostNGivenDigitSet(digits, 100);
    cout << sol << "\n";
    
    return 0;
}
