#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {

    map<int, vector<string>> m_dp;

    public:
        vector<string> wordBreak(string s, vector<string>& wordDict) {
            sort(wordDict.begin(), wordDict.end());
            const int n = s.size();
        
            return rec(s, wordDict, n-1);
        }

        vector<string> rec(string& s, vector<string>& dict, int end) {
            if (end < 0) {return {};}

            if (m_dp.count(end) > 0) {return m_dp[end];}

            vector<string> result;

            string sub = s.substr(0, end+1);
            if (binary_search(dict.begin(), dict.end(), sub)) {
                result.push_back(sub);
            }
            
            for (int i = end; i >= 0; --i) {
                string cur = s.substr(i, end - i + 1);

                if (binary_search(dict.begin(), dict.end(), cur)) {
                    vector<string> splits = rec(s, dict, i-1);
                    for (auto& e : splits) {
                        result.push_back(e + " " + cur);
                    }
                }
            }

            m_dp[end] = result;
            return result;
        }
};

/*
    "pine apple pen apple"
    "pineapple pen apple"
    "pine applepen apple"

    pineapple pen apple
    pine applepen apple
*/
int main() {

    vector<string> dict {"apple","pen","applepen","pine","pineapple"};

    Solution solution{};
    auto r = solution.wordBreak("pineapplepenapple", dict);

    for (auto& e : r) cout << e << "\n";

    return 0;
}
