#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

/*
    UNSOLVED!
*/

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

int main() {


    return 0;
}
