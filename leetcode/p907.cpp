#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1'000'000'007;

class Solution {

    public:
        int sumSubarrayMins(vector<int>& a) {
            const int n = a.size();

            vector<int> ms;

            // Result
            long long r = 0;

            // Sum of minima of subarrays before current element
            long long prefix = 0;

            for (int i = 0; i < n; ++i) {

                while (ms.size() > 0 && a[ms[ms.size()-1]] > a[i]) {
                    int t = ms[ms.size()-1];
                    int occ = ms.size() == 1 ? t+1 : (ms[ms.size()-1] - ms[ms.size()-2]);
                    prefix -= occ*a[t];
                    ms.pop_back();
                }

                int add = (ms.size() == 0) ? (i+1) : (i - ms[ms.size()-1]);
                prefix = (add * a[i] + prefix) % MOD;

                ms.push_back(i);
                r = (r + prefix) % MOD;
            }

            return r;
        }
};

int main() {

    vector<int> a{11};

    Solution solution{};
    int r = solution.sumSubarrayMins(a);
    cout << r << "\n";

    return 0;
}
