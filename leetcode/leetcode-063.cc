#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(std::vector<std::vector<int> >& obstacleGrid) {

        int m = 0, n = 0;
        m = obstacleGrid.size();
        if (m != 0) 
            n = obstacleGrid[0].size();

        if (m <= 0 || n <= 0) 
        	return 0;

        int ** dp = new int * [m+1];

        for(int i=0;i < m+1;i++) {
        	dp[i] = new int [n+1];
        }

        for (int i=0;i<m+1;i++) {
        	for (int j=0;j<n+1;j++) {
        		dp[i][j] = 0;
        	}
        }

        if (obstacleGrid[0][0] == 0)
            dp[1][1] = 1;

        for (int i=1;i<m+1;i++) {
        	for (int j=1;j<n+1;j++) {
                if (obstacleGrid[i-1][j-1] == 1)
                    dp[i][j] = 0;
                else
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
    std::vector<std::vector<int> > v;
    std::vector<int> v2;
    v2.push_back(1);
    v.push_back(v2);
    s->uniquePathsWithObstacles(v);
    delete s;
    return 0;
}
