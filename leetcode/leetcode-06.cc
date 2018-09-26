#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {

        if (0 == s.length() || numRows == 1) return s;
        string ans = "";
        int round = s.length()/2/(numRows - 1);
        if (s.length()/2/(numRows - 1)) round++;

        for (int i=0; i<numRows; i++) {
            for (int j=0; j<round; j++) {
                ans += s[i+j*2*(numRows-1)];
                if (i > 0 && i < numRows - 1) {
                    ans += s[2*(numRows-1)*(1+j)-i];
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.convert("PAYPALISHIRING", 3) << endl;
}