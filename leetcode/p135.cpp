#include <iostream>
#include <vector>

using namespace std;

class Solution {

    public:
        int candy(vector<int>& ratings) {
            const int n = ratings.size();
            vector<int> c(n, 1);

            int res = n;

            for (int i = 1; i < n; ++i) {
                if (ratings[i] < ratings[i-1] && c[i-1] <= c[i]) {
                    res += (c[i]-c[i-1]+1);
                    c[i-1] = c[i]+1;
                } else if (ratings[i] > ratings[i-1] && c[i] <= c[i-1]) {
                    res += (c[i-1]-c[i]+1);
                    c[i] = c[i-1]+1;
                }
            }

            for (int i = n-2; i >= 0; --i) {
                if (ratings[i] < ratings[i+1] && c[i+1] <= c[i]) {
                    res += (c[i]-c[i+1]+1);
                    c[i+1] = c[i]+1;
                } else if (ratings[i] > ratings[i+1] && c[i] <= c[i+1]) {
                    res += (c[i+1]-c[i]+1);
                    c[i] = c[i+1]+1;
                }
            }

            for (auto& e : c) cout << e << " ";
            cout << "\n";

            return res;
        }
};

int main() {

    vector<int> nums{1,2,3,4,3,2,1};
    Solution solution{};
    int c = solution.candy(nums);

    cout << c << "\n";

    return 0;
}
