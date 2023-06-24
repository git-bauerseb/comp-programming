#include <iostream>

using namespace std;

struct TreeNode {

    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

class Solution {

    public:
        int maxPathSum(TreeNode* root) {
            m_globMax = -1003;
            rec(root);
            return m_globMax;
        }

        int rec(TreeNode* current) {
            if (current->left == nullptr && current->right == nullptr) {
                m_globMax = max(m_globMax, current->val);
                return current->val;
            }
            int leftMax = -1003;
            int rightMax = -1003;
            if (current->left != nullptr) leftMax = rec(current->left);
            if (current->right != nullptr) rightMax = rec(current->right);
            int cMax = current->val + max(leftMax, rightMax);
        
            // Case: Current node alone is max path
            m_globMax = max(current->val, m_globMax);
            
            // Case: Current node + one of child nodes is max path
            m_globMax = max(cMax, m_globMax);
            
            
            // Case: Current node is top of path
            m_globMax = max(current->val + leftMax + rightMax, m_globMax);
            
            
            return max(cMax, current->val);
        }

    private:
        int m_globMax;
};

int main() {

    TreeNode* root = new TreeNode(0);

    Solution solution{};
    int m = solution.maxPathSum(root);
    cout << m << "\n";
    return 0;
}
