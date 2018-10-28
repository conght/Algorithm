#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    string encode(vector<vector<int>>& board) {
        string ans = 0;
        for (int i=0;i<2;i++)
            for (int j=0;j<3;j++) {
                ans.push_back(board[i][j] + '0');
            }
        return ans;
    }

    bool solved(string board_str) {
        if (board_str == "123450") return true;
        return false;
    }

    int slidingPuzzle(vector<vector<int>>& board) {
        int ans = 0;

        queue<pair<string, int>> q;
        map<string, bool> checked;

        for (int zero_i=0;zero_i<2;zero_i++)
            for (int zero_j=0;zero_j<3;zero_j++)
                if (board[zero_i][zero_j] == 0) {
                    string board_str = encode(board);
                    q.push({board_str, zero_i*3+zero_j});
                    break;
                }

        vector<int> dir({0,-1,0,1,0});
        while(!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto item = q.front();
                q.pop();
                if (solved(item.first)) { return ans; }
                if (checked[item.first]) { continue; }
                checked[item.first] = true;
                int i = item.second / 3;
                int j = item.second % 3;
                string str = item.first;
                for (int k=0;k<4;k++) {
                    int ni = i+dir[k];
                    int nj = j+dir[k+1];
                    if (ni < 0 || nj < 0 || ni > 2 || nj > 3) continue;
                    swap(str[i*3+j], str[ni*3+nj]);
                    q.push({str, ni*3+nj});
                    swap(str[i*3+j], str[ni*3+nj]);
                }
            }
            ans++;
        }
        return -1;
    }
};

int main() {}