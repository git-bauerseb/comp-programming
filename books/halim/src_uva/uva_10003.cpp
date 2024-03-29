#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <bitset>
#include <map>

// For memset
#include <cstring>

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

// Greedy approach to UVa 10003
// Does not work -> gives not optimal solution
void solution1() {
    while (true) {
        int l; cin >> l;
        if (!l) break;

        int cuts; cin >> cuts;
        vi c(cuts); for (int i = 0; i < cuts; ++i) cin >> c[i];

        set<pair<int,int>> segments;
        segments.insert({0,l});
        int cost = 0;

        while (!c.empty()) {
            int bestC = -1;
            int minDiff = 1E8;
            int start = -1;
            int end = -1;
            int cPos = -1;
            for (auto& s : segments) {
                for (int i = 0; i < c.size(); ++i) {
                    // Can cut
                    if (c[i] > s.first && c[i] < s.second) {
                        int diff = abs(abs(c[i] - s.first) - abs(s.second - c[i]));
                        if (diff < minDiff) {
                            bestC = i;
                            minDiff = diff;
                            start = s.first;
                            end = s.second;
                            cPos = c[i];
                        }
                    }
                }
            }

            cost += end - start;
            c.erase(c.begin()+bestC);
            segments.erase({start, end});
            segments.insert({start, cPos});
            segments.insert({cPos, end});
        }

        cout << cost << "\n";
    }
}


int solution2rec(vector<int>& cuts, bitset<51>& bs, int left, int right) {
    int mCost = 1E9;
    bool performed = false;

    for (int i = 0; i < cuts.size(); ++i) {
        if (!bs[i]) {
            // Perform cut
            if (cuts[i] > left && cuts[i] < right) {
                bs[i] = 1;
                int lS = solution2rec(cuts, bs, left, cuts[i]);
                int rS = solution2rec(cuts, bs, cuts[i], right);
                mCost = min(mCost, lS + rS + right - left); 
                performed = true;
                bs[i] = 0;
            }
        }
    }

    // Cost is 0 if no cut was performed
    if (performed) return mCost;
    else return 0;
}

// Uses recursive backtracking to try every possible comibination of cuts
// => Too slow as it grows in O(|Cuts|!)
void solution2() {
    while (true) {
        int n; cin >> n;
        if (!n) break;
        int c; cin >> c;
        vi cuts(c);
        for (int i = 0; i < c; ++i) cin >> cuts[i];
        bitset<51> s;
        cout << solution2rec(cuts, s, 0, n) << "\n"; 
    }
}

// Top Down DP solution
// Idea:
//   - cut2(left, right) -> compute minimum cost for cutting stick s[left], ..., s[right]
//     given the cutting position
//   - for every possible cutting position, make a cut and calculate minimum
//     for left & right stick
//   - save results in memo
/*
int nG;
int cut2(int left, int right) {
    if (left+1 == right) return 0;
    int& ans = memo[left][right];
    if (ans != -1) return ans;

    ans = 2e9;
    for (int i = 1; i <= nG; ++i) {
        if (A[i] > left && A[i] < right) {
            int lCut = cut2(left, A[i]);
            int rCut = cut2(A[i], right);
            ans = min(lCut + rCut + right - left, ans);
        }
    }

    // If no cut can be performed, then set cost to 0 as only cuts contribute to cost
    if (ans == 2e9) ans = 0;
    return ans;
}
*/

/*
void solution3() {
    while (true) {
        int l; cin >> l;
        if (!l) break;
        int n; cin >> n;
        nG = n;
        A[0] = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> A[i];
        }
        A[n+1] = l;
        memset(memo, -1, sizeof(memo));
        int ans = cut2(0, l);
        cout << "The minimum cutting is " << ans << ".\n";
    }
}
*/

// memo[i][j] := Minimum cost after performing cuts i,...,j
int memo[54][54];
int A[54];

int cut(int first, int last) {
    if (first + 1 == last) return 0;    // No cut occuring
    int& ans = memo[first][last];
    if (ans != -1) return ans;
    ans = 1E9;
    for (int i = first+1; i < last; ++i) {
        int left = cut(first, i);   // Minimum cost of performing cuts first, ..., i
        int right = cut(i, last);   // Minimum cost of performing cuts i, ..., last
        ans = min(left + right + A[last] - A[first], ans);
    }
    return ans;
}

void solution4() {
    while (true) {
        int l; cin >> l;
        if (!l) break;
        int n; cin >> n;
        A[0] = 0;
        for (int i = 1; i <= n; ++i) cin >> A[i];
        A[n+1] = l;

        memset(memo, -1, sizeof memo);
        int ans = cut(0,n+1);
        cout << "The minimum cutting is " << ans << ".\n";
    }
}

int main() {
//    solution1();
//    solution2();   
//    solution3();
    solution4();
    return 0;
}
