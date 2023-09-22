#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumRows(vector<vector<int>>& matrix, int numSelect) {
        const int m = matrix.size();
        const int n = matrix[0].size();

        vector<int> rSum(m, 0);

        for (int y = 0; y < m; ++y) {
            for (int x = 0; x < n; ++x) {
                if (matrix[y][x] == 1) rSum[y]++;
            }
        }

        

        int mCovered = 0;

        for (int mask = 0; mask < (1 << n); ++mask) {
            if (__builtin_popcount(mask) <= numSelect) {
                int cCovered = 0;
                for (int y = 0; y < m; ++y) {
                    int rCov = 0;
                    for (int x = 0; x < n; ++x) {
                        if ((mask & (1 << x)) > 0 && matrix[y][x] == 1) rCov++; 
                    }
                    cCovered += rCov >= rSum[y];
                }

                mCovered = max(mCovered, cCovered);
            }
        }

        return mCovered;
    }
};

int main() {
    vector<vector<int>> m = {
        {0,0,0},
        {1,0,1},
        {0,1,1},
        {0,0,1}
    };

    Solution s{};
    cout << s.maximumRows(m, 2) << "\n";
    return 0;
}
