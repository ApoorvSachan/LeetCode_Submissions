class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
       int r=matrix.size(), c=matrix[0].size();
       int dp[r][c], ans=matrix[0][0]-'0';
       for(int i=0;i<r;i++) 
       {
           dp[i][0]=matrix[i][0]-'0';
           if(dp[i][0]==1) ans=1;
       }
       for(int i=0;i<c;i++) 
       {
           dp[0][i]=matrix[0][i]-'0';
           if(dp[0][i]==1) ans=1;
       } 
        for(int i=1;i<r;i++)
        {
            for(int j=1;j<c;j++)
            {
                if(matrix[i][j]=='1')
                {
                    dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
                }
                else
                    dp[i][j]=0;
                ans=max(ans,dp[i][j]*dp[i][j]);
            }
        }
       return ans; 
    }
};