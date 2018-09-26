#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if (0 == s.length() || words.empty()) return ans;
        unordered_map<string, int> counts;
        for (auto word : words) counts[word]++;

        int len = words[0].length();
        int num = words.size();
        int n = s.length();

        for (int i=0; i < n - num*len + 1; i++) {
            unordered_map<string, int> seen;
            int j = 0;
            for (; j <= num; j++) {
                string tmp = s.substr(i+j*len, len);
                if (counts.find(tmp) != counts.end()) {
                    seen[tmp]++;
                    if (seen[tmp] > counts[tmp]) break;
                } else break;
            }
            if (j == num) ans.push_back(i);
        }
        return ans;
    }
};