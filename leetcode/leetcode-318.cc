#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int ans = 0;
        if (words.size() == 0) return ans;

        vector<int> wordbits;

        for (auto s : words) {
            int bits = 0;
            for (int i=0;i<s.length();i++) {
                bits += (1<<(s[i] - 'a'));
            }
            wordbits.push_back(bits);
            cout << bits << endl;
        }

        for (int i=0;i<words.size()-1;i++) {
            for (int j=i+1;j<words.size();j++) {
                if ((wordbits[i] & wordbits[j]) == 0) {
                    ans = max(ans, (int)words[i].length()*(int)words[j].length());
                }
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}