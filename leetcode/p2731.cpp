#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int MOD = 1'000'000'007;

class Solution {
public:
    int sumDistance(vector<int>& nums, string s, int d) {
        const int n = nums.size();
        vector<long long> nPos(n);
        long long dist = d;
        for (int i = 0; i < n; ++i) {
            nPos[i] = s[i] == 'L' ? (long long)(nums[i] - dist) : (long long)(nums[i] + dist);
        }
        sort(nPos.begin(), nPos.end());

        long long answer = 0;
        long long negDist = 0;
        long long numNeg = 0;

        for (int i = 0; i < n; ++i) {
            if (nPos[i] < 0) {
                numNeg++;
                negDist += (long long)abs(nPos[i]);
            }
        }

        for (int i = 0; i < n; ++i) {
            if (nPos[i] >= 0) {
                answer = (answer + nPos[i] * numNeg + negDist) % MOD;
            }
        }


        int idx = n-2;
        long long prefix = 0;
        long long inc = 1;
        while (idx >= 0 && nPos[idx] >= 0) {
            prefix = (prefix + inc * abs(nPos[idx+1] - nPos[idx])) % MOD;
            inc++;
            idx--;
            answer = (answer + prefix) % MOD;
        }

        idx = 1;
        prefix = 0;
        inc = 1;
        
        while (idx < n && nPos[idx] < 0) {
            prefix = (prefix + inc * abs(nPos[idx] - nPos[idx-1])) % MOD;
            inc++;
            idx++;
            answer = (answer + prefix) % MOD;
        }

        return answer;
    }
};

int main() {
    vector<int> nums{0,-2};
    Solution solution{};
    cout << solution.sumDistance(nums, "LL", 2) << "\n";
    return 0;
}
