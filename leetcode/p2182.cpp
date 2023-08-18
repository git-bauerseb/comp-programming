#include <iostream>
#include <string>

#include <cstring>

using namespace std;

int occ[26];

class Solution {
public:


    string repeatLimitedString(string s, int repeatLimit) {
        const int n = s.size();
        memset(occ, 0, sizeof(occ));

        for (auto& c : s) {
            occ[c - 'a']++;
        }

        string output;
        int same = 0;        
        char p;

        for (int i = 0; i < n; ++i) {
            char next;

            if (same == repeatLimit) {
                next = getNext(output[output.size()-1]);
                same = 1;
            } else {
                next = getNext('\0');
                
                if (next != p) {
                    same = 1;
                } else {
                    same++;
                }
            }

            if (next != '\0') {
                p = next;
                output += next;
            }
        }

        return output;
    }

    char getNext(char p) {
        for (int i = 25; i >= 0; --i) {
            if (occ[i] > 0 && (i+'a') != p) {
                occ[i]--;
                return i+'a';
            }
        }

        return '\0';
    }
};

int main() {

    Solution solution{};
    string o = solution.repeatLimitedString("aababab", 2);
    cout << o.size() << "\n";

    return 0;
}
