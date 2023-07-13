#include <iostream>
#include <algorithm>
#include <cmath>


using namespace std;

#define EPS (1E-10)

class Solution {

    public:
        int maxPoints(vector<vector<int>>& points) {
            const int n = points.size();
    
            int res = 0;

            for (int i = 0; i < n; ++i) {
                // Number of points that lie on same vertical line
                int vert = 1;

                for (int j = 0; j < n; ++j) {
                    if (i == j) {
                        continue;
                    } if (points[j][0] == points[i][0]) {
                        vert++;
                        continue;
                    }
            

                    // Stupid mistake!
                    double m = static_cast<double>(points[j][1] - points[i][1]) / (points[j][0] - points[i][0]);
                    double b = points[i][1] - m * points[i][0];
            
                    int onLine = 2;

                    for (int k = 0; k < n; ++k) {
                        if (k == i || k == j) continue;
                        onLine += abs(m * points[k][0] + b - points[k][1]) < EPS;
                    }

                    res = max(res, onLine);
                }
                res = max(res, vert);
            }


            return res;
        }
};

int main() {

    vector<vector<int>> p{
        {-1,1}, {0,1}, {1,1},
        {-1,0}, {0,0}, {1,0},
        {-1,-1}, {0,-1}, {1,-1}
    };

    Solution solution{};
    int m = solution.maxPoints(p);
    cout << m << "\n";

    return 0;
}
