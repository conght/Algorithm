#include <limits.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        
        if (nums.size() == 0) {
            return 0;
        }
        
        std::vector<int> times(10001, 0);
        for (auto i = nums.begin(); i != nums.end(); i++) {
            times[*i]++;
        }
        
        std::vector<int> dp(10001, 0);
        
        dp[1] = times[1];
        for (int i=2;i<10001;i++) {
            dp[i] = max(dp[i-1], dp[i-2] + times[i] * i);
        }
        return dp[10000];
    }
};

int main() {
    Solution* s = new Solution();
    int v0[9] = {1,1,1,2,4,5,5,5,6};
    std::vector<int> v(v0,v0+9);
    
    cout << s->deleteAndEarn(v) << endl;
    delete s;
    return 0;
}
