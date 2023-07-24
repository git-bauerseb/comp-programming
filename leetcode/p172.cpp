#include <iostream>

using namespace std;

class Solution {
    public:

        int numFactors(int n, int fac) {
            int r = 0;
            while (n % fac == 0) {n /= fac; ++r;}
            return r;
        }

        int trailingZeroes(int n) {
            int fives = 0;
            int twos = 0;

            for (int i = 2; i <= n; ++i) {
                fives += numFactors(i, 5);
                twos += numFactors(i, 2);
            }

            return min(fives, twos);
        }
};
