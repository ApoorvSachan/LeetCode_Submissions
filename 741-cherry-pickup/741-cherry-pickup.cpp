class Solution {
public:
    int dp[50][50][50][50];
    int f(vector<vector<int>>& grid, int i, int j, int x, int y)
    {  
        if(x<0 || y<0 || i<0 || j<0 || grid[i][j]==-1 || grid[x][y]==-1)
            return INT_MIN;
        if(i==0 && j==0)
            return grid[i][j];
     if(dp[i][j][x][y]!=-1) return dp[i][j][x][y];
        int pick=0;
        if(i==x && j==y)
            pick=grid[i][j];
        else
            pick=grid[i][j]+grid[x][y];
        int ans=f(grid,i,j-1,x,y-1);
        ans=max(ans,f(grid,i-1,j,x-1,y));
        ans=max(ans,f(grid,i,j-1,x-1,y));
        return dp[i][j][x][y]=pick+max(ans,f(grid,i-1,j,x,y-1));
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size()-1;
        memset(dp,-1,sizeof(dp));
        return max(0,f(grid,n,n,n,n));
    }
};