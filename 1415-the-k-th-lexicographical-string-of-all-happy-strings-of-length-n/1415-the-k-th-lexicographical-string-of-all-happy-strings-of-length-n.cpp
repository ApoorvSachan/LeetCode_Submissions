class Solution {
public:
    string happy="abc";
    void fun(char prev, int len, string a, set<string> &ans, int n)
    {
        if(len==n)
        {
            ans.insert(a);
            return;
        }
        for(int i=0; i<happy.size(); i++)
        {   if(prev==happy[i]) continue;
            a+=happy[i];
            fun(happy[i],len+1,a,ans,n);
            a.pop_back();
        }
    }
    string getHappyString(int n, int k) {
        set<string> ans;
        string res;
        int count=0;
        fun('d',0,"",ans,n);
        for(auto i:ans)
        {
            //cout<<i<<endl;
            count++;
            if(count==k) res=i;
        }
        return res;
    }
};