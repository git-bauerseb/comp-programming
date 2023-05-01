#include <iostream>
#include <cstring>

using namespace std;

// Knuth-Yao DP optimization
/*
int solve() {
    int N;

    int dp[N][N], opt[N][N]

    auto C = [&](int i, int j) {...}    // Cost function

    for (int i = N-2; i >= 0; i--) {
        for (int j = i+1; j < N; j++) {


        }
    }    
}
*/

// Stick cutting example
const int MAX_CUTS = 55;
int memo[MAX_CUTS][MAX_CUTS];

// Knuth-Yao optimum value storage
int opt[MAX_CUTS][MAX_CUTS];

int A[MAX_CUTS];

int solve(int first, int last) {
    if (first + 1 >= last) {
        opt[first][last] = first+1;   
        return 0;    // No cut in between possible
    }
        
    int& answer = memo[first][last];
    if (answer != -1) return answer;
    answer = 2E9;

    solve(first, last-1);
    solve(first+1, last);
        
    for (int k = opt[first][last-1]; k <= min(last, opt[first+1][last]); ++k) {
        int curr = solve(first, k) + solve(k, last) + A[last] - A[first];
        if (curr < answer) {
            answer = curr;
            opt[first][last] = k;
        }
    }       

    return answer;
}


int main() {
    while (true) {
        int l; cin >> l;
        if (!l) break;
     
        int n; cin >> n;
        A[0] = 0;       // First cut at beginning
        for (int i = 1; i <= n; ++i) {
            int cut; cin >> A[i];
        }
        A[n+1] = l;     // Last cut at end
     
        memset(memo, -1, sizeof memo);
        memset(opt, -1, sizeof opt);
     
        int result = solve(0, n+1);  // Solve problem when considering all cuts 0, ..., n+1
        cout << result << "\n";
    }
    return 0;
}
