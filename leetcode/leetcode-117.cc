#include <bits/stdc++.h>

using namespace std;


struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:

    TreeLinkNode* connectHelper(TreeLinkNode *root, TreeLinkNode *prev) {
        if (NULL == root) return root;

        if (root->left != NULL) {
            root->left->next = root->right;
        }

        if (prev != NULL) {
            prev->next = root->right;
        }

        if (root->right == NULL) {
            if (prev != NULL)
        }

    }

    void connect(TreeLinkNode *root) {

    }
};