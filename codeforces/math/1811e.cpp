#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

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

/*
const int N_MAX = 20;

// dp[i][c][t]
// i - suffix of length i
// c - c=0 -> count how many numbers don't contain digit 4
//     c=1 -> count how many numbers contain digit 4
// t - t=0 -> suffix unbounded
//     t=1 -> suffix bounded
ll dp[N_MAX][2][2];

// 4, 14, 24, 34, 44, 54, 64, 74, 84, 94, 41, 42, 43, 45, 46, 47, 48, 49
void solution() {
    ll k; cin >> k;
    string ks = to_string(k);
    const int n = ks.size();

    // Base case

    // There is exactly 1 empty suffix that does not contain digit 4
    dp[n][0][0] = dp[n][0][1] = 1;

    for (int i = n-1; i >= 0; --i) {
        // Update numbers that don't contain digit 4
        // Digits 0,1,2,3,5,6,7,8,9 contribute
        dp[i][0][0] = 9*dp[i+1][0][0];

        for (char c = '0'; c < ks[i]; ++c) {
            dp[i][0][1] += dp[i+1][0][0];
        }
        
        dp[i][0][1] += dp[i+1][0][1];


        // Update numbers that contain digit 4
        // Either
        //  - previous number already contains 4 (dp[i+1][1][0])
        //  - then all digits 0,...,9 can be used -> 10 choices
        // Or
        //  - previous number does not contain digit 4
        //  - then digit 4 must be used here -> 1 choice
        dp[i][1][0] = 10*dp[i+1][1][0] + dp[i+1][0][0];
        for (int d = 0; d <= ks[i]-'0'; ++d) {
            if (d == ks[i]-'0') {
                dp[i][1][1] += dp[i+1][1][1];
                if (d == 4)
                    dp[i][1][1] += dp[i+1][0][1];
            } else {
                dp[i][1][1] += dp[i+1][1][0];
            }
        }



    }


    ll res = dp[0][1][1];
    cout << res << "\n";
}
*/

ll dp[20][2][2];

// Transitions
//
//  Unbounded, no digit 4
//      - can choose 9 digits (excluding 4)
//      => dp[i][0][0] = 9 * dp[i+1][0][0]
//
//  Unbounded, digit 4
//      - can either have no 4 and current is 4 or have four and choose arbitrary
//      => dp[i][1][0] = 10 * dp[i+1][1][0] + dp[i+1][0][0]
//
//  Bounded, no digit 4
//      - can choose all digits < current digit + unbounded no digit 4
//        AND choose current digit (excluding 4) + bounded no digit 4
//      => dp[i][0][1] = sum_{d < cur. digit, not equal 4} dp[i+1][0][0]
//                     + if{cur. digit != 4} dp[i+1][0][1]
//
//  Bounded, digit 4
//      - can choose all digits < current digit + unbounded digit 4
//        AND choose current digit + bounded no-digit 4
//      => dp[i][1][1] = sum_{d < cur. digit} dp[i+1][0][0]
//          + {cur. digit} dp[i+1][0][1]
void solution() {
    ll k; cin >> k;
    string ks = to_string(k);

    const int n = ks.size();

    // Base case
    dp[n][0][0] = dp[n][0][1] = 1;

    for (int i = n-1; i >= 0; --i) {
        dp[i][0][0] = 9*dp[i+1][0][0];
        dp[i][1][0] = 10*dp[i+1][1][0] + dp[i+1][0][0];

        int cDigit = ks[i]-'0';

        for (int d = 0; d < cDigit; ++d) {
            if (d != 4)
                dp[i][0][1] += dp[i+1][0][0];
        }

        if (cDigit != 4)
           dp[i][0][1] += dp[i+1][0][1]; 

        for (int d = 0; d < cDigit; ++d) {
            dp[i][1][1] += dp[i+1][0][0];
        }

        dp[i][1][1] += dp[i+1][0][1];
    }


    cout << dp[1][1][0] << "\n";
}


int main() {
    solution();
    return 0;
}
