#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <algorithm>
#include <string>
#include <utility>

using namespace std;

/*
class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        const int s1Len = s1.size();
        const int s2Len = s2.size();

        map<pair<int,int>, int> occ;


        if (n1 == 1) {
            int matches = 0;
            int idx = 0;

            for (int i = 0; i < s1Len; ++i) {
                if (s1[i] == s2[idx]) {matches++; idx++; idx %= s2Len;}
            }

            return matches / (s2Len * n2);
        }


        int idx = 0;
        int s2IdxStart = 0;
        int s2IdxCurr = 0;

        int cycleS = -1;
        int cycleE = -1;

        // Length of one cycle in number of s1 words
        int cycleLen = -1;

        // Matches of s2 per cycle
        int mPerCycle = 0;

        int matched = 0;

        int s1Start = 0;
        int s1End = 0;

        while (idx < n1) {
            s1Start = 0;
            s1End = 0;

            int matchPerS1 = 0;

            for (int i = 0; i < s1Len; ++i) {
                if (s1[i] == s2[s2IdxCurr]) {                    
                    
                    if (matchPerS1 == 0) {
                        s1Start = i;
                    }
                    
                    s1End = i;

                    s2IdxCurr++;
                    s2IdxCurr %= s2Len;
                    matched++;
                    matchPerS1++;
                }
            }

            if (occ.count({s1Start, s1End}) > 0) {
                cycleS = occ[{s1Start, s1End}];
                cycleE = idx;

                cycleLen = cycleE - cycleS;

                
                if (cycleLen > 1) {
                    mPerCycle = (cycleLen - 1) * (s2Len - matchPerS1);
                }

                mPerCycle += matchPerS1;


                break;
            }

            occ[{s1Start, s1End}] = idx;
            idx++;
            s2IdxStart = s2IdxCurr;
        }

        if (cycleLen < 1) {
            return matched / (s2Len * n2);
        }



        int begCycle = occ[{s1Start, s1End}] + 1;
        int totalCycles = (n1-begCycle) / cycleLen;
        int remBlock = (n1 - begCycle) % cycleLen;

        
        // printf("Begin of cycle: %d\n", begCycle);
        // printf("Matches per cycle: %d\n", mPerCycle);
        // printf("Total cycles: %d\n", totalCycles);

        // Calculate how many characters are matched before cycle
        int before = 0;
        int bIdx = 0;

        for (int i = 0; i < begCycle; ++i) {
            for (int j = 0; j < s1Len; ++j) {
                if (s1[j] == s2[bIdx]) {
                    before++;
                    bIdx++;
                    bIdx %= s2Len;
                }
            }
        }

        // printf("Before: %d\n", before);


        // Calculate how many characters are matched after cycle
        int after = 0;
        int aIdx = (s2IdxCurr) % s2Len;

        for (int i = 0; i < remBlock; ++i) {
            for (int j = 0; j < s1Len; ++j) {
                if (s1[j] == s2[aIdx]) {
                    after++;
                    aIdx++;
                    aIdx %= s2Len;
                }
            }
        }

        // printf("After: %d\n", after);

        int total = before + totalCycles * mPerCycle + after;
        // printf("Total: %d\n", total);
        int m = total / (s2Len * n2);

        return m;
    }
};
*/

/*
// Brute Force
// Time: O(n1 * sizeof(s1))
class Solution {
    public:
        int getMaxRepetitions(string s1, int n1, string s2, int n2) {
            const int s1Len = s1.size();
            const int s2Len = s2.size();

            int rep = 0;
            int cIdx = 0;

            for (int i = 0; i < n1; ++i) {
                for (int j = 0; j < s1Len; ++j) {
                    if (s1[j] == s2[cIdx]) {
                        rep += cIdx == (s2Len-1);
                        cIdx++;
                        cIdx %= s2Len;
                    }
                }
            }

            return rep / n2;
        }
};
*/

// s1, s2 given
//
// S1 = [s1, n1]
// S2 = [s2, n2]
//
//
// Time complexity: O(size(s1) * size(s2))

int indexr[101];
int countr[101];


class Solution {
    public:
        int getMaxRepetitions(string s1, int n1, string s2, int n2) {
            const int s1Len = s1.size();
            const int s2Len = s2.size();

            // Index in s2 at start of each s1 block
            memset(indexr, sizeof(indexr), 0);

            // Count (number of repetitions of s2) at start of each s1 block
            memset(countr, sizeof(countr), 0);


            // Current index in s2
            int index = 0;

            // Number of times s2 appeared in S1
            int repeat_count = 0;

            for (int i = 0; i < n1; ++i) {

                for (int j = 0; j < s1Len; ++j) {

                    if (s1[j] == s2[index]) {
                        index++;
                    }

                    if (index == s2Len) {
                        repeat_count++;
                        index = 0;
                    }

                }

                countr[i] = repeat_count;
                indexr[i] = index;

                for (int k = 0; k < i; ++k) {

                    // Found an s1 block that ends with the same index in s2 as current
                    // block.
                    // => Next block (i+1) and (k+1) are the same again because they start
                    // with same index in s2.
                    if (index == indexr[k]) {

                        int prev_count = countr[k];

                        // Initialy: Error in division => Parantheses are necessary
                        int pattern_count = (countr[i] - countr[k]) * ((n1 - 1 - k) / (i - k));
                        int remain_count = countr[k + (n1 - 1 - k) % (i - k)] - countr[k];

                        int total = (prev_count + pattern_count + remain_count);
                        return total / n2;
                    }

                }
            }

            return countr[n1-1] / n2;
        }
};




// baaba baaba baaba
//     ^ ^ ^^^ ^ ^^^
//
// ab ab ab
int main() {
    Solution s{};
    cout << s.getMaxRepetitions("aaa", 20, "aaaaa", 1) << "\n";
    return 0;
}
