#include <iostream>
#include <map>
#include <vector>

using namespace std;

/*
    nums1, nums2, nums3, nums4

    Indices (i,j,k,l) s.t.
    nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0

    Naive solution: O(n^4)
    Naive solution: O(n^3 log(n))
        => Sort + Iterate over 3 arrays and do binary search in last array


    (i,j) => nums1[i] + nums2[j] = a fixed    
    Find sum in nums3, nums4 s.t. they add up to -a
        => Preprocessing: Compute all possible sums in nums3, nums4 O(n^2)
        => Then do binary search  for -a => O(log n)

    => Total: O(n^2 log(n))
*/
class Solution {

    public:
        int fourSumCount(vector<int>& n1, vector<int>& n2, vector<int>& n3, vector<int>& n4) {

            map<long long, int> sums;
            for (int i = 0; i < n3.size(); i++) {
                for (int j = 0; j < n4.size(); j++) {
                    sums[static_cast<long long>(n3[i]) + static_cast<long long>(n4[j])]++;
                }
            }            

            int cnt = 0;
            for (int i = 0; i < n1.size(); i++) {
                for (int j = 0; j < n2.size(); j++) {
                    long long a = (long long)(n1[i]) + (long long)(n2[j]);
                    if (sums.count(-a) > 0) cnt += sums[-a];
                }
            }

            return cnt;
        }
};

int main() {

    vector<int> a{-1,-1};
    vector<int> b{-1,1};
    vector<int> c{-1,1};
    vector<int> d{1,-1};

    Solution solution{};
    int cnt = solution.fourSumCount(a,b,c,d);
    cout << cnt << "\n";

    return 0;
}
