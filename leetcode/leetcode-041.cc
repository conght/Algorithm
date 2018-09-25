#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] > 0 && nums[i] <= nums.size() && nums[i] != nums[nums[i]-1]) {
                //swap(nums, i, int(nums[i]-1));
                int tmp = nums[i];
                nums[i] = nums[nums[i]-1];
                nums[nums[i]-1] = tmp;
            }
        }

        for (int i=0; i<nums.size(); i++) {
            if (nums[i] != i+1) return i+1;
        }
        return 1;
    }
};

int main() {
    vector<int> v({7,8,9,11,12});
    Solution s;
    cout << s.firstMissingPositive(v) << endl;
    return 0;
}