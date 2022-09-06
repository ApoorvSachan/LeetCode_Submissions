class Solution {
public:
    vector<string> ans;
    void fun(string &s, int i, set<string> &st, string a){
        if(i==s.size()){
            ans.push_back(a);
            return;
        }
        string t;
        if(a.size()!=0) a+=' ';
        for(int j=i;j<s.size();j++){
            a+=s[j];
            t+=s[j];
            if(st.find(t)!=st.end())
                fun(s,j+1,st,a);
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
    set<string> st;
    for(auto i:wordDict) st.insert(i);
    fun(s,0,st,"");
    return ans;
    }
};