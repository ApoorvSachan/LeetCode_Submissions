class Solution {
public:
    string removeKdigits(string num, int k) {
     stack<char> s;
     for(auto i:num){
         if(s.empty() || s.top()<=i)
             s.push(i);
         else{
             while(!s.empty() && s.top()>i && k>0){
                 s.pop();
                 k--;
             }
             s.push(i);
         }
     }
     while(!s.empty() && k!=0) {s.pop(); k--;}
     int i=s.size()-1, p=0;
     string ans(i+1,' ');
     while(!s.empty()){
        ans[i]=s.top();
         s.pop();
         i--;
     }
     while(ans[p]=='0') p++;
     ans=ans.substr(p);
     return (ans.size()==0)?"0":ans;
    }
};