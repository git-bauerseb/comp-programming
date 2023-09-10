#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
    int findSubstringInWraproundString(string s) {
        const int n = s.size();
        map<char, int> dp;
        for (char c = 'a'; c <= 'z'; ++c) dp[c] = 0;

        int answer = 1;
        int cLength = 1;
        dp[s[0]] = 1;
        char prev = s[0];

        for (int i = 1; i < n; ++i) {
            char next = prev + 1;
            if (next > 'z') next = 'a';

            if (s[i] == next) {
                cLength++;

                if (dp[s[i]] < cLength) {
                    answer += cLength - dp[s[i]];
                    dp[s[i]] = cLength;
                }
            } else {
                cLength = 1;
                if (dp[s[i]] < cLength) {
                    answer += cLength - dp[s[i]];
                    dp[s[i]] = cLength;
                }
            }

            prev = s[i];
        }

        return answer;
    }
};

int main() {
    Solution s{};
    cout << s.findSubstringInWraproundString("abczabcuyzabc") << "\n";
    return 0;
}
