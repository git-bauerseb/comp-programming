#include <iostream>
using namespace std;

class Solution {
    public:
        int lastRemaining(int n) {
         
            bool forward = true;

            int f = 1;
            int step = 1;

            // Remaining number of elements 
            int remaining = n;

            while (remaining > 1) {
                if (forward || (remaining % 2) == 1)
                    f += step;

                step <<= 1;
                remaining /= 2;
                forward = !forward;
            }

            return f;
        }
};

int main() {

    Solution solution{};
    int l = solution.lastRemaining(3453590);
    cout << l << "\n";

    return 0;
}
