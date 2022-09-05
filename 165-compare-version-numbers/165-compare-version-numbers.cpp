class Solution {
public:
    int compareVersion(string v1, string v2) {
    int l=0, r=0;
    string s1,s2;
    while(l<=v1.size() || r<=v2.size()){
       if(l<v1.size() && v1[l]!='.'){
           s1+=v1[l];    
       } 
       if(r<v2.size() && v2[r]!='.'){
           s2+=v2[r];
       }
       if((l>=v1.size()||v1[l]=='.') && (r>=v2.size() || v2[r]=='.')){
           int i=0;
           while(i!=s1.size() && s1[i]=='0') i++;
           s1=s1.substr(i);
           i=0;
           while(i!=s2.size() && s2[i]=='0') i++;
           s2=s2.substr(i);
           if(s1.size()==0) s1="0";
           if(s2.size()==0) s2="0";
           while(s1.size()<s2.size())
               s1='0'+s1;
           while(s2.size()<s1.size())
               s2='0'+s2;
           if(s1>s2) return 1;
           else if(s1<s2) return -1;
           s1="";s2="";
           l++;
           r++;
           continue;
       }
       if(l<v1.size() && v1[l]!='.') l++;
       if(r<v2.size() && v2[r]!='.') r++;
    }
       return 0;
    }
};