class Solution {
public:
    int dp[20002][26], mod=1e9+7;
    int fun(int n, int i, char prev){
        if(i==n) return 1;
        if(dp[i][prev-'a']!=-1) return dp[i][prev-'a'];
        if(prev=='a')
            return dp[i][prev-'a']=fun(n,i+1,'e');
        if(prev=='e')
            return dp[i][prev-'a']=(fun(n,i+1,'a')+fun(n,i+1,'i'))%mod;
        if(prev=='i')
            return dp[i][prev-'a']=(((fun(n,i+1,'a')+fun(n,i+1,'e'))%mod+fun(n,i+1,'o'))%mod+fun(n,i+1,'u'))%mod;
        if(prev=='o')
            return dp[i][prev-'a']=(fun(n,i+1,'i')+fun(n,i+1,'u'))%mod;
        return dp[i][prev-'a']=fun(n,i+1,'a');
    }
    int countVowelPermutation(int n) {
        memset(dp,-1,sizeof(dp));
        return ((((fun(n,1,'a')+fun(n,1,'e'))%mod+fun(n,1,'i'))%mod+fun(n,1,'o'))%mod+fun(n,1,'u'))%mod;
    }
};