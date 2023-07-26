#include <iostream>
#include <vector>

using namespace std;

/*

Time complexity: O(n)

r: points to next element to include
l: start point of current array/ 0 initially

1) Iterate with r over all elements
2) Add element at position r
    s += a[r]
3) While the current array is >= target, remove from left

*/
/*
class Solution {
    public:
        int minSubArrayLen(int target, vector<int>& nums) {
            const int n = nums.size();

            int r = 0;
            int l = 0;

            int s = 0;
            int m = n+1;

            while (r < n) {
                s += nums[r];
                
                // Current array is a[l], ..., a[r]
                // Length: r - l + 1
                while (l <= r && s >= target) {
                    m = min(m, r - l + 1);
                    s -= nums[l];
                    ++l;
                }

                r++;
            }

            return m == n+1 ? 0 : m;
        }        
};
*/

// Time complexity: O(nlog(n))
// Idea: Binary search on window size
class Solution {
    public:
        bool check(vector<int>& nums, int target, int wSize) {
            const int n = nums.size();

            int cSum = 0;
            for (int i = 0; i < wSize; ++i) {cSum += nums[i];}

            if (cSum >= target) return true;

            for (int i = wSize; i < n; ++i) {
                cSum += nums[i] - nums[i - wSize];
            
                if (cSum >= target) {
                    return true;
                }
            }

            return false;
        }

        int minSubArrayLen(int target, vector<int>& nums) {
            const int n = nums.size();


            int lo = 0;
            int hi = n+1;

            while (hi - lo > 1) {
                int m = lo + (hi - lo) / 2;

                if (!check(nums, target, m)) {lo = m;}
                else {hi = m;}
            }

            return hi == n+1 ? 0 : hi;
        }
};

int main() {

    vector<int> nums{2,3,1,2,4,3};

    Solution solution{};
    int r = solution.minSubArrayLen(9, nums);
    cout << r << "\n";

    return 0;
}
