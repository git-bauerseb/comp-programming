#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {

    public:
        int subarraysWithKDistinct(vector<int>& nums, int k) {
            const int n = nums.size();
            int r = 0;

            while (r < n) {
                

            }
        }
};

int main() {
    vector<int> nums{1,2,1,2,3};
    Solution solution{};
    int d = solution.subarraysWithKDistinct(nums, 2);
    cout << d << "\n";
    return 0;
}
