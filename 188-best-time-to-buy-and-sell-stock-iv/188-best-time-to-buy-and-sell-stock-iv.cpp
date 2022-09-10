class Solution {
public:
    int dp[1001][101][2];
    int fun(vector<int> &p, int i, int t, int k){
        if(i==p.size() || k==0) return 0;
        if(dp[i][k][t]!=-1) return dp[i][k][t];
        if(t!=1){
        int buy=-p[i]+fun(p,i+1,1,k);
        int nbuy=fun(p,i+1,0,k);
        return dp[i][k][t]=max(buy,nbuy);
        }
        int sell=p[i]+fun(p,i+1,0,k-1);
        int nsell=fun(p,i+1,1,k);
        return dp[i][k][t]=max(sell,nsell);
    }
    int maxProfit(int k, vector<int>& prices) {
    memset(dp,-1,sizeof(dp));
    return fun(prices,0,0,k);   
    }
};