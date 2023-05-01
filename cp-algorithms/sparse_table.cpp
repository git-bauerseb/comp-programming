#include <iostream>
#include <vector>

using namespace std;

const int K = 20;
const int N_MAX = 100;

int R[K+1][N_MAX];

// Time complexity: O(n log n)
void preprocess(vector<int>& numbers) {
    const int n = numbers.size();
    std::copy(numbers.begin(), numbers.end(), R[0]);
    
    for (int i = 1; i <= K; ++i) {
        for (int j = 0; j + (1 << i) <= n; ++j) {
            R[i][j] = R[i-1][j] + R[i-1][j + (1 << (i-1))];
        }
    }
}

// Range Sum Query
// Compute the sum in the range [l,r] (inclusive).
// No overlap of subarrays must be guaranteed to not count elements twice.
//
// Time complexity: O(log n)
int rsq(int l, int r) {
    int sum = 0;
    for (int i = K; i >= 0; --i) {
        if ((1 << i) <= r - l + 1) {
            sum += R[i][l];
            l += 1 << i;
        }
    }
    return sum;
}

int main() {

    vector<int> numbers{1,2,3,4,5,6,7,8,9,10};
    preprocess(numbers);

    cout << rsq(3,7) << "\n"; // 4 + 5 + 6 + 7 + 8 = 30

    return 0;
}
