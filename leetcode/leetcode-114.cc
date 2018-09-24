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
    TreeNode* flattenHelper(TreeNode* root) {
        if (root->left == NULL && root->right == NULL) { return root; }

        TreeNode* left_head = root->left;
        TreeNode* right_head = root->right;
        TreeNode* left_tail = flattenHelper(root->left);
        if (NULL == left_tail) left_tail = root;
        TreeNode* right_tail = flattenHelper(root->right);
        if (NULL == right_tail) right_tail = left_tail;

        root->right = left_head;
        root->left = NULL;
        left_tail->right = right_head;
        TreeNode* tail = right_tail;

        return tail;
    }
    void flatten(TreeNode* root) {
        flattenHelper(root);
    }
};

int main() {
    Solution s;
    string input = "1,2,5,3,4,null,6";
    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(5);
    TreeNode d(3);
    TreeNode e(4);
    TreeNode f(6);

    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.right = &f;

    s.flatten(&a);
}