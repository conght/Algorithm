#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void myFunc(string& digits, int index, vector<char>& str, vector<vector<char> >& maps, vector<vector<char> >& ans) {
        if (index == digits.length()) {
            ans.push_back(str);
            return ;
        }

        vector<char> lists = maps[digits[index] - '0'];
        for (int i=0;i<lists.size();i++) {
            str[index] = lists[i];
            myFunc(digits, index+1, str, maps, ans);
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        if (digits.length() == 0) 
            return ret;
        vector<vector<char> > maps;
        maps.push_back({}); // 0
        maps.push_back({}); // 1
        maps.push_back({'a', 'b', 'c'}); // 2
        maps.push_back({'d', 'e', 'f'}); // 3
        maps.push_back({'g', 'h', 'i'}); // 4
        maps.push_back({'j', 'k', 'l'}); // 5
        maps.push_back({'m', 'n', 'o'}); // 6
        maps.push_back({'p', 'q', 'r', 's'}); // 7
        maps.push_back({'t', 'u', 'v'}); // 8
        maps.push_back({'w', 'x', 'y', 'z'}); // 9

        vector<char> str(digits.length());
        vector<vector<char> > ans;
        myFunc(digits, 0, str, maps, ans);

        
        for (int i=0;i<ans.size();i++) {
            stringstream ss;
            for (int j=0;j<ans[i].size();j++) {
                ss << ans[i][j];
            }
            ret.push_back(ss.str());
        }

        return ret;
    }
};

int main() {
    Solution s;
    s.letterCombinations("23");
    return 0;
}