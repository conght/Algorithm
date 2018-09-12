#include <bits/stdc++.h>

using namespace std;


 typedef struct _TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 } TreeNode;

class Solution {
public:

    void reverseTree(TreeNode *root) {
        if (root == NULL)
            return;

        TreeNode *tmp = root->left;
        root->left = root->right;
        root->right = tmp;

        reverseTree(root->left);
        reverseTree(root->right);
    }

    bool isSame(TreeNode *a, TreeNode *b) {
        if (!a && !b)
            return true;
        if (!a || !b)
            return false;

        if (a->val == b->val)
            return isSame(a->left, b->left) && isSame(a->right, b->right);
        else
            return false;
    }

    bool isSymmetric(TreeNode *root) {
        if (root == NULL)
            return true;

        reverseTree(root->right);

        return isSame(root->left, root->right);
    }
};