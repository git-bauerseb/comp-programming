#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
        int minimumDifference(vector<int>& nums) {
            const int n = nums.size();

            vector<vector<int>> first(n/2 + 1);
            vector<vector<int>> second(n/2 + 1);

            int tSum = 0;

            for (int i = 0; i < n; ++i) {
                tSum += nums[i];
            }

            for (int i = 0; i < (1 << (n/2)); ++i) {

                int fSum = 0;
                int sSum = 0;
                int idx = 0;
                int bitsSet = 0;

                while ((1 << idx) <= i) {
                    if ((1 << idx) & i) {
                        fSum += nums[idx];
                        sSum += nums[(n/2) + idx];
                        bitsSet++;
                    }
                    idx++;
                }

                first[bitsSet].push_back(fSum);
                second[bitsSet].push_back(sSum);
            }
        
            for (int i = 0; i <= n/2; ++i) {
                sort(second[i].begin(), second[i].end());
            }


            int mDiff = 1 << 28;

            for (int i = 0; i <= n/2; ++i) {
                for (auto& number : first[i]) {

                    int ss = number;
                    int rem = n/2 - i;
                    auto it = lower_bound(second[rem].begin(), second[rem].end(),
                                            tSum/2 - number);
                
                    if (it < second[rem].end()) {
                        ss += *(it);
                    } else {
                        ss += *(--it);
                    }

                    mDiff = min(abs(2*ss - tSum), mDiff);
                }
            }

            return mDiff;
        }
};

int main() {
    vector<int> nums{76,8,45,20,74,84,28,1};
    Solution solution{};
    int d = solution.minimumDifference(nums);
    cout << d << "\n";

    return 0;
}
