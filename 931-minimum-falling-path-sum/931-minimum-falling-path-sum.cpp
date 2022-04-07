class Solution {
public:
    int dp[100][100];
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans=INT_MAX;
        memset(dp,0,sizeof(dp));
        for(int i=0;i<matrix[0].size();i++)
        {
            dp[0][i]=matrix[0][i];
        }
        for(int i=1;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {   int u=INT_MAX,ul=INT_MAX,ur=INT_MAX;
                u=dp[i-1][j];
                if(j-1>=0)
                    ul=dp[i-1][j-1];
                if(j+1<matrix[0].size()) 
                    ur=dp[i-1][j+1];
                dp[i][j]=matrix[i][j]+min(u,min(ul,ur));
            }
        }
        for(int i=0;i<matrix[0].size();i++)
        {
            ans=min(ans,dp[matrix.size()-1][i]);
        }
        return ans;
    }
};