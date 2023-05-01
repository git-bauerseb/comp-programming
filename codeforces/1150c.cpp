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


// Idea
//  Multiset of numbers 1,2
//  Find reordering s.t. prefix sum contains maximally many prime numbers
//
//  General:
//
//  Approach:
//      - Put 2,1 and then use all 2s followed by all 1s
//
//  Difficulties:
//      - Overthinking (generating primes, then use 1 or 2 if prime)
//      - Not observed that all primes are odd and can be used here
//      - Primes have nothing to do with problem
//          - Just need to find sequence s.t. most numbers are odd (after 2)
//          - Thus, start with 3 and then use consecutivelly 2s to jump from 3,5,7,9,11,...
//          - there is no better approach
bool is_prime(int n) {
    if (n == 2 || n == 3) return true;
    if (n <= 1 || n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i*i <= n; i += 6) {
        if (n % i == 0 || n % (i+2) == 0) return false;
    }
    return true;
}

void solution() {
    int n; cin >> n;

    int ones = 0;
    int twos = 0;

    for (int i = 0; i < n; ++i) {
        int num; cin >> num;
        ones += (num == 1) ? 1 : 0;
        twos += (num == 2) ? 1 : 0;
    }

    int prefix = 0;
    for (int i = 0; i < n; ++i) {
        if (ones && is_prime(prefix+1)) {
            cout << " 1 ";
            prefix += 1;
            ones--;
        } else if (twos && is_prime(prefix+2)) {
            cout << " 2 ";
            prefix += 2;
            twos--;
        } else {
            // If we only have 1s, print them
            if (!twos) {prefix += 1; cout << " 1 "; ones--;}
            else if (!ones) {prefix += 2; cout << " 2 "; twos--;}
            else {
                if (prefix % 2) {twos--; prefix += 2; cout << " 2 ";}
                else {ones--; prefix += 1; cout << " 1 ";}
            }
        }
    }

    cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	solution();

	return 0;
}
