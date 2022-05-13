class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        vector<vector<int>> dp(s1.size()+1, vector<int> (s2.size()+1,0));
        for(int i=0;i<=s1.size();i++)
            dp[i][0]=1;
        for(int i=1;i<=s1.size();i++)
        {
            for(int j=1;j<=s2.size();j++)
            {
                if(s1[i-1]==s2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        int n=dp.size()-1, m=dp[0].size()-1;
        string ans;
        while(n>0 && m>0)
        {
            if(s1[n-1]==s2[m-1])
            {
                ans+=s1[n-1];
                n--; m--;
            }
            else if(dp[n][m-1]>dp[n-1][m])
            {
                ans+=s2[m-1];
                m--;
            }
            else
            {
                ans+=s1[n-1];
                n--;
            }
        }
        while(n>0)
        {
            ans+=s1[n-1];
            n--;
        }
        while(m>0)
        {
            ans+=s2[m-1];
            m--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};