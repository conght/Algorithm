
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;

        int ans = 0;
        int min_value = prices[0];

        for (int i=1; i<prices.size(); i++) {
            ans = max(ans, prices[i] - min_value);
            min_value = min(min_value, prices[i]);
        }
        return ans;
    }
};