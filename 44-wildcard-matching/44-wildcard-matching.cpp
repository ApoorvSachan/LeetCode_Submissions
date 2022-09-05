class Solution {
public:
 /*   bool fun(string &s, string &p, int i, int j){
        if(i<0 && j<0) return true;
        if(j<0 && i>=0) return false;
        if(i<0 && j>=0){
            for(;j>=0;j--){
                if(p[j]!='*') return false;
            }
            return true;
        }
        if(dp[i][j]!=-1) return dp[i][j]; 
        if(isalpha(p[j])){
            if(s[i]==p[j]) return dp[i][j]=fun(s,p,i-1,j-1);
            else
                return dp[i][j]=false;
        }
        if(p[j]=='?'){
            return dp[i][j]=fun(s,p,i-1,j-1);
        }
        return dp[i][j]=(fun(s,p,i-1,j-1) or fun(s,p,i-1,j) or fun(s,p,i,j-1));
    }*/
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size()+1,vector<int> (p.size()+1));
        dp[0][0]=1;
        for(int j=0;j<p.size();j++){
            if(p[j]=='*'){
                dp[0][j+1]=1;
            }
            else break;
        }
        for(int i=1;i<s.size()+1;i++){
            for(int j=1;j<p.size()+1;j++){
                if(isalpha(p[j-1])){
                if(s[i-1]==p[j-1]) dp[i][j]=dp[i-1][j-1];
                else
                    dp[i][j]=0;
                }
                else if(p[j-1]=='?'){
                    dp[i][j]=dp[i-1][j-1];
                }
                else dp[i][j]=(dp[i-1][j-1] | dp[i-1][j] | dp[i][j-1]);   
            }
        }
        return dp[s.size()][p.size()];
    }
};