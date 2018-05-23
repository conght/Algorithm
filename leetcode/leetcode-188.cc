#include <limits.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        
        if (prices.size() == 0) {
            return 0;
        }
        
        int n = prices.size();
        
        if (k > n) {
            return _maxProfit(prices);
        }

        int **localProfit = new int *[n];  
        int **globalProfit = new int *[n];

        for (int i=0;i<n;i++) {
            localProfit[i] = new int [k+1];
            globalProfit[i] = new int [k+1];
        }

        for (int i=0;i<n;i++)
            for (int j=0;j<k+1;j++)
                localProfit[i][j] = globalProfit[i][j] = 0;
 
        for (int i = 1; i < n; ++i) {
            int diff = prices[i]-prices[i-1];
            for (int j = k; j > 0; j--) {
                localProfit[i][j] = max(globalProfit[i-1][j-1]+max(diff, 0), localProfit[i-1][j] + diff);
                globalProfit[i][j] = max(globalProfit[i-1][j], localProfit[i][j]);
            }
        }

        int ret = globalProfit[n-1][k];

        delete [] localProfit;
        delete [] globalProfit;

        return ret;
    }
    
    int _maxProfit(vector<int>& prices) {
        int result = 0;
        int n = prices.size();
        for(int i = 1; i < n; i ++){
            if(prices[i] > prices[i-1])
                result += (prices[i] - prices[i-1]);
        }
        return result;
    }
};

int main() {
    Solution* s = new Solution();
    int v0[6] = {6,1,3,2,5,7};
    std::vector<int> v(v0,v0+6);
    
    cout << s->maxProfit(2, v) << endl;
    delete s;
    return 0;
}
