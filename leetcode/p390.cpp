#include <iostream>

using namespace std;

class Solution {

    public:

        // left function
        int left(int i, int n) {
            if (i == 0) {return 1;}

            int rightmost = right(i-1, n);

            int p = 1;
            for (int j = 0; j <= i; ++j) {p <<= 1;}

            int k = rightmost / p;
            return rightmost - k * p;
        }

        int right(int i, int n) {
            if (i == 0) {return n;}

            int leftmost = left(i-1, n);

            int p = 1;
            for (int j = 0; j <= i; ++j) {p <<= 1;}

            int k = (n- leftmost) / p;
            return leftmost +  k * p;
        }


};


int main() {

    Solution solution{};
    int r = solution.left(3, 9);
    cout << r << "\n";

    return 0;
}
