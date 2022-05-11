class Solution {
public:
    int ans=-1e9;
    map<vector<long long int>,long long int> mp;
    int bfs(vector<vector<int>>& m, int i, int j, int prev)
    {
        if(i<0 || j<0 || i==m.size() || j==m[0].size() || prev>=m[i][j])
        {
            return 0;
        }
        if(mp.find({i,j,prev})!=mp.end()) return mp[{i,j,prev}];
        int d=bfs(m,i+1,j,m[i][j]);
        int r=bfs(m,i,j+1,m[i][j]);
        int u=bfs(m,i-1,j,m[i][j]);
        int l=bfs(m,i,j-1,m[i][j]);
        int maxi=max(d,r);
        maxi=max(maxi,u);
        return mp[{i,j,prev}]=max(maxi,l)+1;
            
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
                ans=max(ans,bfs(matrix,i,j,-1));
        }
        return ans;
    }
};