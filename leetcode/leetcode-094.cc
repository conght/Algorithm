
class Solution {
public:

    void inorderTraversal(TreeNode* root, vector<int>& ans) {
        if (NULL == root) { return; }

        inorderTraversal(root->left, ans);
        ans.push_back(root->val);
        inorderTraversal(root->right, ans);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorderTraversal(root, ans);

        return ans;
    }
};