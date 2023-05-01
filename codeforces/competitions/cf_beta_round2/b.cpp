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

const int N_MAX = 1001;
int M[N_MAX][N_MAX];

// [][][0] - Number of 2 factors
// [][][1] - Number of 5 factors
int DP[N_MAX][N_MAX][2];

int factors(int num, int fac) {
    int count = 0;
    while (num > 0 && num % fac == 0) {count++; num /= fac;}
    return count;
}

void solution() {
    int n; cin >> n;

    bool cZero = false;
    int zeroX = -1;
    int zeroY = -1;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            cin >> M[i][j];
            if (!M[i][j]) {
                cZero = true;
                zeroX = j;
                zeroY = i;
            }
        }

    DP[0][0][0] = factors(M[0][0],2);
    DP[0][0][1] = factors(M[0][0],5);

    for (int i = 1; i < n; ++i) {
        DP[0][i][0] = DP[0][i-1][0] + factors(M[0][i] == 0 ? 10 : M[0][i], 2);
        DP[0][i][1] = DP[0][i-1][1] + factors(M[0][i] == 0 ? 10 : M[0][i], 5);
        DP[i][0][0] = DP[i-1][0][0] + factors(M[i][0] == 0 ? 10 : M[i][0], 2);
        DP[i][0][1] = DP[i-1][0][1] + factors(M[i][0] == 0 ? 10 : M[i][0], 5); 
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            int tFac = factors(M[i][j] == 0 ? 10 : M[i][j], 2);
            int fFac = factors(M[i][j] == 0 ? 10 : M[i][j], 5);
            DP[i][j][0] = min(DP[i-1][j][0], DP[i][j-1][0]) + tFac;
            DP[i][j][1] = min(DP[i-1][j][1], DP[i][j-1][1]) + fFac;
        }
    }


    /*
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d %d   ", DP[i][j][0], DP[i][j][1]);
        }

        cout << "\n";
    }
    */


    // If we encountered a zero then max answer will be 1
    if (min(DP[n-1][n-1][0], DP[n-1][n-1][1]) > 1 && cZero) {
        int x = 0;
        int y = 0;
        string path;
        while (x < zeroX || y < zeroY) {
            if (x < zeroX) {x++; path += 'R';}
            else {y++; path += 'D';}
        }

        while (x < n-1 || y < n-1) {
            if (x < n-1) {x++; path += 'R';}
            else {y++; path += 'D';}
        }

        cout << "1\n";
        cout << path << "\n";
    } else {
        cout << min(DP[n-1][n-1][0], DP[n-1][n-1][1]) << "\n";
        int k = -1;
        if (DP[n-1][n-1][0] < DP[n-1][n-1][1]) {k = 0;}
        else {k = 1;}

        string path;

        int x = n-1;
        int y = n-1;
        while (x > 0 || y > 0) {
            if (y && DP[y][x][k] == (DP[y-1][x][k] + factors(M[y][x], k == 0 ? 2 : 5))) {
                y--; path += 'D';
            } else {x--; path += 'R';}
        }

        reverse(path.begin(), path.end());
        cout << path << "\n";
    }
}

int main() {
    solution();
	return 0;
}
