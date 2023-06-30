#include <iostream>
#include <numeric>

using namespace std;

using ll = long long;


class Solution {

    public:
        int nthUglyNumber(int n, int a, int b, int c) {
            if (n == 1) {return min(a, min(b,c));}
            ll lower = 0L;
            ll upper = 2'000'000'009L;

            ll a_ = a;
            ll b_ = b;
            ll c_ = c;

            const ll ab = a_ * b_ / gcd(a_,b_);
            const ll ac = a_ * c_ / gcd(a_,c_);
            const ll bc = b_ * c_ / gcd(b_,c_);
            const ll abc = a_ * bc / gcd(a_, bc);

            while (upper - lower > 1L) {
                ll m = lower + (upper - lower) / 2L;
                // m is current guess
                // Use PIE principle to get number of ugly numbers <= m
                ll ones = cMult(m, a_) + cMult(m, b_) + cMult(m, c_);
                ll two  = cMult(m, ab) + cMult(m, ac) + cMult(m, bc);
                ll three = cMult(m, abc);
                ll cur = ones - two + three;
                if (cur < n) lower = m;
                else upper = m;
            }
            return upper;
        }

        // Count number of multiplies of k in range [1, ..., n]
        ll cMult(ll n, ll k) {
            if (n == 1L) return k == 1L;
            if (k == 1L) return n;
            if (k > n) return 0L;
            ll rem = n % k;
            return (n - rem) / k;
        }
};

int main() {
    Solution solution{};
    int c = solution.nthUglyNumber(4, 2, 3, 3);
    cout << c << "\n";
    return 0;
}
