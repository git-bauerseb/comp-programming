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

// Determine longest non-decreasing subsequence
ll dp(string& s) {
    vector<int> sub;
    for (int i = 0; i < s.length(); ++i) {
        int el = s[i] - '0';
        if (sub.empty() || sub[sub.size()-1] <= el) sub.push_back(el);
        else {
            int idx = static_cast<int>(upper_bound(sub.begin(), sub.end(), el) - sub.begin());
            sub[idx] = el;
        }
    }

    return sub.size();
}

/*
void solution() {
    string s; cin >> s;
    const ll n = s.length();

    string s2(s);
    string s3(s);
    for (int i = 0; i < n-1; i++) {
        if (s2[i] == '1' && s2[i+1] == '0') {
            s2[i] = '0';
            s2[i+1] = '1';
            break;
        }
    }

    for (int i = n-1; i > 0; i--) {
        if (s3[i] == '0' && s3[i-1] == '1') {
            s3[i] = '1';
            s3[i-1] = '0';
            break;
        }
    }

    ll cost1 = (n-dp(s)) * 1'000'000'000'001;
    ll cost2 = (n-dp(s2)) * 1'000'000'000'001 + 1'000'000'000'000;
    ll cost3 = (n-dp(s3)) * 1'000'000'000'001 + 1'000'000'000'000;
    cout << min(cost1, min(cost2, cost3)) << "\n";
}
*/

/*
void solution() {
    string s; cin >> s;
    const int n = s.length();

    if (n == 1) {cout << "0\n"; return;}
    else if (n == 2) {if (s == "10") cout << "1000000000000\n"; else cout << "0\n"; return;}

    // Prefix '1's
    vi prefix(n, 0);
    prefix[0] = s[0] == '1' ? 1 : 0;

    for (int i = 1; i < n; ++i) {
        prefix[i] = prefix[i-1] + (s[i] == '1' ? 1 : 0);
    }

    ll cost = 0;
    for (int i = n-2; i >= 0; i--) {
        // Inversion
        if (s[i] == '1' && s[i+1] == '0') {
            // Do a swap
            if (i == 0 && s[i+2] == '1' || i > 0 && prefix[i-1] == 0) {
                cost += 1'000'000'000'000;
            // Do delete
            } else {
                cost += 1'000'000'000'001;
            }
        }
    }


    cout << cost << "\n";
}
*/

void solution() {
    string s; cin >> s;
    int zeros = 0;
    int ones = count(s.begin(), s.end(), '1');

    const int n = s.length(); if (n == 1) {cout << "0\n"; return;}
    ll answer = 1e18;
    ll del = 1e12+1;
    ll sw = 1e12;
    for (int i = 0; i < n-1; ++i) {
        zeros += s[i] == '0';
        ones -= s[i] == '1';
        ll inv = (s[i] == '1') + (s[i+1] == '0');
        ll cost = (n - (zeros + ones + inv)) * del;
        // Inversion
        if (inv == 2) {
            cost += sw;
        }

        answer = min(answer, cost);
    }

    cout << answer << "\n";
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
