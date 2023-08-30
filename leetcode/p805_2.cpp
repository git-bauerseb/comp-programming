#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const double EPS = 1e-7;

class Solution {
public:
    bool bin_search(vector<double>& n2, double value) {
        int lo = -1;
        int hi = n2.size();

        while (hi - lo > 1) {
            int m = (hi + lo) / 2;
            if (abs(n2[m] - value) < EPS) {return true;}

            if (n2[m] <= value) {
                lo = m;
            } else {
                hi = m;
            }
        }
        return lo < n2.size() && (abs(n2[lo] - value) < EPS);
    }

    bool splitArraySameAverage(vector<int>& nums) {
        const int n = nums.size();

        if (n == 1) {
            return false;
        }

        double avg = 0.0;
        int sum = 0;

        for (auto& e : nums) {
            sum += e;
        }

        avg = (double)sum / (double)n;

        vector<double> numsNorm(n);
        for (int i = 0; i < n; ++i) {
            numsNorm[i] = nums[i] - avg;
        }



        int h1 = n % 2 == 0 ? n / 2 : (n-1) / 2;
        int h2 = n - h1;
        vector<double> first((1 << h1)-1);
        vector<double> second((1 << h2)-1);

        for (int mask = 1; mask < (1 << h1); ++mask) {
            double sum = 0;
            for (int j = 0; j < h1; ++j) {
                if ((mask & (1 << j))) {
                    sum += numsNorm[j];
                }
            }
            first[mask-1] = sum;
        }

        for (int mask = 0; mask < (1 << h2)-1; ++mask) {
            double sum = 0;
            for (int j = 0; j < h2; ++j) {
                if ((mask & (1 << j))) {
                    sum += numsNorm[h1+j];
                }
            }
            second[mask] = sum;
        }

        sort(second.begin(), second.end());
 
        for (double& e : first) {
            
            if (abs(e - 5.8) < EPS) {
                printf("!\n");
            }
            
            if (abs(e) < EPS || bin_search(second, -e)) {
                return true;
            }
        }

        return false;
    }
};

int main() {
    vector<int> nums{8,1,9,8,9,7,2,2,8,2};
    Solution s{};
    cout << s.splitArraySameAverage(nums) << "\n";
    return 0;
}
