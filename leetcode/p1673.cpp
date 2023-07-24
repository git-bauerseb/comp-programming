#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
    public:
        vector<int> mostCompetitive(vector<int>& nums, int k) {
            const int n = nums.size();

            // Increasing monotonic stack
            vector<int> ms;

            for (int i = 0; i < n; ++i) {

                while (ms.size() > 0 && ms[ms.size()-1] > nums[i]
                        && ms.size() + (n - i - 1) >= k) {
                    ms.pop_back();
                }

                ms.push_back(nums[i]);
            }

            return vector<int>(ms.begin(), ms.begin()+k);
        }
};

int main() {

    vector<int> nums{2,9,7,2,8,2,1,2,1};

    Solution solution{};
    auto r = solution.mostCompetitive(nums, 5);

    for (auto& e : r) cout << e << " ";
    cout << "\n";

    return 0;
}
