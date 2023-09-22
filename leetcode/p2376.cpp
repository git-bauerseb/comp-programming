#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        // Count how many special numbers from 1 to 10^n
        int below10X(int n) {
            if (n == 0) {return 0;}
            if (n == 1) {return 0;}

            int ans = 10;
            int poss = 9;
            int dec = 9;
            
            int nCpy = n;

            n--;
            while (n--) {
                poss *= dec;
                dec--;
                ans += poss;
            }

            int pow = nCpy;
            int num = 1;
            while (pow > 0) {num *= 10; pow--;}
            return num - ans + 1;
        }

        int fac(int n) {
            int r = 1;
            for (int i = 2; i <= n; ++i) {
                r *= i;
            }
            return r;
        }

        int binom(int n, int k) {
            return fac(n) / (fac(k)*fac(n-k));
        }
        
        int countSpecialNumbers(int n) {
            int pow = 0;
            int nCpy = n;
            vector<int> digits;
            
            while (nCpy > 0) {
                digits.push_back(nCpy % 10);
                nCpy /= 10;
                pow++;
            }

            pow--;
            int ans = below10X(pow);
            int leading = digits[pow];
            
            printf("%d\n", ans);

            for (int i = 1; i < leading; ++i) {
                for (int j = 1; j <= pow; ++j) {
                    ans += 10 * binom(pow, j);
                }
            }

            
            for (int i = 1; i < (1 << pow); ++i) {
                printf("%d ", i);
            }


            return 0;
        }
};

// 99, 88, 77, 66, 55, 44, 33, 22, 11, 100
int main() {
    Solution s{};
    s.countSpecialNumbers(135);
    return 0;
}
