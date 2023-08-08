/*
    Obs:
     - Start at arbitary point
     - Move to the right and pick fruits
     - If no fruit can fit, stop

    1212121212
    1111111222
    2222111111
    1212 3 111

    Idea (Greedy):
      - Start at left position
      - pick fruit
        - store two types: prev (= fruit previously picked, curr (= fruit currently picked)
        - if encounter other fruit type, then reset local counter
        - set global counter to maximum
*/
#include <vector>
#include <iostream>

using namespace std;

class Solution {

    public:
        int totalFruit(vector<int>& nums) {
            const int n = nums.size();

            if (n == 1) return 1;

            int prev = nums[0];
            int curr = (nums[1] == nums[0] ? -1 : nums[1]);
            
            int nPrev = 1 + (curr == -1 ? 1 : 0);
            int nCurr = curr == -1 ? 0 : 1;
            
            int tMax = 2;

            // 1 2 3 2 2
            //

            for (int i = 2; i < n; ++i) {
                if (nums[i] == prev) {
                    nPrev++;
                    tMax = max(nPrev + nCurr, tMax);
                } else if (nums[i] == curr || curr == -1) {
                    nCurr++;
                    curr = nums[i]; 
                    tMax = max(nPrev + nCurr, tMax);
                } else {
                    if (nums[i-1] == curr) {
                        nPrev = nCurr;
                        nCurr = 1;
                        prev = curr;
                    } else {
                        nCurr = 1;
                    }
                    
                    curr = nums[i];
                }
            }

            return tMax;
        }
};

int main() {
    vector<int> nums {1,0,1,4,1,4,1,2,3};
    Solution solution{};
    int t = solution.totalFruit(nums);
    cout << t << "\n";
    return 0;
}
