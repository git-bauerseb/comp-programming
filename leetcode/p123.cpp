#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

// Constants
#define MOD 1'000'000'007

// Simple types
#define ll long long
#define ld long double

// Aggeragte types
#define pii pair<int,int>
#define pll pair<long,long>

#define vi vector<int>
#define vl vector<long>

#define si set<int>
#define sl set<long>

// Output
template <typename T>
void print_v(vector<T>& v) {cout << "{"; for (auto& x : v) cout << x << " "; cout << "\n";}

// 3 3 5 0 0 1 1 4
// 0 2 -5 0 1 -2 3
//
// prev 0 0 2 2 2 2 2
// gSum 0 2 2 2 2 2 3
class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            const int n = prices.size();           
            vi diff(n-1,0);
            vi prefix(n-1,0);

            // Calculate difference array
            for (int i = 1; i < n; ++i) {
                diff[i-1] = prices[i] - prices[i-1];
                prefix[i-1] = diff[i-1] + (i-1 == 0 ? 0 : prefix[i-2]);
            }


            // Find position/value of largest subarray
            int gSum = 0;
            int cSum = 0;
            int prev = 0;

            int start = 0, end = 0, gStart = 0, gEnd = 0;

            for (int i = 0; i < n-1; ++i) {
                cSum += diff[i];
                if (cSum <= 0) {
                    start = end = i+1;
                    cSum = 0;
                } else {
                
                    if (cSum > gSum) {
                        gStart = start;
                        gEnd = end;
                        prev = max(gSum, prev);
                        gSum = cSum;
                    }
                }

                end++;
            }


            int best = gSum + prev;

            // Break largest subarray sum apart
            for (int j = gStart + 1; j < gEnd-1; ++j) {
                if (diff[j] < 0) {
                    int left = prefix[j-1];
                    if (gStart) left -= prefix[gStart-1];
                    int right = prefix[gEnd-1];
                    if (j) right -= prefix[j];
                    best = max(left + right, best);
                }
            }


            return best;
        }
};

int main() {
    // Diff: -6 9 -8 5 5
    vector<int> nums{3,3,5,5,23,32,32,23,0,234,6,2,52,35,32,52,35,32,52,6,23,52,35,2,43,23,0,213,6,43,6,3,46,0,46,34,0,3,1,4};
    Solution solution{};
    int m = solution.maxProfit(nums);
	cout << m << "\n";
    return 0;
}
