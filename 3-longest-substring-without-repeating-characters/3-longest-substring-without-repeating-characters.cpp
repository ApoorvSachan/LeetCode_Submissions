class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      unordered_map<char,int> m;
      int ans=0, start=0;
      for(int i=0;i<s.size();i++){
          if(m.find(s[i])!=m.end()){
              int e=m[s[i]]+1;
              while(start<e){
                  m[s[start]]=-1;
                  start++;
              }
          }
          m[s[i]]=i;
          ans=max(ans,i-start+1);
      }
        return ans;
    }
};