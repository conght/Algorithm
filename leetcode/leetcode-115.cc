#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int ans = 0;

        if (s.length() < t.length()) { return ans; }

        vector<vector<int> > d(s.length()+1, vector<int>(t.length()+1));

        for (int i=0; i<=s.length(); i++) { d[i][0] = 1; }
        for (int j=1; j<=t.length(); j++) { d[0][j] = 0; }

        for (int i=1; i<=s.length(); i++) {
            for (int j=1; j<=t.length(); j++) {
                d[i][j] = d[i-1][j];
                if (s[i-1] == t[j-1]) { d[i][j] += d[i-1][j-1]; }
                cout << d[i][j] << " ";
            }
            cout << endl;
        }

        return d[s.length()][t.length()];
    }
};

int main() {
    Solution().numDistinct("b", "b");
}