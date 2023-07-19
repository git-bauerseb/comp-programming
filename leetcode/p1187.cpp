#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int LIM = 1'000'000;

// Top-Down DP
class Solution {
    public:
        // map<pair<int,int>,int> memo;
        vector<vector<int>> memo;

        int makeArrayIncreasing(vector<int>& a, vector<int>& a2) {
            sort(a2.begin(), a2.end());
            vector<int> b;
            b.push_back(a2[0]);
            for (int i = 1; i < a2.size(); ++i) {
                if (a2[i] == b[b.size()-1]) {continue;}
                b.push_back(a2[i]);
            }


            memo.resize(a.size(), vector<int>(b.size()+2,-1));

            int result = dp(a,b, 0, -1);
            return result >= LIM ? -1 : result;
        }

        int dp(vector<int>& a, vector<int>& b, int i, int previous) {
            if (i >= a.size()) {return 0;}

            if (memo[i][previous+1] >= 0) {
                return memo[i][previous+1];
            }

            int mOP = LIM;

            int pVal = -1;
            if (previous >= 0) 
                pVal = (previous == b.size()) ? a[i-1] : b[previous];

            if (previous == -1 || a[i] > pVal) {
                mOP = dp(a, b, i+1, b.size());
            }


            int idx = (int)(upper_bound(b.begin(), b.end(), pVal) - b.begin());

            if (idx < b.size()) { mOP = min(mOP, 1 + dp(a, b, i + 1, idx)); }
            if (previous >= 0) { memo[i][previous+1] = mOP; }

            return mOP;
        }
};

int main() {

    vector<int> a{1,5,3,6,7};
    vector<int> b{4,3,1};

    Solution solution{};
    int num = solution.makeArrayIncreasing(a,b);
    cout << num << "\n";

    return 0;
}
