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

class Solution {
    public:
        int maximalRectangle(vector<vector<char>>& matrix) {

            const int n = matrix.size();
            const int m = matrix[0].size();

            vector<vector<int>> prefixSum(n, vector<int>(m,0));

            for (int i = 0; i < m; ++i) {
                prefixSum[0][i] = matrix[0][i] - '0';
            }

            for (int j = 0; j < m; ++j) {
                for (int i = 1; i < n; ++i) {
                    if (matrix[i][j] - '0')
                        prefixSum[i][j] = prefixSum[i-1][j] + matrix[i][j] - '0';
                }        
            }


            int max_ = -1;

            for (int i = 0; i < n; ++i) {
                max_ = max(max_, largestAreaHist(prefixSum[i]));
            }
            return max_;
        }


        int largestAreaHist(vector<int>& heights) {
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

    vector<vector<char>> inp{{'1'}};

    Solution solution{};
    int l = solution.maximalRectangle(inp);
    cout << l << "\n";
	return 0;
}
