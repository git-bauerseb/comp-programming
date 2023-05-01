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

// 1  8 -4                        1 8 -4
// 3  9  2   ---(Prefix Sum)--->  4 9 -2
// -7 0 -5                       -3 9 -7
//
//
//
// k = 5
//
// k = 2
// 1 0 1      -> 1 0 1
// 0 -2 3        1 -2 4
//
// Invariant: lOpt := maximum subarray sum ending at position i and <= k
class Solution {
    public:
        int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
            const int n = matrix.size();
            const int m = matrix[0].size();
            // Calculate prefix sum vertically
            for (int i = 1; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    matrix[i][j] += matrix[i-1][j];
                }
            }

            int gOpt = -1E8;
            // Go over each pair of indices (i,j) s.t i < j
            // n*(n+1)/2
            // (0,0), (0,1), (0,2), (1,1), (1,2), (2,2)
            for (int i = 0; i < n; ++i) {
                for (int j = i; j < n; ++j) {
                    // int number = matrix[j][..] - i == 0 ? 0 : matrix[i-1][..]
                    int start = 0;
                    int end = 0;
                    int sum = matrix[j][0] - (i == 0 ? 0 : matrix[i-1][0]);

                    for (int u = 1; u < m; ++u) {
                        // Calculate element
                        int element = matrix[j][u]; if (i > 0) element -= matrix[i-1][u];

                        sum += element;
                        end += 1;

                            while (sum > k) {
                                int sEl = matrix[j][start]; if (i > 0) sEl -= matrix[i-1][start];
                                sum -= sEl;
                                start++; 
                            }

                        cout << sum << "\n";
                        gOpt = max(gOpt, sum);
                    }

                }
            }

            return gOpt;
        }
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    // 8 7 6 3
    //
    // 5

    vector<vector<int>> dp = {{4,3,2,-1}};

    Solution solution{};
    int sol = solution.maxSumSubmatrix(dp, 1);
    cout << sol << "\n";
	return 0;
}
