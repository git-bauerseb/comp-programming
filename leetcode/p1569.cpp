#include <iostream>
#include <vector>

#define MOD 1'000'000'007

using namespace std;
using ll = long long;

struct Node {


    Node(int val) : m_val(val), m_left(nullptr), m_right(nullptr) {}

    Node(int val, Node* left, Node* right)
        : m_val(val), m_left(left), m_right(right) {}

    int m_val;
    Node* m_left;
    Node* m_right;
};


void insert(Node* root, int val) {
    if (val < root->m_val) {
        if (root->m_left == nullptr) {
            root->m_left = new Node(val);
        } else {
            insert(root->m_left, val);
        }
    } else {
        if (root->m_right == nullptr) {
            root->m_right = new Node(val);
        } else {
            insert(root->m_right, val);
        }
    }
}


ll factorial(ll n) {
    ll r = 1;
    while (n > 1) {r = (r*n) % MOD; --n;}
    return r;
}

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

ll binomcoeff(ll n, ll k) {
    if (k == 0 || k == n) return 1;
    ll inv = (binpow(factorial(k), MOD-2) * binpow(factorial(n-k), MOD-2)) % MOD;
    return (factorial(n) * inv) % MOD;
}

class Solution {

    public:
        int numOfWays(vector<int>& nums) {
            Node* root = new Node(nums[0]);
            // Construct binary tree
            for (int i = 1; i < nums.size(); ++i) {
                insert(root, nums[i]);
            }

            auto r = rec(root);
            return r.second - 1;
        }

        // Return (Number of nodes in tree, Number of ways to arange nodes)
        pair<ll,ll> rec(Node* root) {
            if (root->m_left == nullptr && root->m_right == nullptr) {
                return {1,1};
            }

            pair<ll,ll> left = {0,1};

            if (root->m_left != nullptr) {
                left = rec(root->m_left);
            }

            pair<ll,ll> right = {0,1};
            if (root->m_right != nullptr) {
                right = rec(root->m_right);
            }

            ll comb = binomcoeff(left.first + right.first, left.first);
            comb = (comb * left.second) % MOD;
            comb = (comb * right.second) % MOD;
            
            return {1 + left.first + right.first, comb};
        }
};

int main() {

    vector<int> nums{2,1,3,4,5};
    Solution solution{};
    int nWays = solution.numOfWays(nums);

    cout << nWays << "\n";

    return 0;
}
