#include <iostream>
#include <string>

using namespace std;

class Solution {

    public:
        int appendCharacters(string s, string t) {
            const int n = s.size();

            int matched = -1;

            for (int i = 0; i < n; ++i) {
                if (matched+1 < t.size() && s[i] == t[matched+1]) {
                    matched++;
                }
            }
            return t.size() - (matched + 1);
        }
};

int main() {

    Solution solution{};
    int r = solution.appendCharacters("codeforces", "coderf");
    cout << r << "\n";

    return 0;
}
