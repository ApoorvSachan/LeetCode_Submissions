class Solution {
public:
    string h(string &s)
    {   int count=0;
        string h;
        for(int i=s.size();i>=0;i--)
        {   
            if(s[i]=='#') count++;
            else if(count>0)
                count--;
            else h+=s[i];
        }
        return h;
    }
    bool backspaceCompare(string s, string t) {
      s=h(s);
      t=h(t);
      //  cout<<s<<"   "<<t<<endl;
     return t==s;
    }
};