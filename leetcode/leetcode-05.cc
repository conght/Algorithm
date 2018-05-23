#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
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
};

int main() {
	Solution* s = new Solution();
	string input = "";
	while(cin >> input && input != "!") {
		cout << s->longestPalindrome(input) << endl;
	}
	delete s;
	return 0;
}