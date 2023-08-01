#include <iostream>
#include <string>

using namespace std;

class Solution {

    public:
        int diff[3];


        string longestDiverseString(int a, int b, int c) {
            string s;

            diff[0] = a;
            diff[1] = b;
            diff[2] = c;

            char prev = '\0';
            char pprev = '\0';
            while (true) {
                char next = getNext(prev, pprev);
                
                if (next == '\0') {
                    return s;
                }
                diff[next-'a']--;
                s += next;
                pprev = prev;
                prev = next;
            }
        }

        char getNext(char prev, char pprev) {
            char n = '\0';
            int fFreq = -1;
            for (int i = 0; i < 3; ++i) {
                char c = i + 'a';
                if (diff[i] > fFreq && diff[i] > 0
                        && !(c == prev && c == pprev)) {
                    n = i + 'a';
                    fFreq = diff[i];
                }
            }
            return n;
        }
};

int main() {
    Solution solution{};
    string s = solution.longestDiverseString(7,7,7);
    cout << s << "\n";

    return 0;
}
