Recursion -->
​
class Solution {
public:
int dp[200][200];
int f(vector<vector<int>>& grid, int i, int j)
{   int m=INT_MAX;
if(i==0)
return grid[i][j];
if(dp[i][j]!=-1)
return dp[i][j];
for(int k=0;k<grid[0].size();k++)
{
if(k!=j)
m=min(m,f(grid,i-1,k));
}
return dp[i][j]=grid[i][j]+m;
}
int minFallingPathSum(vector<vector<int>>& grid) {
int ans=INT_MAX;
memset(dp,-1,sizeof(dp));
for(int i=0;i<grid[0].size();i++)
{
ans=min(ans,f(grid,grid.size()-1,i));
}
return ans;
}
};