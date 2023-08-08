#include <iostream>

using namespace std;

class Solution {

    public:

        long long pow(long long base, long long e) {
            long long r = 1;

            while (e > 0) {
                r *= base;
                e--;
            }

            return r;
        }

        int poorPigs(int b, int mTD, int mTT) {
            if (b == 1) { return 0;}
            if ((b-1)*mTD <= mTT) { return 1; }

            int lo = 1;
            int hi = 30;

            while (hi - lo > 1) {
                
                // Current number of pigs
                long long p = lo + (hi - lo) / 2;
                long long s = (mTT + mTD) / mTD;

                if (pow(s, p) < b) {lo = p;}
                else {hi = p;}
            }

            return hi;
        }
};

int main() {

    Solution solution{};
    int m = solution.poorPigs(4, 15, 30);
    cout << m << "\n";


    return 0;
}
