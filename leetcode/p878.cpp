#include <iostream>
#include <vector>
#include <numeric>
#include <limits>

#define MOD 1'000'000'007

using namespace std;
using ll = long long;

class Solution {

    public:
        int nthMagicalNumber(int n, int a, int b) {
            ll a_ = a;
            ll b_ = b;
            ll n_ = n;
            ll ab = (a_ * b_) / gcd(a_, b_);
        
            ll lower = 0;
            ll higher = numeric_limits<ll>::max();

            while (higher - lower > 1) {
                ll m = lower + (higher - lower) / 2;
                ll ones = (m / a_) + (m / b_);
                ll twos = (m / ab);
                ll cur = ones - twos;
                if (cur < n_) {lower = m;}
                else {higher = m;}
            }

            return higher % MOD;
        }
};

int main() {

    Solution solution{};
    int n = solution.nthMagicalNumber(1'000'000'000, 40'000, 39'999);
    cout << n << "\n";

    return 0;
}
