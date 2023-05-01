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

// CORRECT SOLUTION BUT TOO SLOW
pair<int,int> posKEl(vector<int>& nums, int k) {
    const int n = nums.size();
    int sum = 0; for (int i = 0; i < k; ++i) sum += nums[i];
    int pos = sum > 0 ? 1 : 0;
    int neg = sum < 0 ? 1 : 0;
    for (int i = 0; i < n - k; ++i) {
        sum -= nums[i];
        sum += nums[i+k];
        pos += sum > 0 ? 1 : 0;
        neg += sum < 0 ? 1 : 0;
    }

    return {pos,neg};
}

pair<int,int> posEl(vector<int>& nums) {
    pair<int,int> res = {0,0};
    for (int i = 1; i <= nums.size(); ++i) {auto t = posKEl(nums, i); res.first += t.first, res.second += t.second;}
    return res;
}

// a[0], ..., a[n-1]
// -1, ...., -n
bool backtrack(vector<int>& nums, int n, int i, int k) {
    if (i == n) return false;
    for (int j = i+1; j <= (i+1)*(i+2)/2; j++) {
        nums[i] = j;
        auto res = posEl(nums);
        
        if (res.first == k && res.second == n*(n+1)/2 - k) return true;
        else if (res.first < k && backtrack(nums,n,i+1,k)) return true;
        nums[i] = -(i+1);
    }

    return backtrack(nums,n,i+1,k);
}
/*
void solution() {
    int n,k; cin >> n >> k;
    vi nums(n,0);
    for (int i = 0; i != n; ++i) nums[i] = -(i+1);

    backtrack(nums, n, 0, k);
    for (int i = 0; i < n-1; ++i) cout << nums[i] << " ";
    cout << nums[n-1] << "\n";
}
*/
const int N_MAX = 31;
int P[N_MAX]; // 0 1 3

void precompute() {
    for (int i = 0; i <= N_MAX; ++i) {
        P[i] = (i)*(i+1)/2;
    }
}

bool backtrack(vector<int>& nums, int k, int idx) {
    const int n = nums.size();
    if (n == idx) return false;
    nums[idx] = 1;
    auto t = posEl(nums);
    if (t.first == k && t.second == n*(n+1)/2 - k) return true;
    else if (t.first < k && backtrack(nums, k, idx+1)) return true; 
    nums[idx] = -467;
    return backtrack(nums, k, idx+1);
}

/*
void solution() {
    int n,k; cin >> n >> k;

    // Special cases
    if (n == 1) {
        if (k == 0) cout << "-1\n";
        else cout << "1\n";
        return;
    } else if (n == 2) {
        if (k == 0) cout << "-1 -1\n";
        else if (k == 1) {cout << "-10 1\n";}
        else if (k == 2) {cout << "-13 42\n";}
        else cout << "1 1\n";
        return;
    }

    auto it = lower_bound(P, P+N_MAX, k);
    int idx = max(0,static_cast<int>(it - P)-1);
    vi nums(n,-467);
    

    for (int i = 0; i < idx; ++i) nums[i] = 1;
    backtrack(nums, k, idx);

    for (int i = 0; i != n; ++i) cout << nums[i] << " ";
    cout << "\n";
}
*/

/*
void solution() {
    int n,k; cin >> n >> k;
    vi nums(n+1); for (int i = 0; i <= n; ++i) nums[i] = i;

    int swaps = n*(n+1)/2 - k;
    bool end = false;
    for (int i = 0; i <= n; ++i) {
        for (int j = i; j > 0; j--) {
            
            if (swaps <= 0) {end=true;break;}
            else {
                swap(nums[j], nums[j-1]);
                swaps--;
            }
        }
        if (end) break;
    }

    for (int i = 1; i <= n; ++i) {
        cout << nums[i] - nums[i-1] << " ";
    }

    cout << "\n";
}
*/

/*
void solution() {
    int n,k; cin >> n >> k;
    vi nums(n+1); for (int i = 0; i <= n; ++i) nums[i] = i;

    int swaps = n*(n+1)/2;
    int idx = n;
    while (swaps > 0) {
        int cIdx = idx;
        while (cIdx > n-idx && swaps-- > 0)
            cIdx--;
        swap(nums[cIdx], nums[idx]);
        idx--;
    }

    for (int i = 0; i <= n; ++i) cout << nums[i] << " ";
    cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    precompute();

	int tt;
	cin >> tt;
	while (tt--) {
		solution();
	}

	return 0;
}
*/

int main() {
    int n = 50;
    int swaps = 28;
    vi nums(n); for (int i = 0; i < n; ++i) nums[i] = (i+1);
    int idx = n;
    while (swaps > 0) {
        int cIdx = idx-1;
        while (cIdx > n-idx && swaps-- > 0) {
            cIdx--;
        }
        swap(nums[cIdx], nums[idx-1]);
        idx--;
    }
    for (int i = 0; i < n; ++i) cout << nums[i] << " ";
    cout << "\n";
}
