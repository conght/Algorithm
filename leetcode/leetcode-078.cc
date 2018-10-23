

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > res;
        int idx = 0;
        vector<int> path;

        subsets(S,idx,path,res);

        return res;
    }

    void subsets(vector<int> &S,int idx,vector<int> &path,vector<vector<int>> &res)
    {
        if ( idx == S.size() ) {
            res.push_back(path);
            return;
        }


        path.push_back(S[idx]);
        subsets(S,idx+1,path,res);

        path.pop_back();
        subsets(S,idx+1,path,res);
    }
};