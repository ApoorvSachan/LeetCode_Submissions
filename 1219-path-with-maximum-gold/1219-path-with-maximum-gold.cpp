class Solution {
public:
    int di[4]={1,0,-1,0};
    int dj[4]={0,1,0,-1};
    int f(vector<vector<int>>& grid, int i, int j, vector<vector<int>> &visited)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size())
            return 0;
        if(visited[i][j]==1 || grid[i][j]==0) return 0;
        int maxi=INT_MIN;
        visited[i][j]=1;
        for(int d=0; d<4; d++)
        {   
            maxi=max(maxi,f(grid,i+di[d],j+dj[d], visited));
        }
        visited[i][j]=0;
        return maxi+grid[i][j];
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        vector<int> v(grid[0].size(),0);
        vector<vector<int>> visited(grid.size(),v);
        int ans=INT_MIN;
       for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[0].size(); j++)
            {   if(grid[i][j]==0) continue;
                ans=max(ans,f(grid,i,j,visited));
            }
       }
        return max(ans,0);
    }
};