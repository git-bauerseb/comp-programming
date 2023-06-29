#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

/*
// Solution WRONG
//  => This type of greedy does not work here
class Solution {

    public:
        string largestMultipleOfThree(vector<int>& digits) {
            const int n = digits.size();
            int dCount[10];
            memset(dCount, 0, sizeof(dCount));
            for (int i = 0; i < n; ++i) {dCount[digits[i]]++;}


            string result;

            // Add 0, 6, 9
            result.append(dCount[0], '0');
            result.append(dCount[3], '3');
            result.append(dCount[6], '6');
            result.append(dCount[9], '9');
            dCount[0] = 0;
            dCount[3] = 0;
            dCount[6] = 0;
            dCount[9] = 0;


            while (true) {
                // Check if there exist 3 digits = 1 mod 3
                int a = largestMod(dCount, 1, true);
                int b = largestMod(dCount, 1, true);
                int c = largestMod(dCount, 1, true);
                int num1 = a * 10*10 + b * 10 + c;
                bool three1 = (a > 0) && (b > 0) && (c > 0);

                // Check if there exist 3 digits = 2 mod 3
                int d = largestMod(dCount, 2, true);
                int e = largestMod(dCount, 2, true);
                int f = largestMod(dCount, 2, true);
                int num2 = d * 10*10 + e * 10 + f;
                bool three2 = (d > 0) && (e > 0) && (f > 0);


                // Both exist, so use greater
                if (three1 && three2) {
                    if (num1 > num2) {
                        dCount[d]++; dCount[e]++; dCount[f]++;
                        result.append(1, '0' + a);
                        result.append(1, '0' + b);
                        result.append(1, '0' + c);
                    } else {
                        dCount[a]++; dCount[b]++; dCount[c]++;
                        result.append(1, '0' + d);
                        result.append(1, '0' + e);
                        result.append(1, '0' + f);
                    }
                } else if (three1 && !three2) {
                    if (d >= 0) dCount[d]++;
                    if (e >= 0) dCount[e]++;
                    if (f >= 0) dCount[f]++;
                    result.append(1, '0' + a);
                    result.append(1, '0' + b);
                    result.append(1, '0' + c);
                } else if (three2 && !three1) {
                    if (a >= 0) dCount[a]++;
                    if (b >= 0) dCount[b]++;
                    if (c >= 0) dCount[c]++;
                    result.append(1, '0' + d);
                    result.append(1, '0' + e);
                    result.append(1, '0' + f);
                } else if (a >= 0 && d >= 0) {
                    if (b >= 0) dCount[b]++;
                    if (c >= 0) dCount[c]++;
                    if (e >= 0) dCount[e]++;
                    if (f >= 0) dCount[f]++;
                    result.append(1, '0' + a);
                    result.append(1, '0' + d);
                } else {
                    break;
                }
            }
            sort(result.begin(), result.end(), std::greater<char>());
            if (result[0] == '0') return result.substr(0, 1);
            return result;
        }

        int largestMod(int count[10], int mod, bool sub) {
            int res = -1;
            for (int i = 9; i >= 0; --i) {
                if ((count[i] > 0) && (i % 3) == mod) {
                    res = i;
                    if (sub) count[i]--;
                    break;
                }
            }
            return res;
        }
};
*/

int dp[100][3];

class Solution {

    public:
        int largestMultipleOfThree(vector<int>& digits) {
            const int n = digits.size();
            memset(dp, 0, sizeof(dp));
            dp[0][digits[0] % 3] = 1;

            for (int i = 1; i < n; ++i) {
                int cDigit = digits[i];

                // Suppose cDigit = 2 mod 3
                // Then i can make a longer number ending in 0 mod 3
                // by adding cDigit to number 1 mod 3


                dp[i][cDigit % 3] = 1 + dp[i][cDigit % 3]
            }

            return dp[n][0];
        }
};



int main() {
    vector<int> nums{2,2,2,1,1,1};
    Solution solution{};
    int s = solution.largestMultipleOfThree(nums);
    cout << s << "\n";

    return 0;
}
