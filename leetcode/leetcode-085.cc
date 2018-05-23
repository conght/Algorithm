#include <limits.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int maximalRectangle(std::vector<std::vector<char>>& matrix) {



        int M = matrix.length();
        if (0 == M)
            return 0;

        int N = matrix[0].length();

        
        if (0 == N)
            return 0;

        vector<vector<vector<int>>> lw;
        for (int i=0;i<M+1;i++) {
            vector<vector<int>> v;
            for (int j=0;j<N+1;j++) {
                std::vector<int> v2;
                v2.push_back(0);
                v2.push_back(0);
                v.push_back(v2);
            }
            lw.push_back(v);
        }

        for (int i=1;i<M+1;i++) {
            for (int j=1;j<N+1;j++) {
                if (matrix[i][j] == '0') {
                    lw[i][j][0] = lw[i][j][1] = 0;
                } else {
                    lw[i][j][0] = lw[i][j-1][0] + 1;
                    lw[i][j][1] = lw[i-1][j][1] + 1;
                }
            }
        }

        for (int i=0;i<M+1;i++)
            dp[i] = new int [N+1];

        for (int i=0;i<M+1;i++)
            for (int j=0;j<N+1;j++)
                dp[i][j] = 0;

        for (int i=0;i<M+1;i++) 
            dp[i][0] = i;
        for (int j=0;j<N+1;j++) 
            dp[0][j] = j;

        for (int i=1;i<M+1;i++)
            for (int j=1;j<N+1;j++) {
                int flag = 1;
                if (word1[i-1] == word2[j-1])
                    flag = 0;
                dp[i][j] = _Min(dp[i-1][j]+1, dp[i][j-1]+1, dp[i-1][j-1] + flag);
            }

        int result = dp[M][N];
        
        delete [] dp;
        return result;
    }

    int _Min(int a, int b, int c) {
        return min(a,min(b,c));
    }
};

int main() {
    Solution* s = new Solution();
    string a = "sea";
    string b = "eat";
    cout << s->minDistance(a, b) << endl;
    delete s;
    return 0;
}
