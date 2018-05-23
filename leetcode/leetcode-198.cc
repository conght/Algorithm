#include <limits.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        
        if (nums.size() == 0) 
            return 0;
        vector<int> dp(nums.size()+1, 0);

        dp[1] = nums[0];
        for (int i=2;i<nums.size()+1;i++) {
            dp[i] = max(dp[i-1], dp[i-2]+nums[i-1]);
        }

        return dp[nums.size()];
    }
    
};

int main() {
    Solution* s = new Solution();
    int v0[6] = {6,1,3,2,5,7};
    std::vector<int> v(v0,v0+6);
    
    cout << s->rob(v) << endl;
    delete s;
    return 0;
}
