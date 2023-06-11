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
/*
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
*/

/*
class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            const int n = prices.size();

            int l1 = prices[0];
            int h1 = prices[0];
            int p1 = 0;
            int prev = 0;

            for (int i = 1; i < n; ++i) {
                if (prices[i] < h1) {
                    l1 = prices[i];
                    h1 = prices[i];
                    prev = p1;
                    p1 = 0;
                } else {
                    h1 = prices[i];
                    p1 = max(p1, h1-l1);
                }
            }

            return p1 + prev;
        }
};
*/

// Idea: - Keep track of minimum and maximum where maximum comes after minimum
//          - keep indices
//       - do a second run that computes the same outside the bounds of first (min,max)-pair
/*
class Solution {

    public:
        int maxProfit(vector<int>& prices) {


        }
};
*/

class Solution {

    public:
        int maxProfit(vector<int>& prices) {
            const int n = prices.size();
            vector<int> before(n, 0);

            int max_ = -1;
            int min_ = 1 << 29;
            for (int i = 0; i < n; ++i) {
                if (prices[i] < min_) {min_ = prices[i]; max_ = min_;}
                else max_ = max(prices[i], max_);
                before[i] = max(i == 0 ? 0 : before[i-1], max_ - min_);
            }

            vector<int> after(n, 0);
            max_ = -1;
            min_ = 1 << 29;
            for (int i = n-1; i >= 0; --i) {
                if (prices[i] > max_) {max_ = prices[i]; min_ = max_;}
                else min_ = min(prices[i], min_);
                after[i] = max(i == n-1 ? 0 : after[i+1], max_ - min_);
            }

            // Calculate max profit
            int mProfit = 0;
            for (int i = 0; i < n; ++i) {
                int a = i == n-1 ? 0 : after[i+1];
                mProfit = max(mProfit, before[i] + a);
            }
            return mProfit;
            
        }
};


int main() {
    vector<int> nums{3,2,6,5,0,3};
    
    Solution solution{};
    int m = solution.maxProfit(nums);
	cout << m << "\n";
    return 0;
}

