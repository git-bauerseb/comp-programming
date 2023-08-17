#include <iostream>

#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

class Solution {
    public:
        vector<int> output;

        vector<int> findSubstring(string s, vector<string>& words) {
            const int n = s.size();
            const int m = words.size();
            const int l = words[0].size();
            sort(words.begin(), words.end());
            
            // Map word to how often it occurs
            map<string,int> occ;
            for (auto& e : words) {
                occ[e]++;
            }

            if (n < m*l) {
                return {};
            }

            map<string,int> dupOcc;
            for (int start = 0; start < l; ++start) {
                findOffset(s, words, occ, dupOcc, start);
                dupOcc.clear();
            }

            return output;
        }

        void findOffset(string& s, vector<string>& words,
                map<string,int>& occ, map<string,int>& dupOcc, int start) {
            const int n = s.size();
            const int m = words.size();
            const int l = words[0].size();
            
            int lPtr = start;
            int rPtr = start;

            set<string> mis;

            // Initialize window
            int wSize = 0;
            int wordOcc = 0;

            // Number of words that occur but have mismatch
            int occMismatch = 0;

            while (rPtr < m*l) {
                string curr = s.substr(rPtr, l);
                if (binary_search(words.begin(), words.end(), curr)) {
                    dupOcc[curr]++;
                    wordOcc++;
                    if (dupOcc[curr] != occ[curr]) {
                        mis.insert(curr);
                    } else {
                        mis.erase(curr);
                    }
                }
                rPtr += l;
            }

            if (wordOcc == m && mis.size() == 0) {
                output.push_back(lPtr);
            }

            // Main loop: Sliding window
            while (rPtr <= n - l) {
                // Move lPtr one to the left
                string first = s.substr(lPtr, l);
                if (binary_search(words.begin(), words.end(), first)) {
                    dupOcc[first]--;
                    wordOcc--;

                    if (dupOcc[first] == occ[first]) {mis.erase(first);}
                    else {mis.insert(first);}
                }
                lPtr += l;

                // Move rPtr one to the right
                string toAdd = s.substr(rPtr, l);
                if (binary_search(words.begin(), words.end(), toAdd)) {
                    wordOcc++;
                    dupOcc[toAdd]++;
                    if (dupOcc[toAdd] == occ[toAdd]) {mis.erase(toAdd);}
                    else {mis.insert(toAdd);}
                }
                rPtr += l;

                if (wordOcc == m && mis.size() == 0) {
                    output.push_back(lPtr);
                }
            }
        }
};

int main() {
    vector<string> words{"a", "b"};
    Solution solution{};
    auto r = solution.findSubstring("aaa", words);

    for (auto& e : r) cout << e << " ";
    cout << "\n";

    return 0;
}
