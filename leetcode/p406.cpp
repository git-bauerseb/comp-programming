#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
        vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
            sort(people.begin(), people.end(),
                    [&](const vector<int>& first, const vector<int>& second) {
                if (first[0] != second[0]) return first[0] < second[0];
                return first[1] < second[1];         
            });

            const int n = people.size();

            vector<vector<int>> result(n, vector<int>(2,-1));

            for (int i = 0; i < n; ++i) {
                auto curr = people[i];

                int height = curr[0];
                int prev = curr[1];

                // Number of occupied spots before index curr where
                // the person is shorter.
                // We need to skip that many empty spots to ensure that
                // current person is correctly inserted.
                int occ = 0;
                for (int j = 0; j <= prev; ++j) {
                    if (result[j][0] >= 0 && result[j][0] < height) occ++;
                }

                int idx = prev;
                while (occ > 0) {
                    idx++;
                    if (result[idx][0] < 0 || result[idx][0] >= height) occ--;
                } 

                result[idx][0] = height;
                result[idx][1] = prev;
            }

            return result;
        }
};

int main() {

    vector<vector<int>> p = {
        {6,0}, {5,0}, {4,0}, {3,2}, {2,2}, {1,4}
        // {7,0}, {4,4}, {7,1}, {5,0}, {6,1}, {5,2}
    };

    Solution solution{};
    auto r = solution.reconstructQueue(p);

    for (auto& e : r) printf("(%d,%d)\n", e[0], e[1]);

    return 0;
}
