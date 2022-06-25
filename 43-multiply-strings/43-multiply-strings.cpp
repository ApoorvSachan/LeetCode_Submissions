class Solution {
public:
    string add(string a, string b){
        int l1=a.length(), l2=b.length();
        string ans;
        int c=0;
        while(l1 || l2){
            if(l1==0 || l2==0){
               int s=((l1==0)?b[l2-1]:b[l1-1])-'0'+c;
               c=0;
               if(s/10!=0){
                 c=s/10;
                 ans+=(s%10+'0');
                }
                else ans+=s+'0';
               (l1==0)?l2--:l1--;
            }
            else{
                int s=(a[l1-1]-'0')+(b[l2-1]-'0')+c;
                c=0;
                if(s/10!=0){
                 c=s/10;
                 ans+=(s%10+'0');
                }
                else ans+=s+'0';
                l1--;l2--;
            }
        }
        if(c) ans+=(c+'0');
        reverse(ans.begin(),ans.end());
        return ans;
    }
    string multiply(string num1, string num2) {
        int l1=num1.length(), l2=num2.length(), zero=0;
        string ans="";
        while(l2)
        {
           string a;
           int c=0;
           for(int i=l1-1;i>=0;i--)
           {
              int p=(num2[l2-1]-'0')*(num1[i]-'0');
              p=p+c;
              c=0;
              if(p/10!=0)
              {
                  c=p/10;
                  a+=(p%10+'0');
              }
              else a+=(p+'0');
           }
            if(c) a+=(c+'0');
            reverse(a.begin(),a.end());
            for(int i=1;i<=zero;i++) a+='0';
            ans=add(ans,a);
        //    cout<<ans<<endl;
            l2--;
            zero++;
        }
        int i=0;
        while(i<ans.size() && ans[i]=='0') i++;
        ans=ans.substr(i);
        if(ans=="") ans+='0';
        return ans;
    }
};