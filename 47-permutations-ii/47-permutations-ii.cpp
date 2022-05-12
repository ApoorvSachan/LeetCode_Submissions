class Solution {
public:
    void p(vector<int> a,int index, vector<vector<int>> &an)
    {
        if(index==a.size()) {an.push_back(a); return;}
        unordered_set<int> m;
        for(int i=index; i<a.size(); i++)
        {
            if(m.find(a[i])!=m.end()) continue;
            m.insert(a[i]);
            swap(a[i],a[index]);
            p(a,index+1,an);
            swap(a[i],a[index]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
       vector<vector<int>> ans;
       p(nums,0,ans);
        return ans;
    }
};