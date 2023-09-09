#include <iostream>
#include <vector>
#include <vector>
#include <map>

using namespace std;

const int MOD = 1'000'000'007;

long long fact[3001];
long long fact_inv[3001];

class Solution {
    public:

        long long fac(long long f) {
            long long r = 1;
            for (int i = 2; i <= f; ++i) {
                r *= i;
                r %= MOD;
            }
            return r;
        }

        // 01
        // newbase = base*base*base*base
        // base^4 = base * base * base * base
        long long binpow(long long base, int exp) {
            base %= MOD;
            long long res = 1;
            while (exp > 0) {
                if (exp & 1) {
                    res *= base;
                    res %= MOD;
                }
                base *= base;
                base %= MOD;
                exp >>= 1;
            }

            return res;
        }

        long long inv(long long val) {
            return binpow(val, MOD - 2) % MOD;
        }


        // Given chars with their frequencies, returns the number of arrangements
        // possible.
        long long comb(map<char, int>& occ) {
            long long total = 0;
            for (auto& [key, value]: occ) {total += value;}

            long long result = fact[total];

            for (auto& [key, value]: occ) {
                result *= fact_inv[value];
                result %= MOD;
            }

            return result;
        }

        void precalculate() {
            fill(&fact[0], &fact[3000], 1);
            fill(&fact_inv[0], &fact_inv[3000], 1);
            
            for (int i = 1; i <= 3000; ++i) {
                fact[i] = fac(i);
                fact_inv[i] = inv(fact[i]);
            }
        }

        int makeStringSorted(string s) {
            const int n = s.size();
            precalculate();
            
            map<char, int> occ;
            
            for (auto& e : s) {
                occ[e]++;
            }

            long long answer = 0;

            for (int i = 0; i < n-1; ++i) {
                char curr = s[i];
                for (char c = 'a'; c <= 'z'; ++c) {
                    if (occ[c] > 0 && c < curr) {
                        occ[c]--;
                        answer += comb(occ);
                        answer %= MOD;
                        occ[c]++;
                    }
                }

                occ[curr]--;
            }

            return answer;
        }
};

int main() {
    Solution s{};
    // abcdef
    // fedcba
    //
    // abcdefghijklmnopqrstuv
    // vutsrqponmlkjihgfedcba
    cout << s.makeStringSorted("cba") << "\n";
    return 0;
}
