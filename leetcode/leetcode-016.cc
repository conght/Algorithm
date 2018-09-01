#include <bits/stdc++.h>

using namespace std;



class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {


        int ans = INT_MAX;
        if (nums.empty()) {
            return ans;
        }

        sort(nums.begin(), nums.end());

        auto iter = nums.begin();
        for (int i=0; i<nums.size()-1; i++) {
            int l = i+1;
            int r = nums.size()-1;
            if (i>0 && nums[i] == nums[i-1])
                continue;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r] - target;
                if (sum < 0) {
                    if (ans > 0 && ans > -sum) {
                        ans = sum;
                    } else if (ans < 0 && ans < sum) {
                        ans = sum;
                    }
                    ++l;
                    while (l<r && nums[l] == nums[l-1]) ++l;
                } else if (sum > 0) {
                    if (ans > 0 && ans > sum) {
                        ans = sum;
                    } else if (ans < 0 && ans < -sum) {
                        ans = sum;
                    }
                    --r;
                    while (l<r && nums[r] == nums[r+1]) --r;
                } else {
                    return target;
                }
            }
        }
        return ans + target;
    }
};

int main() {
    int a[] = {-1, 2, 1, -4};
    vector<int> v(a, a+4);
    //vector<int> v;

    Solution s;
    int ans = s.threeSumClosest(v, 1);
    cout << ans << endl;
}