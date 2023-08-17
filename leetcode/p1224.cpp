#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <cstring>

using namespace std;
/*

    - If leastFreq >= 2 && mostFrequent - leastFrequent > 1 => Impossible
        2,2,1,1,1,1

        This is why leastFreq >= 2 => Otherwise can remove least frequent
        2,1,1,1,1

    - If leastFreq != mostFrequent && #leastFreq >= 2 && #mostFreq >= 2
        3,4,4,4,5
*/
int dp[100'001];

class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        const int n = nums.size();
        memset(dp, 0, sizeof(dp));

        // occ[i] many elements occur i times
        map<int,int> occ;

        int min_ = 0;   // Minimum number of occurrences
        int max_ = 0;   // Maximum number of occurrences

        int answer = 1;

        for (int i = 0; i < n; ++i) {
            int el = nums[i];

            int old = dp[el];
            dp[el] = old+1;

            if (occ[old] > 0) {
                occ[old]--;
            } else {
                min_ = 1;
            }

            occ[old+1]++;
            max_ = max(max_, old+1);

            // el was last number that occured for minimum number of times
            if (occ[old] == 0 && old == min_) {
                for (int i = old+1; i <= max_; ++i) {
                    if (occ[i] > 0) {
                        min_ = i;
                        break;
                    }
                }
            }

            if (
                (min_ + 1 == max_ && (occ[max_] == 1))
                ||
                (min_ == 1 && occ[min_] == 1 && (max_*occ[max_] + min_*occ[min_]) == i+1)
                ||
                (max_ == min_ && (max_ == 1 || occ[max_] == 1))
                || 
                (max_ == min_ && max_ > 1 && occ[max_] == occ[min_]-1)
            ) {
                answer = i + 1;
            }

        }

        return answer;
    }
};

int main() {
    vector<int> nums{1,1};
    Solution solution {};
    cout << solution.maxEqualFreq(nums) << "\n";
    return 0;
}
