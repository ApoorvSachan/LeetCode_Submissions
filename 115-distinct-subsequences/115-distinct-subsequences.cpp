class Solution {
public:
    int dp[1001][1001];
    int fun(string &s, string &t, int i, int j)
    {
        if(j<0) return 1;
        if(i<0)  return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j])
        {
            return dp[i][j]=fun(s,t,i-1,j-1)+fun(s,t,i-1,j);
        }
        return dp[i][j]=fun(s,t,i-1,j);
    }
    int numDistinct(string s, string t) {
        memset(dp,-1,sizeof(dp));
        return fun(s,t,s.size()-1,t.size()-1);
    }
};