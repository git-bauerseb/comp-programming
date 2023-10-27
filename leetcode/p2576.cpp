#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        const int n = nums.size();
        int rptr = n-1;
        int mid = n % 2 == 0 ? n/2 - 1 : n/2;
        int lptr = mid;
        int del = 0;
        
        while (rptr > mid && lptr >= 0) {
            if (nums[lptr]*2 <= nums[rptr]) {rptr--; lptr--; del+=2 ;}
            else {lptr--;}
        }

        return del;
    }
};
