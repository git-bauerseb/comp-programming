#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

using ll = long long;

class Solution {

    public:
        string encode(string longUrl) {
            m_tUrl[m_idx++] = longUrl;
            char buffer[256];
            snprintf(buffer, sizeof buffer,
                    "http://tinyurl.com/%lld", m_idx-1);
            string s(buffer);
            return s;
        }

        string decode(string shortUrl) {
            char delimiter = '/';
            vector<string> v = split(shortUrl, delimiter);
            ll idx = atol(v[v.size()-1].c_str());
            return m_tUrl[idx];
        }

        vector<string> split(const string& s, char delim) {
            vector<string> result;
            stringstream ss(s);
            string item;
            while (getline(ss, item, delim)) result.push_back(item);
            return result;
        }

    private:
        map<ll, string> m_tUrl;
        ll m_idx = 0xCAFFEE;
};

int main() {

    Solution solution{};
    
    string shortUrl = solution.encode("https://leetcode.com/problems/design-tinyurl");
    cout << shortUrl << "\n";

    string longUrl = solution.decode(shortUrl);
    cout << longUrl << "\n";

    return 0;
}
