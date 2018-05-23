#include <limits.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(std::vector<std::vector<int> >& grid) {

        int m = 0, n = 0;
        m = grid.size();
        if (m != 0) 
            n = grid[0].size();

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

        for (int i=2;i<n+1;i++)
            dp[0][i] = INT_MAX;
        for (int i=2;i<m+1;i++)
            dp[i][0] = INT_MAX;

        for (int i=1;i<m+1;i++) {
        	for (int j=1;j<n+1;j++) {
        		dp[i][j] = (min(dp[i-1][j], dp[i][j-1]) + grid[i-1][j-1]);
        	}
        }
        int ret = dp[m][n];

        
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
    s->minPathSum(v);
    delete s;
    return 0;
}
