#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        int ans = 0;
        int len = s.length();
        int tmp = 0;
        stk.push(-1);

        for (int i=0; i<len; i++) {
            if (s[i] == '(') stk.push(i);
            else {
                stk.pop();
                if (!stk.empty()) {
                    tmp = i - stk.top();
                    ans = max(tmp, ans);
                } else {
                    stk.push(i);
                }
            }
        }

        return ans;

    }
};

int main() {
    Solution s;
    s.longestValidParentheses(")()((())");
    return 0;
}