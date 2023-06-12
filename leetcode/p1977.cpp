#include <iostream>
#include <vector>
#include <string>

using namespace std;

// CURRENTLY UNSOLVED!
class Solution {
    public:
        int numberOfCombinations(string num) {
            m_num = num;

            return 0;
        }

        // j: index where split occurs
        //      0, ..., j-1 is left side
        //      j, ..., n-1 is right side
        //
        // i: index of last split in left part
        //  => last number in left is i, ..., j-1
        int solution(int i, int j) {
            // No leading '0' allowed
            if (m_num[i] == '0' || m_num[j] == '0') return 0;


            int lLen = j-i;
    

        }

    private:
        string& m_num;
};


int main() {

    Solution solution{};
    int comb = solution.numberOfCombinations("327");
    cout << comb << "\n";

    return 0;
}
