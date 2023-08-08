#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
class Solution {

    public:

        // dp[mask] := Number of ways 
        vector<int> m_dp;

        int countArrangement(int n) {
            int bs = 0;
            m_dp.resize(1 << (n+1));
            return rec(0, bs, n);
        }

        // 0101 0110
        // bs := Which numbers are taken
        int rec(int idx, int bs, int n) {
            if (idx >= n) {
                return 1;
            }

            int& entry = m_dp[bs];
            if (entry != 0) {
                return entry;
            }

            int answer = 0;

            for (int i = 1; i <= n; ++i) {
                if (!(bs & (1 << i)) && (i % (idx+1) == 0 || (idx+1) % i == 0)) {
                    bs |= 1 << i;
                    answer += rec(idx+1, bs, n);
                    bs &= ~(1 << i);
                }
            }

            entry = answer;
            return answer;
        }
};

int main() {

    Solution solution{};
    int a = solution.countArrangement(15);
    cout << a << "\n";

    return 0;
}
