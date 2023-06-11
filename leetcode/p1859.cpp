#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <ctype.h>

using namespace std;

class Solution {
public:
    string sortSentence(string s) {
        vector<string> substr = split(s, " ");
        int num = substr.size();
        vector<string> result(num);

        for (string& sub : substr) {
            // Parse suffix number
            int pos = sub.size()-1;
            while (pos >= 0 && isdigit(sub[pos])) {pos--;}
            int idx = atoi(sub.substr(pos+1, sub.size()-pos).c_str());
            cout << idx;
            result[idx] = sub.substr(0, pos);
        }

        string f_res;
        // Concat
        for (int i = 0; i < result.size(); ++i) f_res += result[i];
        return f_res;
    }

    std::vector<std::string> split(const std::string str,
                               const std::string regex_str) {
    std::regex regexz(regex_str);
    return {std::sregex_token_iterator(str.begin(), str.end(), regexz, -1),
            std::sregex_token_iterator()};
    }
};

int main() {

    Solution solution{};
    string s = solution.sortSentence("is2 stence4 This1 a3");
    cout << s << "\n";

    return 0;
}
