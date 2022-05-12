class Solution {
public:
    void fun(vector<int>& n, int i, int prev, vector<int> a,set<vector<int>> &ans)
    {
        if(i==n.size())
        {
           if(a.size()>1)
            ans.insert(a);
            return;
        }
        if(n[i]<prev) 
        {
            if(a.size()>1)
            ans.insert(a);
        }
        if(n[i]>=prev)
        {
            a.push_back(n[i]);
            fun(n,i+1,n[i],a,ans);
            a.pop_back();
        }
        fun(n,i+1,prev,a,ans);
        
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
      set<vector<int>> ans;
      vector<int> a;
      fun(nums,0,-200,a,ans);
      vector<vector<int>> res(ans.begin(),ans.end());
      return res;
    }
};