class Solution {
public:
    void dfs(vector<vector<int>>& h, vector<vector<bool>> &vis, int i, int j, int prev){
        if(i<0 || j<0 || i==h.size() || j==h[0].size() || vis[i][j]!=0 || prev>h[i][j]) return;
        vis[i][j]=1;
        dfs(h,vis,i,j+1,h[i][j]);
        dfs(h,vis,i,j-1,h[i][j]);
        dfs(h,vis,i+1,j,h[i][j]);
        dfs(h,vis,i-1,j,h[i][j]);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
      vector<vector<bool>> vis(heights.size(),vector<bool>(heights[0].size()));
        for(int i=0;i<heights[0].size();i++)
            dfs(heights,vis,0,i,0);
        for(int i=0;i<heights.size();i++)
            dfs(heights,vis,i,0,0);
      vector<vector<bool>> temp(heights.size(),vector<bool>(heights[0].size()));
        for(int i=0;i<heights[0].size();i++)
            dfs(heights,temp,heights.size()-1,i,0);
        for(int i=0;i<heights.size();i++)
            dfs(heights,temp,i,heights[0].size()-1,0);
        vector<vector<int>> ans;
        for(int i=0;i<vis.size();i++){
            for(int j=0;j<vis[0].size();j++){
                if(vis[i][j] && temp[i][j])
                    ans.push_back({i,j});
            }
        }
        return ans;
    }
};