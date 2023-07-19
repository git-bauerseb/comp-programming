#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {

    public:
        int maxCoins(vector<int>& piles) {
            const int n = piles.size();
            sort(piles.rbegin(), piles.rend());


            int l = 1;
            int r = n-1;

            int c = 0;

            while (r > l) {
                c += piles[l];
                r--;
                l += 2;
            }


            return c;
        }
};

int main() {

    // 9, |8|, 7, 6, |5|, 4, 3, |2|, 1
    //
    // (9,8,1) => 8
    // (7,6,2) => 6
    // (5,4,3) => 4
    vector<int> nums{2,4,1,2,7,8};

    Solution solution{};
    int r = solution.maxCoins(nums);
    cout << r << "\n";

    return 0;
}
