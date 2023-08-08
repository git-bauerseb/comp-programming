#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


// Greedy
//
// Strategy: Sort arrays according to start, then finish time
// - If two jobs overlap, remove job with latest finish time
//
// Proof:
//  i) feasibility: No overlapping intervals are selected
//  ii) Optimiality:
//
//  S = {I_{a1}, ..., I_{ak}} intervals selected in greedy algorithm
//  S* = {I_{b1}, ..., I_{bm}} intervals selected in optimal algorithm
//
//  I_{br} >= I_{ar} for all 1 <= r <= k
//
//  r = 1 => 
//
class Solution {

    public:
        int eraseOverlapIntervals(vector<vector<int>>& intervals) {
            const int n = intervals.size();
            sort(intervals.begin(), intervals.end(),
                    [&](const vector<int>& a, const vector<int>& b) {
                        if (a[0] != b[0]) return a[0] < b[0];
                        return a[1] < b[1];
                    });

            
            int rem = 0;
            int ptr = 0;

            for (int i = 1; i < n; ++i) {
                if (intervals[i][0] < intervals[ptr][1]) {
                    if (intervals[i][1] < intervals[ptr][1]) {
                        ptr = i;
                    }
                    rem++;
                } else {
                    ptr = i;
                }
            }

            return rem;
        }
};

int main() {

    vector<vector<int>> i = {
        {1,2},
        {2,3},
        {3,4},
        {1,3},
        {2,3},
        {3,6},
        {1,7}
    };

    Solution solution{};
    int r = solution.eraseOverlapIntervals(i);
    cout << r << "\n";

    return 0;
}
