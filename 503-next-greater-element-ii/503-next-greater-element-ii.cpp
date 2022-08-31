class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
     int l=nums.size();
     for(int i=0;i<l-1;i++)
         nums.push_back(nums[i]);
     stack<int> s;
     vector<int> a(nums.size());
     for(int i=nums.size()-1;i>=0;i--){
        while(!s.empty() && s.top()<=nums[i])
                s.pop();
        if(s.empty()) a[i]=-1;
        else a[i]=s.top();
        s.push(nums[i]);
     }
     vector<int> ans(a.begin(),a.begin()+l);
     return ans;
    }
};