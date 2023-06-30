#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
    public:
        int countRangeSum(vector<int>& nums, long lower, long upper) {
            const int n = nums.size();
            
            m_count = 0;
            m_lower = lower;
            m_higher = upper;


            vector<long> sum(n, 0);
            sum[0] = nums[0];
            for (int i = 1; i < n; ++i) sum[i] = sum[i-1] + static_cast<long>(nums[i]);

            dQ(sum, 0, n-1);
            return m_count;
        }

        // divide and conquer
        void dQ(vector<long>& nums, int l, int r) {
            if (l == r) {
                m_count += nums[l] >= m_lower && nums[l] <= m_higher ? 1 : 0;
            } else {
                int m = (l + r) / 2;

                dQ(nums, l, m);
                dQ(nums, m+1, r);

                /*
                // Naive solution: O(n^2)
                // Here: O(nlog(n))
                for (int i = l; i <= m; ++i) {
                    // First element !(< lo + si) <=> >= lo + si
                    auto it = lower_bound(nums.begin()+m+1, nums.begin()+r+1, m_lower + nums[i]);
                    // First element !(< hi + si + 1) <=> >= hi + si
                    auto it2 = lower_bound(it, nums.begin()+r+1, m_higher + nums[i] + 1);

                    m_count += max(0, (int)(it2 - it));
                }
                */

                
                // Points to lowest index in right array s.t. left[i] - right[lPtr] >= low
                int lPtr = m+1;

                // Points to highest index in right array s.t. right[rPtr] - left[i] <= hi
                int rPtr = m+1;


                // Number of valid sums is then (rPtr - lPtr + 1)
                for (int i = l; i <= m; ++i) {
                    int oLeft = lPtr;
                    while (rPtr <= r && nums[rPtr] - nums[i] <= m_higher) rPtr++;
                    while (lPtr <= r && nums[lPtr] - nums[i] < m_lower) lPtr++;
                    m_count += max(0, rPtr - lPtr);
                }

                merge(nums, l, m, r);
            }
        }

        void merge(vector<long>& nums, int l, int m, int r) {

            // Size left nums[l], ..., nums[m]
            int sl = m - l + 1;
            int sr = r - (m+1) + 1;

            long* L = new long[sl];
            long* R = new long[sr];

            for (int i = 0; i < sl; ++i) {L[i] = nums[l+i];}
            for (int j = 0; j < sr; ++j) {R[j] = nums[m+1+j];}

            int idxL = 0;
            int idxR = 0;

            for (int k = l; k <= r; ++k) {
                if (idxL == sl) {nums[k] = R[idxR++];}
                else if (idxR == sr) {nums[k] = L[idxL++];}
                else if (L[idxL] > R[idxR]) {nums[k] = R[idxR++];}
                else {nums[k] = L[idxL++];}
            }

            delete[] L;
            delete[] R;
        }

    private:
        int m_count;
        long m_lower;
        long m_higher;

};

int main() {

    // -1, 0
    // -1 + 0 = -1
    // 100 + -100 = 0
    // 100 + -100 -1 = -1
    // 100 + -100 -1 + 0 = -1
    
    vector<int> nums{2147483647,-2147483648,-1,0};

    Solution solution{};
    int c = solution.countRangeSum(nums, -1,0);

    cout << c << "\n";

    return 0;
}
