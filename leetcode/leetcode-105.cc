#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int& pre_index,
        vector<int>::iterator begin, vector<int>::iterator end) {
        if (pre_index == preorder.size()) return NULL;
        TreeNode* root = new TreeNode(preorder[pre_index]);
        auto root_iter = find(begin, end, preorder[pre_index]);

        if (begin < root_iter)
            root->left = buildTree(preorder, inorder, ++pre_index, begin, root_iter-1);
        if (root_iter+1 < end)
            root->right = buildTree(preorder, inorder, ++pre_index, root_iter+1, end);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index = 0;
        return buildTree(preorder, inorder, index, inorder.begin(), inorder.end());
    }
};