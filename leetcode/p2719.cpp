#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

#define MOD 1'000'000'007L

class Solution {

    public:
        int count(string num1, string num2, int min_sum, int max_sum) {
            long lower = dpFunc(num1, min_sum, max_sum);
            long upper = dpFunc(num2, min_sum, max_sum);

            int num1DigitSum = 0;

            printf("%ld, %ld\n", lower, upper);

            for (int i = 0; i < num1.size(); ++i) num1DigitSum += (num1[i] - '0');

            bool valid = min_sum <= num1DigitSum && max_sum >= num1DigitSum;
        
        
            return (upper - lower + MOD + (valid ? 1 : 0)) % MOD;
        }


    private:

        long dp[26][410][2];

        // Returns (mod 10^9 + 7) the number of integers <= number s.t.
        // the digit sum >= minSum & digit sum <= maxSum
        long dpFunc(string& number, int minSum, int maxSum) {
            const int n = number.size();
            memset(dp, 0, sizeof(dp));
            
            // Base cases
            dp[n][0][0] = 1;
            dp[n][0][1] = 1;

            for (int s = n-1; s >= 0; --s) {
                for (int dSum = 0; dSum <= 400; ++dSum) {
                    // Unbounded case
                    for (int digit = 0; digit <= 9; ++digit) {
                        if (dSum - digit >= 0)
                        dp[s][dSum][0] = (dp[s][dSum][0] + dp[s+1][dSum - digit][0]) % MOD;
                    }

                    // Bounded case
                    int cDigit = number[s] - '0';
                    for (int digit = 0; digit < cDigit; ++digit) {
                        if (dSum - digit >= 0)
                            dp[s][dSum][1] = (dp[s][dSum][1] + dp[s+1][dSum - digit][0]) % MOD;
                    }
                    
                    if (dSum - cDigit >= 0)
                        dp[s][dSum][1] = (dp[s][dSum][1] + dp[s+1][dSum - cDigit][1]) % MOD;
                }
            }


            // Count how many numbers have digit sum >= minSum & <= maxSum
            long result = 0L;

            for (int digitSum = minSum; digitSum <= maxSum; ++digitSum)
                result = (result + dp[0][digitSum][1]) % MOD;

            return result;
        }
};

int main() {

    Solution solution {};
    long res = solution.count("4179205230", "7748704426", 8, 46);
    cout << res << "\n";

    return 0;
}
