#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

/*
    Strategy for selecting remaining numbers:

    If 2*min(1s, 2s) > 3 => take min(1s,2s) 1s and 2s 

    1 1 1 2 2 2 2 2 2

    (1,2), (1,2), (1,2) 2

    Proof of optimal length:

    Case 1: Suppose same number of 1s/2s, then all can be selected greedily.
            => Optimal length

    Case 2: Suppose number of 2s > number of 1s (Same for symmetric case).
            => Then greedy algorithm leaves some 2s

            The only case where no numbers can be greedily formed but by 2s only
            is 2 2 2. But since
2*min(1s, 2s) > 3
            2min(1s,2s) > 3 = 2*1s > 3

            the greedily selected numbers form a number with greater length.
*/


using namespace std;

class Solution {

    int digits[10];

    public:
        string largestMultipleOfThree(vector<int>& dig) {
            const int n = dig.size();
            memset(digits, 0, sizeof(digits));

            int oMod = 0;
            int tMod = 0;

            string output;

            for (int i = 0; i < n; ++i) {
                int cd = dig[i];    
                if (cd % 3 == 0) {
                    output += cd + '0';
                } else if (cd % 3 == 1) {
                    oMod++;
                    digits[cd]++;
                } else {
                    tMod++;
                    digits[cd]++;
                }
            }

            while (true) {
                if (2*min(oMod, tMod) > 3) {
                    for (int i = 0; 2*min(oMod, tMod) > 3; ++i) {
                        output += largestMod(1) + '0';
                        output += largestMod(2) + '0';
                        oMod -= 1;
                        tMod -= 1;
                    }
                } else if (tMod > 2) {
                    for (int i = 0; i < 3; ++i) output += largestMod(2) + '0';
                    tMod -= 3;
                } else if (oMod > 2) {
                    for (int i = 0; i < 3; ++i) output += largestMod(1) + '0';
                    oMod -= 3;
                } else {break;}
            }

            int bound = min(oMod, tMod);
            for (int i = 0; i < bound; ++i) {
                output += largestMod(1) + '0';
                output += largestMod(2) + '0';
            }

            sort(output.begin(), output.end(), std::greater<char>());
            
            
            if (output[0] == '0' && output[output.size()-1] == '0' && output.size() > 0) {
                return "0";
            }
            
            return output;
        }

        int largestMod(int rem) {
            for (int i = 9; i >= 1; --i) {
                if (i % 3 == rem && digits[i] > 0) {digits[i]--; return i;}
            }
            return -1;
        }
};

int main() {

    // 7 1 2 4 4 8

    // Expected: 87441000
    // Output:   8742000

    // 1 mod: 7 4 4 1
    // 2 mod: 8 2

    // vector<int> digits{8,7,4,4,2,1};
    vector<int> digits{7,1,2,4,0,0,4,0,3,8};

    Solution solution{};
    string s = solution.largestMultipleOfThree(digits);
    cout << s << "\n";
    return 0;
}
