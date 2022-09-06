class Solution {
public:
    int dp[301];
    bool fun(string &s, int i, set<string> &st){
      if(i==s.size()) return 1;
      if(dp[i]!=-1) return dp[i];
      string t;
      for(int j=i;j<s.size();j++){
          t+=s[j];
          if(st.find(t)!=st.end()){
          if(fun(s,j+1,st)) return dp[i]=true;    
          }
      }
      return dp[i]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
    set<string> st;
    for(auto i:wordDict) st.insert(i);
    memset(dp,-1,sizeof(dp));
    return fun(s,0,st);
    }
};