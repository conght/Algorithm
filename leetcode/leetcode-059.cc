#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > ans;
        for (int i=0; i<n; i++) ans.push_back(vector<int>(n));

        int a = 1;
        int forward = 0;
        int i = 0;
        int j = 0;
        int top = 0;
        int bottom = n-1;
        int left = 0;
        int right = n-1;
        while (a <= n*n) {
            ans[i][j] = a;
            switch (forward) {
            case 0:
                if (j==right) {
                    forward = (forward+1) % 4;
                    ++i;
                    ++top;
                } else ++j;
                break;
            case 1:
                if (i == bottom) {
                    forward = (forward+1) % 4;
                    --j;
                    --right;
                } else ++i;
                break;
            case 2:
                if (j == left) {
                    forward = (forward+1) % 4;
                    --i;
                    --bottom;
                } else --j;
                break;
            case 3:
                if (i == top) {
                    forward = (forward+1) % 4;
                    ++j;
                    ++left;
                } else --i;
                break;
            }
            ++a;
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<int> > ans = s.generateMatrix(3);

    for (auto i:ans) {
        for (auto j:i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}