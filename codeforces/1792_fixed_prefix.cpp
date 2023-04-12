#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <numeric>

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

struct Comp {
    Comp(int value, int idx) 
        : m_value{value}, m_idx{idx} {}
    bool operator()(const vector<int>& element, int unused__) {return element[m_idx] == m_value;}
    bool operator()(int unused__, const vector<int>& element) {return element[m_idx] == m_value;}
    int m_value;    
    int m_idx;
};

// Output
template <typename T>
void print_v(vector<T>& v) {cout << "{"; for (auto& x : v) cout << x << " "; cout << "\n";}

void perm_inv(vector<int>& p, vector<int>& inv) {
    const int n = p.size();
    for (int i = 0; i < n; ++i) {
        inv[p[i]-1] = i+1;
    }
}

void solution() {
int n, m; cin >> n >> m;
    vector<vector<int>> perms(n, vector<int>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> perms[i][j];
        }
    }
   
    vector<vector<int>> inv_perms(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            inv_perms[i][perms[i][j]-1] = (j+1);
        }
    }

    sort(inv_perms.begin(), inv_perms.end());
    vector<int> result(n);

    for (int i = 0; i < n; ++i) {
        vector<int>& p = perms[i];

        auto begin = inv_perms.begin();
        auto end = inv_perms.end();
        int cBeauty = 0;


        for (int b = 0; b < m; ++b) {
            
            begin = lower_bound(begin, end, -1,
                    [&](const vector<int>& permutation, int unused__) {
                        return permutation[b] < p[b];
                    });
            end = upper_bound(begin, end, -1,
                    [&](int unused__, const vector<int>& permutation) {
                        return permutation[b] > p[b];
                    });

            int num = end - begin;
            if (num == 0) break;
            cBeauty++;
        }

        result[i] = cBeauty;
    }

    for (auto& e : result) cout << e << " ";
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
