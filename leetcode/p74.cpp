#include <iostream>
#include <vector>

using namespace std;

class Solution {

    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            const int m = matrix.size();
            const int n = matrix[0].size();

            int l = -1;
            int r = m;

            if (matrix[m-1][n-1] < target
            || matrix[0][0] > target)
                return false;

            auto f = [&](int idx) {
                int lo = -1;
                int hi = n;

                while (hi-lo > 1) {
                    int m = lo + (hi-lo)/2;
                    if (matrix[idx][m] < target) {lo = m;}
                    else {hi = m;}
                }

                return hi;
            };

            while (r-l > 1) {
                int m = l + (r-l)/2;
                if (f(m) == n) {l = m;}
                else {r = m;}
            }


            int col = f(r);
            return col < n && r < m
                && matrix[r][col] == target;
        }

};

int main() {

    vector<vector<int>> nums=
    {{1,3,5,7},{10,11,16,20},{23,30,34,60}};

    Solution solution{};
    bool res = solution.searchMatrix(nums, 4);
    cout << res << "\n";


    return 0;
}
