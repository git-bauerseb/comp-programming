#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <bitset>

using namespace std;

// Constants
#define MOD 1'000'000'007

// Simple types
#define ll long long
#define ld long double

// Aggeragte types
#define pii pair<int,int>
#define pll pair<long,long>

#define vi vector<int>
#define vl vector<long>

#define si set<int>
#define sl set<long>

// Output
template <typename T>
void print_v(vector<T>& v) {cout << "{"; for (auto& x : v) cout << x << " "; cout << "\n";}

class Solution {

    public:
        int findTheWinner(int n, int k) {
            bitset<503> ingame;

            int rem = n-1;
            int start = 0;

            while (rem) {

                // Determine loser
                int inc = 1;
                int pos = start;
                while (inc < k) {
                    pos = (pos+1)%n;
                    while (ingame[pos]) {pos = (pos+1)%n;}
                    inc++;
                }


                rem--;
                ingame[pos] = 1;
                start = (pos+1)%n;
                while (ingame[start]) {start = (start+1)%n;}
            }

            for (int i = 0; i < n; ++i) if (!ingame[i]) return (i+1);

            return -1;

        }

};

int main() {

    Solution solution{};
    int w = solution.findTheWinner(293,258);
    cout << w << "\n";
	return 0;
}
