#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <set>

using namespace std;

// Time complexity: O(n*m^2 * log(n))
//
// Where
//   n : number of words
//   m : max length of word
class Solution {
    public:
        vector<vector<int>> palindromePairs(vector<string>& words) {
            const int n = words.size();

            // Sort words by indices to keep track
            vector<int> indices(n);
            std::iota(indices.begin(), indices.end(), 0);
            sort(indices.begin(), indices.end(),
                    [&](const int a, const int b) {
                        return words[a] < words[b];
                    });

            vector<vector<int>> output;

            for (int i = 0; i < n; ++i) {
                string& curr = words[i];
                if (curr.empty()) continue;
                int len = curr.size();
                // Invariant: 0, ..., j-1 is palindrome prefix
                // AND look for reverse of string j, ..., len-1
                for (int j = 0; j <= len; ++j) {
                    // Inefficent
                    
                    // Check for palindrome of first j characters
                    if (isPalindrome(0,j-1, curr)) {
                        // Check if reverse of remaining string is in array
                        string revRem = curr.substr(j, len+1-j);
                        reverse(revRem.begin(), revRem.end());
                        auto it = lower_bound(indices.begin(), indices.end(), revRem,
                                [&](const int element, const string& value) {
                                return words[element] < value;
                        });

                        if (it != indices.end() 
                            && i != *it
                            && words[*it] == revRem) {
                            output.push_back({*it, i});
                        }
                    }

                    // Check for palindrome of last j characters
                    if (j < len && isPalindrome(len-1-j,len-1, curr)) {
                        string revRem = curr.substr(0, len-j-1);
                        reverse(revRem.begin(), revRem.end());
                        auto it = lower_bound(indices.begin(), indices.end(), revRem,
                                [&](const int element, const string& value) {
                            return words[element] < value;
                        });
                        if (it != indices.end()
                                && i != *it
                                && words[*it] == revRem) {
                            output.push_back({i, *it});
                        }
                    }
                }
            }

            return output;
        }


        bool isPalindrome(int i, int j, string& ref) {
            if (j < i) return true;
            while (i < j) {
                if (ref[i] != ref[j]) return false;
                i++;
                j--;
            }
            return true;
        }
};

int main() {

    vector<string> words{
    "ab","ba","abc","cba"
    };

    Solution solution{};
    auto r = solution.palindromePairs(words);
    for (auto& e : r) printf("(%d,%d)\n", e[0], e[1]);
    return 0;
}
