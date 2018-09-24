#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxArea_not_best(vector<int>& height) {
        int ans = 0;
        for (int i = 0; i < height.size() - 1; i ++) {
            for (int j = i+1; j < height.size(); j++) {
                ans = max(ans, (j-i) * min(height[i], height[j]));
            }
        }

        return ans;
    }

    int maxArea(vector<int>& height) {
        int ans = min(height[0], height[1]);
        int max_index = height[1] > height[0] ? 1 : 0;
        for (int i=2; i<height.size(); i++) {
            int tmp = min(height[max_index], height[i]) * (i - max_index);
            ans = ans < tmp ? tmp : ans;
            max_index = height[max_index] < height[i] ? i : max_index;
        }
        return ans;
    }

};

int main() {
    int a[] = {1,8,6,2,5,4,8,3,7};
    vector<int> v(a, a+9);
    Solution s;
    cout << s.maxArea(v) << endl;
}