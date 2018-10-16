#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void generateParenthesisHelper(vector<string>& ans, string current, int open, int close, int max) {
        if (current.size() == max*2) {
            ans.push_back(current);
            return;
        }

        if (open < max) {
            generateParenthesisHelper(ans, current + "(", open + 1, close, max);
        }

        if (close < open) {
            generateParenthesisHelper(ans, current + ")", open, close+1, max);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        generateParenthesisHelper(ans, "", 0, 0, n);
        return ans;
    }
};