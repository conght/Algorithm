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
    vector<TreeNode*> generateTrees(int lo, int hi) {

        vector<TreeNode*> ans;
        if (lo > hi) { return ans; }

        if (lo == hi) { ans.push_back(new TreeNode(lo)); return ans; }

        vector<TreeNode*> lefts;
        vector<TreeNode*> rights;

        for (int i=lo; i<=hi; i++) {
            vector<TreeNode*> lefts = generateTrees(lo, i-1);
            vector<TreeNode*> rights = generateTrees(i+1, hi);
            if (lefts.empty()) lefts.push_back(NULL);
            if (rights.empty()) rights.push_back(NULL);
            for (int k=0; k<lefts.size(); k++) {
                for (int j=0; j<rights.size(); j++) {
                    TreeNode* root = new TreeNode(i);
                    root->left = lefts[k];
                    root->right = rights[j];
                    ans.push_back(root);
                }
            }
        }

        return ans;

    }

    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> ans;
        if (n <= 0) return ans;

        ans = generateTrees(1, n);
        return ans;
    }
};

int main() {
    Solution s;
    vector<TreeNode*> ans = s.generateTrees(3);
    return 0;
}