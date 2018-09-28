#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<vector<int> > d(nums.size(), vector<int>(2));

        d[0][0] = nums[0];
        d[0][1] = nums[0];

        int ans = d[0][0];
        for (int i=1; i<nums.size(); i++) {
            d[i][0] = max(nums[i], max(nums[i]*d[i-1][0], nums[i]*d[i-1][1]));
            d[i][1] = min(nums[i], min(nums[i]*d[i-1][0], nums[i]*d[i-1][1]));

            ans = max(ans, d[i][0]);
        }

        return ans;
    }
};


int main() {

}