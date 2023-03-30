#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>

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
//  WRONG
//
//  n = 6
//           2  1  5  6  2  3
//     left  0  0  2  3  3  3
// cor. lef  0  0  2  3  2  5
//
//     right 0  3  3  3  5  5
// cor. righ 0  5  3  3  5  5
//
//     sol   min(heights[left[i]], heights[right[i]])
//           2 * 
//
class Solution {

    public:
        int largrestRectangleArea(vector<int>& heights) {
            const int n = heights.size();
            
            vi right(n,0);
            vi left(n,0);

            stack<int> mon;
            for (int i = 0; i < n; ++i) {
                while (!mon.empty() && heights[mon.top()] > heights[i]) {
                    int t = mon.top();
                    mon.pop();
                    right[t] = i;
                }
                mon.push(i);
            }
            

            while (!mon.empty()) {   
                int t = mon.top();
                mon.pop();
                right[t] = n;
            }


            for (int i = n-1; i >= 0; --i) {
                while (!mon.empty() && heights[mon.top()] > heights[i]) {
                    int t = mon.top();
                    mon.pop();
                    left[t] = i;
                }
                mon.push(i);
            }

            while (!mon.empty()) {
                int t = mon.top();
                mon.pop();
                left[t] = -1;
            }

            int max_ = -1;
            for (int i = 0; i < n; ++i) {
                int lIdx = left[i]+1;
                int rIdx = right[i]-1;
                int cHeight = heights[i] * (rIdx-lIdx+1);
                max_ = max(max_, cHeight);
            }

            return max_;
        }
};


int main() {

    vector<int> nums{3,1,3,2,2};
    Solution solution{};
    int m = solution.largrestRectangleArea(nums);
    cout << m << "\n";
	return 0;
}
