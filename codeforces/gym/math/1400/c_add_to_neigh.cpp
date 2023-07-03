#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#include <stack>

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

vector<int> getDivisors(int minDiv, int n) {
    vector<int> result;
    for (int i = 1; i <= sqrt(n); ++i) {
        if ((n % i) == 0) {
            if (i == (n/i)) {
                if (i >= minDiv) {result.push_back(i);}
            } else {
                if (i >= minDiv) {result.push_back(i);}
                if (n/i >= minDiv) {result.push_back(n/i);}
            }
        }
    }
    return result;
}

void solution1() {
    int n; cin >> n;
    vector<int> nums(n, 0);

    int tSum = 0;
    int mNum = -1;

    bool allSame = true;

    for (int i = 0; i < n; ++i) {
        int cNum; cin >> cNum;
        mNum = max(mNum, cNum);
        tSum += cNum;
        nums[i] = cNum;

        if (i > 0 && nums[i] != nums[i-1]) allSame = false;
    }

    if (allSame) {cout << "0\n"; return;}

    vector<int> div = getDivisors(mNum, tSum);
    int minOp = n-1;
    for (auto& e : div) {


        int ops = 0;
        stack<int> s;
        
        for (auto& e : nums) {
            s.push(e);
        }


        // Inelegant solution with stack
        // => INSTEAD: use running sum
        bool poss = true;
        while (!s.empty()) {
            int top = s.top();
            s.pop();

            if (top == e) {
                continue;
            }

            // Element less than divisor, so needs addition
            if (top < e) {
                if (s.empty()) {
                    poss = false;
                    break;
                }
                
                int el2 = s.top();
                s.pop();
                
                if (top + el2 > e) {
                    poss = false;
                    break;
                }
                
                s.push(top + el2);
                ops++;
            }
        }

        if (poss) {
            minOp = min(minOp, ops);
        }
    }
    cout << minOp << "\n";
}

void solution2() {
    int n; cin >> n;
    vector<int> nums(n,0);
    int mElement = -1;
    int tSum = 0;
    bool allSame = true;
    for (int i = 0; i < n; ++i) {
        int cNum; cin >> cNum;
        mElement = max(mElement, cNum);
        tSum += cNum;
        nums[i] = cNum;
        if (i > 0 && nums[i] != nums[i-1]) allSame = false;
    }

    if (allSame) {cout << "0\n"; return;}
    vector<int> divisors = getDivisors(mElement, tSum);
    
    int minOps = n-1;

    for (auto& div : divisors) {
        
        // Running sum
        int rSum = 0;
        int ops = 0;
        
        bool poss = true;

        for (int i = 0; i < n; ++i) {
            if (rSum + nums[i] < div) {rSum += nums[i]; ops++;}
            else if (rSum + nums[i] > div) {poss = false; break;}
            else {rSum = 0;}
        }
        if (poss)
        minOps = min(ops, minOps);
    }

    cout << minOps << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int tt;
	cin >> tt;
	while (tt--) {
		solution2();
	}

	return 0;
}
