/**
 *  conght 
 */


#include <iostream>
#include <vector>

using namespace std;

int lengthOfLIS(vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }
    vector<int> dp(nums.size(), 1);
    //for (int i = 0;i<dp.size();i++)
    //    dp[i] = 1;
    int max = 1;
    for (int i = 0;i < nums.size();i++) {
        for (int j = 0; j < i; j ++ ) {
            if (nums[i] > nums[j]) {
                dp[i] = (dp[j] + 1) > dp[i] ? (dp[j] + 1) : dp[i]; 
            }
        }
        if (dp[i] > max) {
            max = dp[i];
        }
    }
    return max;
}

int main() {
    vector<int> test;
    //{10, 9, 2, 5, 3, 7, 101, 18};
    test.push_back(10);
    test.push_back(9);
    test.push_back(2);
    test.push_back(5);
    test.push_back(3);
    test.push_back(7);
    test.push_back(101);
    test.push_back(18);
    cout << lengthOfLIS(test); 
    return 0;
}
