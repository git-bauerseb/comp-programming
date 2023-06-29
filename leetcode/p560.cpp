#include <iostream>
#include <vector>
#include <map>

using namespace std;

// Simplest solution
// Time complexity: O(n^2)
// Space complexity: O(n)
//
// Idea
//   - Compute prefix sum
//   - For each pair, check if sum == k
//     - increment counter
//
//
// HERE (NOW): Improved solution
// Time complexity: O(nlog(n)) (if using std::map)
// Space compleixty: O(n)
//
// Idea
//   - Compute prefix sum
//   - We want to count all index pairs (i,j) s.t. j <= i and s[i] - s[j-1] = k
//   - Store prefix in hashmap
//   - For current prefix s[l], query map how many prefixes are there (s[o]) s.t. 
//              s[l] - s[o] = k
//          <=> s[o] = s[l] - k
class Solution {

    public:
        int subarraySum(vector<int>& nums, int k) {
            const int n = nums.size();
            vector<int> prefix(n, 0);
            prefix[0] = nums[0];
            for (int i = 1; i < n; ++i) {prefix[i] = prefix[i-1] + nums[i];}

            // Count how often prefix occurs during traversing
            map<int,int> pCount;

            // Empty prefix has a sum of 0
            pCount[0]++;

            int count = 0;
            for (int i = 0; i < n; ++i) {
                int l = prefix[i] - k;
                if (pCount.count(l) > 0) count += pCount[l];
                pCount[prefix[i]]++;
            }
            
            return count;
        }
};

int main() {
    vector<int> nums{1,1,1};

    Solution solution{};
    int c = solution.subarraySum(nums, 4);
    cout << c << "\n";

    return 0;
}
