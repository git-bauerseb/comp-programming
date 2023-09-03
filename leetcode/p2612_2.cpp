#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> minReverseOperations(int n, int p, vector<int>& banned, int k) {
        vector<bool> valid(n, true);
        for (int i = 0; i < banned.size(); ++i) {
            valid[banned[i]] = false;
        }

        set<int> odd;
        set<int> even;

        for (int i = 0; i < n; ++i) {
            if (valid[i]) {
                if (i % 2 == 0) {even.insert(i);}
                else {odd.insert(i);}
            }
        }

        vector<bool> visited(n, false);
        vector<int> distance(n, -1);
        
        queue<int> q;
        q.push(p);
        distance[p] = 0;

        map<int,int> toerase;

        while (!q.empty()) {
            int curr = q.front();
            visited[curr] = true;
            q.pop();

            // If k even => parity changes
            // If k odd => parity remains the same
            set<int> idxSet;

            if (k % 2 == 0) {
                idxSet = (curr % 2 == 1) ? move(even) : move(odd);
            } else {
                idxSet = (curr % 2 == 1) ? move(odd) : move(even);
            }

            toerase.clear();

            auto low = idxSet.lower_bound(curr - (k-1));
            auto upp = idxSet.upper_bound(curr + (k-1));

            for (auto it = low; it != upp; ++it) {
                
                if (visited[*it]) {continue;}

                int s = min(*it, curr);
                int l = max(*it, curr);
                
                int dist = l - s - 1;
                int ext = (k - (dist+2)) / 2;

                if (ext <= 0 || !(s - ext < 0 || l + ext > n-1) && distance[curr] != -1) {
                    distance[*it] = 1 + distance[curr];
                    q.push(*it);
                    toerase[*it] = 1;
                }
            }

            for (auto& [key,value] : toerase) {
                idxSet.erase(key);
            }

            if (k % 2 == 0) {
                if (curr % 2 == 1) {
                    even = move(idxSet);
                } else {
                    odd = move(idxSet);
                }
            } else {
                if (curr % 2 == 1) {
                    odd = move(idxSet);
                } else {
                    even = move(idxSet);
                }
            }
        }

        return distance;
    }
};

int main() {
    vector<int> banned{};
    Solution s{};
    auto r = s.minReverseOperations(10, 4, banned, 3);
    for (auto& e : r) cout << e << " ";
    cout << "\n";
    return 0;
}
