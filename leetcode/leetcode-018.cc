#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    bool isContain(vector<vector<int> >& ans, vector<int>& v) {
        auto iter = ans.begin();
        for (; iter != ans.end(); iter ++) {
            int i = 0;
            for (; i < v.size(); i++) {
                if ((*iter)[i] != v[i]) {
                    break;
                }
            }
            if (i == v.size()) {
                return true;
            }
        }
        return false;
    }

    bool _fourSum(int i, int j, int target, vector<int>& nums, vector<vector<int> >& ans) {
        bool find = false;
        if (i+2 >= j)
            return false;
        //while (i + 2 < j) {
        find = false;
        int sum = nums[i] + nums[j];
        int a = i + 1;
        int b = j - 1;
        while (a < b) {
            sum = nums[i] + nums[j] + nums[a] + nums[b];
            if (sum > target) {
                --b;
                while (a < b && nums[b] == nums[b+1]) --b;
            } else if (sum < target) {
                ++a;
                while (a < b && nums[a] == nums[a-1]) ++a;
            } else {
                vector<int> v {nums[i], nums[a], nums[b], nums[j]};
                if (!isContain(ans, v))
                    ans.push_back(v);
                find = true;
                ++a;
                --b;
                while (a < b && nums[b] == nums[b+1]) --b;
                while (a < b && nums[a] == nums[a-1]) ++a;
            }

            //
            //
        }

        /*if (!find) {
            sum = nums[i] + nums[j];
            if (sum > target) {
                --j;
            } else if (sum < target) {
                ++i;
            } else {
                ++i;
                --j;
            }
            _fourSum(i+1, j, target, nums, ans);
            _fourSum(i, j-1, target, nums, ans);
        } else {
            ++i;
            --j;
        }*/

        _fourSum(i, j-1, target, nums, ans);
        _fourSum(i+1, j, target, nums, ans);

        while (i + 2 < j && nums[j] == nums[j+1]) --j;
        while (i + 2 < j && nums[i] == nums[i-1]) ++i;
        //}
        return find;
    }

    vector<vector<int> > fourSum2(vector<int>& nums, int target) {
        vector<vector<int> > ans;
        if (nums.empty()) {
            return ans;
        }

        sort(nums.begin(), nums.end());

        int i = 0;
        int j = nums.size() -1 ;
        _fourSum(i, j, target, nums, ans);
        return ans;
    }

    vector<vector<int> > fourSum(vector<int>& nums, int target) {
        vector<vector<int> > ans;
        if (nums.empty()) {
            return ans;
        }

        sort(nums.begin(), nums.end());

        int len = nums.size() - 3;
        for (int i=0;i<len;i++) {
            for (int j =nums.size() - 1; i + 2 < j; j--) {
                int sum = nums[i] + nums[j];
                bool find = false;
                int a = i + 1;
                int b = j - 1;
                while (a < b) {
                    sum = nums[i] + nums[j] + nums[a] + nums[b];
                    if (sum > target) {
                        --b;
                        while (a < b && nums[b] == nums[b+1]) --b;
                    } else if (sum < target) {
                        ++a;
                        while (a < b && nums[a] == nums[a-1]) ++a;
                    } else {
                        vector<int> v {nums[i], nums[a], nums[b], nums[j]};
                        if (!isContain(ans, v))
                            ans.push_back(v);
                        //ans.push_back({nums[i], nums[a], nums[b], nums[j]});
                        find = true;
                        ++a;
                        --b;
                        while (a < b && nums[b] == nums[b+1]) --b;
                        while (a < b && nums[a] == nums[a-1]) ++a;
                    }

                }
            }
        }
        return ans;
    }
};

int main() {
    //int a[] = {1,0,-1,0,-2,2};
    int a[] = {0};
    vector<int> v(a, a+1);
    //vector<int> v;

    Solution s;
    vector<vector<int> > ans = s.fourSum(v, 0);
    for (auto iter1 = ans.begin();iter1!=ans.end();iter1++) {
        for (auto iter2 = iter1->begin(); iter2 != iter1->end(); iter2 ++) {
            cout << *iter2 << " ";
        }
        cout << endl;
    }
}