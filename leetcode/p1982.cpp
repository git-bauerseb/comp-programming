#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Solution only working for positive numbers.
/*
class Solution {

    public:
        vector<int> recoverArray(int n, vector<int>& sums) {
            sort(sums.begin(), sums.end());
            rec(sums, 0, sums.size());
            return m_res;
        }

        void rec(vector<int>& sums, int l, int r) {
            if (l+1 >= r) {return;}
            
            // Find smallest positive number
            int num = sums[l+1];
            m_res.push_back(num);

            for (int i = 0; i < (r-l)/2; ++i) {
                sums[i] = sums[2*i];
            }
            rec(sums, l, (r-l)/2);
        }

    private:
        vector<int> m_res;
};
*/

class Solution {

    public:
        vector<int> recoverArray(int n, vector<int>& sums) {
            sort(sums.begin(), sums.end());
            rec(sums);
            return m_result;
        }


        void rec(vector<int>& sums) {
            if (sums.size() < 2) {return sums[0] == 0;}



            vector<int> v1;
            vector<int> v2;


            // If p1 != p2, need to check if either p1 belongs to array or p2

            // Assume here p1 belongs to array
            // then split sums into sums that contain p1 and sums that don't contain
            // p1

            for (int i = 0; i < sums.size()-1; i += 2) {
                v1.push_back(sums[i]);
                v2.push_back(sums[i+1]);
            }

            if (lower_bound(v1.begin(), v1.end(), 0) != v1.end()) {
                   
            }
        }

    private:
        vector<int> m_result;
};


vector<int> generateSubsetSums(vector<int>& nums) {
    const int n = nums.size();
    vector<int> sums;
    for (int i = 0; i < (1 << n); ++i) {
        int iCpy = i;
        int cSum = 0;
        int idx = 0;
        while ((iCpy >> idx) > 0) {
            if ((iCpy >> idx) & 1) cSum += nums[idx];
            idx++;
        }
        
        sums.push_back(cSum);
    }

    return sums;
}

int main() {
    vector<int> nums{-1,2,3};
    vector<int> ss1 = generateSubsetSums(nums);

    Solution solution{};
    auto a = solution.recoverArray(3, ss1);
    
    for (auto& e : a) cout << e << " ";
    cout << "\n";

    return 0;
}
