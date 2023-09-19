#include <vector>
#include <string>
#include <algorithm>
#include <utility>

#include <iostream>

using namespace std;

//                         a
//             a|b                     b|a
//    (a|b)|c     c|(a|b)      c|(b|a)      (b|a)|c
// 
//
// => DP
// State 
// dp[i][s][e] := Minimum length of string when concatenating first i words
//                and starting with char 's', ending with char 'e'
//
//
// dp[0][s[0]][s[0]] = len(s[0])
//
// Let st = starting char of s[i]
//     en = ending char of s[i]
// dp[i][st][c] = min len when concatenating current word on left side
//              = min_{j} (len(s[i]) + dp[i-1][j][c] - 1 iff j == en)
// dp[i][c][en] = min_{j} (len(s[i]) + dp[i-1][c][j] - 1 iff j == st)

const int MLEN = 1000;

int dp[MLEN][26][26];
const int INF = 1'000'000'000;

class Solution {
public:
    int minimizeConcatenatedLength(vector<string>& words) {
        const int n = words.size();
        fill(&dp[0][0][0], &dp[MLEN-1][25][25], INF);
    
        // Base case
        int s = words[0][0] - 'a';
        int e = words[0][words[0].size()-1] - 'a';
        dp[0][s][e] = words[0].size();

        for (int i = 1; i < n; ++i) {
            int len = words[i].size();

            s = words[i][0] - 'a';
            e = words[i][len-1] - 'a';

            for (int c = 0; c < 26; ++c) {
                for (int j = 0; j < 26; ++j) {

                    // Concatenate current word on left
                    dp[i][s][c] = min(dp[i][s][c],
                                    len + dp[i-1][j][c] - (e == j ? 1 : 0));

                    // Concatenate current word on right
                    dp[i][c][e] = min(dp[i][c][e],
                                    len + dp[i-1][c][j] - (s == j ? 1 : 0));
                }
            }
        }


        int answer = INF;

        // Answer
        for (int s = 0; s < 26; ++s) {
            for (int e = 0; e < 26; ++e) {
                answer = min(answer, dp[n-1][s][e]);
            }
        }

        return answer;
    }
};

int main() {
    vector<string> ws = {
        "aaa", "c", "aba"
    };

    Solution s{};
    cout << s.minimizeConcatenatedLength(ws) << "\n";

    return 0;
}
