class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>> v;
        vector<int> an;
        for(int i=0;i<mat.size(); i++)
        {   int one=0;
            for(auto j=0;j<mat[i].size();j++)
            {
                if(mat[i][j]==1)
                    one++;
            }
            v.push_back({one,i});
        }
        sort(v.begin(),v.end());
        for(int i=0;i<k; i++)
            an.push_back(v[i].second);
        return an;
    }
};