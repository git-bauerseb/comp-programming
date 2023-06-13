#include <iostream>
#include <vector>

using namespace std;

// Kadane algorithm
//
// Invariant:
// sum := maximum subarray ending at current index
int max1D(std::vector<int>& nums) {
    const int n = nums.size();
    int sum = 0;
    int gSum = -(1 << 29);
    for (int i = 0; i < n; ++i) {
        sum = max(nums[i], sum + nums[i]);
        gSum = max(gSum, sum);
    }
    return gSum;
}


int max2D(std::vector<std::vector<int>>& nums) {
    const int m = nums.size();
    const int n = nums[0].size();

    // Calculate cumulative sum in-place along rows
    for (int j = 1; j < m; ++j) {
        for (int i = 0; i < n; ++i) {
            nums[j][i] += nums[j-1][i];
        }
    }

    // Apply 1D Kadane between each pair of rows
    int gMax = -(1 << 29);
    for (int r1 = 0; r1 < m; ++r1) {
        for (int r2 = r1; r2 < m; ++r2) {
            int lMax = -(1 << 29);
            int sum = -(1 << 29);
            for (int l = 0; l < n; ++l) {
                int element = nums[r2][l] - (r1 == 0 ? 0 : nums[r1-1][l]);
                sum = max(element, sum + element);
                lMax = max(lMax, sum);
            }
            gMax = max(gMax, lMax);
        }
    }

    return gMax;
}


void test1() {
    std::vector<std::vector<int>> nums = 
    {
        {0, -2, -7, 0},
        {9, 2, -6, 2},
        {-4, 1, -4, 1},
        {-1, 8, 0, -2}
    };

    std::cout << max2D(nums) << "\n";
}

int main() {
    // test1();
    
    return 0;
}
