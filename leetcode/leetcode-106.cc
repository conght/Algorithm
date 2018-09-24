#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    TreeNode* buildTree(vector<int>& postorder, vector<int>& inorder, int& pre_index,
        vector<int>::iterator begin, vector<int>::iterator end) {
        if (pre_index < 0) return NULL;
        TreeNode* root = new TreeNode(postorder[pre_index]);
        auto root_iter = find(begin, end, postorder[pre_index]);

        if (root_iter+1 < end)
            root->right = buildTree(postorder, inorder, --pre_index, root_iter+1, end);
        if (begin < root_iter)
            root->left = buildTree(postorder, inorder, --pre_index, begin, root_iter);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int index = postorder.size() - 1;
        return buildTree(postorder, inorder, index, inorder.begin(), inorder.end());
    }
};