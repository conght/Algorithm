#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    //int sum1 = 0;
    int ans = 0;
    void sumNumbersHelper(TreeNode* root, int& sum) {
        if (NULL == root) { return; }

        sum = sum * 10 + root->val;

        if (root->left == NULL && root->right == NULL) { ans += sum; return; }

        int tmp = sum;
        if (root->left)
            sumNumbersHelper(root->left, sum);
        sum = tmp;
        if (root->right)
            sumNumbersHelper(root->right, sum);

    }

    int sumNumbers(TreeNode* root) {
        int sum = 0;
        sumNumbersHelper(root, sum);

        return ans;
    }
};


int main() {
    return 0;
}