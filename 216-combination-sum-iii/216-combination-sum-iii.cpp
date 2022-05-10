class Solution {
public:
    void fun(int &k, int &n, int i, int sum, vector<int> a, vector<vector<int>> &ans)
    {
        if(i<=10 && a.size()==k && sum==n)
            ans.push_back(a);
        if(i>9 || sum>n || a.size()==k)
            return;
        fun(k,n,i+1,sum,a,ans);
        a.push_back(i);
        fun(k,n,i+1,sum+i,a,ans);
        //a.pop_back();
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> a;
        fun(k,n,1,0,a,ans);
        return ans;
    }
};