#include <iostream>
#include <vector>
#include <cstring>

using namespace std;


#define LSOne(x) (x & (-x))

/*
 
// Solution works
// Think about alternative
// O(n log(n))


const int N_MAX = 2*10'000 + 4;
int ft[N_MAX];

void adjust(int idx, int delta) {
    for (int i = idx; i < N_MAX; i += LSOne(i)) {
        ft[i] += delta;
    } 
}

int rsq(int idx) {
    int sum = 0;

    for (int i = idx; i > 0; i -= LSOne(i)) {
        sum += ft[i];
    }

    return sum;
}

class Solution {

    public:
        vector<int> countSmaller(vector<int>& nums) {
            memset(ft, 0, sizeof(ft));
            
            const int n = nums.size();
            vector<int> result(n,0);

            for (int i = n-1; i >= 0; --i) {
                int cNum = nums[i] + 10'001;
                result[i] = cNum <= 1 ? 0 : rsq(cNum-1);
                adjust(cNum, 1);
            }

            return result;
        }
};
*/

// Solution 2
// Use merge sort idea
class Solution {

    public:
        vector<int> countSmaller(vector<int>& nums) {
            const int n = nums.size();

            m_result.resize(n, 0);
            m_indices.resize(n, 0);

            for (int i = 0; i < n; ++i) m_indices[i] = i;

            mergeSortIdea(nums, 0, n-1);

            return m_result;
        }

        void mergeSortIdea(vector<int>& nums, int l, int r) {
            if (l == r) {m_result[l] = 0;
            } else {
                int m = (l + r) / 2;

                // Split list in halfes and count number of elements smaller in left/right
                // list separate
                mergeSortIdea(nums, l, m);
                mergeSortIdea(nums, m+1, r);

                int cumulative = 0;
                int rIdx = m+1;

                // Key part
                //   Left/right lists are sorted
                //   Count for each element in left list, how many elements in right
                //   list are smaller. If we've calculated the number of element
                //   left[i] and want to calculate it for left[j] with j > i,
                //   we know that all elements that are < left[i] are also less than left[j]
                //   (because sorted). This way, we can keep track of a cumulative variable.
                //   Naive implementation would calculate it in O(n^2) => TLE
                for (int i = l; i <= m; ++i) {
                    while (rIdx <= r && nums[rIdx] < nums[i]) {cumulative++; rIdx++;}
                    m_result[m_indices[i]] += cumulative;
                }

                // combine(nums, l, m, r);
                merge(nums, l, m, r);
            }
        }

        void merge(vector<int>& nums, int l, int m, int r) {
            int n1 = m - l + 1;
            int n2 = r - m;

            int* L = new int[n1];       // Contains elements nums[l], ..., nums[m]
            int* R = new int[n2];       // Contains elements nums[m+1], ..., nums[r]

            int* Lidx = new int[n1];
            int* Ridx = new int[n2];

            for (int i = 0; i < n1; ++i) {Lidx[i] = m_indices[l+i]; L[i] = nums[l+i];}
            for (int j = 0; j < n2; ++j) {Ridx[j] = m_indices[m+1+j]; R[j] = nums[m+1+j];}

            int i = 0;      // Points to largest element in L not inserted 
            int j = 0;      // same -- in R not inserted

            // Sort indices with numbers

            for (int k = l; k <= r; ++k) {
                if (i == n1) {
                    m_indices[k] = Ridx[j];
                    nums[k] = R[j++];
                } else if (j == n2) {
                    m_indices[k] = Lidx[i];
                    nums[k] = L[i++];
                } else if (L[i] > R[j]) {
                    m_indices[k] = Ridx[j];
                    nums[k] = R[j++];
                } else {
                    m_indices[k] = Lidx[i];
                    nums[k] = L[i++];
                }
            }

            delete[] L;
            delete[] R;
            delete[] Lidx;
            delete[] Ridx;
        }

        vector<int> m_result;
        vector<int> m_indices;
};


int main() {

    vector<int> nums{-1};

    Solution solution{};
    vector<int> result = solution.countSmaller(nums);

    for (auto& e : result) cout << e << " ";
    cout << "\n";


    return 0;
}
