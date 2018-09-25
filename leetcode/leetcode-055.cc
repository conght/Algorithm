#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    bool canJumpHelper(vector<int>& nums, int index) {
        if (index >= nums.size() - 1) return true;
        if (nums[index] + index >= nums.size() - 1) return true;
        for (int i=nums[index]; i>0; i--) {
            if (canJumpHelper(nums, index+i)) return true;
        }
        return false;
    }
    bool canJump(vector<int>& nums) {
        //return canJumpHelper(nums, 0);
        int position = nums.size() - 1;
        for (int i=position-1; i>=0; i--) {
            if (nums[i] + i >= position) position = i;
        }

        return position == 0;
    }
};

int main() {
    return 0;
}