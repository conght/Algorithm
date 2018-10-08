/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:

    int robHelper(TreeNode* node) {
        if(!node)
        {
            return 0;
        }

        return max(node-> val + (node->left ? robHelper(node->left->left) + robHelper(node->left->right) : 0) + (node->right ? robHelper(node->right->left) + robHelper(node->right->right) : 0), robHelper(node->left) + robHelper(node->right));
    }

    int rob(TreeNode* root) {
        return robHelper(root);
    }
};