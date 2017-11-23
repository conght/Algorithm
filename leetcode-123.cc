#include <limits.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        if (prices.size() == 0) {
            return 0;
        }
        
        int n = prices.size();
        
        
        int max_sum = 0;

        int *dpl = new int[n];
        int *dpr = new int[n];

        for(int i=0;i<n;i++) {
            dpl[i] = dpr[i] = 0;
        }

        // from left -> right
        int _min1 = prices[0];
        int _maxprofit1 = 0;
        for (int i=1;i<n;i++) {
            int tmp = prices[i] - _min1;
            _maxprofit1 = _maxprofit1 > tmp ? _maxprofit1 : tmp;
            if (prices[i] < _min1) {
                _min1 = prices[i];
            }
            dpl[i] = _maxprofit1;
        }

        // from right -> left

        int _max2 = prices[n-1];
        int _maxprofit2 = 0;
        for (int i=n-2;i>=0;i--) {
            int tmp = _max2 - prices[i];
            _maxprofit2 = _maxprofit2 > tmp ? _maxprofit2 : tmp;
            if (prices[i] > _max2) {
                _max2 = prices[i];
            }
            dpr[i] = _maxprofit2;
        }
        
        for (int k=1;k<n-2;k++) {
            int tmp = dpl[k] + dpr[k+1];
            if (tmp > max_sum)
                max_sum = tmp;
        }
        // transaction one time
        max_sum = max(max_sum, _maxProfit(prices, 0, n-1));
        
        delete dpl;
        delete dpr;
        return max_sum;
    }
    
    int _maxProfit(vector<int>& prices, int start, int end) {
        int maxprofit = 0;
        int _min=prices[start];
        for (int i=start+1;i<end+1;i++) {
            if (_min < prices[i]) {
                maxprofit = (prices[i] - _min) > maxprofit ? prices[i] - _min : maxprofit;
            }
            if (_min > prices[i])
                _min = prices[i];
        }
        return maxprofit;
    }
};

int main() {
    Solution* s = new Solution();
    std::vector<int> v = {1,2,4,2,5,7,2,4,9};
    
    cout << s->maxProfit(v) << endl;
    delete s;
    return 0;
}
