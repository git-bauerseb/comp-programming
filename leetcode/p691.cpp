#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <bitset>
#include <cstring>

using namespace std;
const int INF = 1'000'000'007;

class Solution {

    int dp[762][21];

    public:
        int minStickers(vector<string>& stickers, string target) {
            const int n = stickers.size();
            const int m = target.size();
            std::fill(&dp[0][0], &dp[761][20], -1);
            vector<string> unique;

            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    unique.push_back(stickers[i]);
                }
            }

            bitset<16> missing;
            for (int i = 0; i < m; ++i) {
                missing[i] = 1;
            }
            int s = rec(unique, target, missing, 0, target.size(), 0);
            return s == INF ? -1 : s;
        }

        int rec(vector<string>& unique, string& target, bitset<16> missing,
                int used, int rem, int idx) {
            if (idx >= unique.size()) {return INF;}
            if (rem < 1) {return used;}

            int& entry = dp[idx][rem];
            if (entry != -1) {return entry;}


            int minS = rec(unique, target, missing, used, rem, idx + 1);
            bool contributes = false;

            for (auto& c : unique[idx]) {
                for (int i = 0; i < target.size(); ++i) {
                    if (missing[i] == 1 && target[i] == c) {
                        missing[i] = 0;
                        contributes = true;
                        rem--;
                        break;
                    }
                }
            }

            minS = min(minS, rec(unique, target, missing, used + 1, rem, idx + 1));
            entry = minS;
            return minS;
        }
};

int main() {
    // gasproper
    
    // spring => sprg
    // island => as
    // problem => 
    
    vector<string> v{"island", "keep", "spring", "problem", "subject"};

    Solution solution{};
    int m = solution.minStickers(v, "gasproper");
    cout << m << "\n";

    return 0;
}
