#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <unordered_map>

using namespace std;

const int MOD = 100'103;
int parent[MOD+1];
int dsu_size[MOD+1];


// For large numbers
void make_set(int v) {dsu_size[v] = 1; parent[v] = v;}

int find_set(int v) {
    if (parent[v] < 0) return -1;
    if (v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (dsu_size[a] < dsu_size[b])
            swap(a,b);
        parent[b] = a;
        dsu_size[a] += dsu_size[b];
    }
}


class Solution {

    public:
        int longestConsecutive(vector<int>& nums) {
            int mLen = -1;
            memset(parent, -1, sizeof(parent));
            memset(dsu_size, 0, sizeof(dsu_size));

            // Map number to index
            unordered_map<int,int> index;

            for (int i = 0; i < nums.size(); ++i) make_set(i);

            for (int i = 0; i < nums.size(); ++i) {
                if (index.find(nums[i]) != index.end()) continue;
                if (index.find(nums[i]-1) != index.end()) {
                    union_sets(index[nums[i]-1], i);
                }
                if (index.find(nums[i]+1) != index.end()) {
                    union_sets(index[nums[i]+1], i);
                }

                index[nums[i]] = i;
                mLen = max(mLen, dsu_size[find_set(i)]);
            }


            return max(0,mLen);
        }
};

int main() {

    vector<int> nums{9,1,4,7,3,-1,0,5,8,-1,6};
    Solution solution{};
    int l = solution.longestConsecutive(nums);
    cout << l << "\n";
    return 0;
}
