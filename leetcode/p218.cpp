#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

/*
    UNSOLVED!
*/

/*
struct {
    bool operator()(const pair<int,int>& left, const pair<int,int>& right) {
        return left > right;
    }
} cComparator;

class Solution {

    public:
        vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
            const int n = buildings.size();

            
            vector<vector<int>> key_points;

            for (int i = 0; i < n; ++i) {

                vector<int>& c_building = buildings[i];

                int c_start = c_building[0];
                int m_height = c_building[2];

                // Find height of largest house at current position
                for (int j = i-1; j >= 0; --j) {
                    vector<int>& p_building = buildings[j];
                    if (p_building[0] <= c_start && p_building[1] > c_start) {
                        m_height = max(m_height, p_building[2]);
                    }
                }



                if (key_points.size() == 0) {
                    key_points.push({c_start, m_height});
                } else {
                    // Only append new keypoint if previous one is of different height
                    vector<int>& last = key_points.back();
                    
                    if (last[1] != m_height) {
                        
                    }
                }
            }

        }
};
*/

/*
// Idea: Divide & Conquer
//
// Divide:
// Split vector of buildings into left/right vectors
// that represent valid skyline (recursive)
//
// Conquer:
// Iterate over keypoints. If keypoint represents start of 
// building, insert building height and max valid coord (start + width) into queue.
//
// Also, check for each keypoint:
//   - If there exists a (valid) house that is greater, discard the keypoint
//   - If the greatest house ends at keypoint, then set y coordinate of keypoint
//     to the next greatest house
//
// Time:
//  T(n) = 2T(n/2) + O(nlog(n))
//  => Total time: O(nlog^2(n))
class Solution {

    public:
        vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
            vector<int> sol = divideConquer(buildings, 0, buildings.size()-1);
        }

        vector<vector<int>> divideConquer(int l, int r, vector<int>& buildings) {
            if (l == r) {
                int x1 = buildings[l][0];
                int x2 = buildings[l][1];
                int h = buildings[l][2];
                return {
                    {x1, h},
                    {x2, h}
                };
            } else {
                int m = l + (r - l) / 2;
                vector<vector<int>> kLeft = divideConquer(l, m, buildings);
                vector<vector<int>> kRight = divideConquer(m+1, r, buildings);
                return combine(kLeft, kRight, l, m, r, buildings);
            }
        }

        vector<vector<int>> combine(vector<vector<int>>& kLeft,
                vector<vector<int>>& kRight, int l, int m, int r, vector<int>& buildings) {

            vector<vector<int>> result;

            for (auto& e : kLeft) {
                

            }

            return result;
        }
};
*/

// Idea: Divide and conquer -> ACCEPTED
// Time complexity: O(nlog(n)) 
class Solution {
    public:
        vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
            return divideConquer(buildings, 0, buildings.size()-1);
        }

        vector<vector<int>> divideConquer(vector<vector<int>>& b, int l, int r) {
            // Return keypoint for current buliding which is
            // (left, height), (right, 0)
            if (l == r) {
                return {
                    {b[l][0], b[l][2]},
                    {b[l][1], 0} 
                };
            }

            int m = l + (r - l) / 2;

            auto lKey = divideConquer(b, l, m);
            auto rKey = divideConquer(b, m+1, r);
            auto comb = combine(lKey, rKey, l, m, r);

            return comb;
        }

        vector<vector<int>> combine(vector<vector<int>>& left,
                                    vector<vector<int>>& right,
                                    int l, int m, int r) {
            vector<vector<int>> output;


            const int lSize = left.size();
            const int rSize = right.size();

            int lPtr = 0;
            int rPtr = 0;

            int lHeight = 0;
            int rHeight = 0;

            while (lPtr < lSize || rPtr < rSize) {
                int prevHeight = output.size() == 0 ? -1 : output[output.size()-1][1];

                if (lPtr == lSize) {
                    if (right[rPtr][1] != prevHeight)
                        output.push_back(right[rPtr]);
                    rPtr++;
                    continue;
                } else if (rPtr == rSize) {
                    if (left[lPtr][1] != prevHeight)
                        output.push_back(left[lPtr]);

                    lPtr++;
                    continue;
                }


                // Left segment before right segment
                if (left[lPtr][0] < right[rPtr][0]) {
                    if (rHeight < left[lPtr][1]) {
                        output.push_back(left[lPtr]);
                    } else if (left[lPtr][1] != lHeight && rHeight != prevHeight) {
                        output.push_back({left[lPtr][0], rHeight});
                    }
                    lHeight = left[lPtr][1];
                    lPtr++;
                } else if (left[lPtr][0] > right[rPtr][0]) {
                    if (lHeight < right[rPtr][1] ) {
                        output.push_back(right[rPtr]);
                    } else if (right[rPtr][1] != rHeight && lHeight != prevHeight) {
                        output.push_back({right[rPtr][0], lHeight});
                    }
                    rHeight = right[rPtr][1];
                    rPtr++;
                } else {
                   if (left[lPtr][1] > right[rPtr][1]) {
                        if (left[lPtr][1] != prevHeight)
                        output.push_back(left[lPtr]);
                        lHeight = left[lPtr][1];

                        // Skip right point
                        lPtr++;
                   } else {
                        if (right[rPtr][1] != prevHeight)
                        output.push_back(right[rPtr]);
                        rHeight = right[rPtr][1];

                        rPtr++;
                   }
                }
            }

            return output;
        }
};


int main() {

    vector<vector<int>> b = {
        {1,4,3},
        {2,4,2},
        {4,5,4}
    };

    Solution solution{};
    auto s = solution.getSkyline(b);

    for (auto& p : s) {
        cout << p[0] << " " << p[1] << "\n";
    }
    return 0;
}
