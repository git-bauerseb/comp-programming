#include <iostream>
#include <queue>
#include <map>
#include <vector>

using namespace std;

struct Comparator {
    bool operator()(const pair<int,int>& a, const pair<int,int>& b) {
        return a.second > b.second;
    }
};

class Solution {
    public:
        int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
            const int n = arr.size();

            map<int,int> unique;
            priority_queue<pair<int,int>, vector<pair<int,int>>,
                        Comparator> pq;

            for (int i = 0; i < n; ++i) {unique[arr[i]]++;}

            for (auto& [key, value] : unique) {
                pq.push({key, value});
            }

            while (k--) {
                auto t = pq.top();

                if (t.second == 1) {
                    pq.pop();
                } else {
                    pq.pop();
                    pq.push({t.first, t.second-1});
                }
            }

            return pq.size();
        }
};

int main() {
    vector<int> n{5,5,4};
    Solution solution{};
    int r = solution.findLeastNumOfUniqueInts(n,1);
    cout << r << "\n";
    return 0;
}
