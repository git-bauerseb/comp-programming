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

//  | al + ... + ar | = maxPrefix - minPrefix
//
//  If ensuring at each step that maxPrefix - minPrefix < max(a) - min(a)
//  then condition satisfied
//  
//  If there are only 0s, condition cannot be satisfied max(a) - min(a) = 0
//
//  Steps:
//      - Os are irrelevant
//      - write at front
//
//  Let a1 + ... + ak be the current prefix
//  
//  If current prefix > 0, then add a negative number
//      => because a1 + ... + ak + a{k+1} + ... + an = 0
//      <=> a1 + ... + ak = - (a{k+1} + ... + an)
//      <=> > 0 = -(a{k+1} + .. + an)
//  it is guaranteed that there exists a negative element
//
//  Similary if prefix < 0
//
//  If prefix > 0 and negative number is added, prefix stays in range (min(a), max(a)]
//  If prefix <= 0 and positive number is added, prefix stays in range (min(a), max(a)]
//
//  At the end, prefix is in range (min(a), max(a)]
//
//  Because all prefixes were constructed s.t. in (min(a), max(a)], the condition
//  maxPrefix - minPrefix <= max(a) - (min(a)+1) = max(a) - min(a) - 1 < max(a) - min(a)
void solution() {
    int n; cin >> n;

    int zeros = 0;
    set<int> posIdx;
    set<int> negIdx;
    vector<long long> numbers(n);

    ll ma = -1E12;
    ll mi = 1E12;

    for (int i = 0; i < n; ++i) {
        ll num; cin >> num;
        if (num == 0) zeros++;
        else if (num > 0) posIdx.insert(i);
        else negIdx.insert(i);
        ma = max(ma, num);
        mi = min(mi, num);
        numbers[i] = num;
    }

    if (zeros == n) {cout << "No\n"; return;}
    else cout << "Yes\n";

    for (int i = 0; i < zeros; ++i) cout << " 0 ";

    ll prefix = 0;
    for (int i = 0; i < n-zeros; ++i) {
        if (prefix <= 0) {
            int idx = *posIdx.begin();
            posIdx.erase(posIdx.begin());
            prefix += numbers[idx];
            cout << numbers[idx] << " ";
        } else {
            int idx = *negIdx.begin();
            negIdx.erase(negIdx.begin());
            prefix += numbers[idx];
            cout << numbers[idx] << " ";
        }
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
