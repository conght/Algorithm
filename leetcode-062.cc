#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m <= 0 || n <= 0) 
        	return 0;

        if (m == 1 || n == 1) 
        	return 1;

        int ** dp = new int * [m+1];

        for(int i=0;i < m+1;i++) {
        	dp[i] = new int [n+1];
        }

        for (int i=0;i<m+1;i++) {
        	for (int j=0;j<n+1;j++) {
        		dp[i][j] = 0;
        	}
        }

        dp[1][1] = 1;

        for (int i=1;i<m+1;i++) {
        	for (int j=1;j<n+1;j++) {
        		dp[i][j] += (dp[i-1][j] + dp[i][j-1]);
        	}
        }
        int ret = dp[m][n];

        for (int i=1;i<n+1;i++)
        	cout << dp[1][i] << " " ;
        delete [] dp;
        return ret;
    }
};

int main() {
    Solution* s = new Solution();
    int ret = s->uniquePaths(36, 7);
    cout << ret << endl;
    delete s;
    return 0;
}
