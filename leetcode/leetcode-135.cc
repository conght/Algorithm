class Solution {
public:
    int candy(vector<int>& ratings) {
        int ans = ratings.size();

        if (ratings.size() <= 1) return ans;

        int i = 1;
        while (i<ratings.size()) {
            if (ratings[i] == ratings[i-1]) { ++i; continue; }
            int len = 0;
            while (i<ratings.size() && ratings[i] > ratings[i-1]) {
                ++len;
                ans += len;
                ++i;
            }

            int len2 = 0;
            while (i<ratings.size() && ratings[i] < ratings[i-1]) {
                ++len2;
                ans += len2;
                ++i;
            }

            ans -= min(len, len2);
        }
        return ans;
    }
};