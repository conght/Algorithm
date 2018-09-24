#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int>v1;
    vector<vector<int>>v;
    int countsum;
    vector<vector<int> > pathSum(TreeNode *root, int sum)
    {
        v.clear();
        v1.clear();
        if(root==NULL) return v;
        countsum=0;
        calsum(root,sum);
        return v;
    }
    void calsum(TreeNode *root,int &sum)
    {
        if (NULL == root) return;
        countsum+=root->val;
        v1.push_back(root->val);
        if(countsum==sum&&root->left==NULL&&root->right==NULL) { v.push_back(v1); }
        if(root->left) calsum(root->left,sum);
        if(root->right) calsum(root->right,sum);
        countsum-=root->val;
        v1.pop_back();
    }
};