#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

/*
class Solution {

    public:
        int createSortedArray(vector<int>& ins) {
            const int n = ins.size();
            m_smaller.resize(n, 0);
            m_bigger.resize(n, 0);
            m_indices.resize(n, 0);

            m_helper.resize(n, 0);
            m_helper2.resize(n,0);

            mergeSort(ins, 0, n-1);

            long cost = 0L;
            for (int i = 0; i < n; ++i) cost = (cost + static_cast<long>(min(m_smaller[i], m_bigger[i]))) % 1'000'000'007;
            return cost;
        }

        void mergeSort(vector<int>& nums, int l, int r) {
            if (l == r) {m_indices[l] = l;} // Save one O(n) for loop with this
            else {
                int m = (l + r) / 2;

                mergeSort(nums, l, m);
                mergeSort(nums, m+1, r);

                // Points to first element that is >= current
                long sIdx = l;
                // Points to first element that is > current
                long bIdx = l;

                for (int k = m+1; k <= r; ++k) {
                    while (sIdx <= m && nums[sIdx] < nums[k]) {sIdx++;}
                    while (bIdx <= m && nums[bIdx] <= nums[k]) {bIdx++;}
                    m_smaller[m_indices[k]] += sIdx - l;
                    m_bigger[m_indices[k]] += m - bIdx + 1;
                }
                
                merge(nums, l, m, r);
                // inplace_merge(nums.begin()+l, nums.begin()+m+1, nums.begin()+r+1);
            }
        }

        void merge(vector<int>& nums, int l, int m, int r) {
            int n1 = m - l + 1;
            int n2 = r - m;

            // Use helper array for speed-up
            // long* L = new long[n1];       // Contains elements nums[l], ..., nums[m]
            // long* R = new long[n2];       // Contains elements nums[m+1], ..., nums[r]

            // int* Lidx = new int[n1];
            // int* Ridx = new int[n2];

            for (int i = 0; i < n1; ++i) {
                m_helper2[i] = m_indices[l+i];
                m_helper[i] = nums[l+i];
            }
            
            for (int j = 0; j < n2; ++j) {
                m_helper2[n1+j] = m_indices[m+1+j];
                m_helper[n1+j] = nums[m+1+j];
            }

            int i = 0;      // Points to largest element in L not inserted 
            int j = 0;      // same -- in R not inserted

            // Sort indices with numbers

            for (int k = l; k <= r; ++k) {
                if (i == n1) {
                    m_indices[k] = m_helper2[n1+j];
                    nums[k] = m_helper[n1+j];
                    ++j;
                } else if (j == n2) {
                    m_indices[k] = m_helper2[i];
                    nums[k] = m_helper[i++];
                } else if (m_helper[i] > m_helper[n1+j]) {
                    m_indices[k] = m_helper2[n1+j];
                    nums[k] = m_helper[n1+j];
                    ++j;
                } else {
                    m_indices[k] = m_helper2[i];
                    nums[k] = m_helper[i++];
                }
            }

        }

    private:
        vector<long> m_smaller;
        vector<long> m_bigger;
        vector<int> m_indices;

        vector<int> m_helper;
        vector<int> m_helper2;
};
*/

#define LSOne(x) (x & (-x))
const int N_MAX = 100'002;

int ft[N_MAX];

void adjust(int idx, int delta) {
    for (int i = idx; i < N_MAX; i += LSOne(i)) ft[i] += delta;
}

int query(int idx) {
    int sum = 0;
    for (int i = idx; i > 0; i -= LSOne(i)) sum += ft[i];
    return sum;
}

// Solution 2: Using Fenwick/BIT trees
class Solution {

    public:
        int createSortedArray(vector<int>& ins) {
            const int n = ins.size();
            long cost = 0;

            memset(ft, 0, sizeof(ft));

            for (int i = 0; i < n; ++i) {
                int num = ins[i];
                
                int less = num == 1 ? 0 : query(num-1);
                int greater = query(N_MAX-1);
                greater -= query(num);

                cost = (cost + min(greater, less)) % 1'000'000'007;
                adjust(num, 1);
            }

            return cost;
        }
};


int main() {

    vector<int> nums{1,3,3,3,2,4,2,1,2};
    Solution solution{};
    int c = solution.createSortedArray(nums);

    cout << c << "\n";

    return 0;
}
