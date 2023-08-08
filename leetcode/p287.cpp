#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

/*
    Misunderstood problem: Thought all numbers except one is duplicate

    x = 1 ^ 2 ^ 3 ^ 4 ^ ... ^ n

    Suppose l duplicate

    => array is 1,2,3,...,l-1,l,l,l+1,...,n

    XOR array then

    1 ^ 2 ^ 3 ^ ... ^ l-1 ^ l ^ l ^ l+1 ^ ... ^ n
    = 1 ^ 2 ^ 3 ^ ... ^ l-1 ^ l+1 ^ ... ^ n
*/
/*
class Solution {
    public:
        int findDuplicate(vector<int>& nums) {
            const int n = nums.size();

            int v1 = 0;
            int v2 = 0;

            for (int i = 0; i < n-1; ++i) {
                v2 = v2 ^ nums[i];
                v1 = v1 ^ (i+1);
            }
            v2 = v2 ^ nums[n-1];
            return v1 ^ v2;
        }
};
*/

/*
    1  = 1000
    2  = 0100
    3  = 1100
    4  = 0010
    5  = 1010
    6  = 0110
    7  = 1110
    8  = 0001
    9  = 1001
    10 = 0101
*/

/*
class Solution {

    int s1[32];
    int s2[32];

    public:
        int findDuplicate(vector<int>& nums) {
            const int n = nums.size();

            memset(s1, 0, sizeof(s1));
            memset(s2, 0, sizeof(s2));
            
            int ma = 0;

            for (int i = 0; i < n; ++i) {
                int idx = 0;
                while ((1 << idx) <= nums[i]) {
                    s1[idx] += (((1 << idx) & nums[i]) > 0) ? 1 : 0;
                    ++idx;
                }
                ma = max(ma, nums[i]);
            }

            for (int i = 0; i < ma; ++i) {
                int idx = 0;
                while ((1 << idx) <= (i+1)) {
                    s2[idx] += (((1 << idx) & (i+1)) > 0) ? 1 : 0;
                    ++idx;
                }
            }

            int dup = 0;
            for (int i = 0; i < 32; ++i) {
                if (s1[i] != 0 && (s1[i] != s2[i])) {
                    dup |= (1 << i);
                }
            }
            return dup;
        }
};
*/


class Solution {

    int s1[32];

    public:
        int findDuplicate(vector<int>& nums) {
            const int n = nums.size();

            memset(s1, 0, sizeof(s1));

            for (int i = 0; i < n; ++i) {

                int a = nums[i];
                int c = i+1;

                for (int j = 0; a > 0 || c >> 0; ++j) {

                    if ((a & 1) > 0) s1[j]++;
                    a >>= 1;

                    if (i != (n-1) && ((c & 1) > 0)) {
                        s1[j]--;
                    }

                    c >>= 1;
                }
            }

            int r = 0;

            for (int i = 0; i < 32; ++i) {
                if (s1[i] > 0) r |= (1 << i);
            }

            return r;
        }
};


int main() {

    vector<int> nums{1,4,4,2,4};

    Solution solution{};
    int d = solution.findDuplicate(nums);
    cout << d << "\n";

    return 0;
}
