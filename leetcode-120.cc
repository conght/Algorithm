#include <limits.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumTotal(std::vector<std::vector<int> >& triangle) {

        int level = 0;
        level = triangle.size();

        if (level <= 0) 
        	return 0;

        if (level == 1)
            return triangle[0][0];

        int count = (level+1)*level/2;
        int * dp = new int[count];

        for(int i=0;i<count;i++) {
        	dp[i] = 0;a
        }

        dp[0] = triangle[0][0];

        int step = 0;
        int min_sum = INT_MAX;
        for (int i=1;i<level;i++) {
            step += i;
            int level_size = triangle[i].size();
        	for (int j=0;j<level_size;j++) {
                dp[step + j] = triangle[i][j];
        		if (j == 0)
                    dp[step + j] += dp[step + j - i];
                else if (j == level_size - 1)
                    dp[step + j] += dp[step + j - i - 1];
                else
                    dp[step + j] += min(dp[step + j - i], dp[step + j - i - 1]);

                if (i == (level-1))
                    if (min_sum > dp[step+j])
                        min_sum = dp[step+j];
        	}
        }

        for(int i=0;i<count;i++) {
            cout << dp[i] << endl;
        }
        
        delete dp;
        return min_sum;
    }
};

int main() {
    Solution* s = new Solution();
    std::vector<std::vector<int> > v;
    std::vector<int> v_1;
    std::vector<int> v_2;
    std::vector<int> v_3;
    std::vector<int> v_4;
    v_1.push_back(2);
    v_2.push_back(3);
    v_2.push_back(4);
    v_3.push_back(6);
    v_3.push_back(5);
    v_3.push_back(7);
    v_4.push_back(4);
    v_4.push_back(1);
    v_4.push_back(8);
    v_4.push_back(3);

    v.push_back(v_1);
    v.push_back(v_2);
    v.push_back(v_3);
    v.push_back(v_4);

    s->minimumTotal(v);
    delete s;
    return 0;
}
