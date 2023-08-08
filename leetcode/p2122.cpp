#include <iostream>
#include <vector>
#include <set>

#include <algorithm>

using namespace std;

// Time complexity: O(n^2)
class Solution {
    public:
        vector<int> recoverArray(vector<int>& nums) {
            const int n = nums.size();
            m_result.resize(n/2, 0);
            sort(nums.begin(), nums.end());

            int l = nums[0];

            for (int i = 1; i < n; ++i) {
                int u = nums[i];
                if ((u - l) % 2 != 0 || (u-l) <= 0) continue;

                int k = (u-l)/2;

                if (checkK(k, nums)) {
                    break;
                }
            }   

        
            return m_result;
        }

        bool checkK(int k, vector<int>& nums) {
            const int n = nums.size();
            
            multiset<int> lookup;

            int idx = 0;
            for (int i = 0; i < n; ++i) {
                int u = nums[i];

                // Assume u is upper
                // Then lower is u - 2*k
                auto itr = lookup.find(u-2*k);
                
                if (itr != lookup.end()) {
                    m_result[idx++] = u - k;
                    lookup.erase(itr);
                } else {
                    lookup.insert(u);
                }
            }

            return lookup.size() == 0;
        }

        vector<int> m_result;
};

int main() {

    vector<int> nums{2,10,6,4,8,12};

    Solution solution{};
    auto a = solution.recoverArray(nums);

    for (auto& e : a) cout << e << " ";
    cout << "\n";

    return 0;
}
