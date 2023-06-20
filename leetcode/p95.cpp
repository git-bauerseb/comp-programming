#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

struct TreeNode {

    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};


class Solution {

    public:
        vector<TreeNode*> generateTrees(int n) {
            vector<TreeNode*> result;

            bitset<12> mask;

            for (int i = 1; i <= n; ++i) {
                mask[i] = 1;
                auto partResult = rec(mask, 1, n, i);
                mask[i] = 0;

                result.insert(result.end(), partResult.begin(), partResult.end());
            }

            return result;
        }

        // used:        Numbers already used in parent node
        vector<TreeNode*> rec(bitset<12>& used, int lower, int upper, int root) {
            if (lower == upper) {
                TreeNode* leaf = new TreeNode(root);
                return {leaf};
            }

            vector<TreeNode*> leftSubtrees;
            vector<TreeNode*> rightSubtrees;


            // Construct all left subtrees
            for (int i = lower; i < root; ++i) {
                auto left = rec(used, lower, root-1, i);
                leftSubtrees.insert(leftSubtrees.end(), left.begin(), left.end());
            }

            for (int i = root+1; i <= upper; ++i) {
                auto right = rec(used, root+1, upper, i);
                rightSubtrees.insert(rightSubtrees.end(), right.begin(), right.end());
            }



            const int l = leftSubtrees.size();
            const int r = rightSubtrees.size();

            // Special case: No left subtree
            // => return right subtrees
            if (l == 0) {
                for (int i = 0; i < r; ++i) {
                    TreeNode* parent = new TreeNode(root, nullptr, rightSubtrees[i]);
                    rightSubtrees[i] = parent;
                }
                return rightSubtrees;
            } else if (r == 0) {
                for (int i = 0; i < l; ++i) {
                    TreeNode* parent = new TreeNode(root, leftSubtrees[i], nullptr);
                    leftSubtrees[i] = parent;
                }
                return leftSubtrees;
            }

            vector<TreeNode*> complete(l * r);
            int idx = 0;
            for (int i = 0; i < l; ++i) {
                for (int j = 0; j < r; ++j, ++idx) {
                    TreeNode* rootNode = new TreeNode(root, leftSubtrees[i], rightSubtrees[j]);
                    complete[idx] = rootNode;
                }
            }

            return complete;
        }
};


int main() {

    Solution solution{};
    auto res = solution.generateTrees(3);
    cout << res.size() << "\n";
    return 0;
}
