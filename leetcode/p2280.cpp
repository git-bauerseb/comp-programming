#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1'000'000'007;

vector<int> MODS = {
    1'000'000'007,
      805'306'457
};

class Solution {
public:

    long long binexp(long long base, long long exp, long long mod) {
        long long r = 1;
        while (exp > 0) {
            if (exp & 1) {
                r = r * base;
                r %= mod;
            }

            base = base * base;
            base %= mod;
            exp >>= 1;
        }
        return r;
    }

    int minimumLines(vector<vector<int>>& stockPrices) {
        const int n = stockPrices.size();
        if (n <= 1) { return 0; }
        sort(stockPrices.begin(), stockPrices.end());

        vector<long long> ms(MODS.size());
        vector<long long> bs(MODS.size());


        long long pX = stockPrices[0][0];
        long long pY = stockPrices[0][1];

        // Current point -> Second point
        long long cX = stockPrices[1][0];
        long long cY = stockPrices[1][1];

        long long u,d;

        for (int i = 0; i < MODS.size(); ++i) {
            long long& m = ms[i];
            long long& b = bs[i];

            u = (cY - pY + MODS[i]) % MODS[i];
            d = (cX - pX + MODS[i]) % MODS[i];
            d = binexp(d, MODS[i]-2, MODS[i]);

            m = (u * d) % MODS[i];
            b = (cY - ((m*cX) % MODS[i]) + MODS[i]) % MODS[i];

        }

        int answer = 1;

        for (int i = 2; i < n; ++i) {
            
            long long nX = stockPrices[i][0];
            long long nY = stockPrices[i][1];

            bool onLine = true;

            // Check if new point is on line
            for (int i = 0; i < MODS.size(); ++i) {
                long long m = ms[i];
                long long b = bs[i];
                onLine = onLine && (((m*nX % MODS[i]) + b) % MODS[i]) == (nY % MODS[i]);
            }

            pX = cX;
            pY = cY;
            cX = nX;
            cY = nY;

            if (!onLine) {
                answer++;
                for (int i = 0; i < MODS.size(); ++i) {
                    long long& m = ms[i];
                    long long& b = bs[i];

                    u = (cY - pY + MODS[i]) % MODS[i];
                    d = (cX - pX + MODS[i]) % MODS[i];
                    d = binexp(d, MODS[i]-2, MODS[i]);
                    m = (u * d) % MODS[i];
                    b = (cY - ((m*cX) % MODS[i]) + MODS[i]) % MODS[i];
                }
            }
        }

        return answer;
    }
};

int main() {
    vector<vector<int>> pts = {
        {3,4}, {1,2}, {7,8}, {2,3}
    };

    Solution s{};
    cout << s.minimumLines(pts) << "\n";
    return 0;
}
