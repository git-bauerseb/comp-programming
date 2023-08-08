#include <iostream>
#include <vector>

using namespace std;

class Solution {

    public:
        vector<int> constructArray(int n, int k) {
            vector<int> res(n);
            int rem = k;

            for (int i = 0; i < n - rem; ++i) {
                res[i] = i+1;
            }

            int l = n;
            int r = n - rem + 1;


            for (int i = n - rem; i <= n+1; i += 2) {
                if (i < n)
                res[i] = l;
                if (i+1 < n)
                res[i+1] = r;
                l--;
                r++;
            }

            return res;
        }
};

int main() {


    for (int i = 1; i < 6; ++i) {
    Solution solution {};
    auto r = solution.constructArray(6, i);


    for (auto& e : r) cout << e << " ";
    cout << "\n";
    }

    return 0;
}
