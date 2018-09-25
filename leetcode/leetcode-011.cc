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
        int ans = 0;

        int i = 0;
        int j = height.size() - 1;
        while (i < j) {
            ans = max(ans, min(height[i], height[j])*(j-i));
            if (height[i] < height[j]) i++;
            else j--;
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