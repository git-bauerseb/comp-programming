#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> minReverseOperations(int n, int p, vector<int>& banned, int k) {
        sort(banned.begin(), banned.end());
        
        set<int> valid;
        vector<int> distance(n, 1e9);

        for (int i = 0; i < n; ++i) {
            if (!binary_search(banned.begin(), banned.end(), i)) {
                valid.insert(i);
            }
        }

        vector<int> visited(n, false);

        distance[p] = 0;
        queue<int> q;
        q.push(p);

        while (!q.empty()) {
            int t = q.front();
            visited[t] = true;
            q.pop();
            auto low = valid.lower_bound(t - (k-1));
            auto up = valid.upper_bound(t + (k-1));

            set<int> toerase;

            for (auto it = low; it != up; ++it) {

                if (!visited[*it]) {
                    // Check if able to move to position
                    int dist = abs(t - *it + 1);


                    if (dist % 2 == k % 2) {
                        if (dist+2 < k) {
                            int rem = (k - (dist+2)) / 2;
                        
                            if (*it - rem < 0 || t + rem > n-1
                                    || *it + rem > n-1 || t - rem < 0) {
                                continue;
                            }
                        }

                        if (distance[t] >= 0) {
                            distance[*it] = min(distance[*it], 1 + distance[t]);
                            toerase.insert(*it);
                            q.push(*it);
                        }
                    }
                }
            }

            erase_if(valid, [&](int el) {return toerase.contains(el);});
        }

        for (auto& e : distance) e = e == 1e9 ? -1 : e;

        return distance;
    }
};

int main () {
    vector<int> banned{2,4};
    Solution solution{};
    auto r = solution.minReverseOperations(5, 0, banned, 3);
    
    for (auto& e : r) {cout << e << " ";}
    cout << "\n";
    
    return 0;
}
