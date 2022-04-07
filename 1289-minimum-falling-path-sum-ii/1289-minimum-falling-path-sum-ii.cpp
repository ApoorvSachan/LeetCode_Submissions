class Solution {
public:
    int dp[200][200];
    
    int minFallingPathSum(vector<vector<int>>& grid) {
        int ans=INT_MAX;
        memset(dp,0,sizeof(dp));
        
        for(int j=0;j<grid.size();j++)
            dp[0][j]=grid[0][j];
        
        for(int i=1;i<grid.size();i++)
        {
            for(int j=0;j<grid.size();j++)
            {   
                int m=INT_MAX;
                for(int k=0;k<grid[0].size();k++)
                {
                    if(k!=j)
                        m=min(m,dp[i-1][k]);
                }
                dp[i][j]=grid[i][j]+m;
            }
        }
        
        for(int i=0;i<grid[0].size();i++)
        {
            ans=min(ans,dp[grid.size()-1][i]);
        }
        
        return ans;
    }
};