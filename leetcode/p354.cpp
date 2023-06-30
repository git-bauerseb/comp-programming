#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Solution: Wrong
/*
class Solution {
    public:
        int maxEnvelopes(vector<vector<int>>& envelopes) {
            const int n = envelopes.size();
            sort(envelopes.begin(), envelopes.end(),
                    [&](const vector<int>& a, const vector<int>& b) {
                        if (a[0] != b[0]) return a[0] < b[0];
                        return a[1] < b[1];
                    });
            int mEnv = 1;
            vector<int> dp(n, 0);
            dp[0] = 1;
            for (int i = 1; i < n; ++i) {

                if (i == n-1) {
                    cout << "H\n";
                }

                int cWidth = envelopes[i][0];
                int cHeight = envelopes[i][1];

                // Search for largest envelope with smaller width
                // Gives first element !(< width)
                auto sW = lower_bound(envelopes.begin(), envelopes.begin()+i, cWidth,
                     [](const vector<int>& env, int value) {
                        return env[0] < value;
                     }        
                );

                // Search for largest element among smaller width
                // that has height <
                // Gives first element !(< height) <=> >= height
                auto sH = lower_bound(envelopes.begin(), sW, cHeight,
                        [](const vector<int>& env, int value) {
                            return env[1] < value;
                        });

                if (sH != envelopes.begin()) {
                    int idx = (int)(sH - envelopes.begin() - 1);
                    dp[i] = 1 + dp[idx];
                    mEnv = max(mEnv, dp[i]);
                } else {
                    dp[i] = 1;
                }
            } 

            for (auto& e : dp) cout << e << " ";
            cout << "\n";

            return mEnv;
        }
};
*/


// Idea 2: LIS on width and then LIS on height
// Separate LIS not working
//   Example:
//      Width       2 5 6 6
//      Height      3 4 4 7
//
// First selection (2,3) (5,4) (6,4) BUT (6,7) would be better option
/*
class Solution {
    public:
        int maxEnvelopes(vector<vector<int>>& env) {
            const int n = env.size();

            sort(env.begin(), env.end(),
                    [&](const vector<int>& a, const vector<int>& b) {
                if (a[0] != b[0]) return a[0] < b[0];
                return a[1] < b[1];
            });

            // At posiiton i: Contains smallest width such that there is a increasing subsequence
            // of envelopes ending at element env[i] (when sorted)
            // Contains index of element in sorted array
            vector<int> lis;
            
            for (int i = 0; i < n; ++i) {
                int cWidth = env[i][0];
                // Index of first element !(< cWidth) <=> >= cWidth
                int idx = (int)(lower_bound(lis.begin(), lis.end(), cWidth,
                            [&](int index, int value) {
                                return env[index][0] < value;
                            }) - lis.begin());
            
                if (idx == lis.size()) {
                    lis.push_back(idx);
                } else if (idx < lis[idx]) {
                    lis[idx] = idx;
                }
            }


            vector<int> lisHeight;
            const int m = lis.size();


            for (int i = 0; i < m; ++i) {
                int cHeight = env[lis[i]][1];

                int idx = (int)( 
                        lower_bound(
                            lisHeight.begin(),
                            lisHeight.end(),
                            cHeight,
                            [&](int index, int value) {
                                return env[lis[index]][1] < value;
                            }    
                        )
                        
                        - lisHeight.begin());

                if (idx == lisHeight.size()) {
                    lisHeight.push_back(idx);
                } else if (idx < lisHeight[idx]) {
                    lisHeight[idx] = idx;
                }
            }

            return lisHeight.size();
        }
};
*/

/*
bool comp(const vector<int>& envA, const vector<int>& envB) {
    if (envA[0] != envB[0]) return envA[0] < envB[0];
    return envA[1] < envB[1];
}

// Returns true if a fits in b
bool fits(const vector<int>& a, const vector<int>& b) {
    return a[0] < b[0] && a[1] < b[1];
}


class Solution {

    public:

        int maxEnvelopes(vector<vector<int>>& envs) {
            const int n = envs.size();
            sort(envs.begin(), envs.end(), comp);
            vector<int> lis;

            for (int i = 0; i < n; ++i) {
                int idx = (int)(lower_bound(lis.begin(), lis.end(), envs[i], 
                            [&](int index, const vector<int>& value) {
                                return comp(envs[index], value);
                            }
                            ) - lis.begin());
                if (idx == lis.size() 
                && (idx == 0 || fits(envs[lis[idx-1]], envs[i]))) {lis.push_back(idx);}
                else if (comp(envs[i], envs[lis[idx]])) {
                    lis[idx] = i;
                }
            }

            return lis.size();
        }
};
*/

class Solution {

    public:
        int maxEnvelopes(vector<vector<int>>& envs) {
            const int n = envs.size();

            sort(envs.begin(), envs.end(),
                    [&](const vector<int>& a, const vector<int>& b) {
                if (a[0] != b[0]) return a[0] < b[0];
                return a[1] > b[1]; // a[1] < b[1] is WRONG
            });

            vector<int> lis;

            for (int i = 0; i < n; ++i) {
                int idx = (int)(lower_bound(lis.begin(), lis.end(), envs[i][1]) - lis.begin());
                if (idx == lis.size()) {lis.push_back(envs[i][1]);}
                else if (envs[i][1] < lis[idx]) {lis[idx] = envs[i][1];}
            }

            return lis.size();
        }
};


int main() {
    vector<vector<int>> envs {
        {2,3}, {5,4}, {6,4}, {6,7}
    };

    Solution solution{};
    int m = solution.maxEnvelopes(envs);

    cout << m << "\n";

    return 0;
}
