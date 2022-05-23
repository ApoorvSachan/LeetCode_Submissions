class Solution {
public:
    int dp[601][101][101];
    int fun(vector<string>& s, int i, int o, int z, int &m, int &n)
    {
        if(i==s.size()) return 0;
        if(dp[i][o][z]!=-1) return dp[i][o][z];
        int l=fun(s,i+1,o,z,m,n);
        int c=0, r=-1e9;
        for(int j=0;j<s[i].size();j++)
        {
            if(s[i][j]=='1') c++;
        }
        int ze=s[i].size()-c;
        if(o+c<=n && z+ze<=m)
        r=1+fun(s,i+1,o+c,z+ze,m,n);
        return dp[i][o][z]=max(l,r);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp,-1,sizeof(dp));
        return fun(strs,0,0,0,m,n);
    }
};
