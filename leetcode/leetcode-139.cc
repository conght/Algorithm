#include <limits.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.length()+1, false);
        map<string, bool> dict;
        for (auto iter = wordDict.begin();iter != wordDict.end();iter++)
            dict.insert(make_pair(*iter, true));
        dp[0] = true;
        for (int i=1;i < s.length() + 1;i++) {
            if (dict.find(s.substr(0, i)) != dict.end()) {
                dp[i] = true;
                continue;
            }
            for (int j=1;j<i;j++) {
                string tmp =s.substr(j, i-j);
                //cout<<tmp<<endl;
                if (dp[j] && dict.find(s.substr(j, i-j)) != dict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.length()];
    }
};

int main() {
    Solution* s = new Solution();
    string a = "leetcode";
    std::vector<string> v;
    v.push_back("leet");
    v.push_back("code");
    cout << s->wordBreak(a, v) << endl;
    delete s;
    return 0;
}