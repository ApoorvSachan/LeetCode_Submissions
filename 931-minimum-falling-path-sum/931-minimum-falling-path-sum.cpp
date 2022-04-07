class Solution {
public:
    int dp[100][100];
    int helper(vector<vector<int>> &matrix, int i, int j)
    {   if(j<0 || j>=matrix[0].size())
            return INT_MAX;
        if(i==0)
            return matrix[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int u=helper(matrix,i-1,j);
        int ul=helper(matrix,i-1,j-1);
        int ur=helper(matrix,i-1,j+1);
        return dp[i][j]=matrix[i][j]+min(u,min(ul,ur));
        
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans=INT_MAX;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<matrix[0].size();i++)
        {
            ans=min(ans,helper(matrix,matrix.size()-1,i));
        }
        return ans;
    }
};