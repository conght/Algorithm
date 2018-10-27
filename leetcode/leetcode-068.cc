#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;

        string temp_str;
        int start = 0;
        int end = 0;
        int temp = 0;
        for (int i=0; i<words.size(); i++) {
            temp += words[i].length();
            if (maxWidth < temp + (end - start)) {
                temp -= words[end--].length();
                //cout << start << " " << end << " " << temp << endl;
                int each_space = 0;
                int other_space = 0;
                if ((end - start) != 0) {
                    other_space = (maxWidth - temp)%(end - start);
                    each_space = (maxWidth - temp)/(end - start);
                } else {
                    each_space = maxWidth - temp;
                    //cout << each_space << endl;
                }

                for (int j=start; j<=end; j++) {
                    temp_str += words[j];
                    if (j != end) {
                        for (int k = 0; k<each_space; k++) temp_str += " ";
                        if (j-start < other_space) {
                            temp_str += " ";
                        }
                    }
                }
                cout << temp_str.length() << endl;
                for (int k=temp_str.length(); k<maxWidth; k++) temp_str += " ";
                ans.push_back(temp_str);
                temp_str = "";
                temp = 0;
                start = ++end;
                i--;
            } else {
                end++;
            }
        }
        string last_line = "";
        int len = maxWidth;
        for (int i=start; i<words.size(); i++) {
            last_line += words[i];
            len -= words[i].length();
            if (len > 0) {last_line += " "; len--;}

        }

        while (len > 0) {
            last_line += " ";
            len--;
        }
        if (last_line != "") ans.push_back(last_line);
        //cout << start << " " << end << endl;
        return ans;
    }
};
int main() {};