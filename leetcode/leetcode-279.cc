#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numSquares(int n) {

        vector<int> d(n+1);

        for (int i=0; i<=n; i++) {
            if (d[i] == 0) { d[i] = i; }
            if (i != 0 && i*i <= n) { d[i*i] = 1; }
        }

        for (int i=2; i<=n; i++) {
            if (d[i] < i) continue;
            for (int j=1; j<=i/2; j++) {
                d[i] = min(d[i], d[i-j] + d[j]);
            }
        }

        return d[n];
    }
};

int main() {
    cout << Solution().numSquares(8935);
}