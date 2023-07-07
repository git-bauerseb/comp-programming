#include <iostream>
#include <vector>

#include <cassert>

#define next_iter continue

using namespace std;

class Solution {

    public:
        vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
            return divConquer(buildings, 0, buildings.size()-1);
        }

    private:
        vector<vector<int>> divConquer(vector<vector<int>>& b, int l, int r) {
            if (l == r) {
                return {{b[l][0], b[l][2]}, {b[l][1], 0}};
            }
            int m = l + (r - l) / 2;
            auto left = divConquer(b, l, m);
            auto right = divConquer(b, m+1, r);
            return combine(left, right);
        }

        vector<vector<int>> combine(vector<vector<int>>& left, vector<vector<int>>& right) {
            const int lSize = left.size();
            const int rSize = right.size();

            int lEnd = 0;
            int rEnd = 0;


            vector<vector<int>> output;

            // Invariant: Pointing to first left keypoint not processed currently
            int lPtr = 0;

            // Invariant: Pointing to first right keypoint not processed currently
            int rPtr = 0;

            // Invariant: Height of last left keypoint that was processed
            int lHeight = 0;

            // Invariant: Height of last right keypoint that was processed
            int rHeight = 0;


            // Loop invariant: Overall, lPtr + rPtr keypoints have been correctly processed
            // => at the end: lPtr+rPtr = lSize + rSize = all keypoints
            while (lPtr < lSize || rPtr < rSize) {

                // Height of previous point added to output. If there is none,
                // then it's -1. A comparison > prevHeight always is true, even if
                // no point was there.
                int prevHeight = output.size() == 0 ? -1 : output[output.size()-1][1];


                // If there are only left keypoints, add them to output
                // Keypoints are sorted by x-coordinate
                // => This will only be executed at most once
                if (rPtr == rSize) {
                    // We can simply push points from the left because left represents
                    // the keypoints of a valid skyline, so no two adjacent keypoints
                    // have the same height or are invalid in any other way.
                    //
                    // The only thing to be careful, is if a point with same y coordinate
                    // already exists.
                    if (prevHeight != left[lPtr][1]) {
                        output.push_back(left[lPtr]);
                    }
 
                    lPtr++;
                    next_iter;
                }

                // Symmetry: If there are only right keypoints left, add them
                if (lPtr == lSize) {
                    if (prevHeight != right[rPtr][1]) {
                        output.push_back(right[rPtr]);
                    }
                    
                    rPtr++;
                    next_iter;
                }

                
                // Now, both left/right contain keypoints. There are 3 cases to consider:
                //
                // i) Next left keypoint < Next right keypoint
                // ii) Symmetry to case i)
                // iii) Both, the next left/right keypoint start at same position
                

                // Case i: Left keypoint is before next right keypoint
                if (left[lPtr][0] < right[rPtr][0]) {


                    // The current point would always be pushed to the output vector
                    // if we only have the left keypoints, because those represent a valid
                    // skyline.
                    //
                    // The only problem is if we have a segment of the right skyline that
                    // shadows our point.
                    //
                    // So if our point is > than the right segment, definitely add it to the
                    // output.
                    if (left[lPtr][1] > rHeight) {
                        output.push_back(left[lPtr]);
                    }
                    // Here, our left point is shadowed by the right point, i.e.
                    // left[lPtr][1] <= rHeight.
                    //
                    // But we cannot simply discard the point, because it could be that
                    // the right segment is greater than current point but less than the
                    // height of a previous left point.
                    //
                    //      |-------|    <- lHeight
                    //      |       |
                    // ----------------  <- rHeight
                    //      |       |
                    //              o------
                    //              ^
                    //              current point we consider
                    //
                    else if (rHeight < lHeight && rHeight != prevHeight) {
                        output.push_back({left[lPtr][0], rHeight});
                    }

                    lHeight = left[lPtr][1];
                    lPtr++;
                    next_iter;
                }

                // Symmetric case to Case i
                // Just invert roles of left/right
                if (right[rPtr][0] < left[lPtr][0]) {                   
                    if (right[rPtr][1] > lHeight) {
                        output.push_back(right[rPtr]);
                    } else if (rHeight > lHeight && lHeight != prevHeight) {
                        output.push_back({right[rPtr][0], lHeight});
                    }

                    rHeight = right[rPtr][1];
                    rPtr++;
                    next_iter;
                }


                
                // Case iii): Both left/right point have same x coordinate,
                // so choose point with higher y coordinate
                if (left[lPtr][1] > right[rPtr][1]) {
                    if (prevHeight != left[lPtr][1]) {
                        output.push_back(left[lPtr]);
                    }
                    lHeight = left[lPtr][1];
                    lPtr++;
                } else {
                    if (prevHeight != right[rPtr][1]) {
                        output.push_back(right[rPtr]);
                    }


                    rHeight = right[rPtr][1];
                    rPtr++;
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
