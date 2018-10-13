class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> vct(26, 0);

        for (int i=0; i<s.length(); i++) {
            vct[s[i]-'a']++;
        }

        stringstream ss;
        for (int i=0; i<vct.size(); i++) {
            if (vct[i] != 0) {
                ss << (char)('a'+i);
            }
        }

        return ss.str();
    }
};