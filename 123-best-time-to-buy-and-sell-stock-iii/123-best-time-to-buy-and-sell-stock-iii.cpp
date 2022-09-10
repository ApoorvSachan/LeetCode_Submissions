class Solution {
public:
    int dp[100001][2][2];
    int fun(vector<int> &p, int i, int t, int k){
        if(i==p.size() || k==2) return 0;
        if(dp[i][t][k]!=-1) return dp[i][t][k];
        if(!t){
           int buy=-p[i]+fun(p,i+1,1,k);
           int n_buy=fun(p,i+1,0,k);
           return dp[i][t][k]=max(buy,n_buy);
        }
        int sell=p[i]+fun(p,i+1,0,k+1);
        int n_sell=fun(p,i+1,1,k);
        return dp[i][t][k]=max(sell,n_sell);
    }
    int maxProfit(vector<int>& prices){
    memset(dp,-1,sizeof(dp));
    return fun(prices,0,0,0);    
    }
};