#include <iostream>
#include <string>

using namespace std;

class Solution {
    public:
        int secondsToRemoveOccurrences(string s) {
            const int n = s.size();

            bool found = true;
            int sim = 0;

            string sw;
            sw.resize(n);

            while (found) {
                found = false;
                for (int i = 0; i < n; ++i) {
                    if (s[i] == '0' && s[i+1] == '1') {
                        sw[i] = '1';
                        sw[i+1] = '0';
                        found = true;
                        ++i;
                    } else {
                        sw[i] = s[i];
                    }
                }

                cout << sw << "\n";

                if (found) {sim++;}
                swap(s,sw);
            }

            return max(0,sim);
        }
};

// 110101010
// 111010101
// 111101010
// 111110101
// 111111010
// 111111101
// 111111110
// 111111111


// 101011001
//
// 110101010
// 111010100
// 111101000
// 111110000
int main() {
    Solution solution{};
    cout << solution.secondsToRemoveOccurrences("101011001") << "\n";
    return 0;
}
