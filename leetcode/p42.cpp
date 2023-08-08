#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int trap(vector<int>& height) {
            const int n = height.size();
            vector<int> mLeft(n,0);
            vector<int> mRight(n,0);


            mLeft[0] = height[0];
            mRight[n-1] = height[n-1];

            for (int i = 1; i < n; ++i) {
                mLeft[i] = max(mLeft[i-1], height[i]);
                mRight[n-1-i] = max(mRight[n-i], height[n-1-i]);
            }

            int amount = 0;
            for (int i = 1; i < n-1; ++i) {
                amount += max(0, min(mLeft[i-1], mRight[i+1]) - height[i]);
            }
            return amount;
        }
};
