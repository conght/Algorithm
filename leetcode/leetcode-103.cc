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
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > ans;
        if (NULL == root) { return ans; }

        deque<TreeNode*> current_level;
        current_level.push_back(root);
        current_level.push_back(NULL);
        vector<int> level;
        while (!current_level.empty()) {
            TreeNode* node = current_level.front();
            if (node == NULL) {
                if (level.size() > 0) {
                    ans.push_back(level);
                    level.clear();
                    current_level.push_back(NULL);
                }
            } else {
                level.push_back(node->val);
                if (node->left)
                    current_level.push_back(node->left);
                if (node->right)
                    current_level.push_back(node->right);

            }

            current_level.pop_front();
        }

        for (int j=1; j<=ans.size(); j++) {
            if (j % 2 ) { continue; }
            vector<int>& level = ans[j-1];
            for (int i=0; i<level.size()/2; i++) {
                int tmp = level[i];
                level[i] = level[level.size() - i - 1];
                level[level.size() - i - 1] = tmp;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    TreeNode node(3);
    TreeNode node2(9);
    TreeNode node3(20);
    TreeNode node4(15);
    node.left = &node2;
    node.right = &node3;
    node3.right = &node4;
    s.zigzagLevelOrder(&node);
}