class Solution {
public:
    int mod=1e9+7;
    int dp[31][1001];
    int fun(int n, int &k, int t)
    {
        if(t==0 && n==0) return 1;
        if(n==0) return 0;
        if(dp[n][t]!=-1) return dp[n][t];
        long long s=0;
        for(int i=1;i<=k;i++)
        {
            if(t-i<0) break;
            s=(s%mod)+(fun(n-1,k,t-i)%mod);
            s=s%mod;
        }
        return dp[n][t]=s;
    }
    int numRollsToTarget(int n, int k, int target) {
        memset(dp,-1,sizeof(dp));
      return fun(n,k,target);  
    }
};