#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

/*
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        const int n = nums.size();

        // map[i] := length of arithmetic sequence with difference i
        map<int,int> occ;
        map<int,int> last;

        map<int,int> app;

        for (int i = 0; i < n; ++i) {
            app[nums[i]]++;

            for (int j = i-1; j >= 0; --j) {
                int diff = nums[i] - nums[j];

                bool updated = false;
                
                if (diff > 0 && occ.count(diff) > 0 && j == last[diff]) {
                    occ[diff]++;
                    updated = true;
                } else {
                    if (occ.count(diff) <= 0) {
                        updated = true;
                        occ[diff] = 2;
                    }
                }


                if (updated) {
                    last[diff] = i;
                }
            }
        }

        for (auto& [key, value] : occ) {
            printf("%d %d\n", key, value);
        }

        int answer = 0;

        for (auto& [key, value] : occ) {
            if (value > 2) {
                long long total = value*(value+1)/2;
                total -= value;
                total -= (value-1);
                cout << key << " " << total << "\n";
                answer += total;
            }
        }

        for (auto& [key,value] : app) {
            cout << key << " appears " << value << "\n";
        }

        for (auto& [key, value]: app) {
            if (value > 2) {
                long long total = 1 << value;
                total -= value;
                total -= value*(value-1)/2;
                total -= 1;
                answer += total;
            }
        }

        return answer;
    }
};
*/

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        const int n = nums.size();
        vector<unordered_map<long long, int>> dp(n);

        long long answer = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                long long diff = (long long)nums[i] - (long long)nums[j];
                dp[i][diff]++;
                if (dp[j].count(diff)) {
                    dp[i][diff] += dp[j][diff];
                    answer += dp[j][diff];
                }
            }
        }
        
        return answer;
    }
};

int main() {
    vector<int> nums{0,2000000000,-294967296};
    Solution solution{};
    cout << solution.numberOfArithmeticSlices(nums) << "\n";
    return 0;
}
