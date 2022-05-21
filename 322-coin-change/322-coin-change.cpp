class Solution {
public:
    int dp[13][10005];
    int fun(vector<int>& c, int i, int t, int &a)
    {
        if(t==a) return 0;
        if(i==c.size() || t>a) return 1e9+7;
        if(dp[i][t]!=-1) return dp[i][t];
        int p=1e9+7;
        if(c[i]<=a)
        p=1+fun(c,i,t+c[i],a);
        return dp[i][t]=min(p,fun(c,i+1,t,a));
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof(dp));
        int ans=fun(coins,0,0,amount);
        if(ans==1e9+7) return -1;
        return ans;
    }
};