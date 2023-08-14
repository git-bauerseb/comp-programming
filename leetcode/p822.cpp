#include <iostream>

#include <vector>
#include <set>

using namespace std;

class Solution {
    public:
        int flipgame(vector<int>& fronts, vector<int>& backs) {
            const int n = fronts.size();

            set<int> valid;
            set<int> invalid;

            for (int i = 0; i < n; ++i) {
                if (fronts[i] != backs[i]) {
                    if (invalid.find(fronts[i]) == invalid.end()) {
                        valid.insert(fronts[i]);
                    }
                    if (invalid.find(backs[i]) == invalid.end()) {
                        valid.insert(backs[i]);
                    }
                } else {
                    valid.erase(fronts[i]);
                    invalid.insert(fronts[i]);
                }
            }

            int m = 1e9;

            for (auto& e : valid) m = min(e, m);

            if (m == 1e9) {return -1;}
            else {return m;}
        }
};
