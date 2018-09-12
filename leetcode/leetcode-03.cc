#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;

        if (s.length() == 0)
            return 0;

        set<char> sets;
        int index[256] = {-1};
        int i = 0;
        while (i < s.length()) {
            int j = i;
            while (j < s.length()) {
                sets.insert(s[j]);
                if ((j - i + 1) == sets.size()) {
                    ans = ans > sets.size() ? ans : sets.size();
                    index[s[j]] = j;
                    ++j;
                } else {
                    i = index[s[j]] + 1;
                    sets.clear();
                    break;
                }
            }
            if (j == s.length())
                break;
        }
        return ans;
    }
};

int main() {
    string s = "bbbbb";
    Solution sln;
    cout << sln.lengthOfLongestSubstring(s) << endl;
}