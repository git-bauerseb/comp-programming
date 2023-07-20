#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;


// Time complexity: O(m + n*log(max(n,m)))
class Solution {

    int occ[26*2];
    int currOcc[26*2];

    public:

        bool containsChars() {
            for (int i = 0; i < 26*2; ++i) {
                if (currOcc[i] < occ[i]) return false;
            }
            return true;
        }
        
        pair<bool, int> check(string& s, int winSize) {
            memset(currOcc, 0, sizeof(currOcc));

            const int n = s.size();

            int l = 0;
            int r = winSize;

            for (int i = 0; i < winSize; ++i) {
                int pos = s[i] >= 'a' ? s[i] - 'a' + 26 : s[i] - 'A';
                currOcc[pos]++;
            }

            if (containsChars()) {return {true, 0};}

            while (r < n) {
                int nPos = s[r] >= 'a' ? s[r] - 'a' + 26 : s[r] - 'A';
                int oPos = s[l] >= 'a' ? s[l] - 'a' + 26 : s[l] - 'A';

                currOcc[nPos]++;
                currOcc[oPos]--;

                if (containsChars()) {
                    return {true, l+1};
                }

                r++;
                l++;
            }

            return {false, -1};
        }


        string minWindow(string s, string t) {

            if (s.size() < t.size()) {return string("");}

            memset(occ, 0, sizeof(occ));
            for (char& c : t) {
                int pos = c >= 'a' ? (c - 'a') + 26 : c - 'A';
                occ[pos]++;
            }


            // Do binary search on window size
            int lo = t.size()-1;
            int hi = s.size()+1;

            int pos = -1;

            while (hi - lo > 1) {

                int m = lo + (hi - lo) / 2;

                auto q = check(s,m);

                if (q.first) {pos = q.second; hi = m;}
                else {lo = m;}

            }

            if (pos < 0) {return string("");}
            return s.substr(pos, hi);
        }
};

int main() {

    Solution solution{};
    string r = solution.minWindow("ABCGHADAUSJEF", "BJ");

    cout << r << "\n";

    return 0;
}
