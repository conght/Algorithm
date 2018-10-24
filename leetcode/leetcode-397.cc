class Solution {
public:

    int integerReplacement(int n) {
        return integerReplacementHelper(n);
    }
    int integerReplacementHelper(long long n) {
        int ans = 0;
        if (n <= 1) return ans;

        if (n&1) {
            return 1 + min(integerReplacementHelper(n+1), integerReplacementHelper(n-1));
        }

        return 1 + integerReplacementHelper(n >> 1);
        return ans;
    }
};