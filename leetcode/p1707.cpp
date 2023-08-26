#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


// Main idea:
//
// Do binary search on element that most similar to complement of number.
// Most similar is measured from most significant bit to least significant.
class Solution {
public:

    // Return index of last element that has zero bit in position pos.
    int findZeroSet(vector<int>& nums, int lo, int hi, int pos) {
        
        // [-1, lo] : all bits have a zero at pos 
        // [hi, n] : all bits have a one at pos
        while (hi - lo > 1) {
            int m = lo + (hi - lo) / 2;

            bool isZero = ((nums[m]) & (1 << pos)) == 0;

            if (isZero) {
                lo = m;
            } else {
                hi = m;
            }
        }

        // lo := last index where 0 bit is set
        return lo;
    }

    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        const int n = nums.size();
        const int q = queries.size();
        sort(nums.begin(), nums.end());
        auto last = unique(nums.begin(), nums.end());
        nums.erase(last, nums.end());

        vector<int> answer(q);
        for (int i = 0; i < q; ++i) {
            int el = queries[i][0];
            int lim = queries[i][1];

            // first index of element > value
            // <=> from 0 to idx-1 is <= value => this is valid range
            int idx = (int)(upper_bound(nums.begin(), nums.end(), lim) - nums.begin());

            // No element is <= lim
            if (idx == 0) {
                answer[i] = -1;
                continue;
            }

            int msb = 31;
            int lo = -1;
            int hi = idx;
            int comp = ~el;
            while (msb >= 0) {
                int v = findZeroSet(nums, lo, hi, msb);
                if (v == lo || v == hi-1) {
                    msb--;
                    continue;
                }

                bool cIsZero = (comp & (1 << msb)) == 0;
                if (cIsZero) {
                    hi = v+1;
                } else {
                    lo = v;
                }

                msb--;
            }

            int ans = 0;
            for (int j = lo; j <= min(idx-1, lo+2); ++j) {
                if (j >= 0 && j < n) {
                    ans = max(ans, nums[j] ^ el);
                }
            }

            answer[i] = ans;
        }

        return answer;
    }
};

int main() {
    vector<int> nums{0,142254206,330218644,534710168,536870912};
    
    vector<vector<int>> queries = {
        {214004,404207941}
    };

    Solution s{};
    auto ans = s.maximizeXor(nums, queries);
    
    for (auto& e : ans) cout << e << " ";
    cout << "\n";
    
    return 0;
}
