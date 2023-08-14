#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

class Solution {
public:

    int mPos;
    vector<vector<int>> memo;

    int minimumJumps(vector<int>& f, int a, int b, int x) {
        sort(f.begin(), f.end());
        mPos = max(f[f.size()-1], x) + a + b + 2;

        memo.resize(mPos, vector<int>(2,-1));

        int answer = rec(f, x, false, a, b);
        return answer >= 1e9 ? -1 : answer;
    }

    int rec(vector<int>& f, int pos, bool back, int a, int b) {
        if (pos < 0 || pos > (mPos-1) || binary_search(f.begin(), f.end(), pos)) {return INF;}

        int& entry = memo[pos][back?1:0];
        if (entry >= 0) return entry;

        if (pos == 0) {return 0;}
        entry = 1 + rec(f, pos - a, false, a, b);
        if (!back) {
            entry = min(entry, 1 + rec(f, pos + b, true, a, b));
        }

        return entry;
    }
};

int main() {

    // vector<int> forbidden{1,6,2,14,5,17,4};
    vector<int> f{128,178,147,165,63,11,150,20,158,144,136};

    Solution solution{};
    cout << solution.minimumJumps(f, 61, 170, 135) << "\n";

    return 0;
}
