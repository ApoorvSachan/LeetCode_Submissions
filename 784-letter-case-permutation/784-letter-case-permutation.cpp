class Solution {
public:
    void fun(string s, int i, string a, vector<string> &ans)
    {
        if(i==s.size())
        {
            ans.push_back(a);
            return;
        }
        if(isdigit(s[i]))
        {   a+=s[i];
            fun(s,i+1,a,ans);
        }
        else
        {a+=tolower(s[i]);
        fun(s,i+1,a,ans);
        a.pop_back();
        a+=toupper(s[i]);
        fun(s,i+1,a,ans);
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        string a;
        fun(s,0,a,ans);
        return ans;
    }
};