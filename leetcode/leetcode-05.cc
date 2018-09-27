#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindromev1(string s) {
        int str_len = s.length();

        string result = "";

        if (str_len == 0 || str_len == 1) {
            return s;
        }

        // new a dp table
        bool ** dp = new bool *[str_len];
        for (int i=0;i<str_len;i++)
            dp[i] = new bool [str_len];

        // init dp table
        for (int i = 0;i < str_len; i++) {
            for (int j = 0;j < str_len; j++) {
                if (i == j)
                    *(*(dp+i) + j)  = true;
                else
                    *(*(dp+i) + j) = false;

            }
        }

        // declare params
        int max_length = 1;
        int start_index = 0;
        int end_index = 0;

        // first loop : l - length of s[i~j]
        for (int l = 2; l < str_len + 1 ; l ++) {
            // second loop : j - end_index of s[i~j]
            //for (int j = 1; j < str_len; j ++) {
                // third loop : i - start_index of s[i~j]
            for (int i = 0; i < str_len - l + 1; i ++) {
                if (s[i] == s[i + l - 1]) {
                    if (l == 2)
                        dp[i][i+l-1] = true;
                    else
                        dp[i][i+l-1] = dp[i+1][i+l-2] == true ? true:false;

                } else {
                    dp[i][i+l-1] = false;
                }

                if (dp[i][i+l-1] && max_length < l) {
                    max_length = l;
                    start_index = i;
                    end_index = i+l-1;
                }
            }
            //}
        }

        result = s.substr(start_index, max_length);

        delete [] dp;
        return result;
    }

    string longestPalindromev2(string s) {
        if (s == "") return s;

        int len = 0;
        string ans;
        int begin, end;
        if (s.length()%2 == 1) { begin = end = s.length()/2; }
        else { begin = s.length()/2 - 1; end = s.length()/2; }

        while (begin >= 0 && end < s.size()) {
            //int i = begin;
            //int j = end;
            //while (i >= 0 && j < s.size() - 1)
            if (s[begin] == s[end]) {
                begin--;
                end++;
            } else {
                break;
            }
        }
        begin++;
        end--;

        if (len < (end - begin + 1)) ans = s.substr(begin, end - begin + 1);
        if (ans.length() >= s.length() - 1) return ans;

        string left_ans = longestPalindrome(s.substr(0, s.length()-1));
        if (left_ans.length() > ans.length()) ans = left_ans;

        string right_ans = longestPalindrome(s.substr(1, s.length()-1));
        if (right_ans.length() > ans.length()) ans = right_ans;
        return ans;
    }

    string longestPalindrome(string s) {
        //if (ans != "") return ans;
        if (s == "") return s;

        int len = 0;
        string ret = "";
        int begin = 0, end = s.length() - 1;


        int p = begin;
        int q = end;
        while (p < q) {
            if (s[p] == s[q]) {
                p++;
                q--;
            } else {
                break;
            }
        }
        if (p < q) {
            //begin++;
            string left_ret = longestPalindrome(s.substr(0, s.length() - 1));
            string right_ret = longestPalindrome(s.substr(1));

            if (left_ret.length() > right_ret.length()) ret = ans = left_ret;
            else ret = ans = right_ret;
        } else {
            ret = ans = s;
        }
        return ret;
    }
};

int main() {
	Solution* s = new Solution();
	string input = "babaddtattarrattatddetartb";
	/*while(cin >> input && input != "!") {
		cout << s->longestPalindromeV2(input) << endl;
	}*/
    cout << s->longestPalindrome(input) << endl;
	delete s;
	return 0;
}