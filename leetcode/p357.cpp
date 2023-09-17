/*
    n = 2

    First place: 9 possibilities => 1, ...., 9
    Second place: 9 possibilities => 0,....,9 \ {first place}

    => 9*9 = 81

    <= 10
    0,1,2,3,4,5,6,7,8,9 => 10 possibilities

    
    n = 3
    First place: 9
    Second place: 9
    Third place: 8
*/
#include <iostream>
#include <vector>

using namespace std;

/*
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) {return 1;}
        if (n == 1) {return 10;}

        int ans = 10;

        int poss = 9;
        int dec = 9;

        n--;
        while (n--) {
            poss *= dec;
            dec--;
            ans += poss;
        }

        return ans;
    }
};
*/

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        // Count of all numbers < 10^i that have unique digits
        vector<int> dp(9, 0);
        dp[0] = 1;
        dp[1] = 9;

        for (int i = 2; i <= n; ++i) {
            dp[i] = dp[i-1] * (11 - i);
        }

        int ans = 0;
        for (int i = 0; i <= n; ++i) ans += dp[i];
        return ans;
    }
};

// n=8 => 2345851

int main() {
    Solution s{};
    cout << s.countNumbersWithUniqueDigits(0) << "\n";
    return 0;
}
