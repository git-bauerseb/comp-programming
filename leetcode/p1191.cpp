#include <iostream>
#include <vector>

using namespace std;

// 3 cases
// i) Maximum subarray is within single instance => Kadane algorithm
// ii) Maximum subarray is end of first and beginning of second
// iii) Maximum subarray is end of first, multiple times complete array
//      and then the end
//

const int MOD = 1'000'000'007;

class Solution {
public:

    long long kadane(vector<int>& arr) {
        const int n = arr.size();

        long long gAnswer = 0;
        long long cAnswer = 0;

        for (int i = 0; i < arr.size(); ++i) {
            cAnswer = max((long long)arr[i], cAnswer + arr[i]);
            gAnswer = max(cAnswer, gAnswer);
        }

        return gAnswer;
    }

    int kConcatenationMaxSum(vector<int>& arr, int k) {
        const int n = arr.size();

        long long answer = -1e12;

        // Calculate largest prefix/suffix
        long long prefix = arr[0];
        long long suffix = arr[n-1];

        long long mPrefix = arr[0];
        long long mSuffix = arr[n-1];

        long long tSum = arr[0];

        for (int i = 1; i < n; ++i) {
            prefix += arr[i];
            suffix += arr[n-i-1];

            mPrefix = max(mPrefix, prefix);
            mSuffix = max(mSuffix, suffix);
        
            tSum += arr[i];
        }

        if (k > 1) {
            answer = max(answer, mPrefix + mSuffix);
        }

        if (k > 2) {
            answer = max(answer, mPrefix + mSuffix + (k-2)*tSum);
        }

        answer = max(answer, kadane(arr));
        answer %= MOD;

        return answer;
    }
};

int main() {
    vector<int> nums{1,2};
    Solution s{};
    cout << s.kConcatenationMaxSum(nums, 3) << "\n";
    return 0;
}
