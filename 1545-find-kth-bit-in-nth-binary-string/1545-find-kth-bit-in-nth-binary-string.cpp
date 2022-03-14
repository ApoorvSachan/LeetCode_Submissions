class Solution {
public:
    void fun(int n, int i, string &s)
    {   if(i==n+1) return ;
        string r;
        for(int i=s.length()-1;i>=0;i--)
        {
            if(s[i]=='0') r+='1';
            else r+='0';
        }
        s+=('1'+r);
        fun(n,i+1,s);
    }
    char findKthBit(int n, int k) {
        string s="0";
        fun(n,2,s);
       // cout<<s<<endl;
        return s[k-1];
    }
};