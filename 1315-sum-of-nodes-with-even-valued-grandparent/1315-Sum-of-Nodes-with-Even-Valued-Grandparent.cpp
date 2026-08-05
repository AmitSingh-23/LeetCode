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
    int sumEvenGrandparent(TreeNode* root) {
   
        int first = -1;
        int second = -1;
        int sum=0;
        check(root,sum,first,second);
        return sum;

    }
    void check(TreeNode* mover, int& sum, int first, int second) {
        if (mover == NULL)
            return;

        if (first > 0) {
            if (first == 1) {
                first = -1;
                sum += mover->val;

            } else {
                first--;
            }
        }
        if (second >0) {
            if (second == 1) {
                second = -1;
                sum += mover->val;

            } else {
                second--;
            }
        }
        if (mover->val % 2 == 0) {
            if (first == -1)first = 2;
            else {
                second = 2;
            }
        }
        check(mover->left, sum, first, second);
        check(mover->right, sum, first, second);
    }
};