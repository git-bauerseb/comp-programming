#include <vector>
#include <queue>
#include <algorithm>

#include <iostream>

using namespace std;

// Unnecessary complicated solution
// O(nlog(n))
/*
class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        const int n = nums.size();

        priority_queue<int, vector<int>, std::less<int>> pq_min;
        priority_queue<int,vector<int>, std::less<int>> pq_max;

        for (auto e : nums) pq_min.push(e);

        // Push <= half elements to queue
        for (int i = 0; i < n/2; ++i) {
            pq_max.push(pq_min.top());
            pq_min.pop();
        }

        int del = 0;

        while (!pq_max.empty() && !pq_min.empty()) {

            int la = pq_max.top();
            int sm = pq_min.top();

            if (la == sm) pq_min.pop();
            else {
                pq_max.pop();
                pq_min.pop();
                del += 2;
            }
        }


        return n - del;
    }
};
*/

/*
// Time complexity: O(n)
class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        const int n = nums.size();
        int rptr = n-1;
        int mid = n % 2 == 0 ? n/2 - 1 : n/2;
        int lptr = mid;

        int del = 0;

        while (lptr >= 0 && rptr > mid) {
            int larg = nums[rptr];
            int smal = nums[lptr];

            if (larg == smal) {
                lptr--;
            } else {
                del += 2;
                lptr--;
                rptr--;
            }
        }
        return n - del;
    }
};
*/

class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        const int n = nums.size();
               
        // If element occurs > half times the size of the array,
        // it has to be present on mid index.
        int mEl = nums[n/2];
        int l = (int)(lower_bound(nums.begin(), nums.begin() + n/2 + 1, mEl)
                        - nums.begin());
        int r = (int)(lower_bound(nums.begin() + n/2, nums.end(), mEl + 1) 
                        - (nums.begin()));
        int occ = (r-1)-l+1;
        return max(n % 2, 2*occ-n);
    }
};


int main() {
    vector<int> nums{1,4,4,4,4,4,4};

    Solution s{};
    cout << s.minLengthAfterRemovals(nums) << "\n";
    return 0;
}
