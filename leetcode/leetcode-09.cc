#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        if (x < 10)
            return true;

        stringstream ss;
        ss << x;
        string s = ss.str();
        int len = s.size();
        for (int i=0;i<len/2;i++) {
            if (s[i] != s[len - 1 - i])
                return false;
        }

        return true;
    }
};

int main() {
    Solution s;
    cout << s.isPalindrome(12) << endl;
}