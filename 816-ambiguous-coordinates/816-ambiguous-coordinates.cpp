class Solution { 
    public: 
    bool isvalid(string s, int p)
    {
        if(s.size()==1) return 1;
        if(p==0)
        {
            if(s[0]!='0') return 1;
            else return 0;
        }
        int c=0;
        for(int i=0; i<p; i++)
        {
            if(s[i]=='0') c++;
            else
            break;
        }
        if(c>0 && p>1) return 0;
        int c1=0;
        for(int i=s.size()-1;i>p;i--)
        {
            if(s[i]=='0') c1++;
            else break;
        }
        if(c1>0) return 0;
        return 1;
    }
    vector<string> ans; 
    void gen(string a, string b) {
        for(int i=0;i<a.size();i++) 
        { string temp; 
          if(i==0) temp=a;
        else
        {
            string y=a.substr(0,i);
            string k=a.substr(i);
            temp=y+"."+k;
        }
        if(!isvalid(temp,i)) continue;
        for(int j=0;j<b.size();j++)
        {
            string t=b.substr(0,j)+"."+b.substr(j);
            if(j==0) t=b;
            if(!isvalid(t,j)) continue;
            string d=temp+", "+t;
            ans.push_back("("+d+")");
        }
    }
}
vector<string> ambiguousCoordinates(string s) {
    s.erase(0,1);
    s.erase(s.size()-1,1);
    for(int i=0; i<s.size()-1;i++)
       gen(s.substr(0,i+1),s.substr(i+1));  
    return ans;
}
};