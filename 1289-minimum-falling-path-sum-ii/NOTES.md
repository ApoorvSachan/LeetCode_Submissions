Recursion -->
​
class Solution {
public:
int f(vector<vector<int>>& grid, int i, int j)
{   int m=INT_MAX;
if(i==0)
{
return grid[i][j];
}
for(int k=0;k<grid[0].size();k++)
{
if(k!=j)
m=min(m,f(grid,i-1,k));
}
return grid[i][j]+m;
}
int minFallingPathSum(vector<vector<int>>& grid) {
int ans=INT_MAX;
for(int i=0;i<grid[0].size();i++)
{
ans=min(ans,f(grid,grid.size()-1,i));
}
return ans;
}
};