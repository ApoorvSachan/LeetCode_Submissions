class Solution {
public:
    bool flag[10]={0};
    void fun(string &s, string a, set<string> &ans)
    {
       for(int i=0;i<s.size(); i++)
       {
           if(flag[i]==1) continue;
           a+=s[i];
           flag[i]=1;
        //   cout<<a<<endl;
           ans.insert(a);
           fun(s,a,ans);
           a.pop_back();
           flag[i]=0;
       }
    }
    int numTilePossibilities(string tiles) {
        set<string> ans;
        string a;
        fun(tiles,a,ans);
        return ans.size();
    }
};