class Solution {
public:
    string removeDuplicateLetters(string str) {
        vector<int> f(26,0);
        vector<bool> v(26,0);
        stack<char> s;
        for(auto i:str)
            f[i-'a']++;
        s.push(str[0]);
        f[str[0]-'a']--; v[str[0]-'a']=1;
        for(int i=1; i<str.size(); i++)
        {   f[str[i]-'a']--;
                if(v[str[i]-'a']==1) continue;
                if(s.top()<str[i]) 
                {s.push(str[i]); v[str[i]-'a']=1;}
                else
                {   
                    while(s.size()>0 && s.top()>str[i] && f[s.top()-'a']>0)
                    {   
                        v[s.top()-'a']=0;
                        s.pop();
                    } 
                    s.push(str[i]);
                    v[str[i]-'a']=1;
                }
        }
        string ans;
        while(!s.empty())
        {
            ans+=s.top();
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};