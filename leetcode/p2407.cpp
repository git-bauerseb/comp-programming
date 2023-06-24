#include <iostream>
#include <vector>
#include <functional>

using namespace std;


class SegmentTree {
    public:

        // Build an segment
        SegmentTree(const vector<int>& numbers, std::function<int(int,int)> combine): m_numbers{numbers}, m_combine{combine} {
            const int n = m_numbers.size();
            // Reserve enough memory
            // 1 + 2 + 4 + ... + 2^ceil(log2(n)) < 4n vertices
            m_st.resize(4*n+1, 0);
        }

        void build() {build(0, m_numbers.size()-1, 1);}
        void update(int index, int value) {update(index, 0, m_numbers.size()-1, value, 1);}

        // Query sum in range [l,...,r] (l,r inclusive)
        int query(int l, int r) {
            return query(l, r, 0, m_numbers.size()-1, 1);
        }

    public:
        // Functions for range sum query

        // Build a segment tree for range sum queries
        void build(int l, int r, int vertex) {
            if (l == r) m_st[vertex] = m_numbers[l];
            else {
                // Current segment is [l,r]
                // Split into [l, ..., m], [m+1, ..., r]
                // where m = (l+r)/2
                int m = (l+r)/2;
                build(l, m, leftChild(vertex));
                build(m+1,r, rightChild(vertex));
                // Child nodes are built, so compute sum
                // Bottom-up
                m_st[vertex] = m_combine(m_st[leftChild(vertex)], m_st[rightChild(vertex)]);
            }
        }

        // cl: current left endpoint of segment
        // cr: current right endpoint of segment
        int query(int l, int r, int cl, int cr, int vertex) {
            // Cannot answer query because outside range
            if (l == cl && r == cr) return m_st[vertex];
            else {
                int m = (cl+cr)/2;

                // Only need to recursive in left subtree
                if (r <= m) return query(l, r, cl, m, leftChild(vertex));
                else if (l > m) return query(l, r, m+1, cr, rightChild(vertex));
                else {
                    int leftPart = query(l, m, cl, m, leftChild(vertex));
                    int rightPart = query(m+1, r, m+1, cr, rightChild(vertex));
                    return m_combine(leftPart, rightPart);
                }
            }
        }

        void update(int index, int cl, int cr, int val, int vertex) {
            if (cl == cr) m_st[vertex] = val;
            else {
                int m = (cl+cr) / 2;
                if (index <= m) update(index, cl, m, val, leftChild(vertex));
                else update(index, m+1, cr, val, rightChild(vertex));
                m_st[vertex] = m_combine(m_st[leftChild(vertex)], m_st[rightChild(vertex)]);
            }
        }

        int leftChild(int parent) {return 2*parent;}
        int rightChild(int parent) {return 2*parent + 1;}
    

        const vector<int> m_numbers;
        vector<int> m_st;           // Implicit segment tree

        // Combine function (Addition for range sum queries, maximum for range maximum queries)
        std::function<int(int,int)> m_combine;
};

// Solution (TLE)
//
// Store
//  dp[i] := longest increasing subsequence ending with number i
//
//  For number l, update is then:
//      dp[l] = max(dp[l-i] + 1, dp[l+1] + 1, 1 < i <= k)
//      => Time: O(k*n)
//          where k is difference
//                n is length
//
// First misconcept: Increasing => look at smaller elements
/*
class Solution {
    public:
        int lengthOfLIS(vector<int>& nums, int k) {
            const int n = nums.size();

            vector<int> dp(30, 0);
            int tMax = -1;

            for (int i = 0; i < n; ++i) {
                int cur = nums[i];
                int m_ = 1;
                for (int j = 1; j <= k; ++j) {
                    if (cur - j >= 0)
                        m_ = max(m_, 1 + dp[cur-j]);
                }
                dp[cur] = m_;
                tMax = max(tMax, dp[cur]);
            }

            return tMax;
        }
};
*/


class Solution {
    public:
        int lengthOfLIS(vector<int>& nums, int k) {
            const int n = nums.size();
            
            vector<int> occ(100'002, 0);
            SegmentTree st(occ, [](int a, int b) {return max(a,b);});

            for (int i = 0; i < n; ++i) {
                int lower = max(1, nums[i]-k);
                int fLIS = nums[i] == 1 ? 0 : st.query(lower, max(1, nums[i]-1));
                st.update(nums[i], fLIS+1);
            }          

            return st.query(1, 100'001);
        }
};


int main() {

    vector<int> nums{1,1,5};

    Solution solution{};
    int l = solution.lengthOfLIS(nums, 3);
    cout << l << "\n";
    return 0;
}
