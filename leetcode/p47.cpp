#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool o_next_permutation(vector<int>& nums) {
    const int n = nums.size();

    // Find longest decreasing subsequence from back
    int idx = n-1;
    int len = 1;
    while (idx > 0 &&
        nums[idx-1] >= nums[idx]) {len++; idx--;}

    // Check if there is no next permutation
    // This is the case if all elements are decreasing
    // 5,4,3,2,1
    if (idx == 0) return false;

    // Invariant: idx+1, idx+2, ..., n-1 contains LDS


    // Reverse longest decreasing subsequence
    // len = 2
    // n-2, n-1
    // idx = n-2
    for (int i = 0; i < len/2; ++i) {
        swap(nums[idx+i], nums[n-i-1]);
    }

    // Search for largest element in LDS that is larger than previous element
    int prev = nums[idx-1];

    int mLarger = 10000;
    int mLIdx = -1;
    for (int i = 0; i < len; ++i) {
        if (nums[idx+i] > prev && nums[idx+i] < mLarger) {
            mLarger = nums[i+idx];
            mLIdx = i+idx;
        }
    }

    swap(nums[idx-1], nums[mLIdx]);
    
    return true;
}

class Solution {
    public:
        vector<vector<int>> permuteUnique(vector<int>& nums) {
            const int n = nums.size();
            vector<vector<int>> perms;
            sort(nums.begin(), nums.end());
            do {
                
                vector<int> p(n);
                copy(nums.begin(), nums.end(), p.begin());
                perms.push_back(p);

            } while (o_next_permutation(nums));

            return perms;
        }
};

int main() {

    // Next permutation: 3,2,5,1,4
    vector<int> permutation{1,1,2,2};

    do {
        for (auto& e : permutation) cout << e << " ";
        cout << "\n";
    } while (o_next_permutation(permutation));

    return 0;
}
