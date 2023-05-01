#include <iostream>
#include <string>

using namespace std;

const int MAX_NUM_LENGTH = 203;
const int MAX_DIGIT_SUM = 9 * MAX_NUM_LENGTH + 1;
long long dp[MAX_NUM_LENGTH][MAX_DIGIT_SUM][2];

bool is_prime(long long n) {
    if (n == 2 || n == 3) return true;
    if (n <= 1 || (n % 2 == 0) || (n % 3 == 0)) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if ((n % i == 0) || (n % (i + 2) == 0))
            return false;
    }

    return true;
}

long long how_many(string& number) {
    const int n = number.size();

    dp[0][0][0] = 1;
    dp[0][0][1] = 1;

    for (int i = 1; i <= n; ++i) {

        // ith lowest order digit is at n-i
        int currDigit = number[n-i] - '0';

        for (int d = 0; d < 10; ++d) {
            for (int s = d; s <= 9*n; ++s) {
                
                // Bounded case    
                if (d < currDigit) {
                    dp[i][s][1] += dp[i-1][s-d][0];
                } else if (d == currDigit) {
                    dp[i][s][1] += dp[i-1][s-d][1];
                }

                // Unbounded
                dp[i][s][0] += dp[i-1][s-d][0];
            }
        }
    }

    long long primeDSum = 0;
    for (int i = 0; i < MAX_DIGIT_SUM; ++i) {
        if (is_prime(i)) {
            // We are only interested in bounded suffixes
            primeDSum += dp[n][i][1];
        }
    } 

    return primeDSum;
}

int main() {
    
    string s("1");
    for (int i = 0; i < 20; ++i) s += '0';
    long long result = how_many(s);
    cout << result << "\n";

    return 0;
}
