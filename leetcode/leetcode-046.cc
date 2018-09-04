#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    void _permute(int index, vector<int>& nums, vector<vector<int> >& ans) {
        if (index == nums.size() - 1) {
            ans.push_back(nums);
            return ;
        }

        for (int i=index+1; i<nums.size(); i++) {
            int tmp = nums[index+1];
            nums[index+1] = nums[i];
            nums[i] = tmp;

            _permute(index+1, nums, ans);

            tmp = nums[index+1];
            nums[index+1] = nums[i];
            nums[i] = tmp;

        }
    }

    vector<vector<int> > permute(vector<int>& nums) {
        vector<vector<int> > ans;
        if (nums.size() == 0) {
            return ans;
        }

        _permute(-1, nums, ans);

        return ans;
    }
};


int main() {

     //int a[] = {1,0,-1,0,-2,2};
    int a[] = {1,2,3};
    vector<int> v(a, a+3);
    Solution s;
    vector<vector<int> > ans = s.permute(v);
    for (auto iter1 = ans.begin();iter1!=ans.end();iter1++) {
        for (auto iter2 = iter1->begin(); iter2 != iter1->end(); iter2 ++) {
            cout << *iter2 << " ";
        }
        cout << endl;
    }
    return 0;
}