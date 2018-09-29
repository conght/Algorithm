#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int ans = 0;

        if (nums.size() == 0) { return ans; }
        if (nums.size() == 1) { return nums[0]; }
        vector<int> d(nums.size()+1);

        d[0] = 0;
        d[1] = nums[0];

        bool rob_first = true;
        bool rob_last = false;

        for (int i=2; i<=nums.size(); i++) {
            d[i] = max(d[i-1], nums[i-1] + d[i-2]);
            if (nums[i-1] + d[i-2] > d[i-1] && i-2 == 0 && d[i] > ans) { rob_first = false; }
            if (nums[i-1] + d[i-2] > d[i-1] && i-3 == 0 && d[i] > ans) { rob_first = true; }
            if (nums[i-1] + d[i-2] > d[i-1] && i == nums.size() && d[i] > ans) { rob_last = true; }
            ans = max(ans, d[i]);
        }

        if (rob_first && rob_last) {
            ans = 0;
            for (int i=2; i<nums.size(); i++) {
                d[i] = max(d[i-1], nums[i-1] + d[i-2]);
                ans = max(ans, d[i]);
            }
            if (nums.size() >= 2) {
                d[1] = 0;
                d[2] = nums[1];
                for (int i=3; i<=nums.size(); i++) {
                    d[i] = max(d[i-1], nums[i-1] + d[i-2]);
                    ans = max(ans, d[i]);
                }
            }

        }

        return ans;
    }
};

int main() {
    vector<int> input({1});
    cout << Solution().rob(input);
    return 0;

}