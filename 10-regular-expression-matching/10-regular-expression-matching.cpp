class Solution {
public:
    bool fun(string &s, string &p, int i, int j, vector<vector<int>> &dp)
    {
        if(i<0)
        {   if(j<0) return 1;
                while(j>=0)
                {   if(p[j]!='*' && p[j+1]!='*') return 0;
                    j--;
                }  
            return 1;
        }
        if(j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(p[j]=='.')
            return dp[i][j]=fun(s,p,i-1,j-1,dp);
        if(p[j]=='*')
        {   bool r=fun(s,p,i,j-2,dp);
            bool l;
            if(p[j-1]=='.')
                l=fun(s,p,i-1,j,dp);
            else
                l=(p[j-1]==s[i] && fun(s,p,i-1,j,dp));
            return l || r;
        }
        return dp[i][j]=((s[i]==p[j]) && fun(s,p,i-1,j-1,dp));
    }
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size(), vector<int> (p.size(),-1));
        return fun(s,p,s.size()-1,p.size()-1,dp);
    }
};