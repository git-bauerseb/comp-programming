#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Solution {
    public:
        string removeDuplicateLetters(string s) {
            const int n = s.size();

            int occ[26];
            bool used[26];

            memset(occ, 0, sizeof(occ));

            for (int i = 0; i < 26; ++i) {used[i] = false;}

            for (int i = 0; i < n; ++i) {
                occ[s[i] - 'a']++;
            }

            string r;

            for (int i = 0; i < n; ++i) {
                char c = s[i];

                while (r.size() > 0 && r[r.size()-1] > c
                        && occ[r[r.size()-1]-'a'] > 0 && !used[c-'a']) {
                    used[r[r.size()-1]-'a'] = false;
                    r.pop_back();
                }


                if (!used[c-'a']) {
                    r += c;
                    used[c-'a'] = true;
                }

                occ[c-'a']--;
            }


            string re;

            for (int i = 0; i < 26; ++i) used[i] = false;

            for (int i = 0; i < r.size(); ++i) {
                if (!used[r[i]-'a']) {
                    re += r[i];
                    used[r[i]-'a'] = true;
                }
            }

            return re;
        }
};

// cbacdcbc
//
// c
// b
// a
// ac

int main() {


    Solution solution{};
    string r = solution.removeDuplicateLetters("abasdfkjsadvksadgjhgsaksadgcdedacbdacba");
    cout << r << "\n";

    return 0;
}
