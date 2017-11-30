#include <limits.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {

        int M = word1.length();
        int N = word2.length();

        if (0 == M)
            return N;
        if (0 == N)
            return M;

        int **dp = new int *[M + 1];
        for (int i=0;i<M+1;i++)
            dp[i] = new int [N+1];

        for (int i=0;i<M+1;i++)
            for (int j=0;j<N+1;j++)
                dp[i][j] = max(M*2+1, N*2+1);

        dp[0][0] = 0;

        for (int i=1;i<M+1;i++)
            for (int j=1;j<N+1;j++) {
                int flag = 1;
                if (word1[i] == word2[j])
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
    string a = "a";
    string b = "b";
    cout << s->minDistance(a, b) << endl;
    delete s;
    return 0;
}
