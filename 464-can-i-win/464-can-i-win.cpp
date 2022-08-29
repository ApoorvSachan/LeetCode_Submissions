class Solution {
public:
    int dp[1<<21];
    bool fun(int m, int d, int sum, int mask){
        if(dp[mask]!=-1) return dp[mask];
        for(int i=1;i<=m;i++){  
           if((mask&(1<<(i-1)))!=0) continue;
           if(sum+i>=d) return dp[mask]=true;
           if(fun(m,d,sum+i,mask+(1<<(i-1)))==false) return dp[mask]=true;
        }
        return dp[mask]=false;
    }
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
       memset(dp,-1,sizeof(dp));
       if((maxChoosableInteger*(maxChoosableInteger+1))/2<desiredTotal) return false;
       return fun(maxChoosableInteger,desiredTotal,0,0);
    }
};