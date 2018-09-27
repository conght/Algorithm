#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {

        if (s1.length() + s2.length() != s3.length()) return false;
        vector<vector<bool> > d(s1.length()+1, vector<bool>(s2.length()+1));

        d[0][0] = true;
        for (int i=1; i<=s1.length(); i++) {
            d[i][0] = d[i-1][0] && (s1[i-1] == s3[i-1]);
        }

        for (int i=1; i<=s2.length(); i++) {
            d[0][i] = d[0][i-1] && (s2[i-1] == s3[i-1]);
        }

        for (int i=1; i<=s1.length(); i++) {
            for (int j=1; j<=s2.length(); j++) {
                d[i][j] = (d[i][j-1] && s2[j-1] == s3[i+j-1]) || (d[i-1][j] && s1[i-1] == s3[i+j-1]);
                //cout << d[i][j] << " ";
            }
            //cout << endl;
        }

        return d[s1.length()][s2.length()];
    }
};

int main() {
    Solution().isInterleave("aabcc", "dbbca", "aadbbcbcac");
}