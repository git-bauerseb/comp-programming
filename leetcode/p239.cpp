#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct CComparator {
    bool operator() (const pair<int,int>& a, const pair<int,int>& b) {
        return a.first < b.first;
    }
};

// Time complexity: O(nlog(n))
//  => not optimal
class Solution {

    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            const int n = nums.size();
            priority_queue<pair<int,int>, vector<pair<int,int>>, CComparator> pq;
            for (int i = 0; i < k; ++i) {
                pq.push({nums[i],i});
            }

            int l = 0;
            int r = k-1;

            vector<int> m;
            m.push_back(pq.top().first);

            while (r < n-1) {
                r++;
                l++;
                pq.push({nums[r],r});
                while (!pq.empty()) {
                    auto t = pq.top();
                    if (t.second < l || t.second > r) {pq.pop(); continue;}
                    m.push_back(t.first);
                    break;
                }
            }

            return m;
        }
};

int main() {

    vector<int> nums{1,2,3,4,5,6,7,8,9};
    Solution solution{};
    auto o = solution.maxSlidingWindow(nums, 3);
    for (auto& e : o) cout << e << " ";
    cout << "\n";
    return 0;
}
