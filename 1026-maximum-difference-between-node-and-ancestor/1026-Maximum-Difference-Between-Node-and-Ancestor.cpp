/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        int result = 0;
        dfs(root, result);
        return result;
    }
    pair<int, int> dfs(TreeNode* mover, int& result) {
        int value = mover->val;
        pair < int, int >left = {value, value};
        pair < int, int> right = {value, value};

        if (mover->left != NULL) {
            left = dfs(mover->left,result);
        }
        if (mover->right != NULL) {
            right = dfs(mover->right,result);
        }
        int first = max(abs(left.first - value), abs(left.second - value));

        int second = max(abs(right.first - value), abs(right.second - value));
        result = max(first, max(result, second));
        return {max(value, max(left.first, right.first)),
                min(value, min(left.second, right.second))};
    }
};