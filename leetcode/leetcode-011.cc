#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        for (int i = 0; i < height.size() - 1; i ++) {
            for (int j = i+1; j < height.size(); j++) {
                ans = max(ans, (j-i) * min(height[i], height[j]));
            }
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