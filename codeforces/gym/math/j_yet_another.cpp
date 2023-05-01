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

void solution() {
    int n, x, y; cin >> n >> x >> y;

    int a = min(x,y);
    int b = max(x,y);

    int maxStep = b-a;
    int bestStep = 1E9;
    int minMax = 1E9;
    int bBefore = 0;

    for (int i = 1; i <= maxStep; ++i) {
        if (maxStep % i == 0) {
            // Calculate number of elements in between
            // 2 elements for x,y
            //
            int elements = 2 + (maxStep / i) - 1;
            if (elements == n) {
                bBefore = 0;
                bestStep = i;
                minMax = b;
            } else if (elements < n) {

                // Calculate how many elements can be generated before 
                // a
                int before = 0;
                int num = a-i;
                while (num > 0 && before + elements < n) {before++; num -= i;}

                if (before + elements >= n) {
                    bestStep = i;
                    minMax = b;
                    bBefore = before;
                } else {
                    int after = n - before - elements;
                    int num = b + after * i;
                    if (num < minMax) {bBefore = before; minMax = num; bestStep = i;}
                }
            }
        }
    }

    int curr = a - bestStep * bBefore;
    for (int i = 0; i < n; ++i) {
        cout << curr << " ";
        curr += bestStep;
    }

    cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int tt;
	cin >> tt;
	while (tt--) {
		solution();
	}

	return 0;
}
