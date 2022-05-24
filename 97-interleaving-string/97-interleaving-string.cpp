class Solution {
public:
    int dp[202][202];
    bool fun(string &s1, string &s2, string s3 , int i, int j)
    {
        if(i<0 && j<0 && s3.size()>0) return 0;
        if((i>=0 || j>=0) && s3.size()<=0) return 0;
        if(j<0 && i<0 && s3.size()==0) return 1;
        if(dp[i+1][j+1]!=-1) return dp[i+1][j+1];
        int k=s3.size()-1;
        char c=s3[k];
        s3.pop_back();
        if(i>=0 && j>=0 && s1[i]==s2[j] && s1[i]==c)
        {
            return dp[i+1][j+1]=fun(s1,s2,s3,i-1,j) || fun(s1,s2,s3,i,j-1);
        }
        else if(i>=0 && s1[i]==c)
        {
            return dp[i+1][j+1]=fun(s1,s2,s3,i-1,j);
        }
        else if(j>=0 && s2[j]==c)
            return dp[i+1][j+1]=fun(s1,s2,s3,i,j-1);
        else
            return dp[i+1][j+1]=0;
    }
    bool isInterleave(string s1, string s2, string s3) {
        memset(dp,-1,sizeof(dp));
        return fun(s1,s2,s3,s1.size()-1,s2.size()-1);
    }
};