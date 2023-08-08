/*
    Meet in the middle

    1) Split array into two halfes
    2) Compute, for each half, all possible sums (2^(n/2) many sums; possible duplicates)
    3) Sort second array of sums
    4) For each sum in first, search for second sum s.t. difference is minimal
       and all elements are choosen

    Time complexity: O(2^(n/2) + 2^(n/2)*log(2^(n/2)) = O(2^(n/2) + n*2^(n/2)) = O(n2^(n/2))
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1'000'000'007;

/*
class Solution {

    vector<long long> factorial;
    vector<long long> inv_factorial;

    public:

        long long binpow(long long a, long long b) {
            long long res = 1;
            while (b > 0) {
                if (b & 1) res = (res * a) % MOD;
                a = (a * a) % MOD;
                b >>= 1;
            }
            return res;
        }

        long long inverse(long long number) {
            return binpow(number, MOD-2);
        }

        long long binom(int n, int k) {
            return factorial[n] * inv_factorial[k] % MOD * inv_factorial[n-k] % MOD;
        }

        int minimumDifference(vector<int>& nums) {
            factorial.resize(128);
            inv_factorial.resize(128);
            
            factorial[0] = 1;
            for (int i = 1; i < 128; ++i) {
                factorial[i] = factorial[i-1] * (long long)i % MOD;
                inv_factorial[i] = inverse(factorial[i]) % MOD;
            }

            
            const int n = nums.size();

            int tSum = 0;
            for (int i = 0; i < n; ++i) {tSum += nums[i];}

            vector<pair<int,int>> first(1 << (n/2));
            vector<pair<int,int>> second(1 << (n/2));

            for (int i = 0; i < (1 << (n/2)); ++i) {
 
                // Bits of i <=> Elements selected               
                int fSum = 0;
                int sSum = 0;
        
                int idx = 0;
                int bSet = 0;

                while ((1 << idx) <= i) {

                    if ((1 << idx) & i) {
                        fSum += nums[idx];
                        sSum += nums[idx + (n/2)];
                        bSet++;
                    }

                    ++idx;
                }

                first[i] = {bSet, fSum};
                second[i] = {bSet, sSum};
            }


            // Sort first by bits set then by sum
            sort(second.begin(), second.end(), 
                    [&](const pair<int,int>& a, const pair<int,int>& b) {
                if (a.first != b.first) return a.first < b.first;
                return a.second < b.second;
            });


            int mDiff = 300'000'000;
            
            for (int i = 0; i < (1 << (n/2)); ++i) {
                int v = first[i].second;
                int bSet = first[i].first;


                // Need find arrays that have (n/2 - bSet) bits set
                // Points to first element >= bits set
                auto it = lower_bound(second.begin(), second.end(), -1, 
                            [&](const pair<int,int>& element, int value) {
                                return element.first < (n/2) - bSet;
                            }
                        );


                // Now find most similar set among all sets which have (n/2) - bSet
                // bits set
                auto uBound = it + binom(n/2, n/2 - bSet);

                // s < tSum/2 - v
                auto it2 = lower_bound(it, uBound, -1,
                        [&](const pair<int,int>& element, int value) {
                            return element.second < tSum/2 - v;
                        });

                int cSum = 0;

                if (it2 >= second.end()) {
                    cSum = (--it2)->second + v;
                } else {
                    cSum = it2->second + v;
                }

                mDiff = min(mDiff, abs(cSum - tSum/2));
            }
            

            return mDiff;
        }
};
*/

int main() {

    vector<int> nums{91,14,16,82,32,2,38,94};

    Solution solution{};
    int d = solution.minimumDifference(nums);
    cout << d << "\n";

    return 0;
}
