#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        
        long long n1 = num1;
        long long n2 = num2;
        
        for (int k = 0; k <= 60; ++k) {
            long long ta = n1 - k*n2;

            if (!(ta < 0 || __builtin_popcountll(ta) > k)) {
                if (ta == 0 && k > 0) {return -1;}
                long long highest = 60;
                while (highest >= 0 && (1LL << highest) & ta == 0) { highest--; break;}
                if ((1LL << highest) >= __builtin_popcountll(ta) && k <= ta) {return k;}
            }
        }

        return -1;
    }
};

int main() {
    Solution solution {};
    cout << solution.makeTheIntegerZero(85, 42) << "\n";
    return 0;
}
