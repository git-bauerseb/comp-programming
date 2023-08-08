#include <iostream>
#include <string>
#include <cstring>
using namespace std;

// aaab
// abaa
class Solution {
    public:
        int freq[26];

        string reorganizeString(string s) {
            const int n = s.size();
            memset(freq, 0, sizeof(freq));

            for (int i = 0; i < n; ++i) {
                int cur = s[i]-'a';
                freq[cur]++;
            }

            int prev = -1;
            for (int i = 0; i < n; ++i) {
                int curr = maxCurr(prev);
                
                if (curr == -1) {
                    return "";
                }
                s[i] = curr + 'a';
                freq[curr]--;
                prev = curr;
            }

            return s;
        }

        int maxCurr(int prev) {
            int mFreq = -1;
            int mIdx = -1;
            for (int i = 0; i < 26; ++i) {
                if (i != prev && freq[i] > mFreq && freq[i] > 0) {
                    mIdx = i;
                    mFreq = freq[i];
                }
            }

            return mIdx;
        }
};

int main() {

    // cabcabc

    Solution solution{};
    string r = solution.reorganizeString("vdjvevvvs");
    cout << r << "\n";

    return 0;
}
