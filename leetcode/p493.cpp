#include <iostream>
#include <vector>

using namespace std;

// Idea
//
// Similar to merge sort
// During recursion, assume l,r are sorted
// Iterate over all elements in l
// Index in r s.t. 2*nums[idx in r] < nums[idx in l]
// Keep track of cumulative sum => O(n)
//
// Time complexity: O(nlog(n))
class Solution {

    public:
        int reversePairs(vector<int>& nums) {
            const int n = nums.size();
            m_count = 0;
            divideConquer(nums, 0, n-1);
            return m_count;
        }

        void divideConquer(vector<int>& nums, int l, int r) {
            if (l == r) return;
            else {
                int m = (l + r) / 2;

                divideConquer(nums, l, m);
                divideConquer(nums, m+1, r);

                int cumulative = 0;
                int rIdx = m+1;


                for (int i = l; i <= m; ++i) {
                    while (rIdx <= r
                            && static_cast<long>(nums[rIdx])*2L < static_cast<long>(nums[i])) {
                        cumulative++; rIdx++;
                    }
                    m_count += cumulative;
                }

                merge(nums, l, m, r);
            }
        }

        void merge(vector<int>& nums, int l, int m, int r) {

            int l1 = m - l + 1;
            int l2 = r - m;

            int* L = new int[l1];
            int* R = new int[l2];

            for (int i = 0; i < l1; ++i) L[i] = nums[i+l];
            for (int j = 0; j < l2; ++j) R[j] = nums[m+1+j];

            int i = 0;      // Index of largest element in left list not yet inserted
            int j = 0;      // Index of largest element in right list not yet inserted

            for (int k = l; k <= r; ++k) {
                if (i == l1) {
                    nums[k] = R[j++];
                } else if (j == l2) {
                    nums[k] = L[i++];
                } else if (L[i] > R[j]) {
                    nums[k] = R[j++];
                } else {
                    nums[k] = L[i++];
                }
            }

            delete[] L;
            delete[] R;
        }
        
    private:
        int m_count;
};

int main() {
    
    vector<int> nums{1};

    Solution solution{};
    int p = solution.reversePairs(nums);
    cout << p << "\n";

    return 0;
}
