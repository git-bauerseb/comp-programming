#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

/*
class Solution {
    public:
        bool canIWin(int mC, int desired) {
            if (mC >= desired) return true;

            bitset<21> choosen;
            return rec(choosen, mC, desired, 0, 0) == 0; 
        }

        // desired - desired total sum
        // current - current sum
        // cPlayer - 0 = first player, 1 = second player
        // choosen - choosen[i] = 1 if number has been choosen
        // mC      - max. choosable number
        //
        // Returns 0 if first player can win, 1 otherwise
        int rec(bitset<21>& choosen, int mC, int desired, int current, int cPlayer) {
            if (current >= desired) return cPlayer == 0 ? 1 : 0;
            
            for (int i = mC; i >= 1; --i) {
                if (!choosen[i]) {
                    if (current + i >= desired) return cPlayer;    
                    choosen[i] = 1;
                    if (rec(choosen, mC, desired, current + i, cPlayer == 0 ? 1 : 0) == cPlayer)
                        return cPlayer;

                    choosen[i] = 0;
                }
            }

            return cPlayer == 0 ? 1 : 0;
        }
};
*/

#define SET(x, i) ((x) |= (1 << (i-1)))
#define UNSET(x, i) ((x) &= ~(1 << (i-1)))

#define IS_SET(x, i) (((x) & (1 << (i-1))) > 0)

class Solution {

    public:
        bool canIWin(int maxChoosableInteger, int desiredTotal) {
            // Edge cases
            if (maxChoosableInteger >= desiredTotal) return true;
            if (maxChoosableInteger*(maxChoosableInteger+1) / 2 < desiredTotal) return false;
            if (desiredTotal < 1) return true;

            m_memo.resize(1 << maxChoosableInteger, -1);
            return canWin(0, desiredTotal, maxChoosableInteger);
        }


        bool canWin(int mask, int rem, int mC) {
            int& entry = m_memo[mask];
            if (entry >= 0) return entry;

            int sCount = 0;
            for (int i = 1; i <= mC; ++i) {
                sCount += IS_SET(mask, i);
            }

            if (sCount == mC) {entry = 0; return false;}


            // Remaining amount has been taken by previous player
            if (rem <= 0) {entry = 0; return false;}

            // Check if a number can be choosen s.t. remaining amount <= number
            int n = -1;
            for (int num = mC; num >= 1; --num) {
                if (!IS_SET(mask, num)) {n = num; break;}
            }

            if (rem <= n) {entry = 1; return true;}

            // Check recursively if opponent looses when using some number
            for (int i = 1; i < mC; ++i) {
                if (!IS_SET(mask, i)) {
                    bool va = false;
                    SET(mask, i);
                    // Other player cannot win
                    va = canWin(mask, rem-i, mC);
                    UNSET(mask, i);
                    if (!va) {entry = 1; return true;}
                }
            }

            entry = 0;
            return false;
        }
        vector<int> m_memo;     // -1 - undefined, 0 - false, 1 - true
};

int main() {
    Solution solution{};
    bool first = solution.canIWin(10, 40);
    cout << first << "\n";
    return 0;
}
