#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

/*

   List 1: length n
   List 2: length m

   Consider bit i
    k: number of times bit i is set in list 1
    l: number of times bit i is set in list 2

    Bit i only stays on, if two numbers where bit i is set are ANDed
    => there are k*l such numbers

    In the end, if bit i XORed even number of times, then in the end it is turned off.

    => Bit i only set at end iff k*l is odd.

    1 = 1000
    2 = 0100
    3 = 1010

    5 = 1001
    6 = 0101
*/
class Solution {

    int bS1[32];
    int bS2[32];

    public:
        int getXORSum(vector<int>& a1, vector<int>& a2) {
            memset(bS1, 0, sizeof(bS1));
            memset(bS2, 0, sizeof(bS2));

            for (int i = 0; i < a1.size(); ++i) {
                int idx = 0;
                while ((1LL << idx) <= a1[i]) {
                    bS1[idx] += ((1LL << idx) & a1[i]) > 0 ? 1 : 0;
                    idx++;
                }
            }

            for (int i = 0; i < a2.size(); ++i) {
                int idx = 0;
                while ((1LL << idx) <= a2[i]) {
                    bS2[idx] += ((1LL << idx) & a2[i]) > 0 ? 1 : 0;
                    idx++;
                }
            }
            int r = 0;
            for (int i = 0; i < 32; ++i) {
                 if ((static_cast<long long>(bS1[i]) * static_cast<long long>(bS2[i])) % 2 == 1) {
                    r |= (1 << i);
                }
            }
            return r;
        }
};

int main() {

    vector<int> a{4};
    vector<int> b{12};

    Solution solution{};
    int r = solution.getXORSum(a,b);
    cout << r << "\n";

    return 0;
}
