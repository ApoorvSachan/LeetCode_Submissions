class Solution {
public:
    int dp[30001][2];
   /* int fun(vector<int>& p, int i, int buy)
    {
        if(i==p.size()) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        if(buy==1)
        {
            return dp[i][buy]=max(p[i]+fun(p,i+1,0),fun(p,i+1,1));
        }
        else
            return dp[i][buy]=max(fun(p,i+1,1)-p[i],fun(p,i+1,0));
    }*/
    int maxProfit(vector<int>& p) {
        memset(dp,0,sizeof(dp));
        for(int i=p.size()-1;i>=0;i--)
        {
            for(int j=1;j>=0;j--)
            {
                if(j==1)
                    dp[i][j]=max(p[i]+dp[i+1][0],dp[i+1][1]);
                else
                    dp[i][j]=max(dp[i+1][1]-p[i],dp[i+1][0]);
            }
        }
        return dp[0][0];
    }
};