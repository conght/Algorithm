/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Example 1:

Input:
    2
   / \
  1   3
Output: true
Example 2:

    5
   / \
  1   4
     / \
    3   6
Output: false
Explanation: The input is: [5,1,4,null,null,3,6]. The root node's value
             is 5 but its right child's value is 4.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <bits/stdc++.h>

using namespace std;


// [3,1,5,0,2,4,6,null,null,null,3]
class Solution {
public:

    bool isValidBSTHelper(TreeNode* root, TreeNode* prev) {
        if (NULL == root) return true;
        if (root->left && root->val <= root->left->val) return false;
        if (root->right && root->val >= root->right->val) return false;

        if (prev && prev->left == root) {
            if (root->left && prev->val <= root->left->val) return false;
            if (root->right && prev->val <= root->right->val) return false;
        }

        if (prev && prev->right == root) {
            if (root->left && prev->val >= root->left->val) return false;
            if (root->right && prev->val >= root->right->val) return false;
        }

        return isValidBSTHelper(root->left, root) && isValidBSTHelper(root->right, root);
    }
    bool isValidBST(TreeNode* root) {
        return isValidBSTHelper(root, NULL);
    }
};