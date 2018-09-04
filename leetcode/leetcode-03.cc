#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 1;

        if (s.length() == 0)
            return 0;
        set<char> chars;
        for (int i=0;i<s.length();i++) {
            chars.insert(s[i]);
        }

        int len = chars.size();
        vector<vector<bool> > d(s.length()+1, vector<bool>(s.length()+1));
        /*bool ** d = new bool * [s.length()+1];
        for (int i=0;i<s.length()+1;i++) {
            d[i] = new bool[s.length()+1];
        }*/

        for (int i=0;i<s.length()+1;i++) {
            d[i][i] = true;
        }

        for (int i=1;i<len;i++) {
            for (int j=0;j<s.length()-i;j++) {
                d[j][j+i] = s[j] == s[j+i] ? false : true;
                d[j][j+i] = (d[j][j+i-1] && d[j+1][j+i] && d[j][j+i]);

                if (d[j][j+i] && (i+1) > ans)
                    ans = (i+1);
            }
        }
        /*for(int j=0;j<s.length()+1;j++)
            delete[] d[j];
        delete[] d;*/
        return ans;
    }
};

int main() {
    string s = "abcabcbb";
    Solution sln;
    cout << sln.lengthOfLongestSubstring(s) << endl;
}