#include <bits/stdc++.h>

using namespace std;



class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {


        vector<vector<int> > ans;
        if (nums.empty()) {
            return ans;
        }

        sort(nums.begin(), nums.end());

        auto iter = nums.begin();
        for (; iter != nums.end() - 1; iter++) {
            if (iter != nums.begin() && *iter == *(iter-1))
                continue;
            auto first = iter + 1;
            auto last = nums.end() - 1;
            vector<vector<int> > vs;
            vs = twoSum(nums, first, last, -(*iter));
            for (auto vs_iter = vs.begin(); vs_iter != vs.end(); vs_iter ++) {
                if (!isContain(ans, *vs_iter))
                    ans.push_back(*vs_iter);
            }
        }
        return ans;
    }

private:
     vector<vector<int> > twoSum(vector<int>& nums, vector<int>::iterator first, vector<int>::iterator last,
        int target) {

        vector<vector<int> > ans;
        while (first < last) {
            int sum = *first + * last;
            if (sum < target/* && *first == *(first-1)*/) {
                ++first;
            }
            else if (sum > target/* && *last == *(last+1)*/) {
                --last;
            }
            else {
                vector<int> v;
                v.push_back(-target);
                v.push_back(*first);
                v.push_back(*last);
                if (!isContain(ans, v)) {
                    ans.push_back(v);
                }
                first++;
                last--;
            }
        }

        return ans;
    }

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
};

int main() {
    int a[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    vector<int> v(a, a+20);
    //vector<int> v;

    Solution s;
    vector<vector<int> > ans = s.threeSum(v);
    for (auto iter1 = ans.begin();iter1!=ans.end();iter1++) {
        for (auto iter2 = iter1->begin(); iter2 != iter1->end(); iter2 ++) {
            cout << *iter2 << " ";
        }
        cout << endl;
    }
}