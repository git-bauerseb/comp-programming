#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int dp[502][502];

class Solution {
    public:
        bool stoneGame(vector<int>& piles) {
            int total = 0;
            for (auto& e : piles) total += e;
            memset(dp, -1, sizeof(dp)); 
            return rec(piles, 0, piles.size() - 1) >= ((total+1)/2);
        }

        int rec(vector<int>& numbers, int i, int j) {
            if (i >= numbers.size() || j < 0 || i > j) {return 0;}
            int& entry = dp[i][j];
            if (entry >= 0) return entry;
            if (i == j) {entry = numbers[i]; return entry;}

            // Take pile i and enemy takes either pile i+1 or pile j
            //  => Enemy takes pile s.t. sum is minimum for player
            entry = max(
                    numbers[i] + min(rec(numbers, i+2, j), rec(numbers, i+1, j-1)),
                    numbers[j] + min(rec(numbers, i+1, j-1), rec(numbers, i, j-2))
                   );
            return entry;
        }
};

int main() {
    vector<int> numbers{5,100,3,4,6};
    Solution solution{};
    bool can = solution.stoneGame(numbers);
    cout << can << "\n";
    return 0;
}
