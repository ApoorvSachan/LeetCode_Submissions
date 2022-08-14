class Solution {
public:
    int helper(int l, int st){
        int ans=1;
        while(l--){
            ans*=st;
            st--;
        }
        return ans;
    }
    int fun(string &s, int i, char prev, set<char> &t){
        if(i==s.size()) return 1;
        int ans=0;
        char start=(i==0)?'1':'0';
        char end=(i==0 || prev==s[i-1])?s[i]:'9';
        if(i>0 && prev<s[i-1]){
            int l=s.size()-i;
            return helper(l,10-t.size());
        }
        for(char j=start;j<=end;j++){
            if(t.find(j)==t.end()){
            t.insert(j);
            ans+=fun(s,i+1,j,t);
            t.erase(j);
            }
        }
        return ans;
    }
    int countSpecialNumbers(int n) {
      if(n==1) return n;
      string s=to_string(n);
      long temp=0;
      for(int i=1;i<s.size();i++){
      int t=i-1, k=9, ans=9;
      while(t>0){
          ans*=k;
          k--;t--;
      }
      temp+=ans;
      }
      set<char> t;
      int add=fun(s,0,'0',t);
      return temp+add;
    }
};