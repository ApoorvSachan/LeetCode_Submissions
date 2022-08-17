class Solution {
public:
    bool fun(string &num, int i, long long add, long long prev)
    {
        if(i==num.size()) return 1;
        int l=add==0?1:(log10(add)+1);
        if(i+l>num.size()) return 0;
        string t=num.substr(i,l);
        string c=to_string(add);
        if(t==c){
            return fun(num,i+l,prev+add,add);
        }
        return 0;
    }
    bool isAdditiveNumber(string num) {
      if(num.size()<3) return 0;
      int limit=(2*num.size())/3;
      for(int i=1;i<limit;i++){
         if(i>1 && num[0]=='0') return 0;
         string first=num.substr(0,i);
         long long f=stol(first), s;
         for(int j=1;j<=limit-i;j++){
             if(j>1 && num[i]=='0') break;
             string second=num.substr(i,j);
             s=stol(second);
             if(fun(num,i+j,f+s,s)) return 1;
      }
      }
      return 0;  
    }
};