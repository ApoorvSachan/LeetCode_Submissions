class Solution {
public:
    bool flag[15+1]={0};
    void fun(int n, int len, vector<int> a, vector<vector<int>> &ans)
    {   bool f=0;
        for(int i=1;i<=n;i++)
        {
            if(flag[i]!=1)
            {f=1;break;}
        }
        if(f==0) {ans.push_back(a); return;}
        for(int i=1;i<=n;i++)
        {
            if(flag[i]==0 && (i%len==0 || len%i==0))
            {
                a.push_back(i);
                flag[i]=1;
                fun(n, len+1, a, ans);
                a.pop_back();
                flag[i]=0;
            }
        }
    }
    int countArrangement(int n) {
        vector<vector<int>> ans;
        vector<int> a;
        fun(n,1,a,ans);
        return ans.size();
    }
};