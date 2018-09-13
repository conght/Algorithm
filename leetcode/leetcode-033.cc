#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (0 == nums.size()) {
            return -1;
        }

        int p = 0;
        int q = nums.size() - 1;
        int m = (p + q) / 2;

        while (p <= q) {
            if (p == q && target != nums[p])
                return -1;
            if (target == nums[m]) { 
                return m;
            } else if (target == nums[p]) {
                return p;
            } else if (target == nums[q]) {
                return q;
            }

            if (nums[p] < nums[m]) {
                if (target > nums[m] || target < nums[p]) {
                    p = m + 1;
                } else {
                    q = m - 1;
                }
            } else {
                if (target > nums[p] || target < nums[m]) {
                    q = m - 1;
                } else {
                    p = m + 1;
                }
            }

            m = (p + q) / 2;
        }
        return -1;
    }
};


int main() {

    int a[] = {1,3};
    vector<int> v(a, a+2);
    Solution s;
    cout << s.search(v, 0);
    return 0;
}