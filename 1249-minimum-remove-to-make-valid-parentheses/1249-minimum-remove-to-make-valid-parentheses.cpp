class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<int> r;
        int open=0,close=0;
        for(int i=0;i<s.length();i++)
        {   
            if(s[i]=='(') open++;
            else if(s[i]==')') close++;
            if(s[i]==')' && close>open) {r.push_back(i); close--;}
        }
        if(open!=close)
        {   open=0; close=0;
            for(int i=s.length()-1;i>=0;i--)
            {   if(s[i]=='(') open++;
                else if(s[i]==')') close++;
                if(s[i]=='(' && open>close) 
                {r.push_back(i);
                 open--;
                }
            }
        }
        sort(r.begin(),r.end());
        int p=0;
        string ans;
        for(int i=0;i<s.length();i++)
        {   
            if(p<r.size() && i==r[p]) {p++; continue;}
            ans+=s[i];
        }
        return ans;
    }
};