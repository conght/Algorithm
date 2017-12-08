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
    	for (int i=0;i < s.length();i++) {
    		if (dict.find(s.substr(0, i+1)) != dict.end()) {
    			dp[i+1] = true;
    			continue;
    		} 

			for (int j=0;j<i;j++) {
				if (dp[j] && dict.find(s.substr(j+1, i)) != dict.end())
					dp[i] = true;
					continue;
			}
    	}
    	return dp[s.length()+1];
    }
};

int main() {
    Solution* s = new Solution();
    string a = "leedcode";
    std::vector<string> v;
    v.push_back("leet");
    v.push_back("code");
    cout << s->wordBreak(a, v) << endl;
    delete s;
    return 0;
}