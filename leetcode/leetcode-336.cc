#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        while (i < s.length()/2) {
            if (s[i] != s[s.length() - i - 1]) return false;
            i++;
        }
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ans;

        if (words.size() < 2) return ans;

        unordered_map<string, int> hash_map;

        for (int i=0; i<words.size(); i++) {
            string temp = words[i];
            reverse(temp.begin(), temp.end());
            hash_map[temp] = i;
        }

        for (int i=0; i<words.size(); i++) {
            if (words[i] == "") {
                for (int k=0; k<words.size(); k++) {
                    if (k == i) continue;
                    if (isPalindrome(words[k])) {
                        vector<int> ans_item;
                        ans_item.push_back(k);
                        ans_item.push_back(i);
                        ans.push_back(ans_item);
                    }
                }
                continue;
            }
            for (int j=0; j<words[i].length(); j++) {
                string temp = words[i].substr(0, j+1);
                auto iter = hash_map.find(temp);
                if (iter != hash_map.end() && isPalindrome(words[i].substr(j+1)) && iter->second != i) {
                    //cout << temp << " " << iter->first << " " << words[i].substr(j+1) << endl;
                    vector<int> ans_item;
                    ans_item.push_back(i);
                    ans_item.push_back(iter->second);
                    ans.push_back(ans_item);
                }
                temp = words[i].substr(j+1);
                iter = hash_map.find(temp);
                if (iter != hash_map.end() && isPalindrome(words[i].substr(0, j+1)) && iter->second != i) {
                    //cout << temp << " " << iter->first << " " << words[i].substr(j+1) << endl;
                    vector<int> ans_item;
                    ans_item.push_back(iter->second);
                    ans_item.push_back(i);
                    ans.push_back(ans_item);
                }
            }
        }

        return ans;
    }
};

int main() {
    return 0;
}