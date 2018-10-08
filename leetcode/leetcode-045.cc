#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {

        if (nums.size() == 1) return 0;

        vector<int> d(nums.size(), nums.size());
        d[nums.size()-1] = 0;

        for (int i=nums.size()-2; i>=0; i--) {
            if (i+nums[i] >= nums.size()-1) d[i] = 1;
            else {
                for (int j=i+1;j<=i+nums[i];j++) d[i] = min(d[i], d[j]+1);
            }
        }

        return d[0];
    }
};

int main() {
    vector<int> nums({2,3,1,1,4});
    cout << Solution().jump(nums) << endl;
    return 0;
}