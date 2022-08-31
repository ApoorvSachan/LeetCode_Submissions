class Solution {
public:
    int myAtoi(string s) {
    int sign=0, f=0;
    long long ans=0;
    for(int i=0;i<s.size();i++){
        if(s[i]==' ') {
            if(f==0) continue;
            else break;
        } 
        f=1;
        if(s[i]=='-') {if(sign==0) {sign=-1;continue;} else break;}
        if(s[i]=='+') {if(sign==0) {sign=1;continue;} else break;}
        if(!isdigit(s[i])) break;
        if(sign==0) sign=1;
        ans=(ans*10)+(s[i]-'0');
        if(sign==1 && ans>INT_MAX) return INT_MAX;
        if(sign==-1 && sign*ans<INT_MIN) return INT_MIN;
     }
     ans=sign*ans;
     return ans;
    }
};