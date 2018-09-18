#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void findFunc(vector<int>& nums, int left, int right, int target, int& ans_left, int& ans_right) {
        if (left == right) {
            if (nums[left] == target) {
                if (left < ans_left)
                    ans_left = left;
                if (left > ans_right)
                    ans_right = left;
            }

            return;
        }

        int index = -1;
        int s = left;
        int e = right;        
        while (s <= e) {
            int m = (s + e) / 2;
            if (nums[m] < target)
                s = m + 1;
            else if (nums[m] > target)
                e = m - 1;
            else {
                index = m;
                break;
            }
        }

        if (index == -1)
            return ;

        if (index < ans_left)
            ans_left = index;

        if (index > ans_right)
            ans_right = index;

        findFunc(nums, left, index - 1, target, ans_left, ans_right);
        findFunc(nums, index + 1, right, target, ans_left, ans_right);

        return;

    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = nums.size();
        int right = -1;

        findFunc(nums, 0, nums.size()-1, target, left, right);

        if (left > right) {
            left = -1;
            right = -1;
        }

        vector<int> ans;
        ans.push_back(left);
        ans.push_back(right);
        return ans;
    }
};


int main() {
    Solution* s = new Solution();
    std::vector<int> v = {2, 2};
    vector<int> ans = s->searchRange(v, 2);
    cout << ans[0] << " " << ans[1] << endl;
    delete s;
}