class Solution {
public:
    bool ispal(string &s)
    {
        for(int i=0;i<s.size()/2;i++)
        {
            if(s[i]!=s[s.size()-i-1])
                return 0;
        }
        return 1;
    }
    void f(string &s, int index,vector<string> a, vector<vector<string>> &ans)
    {   
        if(index==s.size())
        {
            ans.push_back(a);
            return; 
        }
        for(int i=index; i<s.size(); i++)
        {
            string t=s.substr(index,i-index+1);
            if(ispal(t))
            {
                a.push_back(t);
                f(s,i+1,a,ans);
                a.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> a;
        vector<vector<string>> ans;
        f(s,0,a,ans);
        return ans;
    }
};