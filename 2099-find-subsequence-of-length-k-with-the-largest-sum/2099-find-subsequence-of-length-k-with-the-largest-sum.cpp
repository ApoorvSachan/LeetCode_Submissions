class Solution {
public:
    class cmp
    {
        public:
        bool operator() (pair<int,int> a, pair<int,int> b)
        {
           return a.first>b.first; 
        }
    };
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> q;
        vector<int> ans;
        vector<bool> a(nums.size(),0);
        for(int i=0;i<k;i++)
            q.push({nums[i],i});
        for(int i=k;i<nums.size();i++)
        {
            pair<int,int> t=q.top();
            if(nums[i]>t.first)
            {
                q.pop();
                q.push({nums[i],i});
            }
        }
        while(!q.empty())
        {
            a[q.top().second]=1;
            q.pop();
        }
        for(int i=0; i<nums.size(); i++)
        {
            if(a[i]==1)
                ans.push_back(nums[i]);
        }
        return ans;
    }
};